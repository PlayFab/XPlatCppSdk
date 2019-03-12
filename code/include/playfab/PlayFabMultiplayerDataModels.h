#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace MultiplayerModels
    {
        // Multiplayer Enums
        enum AzureRegion
        {
            AzureRegionAustraliaEast,
            AzureRegionAustraliaSoutheast,
            AzureRegionBrazilSouth,
            AzureRegionCentralUs,
            AzureRegionEastAsia,
            AzureRegionEastUs,
            AzureRegionEastUs2,
            AzureRegionJapanEast,
            AzureRegionJapanWest,
            AzureRegionNorthCentralUs,
            AzureRegionNorthEurope,
            AzureRegionSouthCentralUs,
            AzureRegionSoutheastAsia,
            AzureRegionWestEurope,
            AzureRegionWestUs,
            AzureRegionChinaEast2,
            AzureRegionChinaNorth2
        };

        inline void ToJsonEnum(const AzureRegion input, Json::Value& output)
        {
            if (input == AzureRegionAustraliaEast) output = Json::Value("AustraliaEast");
            if (input == AzureRegionAustraliaSoutheast) output = Json::Value("AustraliaSoutheast");
            if (input == AzureRegionBrazilSouth) output = Json::Value("BrazilSouth");
            if (input == AzureRegionCentralUs) output = Json::Value("CentralUs");
            if (input == AzureRegionEastAsia) output = Json::Value("EastAsia");
            if (input == AzureRegionEastUs) output = Json::Value("EastUs");
            if (input == AzureRegionEastUs2) output = Json::Value("EastUs2");
            if (input == AzureRegionJapanEast) output = Json::Value("JapanEast");
            if (input == AzureRegionJapanWest) output = Json::Value("JapanWest");
            if (input == AzureRegionNorthCentralUs) output = Json::Value("NorthCentralUs");
            if (input == AzureRegionNorthEurope) output = Json::Value("NorthEurope");
            if (input == AzureRegionSouthCentralUs) output = Json::Value("SouthCentralUs");
            if (input == AzureRegionSoutheastAsia) output = Json::Value("SoutheastAsia");
            if (input == AzureRegionWestEurope) output = Json::Value("WestEurope");
            if (input == AzureRegionWestUs) output = Json::Value("WestUs");
            if (input == AzureRegionChinaEast2) output = Json::Value("ChinaEast2");
            if (input == AzureRegionChinaNorth2) output = Json::Value("ChinaNorth2");
        }
        inline void FromJsonEnum(const Json::Value& input, AzureRegion& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "AustraliaEast") output = AzureRegionAustraliaEast;
            if (inputStr == "AustraliaSoutheast") output = AzureRegionAustraliaSoutheast;
            if (inputStr == "BrazilSouth") output = AzureRegionBrazilSouth;
            if (inputStr == "CentralUs") output = AzureRegionCentralUs;
            if (inputStr == "EastAsia") output = AzureRegionEastAsia;
            if (inputStr == "EastUs") output = AzureRegionEastUs;
            if (inputStr == "EastUs2") output = AzureRegionEastUs2;
            if (inputStr == "JapanEast") output = AzureRegionJapanEast;
            if (inputStr == "JapanWest") output = AzureRegionJapanWest;
            if (inputStr == "NorthCentralUs") output = AzureRegionNorthCentralUs;
            if (inputStr == "NorthEurope") output = AzureRegionNorthEurope;
            if (inputStr == "SouthCentralUs") output = AzureRegionSouthCentralUs;
            if (inputStr == "SoutheastAsia") output = AzureRegionSoutheastAsia;
            if (inputStr == "WestEurope") output = AzureRegionWestEurope;
            if (inputStr == "WestUs") output = AzureRegionWestUs;
            if (inputStr == "ChinaEast2") output = AzureRegionChinaEast2;
            if (inputStr == "ChinaNorth2") output = AzureRegionChinaNorth2;
        }

        enum AzureVmSize
        {
            AzureVmSizeStandard_D1_v2,
            AzureVmSizeStandard_D2_v2,
            AzureVmSizeStandard_D3_v2,
            AzureVmSizeStandard_D4_v2,
            AzureVmSizeStandard_D5_v2,
            AzureVmSizeStandard_A1_v2,
            AzureVmSizeStandard_A2_v2,
            AzureVmSizeStandard_A4_v2,
            AzureVmSizeStandard_A8_v2,
            AzureVmSizeStandard_F1,
            AzureVmSizeStandard_F2,
            AzureVmSizeStandard_F4,
            AzureVmSizeStandard_F8,
            AzureVmSizeStandard_F16,
            AzureVmSizeStandard_F2s_v2,
            AzureVmSizeStandard_F4s_v2,
            AzureVmSizeStandard_F8s_v2,
            AzureVmSizeStandard_F16s_v2,
            AzureVmSizeStandard_A1,
            AzureVmSizeStandard_A2,
            AzureVmSizeStandard_A3,
            AzureVmSizeStandard_A4
        };

        inline void ToJsonEnum(const AzureVmSize input, Json::Value& output)
        {
            if (input == AzureVmSizeStandard_D1_v2) output = Json::Value("Standard_D1_v2");
            if (input == AzureVmSizeStandard_D2_v2) output = Json::Value("Standard_D2_v2");
            if (input == AzureVmSizeStandard_D3_v2) output = Json::Value("Standard_D3_v2");
            if (input == AzureVmSizeStandard_D4_v2) output = Json::Value("Standard_D4_v2");
            if (input == AzureVmSizeStandard_D5_v2) output = Json::Value("Standard_D5_v2");
            if (input == AzureVmSizeStandard_A1_v2) output = Json::Value("Standard_A1_v2");
            if (input == AzureVmSizeStandard_A2_v2) output = Json::Value("Standard_A2_v2");
            if (input == AzureVmSizeStandard_A4_v2) output = Json::Value("Standard_A4_v2");
            if (input == AzureVmSizeStandard_A8_v2) output = Json::Value("Standard_A8_v2");
            if (input == AzureVmSizeStandard_F1) output = Json::Value("Standard_F1");
            if (input == AzureVmSizeStandard_F2) output = Json::Value("Standard_F2");
            if (input == AzureVmSizeStandard_F4) output = Json::Value("Standard_F4");
            if (input == AzureVmSizeStandard_F8) output = Json::Value("Standard_F8");
            if (input == AzureVmSizeStandard_F16) output = Json::Value("Standard_F16");
            if (input == AzureVmSizeStandard_F2s_v2) output = Json::Value("Standard_F2s_v2");
            if (input == AzureVmSizeStandard_F4s_v2) output = Json::Value("Standard_F4s_v2");
            if (input == AzureVmSizeStandard_F8s_v2) output = Json::Value("Standard_F8s_v2");
            if (input == AzureVmSizeStandard_F16s_v2) output = Json::Value("Standard_F16s_v2");
            if (input == AzureVmSizeStandard_A1) output = Json::Value("Standard_A1");
            if (input == AzureVmSizeStandard_A2) output = Json::Value("Standard_A2");
            if (input == AzureVmSizeStandard_A3) output = Json::Value("Standard_A3");
            if (input == AzureVmSizeStandard_A4) output = Json::Value("Standard_A4");
        }
        inline void FromJsonEnum(const Json::Value& input, AzureVmSize& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Standard_D1_v2") output = AzureVmSizeStandard_D1_v2;
            if (inputStr == "Standard_D2_v2") output = AzureVmSizeStandard_D2_v2;
            if (inputStr == "Standard_D3_v2") output = AzureVmSizeStandard_D3_v2;
            if (inputStr == "Standard_D4_v2") output = AzureVmSizeStandard_D4_v2;
            if (inputStr == "Standard_D5_v2") output = AzureVmSizeStandard_D5_v2;
            if (inputStr == "Standard_A1_v2") output = AzureVmSizeStandard_A1_v2;
            if (inputStr == "Standard_A2_v2") output = AzureVmSizeStandard_A2_v2;
            if (inputStr == "Standard_A4_v2") output = AzureVmSizeStandard_A4_v2;
            if (inputStr == "Standard_A8_v2") output = AzureVmSizeStandard_A8_v2;
            if (inputStr == "Standard_F1") output = AzureVmSizeStandard_F1;
            if (inputStr == "Standard_F2") output = AzureVmSizeStandard_F2;
            if (inputStr == "Standard_F4") output = AzureVmSizeStandard_F4;
            if (inputStr == "Standard_F8") output = AzureVmSizeStandard_F8;
            if (inputStr == "Standard_F16") output = AzureVmSizeStandard_F16;
            if (inputStr == "Standard_F2s_v2") output = AzureVmSizeStandard_F2s_v2;
            if (inputStr == "Standard_F4s_v2") output = AzureVmSizeStandard_F4s_v2;
            if (inputStr == "Standard_F8s_v2") output = AzureVmSizeStandard_F8s_v2;
            if (inputStr == "Standard_F16s_v2") output = AzureVmSizeStandard_F16s_v2;
            if (inputStr == "Standard_A1") output = AzureVmSizeStandard_A1;
            if (inputStr == "Standard_A2") output = AzureVmSizeStandard_A2;
            if (inputStr == "Standard_A3") output = AzureVmSizeStandard_A3;
            if (inputStr == "Standard_A4") output = AzureVmSizeStandard_A4;
        }

        enum CancellationReason
        {
            CancellationReasonRequested,
            CancellationReasonInternal,
            CancellationReasonTimeout
        };

        inline void ToJsonEnum(const CancellationReason input, Json::Value& output)
        {
            if (input == CancellationReasonRequested) output = Json::Value("Requested");
            if (input == CancellationReasonInternal) output = Json::Value("Internal");
            if (input == CancellationReasonTimeout) output = Json::Value("Timeout");
        }
        inline void FromJsonEnum(const Json::Value& input, CancellationReason& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Requested") output = CancellationReasonRequested;
            if (inputStr == "Internal") output = CancellationReasonInternal;
            if (inputStr == "Timeout") output = CancellationReasonTimeout;
        }

        enum ContainerFlavor
        {
            ContainerFlavorManagedWindowsServerCore,
            ContainerFlavorCustomLinux,
            ContainerFlavorManagedWindowsServerCorePreview
        };

        inline void ToJsonEnum(const ContainerFlavor input, Json::Value& output)
        {
            if (input == ContainerFlavorManagedWindowsServerCore) output = Json::Value("ManagedWindowsServerCore");
            if (input == ContainerFlavorCustomLinux) output = Json::Value("CustomLinux");
            if (input == ContainerFlavorManagedWindowsServerCorePreview) output = Json::Value("ManagedWindowsServerCorePreview");
        }
        inline void FromJsonEnum(const Json::Value& input, ContainerFlavor& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "ManagedWindowsServerCore") output = ContainerFlavorManagedWindowsServerCore;
            if (inputStr == "CustomLinux") output = ContainerFlavorCustomLinux;
            if (inputStr == "ManagedWindowsServerCorePreview") output = ContainerFlavorManagedWindowsServerCorePreview;
        }

        enum ProtocolType
        {
            ProtocolTypeTCP,
            ProtocolTypeUDP
        };

        inline void ToJsonEnum(const ProtocolType input, Json::Value& output)
        {
            if (input == ProtocolTypeTCP) output = Json::Value("TCP");
            if (input == ProtocolTypeUDP) output = Json::Value("UDP");
        }
        inline void FromJsonEnum(const Json::Value& input, ProtocolType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "TCP") output = ProtocolTypeTCP;
            if (inputStr == "UDP") output = ProtocolTypeUDP;
        }

        enum RuleType
        {
            RuleTypeUnknown,
            RuleTypeDifferenceRule,
            RuleTypeStringEqualityRule,
            RuleTypeMatchTotalRule,
            RuleTypeSetIntersectionRule,
            RuleTypeTeamSizeBalanceRule,
            RuleTypeRegionSelectionRule,
            RuleTypeTeamDifferenceRule,
            RuleTypeTeamTicketSizeSimilarityRule
        };

        inline void ToJsonEnum(const RuleType input, Json::Value& output)
        {
            if (input == RuleTypeUnknown) output = Json::Value("Unknown");
            if (input == RuleTypeDifferenceRule) output = Json::Value("DifferenceRule");
            if (input == RuleTypeStringEqualityRule) output = Json::Value("StringEqualityRule");
            if (input == RuleTypeMatchTotalRule) output = Json::Value("MatchTotalRule");
            if (input == RuleTypeSetIntersectionRule) output = Json::Value("SetIntersectionRule");
            if (input == RuleTypeTeamSizeBalanceRule) output = Json::Value("TeamSizeBalanceRule");
            if (input == RuleTypeRegionSelectionRule) output = Json::Value("RegionSelectionRule");
            if (input == RuleTypeTeamDifferenceRule) output = Json::Value("TeamDifferenceRule");
            if (input == RuleTypeTeamTicketSizeSimilarityRule) output = Json::Value("TeamTicketSizeSimilarityRule");
        }
        inline void FromJsonEnum(const Json::Value& input, RuleType& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown") output = RuleTypeUnknown;
            if (inputStr == "DifferenceRule") output = RuleTypeDifferenceRule;
            if (inputStr == "StringEqualityRule") output = RuleTypeStringEqualityRule;
            if (inputStr == "MatchTotalRule") output = RuleTypeMatchTotalRule;
            if (inputStr == "SetIntersectionRule") output = RuleTypeSetIntersectionRule;
            if (inputStr == "TeamSizeBalanceRule") output = RuleTypeTeamSizeBalanceRule;
            if (inputStr == "RegionSelectionRule") output = RuleTypeRegionSelectionRule;
            if (inputStr == "TeamDifferenceRule") output = RuleTypeTeamDifferenceRule;
            if (inputStr == "TeamTicketSizeSimilarityRule") output = RuleTypeTeamTicketSizeSimilarityRule;
        }

        enum TitleMultiplayerServerEnabledStatus
        {
            TitleMultiplayerServerEnabledStatusInitializing,
            TitleMultiplayerServerEnabledStatusEnabled,
            TitleMultiplayerServerEnabledStatusDisabled
        };

        inline void ToJsonEnum(const TitleMultiplayerServerEnabledStatus input, Json::Value& output)
        {
            if (input == TitleMultiplayerServerEnabledStatusInitializing) output = Json::Value("Initializing");
            if (input == TitleMultiplayerServerEnabledStatusEnabled) output = Json::Value("Enabled");
            if (input == TitleMultiplayerServerEnabledStatusDisabled) output = Json::Value("Disabled");
        }
        inline void FromJsonEnum(const Json::Value& input, TitleMultiplayerServerEnabledStatus& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Initializing") output = TitleMultiplayerServerEnabledStatusInitializing;
            if (inputStr == "Enabled") output = TitleMultiplayerServerEnabledStatusEnabled;
            if (inputStr == "Disabled") output = TitleMultiplayerServerEnabledStatusDisabled;
        }

        // Multiplayer Classes
        struct AssetReference : public PlayFabBaseModel
        {
            std::string FileName;
            std::string MountPath;

            AssetReference() :
                PlayFabBaseModel(),
                FileName(),
                MountPath()
            {}

            AssetReference(const AssetReference& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                MountPath(src.MountPath)
            {}

            ~AssetReference() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FileName"], FileName);
                FromJsonUtilS(input["MountPath"], MountPath);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                Json::Value each_MountPath; ToJsonUtilS(MountPath, each_MountPath); output["MountPath"] = each_MountPath;
                return output;
            }
        };

        struct AssetReferenceParams : public PlayFabBaseModel
        {
            std::string FileName;
            std::string MountPath;

            AssetReferenceParams() :
                PlayFabBaseModel(),
                FileName(),
                MountPath()
            {}

            AssetReferenceParams(const AssetReferenceParams& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                MountPath(src.MountPath)
            {}

            ~AssetReferenceParams() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FileName"], FileName);
                FromJsonUtilS(input["MountPath"], MountPath);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                Json::Value each_MountPath; ToJsonUtilS(MountPath, each_MountPath); output["MountPath"] = each_MountPath;
                return output;
            }
        };

        struct AssetSummary : public PlayFabBaseModel
        {
            std::string FileName;
            std::map<std::string, std::string> Metadata;

            AssetSummary() :
                PlayFabBaseModel(),
                FileName(),
                Metadata()
            {}

            AssetSummary(const AssetSummary& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                Metadata(src.Metadata)
            {}

            ~AssetSummary() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FileName"], FileName);
                FromJsonUtilS(input["Metadata"], Metadata);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                return output;
            }
        };

        struct CurrentServerStats : public PlayFabBaseModel
        {
            Int32 Active;
            Int32 Propping;
            Int32 StandingBy;
            Int32 Total;

            CurrentServerStats() :
                PlayFabBaseModel(),
                Active(),
                Propping(),
                StandingBy(),
                Total()
            {}

            CurrentServerStats(const CurrentServerStats& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                Propping(src.Propping),
                StandingBy(src.StandingBy),
                Total(src.Total)
            {}

            ~CurrentServerStats() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Active"], Active);
                FromJsonUtilP(input["Propping"], Propping);
                FromJsonUtilP(input["StandingBy"], StandingBy);
                FromJsonUtilP(input["Total"], Total);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Active; ToJsonUtilP(Active, each_Active); output["Active"] = each_Active;
                Json::Value each_Propping; ToJsonUtilP(Propping, each_Propping); output["Propping"] = each_Propping;
                Json::Value each_StandingBy; ToJsonUtilP(StandingBy, each_StandingBy); output["StandingBy"] = each_StandingBy;
                Json::Value each_Total; ToJsonUtilP(Total, each_Total); output["Total"] = each_Total;
                return output;
            }
        };

        struct BuildRegion : public PlayFabBaseModel
        {
            Boxed<CurrentServerStats> pfCurrentServerStats;
            Int32 MaxServers;
            Boxed<AzureRegion> Region;
            Int32 StandbyServers;
            std::string Status;

            BuildRegion() :
                PlayFabBaseModel(),
                pfCurrentServerStats(),
                MaxServers(),
                Region(),
                StandbyServers(),
                Status()
            {}

            BuildRegion(const BuildRegion& src) :
                PlayFabBaseModel(),
                pfCurrentServerStats(src.pfCurrentServerStats),
                MaxServers(src.MaxServers),
                Region(src.Region),
                StandbyServers(src.StandbyServers),
                Status(src.Status)
            {}

            ~BuildRegion() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["pfCurrentServerStats"], pfCurrentServerStats);
                FromJsonUtilP(input["MaxServers"], MaxServers);
                FromJsonUtilE(input["Region"], Region);
                FromJsonUtilP(input["StandbyServers"], StandbyServers);
                FromJsonUtilS(input["Status"], Status);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfCurrentServerStats; ToJsonUtilO(pfCurrentServerStats, each_pfCurrentServerStats); output["CurrentServerStats"] = each_pfCurrentServerStats;
                Json::Value each_MaxServers; ToJsonUtilP(MaxServers, each_MaxServers); output["MaxServers"] = each_MaxServers;
                Json::Value each_Region; ToJsonUtilE(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_StandbyServers; ToJsonUtilP(StandbyServers, each_StandbyServers); output["StandbyServers"] = each_StandbyServers;
                Json::Value each_Status; ToJsonUtilS(Status, each_Status); output["Status"] = each_Status;
                return output;
            }
        };

        struct BuildRegionParams : public PlayFabBaseModel
        {
            Int32 MaxServers;
            AzureRegion Region;
            Int32 StandbyServers;

            BuildRegionParams() :
                PlayFabBaseModel(),
                MaxServers(),
                Region(),
                StandbyServers()
            {}

            BuildRegionParams(const BuildRegionParams& src) :
                PlayFabBaseModel(),
                MaxServers(src.MaxServers),
                Region(src.Region),
                StandbyServers(src.StandbyServers)
            {}

            ~BuildRegionParams() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["MaxServers"], MaxServers);
                FromJsonEnum(input["Region"], Region);
                FromJsonUtilP(input["StandbyServers"], StandbyServers);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MaxServers; ToJsonUtilP(MaxServers, each_MaxServers); output["MaxServers"] = each_MaxServers;
                Json::Value each_Region; ToJsonEnum(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_StandbyServers; ToJsonUtilP(StandbyServers, each_StandbyServers); output["StandbyServers"] = each_StandbyServers;
                return output;
            }
        };

        struct BuildSummary : public PlayFabBaseModel
        {
            std::string BuildId;
            std::string BuildName;
            Boxed<time_t> CreationTime;
            std::map<std::string, std::string> Metadata;

            BuildSummary() :
                PlayFabBaseModel(),
                BuildId(),
                BuildName(),
                CreationTime(),
                Metadata()
            {}

            BuildSummary(const BuildSummary& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                CreationTime(src.CreationTime),
                Metadata(src.Metadata)
            {}

            ~BuildSummary() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilS(input["Metadata"], Metadata);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_CreationTime; ToJsonUtilT(CreationTime, each_CreationTime); output["CreationTime"] = each_CreationTime;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
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

        struct CancelAllMatchmakingTicketsForPlayerRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string QueueName;

            CancelAllMatchmakingTicketsForPlayerRequest() :
                PlayFabRequestCommon(),
                Entity(),
                QueueName()
            {}

            CancelAllMatchmakingTicketsForPlayerRequest(const CancelAllMatchmakingTicketsForPlayerRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                QueueName(src.QueueName)
            {}

            ~CancelAllMatchmakingTicketsForPlayerRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct CancelAllMatchmakingTicketsForPlayerResult : public PlayFabResultCommon
        {

            CancelAllMatchmakingTicketsForPlayerResult() :
                PlayFabResultCommon()
            {}

            CancelAllMatchmakingTicketsForPlayerResult(const CancelAllMatchmakingTicketsForPlayerResult&) :
                PlayFabResultCommon()
            {}

            ~CancelAllMatchmakingTicketsForPlayerResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CancelMatchmakingTicketRequest : public PlayFabRequestCommon
        {
            std::string QueueName;
            std::string TicketId;

            CancelMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                QueueName(),
                TicketId()
            {}

            CancelMatchmakingTicketRequest(const CancelMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                QueueName(src.QueueName),
                TicketId(src.TicketId)
            {}

            ~CancelMatchmakingTicketRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_TicketId; ToJsonUtilS(TicketId, each_TicketId); output["TicketId"] = each_TicketId;
                return output;
            }
        };

        struct CancelMatchmakingTicketResult : public PlayFabResultCommon
        {

            CancelMatchmakingTicketResult() :
                PlayFabResultCommon()
            {}

            CancelMatchmakingTicketResult(const CancelMatchmakingTicketResult&) :
                PlayFabResultCommon()
            {}

            ~CancelMatchmakingTicketResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct Certificate : public PlayFabBaseModel
        {
            std::string Base64EncodedValue;
            std::string Name;
            std::string Password;

            Certificate() :
                PlayFabBaseModel(),
                Base64EncodedValue(),
                Name(),
                Password()
            {}

            Certificate(const Certificate& src) :
                PlayFabBaseModel(),
                Base64EncodedValue(src.Base64EncodedValue),
                Name(src.Name),
                Password(src.Password)
            {}

            ~Certificate() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Base64EncodedValue"], Base64EncodedValue);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["Password"], Password);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Base64EncodedValue; ToJsonUtilS(Base64EncodedValue, each_Base64EncodedValue); output["Base64EncodedValue"] = each_Base64EncodedValue;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                return output;
            }
        };

        struct CertificateSummary : public PlayFabBaseModel
        {
            std::string Name;
            std::string Thumbprint;

            CertificateSummary() :
                PlayFabBaseModel(),
                Name(),
                Thumbprint()
            {}

            CertificateSummary(const CertificateSummary& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Thumbprint(src.Thumbprint)
            {}

            ~CertificateSummary() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["Thumbprint"], Thumbprint);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Thumbprint; ToJsonUtilS(Thumbprint, each_Thumbprint); output["Thumbprint"] = each_Thumbprint;
                return output;
            }
        };

        struct ConnectedPlayer : public PlayFabBaseModel
        {
            std::string PlayerId;

            ConnectedPlayer() :
                PlayFabBaseModel(),
                PlayerId()
            {}

            ConnectedPlayer(const ConnectedPlayer& src) :
                PlayFabBaseModel(),
                PlayerId(src.PlayerId)
            {}

            ~ConnectedPlayer() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["PlayerId"], PlayerId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output["PlayerId"] = each_PlayerId;
                return output;
            }
        };

        struct ContainerImageReference : public PlayFabBaseModel
        {
            std::string ImageName;
            std::string Tag;

            ContainerImageReference() :
                PlayFabBaseModel(),
                ImageName(),
                Tag()
            {}

            ContainerImageReference(const ContainerImageReference& src) :
                PlayFabBaseModel(),
                ImageName(src.ImageName),
                Tag(src.Tag)
            {}

            ~ContainerImageReference() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ImageName"], ImageName);
                FromJsonUtilS(input["Tag"], Tag);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ImageName; ToJsonUtilS(ImageName, each_ImageName); output["ImageName"] = each_ImageName;
                Json::Value each_Tag; ToJsonUtilS(Tag, each_Tag); output["Tag"] = each_Tag;
                return output;
            }
        };

        struct GameCertificateReferenceParams : public PlayFabBaseModel
        {
            std::string GsdkAlias;
            std::string Name;

            GameCertificateReferenceParams() :
                PlayFabBaseModel(),
                GsdkAlias(),
                Name()
            {}

            GameCertificateReferenceParams(const GameCertificateReferenceParams& src) :
                PlayFabBaseModel(),
                GsdkAlias(src.GsdkAlias),
                Name(src.Name)
            {}

            ~GameCertificateReferenceParams() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["GsdkAlias"], GsdkAlias);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GsdkAlias; ToJsonUtilS(GsdkAlias, each_GsdkAlias); output["GsdkAlias"] = each_GsdkAlias;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct Port : public PlayFabBaseModel
        {
            std::string Name;
            Int32 Num;
            ProtocolType Protocol;

            Port() :
                PlayFabBaseModel(),
                Name(),
                Num(),
                Protocol()
            {}

            Port(const Port& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Num(src.Num),
                Protocol(src.Protocol)
            {}

            ~Port() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["Num"], Num);
                FromJsonEnum(input["Protocol"], Protocol);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Num; ToJsonUtilP(Num, each_Num); output["Num"] = each_Num;
                Json::Value each_Protocol; ToJsonEnum(Protocol, each_Protocol); output["Protocol"] = each_Protocol;
                return output;
            }
        };

        struct CreateBuildWithCustomContainerRequest : public PlayFabRequestCommon
        {
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::string ContainerRepositoryName;
            std::string ContainerRunCommand;
            std::string ContainerTag;
            std::list<AssetReferenceParams> GameAssetReferences;
            std::list<GameCertificateReferenceParams> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegionParams> RegionConfigurations;
            Boxed<AzureVmSize> VmSize;

            CreateBuildWithCustomContainerRequest() :
                PlayFabRequestCommon(),
                BuildName(),
                pfContainerFlavor(),
                ContainerRepositoryName(),
                ContainerRunCommand(),
                ContainerTag(),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(),
                Ports(),
                RegionConfigurations(),
                VmSize()
            {}

            CreateBuildWithCustomContainerRequest(const CreateBuildWithCustomContainerRequest& src) :
                PlayFabRequestCommon(),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                ContainerRepositoryName(src.ContainerRepositoryName),
                ContainerRunCommand(src.ContainerRunCommand),
                ContainerTag(src.ContainerTag),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                VmSize(src.VmSize)
            {}

            ~CreateBuildWithCustomContainerRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["pfContainerFlavor"], pfContainerFlavor);
                FromJsonUtilS(input["ContainerRepositoryName"], ContainerRepositoryName);
                FromJsonUtilS(input["ContainerRunCommand"], ContainerRunCommand);
                FromJsonUtilS(input["ContainerTag"], ContainerTag);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilE(input["VmSize"], VmSize);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_ContainerRepositoryName; ToJsonUtilS(ContainerRepositoryName, each_ContainerRepositoryName); output["ContainerRepositoryName"] = each_ContainerRepositoryName;
                Json::Value each_ContainerRunCommand; ToJsonUtilS(ContainerRunCommand, each_ContainerRunCommand); output["ContainerRunCommand"] = each_ContainerRunCommand;
                Json::Value each_ContainerTag; ToJsonUtilS(ContainerTag, each_ContainerTag); output["ContainerTag"] = each_ContainerTag;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                return output;
            }
        };

        struct GameCertificateReference : public PlayFabBaseModel
        {
            std::string GsdkAlias;
            std::string Name;

            GameCertificateReference() :
                PlayFabBaseModel(),
                GsdkAlias(),
                Name()
            {}

            GameCertificateReference(const GameCertificateReference& src) :
                PlayFabBaseModel(),
                GsdkAlias(src.GsdkAlias),
                Name(src.Name)
            {}

            ~GameCertificateReference() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["GsdkAlias"], GsdkAlias);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GsdkAlias; ToJsonUtilS(GsdkAlias, each_GsdkAlias); output["GsdkAlias"] = each_GsdkAlias;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct CreateBuildWithCustomContainerResponse : public PlayFabResultCommon
        {
            std::string BuildId;
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::string ContainerRunCommand;
            Boxed<time_t> CreationTime;
            Boxed<ContainerImageReference> CustomGameContainerImage;
            std::list<AssetReference> GameAssetReferences;
            std::list<GameCertificateReference> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            Boxed<AzureVmSize> VmSize;

            CreateBuildWithCustomContainerResponse() :
                PlayFabResultCommon(),
                BuildId(),
                BuildName(),
                pfContainerFlavor(),
                ContainerRunCommand(),
                CreationTime(),
                CustomGameContainerImage(),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(),
                Ports(),
                RegionConfigurations(),
                VmSize()
            {}

            CreateBuildWithCustomContainerResponse(const CreateBuildWithCustomContainerResponse& src) :
                PlayFabResultCommon(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                ContainerRunCommand(src.ContainerRunCommand),
                CreationTime(src.CreationTime),
                CustomGameContainerImage(src.CustomGameContainerImage),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                VmSize(src.VmSize)
            {}

            ~CreateBuildWithCustomContainerResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["pfContainerFlavor"], pfContainerFlavor);
                FromJsonUtilS(input["ContainerRunCommand"], ContainerRunCommand);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilO(input["CustomGameContainerImage"], CustomGameContainerImage);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilE(input["VmSize"], VmSize);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_ContainerRunCommand; ToJsonUtilS(ContainerRunCommand, each_ContainerRunCommand); output["ContainerRunCommand"] = each_ContainerRunCommand;
                Json::Value each_CreationTime; ToJsonUtilT(CreationTime, each_CreationTime); output["CreationTime"] = each_CreationTime;
                Json::Value each_CustomGameContainerImage; ToJsonUtilO(CustomGameContainerImage, each_CustomGameContainerImage); output["CustomGameContainerImage"] = each_CustomGameContainerImage;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                return output;
            }
        };

        struct CreateBuildWithManagedContainerRequest : public PlayFabRequestCommon
        {
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::list<AssetReferenceParams> GameAssetReferences;
            std::list<GameCertificateReferenceParams> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegionParams> RegionConfigurations;
            std::string StartMultiplayerServerCommand;
            Boxed<AzureVmSize> VmSize;

            CreateBuildWithManagedContainerRequest() :
                PlayFabRequestCommon(),
                BuildName(),
                pfContainerFlavor(),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(),
                Ports(),
                RegionConfigurations(),
                StartMultiplayerServerCommand(),
                VmSize()
            {}

            CreateBuildWithManagedContainerRequest(const CreateBuildWithManagedContainerRequest& src) :
                PlayFabRequestCommon(),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize)
            {}

            ~CreateBuildWithManagedContainerRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["pfContainerFlavor"], pfContainerFlavor);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilS(input["StartMultiplayerServerCommand"], StartMultiplayerServerCommand);
                FromJsonUtilE(input["VmSize"], VmSize);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_StartMultiplayerServerCommand; ToJsonUtilS(StartMultiplayerServerCommand, each_StartMultiplayerServerCommand); output["StartMultiplayerServerCommand"] = each_StartMultiplayerServerCommand;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                return output;
            }
        };

        struct CreateBuildWithManagedContainerResponse : public PlayFabResultCommon
        {
            std::string BuildId;
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            Boxed<time_t> CreationTime;
            std::list<AssetReference> GameAssetReferences;
            std::list<GameCertificateReference> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            std::string StartMultiplayerServerCommand;
            Boxed<AzureVmSize> VmSize;

            CreateBuildWithManagedContainerResponse() :
                PlayFabResultCommon(),
                BuildId(),
                BuildName(),
                pfContainerFlavor(),
                CreationTime(),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(),
                Ports(),
                RegionConfigurations(),
                StartMultiplayerServerCommand(),
                VmSize()
            {}

            CreateBuildWithManagedContainerResponse(const CreateBuildWithManagedContainerResponse& src) :
                PlayFabResultCommon(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                CreationTime(src.CreationTime),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize)
            {}

            ~CreateBuildWithManagedContainerResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["pfContainerFlavor"], pfContainerFlavor);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilS(input["StartMultiplayerServerCommand"], StartMultiplayerServerCommand);
                FromJsonUtilE(input["VmSize"], VmSize);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_CreationTime; ToJsonUtilT(CreationTime, each_CreationTime); output["CreationTime"] = each_CreationTime;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_StartMultiplayerServerCommand; ToJsonUtilS(StartMultiplayerServerCommand, each_StartMultiplayerServerCommand); output["StartMultiplayerServerCommand"] = each_StartMultiplayerServerCommand;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                return output;
            }
        };

        struct MatchmakingPlayerAttributes : public PlayFabBaseModel
        {
            Json::Value DataObject;
            std::string EscapedDataObject;

            MatchmakingPlayerAttributes() :
                PlayFabBaseModel(),
                DataObject(),
                EscapedDataObject()
            {}

            MatchmakingPlayerAttributes(const MatchmakingPlayerAttributes& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject)
            {}

            ~MatchmakingPlayerAttributes() = default;

            void FromJson(Json::Value& input) override
            {
                DataObject = input["DataObject"];
                FromJsonUtilS(input["EscapedDataObject"], EscapedDataObject);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["DataObject"] = DataObject;
                Json::Value each_EscapedDataObject; ToJsonUtilS(EscapedDataObject, each_EscapedDataObject); output["EscapedDataObject"] = each_EscapedDataObject;
                return output;
            }
        };

        struct MatchmakingPlayer : public PlayFabBaseModel
        {
            Boxed<MatchmakingPlayerAttributes> Attributes;
            EntityKey Entity;

            MatchmakingPlayer() :
                PlayFabBaseModel(),
                Attributes(),
                Entity()
            {}

            MatchmakingPlayer(const MatchmakingPlayer& src) :
                PlayFabBaseModel(),
                Attributes(src.Attributes),
                Entity(src.Entity)
            {}

            ~MatchmakingPlayer() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Attributes"], Attributes);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Attributes; ToJsonUtilO(Attributes, each_Attributes); output["Attributes"] = each_Attributes;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct CreateMatchmakingTicketRequest : public PlayFabRequestCommon
        {
            MatchmakingPlayer Creator;
            Int32 GiveUpAfterSeconds;
            std::list<EntityKey> MembersToMatchWith;
            std::string QueueName;

            CreateMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                Creator(),
                GiveUpAfterSeconds(),
                MembersToMatchWith(),
                QueueName()
            {}

            CreateMatchmakingTicketRequest(const CreateMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                Creator(src.Creator),
                GiveUpAfterSeconds(src.GiveUpAfterSeconds),
                MembersToMatchWith(src.MembersToMatchWith),
                QueueName(src.QueueName)
            {}

            ~CreateMatchmakingTicketRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Creator"], Creator);
                FromJsonUtilP(input["GiveUpAfterSeconds"], GiveUpAfterSeconds);
                FromJsonUtilO(input["MembersToMatchWith"], MembersToMatchWith);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Creator; ToJsonUtilO(Creator, each_Creator); output["Creator"] = each_Creator;
                Json::Value each_GiveUpAfterSeconds; ToJsonUtilP(GiveUpAfterSeconds, each_GiveUpAfterSeconds); output["GiveUpAfterSeconds"] = each_GiveUpAfterSeconds;
                Json::Value each_MembersToMatchWith; ToJsonUtilO(MembersToMatchWith, each_MembersToMatchWith); output["MembersToMatchWith"] = each_MembersToMatchWith;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct CreateMatchmakingTicketResult : public PlayFabResultCommon
        {
            std::string TicketId;

            CreateMatchmakingTicketResult() :
                PlayFabResultCommon(),
                TicketId()
            {}

            CreateMatchmakingTicketResult(const CreateMatchmakingTicketResult& src) :
                PlayFabResultCommon(),
                TicketId(src.TicketId)
            {}

            ~CreateMatchmakingTicketResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TicketId; ToJsonUtilS(TicketId, each_TicketId); output["TicketId"] = each_TicketId;
                return output;
            }
        };

        struct CreateRemoteUserRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            Boxed<time_t> ExpirationTime;
            AzureRegion Region;
            std::string Username;
            std::string VmId;

            CreateRemoteUserRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                ExpirationTime(),
                Region(),
                Username(),
                VmId()
            {}

            CreateRemoteUserRequest(const CreateRemoteUserRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                ExpirationTime(src.ExpirationTime),
                Region(src.Region),
                Username(src.Username),
                VmId(src.VmId)
            {}

            ~CreateRemoteUserRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilT(input["ExpirationTime"], ExpirationTime);
                FromJsonEnum(input["Region"], Region);
                FromJsonUtilS(input["Username"], Username);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_ExpirationTime; ToJsonUtilT(ExpirationTime, each_ExpirationTime); output["ExpirationTime"] = each_ExpirationTime;
                Json::Value each_Region; ToJsonEnum(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
                return output;
            }
        };

        struct CreateRemoteUserResponse : public PlayFabResultCommon
        {
            Boxed<time_t> ExpirationTime;
            std::string Password;
            std::string Username;

            CreateRemoteUserResponse() :
                PlayFabResultCommon(),
                ExpirationTime(),
                Password(),
                Username()
            {}

            CreateRemoteUserResponse(const CreateRemoteUserResponse& src) :
                PlayFabResultCommon(),
                ExpirationTime(src.ExpirationTime),
                Password(src.Password),
                Username(src.Username)
            {}

            ~CreateRemoteUserResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilT(input["ExpirationTime"], ExpirationTime);
                FromJsonUtilS(input["Password"], Password);
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpirationTime; ToJsonUtilT(ExpirationTime, each_ExpirationTime); output["ExpirationTime"] = each_ExpirationTime;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
                return output;
            }
        };

        struct CreateServerMatchmakingTicketRequest : public PlayFabRequestCommon
        {
            Int32 GiveUpAfterSeconds;
            std::list<MatchmakingPlayer> Members;
            std::string QueueName;

            CreateServerMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                GiveUpAfterSeconds(),
                Members(),
                QueueName()
            {}

            CreateServerMatchmakingTicketRequest(const CreateServerMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                GiveUpAfterSeconds(src.GiveUpAfterSeconds),
                Members(src.Members),
                QueueName(src.QueueName)
            {}

            ~CreateServerMatchmakingTicketRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["GiveUpAfterSeconds"], GiveUpAfterSeconds);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GiveUpAfterSeconds; ToJsonUtilP(GiveUpAfterSeconds, each_GiveUpAfterSeconds); output["GiveUpAfterSeconds"] = each_GiveUpAfterSeconds;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct DeleteAssetRequest : public PlayFabRequestCommon
        {
            std::string FileName;

            DeleteAssetRequest() :
                PlayFabRequestCommon(),
                FileName()
            {}

            DeleteAssetRequest(const DeleteAssetRequest& src) :
                PlayFabRequestCommon(),
                FileName(src.FileName)
            {}

            ~DeleteAssetRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FileName"], FileName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                return output;
            }
        };

        struct DeleteBuildRequest : public PlayFabRequestCommon
        {
            std::string BuildId;

            DeleteBuildRequest() :
                PlayFabRequestCommon(),
                BuildId()
            {}

            DeleteBuildRequest(const DeleteBuildRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId)
            {}

            ~DeleteBuildRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                return output;
            }
        };

        struct DeleteCertificateRequest : public PlayFabRequestCommon
        {
            std::string Name;

            DeleteCertificateRequest() :
                PlayFabRequestCommon(),
                Name()
            {}

            DeleteCertificateRequest(const DeleteCertificateRequest& src) :
                PlayFabRequestCommon(),
                Name(src.Name)
            {}

            ~DeleteCertificateRequest() = default;

            void FromJson(Json::Value& input) override
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

        struct DeleteRemoteUserRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            AzureRegion Region;
            std::string Username;
            std::string VmId;

            DeleteRemoteUserRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                Region(),
                Username(),
                VmId()
            {}

            DeleteRemoteUserRequest(const DeleteRemoteUserRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                Region(src.Region),
                Username(src.Username),
                VmId(src.VmId)
            {}

            ~DeleteRemoteUserRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonEnum(input["Region"], Region);
                FromJsonUtilS(input["Username"], Username);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_Region; ToJsonEnum(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
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

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct EnableMultiplayerServersForTitleRequest : public PlayFabRequestCommon
        {

            EnableMultiplayerServersForTitleRequest() :
                PlayFabRequestCommon()
            {}

            EnableMultiplayerServersForTitleRequest(const EnableMultiplayerServersForTitleRequest&) :
                PlayFabRequestCommon()
            {}

            ~EnableMultiplayerServersForTitleRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct EnableMultiplayerServersForTitleResponse : public PlayFabResultCommon
        {
            Boxed<TitleMultiplayerServerEnabledStatus> Status;

            EnableMultiplayerServersForTitleResponse() :
                PlayFabResultCommon(),
                Status()
            {}

            EnableMultiplayerServersForTitleResponse(const EnableMultiplayerServersForTitleResponse& src) :
                PlayFabResultCommon(),
                Status(src.Status)
            {}

            ~EnableMultiplayerServersForTitleResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["Status"], Status);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                return output;
            }
        };

        struct GetAssetUploadUrlRequest : public PlayFabRequestCommon
        {
            std::string FileName;

            GetAssetUploadUrlRequest() :
                PlayFabRequestCommon(),
                FileName()
            {}

            GetAssetUploadUrlRequest(const GetAssetUploadUrlRequest& src) :
                PlayFabRequestCommon(),
                FileName(src.FileName)
            {}

            ~GetAssetUploadUrlRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FileName"], FileName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                return output;
            }
        };

        struct GetAssetUploadUrlResponse : public PlayFabResultCommon
        {
            std::string AssetUploadUrl;
            std::string FileName;

            GetAssetUploadUrlResponse() :
                PlayFabResultCommon(),
                AssetUploadUrl(),
                FileName()
            {}

            GetAssetUploadUrlResponse(const GetAssetUploadUrlResponse& src) :
                PlayFabResultCommon(),
                AssetUploadUrl(src.AssetUploadUrl),
                FileName(src.FileName)
            {}

            ~GetAssetUploadUrlResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["AssetUploadUrl"], AssetUploadUrl);
                FromJsonUtilS(input["FileName"], FileName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AssetUploadUrl; ToJsonUtilS(AssetUploadUrl, each_AssetUploadUrl); output["AssetUploadUrl"] = each_AssetUploadUrl;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                return output;
            }
        };

        struct GetBuildRequest : public PlayFabRequestCommon
        {
            std::string BuildId;

            GetBuildRequest() :
                PlayFabRequestCommon(),
                BuildId()
            {}

            GetBuildRequest(const GetBuildRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId)
            {}

            ~GetBuildRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                return output;
            }
        };

        struct GetBuildResponse : public PlayFabResultCommon
        {
            std::string BuildId;
            std::string BuildName;
            std::string BuildStatus;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::string ContainerRunCommand;
            Boxed<time_t> CreationTime;
            Boxed<ContainerImageReference> CustomGameContainerImage;
            std::list<AssetReference> GameAssetReferences;
            std::list<GameCertificateReference> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            std::string StartMultiplayerServerCommand;
            Boxed<AzureVmSize> VmSize;

            GetBuildResponse() :
                PlayFabResultCommon(),
                BuildId(),
                BuildName(),
                BuildStatus(),
                pfContainerFlavor(),
                ContainerRunCommand(),
                CreationTime(),
                CustomGameContainerImage(),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(),
                Ports(),
                RegionConfigurations(),
                StartMultiplayerServerCommand(),
                VmSize()
            {}

            GetBuildResponse(const GetBuildResponse& src) :
                PlayFabResultCommon(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                BuildStatus(src.BuildStatus),
                pfContainerFlavor(src.pfContainerFlavor),
                ContainerRunCommand(src.ContainerRunCommand),
                CreationTime(src.CreationTime),
                CustomGameContainerImage(src.CustomGameContainerImage),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize)
            {}

            ~GetBuildResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilS(input["BuildStatus"], BuildStatus);
                FromJsonUtilE(input["pfContainerFlavor"], pfContainerFlavor);
                FromJsonUtilS(input["ContainerRunCommand"], ContainerRunCommand);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilO(input["CustomGameContainerImage"], CustomGameContainerImage);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilS(input["StartMultiplayerServerCommand"], StartMultiplayerServerCommand);
                FromJsonUtilE(input["VmSize"], VmSize);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_BuildStatus; ToJsonUtilS(BuildStatus, each_BuildStatus); output["BuildStatus"] = each_BuildStatus;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_ContainerRunCommand; ToJsonUtilS(ContainerRunCommand, each_ContainerRunCommand); output["ContainerRunCommand"] = each_ContainerRunCommand;
                Json::Value each_CreationTime; ToJsonUtilT(CreationTime, each_CreationTime); output["CreationTime"] = each_CreationTime;
                Json::Value each_CustomGameContainerImage; ToJsonUtilO(CustomGameContainerImage, each_CustomGameContainerImage); output["CustomGameContainerImage"] = each_CustomGameContainerImage;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_StartMultiplayerServerCommand; ToJsonUtilS(StartMultiplayerServerCommand, each_StartMultiplayerServerCommand); output["StartMultiplayerServerCommand"] = each_StartMultiplayerServerCommand;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                return output;
            }
        };

        struct GetContainerRegistryCredentialsRequest : public PlayFabRequestCommon
        {

            GetContainerRegistryCredentialsRequest() :
                PlayFabRequestCommon()
            {}

            GetContainerRegistryCredentialsRequest(const GetContainerRegistryCredentialsRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetContainerRegistryCredentialsRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct GetContainerRegistryCredentialsResponse : public PlayFabResultCommon
        {
            std::string DnsName;
            std::string Password;
            std::string Username;

            GetContainerRegistryCredentialsResponse() :
                PlayFabResultCommon(),
                DnsName(),
                Password(),
                Username()
            {}

            GetContainerRegistryCredentialsResponse(const GetContainerRegistryCredentialsResponse& src) :
                PlayFabResultCommon(),
                DnsName(src.DnsName),
                Password(src.Password),
                Username(src.Username)
            {}

            ~GetContainerRegistryCredentialsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DnsName"], DnsName);
                FromJsonUtilS(input["Password"], Password);
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DnsName; ToJsonUtilS(DnsName, each_DnsName); output["DnsName"] = each_DnsName;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
                return output;
            }
        };

        struct GetMatchmakingQueueRequest : public PlayFabRequestCommon
        {
            std::string QueueName;

            GetMatchmakingQueueRequest() :
                PlayFabRequestCommon(),
                QueueName()
            {}

            GetMatchmakingQueueRequest(const GetMatchmakingQueueRequest& src) :
                PlayFabRequestCommon(),
                QueueName(src.QueueName)
            {}

            ~GetMatchmakingQueueRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct MatchmakingQueueRule : public PlayFabBaseModel
        {
            std::string Name;
            Boxed<Uint32> SecondsUntilOptional;
            RuleType Type;

            MatchmakingQueueRule() :
                PlayFabBaseModel(),
                Name(),
                SecondsUntilOptional(),
                Type()
            {}

            MatchmakingQueueRule(const MatchmakingQueueRule& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                SecondsUntilOptional(src.SecondsUntilOptional),
                Type(src.Type)
            {}

            ~MatchmakingQueueRule() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilP(input["SecondsUntilOptional"], SecondsUntilOptional);
                FromJsonEnum(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_SecondsUntilOptional; ToJsonUtilP(SecondsUntilOptional, each_SecondsUntilOptional); output["SecondsUntilOptional"] = each_SecondsUntilOptional;
                Json::Value each_Type; ToJsonEnum(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct StatisticsVisibilityToPlayers : public PlayFabBaseModel
        {
            bool ShowNumberOfPlayersMatching;
            bool ShowTimeToMatch;

            StatisticsVisibilityToPlayers() :
                PlayFabBaseModel(),
                ShowNumberOfPlayersMatching(),
                ShowTimeToMatch()
            {}

            StatisticsVisibilityToPlayers(const StatisticsVisibilityToPlayers& src) :
                PlayFabBaseModel(),
                ShowNumberOfPlayersMatching(src.ShowNumberOfPlayersMatching),
                ShowTimeToMatch(src.ShowTimeToMatch)
            {}

            ~StatisticsVisibilityToPlayers() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ShowNumberOfPlayersMatching"], ShowNumberOfPlayersMatching);
                FromJsonUtilP(input["ShowTimeToMatch"], ShowTimeToMatch);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ShowNumberOfPlayersMatching; ToJsonUtilP(ShowNumberOfPlayersMatching, each_ShowNumberOfPlayersMatching); output["ShowNumberOfPlayersMatching"] = each_ShowNumberOfPlayersMatching;
                Json::Value each_ShowTimeToMatch; ToJsonUtilP(ShowTimeToMatch, each_ShowTimeToMatch); output["ShowTimeToMatch"] = each_ShowTimeToMatch;
                return output;
            }
        };

        struct MatchmakingQueueTeam : public PlayFabBaseModel
        {
            Uint32 MaxTeamSize;
            Uint32 MinTeamSize;
            std::string Name;

            MatchmakingQueueTeam() :
                PlayFabBaseModel(),
                MaxTeamSize(),
                MinTeamSize(),
                Name()
            {}

            MatchmakingQueueTeam(const MatchmakingQueueTeam& src) :
                PlayFabBaseModel(),
                MaxTeamSize(src.MaxTeamSize),
                MinTeamSize(src.MinTeamSize),
                Name(src.Name)
            {}

            ~MatchmakingQueueTeam() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["MaxTeamSize"], MaxTeamSize);
                FromJsonUtilP(input["MinTeamSize"], MinTeamSize);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MaxTeamSize; ToJsonUtilP(MaxTeamSize, each_MaxTeamSize); output["MaxTeamSize"] = each_MaxTeamSize;
                Json::Value each_MinTeamSize; ToJsonUtilP(MinTeamSize, each_MinTeamSize); output["MinTeamSize"] = each_MinTeamSize;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct MatchmakingQueueConfig : public PlayFabBaseModel
        {
            std::string BuildId;
            Uint32 MaxMatchSize;
            Uint32 MinMatchSize;
            std::string Name;
            std::list<MatchmakingQueueRule> Rules;
            bool ServerAllocationEnabled;
            Boxed<StatisticsVisibilityToPlayers> pfStatisticsVisibilityToPlayers;
            std::list<MatchmakingQueueTeam> Teams;

            MatchmakingQueueConfig() :
                PlayFabBaseModel(),
                BuildId(),
                MaxMatchSize(),
                MinMatchSize(),
                Name(),
                Rules(),
                ServerAllocationEnabled(),
                pfStatisticsVisibilityToPlayers(),
                Teams()
            {}

            MatchmakingQueueConfig(const MatchmakingQueueConfig& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                MaxMatchSize(src.MaxMatchSize),
                MinMatchSize(src.MinMatchSize),
                Name(src.Name),
                Rules(src.Rules),
                ServerAllocationEnabled(src.ServerAllocationEnabled),
                pfStatisticsVisibilityToPlayers(src.pfStatisticsVisibilityToPlayers),
                Teams(src.Teams)
            {}

            ~MatchmakingQueueConfig() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilP(input["MaxMatchSize"], MaxMatchSize);
                FromJsonUtilP(input["MinMatchSize"], MinMatchSize);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilO(input["Rules"], Rules);
                FromJsonUtilP(input["ServerAllocationEnabled"], ServerAllocationEnabled);
                FromJsonUtilO(input["pfStatisticsVisibilityToPlayers"], pfStatisticsVisibilityToPlayers);
                FromJsonUtilO(input["Teams"], Teams);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_MaxMatchSize; ToJsonUtilP(MaxMatchSize, each_MaxMatchSize); output["MaxMatchSize"] = each_MaxMatchSize;
                Json::Value each_MinMatchSize; ToJsonUtilP(MinMatchSize, each_MinMatchSize); output["MinMatchSize"] = each_MinMatchSize;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Rules; ToJsonUtilO(Rules, each_Rules); output["Rules"] = each_Rules;
                Json::Value each_ServerAllocationEnabled; ToJsonUtilP(ServerAllocationEnabled, each_ServerAllocationEnabled); output["ServerAllocationEnabled"] = each_ServerAllocationEnabled;
                Json::Value each_pfStatisticsVisibilityToPlayers; ToJsonUtilO(pfStatisticsVisibilityToPlayers, each_pfStatisticsVisibilityToPlayers); output["StatisticsVisibilityToPlayers"] = each_pfStatisticsVisibilityToPlayers;
                Json::Value each_Teams; ToJsonUtilO(Teams, each_Teams); output["Teams"] = each_Teams;
                return output;
            }
        };

        struct GetMatchmakingQueueResult : public PlayFabResultCommon
        {
            Boxed<MatchmakingQueueConfig> MatchmakingQueue;

            GetMatchmakingQueueResult() :
                PlayFabResultCommon(),
                MatchmakingQueue()
            {}

            GetMatchmakingQueueResult(const GetMatchmakingQueueResult& src) :
                PlayFabResultCommon(),
                MatchmakingQueue(src.MatchmakingQueue)
            {}

            ~GetMatchmakingQueueResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["MatchmakingQueue"], MatchmakingQueue);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MatchmakingQueue; ToJsonUtilO(MatchmakingQueue, each_MatchmakingQueue); output["MatchmakingQueue"] = each_MatchmakingQueue;
                return output;
            }
        };

        struct GetMatchmakingTicketRequest : public PlayFabRequestCommon
        {
            bool EscapeObject;
            std::string QueueName;
            std::string TicketId;

            GetMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                EscapeObject(),
                QueueName(),
                TicketId()
            {}

            GetMatchmakingTicketRequest(const GetMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                EscapeObject(src.EscapeObject),
                QueueName(src.QueueName),
                TicketId(src.TicketId)
            {}

            ~GetMatchmakingTicketRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["EscapeObject"], EscapeObject);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EscapeObject; ToJsonUtilP(EscapeObject, each_EscapeObject); output["EscapeObject"] = each_EscapeObject;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_TicketId; ToJsonUtilS(TicketId, each_TicketId); output["TicketId"] = each_TicketId;
                return output;
            }
        };

        struct GetMatchmakingTicketResult : public PlayFabResultCommon
        {
            Boxed<CancellationReason> pfCancellationReason;
            time_t Created;
            EntityKey Creator;
            Int32 GiveUpAfterSeconds;
            std::string MatchId;
            std::list<MatchmakingPlayer> Members;
            std::list<EntityKey> MembersToMatchWith;
            std::string QueueName;
            std::string Status;
            std::string TicketId;

            GetMatchmakingTicketResult() :
                PlayFabResultCommon(),
                pfCancellationReason(),
                Created(),
                Creator(),
                GiveUpAfterSeconds(),
                MatchId(),
                Members(),
                MembersToMatchWith(),
                QueueName(),
                Status(),
                TicketId()
            {}

            GetMatchmakingTicketResult(const GetMatchmakingTicketResult& src) :
                PlayFabResultCommon(),
                pfCancellationReason(src.pfCancellationReason),
                Created(src.Created),
                Creator(src.Creator),
                GiveUpAfterSeconds(src.GiveUpAfterSeconds),
                MatchId(src.MatchId),
                Members(src.Members),
                MembersToMatchWith(src.MembersToMatchWith),
                QueueName(src.QueueName),
                Status(src.Status),
                TicketId(src.TicketId)
            {}

            ~GetMatchmakingTicketResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["pfCancellationReason"], pfCancellationReason);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilO(input["Creator"], Creator);
                FromJsonUtilP(input["GiveUpAfterSeconds"], GiveUpAfterSeconds);
                FromJsonUtilS(input["MatchId"], MatchId);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilO(input["MembersToMatchWith"], MembersToMatchWith);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilS(input["Status"], Status);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfCancellationReason; ToJsonUtilE(pfCancellationReason, each_pfCancellationReason); output["CancellationReason"] = each_pfCancellationReason;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_Creator; ToJsonUtilO(Creator, each_Creator); output["Creator"] = each_Creator;
                Json::Value each_GiveUpAfterSeconds; ToJsonUtilP(GiveUpAfterSeconds, each_GiveUpAfterSeconds); output["GiveUpAfterSeconds"] = each_GiveUpAfterSeconds;
                Json::Value each_MatchId; ToJsonUtilS(MatchId, each_MatchId); output["MatchId"] = each_MatchId;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_MembersToMatchWith; ToJsonUtilO(MembersToMatchWith, each_MembersToMatchWith); output["MembersToMatchWith"] = each_MembersToMatchWith;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_Status; ToJsonUtilS(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_TicketId; ToJsonUtilS(TicketId, each_TicketId); output["TicketId"] = each_TicketId;
                return output;
            }
        };

        struct GetMatchRequest : public PlayFabRequestCommon
        {
            bool EscapeObject;
            std::string MatchId;
            std::string QueueName;
            bool ReturnMemberAttributes;

            GetMatchRequest() :
                PlayFabRequestCommon(),
                EscapeObject(),
                MatchId(),
                QueueName(),
                ReturnMemberAttributes()
            {}

            GetMatchRequest(const GetMatchRequest& src) :
                PlayFabRequestCommon(),
                EscapeObject(src.EscapeObject),
                MatchId(src.MatchId),
                QueueName(src.QueueName),
                ReturnMemberAttributes(src.ReturnMemberAttributes)
            {}

            ~GetMatchRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["EscapeObject"], EscapeObject);
                FromJsonUtilS(input["MatchId"], MatchId);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilP(input["ReturnMemberAttributes"], ReturnMemberAttributes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EscapeObject; ToJsonUtilP(EscapeObject, each_EscapeObject); output["EscapeObject"] = each_EscapeObject;
                Json::Value each_MatchId; ToJsonUtilS(MatchId, each_MatchId); output["MatchId"] = each_MatchId;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_ReturnMemberAttributes; ToJsonUtilP(ReturnMemberAttributes, each_ReturnMemberAttributes); output["ReturnMemberAttributes"] = each_ReturnMemberAttributes;
                return output;
            }
        };

        struct MatchmakingPlayerWithTeamAssignment : public PlayFabBaseModel
        {
            Boxed<MatchmakingPlayerAttributes> Attributes;
            EntityKey Entity;
            std::string TeamId;

            MatchmakingPlayerWithTeamAssignment() :
                PlayFabBaseModel(),
                Attributes(),
                Entity(),
                TeamId()
            {}

            MatchmakingPlayerWithTeamAssignment(const MatchmakingPlayerWithTeamAssignment& src) :
                PlayFabBaseModel(),
                Attributes(src.Attributes),
                Entity(src.Entity),
                TeamId(src.TeamId)
            {}

            ~MatchmakingPlayerWithTeamAssignment() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Attributes"], Attributes);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["TeamId"], TeamId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Attributes; ToJsonUtilO(Attributes, each_Attributes); output["Attributes"] = each_Attributes;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_TeamId; ToJsonUtilS(TeamId, each_TeamId); output["TeamId"] = each_TeamId;
                return output;
            }
        };

        struct ServerDetails : public PlayFabBaseModel
        {
            std::string IPV4Address;
            std::list<Port> Ports;

            ServerDetails() :
                PlayFabBaseModel(),
                IPV4Address(),
                Ports()
            {}

            ServerDetails(const ServerDetails& src) :
                PlayFabBaseModel(),
                IPV4Address(src.IPV4Address),
                Ports(src.Ports)
            {}

            ~ServerDetails() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilO(input["Ports"], Ports);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IPV4Address; ToJsonUtilS(IPV4Address, each_IPV4Address); output["IPV4Address"] = each_IPV4Address;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                return output;
            }
        };

        struct GetMatchResult : public PlayFabResultCommon
        {
            std::string MatchId;
            std::list<MatchmakingPlayerWithTeamAssignment> Members;
            std::list<std::string> RegionPreferences;
            Boxed<ServerDetails> pfServerDetails;

            GetMatchResult() :
                PlayFabResultCommon(),
                MatchId(),
                Members(),
                RegionPreferences(),
                pfServerDetails()
            {}

            GetMatchResult(const GetMatchResult& src) :
                PlayFabResultCommon(),
                MatchId(src.MatchId),
                Members(src.Members),
                RegionPreferences(src.RegionPreferences),
                pfServerDetails(src.pfServerDetails)
            {}

            ~GetMatchResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["MatchId"], MatchId);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["RegionPreferences"], RegionPreferences);
                FromJsonUtilO(input["pfServerDetails"], pfServerDetails);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MatchId; ToJsonUtilS(MatchId, each_MatchId); output["MatchId"] = each_MatchId;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_RegionPreferences; ToJsonUtilS(RegionPreferences, each_RegionPreferences); output["RegionPreferences"] = each_RegionPreferences;
                Json::Value each_pfServerDetails; ToJsonUtilO(pfServerDetails, each_pfServerDetails); output["ServerDetails"] = each_pfServerDetails;
                return output;
            }
        };

        struct GetMultiplayerServerDetailsRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            AzureRegion Region;
            std::string SessionId;

            GetMultiplayerServerDetailsRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                Region(),
                SessionId()
            {}

            GetMultiplayerServerDetailsRequest(const GetMultiplayerServerDetailsRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                Region(src.Region),
                SessionId(src.SessionId)
            {}

            ~GetMultiplayerServerDetailsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonEnum(input["Region"], Region);
                FromJsonUtilS(input["SessionId"], SessionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_Region; ToJsonEnum(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                return output;
            }
        };

        struct GetMultiplayerServerDetailsResponse : public PlayFabResultCommon
        {
            std::list<ConnectedPlayer> ConnectedPlayers;
            std::string FQDN;
            std::string IPV4Address;
            Boxed<time_t> LastStateTransitionTime;
            std::list<Port> Ports;
            Boxed<AzureRegion> Region;
            std::string ServerId;
            std::string SessionId;
            std::string State;
            std::string VmId;

            GetMultiplayerServerDetailsResponse() :
                PlayFabResultCommon(),
                ConnectedPlayers(),
                FQDN(),
                IPV4Address(),
                LastStateTransitionTime(),
                Ports(),
                Region(),
                ServerId(),
                SessionId(),
                State(),
                VmId()
            {}

            GetMultiplayerServerDetailsResponse(const GetMultiplayerServerDetailsResponse& src) :
                PlayFabResultCommon(),
                ConnectedPlayers(src.ConnectedPlayers),
                FQDN(src.FQDN),
                IPV4Address(src.IPV4Address),
                LastStateTransitionTime(src.LastStateTransitionTime),
                Ports(src.Ports),
                Region(src.Region),
                ServerId(src.ServerId),
                SessionId(src.SessionId),
                State(src.State),
                VmId(src.VmId)
            {}

            ~GetMultiplayerServerDetailsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["ConnectedPlayers"], ConnectedPlayers);
                FromJsonUtilS(input["FQDN"], FQDN);
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilT(input["LastStateTransitionTime"], LastStateTransitionTime);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilE(input["Region"], Region);
                FromJsonUtilS(input["ServerId"], ServerId);
                FromJsonUtilS(input["SessionId"], SessionId);
                FromJsonUtilS(input["State"], State);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectedPlayers; ToJsonUtilO(ConnectedPlayers, each_ConnectedPlayers); output["ConnectedPlayers"] = each_ConnectedPlayers;
                Json::Value each_FQDN; ToJsonUtilS(FQDN, each_FQDN); output["FQDN"] = each_FQDN;
                Json::Value each_IPV4Address; ToJsonUtilS(IPV4Address, each_IPV4Address); output["IPV4Address"] = each_IPV4Address;
                Json::Value each_LastStateTransitionTime; ToJsonUtilT(LastStateTransitionTime, each_LastStateTransitionTime); output["LastStateTransitionTime"] = each_LastStateTransitionTime;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_Region; ToJsonUtilE(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_ServerId; ToJsonUtilS(ServerId, each_ServerId); output["ServerId"] = each_ServerId;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                Json::Value each_State; ToJsonUtilS(State, each_State); output["State"] = each_State;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
                return output;
            }
        };

        struct GetQueueStatisticsRequest : public PlayFabRequestCommon
        {
            std::string QueueName;

            GetQueueStatisticsRequest() :
                PlayFabRequestCommon(),
                QueueName()
            {}

            GetQueueStatisticsRequest(const GetQueueStatisticsRequest& src) :
                PlayFabRequestCommon(),
                QueueName(src.QueueName)
            {}

            ~GetQueueStatisticsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct Statistics : public PlayFabBaseModel
        {
            double Average;
            double Percentile50;
            double Percentile90;
            double Percentile99;

            Statistics() :
                PlayFabBaseModel(),
                Average(),
                Percentile50(),
                Percentile90(),
                Percentile99()
            {}

            Statistics(const Statistics& src) :
                PlayFabBaseModel(),
                Average(src.Average),
                Percentile50(src.Percentile50),
                Percentile90(src.Percentile90),
                Percentile99(src.Percentile99)
            {}

            ~Statistics() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["Average"], Average);
                FromJsonUtilP(input["Percentile50"], Percentile50);
                FromJsonUtilP(input["Percentile90"], Percentile90);
                FromJsonUtilP(input["Percentile99"], Percentile99);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Average; ToJsonUtilP(Average, each_Average); output["Average"] = each_Average;
                Json::Value each_Percentile50; ToJsonUtilP(Percentile50, each_Percentile50); output["Percentile50"] = each_Percentile50;
                Json::Value each_Percentile90; ToJsonUtilP(Percentile90, each_Percentile90); output["Percentile90"] = each_Percentile90;
                Json::Value each_Percentile99; ToJsonUtilP(Percentile99, each_Percentile99); output["Percentile99"] = each_Percentile99;
                return output;
            }
        };

        struct GetQueueStatisticsResult : public PlayFabResultCommon
        {
            Boxed<Uint32> NumberOfPlayersMatching;
            Boxed<Statistics> TimeToMatchStatisticsInSeconds;

            GetQueueStatisticsResult() :
                PlayFabResultCommon(),
                NumberOfPlayersMatching(),
                TimeToMatchStatisticsInSeconds()
            {}

            GetQueueStatisticsResult(const GetQueueStatisticsResult& src) :
                PlayFabResultCommon(),
                NumberOfPlayersMatching(src.NumberOfPlayersMatching),
                TimeToMatchStatisticsInSeconds(src.TimeToMatchStatisticsInSeconds)
            {}

            ~GetQueueStatisticsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["NumberOfPlayersMatching"], NumberOfPlayersMatching);
                FromJsonUtilO(input["TimeToMatchStatisticsInSeconds"], TimeToMatchStatisticsInSeconds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_NumberOfPlayersMatching; ToJsonUtilP(NumberOfPlayersMatching, each_NumberOfPlayersMatching); output["NumberOfPlayersMatching"] = each_NumberOfPlayersMatching;
                Json::Value each_TimeToMatchStatisticsInSeconds; ToJsonUtilO(TimeToMatchStatisticsInSeconds, each_TimeToMatchStatisticsInSeconds); output["TimeToMatchStatisticsInSeconds"] = each_TimeToMatchStatisticsInSeconds;
                return output;
            }
        };

        struct GetRemoteLoginEndpointRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            AzureRegion Region;
            std::string VmId;

            GetRemoteLoginEndpointRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                Region(),
                VmId()
            {}

            GetRemoteLoginEndpointRequest(const GetRemoteLoginEndpointRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                Region(src.Region),
                VmId(src.VmId)
            {}

            ~GetRemoteLoginEndpointRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonEnum(input["Region"], Region);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_Region; ToJsonEnum(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
                return output;
            }
        };

        struct GetRemoteLoginEndpointResponse : public PlayFabResultCommon
        {
            std::string IPV4Address;
            Int32 Port;

            GetRemoteLoginEndpointResponse() :
                PlayFabResultCommon(),
                IPV4Address(),
                Port()
            {}

            GetRemoteLoginEndpointResponse(const GetRemoteLoginEndpointResponse& src) :
                PlayFabResultCommon(),
                IPV4Address(src.IPV4Address),
                Port(src.Port)
            {}

            ~GetRemoteLoginEndpointResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilP(input["Port"], Port);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IPV4Address; ToJsonUtilS(IPV4Address, each_IPV4Address); output["IPV4Address"] = each_IPV4Address;
                Json::Value each_Port; ToJsonUtilP(Port, each_Port); output["Port"] = each_Port;
                return output;
            }
        };

        struct GetTitleEnabledForMultiplayerServersStatusRequest : public PlayFabRequestCommon
        {

            GetTitleEnabledForMultiplayerServersStatusRequest() :
                PlayFabRequestCommon()
            {}

            GetTitleEnabledForMultiplayerServersStatusRequest(const GetTitleEnabledForMultiplayerServersStatusRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetTitleEnabledForMultiplayerServersStatusRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct GetTitleEnabledForMultiplayerServersStatusResponse : public PlayFabResultCommon
        {
            Boxed<TitleMultiplayerServerEnabledStatus> Status;

            GetTitleEnabledForMultiplayerServersStatusResponse() :
                PlayFabResultCommon(),
                Status()
            {}

            GetTitleEnabledForMultiplayerServersStatusResponse(const GetTitleEnabledForMultiplayerServersStatusResponse& src) :
                PlayFabResultCommon(),
                Status(src.Status)
            {}

            ~GetTitleEnabledForMultiplayerServersStatusResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["Status"], Status);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                return output;
            }
        };

        struct JoinMatchmakingTicketRequest : public PlayFabRequestCommon
        {
            MatchmakingPlayer Member;
            std::string QueueName;
            std::string TicketId;

            JoinMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                Member(),
                QueueName(),
                TicketId()
            {}

            JoinMatchmakingTicketRequest(const JoinMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                Member(src.Member),
                QueueName(src.QueueName),
                TicketId(src.TicketId)
            {}

            ~JoinMatchmakingTicketRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Member"], Member);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Member; ToJsonUtilO(Member, each_Member); output["Member"] = each_Member;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_TicketId; ToJsonUtilS(TicketId, each_TicketId); output["TicketId"] = each_TicketId;
                return output;
            }
        };

        struct JoinMatchmakingTicketResult : public PlayFabResultCommon
        {

            JoinMatchmakingTicketResult() :
                PlayFabResultCommon()
            {}

            JoinMatchmakingTicketResult(const JoinMatchmakingTicketResult&) :
                PlayFabResultCommon()
            {}

            ~JoinMatchmakingTicketResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct ListAssetSummariesRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListAssetSummariesRequest() :
                PlayFabRequestCommon(),
                PageSize(),
                SkipToken()
            {}

            ListAssetSummariesRequest(const ListAssetSummariesRequest& src) :
                PlayFabRequestCommon(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListAssetSummariesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListAssetSummariesResponse : public PlayFabResultCommon
        {
            std::list<AssetSummary> AssetSummaries;
            Int32 PageSize;
            std::string SkipToken;

            ListAssetSummariesResponse() :
                PlayFabResultCommon(),
                AssetSummaries(),
                PageSize(),
                SkipToken()
            {}

            ListAssetSummariesResponse(const ListAssetSummariesResponse& src) :
                PlayFabResultCommon(),
                AssetSummaries(src.AssetSummaries),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListAssetSummariesResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["AssetSummaries"], AssetSummaries);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AssetSummaries; ToJsonUtilO(AssetSummaries, each_AssetSummaries); output["AssetSummaries"] = each_AssetSummaries;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListBuildSummariesRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListBuildSummariesRequest() :
                PlayFabRequestCommon(),
                PageSize(),
                SkipToken()
            {}

            ListBuildSummariesRequest(const ListBuildSummariesRequest& src) :
                PlayFabRequestCommon(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListBuildSummariesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListBuildSummariesResponse : public PlayFabResultCommon
        {
            std::list<BuildSummary> BuildSummaries;
            Int32 PageSize;
            std::string SkipToken;

            ListBuildSummariesResponse() :
                PlayFabResultCommon(),
                BuildSummaries(),
                PageSize(),
                SkipToken()
            {}

            ListBuildSummariesResponse(const ListBuildSummariesResponse& src) :
                PlayFabResultCommon(),
                BuildSummaries(src.BuildSummaries),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListBuildSummariesResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["BuildSummaries"], BuildSummaries);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildSummaries; ToJsonUtilO(BuildSummaries, each_BuildSummaries); output["BuildSummaries"] = each_BuildSummaries;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListCertificateSummariesRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListCertificateSummariesRequest() :
                PlayFabRequestCommon(),
                PageSize(),
                SkipToken()
            {}

            ListCertificateSummariesRequest(const ListCertificateSummariesRequest& src) :
                PlayFabRequestCommon(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListCertificateSummariesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListCertificateSummariesResponse : public PlayFabResultCommon
        {
            std::list<CertificateSummary> CertificateSummaries;
            Int32 PageSize;
            std::string SkipToken;

            ListCertificateSummariesResponse() :
                PlayFabResultCommon(),
                CertificateSummaries(),
                PageSize(),
                SkipToken()
            {}

            ListCertificateSummariesResponse(const ListCertificateSummariesResponse& src) :
                PlayFabResultCommon(),
                CertificateSummaries(src.CertificateSummaries),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListCertificateSummariesResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["CertificateSummaries"], CertificateSummaries);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CertificateSummaries; ToJsonUtilO(CertificateSummaries, each_CertificateSummaries); output["CertificateSummaries"] = each_CertificateSummaries;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListContainerImagesRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListContainerImagesRequest() :
                PlayFabRequestCommon(),
                PageSize(),
                SkipToken()
            {}

            ListContainerImagesRequest(const ListContainerImagesRequest& src) :
                PlayFabRequestCommon(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListContainerImagesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListContainerImagesResponse : public PlayFabResultCommon
        {
            std::list<std::string> Images;
            Int32 PageSize;
            std::string SkipToken;

            ListContainerImagesResponse() :
                PlayFabResultCommon(),
                Images(),
                PageSize(),
                SkipToken()
            {}

            ListContainerImagesResponse(const ListContainerImagesResponse& src) :
                PlayFabResultCommon(),
                Images(src.Images),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListContainerImagesResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Images"], Images);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Images; ToJsonUtilS(Images, each_Images); output["Images"] = each_Images;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListContainerImageTagsRequest : public PlayFabRequestCommon
        {
            std::string ImageName;

            ListContainerImageTagsRequest() :
                PlayFabRequestCommon(),
                ImageName()
            {}

            ListContainerImageTagsRequest(const ListContainerImageTagsRequest& src) :
                PlayFabRequestCommon(),
                ImageName(src.ImageName)
            {}

            ~ListContainerImageTagsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["ImageName"], ImageName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ImageName; ToJsonUtilS(ImageName, each_ImageName); output["ImageName"] = each_ImageName;
                return output;
            }
        };

        struct ListContainerImageTagsResponse : public PlayFabResultCommon
        {
            std::list<std::string> Tags;

            ListContainerImageTagsResponse() :
                PlayFabResultCommon(),
                Tags()
            {}

            ListContainerImageTagsResponse(const ListContainerImageTagsResponse& src) :
                PlayFabResultCommon(),
                Tags(src.Tags)
            {}

            ~ListContainerImageTagsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                return output;
            }
        };

        struct ListMatchmakingQueuesRequest : public PlayFabRequestCommon
        {

            ListMatchmakingQueuesRequest() :
                PlayFabRequestCommon()
            {}

            ListMatchmakingQueuesRequest(const ListMatchmakingQueuesRequest&) :
                PlayFabRequestCommon()
            {}

            ~ListMatchmakingQueuesRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct ListMatchmakingQueuesResult : public PlayFabResultCommon
        {
            std::list<MatchmakingQueueConfig> MatchMakingQueues;

            ListMatchmakingQueuesResult() :
                PlayFabResultCommon(),
                MatchMakingQueues()
            {}

            ListMatchmakingQueuesResult(const ListMatchmakingQueuesResult& src) :
                PlayFabResultCommon(),
                MatchMakingQueues(src.MatchMakingQueues)
            {}

            ~ListMatchmakingQueuesResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["MatchMakingQueues"], MatchMakingQueues);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MatchMakingQueues; ToJsonUtilO(MatchMakingQueues, each_MatchMakingQueues); output["MatchMakingQueues"] = each_MatchMakingQueues;
                return output;
            }
        };

        struct ListMatchmakingTicketsForPlayerRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string QueueName;

            ListMatchmakingTicketsForPlayerRequest() :
                PlayFabRequestCommon(),
                Entity(),
                QueueName()
            {}

            ListMatchmakingTicketsForPlayerRequest(const ListMatchmakingTicketsForPlayerRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                QueueName(src.QueueName)
            {}

            ~ListMatchmakingTicketsForPlayerRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct ListMatchmakingTicketsForPlayerResult : public PlayFabResultCommon
        {
            std::list<std::string> TicketIds;

            ListMatchmakingTicketsForPlayerResult() :
                PlayFabResultCommon(),
                TicketIds()
            {}

            ListMatchmakingTicketsForPlayerResult(const ListMatchmakingTicketsForPlayerResult& src) :
                PlayFabResultCommon(),
                TicketIds(src.TicketIds)
            {}

            ~ListMatchmakingTicketsForPlayerResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["TicketIds"], TicketIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_TicketIds; ToJsonUtilS(TicketIds, each_TicketIds); output["TicketIds"] = each_TicketIds;
                return output;
            }
        };

        struct ListMultiplayerServersRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            Boxed<Int32> PageSize;
            AzureRegion Region;
            std::string SkipToken;

            ListMultiplayerServersRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                PageSize(),
                Region(),
                SkipToken()
            {}

            ListMultiplayerServersRequest(const ListMultiplayerServersRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                PageSize(src.PageSize),
                Region(src.Region),
                SkipToken(src.SkipToken)
            {}

            ~ListMultiplayerServersRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonEnum(input["Region"], Region);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_Region; ToJsonEnum(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct MultiplayerServerSummary : public PlayFabBaseModel
        {
            std::list<ConnectedPlayer> ConnectedPlayers;
            Boxed<time_t> LastStateTransitionTime;
            Boxed<AzureRegion> Region;
            std::string ServerId;
            std::string SessionId;
            std::string State;
            std::string VmId;

            MultiplayerServerSummary() :
                PlayFabBaseModel(),
                ConnectedPlayers(),
                LastStateTransitionTime(),
                Region(),
                ServerId(),
                SessionId(),
                State(),
                VmId()
            {}

            MultiplayerServerSummary(const MultiplayerServerSummary& src) :
                PlayFabBaseModel(),
                ConnectedPlayers(src.ConnectedPlayers),
                LastStateTransitionTime(src.LastStateTransitionTime),
                Region(src.Region),
                ServerId(src.ServerId),
                SessionId(src.SessionId),
                State(src.State),
                VmId(src.VmId)
            {}

            ~MultiplayerServerSummary() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["ConnectedPlayers"], ConnectedPlayers);
                FromJsonUtilT(input["LastStateTransitionTime"], LastStateTransitionTime);
                FromJsonUtilE(input["Region"], Region);
                FromJsonUtilS(input["ServerId"], ServerId);
                FromJsonUtilS(input["SessionId"], SessionId);
                FromJsonUtilS(input["State"], State);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectedPlayers; ToJsonUtilO(ConnectedPlayers, each_ConnectedPlayers); output["ConnectedPlayers"] = each_ConnectedPlayers;
                Json::Value each_LastStateTransitionTime; ToJsonUtilT(LastStateTransitionTime, each_LastStateTransitionTime); output["LastStateTransitionTime"] = each_LastStateTransitionTime;
                Json::Value each_Region; ToJsonUtilE(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_ServerId; ToJsonUtilS(ServerId, each_ServerId); output["ServerId"] = each_ServerId;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                Json::Value each_State; ToJsonUtilS(State, each_State); output["State"] = each_State;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
                return output;
            }
        };

        struct ListMultiplayerServersResponse : public PlayFabResultCommon
        {
            std::list<MultiplayerServerSummary> MultiplayerServerSummaries;
            Int32 PageSize;
            std::string SkipToken;

            ListMultiplayerServersResponse() :
                PlayFabResultCommon(),
                MultiplayerServerSummaries(),
                PageSize(),
                SkipToken()
            {}

            ListMultiplayerServersResponse(const ListMultiplayerServersResponse& src) :
                PlayFabResultCommon(),
                MultiplayerServerSummaries(src.MultiplayerServerSummaries),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListMultiplayerServersResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["MultiplayerServerSummaries"], MultiplayerServerSummaries);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MultiplayerServerSummaries; ToJsonUtilO(MultiplayerServerSummaries, each_MultiplayerServerSummaries); output["MultiplayerServerSummaries"] = each_MultiplayerServerSummaries;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListQosServersRequest : public PlayFabRequestCommon
        {

            ListQosServersRequest() :
                PlayFabRequestCommon()
            {}

            ListQosServersRequest(const ListQosServersRequest&) :
                PlayFabRequestCommon()
            {}

            ~ListQosServersRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct QosServer : public PlayFabBaseModel
        {
            Boxed<AzureRegion> Region;
            std::string ServerUrl;

            QosServer() :
                PlayFabBaseModel(),
                Region(),
                ServerUrl()
            {}

            QosServer(const QosServer& src) :
                PlayFabBaseModel(),
                Region(src.Region),
                ServerUrl(src.ServerUrl)
            {}

            ~QosServer() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilE(input["Region"], Region);
                FromJsonUtilS(input["ServerUrl"], ServerUrl);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Region; ToJsonUtilE(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_ServerUrl; ToJsonUtilS(ServerUrl, each_ServerUrl); output["ServerUrl"] = each_ServerUrl;
                return output;
            }
        };

        struct ListQosServersResponse : public PlayFabResultCommon
        {
            Int32 PageSize;
            std::list<QosServer> QosServers;
            std::string SkipToken;

            ListQosServersResponse() :
                PlayFabResultCommon(),
                PageSize(),
                QosServers(),
                SkipToken()
            {}

            ListQosServersResponse(const ListQosServersResponse& src) :
                PlayFabResultCommon(),
                PageSize(src.PageSize),
                QosServers(src.QosServers),
                SkipToken(src.SkipToken)
            {}

            ~ListQosServersResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilO(input["QosServers"], QosServers);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_QosServers; ToJsonUtilO(QosServers, each_QosServers); output["QosServers"] = each_QosServers;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListVirtualMachineSummariesRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            Boxed<Int32> PageSize;
            AzureRegion Region;
            std::string SkipToken;

            ListVirtualMachineSummariesRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                PageSize(),
                Region(),
                SkipToken()
            {}

            ListVirtualMachineSummariesRequest(const ListVirtualMachineSummariesRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                PageSize(src.PageSize),
                Region(src.Region),
                SkipToken(src.SkipToken)
            {}

            ~ListVirtualMachineSummariesRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonEnum(input["Region"], Region);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_Region; ToJsonEnum(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct VirtualMachineSummary : public PlayFabBaseModel
        {
            std::string HealthStatus;
            std::string State;
            std::string VmId;

            VirtualMachineSummary() :
                PlayFabBaseModel(),
                HealthStatus(),
                State(),
                VmId()
            {}

            VirtualMachineSummary(const VirtualMachineSummary& src) :
                PlayFabBaseModel(),
                HealthStatus(src.HealthStatus),
                State(src.State),
                VmId(src.VmId)
            {}

            ~VirtualMachineSummary() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["HealthStatus"], HealthStatus);
                FromJsonUtilS(input["State"], State);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_HealthStatus; ToJsonUtilS(HealthStatus, each_HealthStatus); output["HealthStatus"] = each_HealthStatus;
                Json::Value each_State; ToJsonUtilS(State, each_State); output["State"] = each_State;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
                return output;
            }
        };

        struct ListVirtualMachineSummariesResponse : public PlayFabResultCommon
        {
            Int32 PageSize;
            std::string SkipToken;
            std::list<VirtualMachineSummary> VirtualMachines;

            ListVirtualMachineSummariesResponse() :
                PlayFabResultCommon(),
                PageSize(),
                SkipToken(),
                VirtualMachines()
            {}

            ListVirtualMachineSummariesResponse(const ListVirtualMachineSummariesResponse& src) :
                PlayFabResultCommon(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken),
                VirtualMachines(src.VirtualMachines)
            {}

            ~ListVirtualMachineSummariesResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
                FromJsonUtilO(input["VirtualMachines"], VirtualMachines);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                Json::Value each_VirtualMachines; ToJsonUtilO(VirtualMachines, each_VirtualMachines); output["VirtualMachines"] = each_VirtualMachines;
                return output;
            }
        };

        struct RemoveMatchmakingQueueRequest : public PlayFabRequestCommon
        {
            std::string QueueName;

            RemoveMatchmakingQueueRequest() :
                PlayFabRequestCommon(),
                QueueName()
            {}

            RemoveMatchmakingQueueRequest(const RemoveMatchmakingQueueRequest& src) :
                PlayFabRequestCommon(),
                QueueName(src.QueueName)
            {}

            ~RemoveMatchmakingQueueRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct RemoveMatchmakingQueueResult : public PlayFabResultCommon
        {

            RemoveMatchmakingQueueResult() :
                PlayFabResultCommon()
            {}

            RemoveMatchmakingQueueResult(const RemoveMatchmakingQueueResult&) :
                PlayFabResultCommon()
            {}

            ~RemoveMatchmakingQueueResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct RequestMultiplayerServerRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::list<std::string> InitialPlayers;
            std::list<AzureRegion> PreferredRegions;
            std::string SessionCookie;
            std::string SessionId;

            RequestMultiplayerServerRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                InitialPlayers(),
                PreferredRegions(),
                SessionCookie(),
                SessionId()
            {}

            RequestMultiplayerServerRequest(const RequestMultiplayerServerRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                InitialPlayers(src.InitialPlayers),
                PreferredRegions(src.PreferredRegions),
                SessionCookie(src.SessionCookie),
                SessionId(src.SessionId)
            {}

            ~RequestMultiplayerServerRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["InitialPlayers"], InitialPlayers);
                FromJsonUtilE(input["PreferredRegions"], PreferredRegions);
                FromJsonUtilS(input["SessionCookie"], SessionCookie);
                FromJsonUtilS(input["SessionId"], SessionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_InitialPlayers; ToJsonUtilS(InitialPlayers, each_InitialPlayers); output["InitialPlayers"] = each_InitialPlayers;
                Json::Value each_PreferredRegions; ToJsonUtilE(PreferredRegions, each_PreferredRegions); output["PreferredRegions"] = each_PreferredRegions;
                Json::Value each_SessionCookie; ToJsonUtilS(SessionCookie, each_SessionCookie); output["SessionCookie"] = each_SessionCookie;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                return output;
            }
        };

        struct RequestMultiplayerServerResponse : public PlayFabResultCommon
        {
            std::list<ConnectedPlayer> ConnectedPlayers;
            std::string FQDN;
            std::string IPV4Address;
            Boxed<time_t> LastStateTransitionTime;
            std::list<Port> Ports;
            Boxed<AzureRegion> Region;
            std::string ServerId;
            std::string SessionId;
            std::string State;
            std::string VmId;

            RequestMultiplayerServerResponse() :
                PlayFabResultCommon(),
                ConnectedPlayers(),
                FQDN(),
                IPV4Address(),
                LastStateTransitionTime(),
                Ports(),
                Region(),
                ServerId(),
                SessionId(),
                State(),
                VmId()
            {}

            RequestMultiplayerServerResponse(const RequestMultiplayerServerResponse& src) :
                PlayFabResultCommon(),
                ConnectedPlayers(src.ConnectedPlayers),
                FQDN(src.FQDN),
                IPV4Address(src.IPV4Address),
                LastStateTransitionTime(src.LastStateTransitionTime),
                Ports(src.Ports),
                Region(src.Region),
                ServerId(src.ServerId),
                SessionId(src.SessionId),
                State(src.State),
                VmId(src.VmId)
            {}

            ~RequestMultiplayerServerResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["ConnectedPlayers"], ConnectedPlayers);
                FromJsonUtilS(input["FQDN"], FQDN);
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilT(input["LastStateTransitionTime"], LastStateTransitionTime);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilE(input["Region"], Region);
                FromJsonUtilS(input["ServerId"], ServerId);
                FromJsonUtilS(input["SessionId"], SessionId);
                FromJsonUtilS(input["State"], State);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectedPlayers; ToJsonUtilO(ConnectedPlayers, each_ConnectedPlayers); output["ConnectedPlayers"] = each_ConnectedPlayers;
                Json::Value each_FQDN; ToJsonUtilS(FQDN, each_FQDN); output["FQDN"] = each_FQDN;
                Json::Value each_IPV4Address; ToJsonUtilS(IPV4Address, each_IPV4Address); output["IPV4Address"] = each_IPV4Address;
                Json::Value each_LastStateTransitionTime; ToJsonUtilT(LastStateTransitionTime, each_LastStateTransitionTime); output["LastStateTransitionTime"] = each_LastStateTransitionTime;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_Region; ToJsonUtilE(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_ServerId; ToJsonUtilS(ServerId, each_ServerId); output["ServerId"] = each_ServerId;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                Json::Value each_State; ToJsonUtilS(State, each_State); output["State"] = each_State;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
                return output;
            }
        };

        struct RolloverContainerRegistryCredentialsRequest : public PlayFabRequestCommon
        {

            RolloverContainerRegistryCredentialsRequest() :
                PlayFabRequestCommon()
            {}

            RolloverContainerRegistryCredentialsRequest(const RolloverContainerRegistryCredentialsRequest&) :
                PlayFabRequestCommon()
            {}

            ~RolloverContainerRegistryCredentialsRequest() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct RolloverContainerRegistryCredentialsResponse : public PlayFabResultCommon
        {
            std::string DnsName;
            std::string Password;
            std::string Username;

            RolloverContainerRegistryCredentialsResponse() :
                PlayFabResultCommon(),
                DnsName(),
                Password(),
                Username()
            {}

            RolloverContainerRegistryCredentialsResponse(const RolloverContainerRegistryCredentialsResponse& src) :
                PlayFabResultCommon(),
                DnsName(src.DnsName),
                Password(src.Password),
                Username(src.Username)
            {}

            ~RolloverContainerRegistryCredentialsResponse() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["DnsName"], DnsName);
                FromJsonUtilS(input["Password"], Password);
                FromJsonUtilS(input["Username"], Username);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DnsName; ToJsonUtilS(DnsName, each_DnsName); output["DnsName"] = each_DnsName;
                Json::Value each_Password; ToJsonUtilS(Password, each_Password); output["Password"] = each_Password;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
                return output;
            }
        };

        struct SetMatchmakingQueueRequest : public PlayFabRequestCommon
        {
            Boxed<MatchmakingQueueConfig> MatchmakingQueue;

            SetMatchmakingQueueRequest() :
                PlayFabRequestCommon(),
                MatchmakingQueue()
            {}

            SetMatchmakingQueueRequest(const SetMatchmakingQueueRequest& src) :
                PlayFabRequestCommon(),
                MatchmakingQueue(src.MatchmakingQueue)
            {}

            ~SetMatchmakingQueueRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["MatchmakingQueue"], MatchmakingQueue);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MatchmakingQueue; ToJsonUtilO(MatchmakingQueue, each_MatchmakingQueue); output["MatchmakingQueue"] = each_MatchmakingQueue;
                return output;
            }
        };

        struct SetMatchmakingQueueResult : public PlayFabResultCommon
        {

            SetMatchmakingQueueResult() :
                PlayFabResultCommon()
            {}

            SetMatchmakingQueueResult(const SetMatchmakingQueueResult&) :
                PlayFabResultCommon()
            {}

            ~SetMatchmakingQueueResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct ShutdownMultiplayerServerRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            AzureRegion Region;
            std::string SessionId;

            ShutdownMultiplayerServerRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                Region(),
                SessionId()
            {}

            ShutdownMultiplayerServerRequest(const ShutdownMultiplayerServerRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                Region(src.Region),
                SessionId(src.SessionId)
            {}

            ~ShutdownMultiplayerServerRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonEnum(input["Region"], Region);
                FromJsonUtilS(input["SessionId"], SessionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_Region; ToJsonEnum(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                return output;
            }
        };

        struct UpdateBuildRegionsRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::list<BuildRegionParams> BuildRegions;

            UpdateBuildRegionsRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                BuildRegions()
            {}

            UpdateBuildRegionsRequest(const UpdateBuildRegionsRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                BuildRegions(src.BuildRegions)
            {}

            ~UpdateBuildRegionsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilO(input["BuildRegions"], BuildRegions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildRegions; ToJsonUtilO(BuildRegions, each_BuildRegions); output["BuildRegions"] = each_BuildRegions;
                return output;
            }
        };

        struct UploadCertificateRequest : public PlayFabRequestCommon
        {
            Certificate GameCertificate;

            UploadCertificateRequest() :
                PlayFabRequestCommon(),
                GameCertificate()
            {}

            UploadCertificateRequest(const UploadCertificateRequest& src) :
                PlayFabRequestCommon(),
                GameCertificate(src.GameCertificate)
            {}

            ~UploadCertificateRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["GameCertificate"], GameCertificate);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GameCertificate; ToJsonUtilO(GameCertificate, each_GameCertificate); output["GameCertificate"] = each_GameCertificate;
                return output;
            }
        };

    }
}

#endif
