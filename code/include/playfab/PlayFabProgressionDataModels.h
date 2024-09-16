#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>
#include <playfab/PlayFabPlatformUtils.h>

namespace PlayFab
{
    namespace ProgressionModels
    {
        // Progression Enums
        enum class ExternalFriendSources
        {
            ExternalFriendSourcesNone = 0x0,
            ExternalFriendSourcesSteam = 0x1,
            ExternalFriendSourcesFacebook = 0x2,
            ExternalFriendSourcesXbox = 0x4,
            ExternalFriendSourcesPsn = 0x8,
            ExternalFriendSourcesAll = 0x10
        };

        DEFINE_ENUM_FLAG_OPERATORS(ExternalFriendSources);

        inline void ToJsonEnum(const ExternalFriendSources input, Json::Value& output)
        {
            std::string separator{};
            std::stringstream ss;

            if (input == ExternalFriendSources::ExternalFriendSourcesNone)
            {
                output = Json::Value{  };
                return;
            }
            if ((input & ExternalFriendSources::ExternalFriendSourcesSteam) == ExternalFriendSources::ExternalFriendSourcesSteam)
            {
                ss << separator << "Steam";
                separator = ",";
            }
            if ((input & ExternalFriendSources::ExternalFriendSourcesFacebook) == ExternalFriendSources::ExternalFriendSourcesFacebook)
            {
                ss << separator << "Facebook";
                separator = ",";
            }
            if ((input & ExternalFriendSources::ExternalFriendSourcesXbox) == ExternalFriendSources::ExternalFriendSourcesXbox)
            {
                ss << separator << "Xbox";
                separator = ",";
            }
            if ((input & ExternalFriendSources::ExternalFriendSourcesPsn) == ExternalFriendSources::ExternalFriendSourcesPsn)
            {
                ss << separator << "Psn";
                separator = ",";
            }
            if ((input & ExternalFriendSources::ExternalFriendSourcesAll) == ExternalFriendSources::ExternalFriendSourcesAll)
            {
                ss << separator << "All";
                separator = ",";
            }

            output = Json::Value{ ss.str().data() };
        }
        inline void FromJsonEnum(const Json::Value& input, ExternalFriendSources& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "None")
            {
                output = ExternalFriendSources::ExternalFriendSourcesNone;
                return;
            }
            if (inputStr == "Steam")
            {
                output = ExternalFriendSources::ExternalFriendSourcesSteam;
                return;
            }
            if (inputStr == "Facebook")
            {
                output = ExternalFriendSources::ExternalFriendSourcesFacebook;
                return;
            }
            if (inputStr == "Xbox")
            {
                output = ExternalFriendSources::ExternalFriendSourcesXbox;
                return;
            }
            if (inputStr == "Psn")
            {
                output = ExternalFriendSources::ExternalFriendSourcesPsn;
                return;
            }
            if (inputStr == "All")
            {
                output = ExternalFriendSources::ExternalFriendSourcesAll;
                return;
            }
        }

        enum class LeaderboardSortDirection
        {
            LeaderboardSortDirectionDescending,
            LeaderboardSortDirectionAscending
        };

        inline void ToJsonEnum(const LeaderboardSortDirection input, Json::Value& output)
        {
            if (input == LeaderboardSortDirection::LeaderboardSortDirectionDescending)
            {
                output = Json::Value("Descending");
                return;
            }
            if (input == LeaderboardSortDirection::LeaderboardSortDirectionAscending)
            {
                output = Json::Value("Ascending");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, LeaderboardSortDirection& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Descending")
            {
                output = LeaderboardSortDirection::LeaderboardSortDirectionDescending;
                return;
            }
            if (inputStr == "Ascending")
            {
                output = LeaderboardSortDirection::LeaderboardSortDirectionAscending;
                return;
            }
        }

        enum class ResetInterval
        {
            ResetIntervalManual,
            ResetIntervalHour,
            ResetIntervalDay,
            ResetIntervalWeek,
            ResetIntervalMonth
        };

        inline void ToJsonEnum(const ResetInterval input, Json::Value& output)
        {
            if (input == ResetInterval::ResetIntervalManual)
            {
                output = Json::Value("Manual");
                return;
            }
            if (input == ResetInterval::ResetIntervalHour)
            {
                output = Json::Value("Hour");
                return;
            }
            if (input == ResetInterval::ResetIntervalDay)
            {
                output = Json::Value("Day");
                return;
            }
            if (input == ResetInterval::ResetIntervalWeek)
            {
                output = Json::Value("Week");
                return;
            }
            if (input == ResetInterval::ResetIntervalMonth)
            {
                output = Json::Value("Month");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, ResetInterval& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Manual")
            {
                output = ResetInterval::ResetIntervalManual;
                return;
            }
            if (inputStr == "Hour")
            {
                output = ResetInterval::ResetIntervalHour;
                return;
            }
            if (inputStr == "Day")
            {
                output = ResetInterval::ResetIntervalDay;
                return;
            }
            if (inputStr == "Week")
            {
                output = ResetInterval::ResetIntervalWeek;
                return;
            }
            if (inputStr == "Month")
            {
                output = ResetInterval::ResetIntervalMonth;
                return;
            }
        }

        enum class StatisticAggregationMethod
        {
            StatisticAggregationMethodLast,
            StatisticAggregationMethodMin,
            StatisticAggregationMethodMax,
            StatisticAggregationMethodSum
        };

        inline void ToJsonEnum(const StatisticAggregationMethod input, Json::Value& output)
        {
            if (input == StatisticAggregationMethod::StatisticAggregationMethodLast)
            {
                output = Json::Value("Last");
                return;
            }
            if (input == StatisticAggregationMethod::StatisticAggregationMethodMin)
            {
                output = Json::Value("Min");
                return;
            }
            if (input == StatisticAggregationMethod::StatisticAggregationMethodMax)
            {
                output = Json::Value("Max");
                return;
            }
            if (input == StatisticAggregationMethod::StatisticAggregationMethodSum)
            {
                output = Json::Value("Sum");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, StatisticAggregationMethod& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Last")
            {
                output = StatisticAggregationMethod::StatisticAggregationMethodLast;
                return;
            }
            if (inputStr == "Min")
            {
                output = StatisticAggregationMethod::StatisticAggregationMethodMin;
                return;
            }
            if (inputStr == "Max")
            {
                output = StatisticAggregationMethod::StatisticAggregationMethodMax;
                return;
            }
            if (inputStr == "Sum")
            {
                output = StatisticAggregationMethod::StatisticAggregationMethodSum;
                return;
            }
        }

        // Progression Classes
        struct LinkedStatisticColumn : public PlayFabBaseModel
        {
            std::string LinkedStatisticColumnName;
            std::string LinkedStatisticName;

            LinkedStatisticColumn() :
                PlayFabBaseModel(),
                LinkedStatisticColumnName(),
                LinkedStatisticName()
            {}

            LinkedStatisticColumn(const LinkedStatisticColumn& src) :
                PlayFabBaseModel(),
                LinkedStatisticColumnName(src.LinkedStatisticColumnName),
                LinkedStatisticName(src.LinkedStatisticName)
            {}

            ~LinkedStatisticColumn() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["LinkedStatisticColumnName"], LinkedStatisticColumnName);
                FromJsonUtilS(input["LinkedStatisticName"], LinkedStatisticName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LinkedStatisticColumnName; ToJsonUtilS(LinkedStatisticColumnName, each_LinkedStatisticColumnName); output["LinkedStatisticColumnName"] = each_LinkedStatisticColumnName;
                Json::Value each_LinkedStatisticName; ToJsonUtilS(LinkedStatisticName, each_LinkedStatisticName); output["LinkedStatisticName"] = each_LinkedStatisticName;
                return output;
            }
        };

        struct LeaderboardColumn : public PlayFabBaseModel
        {
            Boxed<LinkedStatisticColumn> pfLinkedStatisticColumn;
            std::string Name;
            LeaderboardSortDirection SortDirection;

            LeaderboardColumn() :
                PlayFabBaseModel(),
                pfLinkedStatisticColumn(),
                Name(),
                SortDirection()
            {}

            LeaderboardColumn(const LeaderboardColumn& src) :
                PlayFabBaseModel(),
                pfLinkedStatisticColumn(src.pfLinkedStatisticColumn),
                Name(src.Name),
                SortDirection(src.SortDirection)
            {}

            ~LeaderboardColumn() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["LinkedStatisticColumn"], pfLinkedStatisticColumn);
                FromJsonUtilS(input["Name"], Name);
                FromJsonEnum(input["SortDirection"], SortDirection);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfLinkedStatisticColumn; ToJsonUtilO(pfLinkedStatisticColumn, each_pfLinkedStatisticColumn); output["LinkedStatisticColumn"] = each_pfLinkedStatisticColumn;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_SortDirection; ToJsonEnum(SortDirection, each_SortDirection); output["SortDirection"] = each_SortDirection;
                return output;
            }
        };

        struct VersionConfiguration : public PlayFabBaseModel
        {
            Int32 MaxQueryableVersions;
            ResetInterval pfResetInterval;

            VersionConfiguration() :
                PlayFabBaseModel(),
                MaxQueryableVersions(),
                pfResetInterval()
            {}

            VersionConfiguration(const VersionConfiguration& src) :
                PlayFabBaseModel(),
                MaxQueryableVersions(src.MaxQueryableVersions),
                pfResetInterval(src.pfResetInterval)
            {}

            ~VersionConfiguration() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["MaxQueryableVersions"], MaxQueryableVersions);
                FromJsonEnum(input["ResetInterval"], pfResetInterval);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MaxQueryableVersions; ToJsonUtilP(MaxQueryableVersions, each_MaxQueryableVersions); output["MaxQueryableVersions"] = each_MaxQueryableVersions;
                Json::Value each_pfResetInterval; ToJsonEnum(pfResetInterval, each_pfResetInterval); output["ResetInterval"] = each_pfResetInterval;
                return output;
            }
        };

        struct CreateLeaderboardDefinitionRequest : public PlayFabRequestCommon
        {
            std::list<LeaderboardColumn> Columns;
            std::map<std::string, std::string> CustomTags;
            std::string EntityType;
            std::string Name;
            Int32 SizeLimit;
            VersionConfiguration pfVersionConfiguration;

            CreateLeaderboardDefinitionRequest() :
                PlayFabRequestCommon(),
                Columns(),
                CustomTags(),
                EntityType(),
                Name(),
                SizeLimit(),
                pfVersionConfiguration()
            {}

            CreateLeaderboardDefinitionRequest(const CreateLeaderboardDefinitionRequest& src) :
                PlayFabRequestCommon(),
                Columns(src.Columns),
                CustomTags(src.CustomTags),
                EntityType(src.EntityType),
                Name(src.Name),
                SizeLimit(src.SizeLimit),
                pfVersionConfiguration(src.pfVersionConfiguration)
            {}

            ~CreateLeaderboardDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Columns"], Columns);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["EntityType"], EntityType);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["SizeLimit"], SizeLimit);
                FromJsonUtilO(input["VersionConfiguration"], pfVersionConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Columns; ToJsonUtilO(Columns, each_Columns); output["Columns"] = each_Columns;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EntityType; ToJsonUtilS(EntityType, each_EntityType); output["EntityType"] = each_EntityType;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_SizeLimit; ToJsonUtilP(SizeLimit, each_SizeLimit); output["SizeLimit"] = each_SizeLimit;
                Json::Value each_pfVersionConfiguration; ToJsonUtilO(pfVersionConfiguration, each_pfVersionConfiguration); output["VersionConfiguration"] = each_pfVersionConfiguration;
                return output;
            }
        };

        struct StatisticColumn : public PlayFabBaseModel
        {
            StatisticAggregationMethod AggregationMethod;
            std::string Name;

            StatisticColumn() :
                PlayFabBaseModel(),
                AggregationMethod(),
                Name()
            {}

            StatisticColumn(const StatisticColumn& src) :
                PlayFabBaseModel(),
                AggregationMethod(src.AggregationMethod),
                Name(src.Name)
            {}

            ~StatisticColumn() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonEnum(input["AggregationMethod"], AggregationMethod);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AggregationMethod; ToJsonEnum(AggregationMethod, each_AggregationMethod); output["AggregationMethod"] = each_AggregationMethod;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct CreateStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            std::list<StatisticColumn> Columns;
            std::map<std::string, std::string> CustomTags;
            std::string EntityType;
            std::string Name;
            Boxed<VersionConfiguration> pfVersionConfiguration;

            CreateStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                Columns(),
                CustomTags(),
                EntityType(),
                Name(),
                pfVersionConfiguration()
            {}

            CreateStatisticDefinitionRequest(const CreateStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                Columns(src.Columns),
                CustomTags(src.CustomTags),
                EntityType(src.EntityType),
                Name(src.Name),
                pfVersionConfiguration(src.pfVersionConfiguration)
            {}

            ~CreateStatisticDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Columns"], Columns);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["EntityType"], EntityType);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilO(input["VersionConfiguration"], pfVersionConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Columns; ToJsonUtilO(Columns, each_Columns); output["Columns"] = each_Columns;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EntityType; ToJsonUtilS(EntityType, each_EntityType); output["EntityType"] = each_EntityType;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_pfVersionConfiguration; ToJsonUtilO(pfVersionConfiguration, each_pfVersionConfiguration); output["VersionConfiguration"] = each_pfVersionConfiguration;
                return output;
            }
        };

        struct DeleteLeaderboardDefinitionRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            DeleteLeaderboardDefinitionRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            DeleteLeaderboardDefinitionRequest(const DeleteLeaderboardDefinitionRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~DeleteLeaderboardDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct DeleteLeaderboardEntriesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::list<std::string> EntityIds;
            std::string Name;

            DeleteLeaderboardEntriesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                EntityIds(),
                Name()
            {}

            DeleteLeaderboardEntriesRequest(const DeleteLeaderboardEntriesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                EntityIds(src.EntityIds),
                Name(src.Name)
            {}

            ~DeleteLeaderboardEntriesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["EntityIds"], EntityIds);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EntityIds; ToJsonUtilS(EntityIds, each_EntityIds); output["EntityIds"] = each_EntityIds;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct DeleteStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            DeleteStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            DeleteStatisticDefinitionRequest(const DeleteStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~DeleteStatisticDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
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

        struct StatisticDelete : public PlayFabBaseModel
        {
            std::string Name;

            StatisticDelete() :
                PlayFabBaseModel(),
                Name()
            {}

            StatisticDelete(const StatisticDelete& src) :
                PlayFabBaseModel(),
                Name(src.Name)
            {}

            ~StatisticDelete() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct DeleteStatisticsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::list<StatisticDelete> Statistics;

            DeleteStatisticsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                Statistics()
            {}

            DeleteStatisticsRequest(const DeleteStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Statistics(src.Statistics)
            {}

            ~DeleteStatisticsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                return output;
            }
        };

        struct DeleteStatisticsResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;

            DeleteStatisticsResponse() :
                PlayFabResultCommon(),
                Entity()
            {}

            DeleteStatisticsResponse(const DeleteStatisticsResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity)
            {}

            ~DeleteStatisticsResponse() = default;

            void FromJson(const Json::Value& input) override
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

        struct EntityLeaderboardEntry : public PlayFabBaseModel
        {
            std::string DisplayName;
            Boxed<EntityKey> Entity;
            time_t LastUpdated;
            std::string Metadata;
            Int32 Rank;
            std::list<std::string> Scores;

            EntityLeaderboardEntry() :
                PlayFabBaseModel(),
                DisplayName(),
                Entity(),
                LastUpdated(),
                Metadata(),
                Rank(),
                Scores()
            {}

            EntityLeaderboardEntry(const EntityLeaderboardEntry& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                Entity(src.Entity),
                LastUpdated(src.LastUpdated),
                Metadata(src.Metadata),
                Rank(src.Rank),
                Scores(src.Scores)
            {}

            ~EntityLeaderboardEntry() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["DisplayName"], DisplayName);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilT(input["LastUpdated"], LastUpdated);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilP(input["Rank"], Rank);
                FromJsonUtilS(input["Scores"], Scores);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output["DisplayName"] = each_DisplayName;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_LastUpdated; ToJsonUtilT(LastUpdated, each_LastUpdated); output["LastUpdated"] = each_LastUpdated;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_Rank; ToJsonUtilP(Rank, each_Rank); output["Rank"] = each_Rank;
                Json::Value each_Scores; ToJsonUtilS(Scores, each_Scores); output["Scores"] = each_Scores;
                return output;
            }
        };

        struct EntityStatisticValue : public PlayFabBaseModel
        {
            std::string Metadata;
            std::string Name;
            std::list<std::string> Scores;
            Int32 Version;

            EntityStatisticValue() :
                PlayFabBaseModel(),
                Metadata(),
                Name(),
                Scores(),
                Version()
            {}

            EntityStatisticValue(const EntityStatisticValue& src) :
                PlayFabBaseModel(),
                Metadata(src.Metadata),
                Name(src.Name),
                Scores(src.Scores),
                Version(src.Version)
            {}

            ~EntityStatisticValue() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["Scores"], Scores);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Scores; ToJsonUtilS(Scores, each_Scores); output["Scores"] = each_Scores;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct EntityStatistics : public PlayFabBaseModel
        {
            Boxed<EntityKey> pfEntityKey;
            std::list<EntityStatisticValue> Statistics;

            EntityStatistics() :
                PlayFabBaseModel(),
                pfEntityKey(),
                Statistics()
            {}

            EntityStatistics(const EntityStatistics& src) :
                PlayFabBaseModel(),
                pfEntityKey(src.pfEntityKey),
                Statistics(src.Statistics)
            {}

            ~EntityStatistics() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["EntityKey"], pfEntityKey);
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfEntityKey; ToJsonUtilO(pfEntityKey, each_pfEntityKey); output["EntityKey"] = each_pfEntityKey;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                return output;
            }
        };

        struct GetEntityLeaderboardRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string LeaderboardName;
            Uint32 PageSize;
            Boxed<Uint32> StartingPosition;
            Boxed<Uint32> Version;

            GetEntityLeaderboardRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                LeaderboardName(),
                PageSize(),
                StartingPosition(),
                Version()
            {}

            GetEntityLeaderboardRequest(const GetEntityLeaderboardRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                LeaderboardName(src.LeaderboardName),
                PageSize(src.PageSize),
                StartingPosition(src.StartingPosition),
                Version(src.Version)
            {}

            ~GetEntityLeaderboardRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["LeaderboardName"], LeaderboardName);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilP(input["StartingPosition"], StartingPosition);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_LeaderboardName; ToJsonUtilS(LeaderboardName, each_LeaderboardName); output["LeaderboardName"] = each_LeaderboardName;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_StartingPosition; ToJsonUtilP(StartingPosition, each_StartingPosition); output["StartingPosition"] = each_StartingPosition;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct GetEntityLeaderboardResponse : public PlayFabResultCommon
        {
            std::list<LeaderboardColumn> Columns;
            std::list<EntityLeaderboardEntry> Rankings;
            Uint32 Version;

            GetEntityLeaderboardResponse() :
                PlayFabResultCommon(),
                Columns(),
                Rankings(),
                Version()
            {}

            GetEntityLeaderboardResponse(const GetEntityLeaderboardResponse& src) :
                PlayFabResultCommon(),
                Columns(src.Columns),
                Rankings(src.Rankings),
                Version(src.Version)
            {}

            ~GetEntityLeaderboardResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Columns"], Columns);
                FromJsonUtilO(input["Rankings"], Rankings);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Columns; ToJsonUtilO(Columns, each_Columns); output["Columns"] = each_Columns;
                Json::Value each_Rankings; ToJsonUtilO(Rankings, each_Rankings); output["Rankings"] = each_Rankings;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct GetFriendLeaderboardForEntityRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            Boxed<ExternalFriendSources> pfExternalFriendSources;
            std::string LeaderboardName;
            Boxed<Uint32> Version;
            std::string XboxToken;

            GetFriendLeaderboardForEntityRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                pfExternalFriendSources(),
                LeaderboardName(),
                Version(),
                XboxToken()
            {}

            GetFriendLeaderboardForEntityRequest(const GetFriendLeaderboardForEntityRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                pfExternalFriendSources(src.pfExternalFriendSources),
                LeaderboardName(src.LeaderboardName),
                Version(src.Version),
                XboxToken(src.XboxToken)
            {}

            ~GetFriendLeaderboardForEntityRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilE(input["ExternalFriendSources"], pfExternalFriendSources);
                FromJsonUtilS(input["LeaderboardName"], LeaderboardName);
                FromJsonUtilP(input["Version"], Version);
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_pfExternalFriendSources; ToJsonUtilE(pfExternalFriendSources, each_pfExternalFriendSources); output["ExternalFriendSources"] = each_pfExternalFriendSources;
                Json::Value each_LeaderboardName; ToJsonUtilS(LeaderboardName, each_LeaderboardName); output["LeaderboardName"] = each_LeaderboardName;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct GetLeaderboardAroundEntityRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string LeaderboardName;
            Uint32 MaxSurroundingEntries;
            Boxed<Uint32> Version;

            GetLeaderboardAroundEntityRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                LeaderboardName(),
                MaxSurroundingEntries(),
                Version()
            {}

            GetLeaderboardAroundEntityRequest(const GetLeaderboardAroundEntityRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                LeaderboardName(src.LeaderboardName),
                MaxSurroundingEntries(src.MaxSurroundingEntries),
                Version(src.Version)
            {}

            ~GetLeaderboardAroundEntityRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["LeaderboardName"], LeaderboardName);
                FromJsonUtilP(input["MaxSurroundingEntries"], MaxSurroundingEntries);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_LeaderboardName; ToJsonUtilS(LeaderboardName, each_LeaderboardName); output["LeaderboardName"] = each_LeaderboardName;
                Json::Value each_MaxSurroundingEntries; ToJsonUtilP(MaxSurroundingEntries, each_MaxSurroundingEntries); output["MaxSurroundingEntries"] = each_MaxSurroundingEntries;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct GetLeaderboardDefinitionRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            GetLeaderboardDefinitionRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            GetLeaderboardDefinitionRequest(const GetLeaderboardDefinitionRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~GetLeaderboardDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct GetLeaderboardDefinitionResponse : public PlayFabResultCommon
        {
            std::list<LeaderboardColumn> Columns;
            time_t Created;
            std::string EntityType;
            Boxed<time_t> LastResetTime;
            std::string Name;
            Int32 SizeLimit;
            Uint32 Version;
            VersionConfiguration pfVersionConfiguration;

            GetLeaderboardDefinitionResponse() :
                PlayFabResultCommon(),
                Columns(),
                Created(),
                EntityType(),
                LastResetTime(),
                Name(),
                SizeLimit(),
                Version(),
                pfVersionConfiguration()
            {}

            GetLeaderboardDefinitionResponse(const GetLeaderboardDefinitionResponse& src) :
                PlayFabResultCommon(),
                Columns(src.Columns),
                Created(src.Created),
                EntityType(src.EntityType),
                LastResetTime(src.LastResetTime),
                Name(src.Name),
                SizeLimit(src.SizeLimit),
                Version(src.Version),
                pfVersionConfiguration(src.pfVersionConfiguration)
            {}

            ~GetLeaderboardDefinitionResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Columns"], Columns);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilS(input["EntityType"], EntityType);
                FromJsonUtilT(input["LastResetTime"], LastResetTime);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["SizeLimit"], SizeLimit);
                FromJsonUtilP(input["Version"], Version);
                FromJsonUtilO(input["VersionConfiguration"], pfVersionConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Columns; ToJsonUtilO(Columns, each_Columns); output["Columns"] = each_Columns;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_EntityType; ToJsonUtilS(EntityType, each_EntityType); output["EntityType"] = each_EntityType;
                Json::Value each_LastResetTime; ToJsonUtilT(LastResetTime, each_LastResetTime); output["LastResetTime"] = each_LastResetTime;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_SizeLimit; ToJsonUtilP(SizeLimit, each_SizeLimit); output["SizeLimit"] = each_SizeLimit;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                Json::Value each_pfVersionConfiguration; ToJsonUtilO(pfVersionConfiguration, each_pfVersionConfiguration); output["VersionConfiguration"] = each_pfVersionConfiguration;
                return output;
            }
        };

        struct GetLeaderboardForEntitiesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::list<std::string> EntityIds;
            std::string LeaderboardName;
            Boxed<Uint32> Version;

            GetLeaderboardForEntitiesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                EntityIds(),
                LeaderboardName(),
                Version()
            {}

            GetLeaderboardForEntitiesRequest(const GetLeaderboardForEntitiesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                EntityIds(src.EntityIds),
                LeaderboardName(src.LeaderboardName),
                Version(src.Version)
            {}

            ~GetLeaderboardForEntitiesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["EntityIds"], EntityIds);
                FromJsonUtilS(input["LeaderboardName"], LeaderboardName);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EntityIds; ToJsonUtilS(EntityIds, each_EntityIds); output["EntityIds"] = each_EntityIds;
                Json::Value each_LeaderboardName; ToJsonUtilS(LeaderboardName, each_LeaderboardName); output["LeaderboardName"] = each_LeaderboardName;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct GetStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            GetStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            GetStatisticDefinitionRequest(const GetStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~GetStatisticDefinitionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct GetStatisticDefinitionResponse : public PlayFabResultCommon
        {
            std::list<StatisticColumn> Columns;
            time_t Created;
            std::string EntityType;
            Boxed<time_t> LastResetTime;
            std::list<std::string> LinkedLeaderboardNames;
            std::string Name;
            Uint32 Version;
            Boxed<VersionConfiguration> pfVersionConfiguration;

            GetStatisticDefinitionResponse() :
                PlayFabResultCommon(),
                Columns(),
                Created(),
                EntityType(),
                LastResetTime(),
                LinkedLeaderboardNames(),
                Name(),
                Version(),
                pfVersionConfiguration()
            {}

            GetStatisticDefinitionResponse(const GetStatisticDefinitionResponse& src) :
                PlayFabResultCommon(),
                Columns(src.Columns),
                Created(src.Created),
                EntityType(src.EntityType),
                LastResetTime(src.LastResetTime),
                LinkedLeaderboardNames(src.LinkedLeaderboardNames),
                Name(src.Name),
                Version(src.Version),
                pfVersionConfiguration(src.pfVersionConfiguration)
            {}

            ~GetStatisticDefinitionResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Columns"], Columns);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilS(input["EntityType"], EntityType);
                FromJsonUtilT(input["LastResetTime"], LastResetTime);
                FromJsonUtilS(input["LinkedLeaderboardNames"], LinkedLeaderboardNames);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["Version"], Version);
                FromJsonUtilO(input["VersionConfiguration"], pfVersionConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Columns; ToJsonUtilO(Columns, each_Columns); output["Columns"] = each_Columns;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_EntityType; ToJsonUtilS(EntityType, each_EntityType); output["EntityType"] = each_EntityType;
                Json::Value each_LastResetTime; ToJsonUtilT(LastResetTime, each_LastResetTime); output["LastResetTime"] = each_LastResetTime;
                Json::Value each_LinkedLeaderboardNames; ToJsonUtilS(LinkedLeaderboardNames, each_LinkedLeaderboardNames); output["LinkedLeaderboardNames"] = each_LinkedLeaderboardNames;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                Json::Value each_pfVersionConfiguration; ToJsonUtilO(pfVersionConfiguration, each_pfVersionConfiguration); output["VersionConfiguration"] = each_pfVersionConfiguration;
                return output;
            }
        };

        struct GetStatisticsForEntitiesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::list<EntityKey> Entities;

            GetStatisticsForEntitiesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entities()
            {}

            GetStatisticsForEntitiesRequest(const GetStatisticsForEntitiesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entities(src.Entities)
            {}

            ~GetStatisticsForEntitiesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entities"], Entities);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entities; ToJsonUtilO(Entities, each_Entities); output["Entities"] = each_Entities;
                return output;
            }
        };

        struct StatisticColumnCollection : public PlayFabBaseModel
        {
            std::list<StatisticColumn> Columns;

            StatisticColumnCollection() :
                PlayFabBaseModel(),
                Columns()
            {}

            StatisticColumnCollection(const StatisticColumnCollection& src) :
                PlayFabBaseModel(),
                Columns(src.Columns)
            {}

            ~StatisticColumnCollection() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Columns"], Columns);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Columns; ToJsonUtilO(Columns, each_Columns); output["Columns"] = each_Columns;
                return output;
            }
        };

        struct GetStatisticsForEntitiesResponse : public PlayFabResultCommon
        {
            std::map<std::string, StatisticColumnCollection> ColumnDetails;
            std::list<EntityStatistics> EntitiesStatistics;

            GetStatisticsForEntitiesResponse() :
                PlayFabResultCommon(),
                ColumnDetails(),
                EntitiesStatistics()
            {}

            GetStatisticsForEntitiesResponse(const GetStatisticsForEntitiesResponse& src) :
                PlayFabResultCommon(),
                ColumnDetails(src.ColumnDetails),
                EntitiesStatistics(src.EntitiesStatistics)
            {}

            ~GetStatisticsForEntitiesResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["ColumnDetails"], ColumnDetails);
                FromJsonUtilO(input["EntitiesStatistics"], EntitiesStatistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ColumnDetails; ToJsonUtilO(ColumnDetails, each_ColumnDetails); output["ColumnDetails"] = each_ColumnDetails;
                Json::Value each_EntitiesStatistics; ToJsonUtilO(EntitiesStatistics, each_EntitiesStatistics); output["EntitiesStatistics"] = each_EntitiesStatistics;
                return output;
            }
        };

        struct GetStatisticsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetStatisticsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            GetStatisticsRequest(const GetStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetStatisticsRequest() = default;

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

        struct GetStatisticsResponse : public PlayFabResultCommon
        {
            std::map<std::string, StatisticColumnCollection> ColumnDetails;
            Boxed<EntityKey> Entity;
            std::map<std::string, EntityStatisticValue> Statistics;

            GetStatisticsResponse() :
                PlayFabResultCommon(),
                ColumnDetails(),
                Entity(),
                Statistics()
            {}

            GetStatisticsResponse(const GetStatisticsResponse& src) :
                PlayFabResultCommon(),
                ColumnDetails(src.ColumnDetails),
                Entity(src.Entity),
                Statistics(src.Statistics)
            {}

            ~GetStatisticsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["ColumnDetails"], ColumnDetails);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ColumnDetails; ToJsonUtilO(ColumnDetails, each_ColumnDetails); output["ColumnDetails"] = each_ColumnDetails;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                return output;
            }
        };

        struct IncrementLeaderboardVersionRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            IncrementLeaderboardVersionRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            IncrementLeaderboardVersionRequest(const IncrementLeaderboardVersionRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~IncrementLeaderboardVersionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct IncrementLeaderboardVersionResponse : public PlayFabResultCommon
        {
            Uint32 Version;

            IncrementLeaderboardVersionResponse() :
                PlayFabResultCommon(),
                Version()
            {}

            IncrementLeaderboardVersionResponse(const IncrementLeaderboardVersionResponse& src) :
                PlayFabResultCommon(),
                Version(src.Version)
            {}

            ~IncrementLeaderboardVersionResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct IncrementStatisticVersionRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            IncrementStatisticVersionRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            IncrementStatisticVersionRequest(const IncrementStatisticVersionRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~IncrementStatisticVersionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct IncrementStatisticVersionResponse : public PlayFabResultCommon
        {
            Uint32 Version;

            IncrementStatisticVersionResponse() :
                PlayFabResultCommon(),
                Version()
            {}

            IncrementStatisticVersionResponse(const IncrementStatisticVersionResponse& src) :
                PlayFabResultCommon(),
                Version(src.Version)
            {}

            ~IncrementStatisticVersionResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct LeaderboardDefinition : public PlayFabBaseModel
        {
            std::list<LeaderboardColumn> Columns;
            time_t Created;
            std::string EntityType;
            Boxed<time_t> LastResetTime;
            std::string Name;
            Int32 SizeLimit;
            Uint32 Version;
            VersionConfiguration pfVersionConfiguration;

            LeaderboardDefinition() :
                PlayFabBaseModel(),
                Columns(),
                Created(),
                EntityType(),
                LastResetTime(),
                Name(),
                SizeLimit(),
                Version(),
                pfVersionConfiguration()
            {}

            LeaderboardDefinition(const LeaderboardDefinition& src) :
                PlayFabBaseModel(),
                Columns(src.Columns),
                Created(src.Created),
                EntityType(src.EntityType),
                LastResetTime(src.LastResetTime),
                Name(src.Name),
                SizeLimit(src.SizeLimit),
                Version(src.Version),
                pfVersionConfiguration(src.pfVersionConfiguration)
            {}

            ~LeaderboardDefinition() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Columns"], Columns);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilS(input["EntityType"], EntityType);
                FromJsonUtilT(input["LastResetTime"], LastResetTime);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["SizeLimit"], SizeLimit);
                FromJsonUtilP(input["Version"], Version);
                FromJsonUtilO(input["VersionConfiguration"], pfVersionConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Columns; ToJsonUtilO(Columns, each_Columns); output["Columns"] = each_Columns;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_EntityType; ToJsonUtilS(EntityType, each_EntityType); output["EntityType"] = each_EntityType;
                Json::Value each_LastResetTime; ToJsonUtilT(LastResetTime, each_LastResetTime); output["LastResetTime"] = each_LastResetTime;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_SizeLimit; ToJsonUtilP(SizeLimit, each_SizeLimit); output["SizeLimit"] = each_SizeLimit;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                Json::Value each_pfVersionConfiguration; ToJsonUtilO(pfVersionConfiguration, each_pfVersionConfiguration); output["VersionConfiguration"] = each_pfVersionConfiguration;
                return output;
            }
        };

        struct LeaderboardEntryUpdate : public PlayFabBaseModel
        {
            std::string EntityId;
            std::string Metadata;
            std::list<std::string> Scores;

            LeaderboardEntryUpdate() :
                PlayFabBaseModel(),
                EntityId(),
                Metadata(),
                Scores()
            {}

            LeaderboardEntryUpdate(const LeaderboardEntryUpdate& src) :
                PlayFabBaseModel(),
                EntityId(src.EntityId),
                Metadata(src.Metadata),
                Scores(src.Scores)
            {}

            ~LeaderboardEntryUpdate() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["EntityId"], EntityId);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilS(input["Scores"], Scores);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EntityId; ToJsonUtilS(EntityId, each_EntityId); output["EntityId"] = each_EntityId;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_Scores; ToJsonUtilS(Scores, each_Scores); output["Scores"] = each_Scores;
                return output;
            }
        };

        struct ListLeaderboardDefinitionsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            ListLeaderboardDefinitionsRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            ListLeaderboardDefinitionsRequest(const ListLeaderboardDefinitionsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~ListLeaderboardDefinitionsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct ListLeaderboardDefinitionsResponse : public PlayFabResultCommon
        {
            std::list<LeaderboardDefinition> LeaderboardDefinitions;

            ListLeaderboardDefinitionsResponse() :
                PlayFabResultCommon(),
                LeaderboardDefinitions()
            {}

            ListLeaderboardDefinitionsResponse(const ListLeaderboardDefinitionsResponse& src) :
                PlayFabResultCommon(),
                LeaderboardDefinitions(src.LeaderboardDefinitions)
            {}

            ~ListLeaderboardDefinitionsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["LeaderboardDefinitions"], LeaderboardDefinitions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LeaderboardDefinitions; ToJsonUtilO(LeaderboardDefinitions, each_LeaderboardDefinitions); output["LeaderboardDefinitions"] = each_LeaderboardDefinitions;
                return output;
            }
        };

        struct ListStatisticDefinitionsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            ListStatisticDefinitionsRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            ListStatisticDefinitionsRequest(const ListStatisticDefinitionsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~ListStatisticDefinitionsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct StatisticDefinition : public PlayFabBaseModel
        {
            std::list<StatisticColumn> Columns;
            time_t Created;
            std::string EntityType;
            Boxed<time_t> LastResetTime;
            std::list<std::string> LinkedLeaderboardNames;
            std::string Name;
            Uint32 Version;
            Boxed<VersionConfiguration> pfVersionConfiguration;

            StatisticDefinition() :
                PlayFabBaseModel(),
                Columns(),
                Created(),
                EntityType(),
                LastResetTime(),
                LinkedLeaderboardNames(),
                Name(),
                Version(),
                pfVersionConfiguration()
            {}

            StatisticDefinition(const StatisticDefinition& src) :
                PlayFabBaseModel(),
                Columns(src.Columns),
                Created(src.Created),
                EntityType(src.EntityType),
                LastResetTime(src.LastResetTime),
                LinkedLeaderboardNames(src.LinkedLeaderboardNames),
                Name(src.Name),
                Version(src.Version),
                pfVersionConfiguration(src.pfVersionConfiguration)
            {}

            ~StatisticDefinition() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Columns"], Columns);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilS(input["EntityType"], EntityType);
                FromJsonUtilT(input["LastResetTime"], LastResetTime);
                FromJsonUtilS(input["LinkedLeaderboardNames"], LinkedLeaderboardNames);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["Version"], Version);
                FromJsonUtilO(input["VersionConfiguration"], pfVersionConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Columns; ToJsonUtilO(Columns, each_Columns); output["Columns"] = each_Columns;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_EntityType; ToJsonUtilS(EntityType, each_EntityType); output["EntityType"] = each_EntityType;
                Json::Value each_LastResetTime; ToJsonUtilT(LastResetTime, each_LastResetTime); output["LastResetTime"] = each_LastResetTime;
                Json::Value each_LinkedLeaderboardNames; ToJsonUtilS(LinkedLeaderboardNames, each_LinkedLeaderboardNames); output["LinkedLeaderboardNames"] = each_LinkedLeaderboardNames;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                Json::Value each_pfVersionConfiguration; ToJsonUtilO(pfVersionConfiguration, each_pfVersionConfiguration); output["VersionConfiguration"] = each_pfVersionConfiguration;
                return output;
            }
        };

        struct ListStatisticDefinitionsResponse : public PlayFabResultCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::list<StatisticDefinition> StatisticDefinitions;

            ListStatisticDefinitionsResponse() :
                PlayFabResultCommon(),
                CustomTags(),
                StatisticDefinitions()
            {}

            ListStatisticDefinitionsResponse(const ListStatisticDefinitionsResponse& src) :
                PlayFabResultCommon(),
                CustomTags(src.CustomTags),
                StatisticDefinitions(src.StatisticDefinitions)
            {}

            ~ListStatisticDefinitionsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["StatisticDefinitions"], StatisticDefinitions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_StatisticDefinitions; ToJsonUtilO(StatisticDefinitions, each_StatisticDefinitions); output["StatisticDefinitions"] = each_StatisticDefinitions;
                return output;
            }
        };

        struct StatisticUpdate : public PlayFabBaseModel
        {
            std::string Metadata;
            std::string Name;
            std::list<std::string> Scores;
            Boxed<Uint32> Version;

            StatisticUpdate() :
                PlayFabBaseModel(),
                Metadata(),
                Name(),
                Scores(),
                Version()
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                Metadata(src.Metadata),
                Name(src.Name),
                Scores(src.Scores),
                Version(src.Version)
            {}

            ~StatisticUpdate() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["Scores"], Scores);
                FromJsonUtilP(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Scores; ToJsonUtilS(Scores, each_Scores); output["Scores"] = each_Scores;
                Json::Value each_Version; ToJsonUtilP(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct UnlinkLeaderboardFromStatisticRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;
            std::string StatisticName;

            UnlinkLeaderboardFromStatisticRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name(),
                StatisticName()
            {}

            UnlinkLeaderboardFromStatisticRequest(const UnlinkLeaderboardFromStatisticRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name),
                StatisticName(src.StatisticName)
            {}

            ~UnlinkLeaderboardFromStatisticRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["StatisticName"], StatisticName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output["StatisticName"] = each_StatisticName;
                return output;
            }
        };

        struct UpdateLeaderboardEntriesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::list<LeaderboardEntryUpdate> Entries;
            std::string LeaderboardName;

            UpdateLeaderboardEntriesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entries(),
                LeaderboardName()
            {}

            UpdateLeaderboardEntriesRequest(const UpdateLeaderboardEntriesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entries(src.Entries),
                LeaderboardName(src.LeaderboardName)
            {}

            ~UpdateLeaderboardEntriesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entries"], Entries);
                FromJsonUtilS(input["LeaderboardName"], LeaderboardName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entries; ToJsonUtilO(Entries, each_Entries); output["Entries"] = each_Entries;
                Json::Value each_LeaderboardName; ToJsonUtilS(LeaderboardName, each_LeaderboardName); output["LeaderboardName"] = each_LeaderboardName;
                return output;
            }
        };

        struct UpdateStatisticsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::list<StatisticUpdate> Statistics;

            UpdateStatisticsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                Statistics()
            {}

            UpdateStatisticsRequest(const UpdateStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Statistics(src.Statistics)
            {}

            ~UpdateStatisticsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                return output;
            }
        };

        struct UpdateStatisticsResponse : public PlayFabResultCommon
        {
            std::map<std::string, StatisticColumnCollection> ColumnDetails;
            Boxed<EntityKey> Entity;
            std::map<std::string, EntityStatisticValue> Statistics;

            UpdateStatisticsResponse() :
                PlayFabResultCommon(),
                ColumnDetails(),
                Entity(),
                Statistics()
            {}

            UpdateStatisticsResponse(const UpdateStatisticsResponse& src) :
                PlayFabResultCommon(),
                ColumnDetails(src.ColumnDetails),
                Entity(src.Entity),
                Statistics(src.Statistics)
            {}

            ~UpdateStatisticsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["ColumnDetails"], ColumnDetails);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Statistics"], Statistics);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ColumnDetails; ToJsonUtilO(ColumnDetails, each_ColumnDetails); output["ColumnDetails"] = each_ColumnDetails;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output["Statistics"] = each_Statistics;
                return output;
            }
        };

    }
}

#endif
