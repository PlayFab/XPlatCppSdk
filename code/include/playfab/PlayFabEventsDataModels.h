#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace EventsModels
    {
        // Events Enums
        // Events Classes
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

        struct CreateTelemetryKeyRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string KeyName;

            CreateTelemetryKeyRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                KeyName()
            {}

            CreateTelemetryKeyRequest(const CreateTelemetryKeyRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                KeyName(src.KeyName)
            {}

            ~CreateTelemetryKeyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["KeyName"], KeyName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_KeyName; ToJsonUtilS(KeyName, each_KeyName); output["KeyName"] = each_KeyName;
                return output;
            }
        };

        struct TelemetryKeyDetails : public PlayFabBaseModel
        {
            time_t CreateTime;
            bool IsActive;
            std::string KeyValue;
            time_t LastUpdateTime;
            std::string Name;

            TelemetryKeyDetails() :
                PlayFabBaseModel(),
                CreateTime(),
                IsActive(),
                KeyValue(),
                LastUpdateTime(),
                Name()
            {}

            TelemetryKeyDetails(const TelemetryKeyDetails& src) :
                PlayFabBaseModel(),
                CreateTime(src.CreateTime),
                IsActive(src.IsActive),
                KeyValue(src.KeyValue),
                LastUpdateTime(src.LastUpdateTime),
                Name(src.Name)
            {}

            ~TelemetryKeyDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilT(input["CreateTime"], CreateTime);
                FromJsonUtilP(input["IsActive"], IsActive);
                FromJsonUtilS(input["KeyValue"], KeyValue);
                FromJsonUtilT(input["LastUpdateTime"], LastUpdateTime);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CreateTime; ToJsonUtilT(CreateTime, each_CreateTime); output["CreateTime"] = each_CreateTime;
                Json::Value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output["IsActive"] = each_IsActive;
                Json::Value each_KeyValue; ToJsonUtilS(KeyValue, each_KeyValue); output["KeyValue"] = each_KeyValue;
                Json::Value each_LastUpdateTime; ToJsonUtilT(LastUpdateTime, each_LastUpdateTime); output["LastUpdateTime"] = each_LastUpdateTime;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct CreateTelemetryKeyResponse : public PlayFabResultCommon
        {
            Boxed<TelemetryKeyDetails> NewKeyDetails;

            CreateTelemetryKeyResponse() :
                PlayFabResultCommon(),
                NewKeyDetails()
            {}

            CreateTelemetryKeyResponse(const CreateTelemetryKeyResponse& src) :
                PlayFabResultCommon(),
                NewKeyDetails(src.NewKeyDetails)
            {}

            ~CreateTelemetryKeyResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["NewKeyDetails"], NewKeyDetails);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_NewKeyDetails; ToJsonUtilO(NewKeyDetails, each_NewKeyDetails); output["NewKeyDetails"] = each_NewKeyDetails;
                return output;
            }
        };

        struct DeleteTelemetryKeyRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string KeyName;

            DeleteTelemetryKeyRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                KeyName()
            {}

            DeleteTelemetryKeyRequest(const DeleteTelemetryKeyRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                KeyName(src.KeyName)
            {}

            ~DeleteTelemetryKeyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["KeyName"], KeyName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_KeyName; ToJsonUtilS(KeyName, each_KeyName); output["KeyName"] = each_KeyName;
                return output;
            }
        };

        struct DeleteTelemetryKeyResponse : public PlayFabResultCommon
        {
            bool WasKeyDeleted;

            DeleteTelemetryKeyResponse() :
                PlayFabResultCommon(),
                WasKeyDeleted()
            {}

            DeleteTelemetryKeyResponse(const DeleteTelemetryKeyResponse& src) :
                PlayFabResultCommon(),
                WasKeyDeleted(src.WasKeyDeleted)
            {}

            ~DeleteTelemetryKeyResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["WasKeyDeleted"], WasKeyDeleted);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_WasKeyDeleted; ToJsonUtilP(WasKeyDeleted, each_WasKeyDeleted); output["WasKeyDeleted"] = each_WasKeyDeleted;
                return output;
            }
        };

        struct EventContents : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string EventNamespace;
            std::string Name;
            std::string OriginalId;
            Boxed<time_t> OriginalTimestamp;
            Json::Value Payload;
            std::string PayloadJSON;

            EventContents() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                EventNamespace(),
                Name(),
                OriginalId(),
                OriginalTimestamp(),
                Payload(),
                PayloadJSON()
            {}

            EventContents(const EventContents& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                EventNamespace(src.EventNamespace),
                Name(src.Name),
                OriginalId(src.OriginalId),
                OriginalTimestamp(src.OriginalTimestamp),
                Payload(src.Payload),
                PayloadJSON(src.PayloadJSON)
            {}

            ~EventContents() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["EventNamespace"], EventNamespace);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["OriginalId"], OriginalId);
                FromJsonUtilT(input["OriginalTimestamp"], OriginalTimestamp);
                Payload = input["Payload"];
                FromJsonUtilS(input["PayloadJSON"], PayloadJSON);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_EventNamespace; ToJsonUtilS(EventNamespace, each_EventNamespace); output["EventNamespace"] = each_EventNamespace;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_OriginalId; ToJsonUtilS(OriginalId, each_OriginalId); output["OriginalId"] = each_OriginalId;
                Json::Value each_OriginalTimestamp; ToJsonUtilT(OriginalTimestamp, each_OriginalTimestamp); output["OriginalTimestamp"] = each_OriginalTimestamp;
                output["Payload"] = Payload;
                Json::Value each_PayloadJSON; ToJsonUtilS(PayloadJSON, each_PayloadJSON); output["PayloadJSON"] = each_PayloadJSON;
                return output;
            }
        };

        struct GetTelemetryKeyRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string KeyName;

            GetTelemetryKeyRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                KeyName()
            {}

            GetTelemetryKeyRequest(const GetTelemetryKeyRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                KeyName(src.KeyName)
            {}

            ~GetTelemetryKeyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["KeyName"], KeyName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_KeyName; ToJsonUtilS(KeyName, each_KeyName); output["KeyName"] = each_KeyName;
                return output;
            }
        };

        struct GetTelemetryKeyResponse : public PlayFabResultCommon
        {
            Boxed<TelemetryKeyDetails> KeyDetails;

            GetTelemetryKeyResponse() :
                PlayFabResultCommon(),
                KeyDetails()
            {}

            GetTelemetryKeyResponse(const GetTelemetryKeyResponse& src) :
                PlayFabResultCommon(),
                KeyDetails(src.KeyDetails)
            {}

            ~GetTelemetryKeyResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["KeyDetails"], KeyDetails);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_KeyDetails; ToJsonUtilO(KeyDetails, each_KeyDetails); output["KeyDetails"] = each_KeyDetails;
                return output;
            }
        };

        struct ListTelemetryKeysRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            ListTelemetryKeysRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            ListTelemetryKeysRequest(const ListTelemetryKeysRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~ListTelemetryKeysRequest() = default;

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

        struct ListTelemetryKeysResponse : public PlayFabResultCommon
        {
            std::list<TelemetryKeyDetails> KeyDetails;

            ListTelemetryKeysResponse() :
                PlayFabResultCommon(),
                KeyDetails()
            {}

            ListTelemetryKeysResponse(const ListTelemetryKeysResponse& src) :
                PlayFabResultCommon(),
                KeyDetails(src.KeyDetails)
            {}

            ~ListTelemetryKeysResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["KeyDetails"], KeyDetails);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_KeyDetails; ToJsonUtilO(KeyDetails, each_KeyDetails); output["KeyDetails"] = each_KeyDetails;
                return output;
            }
        };

        struct SetTelemetryKeyActiveRequest : public PlayFabRequestCommon
        {
            bool Active;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string KeyName;

            SetTelemetryKeyActiveRequest() :
                PlayFabRequestCommon(),
                Active(),
                CustomTags(),
                Entity(),
                KeyName()
            {}

            SetTelemetryKeyActiveRequest(const SetTelemetryKeyActiveRequest& src) :
                PlayFabRequestCommon(),
                Active(src.Active),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                KeyName(src.KeyName)
            {}

            ~SetTelemetryKeyActiveRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Active"], Active);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["KeyName"], KeyName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Active; ToJsonUtilP(Active, each_Active); output["Active"] = each_Active;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_KeyName; ToJsonUtilS(KeyName, each_KeyName); output["KeyName"] = each_KeyName;
                return output;
            }
        };

        struct SetTelemetryKeyActiveResponse : public PlayFabResultCommon
        {
            Boxed<TelemetryKeyDetails> KeyDetails;
            bool WasKeyUpdated;

            SetTelemetryKeyActiveResponse() :
                PlayFabResultCommon(),
                KeyDetails(),
                WasKeyUpdated()
            {}

            SetTelemetryKeyActiveResponse(const SetTelemetryKeyActiveResponse& src) :
                PlayFabResultCommon(),
                KeyDetails(src.KeyDetails),
                WasKeyUpdated(src.WasKeyUpdated)
            {}

            ~SetTelemetryKeyActiveResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["KeyDetails"], KeyDetails);
                FromJsonUtilP(input["WasKeyUpdated"], WasKeyUpdated);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_KeyDetails; ToJsonUtilO(KeyDetails, each_KeyDetails); output["KeyDetails"] = each_KeyDetails;
                Json::Value each_WasKeyUpdated; ToJsonUtilP(WasKeyUpdated, each_WasKeyUpdated); output["WasKeyUpdated"] = each_WasKeyUpdated;
                return output;
            }
        };

        struct WriteEventsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::list<EventContents> Events;

            WriteEventsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Events()
            {}

            WriteEventsRequest(const WriteEventsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Events(src.Events)
            {}

            ~WriteEventsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Events"], Events);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Events; ToJsonUtilO(Events, each_Events); output["Events"] = each_Events;
                return output;
            }
        };

        struct WriteEventsResponse : public PlayFabResultCommon
        {
            std::list<std::string> AssignedEventIds;

            WriteEventsResponse() :
                PlayFabResultCommon(),
                AssignedEventIds()
            {}

            WriteEventsResponse(const WriteEventsResponse& src) :
                PlayFabResultCommon(),
                AssignedEventIds(src.AssignedEventIds)
            {}

            ~WriteEventsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AssignedEventIds"], AssignedEventIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AssignedEventIds; ToJsonUtilS(AssignedEventIds, each_AssignedEventIds); output["AssignedEventIds"] = each_AssignedEventIds;
                return output;
            }
        };

    }
}

#endif
