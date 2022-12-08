#include <stdafx.h>

#include <playfab/QoS/XPlatSocket.h>
#include <playfab/QoS/QoS.h>

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
#include <sys/utime.h>
#else
#include <sys/ioctl.h>
#include <utime.h>
#endif // #if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)

using namespace std;

namespace PlayFab
{
    namespace QoS
    {
        XPlatSocket::XPlatSocket()
        {
            initialized = false;
            memset(&timeOutVal, 0, sizeof(timeOutVal));
        }

        XPlatSocket::~XPlatSocket()
        {
#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
            closesocket(s);
            WSACleanup();
#else
            close(s);
#endif // defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
        }

        int XPlatSocket::InitializeSocket()
        {
            // If the socket is already initialized, return 0,
            // else initialize it
            if (initialized)
            {
                return 0;
            }

            slen = sizeof(siOther);

            int errorCode = 0;

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
            // Initializing
            if ((errorCode = WSAStartup(MAKEWORD(2, 2), &wsa)) != 0)
            {
                LOG_QOS("WSAStartup failed with the error code : " << errorCode << endl);
                return errorCode;
            }
#endif

            // create socket
            if ((s = static_cast<int>(socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))) == SOCKET_ERROR)
            {
#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
                errorCode = WSAGetLastError();
#endif
                LOG_QOS("Socket creation failed with the error code : " << errorCode << endl);
                return errorCode;
            }

            //setup address structure
            memset((char *)&siOther, 0, sizeof(siOther));
            siOther.sin_family = AF_INET;
            initialized = true;

            return 0;
        }

        int XPlatSocket::SetTimeout(int timeoutMs)
        {
            // If an initialization error was logged, return -1
            if (LogErrorIfNotInitialized())
            {
                return -1;
            }

            // Input timeout is in milliseconds, tv_sec is in seconds
            timeOutVal.tv_sec = timeoutMs / 1000;

            // tv_usec takes microseconds, hence convert the input milliseconds to microseconds
            timeOutVal.tv_usec = (timeoutMs - timeOutVal.tv_sec * 1000) * 1000;
#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
            int errorCode = setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<const char*>(&timeoutMs), sizeof(timeoutMs));

            if (errorCode == 0)
            {
                errorCode = setsockopt(s, SOL_SOCKET, SO_SNDTIMEO, reinterpret_cast<const char*>(&timeoutMs), sizeof(timeoutMs));
            }

            return errorCode;
#else
            return setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (struct timeval *) &timeOutVal, sizeof(struct timeval));
#endif
        }

        int XPlatSocket::SetAddress(const char* socketAddr)
        {
            // If an initialization error was logged, return -1
            if (LogErrorIfNotInitialized())
            {
                return -1;
            }

            struct addrinfo hints = { 0 }, *addr;
            
            // TODO : Optimization
            //	Find a way to cache the hostent as we can have the same address being set again.
            //	Might look into using an unordered_map<socketAddr, hostent> but that might be expensive.
            int status = getaddrinfo(socketAddr, NULL, &hints, &addr);

            if (status != 0)
            {
                return GetLastErrorCode();
            }

            in_addr* inAddr = &reinterpret_cast<sockaddr_in*>(addr->ai_addr)->sin_addr;

#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
            if (inAddr->S_un.S_addr == 0)
            {
                LOG_QOS("Address casting failed\n");
                return -1;
            }
            siOther.sin_addr.S_un.S_addr = inAddr->S_un.S_addr;
#else
            if (inAddr->s_addr == 0)
            {
                LOG_QOS("Address casting failed\n");
                return -1;
            }
            siOther.sin_addr.s_addr = inAddr->s_addr;
#endif

            // 0 indicates that the host was found
            return 0;
        }

        int XPlatSocket::SetPort(int port)
        {
            // If an initialization error was logged, return -1
            if (LogErrorIfNotInitialized())
            {
                return -1;
            }

            siOther.sin_port = htons(static_cast<u_short>(port));
            return 0;
        }

        int XPlatSocket::SendMessage(const char* message)
        {
            // If an initialization error was logged, return -1
            if (LogErrorIfNotInitialized())
            {
                return -1;
            }

            return static_cast<int>(sendto(s, message, static_cast<int>(strlen(message)), 0, (struct sockaddr *) &siOther, slen));
        }

        int XPlatSocket::ReceiveReply(char* buf, const int& buflen)
        {
            // If an initialization error was logged, return -1
            if (LogErrorIfNotInitialized())
            {
                return -1;
            }

            fd_set socketSet;

            FD_ZERO(&socketSet);
            FD_CLR(0, &socketSet);
            FD_SET(s, &socketSet);

            int selectResult = select(s+1, &socketSet, nullptr, nullptr, &timeOutVal);

            if (selectResult > 0)
            {
                int recvResult = static_cast<int>(recvfrom(s, buf, buflen, 0, (struct sockaddr *) &siOther, &slen));
                if (recvResult < 0)
                {
                    return platformSpecificError();
                }
                return recvResult;
            }
            else if (selectResult < 0)
            {
                return platformSpecificError();
            }
            else
            {
                return selectResult;
            }
        }

        int XPlatSocket::GetLastErrorCode() const
        {
            // If an initialization error was logged, return -1
            if (LogErrorIfNotInitialized())
            {
                return -1;
            }

            return h_errno;
        }

        bool XPlatSocket::LogErrorIfNotInitialized() const
        {
            if (!initialized)
            {
                LOG_QOS("Trying to use the socket without initialization" << std::endl);
            }

            return !initialized;
        }
        unsigned int XPlatSocket::platformSpecificError() const
        {
#if defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
            return WSAGetLastError();
#else
            return errno;
#endif
        }

    }
}
