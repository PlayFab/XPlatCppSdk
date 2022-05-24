#include <stdafx.h>

#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabTransportHeaders.h>

namespace PlayFab
{
    const std::string PlayFabPluginManager::defaultInstanceName;

    PlayFabPluginManager& PlayFabPluginManager::GetInstance()
    {
        static PlayFabPluginManager instance;
        return instance;
    }

    PlayFabPluginManager::PlayFabPluginManager()
    {
    }

    void PlayFabPluginManager::SetPlugin(const std::shared_ptr<IPlayFabPlugin>& plugin, const PlayFabPluginContract contract, const std::string& instanceName)
    {
        GetInstance().SetPluginInternal(plugin, contract, instanceName);
    }

    void PlayFabPluginManager::SetPluginInstance(const std::shared_ptr<IPlayFabPlugin>& plugin, const PlayFabPluginContract contract, const std::string& instanceName)
    {
        SetPluginInternal(plugin, contract, instanceName);
    }

    std::shared_ptr<IPlayFabPlugin> PlayFabPluginManager::GetPluginInternal(const PlayFabPluginContract contract, const std::string& instanceName)
    {
        { // LOCK pluginsMutex
            std::unique_lock<std::mutex> lock(pluginsMutex);
            PluginEntry& entry = FindOrCreatePluginEntry(contract, instanceName);
            if (entry.plugin == nullptr)
            {
                switch (contract)
                {
                case PlayFabPluginContract::PlayFab_Serializer:
                    entry.plugin = CreatePlayFabSerializerPlugin();
                    break;
                case PlayFabPluginContract::PlayFab_Transport:
                    entry.plugin = CreatePlayFabTransportPlugin();
                    break;
                default:
                    throw PlayFabException(PlayFabExceptionCode::PluginAmbiguity, "This contract is not supported");
                    break;
                }
            }
            return entry.plugin;
        } // UNLOCK pluginsMutex
    }

    void PlayFabPluginManager::SetPluginInternal(const std::shared_ptr<IPlayFabPlugin>& plugin, const PlayFabPluginContract contract, const std::string& instanceName)
    {
        { // LOCK pluginsMutex
            std::unique_lock<std::mutex> lock(pluginsMutex);
            PluginEntry& entry = FindOrCreatePluginEntry(contract, instanceName);
            entry.plugin = plugin;
        } // UNLOCK pluginsMutex
    }

    PlayFabPluginManager::PluginEntry& PlayFabPluginManager::FindOrCreatePluginEntry(PlayFabPluginContract contract, const std::string& instanceName)
    {
        for (PluginEntry& pluginEntry : plugins)
        {
            if (pluginEntry.contract == contract &&
                pluginEntry.name == instanceName)
            {
                return pluginEntry;
            }
        }
        plugins.emplace_back<PluginEntry>({contract, instanceName, nullptr});
        return plugins.back();
    }

    std::shared_ptr<IPlayFabPlugin> PlayFabPluginManager::CreatePlayFabSerializerPlugin()
    {
        return std::make_shared<IPlayFabSerializerPlugin>();
    }

    std::shared_ptr<IPlayFabPlugin> PlayFabPluginManager::CreatePlayFabTransportPlugin()
    {
#ifdef PLAYFAB_PLATFORM_XBOX
        return std::make_shared<PlayFabIXHR2HttpPlugin>();
#elif defined(PLAYFAB_PLATFORM_WINDOWS) && !defined(PLAYFAB_PLATFORM_GDK)
        return std::make_shared<PlayFabWinHttpPlugin>();
#elif defined(PLAYFAB_PLATFORM_IOS)
        return std::make_shared<PlayFabIOSHttpPlugin>();
#elif defined(PLAYFAB_PLATFORM_ANDROID)
        return std::make_shared<PlayFabAndroidHttpPlugin>();
#elif defined(PLAYFAB_PLATFORM_PLAYSTATION)
        return std::make_shared<PlayFabPS4HttpPlugin>();
#elif defined(PLAYFAB_PLATFORM_SWITCH)
        return std::make_shared<PlayFabCurlHttpPlugin>();
#else
        return std::make_shared<PlayFabCurlHttpPlugin>();
#endif // PLAYFAB_PLATFORM_XBOX
    }

    void PlayFabPluginManager::HandleException(const std::exception ex)
    {
        { // LOCK userExceptionCallbackMutex
            std::unique_lock<std::mutex> lock(userExceptionCallbackMutex);
            if (userExceptionCallback)
            {
                userExceptionCallback(ex);
            }
        } // UNLOCK userExceptionCallbackMutex
    }

    void PlayFabPluginManager::SetExceptionHandler(ExceptionCallback exceptionCallback)
    {
        { // LOCK userExceptionCallbackMutex
            std::unique_lock<std::mutex> lock(userExceptionCallbackMutex);
            userExceptionCallback = exceptionCallback;
        } // UNLOCK userExceptionCallbackMutex
    }
}
