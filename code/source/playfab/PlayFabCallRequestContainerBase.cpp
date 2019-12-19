#include <stdafx.h>

#include <playfab/PlayFabCallRequestContainer.h>

namespace PlayFab
{
    CallRequestContainerBase::CallRequestContainerBase(
        const std::string& url,
        const std::unordered_map<std::string, std::string>& headers,
        const std::string& requestBody,
        CallRequestContainerCallback callback,
        void* customData) :
        url(url),
        requestHeaders(headers),
        requestBody(requestBody),
        callback(callback),
        customData(customData)
    {
    }

    std::string CallRequestContainerBase::GetUrl() const
    {
        return this->url;
    }

    std::unordered_map<std::string, std::string> CallRequestContainerBase::GetRequestHeaders() const
    {
        return this->requestHeaders;
    }

    std::string CallRequestContainerBase::GetRequestBody() const
    {
        return this->requestBody;
    }

    CallRequestContainerCallback CallRequestContainerBase::GetCallback() const
    {
        return this->callback;
    }

    void* CallRequestContainerBase::GetCustomData() const
    {
        return this->customData;
    }
}
