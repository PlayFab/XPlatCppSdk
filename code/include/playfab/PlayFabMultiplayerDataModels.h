#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace MultiplayerModels
    {
        // Multiplayer Enums
        enum class AzureRegion
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
            AzureRegionChinaNorth2,
            AzureRegionSouthAfricaNorth
        };

        inline void ToJsonEnum(const AzureRegion input, Json::Value& output)
        {
            if (input == AzureRegion::AzureRegionAustraliaEast)
            {
                output = Json::Value("AustraliaEast");
                return;
            }
            if (input == AzureRegion::AzureRegionAustraliaSoutheast)
            {
                output = Json::Value("AustraliaSoutheast");
                return;
            }
            if (input == AzureRegion::AzureRegionBrazilSouth)
            {
                output = Json::Value("BrazilSouth");
                return;
            }
            if (input == AzureRegion::AzureRegionCentralUs)
            {
                output = Json::Value("CentralUs");
                return;
            }
            if (input == AzureRegion::AzureRegionEastAsia)
            {
                output = Json::Value("EastAsia");
                return;
            }
            if (input == AzureRegion::AzureRegionEastUs)
            {
                output = Json::Value("EastUs");
                return;
            }
            if (input == AzureRegion::AzureRegionEastUs2)
            {
                output = Json::Value("EastUs2");
                return;
            }
            if (input == AzureRegion::AzureRegionJapanEast)
            {
                output = Json::Value("JapanEast");
                return;
            }
            if (input == AzureRegion::AzureRegionJapanWest)
            {
                output = Json::Value("JapanWest");
                return;
            }
            if (input == AzureRegion::AzureRegionNorthCentralUs)
            {
                output = Json::Value("NorthCentralUs");
                return;
            }
            if (input == AzureRegion::AzureRegionNorthEurope)
            {
                output = Json::Value("NorthEurope");
                return;
            }
            if (input == AzureRegion::AzureRegionSouthCentralUs)
            {
                output = Json::Value("SouthCentralUs");
                return;
            }
            if (input == AzureRegion::AzureRegionSoutheastAsia)
            {
                output = Json::Value("SoutheastAsia");
                return;
            }
            if (input == AzureRegion::AzureRegionWestEurope)
            {
                output = Json::Value("WestEurope");
                return;
            }
            if (input == AzureRegion::AzureRegionWestUs)
            {
                output = Json::Value("WestUs");
                return;
            }
            if (input == AzureRegion::AzureRegionChinaEast2)
            {
                output = Json::Value("ChinaEast2");
                return;
            }
            if (input == AzureRegion::AzureRegionChinaNorth2)
            {
                output = Json::Value("ChinaNorth2");
                return;
            }
            if (input == AzureRegion::AzureRegionSouthAfricaNorth)
            {
                output = Json::Value("SouthAfricaNorth");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, AzureRegion& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "AustraliaEast")
            {
                output = AzureRegion::AzureRegionAustraliaEast;
                return;
            }
            if (inputStr == "AustraliaSoutheast")
            {
                output = AzureRegion::AzureRegionAustraliaSoutheast;
                return;
            }
            if (inputStr == "BrazilSouth")
            {
                output = AzureRegion::AzureRegionBrazilSouth;
                return;
            }
            if (inputStr == "CentralUs")
            {
                output = AzureRegion::AzureRegionCentralUs;
                return;
            }
            if (inputStr == "EastAsia")
            {
                output = AzureRegion::AzureRegionEastAsia;
                return;
            }
            if (inputStr == "EastUs")
            {
                output = AzureRegion::AzureRegionEastUs;
                return;
            }
            if (inputStr == "EastUs2")
            {
                output = AzureRegion::AzureRegionEastUs2;
                return;
            }
            if (inputStr == "JapanEast")
            {
                output = AzureRegion::AzureRegionJapanEast;
                return;
            }
            if (inputStr == "JapanWest")
            {
                output = AzureRegion::AzureRegionJapanWest;
                return;
            }
            if (inputStr == "NorthCentralUs")
            {
                output = AzureRegion::AzureRegionNorthCentralUs;
                return;
            }
            if (inputStr == "NorthEurope")
            {
                output = AzureRegion::AzureRegionNorthEurope;
                return;
            }
            if (inputStr == "SouthCentralUs")
            {
                output = AzureRegion::AzureRegionSouthCentralUs;
                return;
            }
            if (inputStr == "SoutheastAsia")
            {
                output = AzureRegion::AzureRegionSoutheastAsia;
                return;
            }
            if (inputStr == "WestEurope")
            {
                output = AzureRegion::AzureRegionWestEurope;
                return;
            }
            if (inputStr == "WestUs")
            {
                output = AzureRegion::AzureRegionWestUs;
                return;
            }
            if (inputStr == "ChinaEast2")
            {
                output = AzureRegion::AzureRegionChinaEast2;
                return;
            }
            if (inputStr == "ChinaNorth2")
            {
                output = AzureRegion::AzureRegionChinaNorth2;
                return;
            }
            if (inputStr == "SouthAfricaNorth")
            {
                output = AzureRegion::AzureRegionSouthAfricaNorth;
                return;
            }
        }

        enum class AzureVmFamily
        {
            AzureVmFamilyA,
            AzureVmFamilyAv2,
            AzureVmFamilyDv2,
            AzureVmFamilyF,
            AzureVmFamilyFsv2
        };

        inline void ToJsonEnum(const AzureVmFamily input, Json::Value& output)
        {
            if (input == AzureVmFamily::AzureVmFamilyA)
            {
                output = Json::Value("A");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyAv2)
            {
                output = Json::Value("Av2");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyDv2)
            {
                output = Json::Value("Dv2");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyF)
            {
                output = Json::Value("F");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyFsv2)
            {
                output = Json::Value("Fsv2");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, AzureVmFamily& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "A")
            {
                output = AzureVmFamily::AzureVmFamilyA;
                return;
            }
            if (inputStr == "Av2")
            {
                output = AzureVmFamily::AzureVmFamilyAv2;
                return;
            }
            if (inputStr == "Dv2")
            {
                output = AzureVmFamily::AzureVmFamilyDv2;
                return;
            }
            if (inputStr == "F")
            {
                output = AzureVmFamily::AzureVmFamilyF;
                return;
            }
            if (inputStr == "Fsv2")
            {
                output = AzureVmFamily::AzureVmFamilyFsv2;
                return;
            }
        }

        enum class AzureVmSize
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
            if (input == AzureVmSize::AzureVmSizeStandard_D1_v2)
            {
                output = Json::Value("Standard_D1_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D2_v2)
            {
                output = Json::Value("Standard_D2_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D3_v2)
            {
                output = Json::Value("Standard_D3_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4_v2)
            {
                output = Json::Value("Standard_D4_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D5_v2)
            {
                output = Json::Value("Standard_D5_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_A1_v2)
            {
                output = Json::Value("Standard_A1_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_A2_v2)
            {
                output = Json::Value("Standard_A2_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_A4_v2)
            {
                output = Json::Value("Standard_A4_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_A8_v2)
            {
                output = Json::Value("Standard_A8_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_F1)
            {
                output = Json::Value("Standard_F1");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_F2)
            {
                output = Json::Value("Standard_F2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_F4)
            {
                output = Json::Value("Standard_F4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_F8)
            {
                output = Json::Value("Standard_F8");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_F16)
            {
                output = Json::Value("Standard_F16");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_F2s_v2)
            {
                output = Json::Value("Standard_F2s_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_F4s_v2)
            {
                output = Json::Value("Standard_F4s_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_F8s_v2)
            {
                output = Json::Value("Standard_F8s_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_F16s_v2)
            {
                output = Json::Value("Standard_F16s_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_A1)
            {
                output = Json::Value("Standard_A1");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_A2)
            {
                output = Json::Value("Standard_A2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_A3)
            {
                output = Json::Value("Standard_A3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_A4)
            {
                output = Json::Value("Standard_A4");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, AzureVmSize& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Standard_D1_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_D1_v2;
                return;
            }
            if (inputStr == "Standard_D2_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2_v2;
                return;
            }
            if (inputStr == "Standard_D3_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_D3_v2;
                return;
            }
            if (inputStr == "Standard_D4_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4_v2;
                return;
            }
            if (inputStr == "Standard_D5_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_D5_v2;
                return;
            }
            if (inputStr == "Standard_A1_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_A1_v2;
                return;
            }
            if (inputStr == "Standard_A2_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_A2_v2;
                return;
            }
            if (inputStr == "Standard_A4_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_A4_v2;
                return;
            }
            if (inputStr == "Standard_A8_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_A8_v2;
                return;
            }
            if (inputStr == "Standard_F1")
            {
                output = AzureVmSize::AzureVmSizeStandard_F1;
                return;
            }
            if (inputStr == "Standard_F2")
            {
                output = AzureVmSize::AzureVmSizeStandard_F2;
                return;
            }
            if (inputStr == "Standard_F4")
            {
                output = AzureVmSize::AzureVmSizeStandard_F4;
                return;
            }
            if (inputStr == "Standard_F8")
            {
                output = AzureVmSize::AzureVmSizeStandard_F8;
                return;
            }
            if (inputStr == "Standard_F16")
            {
                output = AzureVmSize::AzureVmSizeStandard_F16;
                return;
            }
            if (inputStr == "Standard_F2s_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_F2s_v2;
                return;
            }
            if (inputStr == "Standard_F4s_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_F4s_v2;
                return;
            }
            if (inputStr == "Standard_F8s_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_F8s_v2;
                return;
            }
            if (inputStr == "Standard_F16s_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_F16s_v2;
                return;
            }
            if (inputStr == "Standard_A1")
            {
                output = AzureVmSize::AzureVmSizeStandard_A1;
                return;
            }
            if (inputStr == "Standard_A2")
            {
                output = AzureVmSize::AzureVmSizeStandard_A2;
                return;
            }
            if (inputStr == "Standard_A3")
            {
                output = AzureVmSize::AzureVmSizeStandard_A3;
                return;
            }
            if (inputStr == "Standard_A4")
            {
                output = AzureVmSize::AzureVmSizeStandard_A4;
                return;
            }
        }

        enum class CancellationReason
        {
            CancellationReasonRequested,
            CancellationReasonInternal,
            CancellationReasonTimeout
        };

        inline void ToJsonEnum(const CancellationReason input, Json::Value& output)
        {
            if (input == CancellationReason::CancellationReasonRequested)
            {
                output = Json::Value("Requested");
                return;
            }
            if (input == CancellationReason::CancellationReasonInternal)
            {
                output = Json::Value("Internal");
                return;
            }
            if (input == CancellationReason::CancellationReasonTimeout)
            {
                output = Json::Value("Timeout");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, CancellationReason& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Requested")
            {
                output = CancellationReason::CancellationReasonRequested;
                return;
            }
            if (inputStr == "Internal")
            {
                output = CancellationReason::CancellationReasonInternal;
                return;
            }
            if (inputStr == "Timeout")
            {
                output = CancellationReason::CancellationReasonTimeout;
                return;
            }
        }

        enum class ContainerFlavor
        {
            ContainerFlavorManagedWindowsServerCore,
            ContainerFlavorCustomLinux,
            ContainerFlavorManagedWindowsServerCorePreview
        };

        inline void ToJsonEnum(const ContainerFlavor input, Json::Value& output)
        {
            if (input == ContainerFlavor::ContainerFlavorManagedWindowsServerCore)
            {
                output = Json::Value("ManagedWindowsServerCore");
                return;
            }
            if (input == ContainerFlavor::ContainerFlavorCustomLinux)
            {
                output = Json::Value("CustomLinux");
                return;
            }
            if (input == ContainerFlavor::ContainerFlavorManagedWindowsServerCorePreview)
            {
                output = Json::Value("ManagedWindowsServerCorePreview");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, ContainerFlavor& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "ManagedWindowsServerCore")
            {
                output = ContainerFlavor::ContainerFlavorManagedWindowsServerCore;
                return;
            }
            if (inputStr == "CustomLinux")
            {
                output = ContainerFlavor::ContainerFlavorCustomLinux;
                return;
            }
            if (inputStr == "ManagedWindowsServerCorePreview")
            {
                output = ContainerFlavor::ContainerFlavorManagedWindowsServerCorePreview;
                return;
            }
        }

        enum class ProtocolType
        {
            ProtocolTypeTCP,
            ProtocolTypeUDP
        };

        inline void ToJsonEnum(const ProtocolType input, Json::Value& output)
        {
            if (input == ProtocolType::ProtocolTypeTCP)
            {
                output = Json::Value("TCP");
                return;
            }
            if (input == ProtocolType::ProtocolTypeUDP)
            {
                output = Json::Value("UDP");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, ProtocolType& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "TCP")
            {
                output = ProtocolType::ProtocolTypeTCP;
                return;
            }
            if (inputStr == "UDP")
            {
                output = ProtocolType::ProtocolTypeUDP;
                return;
            }
        }

        enum class TitleMultiplayerServerEnabledStatus
        {
            TitleMultiplayerServerEnabledStatusInitializing,
            TitleMultiplayerServerEnabledStatusEnabled,
            TitleMultiplayerServerEnabledStatusDisabled
        };

        inline void ToJsonEnum(const TitleMultiplayerServerEnabledStatus input, Json::Value& output)
        {
            if (input == TitleMultiplayerServerEnabledStatus::TitleMultiplayerServerEnabledStatusInitializing)
            {
                output = Json::Value("Initializing");
                return;
            }
            if (input == TitleMultiplayerServerEnabledStatus::TitleMultiplayerServerEnabledStatusEnabled)
            {
                output = Json::Value("Enabled");
                return;
            }
            if (input == TitleMultiplayerServerEnabledStatus::TitleMultiplayerServerEnabledStatusDisabled)
            {
                output = Json::Value("Disabled");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, TitleMultiplayerServerEnabledStatus& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Initializing")
            {
                output = TitleMultiplayerServerEnabledStatus::TitleMultiplayerServerEnabledStatusInitializing;
                return;
            }
            if (inputStr == "Enabled")
            {
                output = TitleMultiplayerServerEnabledStatus::TitleMultiplayerServerEnabledStatusEnabled;
                return;
            }
            if (inputStr == "Disabled")
            {
                output = TitleMultiplayerServerEnabledStatus::TitleMultiplayerServerEnabledStatusDisabled;
                return;
            }
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

        struct BuildSelectionCriterion : public PlayFabBaseModel
        {
            std::map<std::string, Uint32> BuildWeightDistribution;

            BuildSelectionCriterion() :
                PlayFabBaseModel(),
                BuildWeightDistribution()
            {}

            BuildSelectionCriterion(const BuildSelectionCriterion& src) :
                PlayFabBaseModel(),
                BuildWeightDistribution(src.BuildWeightDistribution)
            {}

            ~BuildSelectionCriterion() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["BuildWeightDistribution"], BuildWeightDistribution);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildWeightDistribution; ToJsonUtilP(BuildWeightDistribution, each_BuildWeightDistribution); output["BuildWeightDistribution"] = each_BuildWeightDistribution;
                return output;
            }
        };

        struct BuildAliasDetailsResponse : public PlayFabResultCommon
        {
            std::string AliasId;
            std::string AliasName;
            std::list<BuildSelectionCriterion> BuildSelectionCriteria;
            Int32 PageSize;
            std::string SkipToken;

            BuildAliasDetailsResponse() :
                PlayFabResultCommon(),
                AliasId(),
                AliasName(),
                BuildSelectionCriteria(),
                PageSize(),
                SkipToken()
            {}

            BuildAliasDetailsResponse(const BuildAliasDetailsResponse& src) :
                PlayFabResultCommon(),
                AliasId(src.AliasId),
                AliasName(src.AliasName),
                BuildSelectionCriteria(src.BuildSelectionCriteria),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~BuildAliasDetailsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasId"], AliasId);
                FromJsonUtilS(input["AliasName"], AliasName);
                FromJsonUtilO(input["BuildSelectionCriteria"], BuildSelectionCriteria);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasId; ToJsonUtilS(AliasId, each_AliasId); output["AliasId"] = each_AliasId;
                Json::Value each_AliasName; ToJsonUtilS(AliasName, each_AliasName); output["AliasName"] = each_AliasName;
                Json::Value each_BuildSelectionCriteria; ToJsonUtilO(BuildSelectionCriteria, each_BuildSelectionCriteria); output["BuildSelectionCriteria"] = each_BuildSelectionCriteria;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct BuildAliasParams : public PlayFabBaseModel
        {
            std::string AliasId;

            BuildAliasParams() :
                PlayFabBaseModel(),
                AliasId()
            {}

            BuildAliasParams(const BuildAliasParams& src) :
                PlayFabBaseModel(),
                AliasId(src.AliasId)
            {}

            ~BuildAliasParams() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasId"], AliasId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasId; ToJsonUtilS(AliasId, each_AliasId); output["AliasId"] = each_AliasId;
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

            void FromJson(const Json::Value& input) override
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

        struct DynamicStandbyThreshold : public PlayFabBaseModel
        {
            double Multiplier;
            double TriggerThresholdPercentage;

            DynamicStandbyThreshold() :
                PlayFabBaseModel(),
                Multiplier(),
                TriggerThresholdPercentage()
            {}

            DynamicStandbyThreshold(const DynamicStandbyThreshold& src) :
                PlayFabBaseModel(),
                Multiplier(src.Multiplier),
                TriggerThresholdPercentage(src.TriggerThresholdPercentage)
            {}

            ~DynamicStandbyThreshold() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Multiplier"], Multiplier);
                FromJsonUtilP(input["TriggerThresholdPercentage"], TriggerThresholdPercentage);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Multiplier; ToJsonUtilP(Multiplier, each_Multiplier); output["Multiplier"] = each_Multiplier;
                Json::Value each_TriggerThresholdPercentage; ToJsonUtilP(TriggerThresholdPercentage, each_TriggerThresholdPercentage); output["TriggerThresholdPercentage"] = each_TriggerThresholdPercentage;
                return output;
            }
        };

        struct DynamicStandbySettings : public PlayFabBaseModel
        {
            std::list<DynamicStandbyThreshold> DynamicFloorMultiplierThresholds;
            bool IsEnabled;
            Boxed<Int32> RampDownSeconds;

            DynamicStandbySettings() :
                PlayFabBaseModel(),
                DynamicFloorMultiplierThresholds(),
                IsEnabled(),
                RampDownSeconds()
            {}

            DynamicStandbySettings(const DynamicStandbySettings& src) :
                PlayFabBaseModel(),
                DynamicFloorMultiplierThresholds(src.DynamicFloorMultiplierThresholds),
                IsEnabled(src.IsEnabled),
                RampDownSeconds(src.RampDownSeconds)
            {}

            ~DynamicStandbySettings() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["DynamicFloorMultiplierThresholds"], DynamicFloorMultiplierThresholds);
                FromJsonUtilP(input["IsEnabled"], IsEnabled);
                FromJsonUtilP(input["RampDownSeconds"], RampDownSeconds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DynamicFloorMultiplierThresholds; ToJsonUtilO(DynamicFloorMultiplierThresholds, each_DynamicFloorMultiplierThresholds); output["DynamicFloorMultiplierThresholds"] = each_DynamicFloorMultiplierThresholds;
                Json::Value each_IsEnabled; ToJsonUtilP(IsEnabled, each_IsEnabled); output["IsEnabled"] = each_IsEnabled;
                Json::Value each_RampDownSeconds; ToJsonUtilP(RampDownSeconds, each_RampDownSeconds); output["RampDownSeconds"] = each_RampDownSeconds;
                return output;
            }
        };

        struct BuildRegion : public PlayFabBaseModel
        {
            Boxed<CurrentServerStats> pfCurrentServerStats;
            Boxed<DynamicStandbySettings> pfDynamicStandbySettings;
            Int32 MaxServers;
            std::string Region;
            Int32 StandbyServers;
            std::string Status;

            BuildRegion() :
                PlayFabBaseModel(),
                pfCurrentServerStats(),
                pfDynamicStandbySettings(),
                MaxServers(),
                Region(),
                StandbyServers(),
                Status()
            {}

            BuildRegion(const BuildRegion& src) :
                PlayFabBaseModel(),
                pfCurrentServerStats(src.pfCurrentServerStats),
                pfDynamicStandbySettings(src.pfDynamicStandbySettings),
                MaxServers(src.MaxServers),
                Region(src.Region),
                StandbyServers(src.StandbyServers),
                Status(src.Status)
            {}

            ~BuildRegion() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["CurrentServerStats"], pfCurrentServerStats);
                FromJsonUtilO(input["DynamicStandbySettings"], pfDynamicStandbySettings);
                FromJsonUtilP(input["MaxServers"], MaxServers);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilP(input["StandbyServers"], StandbyServers);
                FromJsonUtilS(input["Status"], Status);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfCurrentServerStats; ToJsonUtilO(pfCurrentServerStats, each_pfCurrentServerStats); output["CurrentServerStats"] = each_pfCurrentServerStats;
                Json::Value each_pfDynamicStandbySettings; ToJsonUtilO(pfDynamicStandbySettings, each_pfDynamicStandbySettings); output["DynamicStandbySettings"] = each_pfDynamicStandbySettings;
                Json::Value each_MaxServers; ToJsonUtilP(MaxServers, each_MaxServers); output["MaxServers"] = each_MaxServers;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_StandbyServers; ToJsonUtilP(StandbyServers, each_StandbyServers); output["StandbyServers"] = each_StandbyServers;
                Json::Value each_Status; ToJsonUtilS(Status, each_Status); output["Status"] = each_Status;
                return output;
            }
        };

        struct BuildRegionParams : public PlayFabBaseModel
        {
            Boxed<DynamicStandbySettings> pfDynamicStandbySettings;
            Int32 MaxServers;
            std::string Region;
            Int32 StandbyServers;

            BuildRegionParams() :
                PlayFabBaseModel(),
                pfDynamicStandbySettings(),
                MaxServers(),
                Region(),
                StandbyServers()
            {}

            BuildRegionParams(const BuildRegionParams& src) :
                PlayFabBaseModel(),
                pfDynamicStandbySettings(src.pfDynamicStandbySettings),
                MaxServers(src.MaxServers),
                Region(src.Region),
                StandbyServers(src.StandbyServers)
            {}

            ~BuildRegionParams() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["DynamicStandbySettings"], pfDynamicStandbySettings);
                FromJsonUtilP(input["MaxServers"], MaxServers);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilP(input["StandbyServers"], StandbyServers);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfDynamicStandbySettings; ToJsonUtilO(pfDynamicStandbySettings, each_pfDynamicStandbySettings); output["DynamicStandbySettings"] = each_pfDynamicStandbySettings;
                Json::Value each_MaxServers; ToJsonUtilP(MaxServers, each_MaxServers); output["MaxServers"] = each_MaxServers;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
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
            std::list<BuildRegion> RegionConfigurations;

            BuildSummary() :
                PlayFabBaseModel(),
                BuildId(),
                BuildName(),
                CreationTime(),
                Metadata(),
                RegionConfigurations()
            {}

            BuildSummary(const BuildSummary& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                CreationTime(src.CreationTime),
                Metadata(src.Metadata),
                RegionConfigurations(src.RegionConfigurations)
            {}

            ~BuildSummary() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_CreationTime; ToJsonUtilT(CreationTime, each_CreationTime); output["CreationTime"] = each_CreationTime;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value&) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value&) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

        struct CoreCapacity : public PlayFabBaseModel
        {
            Int32 Available;
            std::string Region;
            Int32 Total;
            Boxed<AzureVmFamily> VmFamily;

            CoreCapacity() :
                PlayFabBaseModel(),
                Available(),
                Region(),
                Total(),
                VmFamily()
            {}

            CoreCapacity(const CoreCapacity& src) :
                PlayFabBaseModel(),
                Available(src.Available),
                Region(src.Region),
                Total(src.Total),
                VmFamily(src.VmFamily)
            {}

            ~CoreCapacity() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Available"], Available);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilP(input["Total"], Total);
                FromJsonUtilE(input["VmFamily"], VmFamily);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Available; ToJsonUtilP(Available, each_Available); output["Available"] = each_Available;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_Total; ToJsonUtilP(Total, each_Total); output["Total"] = each_Total;
                Json::Value each_VmFamily; ToJsonUtilE(VmFamily, each_VmFamily); output["VmFamily"] = each_VmFamily;
                return output;
            }
        };

        struct CreateBuildAliasRequest : public PlayFabRequestCommon
        {
            std::string AliasName;
            std::list<BuildSelectionCriterion> BuildSelectionCriteria;

            CreateBuildAliasRequest() :
                PlayFabRequestCommon(),
                AliasName(),
                BuildSelectionCriteria()
            {}

            CreateBuildAliasRequest(const CreateBuildAliasRequest& src) :
                PlayFabRequestCommon(),
                AliasName(src.AliasName),
                BuildSelectionCriteria(src.BuildSelectionCriteria)
            {}

            ~CreateBuildAliasRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasName"], AliasName);
                FromJsonUtilO(input["BuildSelectionCriteria"], BuildSelectionCriteria);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasName; ToJsonUtilS(AliasName, each_AliasName); output["AliasName"] = each_AliasName;
                Json::Value each_BuildSelectionCriteria; ToJsonUtilO(BuildSelectionCriteria, each_BuildSelectionCriteria); output["BuildSelectionCriteria"] = each_BuildSelectionCriteria;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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
            Boxed<ContainerImageReference> pfContainerImageReference;
            std::string ContainerRunCommand;
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
                pfContainerImageReference(),
                ContainerRunCommand(),
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
                pfContainerImageReference(src.pfContainerImageReference),
                ContainerRunCommand(src.ContainerRunCommand),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                VmSize(src.VmSize)
            {}

            ~CreateBuildWithCustomContainerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
                FromJsonUtilO(input["ContainerImageReference"], pfContainerImageReference);
                FromJsonUtilS(input["ContainerRunCommand"], ContainerRunCommand);
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
                Json::Value each_pfContainerImageReference; ToJsonUtilO(pfContainerImageReference, each_pfContainerImageReference); output["ContainerImageReference"] = each_pfContainerImageReference;
                Json::Value each_ContainerRunCommand; ToJsonUtilS(ContainerRunCommand, each_ContainerRunCommand); output["ContainerRunCommand"] = each_ContainerRunCommand;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
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

        struct InstrumentationConfiguration : public PlayFabBaseModel
        {
            std::list<std::string> ProcessesToMonitor;

            InstrumentationConfiguration() :
                PlayFabBaseModel(),
                ProcessesToMonitor()
            {}

            InstrumentationConfiguration(const InstrumentationConfiguration& src) :
                PlayFabBaseModel(),
                ProcessesToMonitor(src.ProcessesToMonitor)
            {}

            ~InstrumentationConfiguration() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ProcessesToMonitor"], ProcessesToMonitor);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ProcessesToMonitor; ToJsonUtilS(ProcessesToMonitor, each_ProcessesToMonitor); output["ProcessesToMonitor"] = each_ProcessesToMonitor;
                return output;
            }
        };

        struct CreateBuildWithManagedContainerRequest : public PlayFabRequestCommon
        {
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::list<AssetReferenceParams> GameAssetReferences;
            std::list<GameCertificateReferenceParams> GameCertificateReferences;
            Boxed<InstrumentationConfiguration> pfInstrumentationConfiguration;
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
                pfInstrumentationConfiguration(),
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
                pfInstrumentationConfiguration(src.pfInstrumentationConfiguration),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize)
            {}

            ~CreateBuildWithManagedContainerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilO(input["InstrumentationConfiguration"], pfInstrumentationConfiguration);
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
                Json::Value each_pfInstrumentationConfiguration; ToJsonUtilO(pfInstrumentationConfiguration, each_pfInstrumentationConfiguration); output["InstrumentationConfiguration"] = each_pfInstrumentationConfiguration;
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
            Boxed<InstrumentationConfiguration> pfInstrumentationConfiguration;
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
                pfInstrumentationConfiguration(),
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
                pfInstrumentationConfiguration(src.pfInstrumentationConfiguration),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize)
            {}

            ~CreateBuildWithManagedContainerResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilO(input["InstrumentationConfiguration"], pfInstrumentationConfiguration);
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
                Json::Value each_pfInstrumentationConfiguration; ToJsonUtilO(pfInstrumentationConfiguration, each_pfInstrumentationConfiguration); output["InstrumentationConfiguration"] = each_pfInstrumentationConfiguration;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilT(input["ExpirationTime"], ExpirationTime);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["Username"], Username);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_ExpirationTime; ToJsonUtilT(ExpirationTime, each_ExpirationTime); output["ExpirationTime"] = each_ExpirationTime;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

        struct DeleteBuildAliasRequest : public PlayFabRequestCommon
        {
            std::string AliasId;

            DeleteBuildAliasRequest() :
                PlayFabRequestCommon(),
                AliasId()
            {}

            DeleteBuildAliasRequest(const DeleteBuildAliasRequest& src) :
                PlayFabRequestCommon(),
                AliasId(src.AliasId)
            {}

            ~DeleteBuildAliasRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasId"], AliasId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasId; ToJsonUtilS(AliasId, each_AliasId); output["AliasId"] = each_AliasId;
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

            void FromJson(const Json::Value& input) override
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

        struct DeleteRemoteUserRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["Username"], Username);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
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

            void FromJson(const Json::Value&) override
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

            void FromJson(const Json::Value&) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

        struct GetBuildAliasRequest : public PlayFabRequestCommon
        {
            std::string AliasId;

            GetBuildAliasRequest() :
                PlayFabRequestCommon(),
                AliasId()
            {}

            GetBuildAliasRequest(const GetBuildAliasRequest& src) :
                PlayFabRequestCommon(),
                AliasId(src.AliasId)
            {}

            ~GetBuildAliasRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasId"], AliasId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasId; ToJsonUtilS(AliasId, each_AliasId); output["AliasId"] = each_AliasId;
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

            void FromJson(const Json::Value& input) override
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
            Boxed<InstrumentationConfiguration> pfInstrumentationConfiguration;
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
                pfInstrumentationConfiguration(),
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
                pfInstrumentationConfiguration(src.pfInstrumentationConfiguration),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize)
            {}

            ~GetBuildResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilS(input["BuildStatus"], BuildStatus);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
                FromJsonUtilS(input["ContainerRunCommand"], ContainerRunCommand);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilO(input["CustomGameContainerImage"], CustomGameContainerImage);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilO(input["InstrumentationConfiguration"], pfInstrumentationConfiguration);
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
                Json::Value each_pfInstrumentationConfiguration; ToJsonUtilO(pfInstrumentationConfiguration, each_pfInstrumentationConfiguration); output["InstrumentationConfiguration"] = each_pfInstrumentationConfiguration;
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

            void FromJson(const Json::Value&) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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
            std::string CancellationReasonString;
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
                CancellationReasonString(),
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
                CancellationReasonString(src.CancellationReasonString),
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilE(input["CancellationReason"], pfCancellationReason);
                FromJsonUtilS(input["CancellationReasonString"], CancellationReasonString);
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
                Json::Value each_CancellationReasonString; ToJsonUtilS(CancellationReasonString, each_CancellationReasonString); output["CancellationReasonString"] = each_CancellationReasonString;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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
            std::string Region;

            ServerDetails() :
                PlayFabBaseModel(),
                IPV4Address(),
                Ports(),
                Region()
            {}

            ServerDetails(const ServerDetails& src) :
                PlayFabBaseModel(),
                IPV4Address(src.IPV4Address),
                Ports(src.Ports),
                Region(src.Region)
            {}

            ~ServerDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilS(input["Region"], Region);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IPV4Address; ToJsonUtilS(IPV4Address, each_IPV4Address); output["IPV4Address"] = each_IPV4Address;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["MatchId"], MatchId);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["RegionPreferences"], RegionPreferences);
                FromJsonUtilO(input["ServerDetails"], pfServerDetails);
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
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["SessionId"], SessionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
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
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["ConnectedPlayers"], ConnectedPlayers);
                FromJsonUtilS(input["FQDN"], FQDN);
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilT(input["LastStateTransitionTime"], LastStateTransitionTime);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilS(input["Region"], Region);
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
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_ServerId; ToJsonUtilS(ServerId, each_ServerId); output["ServerId"] = each_ServerId;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                Json::Value each_State; ToJsonUtilS(State, each_State); output["State"] = each_State;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
                return output;
            }
        };

        struct GetMultiplayerServerLogsRequest : public PlayFabRequestCommon
        {
            std::string Region;
            std::string ServerId;

            GetMultiplayerServerLogsRequest() :
                PlayFabRequestCommon(),
                Region(),
                ServerId()
            {}

            GetMultiplayerServerLogsRequest(const GetMultiplayerServerLogsRequest& src) :
                PlayFabRequestCommon(),
                Region(src.Region),
                ServerId(src.ServerId)
            {}

            ~GetMultiplayerServerLogsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["ServerId"], ServerId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_ServerId; ToJsonUtilS(ServerId, each_ServerId); output["ServerId"] = each_ServerId;
                return output;
            }
        };

        struct GetMultiplayerServerLogsResponse : public PlayFabResultCommon
        {
            std::string LogDownloadUrl;

            GetMultiplayerServerLogsResponse() :
                PlayFabResultCommon(),
                LogDownloadUrl()
            {}

            GetMultiplayerServerLogsResponse(const GetMultiplayerServerLogsResponse& src) :
                PlayFabResultCommon(),
                LogDownloadUrl(src.LogDownloadUrl)
            {}

            ~GetMultiplayerServerLogsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["LogDownloadUrl"], LogDownloadUrl);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LogDownloadUrl; ToJsonUtilS(LogDownloadUrl, each_LogDownloadUrl); output["LogDownloadUrl"] = each_LogDownloadUrl;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value&) override
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

            void FromJson(const Json::Value& input) override
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

        struct GetTitleMultiplayerServersQuotasRequest : public PlayFabRequestCommon
        {

            GetTitleMultiplayerServersQuotasRequest() :
                PlayFabRequestCommon()
            {}

            GetTitleMultiplayerServersQuotasRequest(const GetTitleMultiplayerServersQuotasRequest&) :
                PlayFabRequestCommon()
            {}

            ~GetTitleMultiplayerServersQuotasRequest() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct TitleMultiplayerServersQuotas : public PlayFabBaseModel
        {
            std::list<CoreCapacity> CoreCapacities;

            TitleMultiplayerServersQuotas() :
                PlayFabBaseModel(),
                CoreCapacities()
            {}

            TitleMultiplayerServersQuotas(const TitleMultiplayerServersQuotas& src) :
                PlayFabBaseModel(),
                CoreCapacities(src.CoreCapacities)
            {}

            ~TitleMultiplayerServersQuotas() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["CoreCapacities"], CoreCapacities);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CoreCapacities; ToJsonUtilO(CoreCapacities, each_CoreCapacities); output["CoreCapacities"] = each_CoreCapacities;
                return output;
            }
        };

        struct GetTitleMultiplayerServersQuotasResponse : public PlayFabResultCommon
        {
            Boxed<TitleMultiplayerServersQuotas> Quotas;

            GetTitleMultiplayerServersQuotasResponse() :
                PlayFabResultCommon(),
                Quotas()
            {}

            GetTitleMultiplayerServersQuotasResponse(const GetTitleMultiplayerServersQuotasResponse& src) :
                PlayFabResultCommon(),
                Quotas(src.Quotas)
            {}

            ~GetTitleMultiplayerServersQuotasResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Quotas"], Quotas);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Quotas; ToJsonUtilO(Quotas, each_Quotas); output["Quotas"] = each_Quotas;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value&) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

        struct ListBuildAliasesForTitleResponse : public PlayFabResultCommon
        {
            std::list<BuildAliasDetailsResponse> BuildAliases;

            ListBuildAliasesForTitleResponse() :
                PlayFabResultCommon(),
                BuildAliases()
            {}

            ListBuildAliasesForTitleResponse(const ListBuildAliasesForTitleResponse& src) :
                PlayFabResultCommon(),
                BuildAliases(src.BuildAliases)
            {}

            ~ListBuildAliasesForTitleResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["BuildAliases"], BuildAliases);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildAliases; ToJsonUtilO(BuildAliases, each_BuildAliases); output["BuildAliases"] = each_BuildAliases;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct MultiplayerServerSummary : public PlayFabBaseModel
        {
            std::list<ConnectedPlayer> ConnectedPlayers;
            Boxed<time_t> LastStateTransitionTime;
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["ConnectedPlayers"], ConnectedPlayers);
                FromJsonUtilT(input["LastStateTransitionTime"], LastStateTransitionTime);
                FromJsonUtilS(input["Region"], Region);
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
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
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

            void FromJson(const Json::Value& input) override
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

        struct ListPartyQosServersRequest : public PlayFabRequestCommon
        {
            std::string Version;

            ListPartyQosServersRequest() :
                PlayFabRequestCommon(),
                Version()
            {}

            ListPartyQosServersRequest(const ListPartyQosServersRequest& src) :
                PlayFabRequestCommon(),
                Version(src.Version)
            {}

            ~ListPartyQosServersRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Version; ToJsonUtilS(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct QosServer : public PlayFabBaseModel
        {
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["ServerUrl"], ServerUrl);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_ServerUrl; ToJsonUtilS(ServerUrl, each_ServerUrl); output["ServerUrl"] = each_ServerUrl;
                return output;
            }
        };

        struct ListPartyQosServersResponse : public PlayFabResultCommon
        {
            Int32 PageSize;
            std::list<QosServer> QosServers;
            std::string SkipToken;

            ListPartyQosServersResponse() :
                PlayFabResultCommon(),
                PageSize(),
                QosServers(),
                SkipToken()
            {}

            ListPartyQosServersResponse(const ListPartyQosServersResponse& src) :
                PlayFabResultCommon(),
                PageSize(src.PageSize),
                QosServers(src.QosServers),
                SkipToken(src.SkipToken)
            {}

            ~ListPartyQosServersResponse() = default;

            void FromJson(const Json::Value& input) override
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

        struct ListQosServersForTitleRequest : public PlayFabRequestCommon
        {

            ListQosServersForTitleRequest() :
                PlayFabRequestCommon()
            {}

            ListQosServersForTitleRequest(const ListQosServersForTitleRequest&) :
                PlayFabRequestCommon()
            {}

            ~ListQosServersForTitleRequest() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct ListQosServersForTitleResponse : public PlayFabResultCommon
        {
            Int32 PageSize;
            std::list<QosServer> QosServers;
            std::string SkipToken;

            ListQosServersForTitleResponse() :
                PlayFabResultCommon(),
                PageSize(),
                QosServers(),
                SkipToken()
            {}

            ListQosServersForTitleResponse(const ListQosServersForTitleResponse& src) :
                PlayFabResultCommon(),
                PageSize(src.PageSize),
                QosServers(src.QosServers),
                SkipToken(src.SkipToken)
            {}

            ~ListQosServersForTitleResponse() = default;

            void FromJson(const Json::Value& input) override
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

        struct ListQosServersRequest : public PlayFabRequestCommon
        {

            ListQosServersRequest() :
                PlayFabRequestCommon()
            {}

            ListQosServersRequest(const ListQosServersRequest&) :
                PlayFabRequestCommon()
            {}

            ~ListQosServersRequest() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            void FromJson(const Json::Value& input) override
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
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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

        struct MultiplayerEmptyRequest : public PlayFabRequestCommon
        {

            MultiplayerEmptyRequest() :
                PlayFabRequestCommon()
            {}

            MultiplayerEmptyRequest(const MultiplayerEmptyRequest&) :
                PlayFabRequestCommon()
            {}

            ~MultiplayerEmptyRequest() = default;

            void FromJson(const Json::Value&) override
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
            Boxed<BuildAliasParams> pfBuildAliasParams;
            std::string BuildId;
            std::list<std::string> InitialPlayers;
            std::list<std::string> PreferredRegions;
            std::string SessionCookie;
            std::string SessionId;

            RequestMultiplayerServerRequest() :
                PlayFabRequestCommon(),
                pfBuildAliasParams(),
                BuildId(),
                InitialPlayers(),
                PreferredRegions(),
                SessionCookie(),
                SessionId()
            {}

            RequestMultiplayerServerRequest(const RequestMultiplayerServerRequest& src) :
                PlayFabRequestCommon(),
                pfBuildAliasParams(src.pfBuildAliasParams),
                BuildId(src.BuildId),
                InitialPlayers(src.InitialPlayers),
                PreferredRegions(src.PreferredRegions),
                SessionCookie(src.SessionCookie),
                SessionId(src.SessionId)
            {}

            ~RequestMultiplayerServerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["BuildAliasParams"], pfBuildAliasParams);
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["InitialPlayers"], InitialPlayers);
                FromJsonUtilS(input["PreferredRegions"], PreferredRegions);
                FromJsonUtilS(input["SessionCookie"], SessionCookie);
                FromJsonUtilS(input["SessionId"], SessionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfBuildAliasParams; ToJsonUtilO(pfBuildAliasParams, each_pfBuildAliasParams); output["BuildAliasParams"] = each_pfBuildAliasParams;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_InitialPlayers; ToJsonUtilS(InitialPlayers, each_InitialPlayers); output["InitialPlayers"] = each_InitialPlayers;
                Json::Value each_PreferredRegions; ToJsonUtilS(PreferredRegions, each_PreferredRegions); output["PreferredRegions"] = each_PreferredRegions;
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
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["ConnectedPlayers"], ConnectedPlayers);
                FromJsonUtilS(input["FQDN"], FQDN);
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilT(input["LastStateTransitionTime"], LastStateTransitionTime);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilS(input["Region"], Region);
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
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
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

            void FromJson(const Json::Value&) override
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

            void FromJson(const Json::Value& input) override
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

        struct ShutdownMultiplayerServerRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::string Region;
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

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["SessionId"], SessionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                return output;
            }
        };

        struct UntagContainerImageRequest : public PlayFabRequestCommon
        {
            std::string ImageName;
            std::string Tag;

            UntagContainerImageRequest() :
                PlayFabRequestCommon(),
                ImageName(),
                Tag()
            {}

            UntagContainerImageRequest(const UntagContainerImageRequest& src) :
                PlayFabRequestCommon(),
                ImageName(src.ImageName),
                Tag(src.Tag)
            {}

            ~UntagContainerImageRequest() = default;

            void FromJson(const Json::Value& input) override
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

        struct UpdateBuildAliasRequest : public PlayFabRequestCommon
        {
            std::string AliasId;
            std::string AliasName;
            std::list<BuildSelectionCriterion> BuildSelectionCriteria;

            UpdateBuildAliasRequest() :
                PlayFabRequestCommon(),
                AliasId(),
                AliasName(),
                BuildSelectionCriteria()
            {}

            UpdateBuildAliasRequest(const UpdateBuildAliasRequest& src) :
                PlayFabRequestCommon(),
                AliasId(src.AliasId),
                AliasName(src.AliasName),
                BuildSelectionCriteria(src.BuildSelectionCriteria)
            {}

            ~UpdateBuildAliasRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasId"], AliasId);
                FromJsonUtilS(input["AliasName"], AliasName);
                FromJsonUtilO(input["BuildSelectionCriteria"], BuildSelectionCriteria);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasId; ToJsonUtilS(AliasId, each_AliasId); output["AliasId"] = each_AliasId;
                Json::Value each_AliasName; ToJsonUtilS(AliasName, each_AliasName); output["AliasName"] = each_AliasName;
                Json::Value each_BuildSelectionCriteria; ToJsonUtilO(BuildSelectionCriteria, each_BuildSelectionCriteria); output["BuildSelectionCriteria"] = each_BuildSelectionCriteria;
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

            void FromJson(const Json::Value& input) override
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

            void FromJson(const Json::Value& input) override
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
