#pragma once

#ifdef ENABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>

// Intellisense-only includes
#ifndef _WIN32
#include <jsoncpp/json/value.h>
#endif
#ifdef _WIN32
#include <json/value.h>
#endif

namespace PlayFab
{
    namespace AuthenticationModels
    {
        // Authentication Enums
        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup,
            EntityTypesservice
        };

        inline void ToJsonEnum(const EntityTypes input, Json::Value& output)
        {
            if (input == EntityTypestitle) output = Json::Value("title");
            if (input == EntityTypesmaster_player_account) output = Json::Value("master_player_account");
            if (input == EntityTypestitle_player_account) output = Json::Value("title_player_account");
            if (input == EntityTypescharacter) output = Json::Value("character");
            if (input == EntityTypesgroup) output = Json::Value("group");
            if (input == EntityTypesservice) output = Json::Value("service");
        }
        inline void FromJsonEnum(const Json::Value& input, EntityTypes& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "title") output = EntityTypestitle;
            if (inputStr == "master_player_account") output = EntityTypesmaster_player_account;
            if (inputStr == "title_player_account") output = EntityTypestitle_player_account;
            if (inputStr == "character") output = EntityTypescharacter;
            if (inputStr == "group") output = EntityTypesgroup;
            if (inputStr == "service") output = EntityTypesservice;
        }

        // Authentication Classes
        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            Boxed<EntityTypes> Type;
            std::string TypeString;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type(),
                TypeString()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type),
                TypeString(src.TypeString)
            {}

            ~EntityKey() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilE(input["Type"], Type);
                FromJsonUtilS(input["TypeString"], TypeString);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Type; ToJsonUtilE(Type, each_Type); output["Type"] = each_Type;
                Json::Value each_TypeString; ToJsonUtilS(TypeString, each_TypeString); output["TypeString"] = each_TypeString;
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

    }
}

#endif
