#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace AddonModels
    {
        // Addon Enums
        // Addon Classes
        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            std::string Type;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type)
            {}

            ~EntityKey() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct CreateOrUpdateAppleRequest : public PlayFabRequestCommon
        {
            Boxed<bool> AllowProduction;
            Boxed<bool> AllowSandbox;
            std::string AppBundleId;
            std::string AppId;
            std::string AppSharedSecret;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            Boxed<bool> ErrorIfExists;
            Boxed<bool> IgnoreExpirationDate;
            std::string IssuerId;
            std::string KeyId;
            std::string PrivateKey;
            Boxed<bool> RequireSecureAuthentication;

            CreateOrUpdateAppleRequest() :
                PlayFabRequestCommon(),
                AllowProduction(),
                AllowSandbox(),
                AppBundleId(),
                AppId(),
                AppSharedSecret(),
                CustomTags(),
                Entity(),
                ErrorIfExists(),
                IgnoreExpirationDate(),
                IssuerId(),
                KeyId(),
                PrivateKey(),
                RequireSecureAuthentication()
            {}

            CreateOrUpdateAppleRequest(const CreateOrUpdateAppleRequest& src) :
                PlayFabRequestCommon(),
                AllowProduction(src.AllowProduction),
                AllowSandbox(src.AllowSandbox),
                AppBundleId(src.AppBundleId),
                AppId(src.AppId),
                AppSharedSecret(src.AppSharedSecret),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ErrorIfExists(src.ErrorIfExists),
                IgnoreExpirationDate(src.IgnoreExpirationDate),
                IssuerId(src.IssuerId),
                KeyId(src.KeyId),
                PrivateKey(src.PrivateKey),
                RequireSecureAuthentication(src.RequireSecureAuthentication)
            {}

            ~CreateOrUpdateAppleRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["AllowProduction"], AllowProduction);
                FromJsonUtilP(input["AllowSandbox"], AllowSandbox);
                FromJsonUtilS(input["AppBundleId"], AppBundleId);
                FromJsonUtilS(input["AppId"], AppId);
                FromJsonUtilS(input["AppSharedSecret"], AppSharedSecret);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
                FromJsonUtilP(input["IgnoreExpirationDate"], IgnoreExpirationDate);
                FromJsonUtilS(input["IssuerId"], IssuerId);
                FromJsonUtilS(input["KeyId"], KeyId);
                FromJsonUtilS(input["PrivateKey"], PrivateKey);
                FromJsonUtilP(input["RequireSecureAuthentication"], RequireSecureAuthentication);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AllowProduction; ToJsonUtilP(AllowProduction, each_AllowProduction); output["AllowProduction"] = each_AllowProduction;
                Json::Value each_AllowSandbox; ToJsonUtilP(AllowSandbox, each_AllowSandbox); output["AllowSandbox"] = each_AllowSandbox;
                Json::Value each_AppBundleId; ToJsonUtilS(AppBundleId, each_AppBundleId); output["AppBundleId"] = each_AppBundleId;
                Json::Value each_AppId; ToJsonUtilS(AppId, each_AppId); output["AppId"] = each_AppId;
                Json::Value each_AppSharedSecret; ToJsonUtilS(AppSharedSecret, each_AppSharedSecret); output["AppSharedSecret"] = each_AppSharedSecret;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                Json::Value each_IgnoreExpirationDate; ToJsonUtilP(IgnoreExpirationDate, each_IgnoreExpirationDate); output["IgnoreExpirationDate"] = each_IgnoreExpirationDate;
                Json::Value each_IssuerId; ToJsonUtilS(IssuerId, each_IssuerId); output["IssuerId"] = each_IssuerId;
                Json::Value each_KeyId; ToJsonUtilS(KeyId, each_KeyId); output["KeyId"] = each_KeyId;
                Json::Value each_PrivateKey; ToJsonUtilS(PrivateKey, each_PrivateKey); output["PrivateKey"] = each_PrivateKey;
                Json::Value each_RequireSecureAuthentication; ToJsonUtilP(RequireSecureAuthentication, each_RequireSecureAuthentication); output["RequireSecureAuthentication"] = each_RequireSecureAuthentication;
                return output;
            }
        };

        struct CreateOrUpdateAppleResponse : public PlayFabResultCommon
        {

            CreateOrUpdateAppleResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateAppleResponse(const CreateOrUpdateAppleResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateAppleResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateOrUpdateFacebookInstantGamesRequest : public PlayFabRequestCommon
        {
            std::string AppID;
            std::string AppSecret;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            Boxed<bool> ErrorIfExists;

            CreateOrUpdateFacebookInstantGamesRequest() :
                PlayFabRequestCommon(),
                AppID(),
                AppSecret(),
                CustomTags(),
                Entity(),
                ErrorIfExists()
            {}

            CreateOrUpdateFacebookInstantGamesRequest(const CreateOrUpdateFacebookInstantGamesRequest& src) :
                PlayFabRequestCommon(),
                AppID(src.AppID),
                AppSecret(src.AppSecret),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ErrorIfExists(src.ErrorIfExists)
            {}

            ~CreateOrUpdateFacebookInstantGamesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AppID"], AppID);
                FromJsonUtilS(input["AppSecret"], AppSecret);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AppID; ToJsonUtilS(AppID, each_AppID); output["AppID"] = each_AppID;
                Json::Value each_AppSecret; ToJsonUtilS(AppSecret, each_AppSecret); output["AppSecret"] = each_AppSecret;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                return output;
            }
        };

        struct CreateOrUpdateFacebookInstantGamesResponse : public PlayFabResultCommon
        {

            CreateOrUpdateFacebookInstantGamesResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateFacebookInstantGamesResponse(const CreateOrUpdateFacebookInstantGamesResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateFacebookInstantGamesResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateOrUpdateFacebookRequest : public PlayFabRequestCommon
        {
            std::string AppID;
            std::string AppSecret;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            Boxed<bool> ErrorIfExists;
            std::string NotificationEmail;

            CreateOrUpdateFacebookRequest() :
                PlayFabRequestCommon(),
                AppID(),
                AppSecret(),
                CustomTags(),
                Entity(),
                ErrorIfExists(),
                NotificationEmail()
            {}

            CreateOrUpdateFacebookRequest(const CreateOrUpdateFacebookRequest& src) :
                PlayFabRequestCommon(),
                AppID(src.AppID),
                AppSecret(src.AppSecret),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ErrorIfExists(src.ErrorIfExists),
                NotificationEmail(src.NotificationEmail)
            {}

            ~CreateOrUpdateFacebookRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AppID"], AppID);
                FromJsonUtilS(input["AppSecret"], AppSecret);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
                FromJsonUtilS(input["NotificationEmail"], NotificationEmail);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AppID; ToJsonUtilS(AppID, each_AppID); output["AppID"] = each_AppID;
                Json::Value each_AppSecret; ToJsonUtilS(AppSecret, each_AppSecret); output["AppSecret"] = each_AppSecret;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                Json::Value each_NotificationEmail; ToJsonUtilS(NotificationEmail, each_NotificationEmail); output["NotificationEmail"] = each_NotificationEmail;
                return output;
            }
        };

        struct CreateOrUpdateFacebookResponse : public PlayFabResultCommon
        {

            CreateOrUpdateFacebookResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateFacebookResponse(const CreateOrUpdateFacebookResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateFacebookResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateOrUpdateGoogleRequest : public PlayFabRequestCommon
        {
            std::string AppLicenseKey;
            std::string AppPackageID;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            Boxed<bool> ErrorIfExists;
            std::string OAuthClientID;
            std::string OAuthClientSecret;
            std::string OAuthCustomRedirectUri;
            std::string ServiceAccountKey;

            CreateOrUpdateGoogleRequest() :
                PlayFabRequestCommon(),
                AppLicenseKey(),
                AppPackageID(),
                CustomTags(),
                Entity(),
                ErrorIfExists(),
                OAuthClientID(),
                OAuthClientSecret(),
                OAuthCustomRedirectUri(),
                ServiceAccountKey()
            {}

            CreateOrUpdateGoogleRequest(const CreateOrUpdateGoogleRequest& src) :
                PlayFabRequestCommon(),
                AppLicenseKey(src.AppLicenseKey),
                AppPackageID(src.AppPackageID),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ErrorIfExists(src.ErrorIfExists),
                OAuthClientID(src.OAuthClientID),
                OAuthClientSecret(src.OAuthClientSecret),
                OAuthCustomRedirectUri(src.OAuthCustomRedirectUri),
                ServiceAccountKey(src.ServiceAccountKey)
            {}

            ~CreateOrUpdateGoogleRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AppLicenseKey"], AppLicenseKey);
                FromJsonUtilS(input["AppPackageID"], AppPackageID);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
                FromJsonUtilS(input["OAuthClientID"], OAuthClientID);
                FromJsonUtilS(input["OAuthClientSecret"], OAuthClientSecret);
                FromJsonUtilS(input["OAuthCustomRedirectUri"], OAuthCustomRedirectUri);
                FromJsonUtilS(input["ServiceAccountKey"], ServiceAccountKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AppLicenseKey; ToJsonUtilS(AppLicenseKey, each_AppLicenseKey); output["AppLicenseKey"] = each_AppLicenseKey;
                Json::Value each_AppPackageID; ToJsonUtilS(AppPackageID, each_AppPackageID); output["AppPackageID"] = each_AppPackageID;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                Json::Value each_OAuthClientID; ToJsonUtilS(OAuthClientID, each_OAuthClientID); output["OAuthClientID"] = each_OAuthClientID;
                Json::Value each_OAuthClientSecret; ToJsonUtilS(OAuthClientSecret, each_OAuthClientSecret); output["OAuthClientSecret"] = each_OAuthClientSecret;
                Json::Value each_OAuthCustomRedirectUri; ToJsonUtilS(OAuthCustomRedirectUri, each_OAuthCustomRedirectUri); output["OAuthCustomRedirectUri"] = each_OAuthCustomRedirectUri;
                Json::Value each_ServiceAccountKey; ToJsonUtilS(ServiceAccountKey, each_ServiceAccountKey); output["ServiceAccountKey"] = each_ServiceAccountKey;
                return output;
            }
        };

        struct CreateOrUpdateGoogleResponse : public PlayFabResultCommon
        {

            CreateOrUpdateGoogleResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateGoogleResponse(const CreateOrUpdateGoogleResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateGoogleResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateOrUpdateKongregateRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            Boxed<bool> ErrorIfExists;
            std::string SecretAPIKey;

            CreateOrUpdateKongregateRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                ErrorIfExists(),
                SecretAPIKey()
            {}

            CreateOrUpdateKongregateRequest(const CreateOrUpdateKongregateRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ErrorIfExists(src.ErrorIfExists),
                SecretAPIKey(src.SecretAPIKey)
            {}

            ~CreateOrUpdateKongregateRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
                FromJsonUtilS(input["SecretAPIKey"], SecretAPIKey);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                Json::Value each_SecretAPIKey; ToJsonUtilS(SecretAPIKey, each_SecretAPIKey); output["SecretAPIKey"] = each_SecretAPIKey;
                return output;
            }
        };

        struct CreateOrUpdateKongregateResponse : public PlayFabResultCommon
        {

            CreateOrUpdateKongregateResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateKongregateResponse(const CreateOrUpdateKongregateResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateKongregateResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct NintendoEnvironment : public PlayFabBaseModel
        {
            std::string ClientID;
            std::string ClientSecret;
            std::string ID;

            NintendoEnvironment() :
                PlayFabBaseModel(),
                ClientID(),
                ClientSecret(),
                ID()
            {}

            NintendoEnvironment(const NintendoEnvironment& src) :
                PlayFabBaseModel(),
                ClientID(src.ClientID),
                ClientSecret(src.ClientSecret),
                ID(src.ID)
            {}

            ~NintendoEnvironment() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ClientID"], ClientID);
                FromJsonUtilS(input["ClientSecret"], ClientSecret);
                FromJsonUtilS(input["ID"], ID);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ClientID; ToJsonUtilS(ClientID, each_ClientID); output["ClientID"] = each_ClientID;
                Json::Value each_ClientSecret; ToJsonUtilS(ClientSecret, each_ClientSecret); output["ClientSecret"] = each_ClientSecret;
                Json::Value each_ID; ToJsonUtilS(ID, each_ID); output["ID"] = each_ID;
                return output;
            }
        };

        struct CreateOrUpdateNintendoRequest : public PlayFabRequestCommon
        {
            std::string ApplicationID;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::list<NintendoEnvironment> Environments;
            Boxed<bool> ErrorIfExists;

            CreateOrUpdateNintendoRequest() :
                PlayFabRequestCommon(),
                ApplicationID(),
                CustomTags(),
                Entity(),
                Environments(),
                ErrorIfExists()
            {}

            CreateOrUpdateNintendoRequest(const CreateOrUpdateNintendoRequest& src) :
                PlayFabRequestCommon(),
                ApplicationID(src.ApplicationID),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Environments(src.Environments),
                ErrorIfExists(src.ErrorIfExists)
            {}

            ~CreateOrUpdateNintendoRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ApplicationID"], ApplicationID);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Environments"], Environments);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ApplicationID; ToJsonUtilS(ApplicationID, each_ApplicationID); output["ApplicationID"] = each_ApplicationID;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Environments; ToJsonUtilO(Environments, each_Environments); output["Environments"] = each_Environments;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                return output;
            }
        };

        struct CreateOrUpdateNintendoResponse : public PlayFabResultCommon
        {

            CreateOrUpdateNintendoResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateNintendoResponse(const CreateOrUpdateNintendoResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateNintendoResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateOrUpdatePSNRequest : public PlayFabRequestCommon
        {
            std::string ClientID;
            std::string ClientSecret;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            Boxed<bool> ErrorIfExists;
            std::string NextGenClientID;
            std::string NextGenClientSecret;

            CreateOrUpdatePSNRequest() :
                PlayFabRequestCommon(),
                ClientID(),
                ClientSecret(),
                CustomTags(),
                Entity(),
                ErrorIfExists(),
                NextGenClientID(),
                NextGenClientSecret()
            {}

            CreateOrUpdatePSNRequest(const CreateOrUpdatePSNRequest& src) :
                PlayFabRequestCommon(),
                ClientID(src.ClientID),
                ClientSecret(src.ClientSecret),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ErrorIfExists(src.ErrorIfExists),
                NextGenClientID(src.NextGenClientID),
                NextGenClientSecret(src.NextGenClientSecret)
            {}

            ~CreateOrUpdatePSNRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ClientID"], ClientID);
                FromJsonUtilS(input["ClientSecret"], ClientSecret);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
                FromJsonUtilS(input["NextGenClientID"], NextGenClientID);
                FromJsonUtilS(input["NextGenClientSecret"], NextGenClientSecret);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ClientID; ToJsonUtilS(ClientID, each_ClientID); output["ClientID"] = each_ClientID;
                Json::Value each_ClientSecret; ToJsonUtilS(ClientSecret, each_ClientSecret); output["ClientSecret"] = each_ClientSecret;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                Json::Value each_NextGenClientID; ToJsonUtilS(NextGenClientID, each_NextGenClientID); output["NextGenClientID"] = each_NextGenClientID;
                Json::Value each_NextGenClientSecret; ToJsonUtilS(NextGenClientSecret, each_NextGenClientSecret); output["NextGenClientSecret"] = each_NextGenClientSecret;
                return output;
            }
        };

        struct CreateOrUpdatePSNResponse : public PlayFabResultCommon
        {

            CreateOrUpdatePSNResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdatePSNResponse(const CreateOrUpdatePSNResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdatePSNResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateOrUpdateSteamRequest : public PlayFabRequestCommon
        {
            std::string ApplicationId;
            std::map<std::string, std::string> CustomTags;
            Boxed<bool> EnforceServiceSpecificTickets;
            Boxed<EntityKey> Entity;
            Boxed<bool> ErrorIfExists;
            std::string SecretKey;
            Boxed<bool> UseSandbox;

            CreateOrUpdateSteamRequest() :
                PlayFabRequestCommon(),
                ApplicationId(),
                CustomTags(),
                EnforceServiceSpecificTickets(),
                Entity(),
                ErrorIfExists(),
                SecretKey(),
                UseSandbox()
            {}

            CreateOrUpdateSteamRequest(const CreateOrUpdateSteamRequest& src) :
                PlayFabRequestCommon(),
                ApplicationId(src.ApplicationId),
                CustomTags(src.CustomTags),
                EnforceServiceSpecificTickets(src.EnforceServiceSpecificTickets),
                Entity(src.Entity),
                ErrorIfExists(src.ErrorIfExists),
                SecretKey(src.SecretKey),
                UseSandbox(src.UseSandbox)
            {}

            ~CreateOrUpdateSteamRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ApplicationId"], ApplicationId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["EnforceServiceSpecificTickets"], EnforceServiceSpecificTickets);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
                FromJsonUtilS(input["SecretKey"], SecretKey);
                FromJsonUtilP(input["UseSandbox"], UseSandbox);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ApplicationId; ToJsonUtilS(ApplicationId, each_ApplicationId); output["ApplicationId"] = each_ApplicationId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EnforceServiceSpecificTickets; ToJsonUtilP(EnforceServiceSpecificTickets, each_EnforceServiceSpecificTickets); output["EnforceServiceSpecificTickets"] = each_EnforceServiceSpecificTickets;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                Json::Value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output["SecretKey"] = each_SecretKey;
                Json::Value each_UseSandbox; ToJsonUtilP(UseSandbox, each_UseSandbox); output["UseSandbox"] = each_UseSandbox;
                return output;
            }
        };

        struct CreateOrUpdateSteamResponse : public PlayFabResultCommon
        {

            CreateOrUpdateSteamResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateSteamResponse(const CreateOrUpdateSteamResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateSteamResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateOrUpdateToxModRequest : public PlayFabRequestCommon
        {
            std::string AccountId;
            std::string AccountKey;
            std::map<std::string, std::string> CustomTags;
            bool Enabled;
            Boxed<EntityKey> Entity;
            Boxed<bool> ErrorIfExists;

            CreateOrUpdateToxModRequest() :
                PlayFabRequestCommon(),
                AccountId(),
                AccountKey(),
                CustomTags(),
                Enabled(),
                Entity(),
                ErrorIfExists()
            {}

            CreateOrUpdateToxModRequest(const CreateOrUpdateToxModRequest& src) :
                PlayFabRequestCommon(),
                AccountId(src.AccountId),
                AccountKey(src.AccountKey),
                CustomTags(src.CustomTags),
                Enabled(src.Enabled),
                Entity(src.Entity),
                ErrorIfExists(src.ErrorIfExists)
            {}

            ~CreateOrUpdateToxModRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AccountId"], AccountId);
                FromJsonUtilS(input["AccountKey"], AccountKey);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["Enabled"], Enabled);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccountId; ToJsonUtilS(AccountId, each_AccountId); output["AccountId"] = each_AccountId;
                Json::Value each_AccountKey; ToJsonUtilS(AccountKey, each_AccountKey); output["AccountKey"] = each_AccountKey;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Enabled; ToJsonUtilP(Enabled, each_Enabled); output["Enabled"] = each_Enabled;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                return output;
            }
        };

        struct CreateOrUpdateToxModResponse : public PlayFabResultCommon
        {

            CreateOrUpdateToxModResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateToxModResponse(const CreateOrUpdateToxModResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateToxModResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateOrUpdateTwitchRequest : public PlayFabRequestCommon
        {
            std::string ClientID;
            std::string ClientSecret;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            Boxed<bool> ErrorIfExists;

            CreateOrUpdateTwitchRequest() :
                PlayFabRequestCommon(),
                ClientID(),
                ClientSecret(),
                CustomTags(),
                Entity(),
                ErrorIfExists()
            {}

            CreateOrUpdateTwitchRequest(const CreateOrUpdateTwitchRequest& src) :
                PlayFabRequestCommon(),
                ClientID(src.ClientID),
                ClientSecret(src.ClientSecret),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ErrorIfExists(src.ErrorIfExists)
            {}

            ~CreateOrUpdateTwitchRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ClientID"], ClientID);
                FromJsonUtilS(input["ClientSecret"], ClientSecret);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilP(input["ErrorIfExists"], ErrorIfExists);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ClientID; ToJsonUtilS(ClientID, each_ClientID); output["ClientID"] = each_ClientID;
                Json::Value each_ClientSecret; ToJsonUtilS(ClientSecret, each_ClientSecret); output["ClientSecret"] = each_ClientSecret;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ErrorIfExists; ToJsonUtilP(ErrorIfExists, each_ErrorIfExists); output["ErrorIfExists"] = each_ErrorIfExists;
                return output;
            }
        };

        struct CreateOrUpdateTwitchResponse : public PlayFabResultCommon
        {

            CreateOrUpdateTwitchResponse() :
                PlayFabResultCommon()
            {}

            CreateOrUpdateTwitchResponse(const CreateOrUpdateTwitchResponse&) :
                PlayFabResultCommon()
            {}

            ~CreateOrUpdateTwitchResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteAppleRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteAppleRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteAppleRequest(const DeleteAppleRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteAppleRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteAppleResponse : public PlayFabResultCommon
        {

            DeleteAppleResponse() :
                PlayFabResultCommon()
            {}

            DeleteAppleResponse(const DeleteAppleResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteAppleResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteFacebookInstantGamesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteFacebookInstantGamesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteFacebookInstantGamesRequest(const DeleteFacebookInstantGamesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteFacebookInstantGamesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteFacebookInstantGamesResponse : public PlayFabResultCommon
        {

            DeleteFacebookInstantGamesResponse() :
                PlayFabResultCommon()
            {}

            DeleteFacebookInstantGamesResponse(const DeleteFacebookInstantGamesResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteFacebookInstantGamesResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteFacebookRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteFacebookRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteFacebookRequest(const DeleteFacebookRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteFacebookRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteFacebookResponse : public PlayFabResultCommon
        {

            DeleteFacebookResponse() :
                PlayFabResultCommon()
            {}

            DeleteFacebookResponse(const DeleteFacebookResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteFacebookResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteGoogleRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteGoogleRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteGoogleRequest(const DeleteGoogleRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteGoogleRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteGoogleResponse : public PlayFabResultCommon
        {

            DeleteGoogleResponse() :
                PlayFabResultCommon()
            {}

            DeleteGoogleResponse(const DeleteGoogleResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteGoogleResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteKongregateRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteKongregateRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteKongregateRequest(const DeleteKongregateRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteKongregateRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteKongregateResponse : public PlayFabResultCommon
        {

            DeleteKongregateResponse() :
                PlayFabResultCommon()
            {}

            DeleteKongregateResponse(const DeleteKongregateResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteKongregateResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteNintendoRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteNintendoRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteNintendoRequest(const DeleteNintendoRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteNintendoRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteNintendoResponse : public PlayFabResultCommon
        {

            DeleteNintendoResponse() :
                PlayFabResultCommon()
            {}

            DeleteNintendoResponse(const DeleteNintendoResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteNintendoResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeletePSNRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeletePSNRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeletePSNRequest(const DeletePSNRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeletePSNRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeletePSNResponse : public PlayFabResultCommon
        {

            DeletePSNResponse() :
                PlayFabResultCommon()
            {}

            DeletePSNResponse(const DeletePSNResponse&) :
                PlayFabResultCommon()
            {}

            ~DeletePSNResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteSteamRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteSteamRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteSteamRequest(const DeleteSteamRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteSteamRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteSteamResponse : public PlayFabResultCommon
        {

            DeleteSteamResponse() :
                PlayFabResultCommon()
            {}

            DeleteSteamResponse(const DeleteSteamResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteSteamResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteToxModRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteToxModRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteToxModRequest(const DeleteToxModRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteToxModRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteToxModResponse : public PlayFabResultCommon
        {

            DeleteToxModResponse() :
                PlayFabResultCommon()
            {}

            DeleteToxModResponse(const DeleteToxModResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteToxModResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteTwitchRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteTwitchRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteTwitchRequest(const DeleteTwitchRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteTwitchRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteTwitchResponse : public PlayFabResultCommon
        {

            DeleteTwitchResponse() :
                PlayFabResultCommon()
            {}

            DeleteTwitchResponse(const DeleteTwitchResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteTwitchResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct GetAppleRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetAppleRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetAppleRequest(const GetAppleRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetAppleRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetAppleResponse : public PlayFabResultCommon
        {
            std::string AppBundleId;
            bool Created;
            Boxed<bool> IgnoreExpirationDate;
            Boxed<bool> RequireSecureAuthentication;

            GetAppleResponse() :
                PlayFabResultCommon(),
                AppBundleId(),
                Created(),
                IgnoreExpirationDate(),
                RequireSecureAuthentication()
            {}

            GetAppleResponse(const GetAppleResponse& src) :
                PlayFabResultCommon(),
                AppBundleId(src.AppBundleId),
                Created(src.Created),
                IgnoreExpirationDate(src.IgnoreExpirationDate),
                RequireSecureAuthentication(src.RequireSecureAuthentication)
            {}

            ~GetAppleResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AppBundleId"], AppBundleId);
                FromJsonUtilP(input["Created"], Created);
                FromJsonUtilP(input["IgnoreExpirationDate"], IgnoreExpirationDate);
                FromJsonUtilP(input["RequireSecureAuthentication"], RequireSecureAuthentication);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AppBundleId; ToJsonUtilS(AppBundleId, each_AppBundleId); output["AppBundleId"] = each_AppBundleId;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_IgnoreExpirationDate; ToJsonUtilP(IgnoreExpirationDate, each_IgnoreExpirationDate); output["IgnoreExpirationDate"] = each_IgnoreExpirationDate;
                Json::Value each_RequireSecureAuthentication; ToJsonUtilP(RequireSecureAuthentication, each_RequireSecureAuthentication); output["RequireSecureAuthentication"] = each_RequireSecureAuthentication;
                return output;
            }
        };

        struct GetFacebookInstantGamesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetFacebookInstantGamesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetFacebookInstantGamesRequest(const GetFacebookInstantGamesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetFacebookInstantGamesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetFacebookInstantGamesResponse : public PlayFabResultCommon
        {
            std::string AppID;
            bool Created;

            GetFacebookInstantGamesResponse() :
                PlayFabResultCommon(),
                AppID(),
                Created()
            {}

            GetFacebookInstantGamesResponse(const GetFacebookInstantGamesResponse& src) :
                PlayFabResultCommon(),
                AppID(src.AppID),
                Created(src.Created)
            {}

            ~GetFacebookInstantGamesResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AppID"], AppID);
                FromJsonUtilP(input["Created"], Created);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AppID; ToJsonUtilS(AppID, each_AppID); output["AppID"] = each_AppID;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                return output;
            }
        };

        struct GetFacebookRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetFacebookRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetFacebookRequest(const GetFacebookRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetFacebookRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetFacebookResponse : public PlayFabResultCommon
        {
            std::string AppID;
            bool Created;
            std::string NotificationEmail;

            GetFacebookResponse() :
                PlayFabResultCommon(),
                AppID(),
                Created(),
                NotificationEmail()
            {}

            GetFacebookResponse(const GetFacebookResponse& src) :
                PlayFabResultCommon(),
                AppID(src.AppID),
                Created(src.Created),
                NotificationEmail(src.NotificationEmail)
            {}

            ~GetFacebookResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AppID"], AppID);
                FromJsonUtilP(input["Created"], Created);
                FromJsonUtilS(input["NotificationEmail"], NotificationEmail);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AppID; ToJsonUtilS(AppID, each_AppID); output["AppID"] = each_AppID;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_NotificationEmail; ToJsonUtilS(NotificationEmail, each_NotificationEmail); output["NotificationEmail"] = each_NotificationEmail;
                return output;
            }
        };

        struct GetGoogleRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetGoogleRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetGoogleRequest(const GetGoogleRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetGoogleRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetGoogleResponse : public PlayFabResultCommon
        {
            std::string AppPackageID;
            bool Created;
            std::string OAuthClientID;
            std::string OauthCustomRedirectUri;

            GetGoogleResponse() :
                PlayFabResultCommon(),
                AppPackageID(),
                Created(),
                OAuthClientID(),
                OauthCustomRedirectUri()
            {}

            GetGoogleResponse(const GetGoogleResponse& src) :
                PlayFabResultCommon(),
                AppPackageID(src.AppPackageID),
                Created(src.Created),
                OAuthClientID(src.OAuthClientID),
                OauthCustomRedirectUri(src.OauthCustomRedirectUri)
            {}

            ~GetGoogleResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AppPackageID"], AppPackageID);
                FromJsonUtilP(input["Created"], Created);
                FromJsonUtilS(input["OAuthClientID"], OAuthClientID);
                FromJsonUtilS(input["OauthCustomRedirectUri"], OauthCustomRedirectUri);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AppPackageID; ToJsonUtilS(AppPackageID, each_AppPackageID); output["AppPackageID"] = each_AppPackageID;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_OAuthClientID; ToJsonUtilS(OAuthClientID, each_OAuthClientID); output["OAuthClientID"] = each_OAuthClientID;
                Json::Value each_OauthCustomRedirectUri; ToJsonUtilS(OauthCustomRedirectUri, each_OauthCustomRedirectUri); output["OauthCustomRedirectUri"] = each_OauthCustomRedirectUri;
                return output;
            }
        };

        struct GetKongregateRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetKongregateRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetKongregateRequest(const GetKongregateRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetKongregateRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetKongregateResponse : public PlayFabResultCommon
        {
            bool Created;

            GetKongregateResponse() :
                PlayFabResultCommon(),
                Created()
            {}

            GetKongregateResponse(const GetKongregateResponse& src) :
                PlayFabResultCommon(),
                Created(src.Created)
            {}

            ~GetKongregateResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Created"], Created);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                return output;
            }
        };

        struct GetNintendoRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetNintendoRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetNintendoRequest(const GetNintendoRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetNintendoRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetNintendoResponse : public PlayFabResultCommon
        {
            std::string ApplicationID;
            bool Created;
            std::list<NintendoEnvironment> Environments;

            GetNintendoResponse() :
                PlayFabResultCommon(),
                ApplicationID(),
                Created(),
                Environments()
            {}

            GetNintendoResponse(const GetNintendoResponse& src) :
                PlayFabResultCommon(),
                ApplicationID(src.ApplicationID),
                Created(src.Created),
                Environments(src.Environments)
            {}

            ~GetNintendoResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ApplicationID"], ApplicationID);
                FromJsonUtilP(input["Created"], Created);
                FromJsonUtilO(input["Environments"], Environments);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ApplicationID; ToJsonUtilS(ApplicationID, each_ApplicationID); output["ApplicationID"] = each_ApplicationID;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_Environments; ToJsonUtilO(Environments, each_Environments); output["Environments"] = each_Environments;
                return output;
            }
        };

        struct GetPSNRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetPSNRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetPSNRequest(const GetPSNRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetPSNRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetPSNResponse : public PlayFabResultCommon
        {
            std::string ClientID;
            bool Created;
            std::string NextGenClientID;

            GetPSNResponse() :
                PlayFabResultCommon(),
                ClientID(),
                Created(),
                NextGenClientID()
            {}

            GetPSNResponse(const GetPSNResponse& src) :
                PlayFabResultCommon(),
                ClientID(src.ClientID),
                Created(src.Created),
                NextGenClientID(src.NextGenClientID)
            {}

            ~GetPSNResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ClientID"], ClientID);
                FromJsonUtilP(input["Created"], Created);
                FromJsonUtilS(input["NextGenClientID"], NextGenClientID);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ClientID; ToJsonUtilS(ClientID, each_ClientID); output["ClientID"] = each_ClientID;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_NextGenClientID; ToJsonUtilS(NextGenClientID, each_NextGenClientID); output["NextGenClientID"] = each_NextGenClientID;
                return output;
            }
        };

        struct GetSteamRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetSteamRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetSteamRequest(const GetSteamRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetSteamRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetSteamResponse : public PlayFabResultCommon
        {
            std::string ApplicationId;
            bool Created;
            Boxed<bool> EnforceServiceSpecificTickets;
            Boxed<bool> UseSandbox;

            GetSteamResponse() :
                PlayFabResultCommon(),
                ApplicationId(),
                Created(),
                EnforceServiceSpecificTickets(),
                UseSandbox()
            {}

            GetSteamResponse(const GetSteamResponse& src) :
                PlayFabResultCommon(),
                ApplicationId(src.ApplicationId),
                Created(src.Created),
                EnforceServiceSpecificTickets(src.EnforceServiceSpecificTickets),
                UseSandbox(src.UseSandbox)
            {}

            ~GetSteamResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ApplicationId"], ApplicationId);
                FromJsonUtilP(input["Created"], Created);
                FromJsonUtilP(input["EnforceServiceSpecificTickets"], EnforceServiceSpecificTickets);
                FromJsonUtilP(input["UseSandbox"], UseSandbox);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ApplicationId; ToJsonUtilS(ApplicationId, each_ApplicationId); output["ApplicationId"] = each_ApplicationId;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_EnforceServiceSpecificTickets; ToJsonUtilP(EnforceServiceSpecificTickets, each_EnforceServiceSpecificTickets); output["EnforceServiceSpecificTickets"] = each_EnforceServiceSpecificTickets;
                Json::Value each_UseSandbox; ToJsonUtilP(UseSandbox, each_UseSandbox); output["UseSandbox"] = each_UseSandbox;
                return output;
            }
        };

        struct GetToxModRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetToxModRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetToxModRequest(const GetToxModRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetToxModRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetToxModResponse : public PlayFabResultCommon
        {
            std::string AccountId;
            std::string AccountKey;
            bool Created;
            bool Enabled;

            GetToxModResponse() :
                PlayFabResultCommon(),
                AccountId(),
                AccountKey(),
                Created(),
                Enabled()
            {}

            GetToxModResponse(const GetToxModResponse& src) :
                PlayFabResultCommon(),
                AccountId(src.AccountId),
                AccountKey(src.AccountKey),
                Created(src.Created),
                Enabled(src.Enabled)
            {}

            ~GetToxModResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AccountId"], AccountId);
                FromJsonUtilS(input["AccountKey"], AccountKey);
                FromJsonUtilP(input["Created"], Created);
                FromJsonUtilP(input["Enabled"], Enabled);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccountId; ToJsonUtilS(AccountId, each_AccountId); output["AccountId"] = each_AccountId;
                Json::Value each_AccountKey; ToJsonUtilS(AccountKey, each_AccountKey); output["AccountKey"] = each_AccountKey;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_Enabled; ToJsonUtilP(Enabled, each_Enabled); output["Enabled"] = each_Enabled;
                return output;
            }
        };

        struct GetTwitchRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetTwitchRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetTwitchRequest(const GetTwitchRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetTwitchRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetTwitchResponse : public PlayFabResultCommon
        {
            std::string ClientID;
            bool Created;

            GetTwitchResponse() :
                PlayFabResultCommon(),
                ClientID(),
                Created()
            {}

            GetTwitchResponse(const GetTwitchResponse& src) :
                PlayFabResultCommon(),
                ClientID(src.ClientID),
                Created(src.Created)
            {}

            ~GetTwitchResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ClientID"], ClientID);
                FromJsonUtilP(input["Created"], Created);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ClientID; ToJsonUtilS(ClientID, each_ClientID); output["ClientID"] = each_ClientID;
                Json::Value each_Created; ToJsonUtilP(Created, each_Created); output["Created"] = each_Created;
                return output;
            }
        };

    }
}

#endif
