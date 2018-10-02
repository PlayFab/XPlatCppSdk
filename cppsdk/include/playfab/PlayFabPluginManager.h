#pragma once

#include <playfab/PlayFabCallRequestContainer.h>
#include <playfab/PlayFabError.h>
#include <unordered_map>

// Intellisense-only includes
#include <curl/curl.h>

namespace PlayFab
{
    /// <summary>
    /// The enumeration of supported plugin contracts.
    /// </summary>
    enum class PlayFabPluginContract
    {
        PlayFab_Serializer,
        PlayFab_Transport,
        PlayFab_Endpoint
    };

    /// <summary>
    /// Interface of any PlayFab SDK plugin.
    /// </summary>
    class IPlayFabPlugin
    {
    };

    /// <summary>
    /// Interface of any transport SDK plugin.
    /// All functions execute asynchronously
    /// </summary>
    class IPlayFabHttpPlugin : public IPlayFabPlugin
    {
    public:
        /// <summary>
        /// starts the process of making a post request.
        /// A user is expected to supply their own CallRequestContainerBase
        /// </summary>
        virtual void MakePostRequest(const CallRequestContainerBase&) = 0;
    };

    /// <summary>
    /// Interface of any data serializer SDK plugin.
    /// </summary>
    class IPlayFabSerializerPlugin : public IPlayFabPlugin
    {
    };

    /// <summary>
    /// Interface of any HTTP endpoint SDK plugin.
    /// An HTTP endpoint is a class that that contains and manages specifics of a particular event ingestion service:
    /// authentication, special headers, payload or data size limitations, batching, retry policies, call frequency throttling, etc.
    /// The idea behind this plugin model is to allow PlayFab API to "doublepump" or "selectively pump" events to different, independent ingestion services
    /// from the same client app.
    /// </summary>
    class IPlayFabEndpointPlugin : public IPlayFabPlugin
    {
    public:
        // Perform any initialization if needed before starting endpoint's worker thread
        virtual void Initialize() = 0;

        // The procedure of endpoint's worker thread
        virtual void WorkerThread() = 0;

        // Pick and process one or more events from the top of the queue
        virtual void ProcessEventQueue() = 0;
    };

    /// <summary>
    /// The PlayFab plugin manager.
    /// </summary>
    class PlayFabPluginManager
    {
    public:
        static PlayFabPluginManager& GetInstance(); // The singleton instance of plugin manager

        // Prevent copy/move construction
        PlayFabPluginManager(const PlayFabPluginManager&) = delete;
        PlayFabPluginManager(PlayFabPluginManager&&) = delete;

        // Prevent copy/move assignment operations
        PlayFabPluginManager& operator=(const PlayFabPluginManager&) = delete;
        PlayFabPluginManager& operator=(PlayFabPluginManager&&) = delete;

        // Gets a plugin.
        // If a plugin with specified contract and optional instance name does not exist, it will create a new one.
        template <typename T>
        static T& GetPlugin(const PlayFabPluginContract& contract, const std::string& instanceName = "")
        {
            return (T&)(GetInstance().GetPluginInternal(contract, instanceName));
        }

        // Sets a custom plugin.
        // If a plugin with specified contract and optional instance name already exists, it will be replaced with specified instance.
        static void SetPlugin(IPlayFabPlugin& plugin, const PlayFabPluginContract& contract, const std::string& instanceName = "");
    private:
        IPlayFabPlugin& GetPluginInternal(const PlayFabPluginContract& contract, const std::string& instanceName);
        void SetPluginInternal(IPlayFabPlugin& plugin, const PlayFabPluginContract& contract, const std::string& instanceName);

        IPlayFabPlugin* CreatePlayFabSerializerPlugin();
        IPlayFabPlugin* CreatePlayFabTransportPlugin();
        IPlayFabPlugin* CreatePlayFabEndpointPlugin();
        IPlayFabPlugin* CreateOneDSEndpointPlugin();

        // Private constructor and destructor
        PlayFabPluginManager() = default;
        ~PlayFabPluginManager() = default;

        std::map<const std::pair<const PlayFabPluginContract, const std::string>, IPlayFabPlugin&> plugins;
    };
}
