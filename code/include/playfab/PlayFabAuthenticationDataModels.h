#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace AuthenticationModels
    {
        // Authentication Enums
        enum class IdentifiedDeviceType
        {
            IdentifiedDeviceTypeUnknown,
            IdentifiedDeviceTypeXboxOne,
            IdentifiedDeviceTypeScarlett
        };

        inline void ToJsonEnum(const IdentifiedDeviceType input, Json::Value& output)
        {
            if (input == IdentifiedDeviceType::IdentifiedDeviceTypeUnknown)
            {
                output = Json::Value("Unknown");
                return;
            }
            if (input == IdentifiedDeviceType::IdentifiedDeviceTypeXboxOne)
            {
                output = Json::Value("XboxOne");
                return;
            }
            if (input == IdentifiedDeviceType::IdentifiedDeviceTypeScarlett)
            {
                output = Json::Value("Scarlett");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, IdentifiedDeviceType& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown")
            {
                output = IdentifiedDeviceType::IdentifiedDeviceTypeUnknown;
                return;
            }
            if (inputStr == "XboxOne")
            {
                output = IdentifiedDeviceType::IdentifiedDeviceTypeXboxOne;
                return;
            }
            if (inputStr == "Scarlett")
            {
                output = IdentifiedDeviceType::IdentifiedDeviceTypeScarlett;
                return;
            }
        }

        enum class LoginIdentityProvider
        {
            LoginIdentityProviderUnknown,
            LoginIdentityProviderPlayFab,
            LoginIdentityProviderCustom,
            LoginIdentityProviderGameCenter,
            LoginIdentityProviderGooglePlay,
            LoginIdentityProviderSteam,
            LoginIdentityProviderXBoxLive,
            LoginIdentityProviderPSN,
            LoginIdentityProviderKongregate,
            LoginIdentityProviderFacebook,
            LoginIdentityProviderIOSDevice,
            LoginIdentityProviderAndroidDevice,
            LoginIdentityProviderTwitch,
            LoginIdentityProviderWindowsHello,
            LoginIdentityProviderGameServer,
            LoginIdentityProviderCustomServer,
            LoginIdentityProviderNintendoSwitch,
            LoginIdentityProviderFacebookInstantGames,
            LoginIdentityProviderOpenIdConnect,
            LoginIdentityProviderApple,
            LoginIdentityProviderNintendoSwitchAccount,
            LoginIdentityProviderGooglePlayGames
        };

        inline void ToJsonEnum(const LoginIdentityProvider input, Json::Value& output)
        {
            if (input == LoginIdentityProvider::LoginIdentityProviderUnknown)
            {
                output = Json::Value("Unknown");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderPlayFab)
            {
                output = Json::Value("PlayFab");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderCustom)
            {
                output = Json::Value("Custom");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderGameCenter)
            {
                output = Json::Value("GameCenter");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderGooglePlay)
            {
                output = Json::Value("GooglePlay");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderSteam)
            {
                output = Json::Value("Steam");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderXBoxLive)
            {
                output = Json::Value("XBoxLive");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderPSN)
            {
                output = Json::Value("PSN");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderKongregate)
            {
                output = Json::Value("Kongregate");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderFacebook)
            {
                output = Json::Value("Facebook");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderIOSDevice)
            {
                output = Json::Value("IOSDevice");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderAndroidDevice)
            {
                output = Json::Value("AndroidDevice");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderTwitch)
            {
                output = Json::Value("Twitch");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderWindowsHello)
            {
                output = Json::Value("WindowsHello");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderGameServer)
            {
                output = Json::Value("GameServer");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderCustomServer)
            {
                output = Json::Value("CustomServer");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderNintendoSwitch)
            {
                output = Json::Value("NintendoSwitch");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderFacebookInstantGames)
            {
                output = Json::Value("FacebookInstantGames");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderOpenIdConnect)
            {
                output = Json::Value("OpenIdConnect");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderApple)
            {
                output = Json::Value("Apple");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderNintendoSwitchAccount)
            {
                output = Json::Value("NintendoSwitchAccount");
                return;
            }
            if (input == LoginIdentityProvider::LoginIdentityProviderGooglePlayGames)
            {
                output = Json::Value("GooglePlayGames");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, LoginIdentityProvider& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown")
            {
                output = LoginIdentityProvider::LoginIdentityProviderUnknown;
                return;
            }
            if (inputStr == "PlayFab")
            {
                output = LoginIdentityProvider::LoginIdentityProviderPlayFab;
                return;
            }
            if (inputStr == "Custom")
            {
                output = LoginIdentityProvider::LoginIdentityProviderCustom;
                return;
            }
            if (inputStr == "GameCenter")
            {
                output = LoginIdentityProvider::LoginIdentityProviderGameCenter;
                return;
            }
            if (inputStr == "GooglePlay")
            {
                output = LoginIdentityProvider::LoginIdentityProviderGooglePlay;
                return;
            }
            if (inputStr == "Steam")
            {
                output = LoginIdentityProvider::LoginIdentityProviderSteam;
                return;
            }
            if (inputStr == "XBoxLive")
            {
                output = LoginIdentityProvider::LoginIdentityProviderXBoxLive;
                return;
            }
            if (inputStr == "PSN")
            {
                output = LoginIdentityProvider::LoginIdentityProviderPSN;
                return;
            }
            if (inputStr == "Kongregate")
            {
                output = LoginIdentityProvider::LoginIdentityProviderKongregate;
                return;
            }
            if (inputStr == "Facebook")
            {
                output = LoginIdentityProvider::LoginIdentityProviderFacebook;
                return;
            }
            if (inputStr == "IOSDevice")
            {
                output = LoginIdentityProvider::LoginIdentityProviderIOSDevice;
                return;
            }
            if (inputStr == "AndroidDevice")
            {
                output = LoginIdentityProvider::LoginIdentityProviderAndroidDevice;
                return;
            }
            if (inputStr == "Twitch")
            {
                output = LoginIdentityProvider::LoginIdentityProviderTwitch;
                return;
            }
            if (inputStr == "WindowsHello")
            {
                output = LoginIdentityProvider::LoginIdentityProviderWindowsHello;
                return;
            }
            if (inputStr == "GameServer")
            {
                output = LoginIdentityProvider::LoginIdentityProviderGameServer;
                return;
            }
            if (inputStr == "CustomServer")
            {
                output = LoginIdentityProvider::LoginIdentityProviderCustomServer;
                return;
            }
            if (inputStr == "NintendoSwitch")
            {
                output = LoginIdentityProvider::LoginIdentityProviderNintendoSwitch;
                return;
            }
            if (inputStr == "FacebookInstantGames")
            {
                output = LoginIdentityProvider::LoginIdentityProviderFacebookInstantGames;
                return;
            }
            if (inputStr == "OpenIdConnect")
            {
                output = LoginIdentityProvider::LoginIdentityProviderOpenIdConnect;
                return;
            }
            if (inputStr == "Apple")
            {
                output = LoginIdentityProvider::LoginIdentityProviderApple;
                return;
            }
            if (inputStr == "NintendoSwitchAccount")
            {
                output = LoginIdentityProvider::LoginIdentityProviderNintendoSwitchAccount;
                return;
            }
            if (inputStr == "GooglePlayGames")
            {
                output = LoginIdentityProvider::LoginIdentityProviderGooglePlayGames;
                return;
            }
        }

        // Authentication Classes
        struct AuthenticateCustomIdRequest : public PlayFabRequestCommon
        {
            std::string CustomId;
            std::map<std::string, std::string> CustomTags;

            AuthenticateCustomIdRequest() :
                PlayFabRequestCommon(),
                CustomId(),
                CustomTags()
            {}

            AuthenticateCustomIdRequest(const AuthenticateCustomIdRequest& src) :
                PlayFabRequestCommon(),
                CustomId(src.CustomId),
                CustomTags(src.CustomTags)
            {}

            ~AuthenticateCustomIdRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomId"], CustomId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output["CustomId"] = each_CustomId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

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

        struct EntityTokenResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::string EntityToken;
            Boxed<time_t> TokenExpiration;

            EntityTokenResponse() :
                PlayFabResultCommon(),
                Entity(),
                EntityToken(),
                TokenExpiration()
            {}

            EntityTokenResponse(const EntityTokenResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            ~EntityTokenResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["EntityToken"], EntityToken);
                FromJsonUtilT(input["TokenExpiration"], TokenExpiration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                Json::Value each_TokenExpiration; ToJsonUtilT(TokenExpiration, each_TokenExpiration); output["TokenExpiration"] = each_TokenExpiration;
                return output;
            }
        };

        struct AuthenticateCustomIdResult : public PlayFabResultCommon
        {
            Boxed<EntityTokenResponse> EntityToken;
            bool NewlyCreated;

            AuthenticateCustomIdResult() :
                PlayFabResultCommon(),
                EntityToken(),
                NewlyCreated()
            {}

            AuthenticateCustomIdResult(const AuthenticateCustomIdResult& src) :
                PlayFabResultCommon(),
                EntityToken(src.EntityToken),
                NewlyCreated(src.NewlyCreated)
            {}

            ~AuthenticateCustomIdResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["EntityToken"], EntityToken);
                FromJsonUtilP(input["NewlyCreated"], NewlyCreated);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EntityToken; ToJsonUtilO(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                Json::Value each_NewlyCreated; ToJsonUtilP(NewlyCreated, each_NewlyCreated); output["NewlyCreated"] = each_NewlyCreated;
                return output;
            }
        };

        struct DeleteRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;

            DeleteRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteRequest(const DeleteRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteRequest() = default;

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

        struct EmptyResponse : public PlayFabResultCommon
        {

            EmptyResponse() :
                PlayFabResultCommon()
            {}

            EmptyResponse(const EmptyResponse&) :
                PlayFabResultCommon()
            {}

            ~EmptyResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct EntityLineage : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string GroupId;
            std::string MasterPlayerAccountId;
            std::string NamespaceId;
            std::string TitleId;
            std::string TitlePlayerAccountId;

            EntityLineage() :
                PlayFabBaseModel(),
                CharacterId(),
                GroupId(),
                MasterPlayerAccountId(),
                NamespaceId(),
                TitleId(),
                TitlePlayerAccountId()
            {}

            EntityLineage(const EntityLineage& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                GroupId(src.GroupId),
                MasterPlayerAccountId(src.MasterPlayerAccountId),
                NamespaceId(src.NamespaceId),
                TitleId(src.TitleId),
                TitlePlayerAccountId(src.TitlePlayerAccountId)
            {}

            ~EntityLineage() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CharacterId"], CharacterId);
                FromJsonUtilS(input["GroupId"], GroupId);
                FromJsonUtilS(input["MasterPlayerAccountId"], MasterPlayerAccountId);
                FromJsonUtilS(input["NamespaceId"], NamespaceId);
                FromJsonUtilS(input["TitleId"], TitleId);
                FromJsonUtilS(input["TitlePlayerAccountId"], TitlePlayerAccountId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output["CharacterId"] = each_CharacterId;
                Json::Value each_GroupId; ToJsonUtilS(GroupId, each_GroupId); output["GroupId"] = each_GroupId;
                Json::Value each_MasterPlayerAccountId; ToJsonUtilS(MasterPlayerAccountId, each_MasterPlayerAccountId); output["MasterPlayerAccountId"] = each_MasterPlayerAccountId;
                Json::Value each_NamespaceId; ToJsonUtilS(NamespaceId, each_NamespaceId); output["NamespaceId"] = each_NamespaceId;
                Json::Value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output["TitleId"] = each_TitleId;
                Json::Value each_TitlePlayerAccountId; ToJsonUtilS(TitlePlayerAccountId, each_TitlePlayerAccountId); output["TitlePlayerAccountId"] = each_TitlePlayerAccountId;
                return output;
            }
        };

        struct GetEntityTokenRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetEntityTokenRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetEntityTokenRequest(const GetEntityTokenRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetEntityTokenRequest() = default;

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

        struct GetEntityTokenResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::string EntityToken;
            Boxed<time_t> TokenExpiration;

            GetEntityTokenResponse() :
                PlayFabResultCommon(),
                Entity(),
                EntityToken(),
                TokenExpiration()
            {}

            GetEntityTokenResponse(const GetEntityTokenResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            ~GetEntityTokenResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["EntityToken"], EntityToken);
                FromJsonUtilT(input["TokenExpiration"], TokenExpiration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                Json::Value each_TokenExpiration; ToJsonUtilT(TokenExpiration, each_TokenExpiration); output["TokenExpiration"] = each_TokenExpiration;
                return output;
            }
        };

        struct ValidateEntityTokenRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string EntityToken;

            ValidateEntityTokenRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                EntityToken()
            {}

            ValidateEntityTokenRequest(const ValidateEntityTokenRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                EntityToken(src.EntityToken)
            {}

            ~ValidateEntityTokenRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["EntityToken"], EntityToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                return output;
            }
        };

        struct ValidateEntityTokenResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Boxed<IdentifiedDeviceType> pfIdentifiedDeviceType;
            Boxed<LoginIdentityProvider> IdentityProvider;
            std::string IdentityProviderIssuedId;
            Boxed<EntityLineage> Lineage;

            ValidateEntityTokenResponse() :
                PlayFabResultCommon(),
                Entity(),
                pfIdentifiedDeviceType(),
                IdentityProvider(),
                IdentityProviderIssuedId(),
                Lineage()
            {}

            ValidateEntityTokenResponse(const ValidateEntityTokenResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                pfIdentifiedDeviceType(src.pfIdentifiedDeviceType),
                IdentityProvider(src.IdentityProvider),
                IdentityProviderIssuedId(src.IdentityProviderIssuedId),
                Lineage(src.Lineage)
            {}

            ~ValidateEntityTokenResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilE(input["IdentifiedDeviceType"], pfIdentifiedDeviceType);
                FromJsonUtilE(input["IdentityProvider"], IdentityProvider);
                FromJsonUtilS(input["IdentityProviderIssuedId"], IdentityProviderIssuedId);
                FromJsonUtilO(input["Lineage"], Lineage);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_pfIdentifiedDeviceType; ToJsonUtilE(pfIdentifiedDeviceType, each_pfIdentifiedDeviceType); output["IdentifiedDeviceType"] = each_pfIdentifiedDeviceType;
                Json::Value each_IdentityProvider; ToJsonUtilE(IdentityProvider, each_IdentityProvider); output["IdentityProvider"] = each_IdentityProvider;
                Json::Value each_IdentityProviderIssuedId; ToJsonUtilS(IdentityProviderIssuedId, each_IdentityProviderIssuedId); output["IdentityProviderIssuedId"] = each_IdentityProviderIssuedId;
                Json::Value each_Lineage; ToJsonUtilO(Lineage, each_Lineage); output["Lineage"] = each_Lineage;
                return output;
            }
        };

    }
}

#endif
