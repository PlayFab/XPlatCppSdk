#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace AuthenticationModels
    {
        // Authentication Enums
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
            LoginIdentityProviderOpenIdConnect
        };

        inline void ToJsonEnum(const LoginIdentityProvider input, Json::Value& output)
        {
            if (input == LoginIdentityProvider::LoginIdentityProviderUnknown) output = Json::Value("Unknown");
            if (input == LoginIdentityProvider::LoginIdentityProviderPlayFab) output = Json::Value("PlayFab");
            if (input == LoginIdentityProvider::LoginIdentityProviderCustom) output = Json::Value("Custom");
            if (input == LoginIdentityProvider::LoginIdentityProviderGameCenter) output = Json::Value("GameCenter");
            if (input == LoginIdentityProvider::LoginIdentityProviderGooglePlay) output = Json::Value("GooglePlay");
            if (input == LoginIdentityProvider::LoginIdentityProviderSteam) output = Json::Value("Steam");
            if (input == LoginIdentityProvider::LoginIdentityProviderXBoxLive) output = Json::Value("XBoxLive");
            if (input == LoginIdentityProvider::LoginIdentityProviderPSN) output = Json::Value("PSN");
            if (input == LoginIdentityProvider::LoginIdentityProviderKongregate) output = Json::Value("Kongregate");
            if (input == LoginIdentityProvider::LoginIdentityProviderFacebook) output = Json::Value("Facebook");
            if (input == LoginIdentityProvider::LoginIdentityProviderIOSDevice) output = Json::Value("IOSDevice");
            if (input == LoginIdentityProvider::LoginIdentityProviderAndroidDevice) output = Json::Value("AndroidDevice");
            if (input == LoginIdentityProvider::LoginIdentityProviderTwitch) output = Json::Value("Twitch");
            if (input == LoginIdentityProvider::LoginIdentityProviderWindowsHello) output = Json::Value("WindowsHello");
            if (input == LoginIdentityProvider::LoginIdentityProviderGameServer) output = Json::Value("GameServer");
            if (input == LoginIdentityProvider::LoginIdentityProviderCustomServer) output = Json::Value("CustomServer");
            if (input == LoginIdentityProvider::LoginIdentityProviderNintendoSwitch) output = Json::Value("NintendoSwitch");
            if (input == LoginIdentityProvider::LoginIdentityProviderFacebookInstantGames) output = Json::Value("FacebookInstantGames");
            if (input == LoginIdentityProvider::LoginIdentityProviderOpenIdConnect) output = Json::Value("OpenIdConnect");
        }
        inline void FromJsonEnum(const Json::Value& input, LoginIdentityProvider& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown") output = LoginIdentityProvider::LoginIdentityProviderUnknown;
            if (inputStr == "PlayFab") output = LoginIdentityProvider::LoginIdentityProviderPlayFab;
            if (inputStr == "Custom") output = LoginIdentityProvider::LoginIdentityProviderCustom;
            if (inputStr == "GameCenter") output = LoginIdentityProvider::LoginIdentityProviderGameCenter;
            if (inputStr == "GooglePlay") output = LoginIdentityProvider::LoginIdentityProviderGooglePlay;
            if (inputStr == "Steam") output = LoginIdentityProvider::LoginIdentityProviderSteam;
            if (inputStr == "XBoxLive") output = LoginIdentityProvider::LoginIdentityProviderXBoxLive;
            if (inputStr == "PSN") output = LoginIdentityProvider::LoginIdentityProviderPSN;
            if (inputStr == "Kongregate") output = LoginIdentityProvider::LoginIdentityProviderKongregate;
            if (inputStr == "Facebook") output = LoginIdentityProvider::LoginIdentityProviderFacebook;
            if (inputStr == "IOSDevice") output = LoginIdentityProvider::LoginIdentityProviderIOSDevice;
            if (inputStr == "AndroidDevice") output = LoginIdentityProvider::LoginIdentityProviderAndroidDevice;
            if (inputStr == "Twitch") output = LoginIdentityProvider::LoginIdentityProviderTwitch;
            if (inputStr == "WindowsHello") output = LoginIdentityProvider::LoginIdentityProviderWindowsHello;
            if (inputStr == "GameServer") output = LoginIdentityProvider::LoginIdentityProviderGameServer;
            if (inputStr == "CustomServer") output = LoginIdentityProvider::LoginIdentityProviderCustomServer;
            if (inputStr == "NintendoSwitch") output = LoginIdentityProvider::LoginIdentityProviderNintendoSwitch;
            if (inputStr == "FacebookInstantGames") output = LoginIdentityProvider::LoginIdentityProviderFacebookInstantGames;
            if (inputStr == "OpenIdConnect") output = LoginIdentityProvider::LoginIdentityProviderOpenIdConnect;
        }

        // Authentication Classes
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

            void FromJson(Json::Value& input) override
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

            void FromJson(Json::Value& input) override
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
            Boxed<EntityKey> Entity;

            GetEntityTokenRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            GetEntityTokenRequest(const GetEntityTokenRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~GetEntityTokenRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            void FromJson(Json::Value& input) override
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
            std::string EntityToken;

            ValidateEntityTokenRequest() :
                PlayFabRequestCommon(),
                EntityToken()
            {}

            ValidateEntityTokenRequest(const ValidateEntityTokenRequest& src) :
                PlayFabRequestCommon(),
                EntityToken(src.EntityToken)
            {}

            ~ValidateEntityTokenRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["EntityToken"], EntityToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output["EntityToken"] = each_EntityToken;
                return output;
            }
        };

        struct ValidateEntityTokenResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Boxed<LoginIdentityProvider> IdentityProvider;
            Boxed<EntityLineage> Lineage;

            ValidateEntityTokenResponse() :
                PlayFabResultCommon(),
                Entity(),
                IdentityProvider(),
                Lineage()
            {}

            ValidateEntityTokenResponse(const ValidateEntityTokenResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                IdentityProvider(src.IdentityProvider),
                Lineage(src.Lineage)
            {}

            ~ValidateEntityTokenResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilE(input["IdentityProvider"], IdentityProvider);
                FromJsonUtilO(input["Lineage"], Lineage);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdentityProvider; ToJsonUtilE(IdentityProvider, each_IdentityProvider); output["IdentityProvider"] = each_IdentityProvider;
                Json::Value each_Lineage; ToJsonUtilO(Lineage, each_Lineage); output["Lineage"] = each_Lineage;
                return output;
            }
        };

    }
}

#endif
