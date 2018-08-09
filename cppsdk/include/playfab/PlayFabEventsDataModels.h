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
    namespace EventsModels
    {
        // Events Enums
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

        // Events Classes
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

        struct EventContents : public PlayFabBaseModel
        {
            EntityKey Entity;
            std::string EventNamespace;
            std::string Name;
            std::string OriginalId;
            Boxed<time_t> OriginalTimestamp;
            Json::Value Payload;
            std::string PayloadJSON;

            EventContents() :
                PlayFabBaseModel(),
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
                Entity(src.Entity),
                EventNamespace(src.EventNamespace),
                Name(src.Name),
                OriginalId(src.OriginalId),
                OriginalTimestamp(src.OriginalTimestamp),
                Payload(src.Payload),
                PayloadJSON(src.PayloadJSON)
            {}

            ~EventContents() = default;

            void FromJson(Json::Value& input) override
            {
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

        struct WriteEventsRequest : public PlayFabRequestCommon
        {
            std::list<EventContents> Events;

            WriteEventsRequest() :
                PlayFabRequestCommon(),
                Events()
            {}

            WriteEventsRequest(const WriteEventsRequest& src) :
                PlayFabRequestCommon(),
                Events(src.Events)
            {}

            ~WriteEventsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Events"], Events);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            void FromJson(Json::Value& input) override
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
