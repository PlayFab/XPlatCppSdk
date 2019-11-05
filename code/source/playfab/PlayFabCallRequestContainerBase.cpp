#include <stdafx.h>

#include <playfab/PlayFabCallRequestContainer.h>

namespace PlayFab
{
    CallRequestContainerBase::CallRequestContainerBase(
        std::string url,
        const std::unordered_map<std::string, std::string>& headers,
        std::string requestBody,
        CallRequestContainerCallback callback,
        std::shared_ptr<PlayFabApiSettings> settings,
        std::shared_ptr<PlayFabAuthenticationContext> context,
        void* customData) :
        url(url),
        requestHeaders(headers),
        requestBody(requestBody),
        m_settings(settings),
        m_context(context),
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

    std::string CallRequestContainerBase::GetRequestId() const
    {
        return this->requestId;
    }

    void CallRequestContainerBase::SetRequestId(const std::string& newRequestId)
    {
        this->requestId = newRequestId;
    }

    std::string CallRequestContainerBase::GetRequestBody() const
    {
        return this->requestBody;
    }

    std::shared_ptr<PlayFabApiSettings> CallRequestContainerBase::GetApiSettings() const
    {
        return this->m_settings;
    }

    std::shared_ptr<PlayFabAuthenticationContext> CallRequestContainerBase::GetContext() const
    {
        return this->m_context;
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
