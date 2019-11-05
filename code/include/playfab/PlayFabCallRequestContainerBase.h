#pragma once

#include <playfab/PlayFabApiSettings.h>
#include <unordered_map>
#include <memory>

namespace PlayFab
{
    class CallRequestContainerBase;
    typedef std::function<void(int, std::string, std::shared_ptr<CallRequestContainerBase>)> CallRequestContainerCallback;

    /// <summary>
    /// A base container meant for holding everything necessary to make a full HTTP request and return a response.
    /// A user may inherit from this if they are to make their own Http plugin and want to pass some additional, plugin-specific data.
    /// </summary>
    class CallRequestContainerBase
    {
    public:
        /// Parameters:
        /// - url is the relative url to the API a user wishes to call
        /// - headers should contain any optional headers that may be associated with this same API call
        /// - requestBody is the actual request Json object as a string
        /// - callback is a general callback that will handle any further logic, it is always called whether a call was successful or not
        /// - customData can be any object a user expects to be associated with this particular transaction (id/hash/tag etc.). It is simply relayed to callback.
        CallRequestContainerBase(
            std::string url,
            const std::unordered_map<std::string, std::string>& headers,
            std::string requestBody,
            CallRequestContainerCallback callback,
            std::shared_ptr<PlayFabApiSettings> apiSettings,
            std::shared_ptr<PlayFabAuthenticationContext> context,
            void* customData);

        virtual ~CallRequestContainerBase() = default;

        std::string GetUrl() const;
        std::unordered_map<std::string, std::string> GetRequestHeaders() const;
        std::string GetRequestId() const;
        void SetRequestId(const std::string& newRequestId);
        std::string GetRequestBody() const;
        std::shared_ptr<PlayFabApiSettings> GetApiSettings() const;
        std::shared_ptr<PlayFabAuthenticationContext> GetContext() const;

        /// <summary>
        /// This function is meant to handle logic of calling the error callback or success
        /// </summary>
        CallRequestContainerCallback GetCallback() const;

        void* GetCustomData() const;
        virtual bool ValidateSettings() = 0;

    protected:
        std::string url;
        std::unordered_map<std::string, std::string> requestHeaders;
        std::string requestBody;
        std::string requestId;
        std::shared_ptr<PlayFabApiSettings> m_settings;
        std::shared_ptr<PlayFabAuthenticationContext> m_context;
        CallRequestContainerCallback callback;

        // I never own this, I can never destroy it
        void* customData; // optional user data (relayed to callback). This gives users the flexibility to tag each request with some data that can be accessed in callback.

    private:
        // Prevent move construction and assignment operations
        CallRequestContainerBase() = delete;
        CallRequestContainerBase(const CallRequestContainerBase&) = delete;
        CallRequestContainerBase& operator=(const CallRequestContainerBase&) = delete;
    };
}
