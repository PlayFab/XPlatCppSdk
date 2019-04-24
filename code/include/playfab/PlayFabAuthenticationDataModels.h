#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace AuthenticationModels
    {
        // Authentication Enums
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

        struct ActivateAPIKeyRequest : public PlayFabRequestCommon
        {
            std::string APIKeyId;
            Boxed<EntityKey> Entity;

            ActivateAPIKeyRequest() :
                PlayFabRequestCommon(),
                APIKeyId(),
                Entity()
            {}

            ActivateAPIKeyRequest(const ActivateAPIKeyRequest& src) :
                PlayFabRequestCommon(),
                APIKeyId(src.APIKeyId),
                Entity(src.Entity)
            {}

            ~ActivateAPIKeyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct ActivateAPIKeyResponse : public PlayFabResultCommon
        {

            ActivateAPIKeyResponse() :
                PlayFabResultCommon()
            {}

            ActivateAPIKeyResponse(const ActivateAPIKeyResponse&) :
                PlayFabResultCommon()
            {}

            ~ActivateAPIKeyResponse() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateAPIKeyDetails : public PlayFabBaseModel
        {
            bool Active;
            std::string APIKeyId;
            std::string APIKeySecret;
            time_t Created;

            CreateAPIKeyDetails() :
                PlayFabBaseModel(),
                Active(),
                APIKeyId(),
                APIKeySecret(),
                Created()
            {}

            CreateAPIKeyDetails(const CreateAPIKeyDetails& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                APIKeyId(src.APIKeyId),
                APIKeySecret(src.APIKeySecret),
                Created(src.Created)
            {}

            ~CreateAPIKeyDetails() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Active"], Active);
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilS(input["APIKeySecret"], APIKeySecret);
                FromJsonUtilT(input["Created"], Created);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Active; ToJsonUtilP(Active, each_Active); output["Active"] = each_Active;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_APIKeySecret; ToJsonUtilS(APIKeySecret, each_APIKeySecret); output["APIKeySecret"] = each_APIKeySecret;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                return output;
            }
        };

        struct CreateAPIKeyRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            CreateAPIKeyRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            CreateAPIKeyRequest(const CreateAPIKeyRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~CreateAPIKeyRequest() = default;

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

        struct CreateAPIKeyResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            Boxed<CreateAPIKeyDetails> Key;

            CreateAPIKeyResponse() :
                PlayFabResultCommon(),
                Entity(),
                Key()
            {}

            CreateAPIKeyResponse(const CreateAPIKeyResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Key(src.Key)
            {}

            ~CreateAPIKeyResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Key"], Key);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Key; ToJsonUtilO(Key, each_Key); output["Key"] = each_Key;
                return output;
            }
        };

        struct DeactivateAPIKeyRequest : public PlayFabRequestCommon
        {
            std::string APIKeyId;
            Boxed<EntityKey> Entity;

            DeactivateAPIKeyRequest() :
                PlayFabRequestCommon(),
                APIKeyId(),
                Entity()
            {}

            DeactivateAPIKeyRequest(const DeactivateAPIKeyRequest& src) :
                PlayFabRequestCommon(),
                APIKeyId(src.APIKeyId),
                Entity(src.Entity)
            {}

            ~DeactivateAPIKeyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeactivateAPIKeyResponse : public PlayFabResultCommon
        {

            DeactivateAPIKeyResponse() :
                PlayFabResultCommon()
            {}

            DeactivateAPIKeyResponse(const DeactivateAPIKeyResponse&) :
                PlayFabResultCommon()
            {}

            ~DeactivateAPIKeyResponse() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteAPIKeyRequest : public PlayFabRequestCommon
        {
            std::string APIKeyId;
            Boxed<EntityKey> Entity;

            DeleteAPIKeyRequest() :
                PlayFabRequestCommon(),
                APIKeyId(),
                Entity()
            {}

            DeleteAPIKeyRequest(const DeleteAPIKeyRequest& src) :
                PlayFabRequestCommon(),
                APIKeyId(src.APIKeyId),
                Entity(src.Entity)
            {}

            ~DeleteAPIKeyRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteAPIKeyResponse : public PlayFabResultCommon
        {

            DeleteAPIKeyResponse() :
                PlayFabResultCommon()
            {}

            DeleteAPIKeyResponse(const DeleteAPIKeyResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteAPIKeyResponse() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct GetAPIKeyDetails : public PlayFabBaseModel
        {
            bool Active;
            std::string APIKeyId;
            time_t Created;

            GetAPIKeyDetails() :
                PlayFabBaseModel(),
                Active(),
                APIKeyId(),
                Created()
            {}

            GetAPIKeyDetails(const GetAPIKeyDetails& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                APIKeyId(src.APIKeyId),
                Created(src.Created)
            {}

            ~GetAPIKeyDetails() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Active"], Active);
                FromJsonUtilS(input["APIKeyId"], APIKeyId);
                FromJsonUtilT(input["Created"], Created);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Active; ToJsonUtilP(Active, each_Active); output["Active"] = each_Active;
                Json::Value each_APIKeyId; ToJsonUtilS(APIKeyId, each_APIKeyId); output["APIKeyId"] = each_APIKeyId;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                return output;
            }
        };

        struct GetAPIKeysRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            GetAPIKeysRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            GetAPIKeysRequest(const GetAPIKeysRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~GetAPIKeysRequest() = default;

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

        struct GetAPIKeysResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::list<GetAPIKeyDetails> Keys;

            GetAPIKeysResponse() :
                PlayFabResultCommon(),
                Entity(),
                Keys()
            {}

            GetAPIKeysResponse(const GetAPIKeysResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                Keys(src.Keys)
            {}

            ~GetAPIKeysResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Keys"], Keys);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Keys; ToJsonUtilO(Keys, each_Keys); output["Keys"] = each_Keys;
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
