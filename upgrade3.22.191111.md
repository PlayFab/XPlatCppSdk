# Upgrade guide for 3.21.191029 -> 3.22.191111

The 3.22 release of XPlatCppSdk will contain a some breaking changes, detailed later in the document. The primary goal for these changes is an overhaul and bugfix for the instance APIs, which allow everything from split-screen simultaneous multiplayer to multi-title access (primary for dev-test-live scenarios). The un-fixed implementation of those instances would allow instances associated with player2 to accidentally access data for player1, without any indication that the mix-up had taken place. This change strongly reinforces the state-isolation between API-instances, and ensures that cross-data contamination between players will not occur.

Please note, this data-isolation-issue only applied to simulateous multi-player scenarios such as split screen play.

The PR itself has a thorough explanation of all changes (here)[https://github.com/PlayFab/XPlatCoreTemplate/pull/39].

Most customers will only be affected by 2 very minor breaking changes in this PR which we feel does not meet our internal threshold for incrementing the major version number. Nearly all customers will need to change 1 or 2 lines of code, but very few customers should need to change more. The upgrade guide below should cover all possible changes required for even the most obscure breaking changes.

# Upgrade instructions

## Affects most/all customers

All customers will need to update how they assign the titleId for their game. And likely many will need to update how they assign the developerSecretKey for their game-servers.

* All customers should have a line setting the titleId:
    * Old: ```PlayFabSettings::titleId = "YourId";```
    * New: ```PlayFabSettings::staticSettings->titleId = "YourId";```
* Many customers likely have a line setting the developerSecretKey:
    * Old: ```PlayFabSettings::developerSecretKey  = "YourId";```
    * New: ```PlayFabSettings::staticSettings->developerSecretKey  = "YourId";```

We apologize that while trivial, these changes were necessary in order to ensure proper data-solation between API instances.

## Significant changes that should affect very few customers

* PlayFabSettings::ValidateSettings() has been moved to CallRequestContainer. The most likely scenario if you're calling this method, is that you've replaced the HTTP interface in the PluginManager, with a custom HTTP interface. PlayFab HTTP calls are packaged and described with the CallRequestContainer, and so it should be straightforward to change:
    * ```PlayFabSettings::ValidateSettings( ..., callRequestContainer);```
    * to
    * ```callRequestContainer.HandleInvalidSettings();```
    * Note, the additional parameters passed into the original ValidateSettings() method, are now available as fields of CallRequestContainer
* CallRequestContainerBase no longer contains a PlayFabApiSettings shared_ptr
    * If this affects you, then you're almost certainly holding a ```unique_ptr/shared_ptr<CallRequestContainerBase>```, which you can dynamic_cast to a CallRequestContainer
    * ```CallRequestContainer* container = dynamic_cast<CallRequestContainer*>(requestContainer.get());```
    * The ```container.GetApiSettings()``` will allow you to access the apiSettings
* CallRequestContainer constructor parameters have been reordered and must provide a new shared_ptr<PlayFabAuthenticationContext>
    * It's very likely that CallRequestContainer objects are only created in PlayFab code
    * If you are, then you will need to find and pass the relevant PlayFabAuthenticationContext into that constructor
    * PlayFabAuthenticationContext contains vital information, and PlayFab API calls can't be completed without it
* Some API instances will throw a new PlayFabException if the shared_ptr<PlayFabAuthenticationContext> inputs are null
    * PlayFabClientInstanceApi does not require a ```shared_ptr<PlayFabAuthenticationContext>``` input (it will create its own)
    * To create most others, call ```PlayFabClientInstanceApi.GetAuthenticationContext()```, and pass that context into the other apiInstance constructor.
    * This will bind those apiInstances to the same player, allowing you to access different types of information about that player

## Trivial changes that should affect very few customers

* Old: ```PlayFabAuthenticationContext->developerSecretKey```
    * New: ```PlayFabApiSettings->developerSecretKey```
* Old: ```PlayFabSettings::requestParams```
    * New: ```PlayFabApiSettings->requestParams```
* Old: ```PlayFabSettings::entityToken```
    * New: ```PlayFabAuthenticationContext->IsEntityLoggedIn()``` or
    * New: ```PlayFabAuthenticationContext->entityToken```
* Old: ```PlayFabSettings::clientSessionTicket```
    * New: ```PlayFabAuthenticationContext->IsClientLoggedIn()``` or
    * New: ```PlayFabAuthenticationContext->clientSessionTicket```
* Old: ```PlayFabSettings::disableAdvertising```
    * New: ```PlayFabAuthenticationContext->disableAdvertising```
* Old: ```PlayFabSettings::advertisingIdType```
    * New: ```PlayFabAuthenticationContext->advertisingIdType```
* Old: ```PlayFabSettings::advertisingIdValue```
    * New: ```PlayFabAuthenticationContext->advertisingIdValue```
* Old: ```PlayFabApiSettings->disableAdvertising```
    * New: ```PlayFabAuthenticationContext->disableAdvertising```
* Old: ```PlayFabApiSettings->advertisingIdType```
    * New: ```PlayFabAuthenticationContext->advertisingIdType```
* Old: ```PlayFabApiSettings->advertisingIdValue```
    * New: ```PlayFabAuthenticationContext->advertisingIdValue```
* Old: ```PlayFabSettings::GetUrl()```
    * New: ```PlayFabApiSettings->GetUrl()```
* Old: ```PlayFabSettings::verticalName```
    * (Delete any reference to this, it never worked in public code)
* Old: ```PlayFabApiSettings->verticalName```
    * (Delete any reference to this, it never worked in public code)
* Old: ```PlayFabApiSettings->useDevelopmentEnvironment ```
    * (Delete any reference to this, it's not been relevant/useful for several years)
* Old: ```PlayFabApiSettings->developmentEnvironmentURL```
    * (Delete any reference to this, it's not been relevant/useful for several years)
    * Just replace the ```PlayFabSettings::productionEnvironmentURL``` directly
* Old: catch (std::runtime_error)
    * New: catch (PlayFabException)
    * (For a few very PlayFab specific errors, thrown directly by the SDK
    * Any non-PlayFab exception thrown by STL objects/methods will be unchanged
* We altered the text output of our SDK internal testing scripts, which should not affect customers directly
* If you are setting advertisingIdType and advertisingIdValue on api instances, MultiStepClientLogin may succeed and/or provide correct attribution, where it could previously fail silently, or provide attribution to the wrong split-screen player


    
