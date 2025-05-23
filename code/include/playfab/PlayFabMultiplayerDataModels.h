#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace MultiplayerModels
    {
        // Multiplayer Enums
        enum class AccessPolicy
        {
            AccessPolicyPublic,
            AccessPolicyFriends,
            AccessPolicyPrivate
        };

        inline void ToJsonEnum(const AccessPolicy input, Json::Value& output)
        {
            if (input == AccessPolicy::AccessPolicyPublic)
            {
                output = Json::Value("Public");
                return;
            }
            if (input == AccessPolicy::AccessPolicyFriends)
            {
                output = Json::Value("Friends");
                return;
            }
            if (input == AccessPolicy::AccessPolicyPrivate)
            {
                output = Json::Value("Private");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, AccessPolicy& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Public")
            {
                output = AccessPolicy::AccessPolicyPublic;
                return;
            }
            if (inputStr == "Friends")
            {
                output = AccessPolicy::AccessPolicyFriends;
                return;
            }
            if (inputStr == "Private")
            {
                output = AccessPolicy::AccessPolicyPrivate;
                return;
            }
        }

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
            AzureRegionSouthAfricaNorth,
            AzureRegionWestCentralUs,
            AzureRegionKoreaCentral,
            AzureRegionFranceCentral,
            AzureRegionWestUs2,
            AzureRegionCentralIndia,
            AzureRegionUaeNorth,
            AzureRegionUkSouth,
            AzureRegionSwedenCentral,
            AzureRegionCanadaCentral,
            AzureRegionMexicoCentral
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
            if (input == AzureRegion::AzureRegionSouthAfricaNorth)
            {
                output = Json::Value("SouthAfricaNorth");
                return;
            }
            if (input == AzureRegion::AzureRegionWestCentralUs)
            {
                output = Json::Value("WestCentralUs");
                return;
            }
            if (input == AzureRegion::AzureRegionKoreaCentral)
            {
                output = Json::Value("KoreaCentral");
                return;
            }
            if (input == AzureRegion::AzureRegionFranceCentral)
            {
                output = Json::Value("FranceCentral");
                return;
            }
            if (input == AzureRegion::AzureRegionWestUs2)
            {
                output = Json::Value("WestUs2");
                return;
            }
            if (input == AzureRegion::AzureRegionCentralIndia)
            {
                output = Json::Value("CentralIndia");
                return;
            }
            if (input == AzureRegion::AzureRegionUaeNorth)
            {
                output = Json::Value("UaeNorth");
                return;
            }
            if (input == AzureRegion::AzureRegionUkSouth)
            {
                output = Json::Value("UkSouth");
                return;
            }
            if (input == AzureRegion::AzureRegionSwedenCentral)
            {
                output = Json::Value("SwedenCentral");
                return;
            }
            if (input == AzureRegion::AzureRegionCanadaCentral)
            {
                output = Json::Value("CanadaCentral");
                return;
            }
            if (input == AzureRegion::AzureRegionMexicoCentral)
            {
                output = Json::Value("MexicoCentral");
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
            if (inputStr == "SouthAfricaNorth")
            {
                output = AzureRegion::AzureRegionSouthAfricaNorth;
                return;
            }
            if (inputStr == "WestCentralUs")
            {
                output = AzureRegion::AzureRegionWestCentralUs;
                return;
            }
            if (inputStr == "KoreaCentral")
            {
                output = AzureRegion::AzureRegionKoreaCentral;
                return;
            }
            if (inputStr == "FranceCentral")
            {
                output = AzureRegion::AzureRegionFranceCentral;
                return;
            }
            if (inputStr == "WestUs2")
            {
                output = AzureRegion::AzureRegionWestUs2;
                return;
            }
            if (inputStr == "CentralIndia")
            {
                output = AzureRegion::AzureRegionCentralIndia;
                return;
            }
            if (inputStr == "UaeNorth")
            {
                output = AzureRegion::AzureRegionUaeNorth;
                return;
            }
            if (inputStr == "UkSouth")
            {
                output = AzureRegion::AzureRegionUkSouth;
                return;
            }
            if (inputStr == "SwedenCentral")
            {
                output = AzureRegion::AzureRegionSwedenCentral;
                return;
            }
            if (inputStr == "CanadaCentral")
            {
                output = AzureRegion::AzureRegionCanadaCentral;
                return;
            }
            if (inputStr == "MexicoCentral")
            {
                output = AzureRegion::AzureRegionMexicoCentral;
                return;
            }
        }

        enum class AzureVmFamily
        {
            AzureVmFamilyA,
            AzureVmFamilyAv2,
            AzureVmFamilyDv2,
            AzureVmFamilyDv3,
            AzureVmFamilyF,
            AzureVmFamilyFsv2,
            AzureVmFamilyDasv4,
            AzureVmFamilyDav4,
            AzureVmFamilyDadsv5,
            AzureVmFamilyEav4,
            AzureVmFamilyEasv4,
            AzureVmFamilyEv4,
            AzureVmFamilyEsv4,
            AzureVmFamilyDsv3,
            AzureVmFamilyDsv2,
            AzureVmFamilyNCasT4_v3,
            AzureVmFamilyDdv4,
            AzureVmFamilyDdsv4,
            AzureVmFamilyHBv3,
            AzureVmFamilyDdv5,
            AzureVmFamilyDdsv5
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
            if (input == AzureVmFamily::AzureVmFamilyDv3)
            {
                output = Json::Value("Dv3");
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
            if (input == AzureVmFamily::AzureVmFamilyDasv4)
            {
                output = Json::Value("Dasv4");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyDav4)
            {
                output = Json::Value("Dav4");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyDadsv5)
            {
                output = Json::Value("Dadsv5");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyEav4)
            {
                output = Json::Value("Eav4");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyEasv4)
            {
                output = Json::Value("Easv4");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyEv4)
            {
                output = Json::Value("Ev4");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyEsv4)
            {
                output = Json::Value("Esv4");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyDsv3)
            {
                output = Json::Value("Dsv3");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyDsv2)
            {
                output = Json::Value("Dsv2");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyNCasT4_v3)
            {
                output = Json::Value("NCasT4_v3");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyDdv4)
            {
                output = Json::Value("Ddv4");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyDdsv4)
            {
                output = Json::Value("Ddsv4");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyHBv3)
            {
                output = Json::Value("HBv3");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyDdv5)
            {
                output = Json::Value("Ddv5");
                return;
            }
            if (input == AzureVmFamily::AzureVmFamilyDdsv5)
            {
                output = Json::Value("Ddsv5");
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
            if (inputStr == "Dv3")
            {
                output = AzureVmFamily::AzureVmFamilyDv3;
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
            if (inputStr == "Dasv4")
            {
                output = AzureVmFamily::AzureVmFamilyDasv4;
                return;
            }
            if (inputStr == "Dav4")
            {
                output = AzureVmFamily::AzureVmFamilyDav4;
                return;
            }
            if (inputStr == "Dadsv5")
            {
                output = AzureVmFamily::AzureVmFamilyDadsv5;
                return;
            }
            if (inputStr == "Eav4")
            {
                output = AzureVmFamily::AzureVmFamilyEav4;
                return;
            }
            if (inputStr == "Easv4")
            {
                output = AzureVmFamily::AzureVmFamilyEasv4;
                return;
            }
            if (inputStr == "Ev4")
            {
                output = AzureVmFamily::AzureVmFamilyEv4;
                return;
            }
            if (inputStr == "Esv4")
            {
                output = AzureVmFamily::AzureVmFamilyEsv4;
                return;
            }
            if (inputStr == "Dsv3")
            {
                output = AzureVmFamily::AzureVmFamilyDsv3;
                return;
            }
            if (inputStr == "Dsv2")
            {
                output = AzureVmFamily::AzureVmFamilyDsv2;
                return;
            }
            if (inputStr == "NCasT4_v3")
            {
                output = AzureVmFamily::AzureVmFamilyNCasT4_v3;
                return;
            }
            if (inputStr == "Ddv4")
            {
                output = AzureVmFamily::AzureVmFamilyDdv4;
                return;
            }
            if (inputStr == "Ddsv4")
            {
                output = AzureVmFamily::AzureVmFamilyDdsv4;
                return;
            }
            if (inputStr == "HBv3")
            {
                output = AzureVmFamily::AzureVmFamilyHBv3;
                return;
            }
            if (inputStr == "Ddv5")
            {
                output = AzureVmFamily::AzureVmFamilyDdv5;
                return;
            }
            if (inputStr == "Ddsv5")
            {
                output = AzureVmFamily::AzureVmFamilyDdsv5;
                return;
            }
        }

        enum class AzureVmSize
        {
            AzureVmSizeStandard_A1,
            AzureVmSizeStandard_A2,
            AzureVmSizeStandard_A3,
            AzureVmSizeStandard_A4,
            AzureVmSizeStandard_A1_v2,
            AzureVmSizeStandard_A2_v2,
            AzureVmSizeStandard_A4_v2,
            AzureVmSizeStandard_A8_v2,
            AzureVmSizeStandard_D1_v2,
            AzureVmSizeStandard_D2_v2,
            AzureVmSizeStandard_D3_v2,
            AzureVmSizeStandard_D4_v2,
            AzureVmSizeStandard_D5_v2,
            AzureVmSizeStandard_D2_v3,
            AzureVmSizeStandard_D4_v3,
            AzureVmSizeStandard_D8_v3,
            AzureVmSizeStandard_D16_v3,
            AzureVmSizeStandard_F1,
            AzureVmSizeStandard_F2,
            AzureVmSizeStandard_F4,
            AzureVmSizeStandard_F8,
            AzureVmSizeStandard_F16,
            AzureVmSizeStandard_F2s_v2,
            AzureVmSizeStandard_F4s_v2,
            AzureVmSizeStandard_F8s_v2,
            AzureVmSizeStandard_F16s_v2,
            AzureVmSizeStandard_D2as_v4,
            AzureVmSizeStandard_D4as_v4,
            AzureVmSizeStandard_D8as_v4,
            AzureVmSizeStandard_D16as_v4,
            AzureVmSizeStandard_D2a_v4,
            AzureVmSizeStandard_D4a_v4,
            AzureVmSizeStandard_D8a_v4,
            AzureVmSizeStandard_D16a_v4,
            AzureVmSizeStandard_D2ads_v5,
            AzureVmSizeStandard_D4ads_v5,
            AzureVmSizeStandard_D8ads_v5,
            AzureVmSizeStandard_D16ads_v5,
            AzureVmSizeStandard_E2a_v4,
            AzureVmSizeStandard_E4a_v4,
            AzureVmSizeStandard_E8a_v4,
            AzureVmSizeStandard_E16a_v4,
            AzureVmSizeStandard_E2as_v4,
            AzureVmSizeStandard_E4as_v4,
            AzureVmSizeStandard_E8as_v4,
            AzureVmSizeStandard_E16as_v4,
            AzureVmSizeStandard_D2s_v3,
            AzureVmSizeStandard_D4s_v3,
            AzureVmSizeStandard_D8s_v3,
            AzureVmSizeStandard_D16s_v3,
            AzureVmSizeStandard_DS1_v2,
            AzureVmSizeStandard_DS2_v2,
            AzureVmSizeStandard_DS3_v2,
            AzureVmSizeStandard_DS4_v2,
            AzureVmSizeStandard_DS5_v2,
            AzureVmSizeStandard_NC4as_T4_v3,
            AzureVmSizeStandard_D2d_v4,
            AzureVmSizeStandard_D4d_v4,
            AzureVmSizeStandard_D8d_v4,
            AzureVmSizeStandard_D16d_v4,
            AzureVmSizeStandard_D2ds_v4,
            AzureVmSizeStandard_D4ds_v4,
            AzureVmSizeStandard_D8ds_v4,
            AzureVmSizeStandard_D16ds_v4,
            AzureVmSizeStandard_HB120_16rs_v3,
            AzureVmSizeStandard_HB120_32rs_v3,
            AzureVmSizeStandard_HB120_64rs_v3,
            AzureVmSizeStandard_HB120_96rs_v3,
            AzureVmSizeStandard_HB120rs_v3,
            AzureVmSizeStandard_D2d_v5,
            AzureVmSizeStandard_D4d_v5,
            AzureVmSizeStandard_D8d_v5,
            AzureVmSizeStandard_D16d_v5,
            AzureVmSizeStandard_D32d_v5,
            AzureVmSizeStandard_D2ds_v5,
            AzureVmSizeStandard_D4ds_v5,
            AzureVmSizeStandard_D8ds_v5,
            AzureVmSizeStandard_D16ds_v5,
            AzureVmSizeStandard_D32ds_v5
        };

        inline void ToJsonEnum(const AzureVmSize input, Json::Value& output)
        {
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
            if (input == AzureVmSize::AzureVmSizeStandard_D2_v3)
            {
                output = Json::Value("Standard_D2_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4_v3)
            {
                output = Json::Value("Standard_D4_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D8_v3)
            {
                output = Json::Value("Standard_D8_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D16_v3)
            {
                output = Json::Value("Standard_D16_v3");
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
            if (input == AzureVmSize::AzureVmSizeStandard_D2as_v4)
            {
                output = Json::Value("Standard_D2as_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4as_v4)
            {
                output = Json::Value("Standard_D4as_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D8as_v4)
            {
                output = Json::Value("Standard_D8as_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D16as_v4)
            {
                output = Json::Value("Standard_D16as_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D2a_v4)
            {
                output = Json::Value("Standard_D2a_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4a_v4)
            {
                output = Json::Value("Standard_D4a_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D8a_v4)
            {
                output = Json::Value("Standard_D8a_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D16a_v4)
            {
                output = Json::Value("Standard_D16a_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D2ads_v5)
            {
                output = Json::Value("Standard_D2ads_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4ads_v5)
            {
                output = Json::Value("Standard_D4ads_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D8ads_v5)
            {
                output = Json::Value("Standard_D8ads_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D16ads_v5)
            {
                output = Json::Value("Standard_D16ads_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_E2a_v4)
            {
                output = Json::Value("Standard_E2a_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_E4a_v4)
            {
                output = Json::Value("Standard_E4a_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_E8a_v4)
            {
                output = Json::Value("Standard_E8a_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_E16a_v4)
            {
                output = Json::Value("Standard_E16a_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_E2as_v4)
            {
                output = Json::Value("Standard_E2as_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_E4as_v4)
            {
                output = Json::Value("Standard_E4as_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_E8as_v4)
            {
                output = Json::Value("Standard_E8as_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_E16as_v4)
            {
                output = Json::Value("Standard_E16as_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D2s_v3)
            {
                output = Json::Value("Standard_D2s_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4s_v3)
            {
                output = Json::Value("Standard_D4s_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D8s_v3)
            {
                output = Json::Value("Standard_D8s_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D16s_v3)
            {
                output = Json::Value("Standard_D16s_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_DS1_v2)
            {
                output = Json::Value("Standard_DS1_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_DS2_v2)
            {
                output = Json::Value("Standard_DS2_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_DS3_v2)
            {
                output = Json::Value("Standard_DS3_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_DS4_v2)
            {
                output = Json::Value("Standard_DS4_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_DS5_v2)
            {
                output = Json::Value("Standard_DS5_v2");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_NC4as_T4_v3)
            {
                output = Json::Value("Standard_NC4as_T4_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D2d_v4)
            {
                output = Json::Value("Standard_D2d_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4d_v4)
            {
                output = Json::Value("Standard_D4d_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D8d_v4)
            {
                output = Json::Value("Standard_D8d_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D16d_v4)
            {
                output = Json::Value("Standard_D16d_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D2ds_v4)
            {
                output = Json::Value("Standard_D2ds_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4ds_v4)
            {
                output = Json::Value("Standard_D4ds_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D8ds_v4)
            {
                output = Json::Value("Standard_D8ds_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D16ds_v4)
            {
                output = Json::Value("Standard_D16ds_v4");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_HB120_16rs_v3)
            {
                output = Json::Value("Standard_HB120_16rs_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_HB120_32rs_v3)
            {
                output = Json::Value("Standard_HB120_32rs_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_HB120_64rs_v3)
            {
                output = Json::Value("Standard_HB120_64rs_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_HB120_96rs_v3)
            {
                output = Json::Value("Standard_HB120_96rs_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_HB120rs_v3)
            {
                output = Json::Value("Standard_HB120rs_v3");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D2d_v5)
            {
                output = Json::Value("Standard_D2d_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4d_v5)
            {
                output = Json::Value("Standard_D4d_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D8d_v5)
            {
                output = Json::Value("Standard_D8d_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D16d_v5)
            {
                output = Json::Value("Standard_D16d_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D32d_v5)
            {
                output = Json::Value("Standard_D32d_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D2ds_v5)
            {
                output = Json::Value("Standard_D2ds_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D4ds_v5)
            {
                output = Json::Value("Standard_D4ds_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D8ds_v5)
            {
                output = Json::Value("Standard_D8ds_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D16ds_v5)
            {
                output = Json::Value("Standard_D16ds_v5");
                return;
            }
            if (input == AzureVmSize::AzureVmSizeStandard_D32ds_v5)
            {
                output = Json::Value("Standard_D32ds_v5");
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
            if (inputStr == "Standard_D2_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2_v3;
                return;
            }
            if (inputStr == "Standard_D4_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4_v3;
                return;
            }
            if (inputStr == "Standard_D8_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_D8_v3;
                return;
            }
            if (inputStr == "Standard_D16_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_D16_v3;
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
            if (inputStr == "Standard_D2as_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2as_v4;
                return;
            }
            if (inputStr == "Standard_D4as_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4as_v4;
                return;
            }
            if (inputStr == "Standard_D8as_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D8as_v4;
                return;
            }
            if (inputStr == "Standard_D16as_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D16as_v4;
                return;
            }
            if (inputStr == "Standard_D2a_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2a_v4;
                return;
            }
            if (inputStr == "Standard_D4a_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4a_v4;
                return;
            }
            if (inputStr == "Standard_D8a_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D8a_v4;
                return;
            }
            if (inputStr == "Standard_D16a_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D16a_v4;
                return;
            }
            if (inputStr == "Standard_D2ads_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2ads_v5;
                return;
            }
            if (inputStr == "Standard_D4ads_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4ads_v5;
                return;
            }
            if (inputStr == "Standard_D8ads_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D8ads_v5;
                return;
            }
            if (inputStr == "Standard_D16ads_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D16ads_v5;
                return;
            }
            if (inputStr == "Standard_E2a_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_E2a_v4;
                return;
            }
            if (inputStr == "Standard_E4a_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_E4a_v4;
                return;
            }
            if (inputStr == "Standard_E8a_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_E8a_v4;
                return;
            }
            if (inputStr == "Standard_E16a_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_E16a_v4;
                return;
            }
            if (inputStr == "Standard_E2as_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_E2as_v4;
                return;
            }
            if (inputStr == "Standard_E4as_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_E4as_v4;
                return;
            }
            if (inputStr == "Standard_E8as_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_E8as_v4;
                return;
            }
            if (inputStr == "Standard_E16as_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_E16as_v4;
                return;
            }
            if (inputStr == "Standard_D2s_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2s_v3;
                return;
            }
            if (inputStr == "Standard_D4s_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4s_v3;
                return;
            }
            if (inputStr == "Standard_D8s_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_D8s_v3;
                return;
            }
            if (inputStr == "Standard_D16s_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_D16s_v3;
                return;
            }
            if (inputStr == "Standard_DS1_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_DS1_v2;
                return;
            }
            if (inputStr == "Standard_DS2_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_DS2_v2;
                return;
            }
            if (inputStr == "Standard_DS3_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_DS3_v2;
                return;
            }
            if (inputStr == "Standard_DS4_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_DS4_v2;
                return;
            }
            if (inputStr == "Standard_DS5_v2")
            {
                output = AzureVmSize::AzureVmSizeStandard_DS5_v2;
                return;
            }
            if (inputStr == "Standard_NC4as_T4_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_NC4as_T4_v3;
                return;
            }
            if (inputStr == "Standard_D2d_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2d_v4;
                return;
            }
            if (inputStr == "Standard_D4d_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4d_v4;
                return;
            }
            if (inputStr == "Standard_D8d_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D8d_v4;
                return;
            }
            if (inputStr == "Standard_D16d_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D16d_v4;
                return;
            }
            if (inputStr == "Standard_D2ds_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2ds_v4;
                return;
            }
            if (inputStr == "Standard_D4ds_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4ds_v4;
                return;
            }
            if (inputStr == "Standard_D8ds_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D8ds_v4;
                return;
            }
            if (inputStr == "Standard_D16ds_v4")
            {
                output = AzureVmSize::AzureVmSizeStandard_D16ds_v4;
                return;
            }
            if (inputStr == "Standard_HB120_16rs_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_HB120_16rs_v3;
                return;
            }
            if (inputStr == "Standard_HB120_32rs_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_HB120_32rs_v3;
                return;
            }
            if (inputStr == "Standard_HB120_64rs_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_HB120_64rs_v3;
                return;
            }
            if (inputStr == "Standard_HB120_96rs_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_HB120_96rs_v3;
                return;
            }
            if (inputStr == "Standard_HB120rs_v3")
            {
                output = AzureVmSize::AzureVmSizeStandard_HB120rs_v3;
                return;
            }
            if (inputStr == "Standard_D2d_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2d_v5;
                return;
            }
            if (inputStr == "Standard_D4d_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4d_v5;
                return;
            }
            if (inputStr == "Standard_D8d_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D8d_v5;
                return;
            }
            if (inputStr == "Standard_D16d_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D16d_v5;
                return;
            }
            if (inputStr == "Standard_D32d_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D32d_v5;
                return;
            }
            if (inputStr == "Standard_D2ds_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D2ds_v5;
                return;
            }
            if (inputStr == "Standard_D4ds_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D4ds_v5;
                return;
            }
            if (inputStr == "Standard_D8ds_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D8ds_v5;
                return;
            }
            if (inputStr == "Standard_D16ds_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D16ds_v5;
                return;
            }
            if (inputStr == "Standard_D32ds_v5")
            {
                output = AzureVmSize::AzureVmSizeStandard_D32ds_v5;
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
            ContainerFlavorManagedWindowsServerCorePreview,
            ContainerFlavorInvalid
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
            if (input == ContainerFlavor::ContainerFlavorInvalid)
            {
                output = Json::Value("Invalid");
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
            if (inputStr == "Invalid")
            {
                output = ContainerFlavor::ContainerFlavorInvalid;
                return;
            }
        }

        enum class DirectPeerConnectivityOptions
        {
            DirectPeerConnectivityOptionsNone,
            DirectPeerConnectivityOptionsSamePlatformType,
            DirectPeerConnectivityOptionsDifferentPlatformType,
            DirectPeerConnectivityOptionsAnyPlatformType,
            DirectPeerConnectivityOptionsSameEntityLoginProvider,
            DirectPeerConnectivityOptionsDifferentEntityLoginProvider,
            DirectPeerConnectivityOptionsAnyEntityLoginProvider,
            DirectPeerConnectivityOptionsAnyPlatformTypeAndEntityLoginProvider,
            DirectPeerConnectivityOptionsOnlyServers
        };

        inline void ToJsonEnum(const DirectPeerConnectivityOptions input, Json::Value& output)
        {
            if (input == DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsNone)
            {
                output = Json::Value("None");
                return;
            }
            if (input == DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsSamePlatformType)
            {
                output = Json::Value("SamePlatformType");
                return;
            }
            if (input == DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsDifferentPlatformType)
            {
                output = Json::Value("DifferentPlatformType");
                return;
            }
            if (input == DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsAnyPlatformType)
            {
                output = Json::Value("AnyPlatformType");
                return;
            }
            if (input == DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsSameEntityLoginProvider)
            {
                output = Json::Value("SameEntityLoginProvider");
                return;
            }
            if (input == DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsDifferentEntityLoginProvider)
            {
                output = Json::Value("DifferentEntityLoginProvider");
                return;
            }
            if (input == DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsAnyEntityLoginProvider)
            {
                output = Json::Value("AnyEntityLoginProvider");
                return;
            }
            if (input == DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsAnyPlatformTypeAndEntityLoginProvider)
            {
                output = Json::Value("AnyPlatformTypeAndEntityLoginProvider");
                return;
            }
            if (input == DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsOnlyServers)
            {
                output = Json::Value("OnlyServers");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, DirectPeerConnectivityOptions& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "None")
            {
                output = DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsNone;
                return;
            }
            if (inputStr == "SamePlatformType")
            {
                output = DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsSamePlatformType;
                return;
            }
            if (inputStr == "DifferentPlatformType")
            {
                output = DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsDifferentPlatformType;
                return;
            }
            if (inputStr == "AnyPlatformType")
            {
                output = DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsAnyPlatformType;
                return;
            }
            if (inputStr == "SameEntityLoginProvider")
            {
                output = DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsSameEntityLoginProvider;
                return;
            }
            if (inputStr == "DifferentEntityLoginProvider")
            {
                output = DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsDifferentEntityLoginProvider;
                return;
            }
            if (inputStr == "AnyEntityLoginProvider")
            {
                output = DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsAnyEntityLoginProvider;
                return;
            }
            if (inputStr == "AnyPlatformTypeAndEntityLoginProvider")
            {
                output = DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsAnyPlatformTypeAndEntityLoginProvider;
                return;
            }
            if (inputStr == "OnlyServers")
            {
                output = DirectPeerConnectivityOptions::DirectPeerConnectivityOptionsOnlyServers;
                return;
            }
        }

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

        enum class MembershipLock
        {
            MembershipLockUnlocked,
            MembershipLockLocked
        };

        inline void ToJsonEnum(const MembershipLock input, Json::Value& output)
        {
            if (input == MembershipLock::MembershipLockUnlocked)
            {
                output = Json::Value("Unlocked");
                return;
            }
            if (input == MembershipLock::MembershipLockLocked)
            {
                output = Json::Value("Locked");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, MembershipLock& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Unlocked")
            {
                output = MembershipLock::MembershipLockUnlocked;
                return;
            }
            if (inputStr == "Locked")
            {
                output = MembershipLock::MembershipLockLocked;
                return;
            }
        }

        enum class OsPlatform
        {
            OsPlatformWindows,
            OsPlatformLinux
        };

        inline void ToJsonEnum(const OsPlatform input, Json::Value& output)
        {
            if (input == OsPlatform::OsPlatformWindows)
            {
                output = Json::Value("Windows");
                return;
            }
            if (input == OsPlatform::OsPlatformLinux)
            {
                output = Json::Value("Linux");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, OsPlatform& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Windows")
            {
                output = OsPlatform::OsPlatformWindows;
                return;
            }
            if (inputStr == "Linux")
            {
                output = OsPlatform::OsPlatformLinux;
                return;
            }
        }

        enum class OwnerMigrationPolicy
        {
            OwnerMigrationPolicyNone,
            OwnerMigrationPolicyAutomatic,
            OwnerMigrationPolicyManual,
            OwnerMigrationPolicyServer
        };

        inline void ToJsonEnum(const OwnerMigrationPolicy input, Json::Value& output)
        {
            if (input == OwnerMigrationPolicy::OwnerMigrationPolicyNone)
            {
                output = Json::Value("None");
                return;
            }
            if (input == OwnerMigrationPolicy::OwnerMigrationPolicyAutomatic)
            {
                output = Json::Value("Automatic");
                return;
            }
            if (input == OwnerMigrationPolicy::OwnerMigrationPolicyManual)
            {
                output = Json::Value("Manual");
                return;
            }
            if (input == OwnerMigrationPolicy::OwnerMigrationPolicyServer)
            {
                output = Json::Value("Server");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, OwnerMigrationPolicy& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "None")
            {
                output = OwnerMigrationPolicy::OwnerMigrationPolicyNone;
                return;
            }
            if (inputStr == "Automatic")
            {
                output = OwnerMigrationPolicy::OwnerMigrationPolicyAutomatic;
                return;
            }
            if (inputStr == "Manual")
            {
                output = OwnerMigrationPolicy::OwnerMigrationPolicyManual;
                return;
            }
            if (inputStr == "Server")
            {
                output = OwnerMigrationPolicy::OwnerMigrationPolicyServer;
                return;
            }
        }

        enum class PartyInvitationRevocability
        {
            PartyInvitationRevocabilityCreator,
            PartyInvitationRevocabilityAnyone
        };

        inline void ToJsonEnum(const PartyInvitationRevocability input, Json::Value& output)
        {
            if (input == PartyInvitationRevocability::PartyInvitationRevocabilityCreator)
            {
                output = Json::Value("Creator");
                return;
            }
            if (input == PartyInvitationRevocability::PartyInvitationRevocabilityAnyone)
            {
                output = Json::Value("Anyone");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, PartyInvitationRevocability& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Creator")
            {
                output = PartyInvitationRevocability::PartyInvitationRevocabilityCreator;
                return;
            }
            if (inputStr == "Anyone")
            {
                output = PartyInvitationRevocability::PartyInvitationRevocabilityAnyone;
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

        enum class RoutingType
        {
            RoutingTypeMicrosoft,
            RoutingTypeInternet
        };

        inline void ToJsonEnum(const RoutingType input, Json::Value& output)
        {
            if (input == RoutingType::RoutingTypeMicrosoft)
            {
                output = Json::Value("Microsoft");
                return;
            }
            if (input == RoutingType::RoutingTypeInternet)
            {
                output = Json::Value("Internet");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, RoutingType& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Microsoft")
            {
                output = RoutingType::RoutingTypeMicrosoft;
                return;
            }
            if (inputStr == "Internet")
            {
                output = RoutingType::RoutingTypeInternet;
                return;
            }
        }

        enum class ServerType
        {
            ServerTypeContainer,
            ServerTypeProcess
        };

        inline void ToJsonEnum(const ServerType input, Json::Value& output)
        {
            if (input == ServerType::ServerTypeContainer)
            {
                output = Json::Value("Container");
                return;
            }
            if (input == ServerType::ServerTypeProcess)
            {
                output = Json::Value("Process");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, ServerType& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Container")
            {
                output = ServerType::ServerTypeContainer;
                return;
            }
            if (inputStr == "Process")
            {
                output = ServerType::ServerTypeProcess;
                return;
            }
        }

        enum class SubscriptionType
        {
            SubscriptionTypeLobbyChange,
            SubscriptionTypeLobbyInvite
        };

        inline void ToJsonEnum(const SubscriptionType input, Json::Value& output)
        {
            if (input == SubscriptionType::SubscriptionTypeLobbyChange)
            {
                output = Json::Value("LobbyChange");
                return;
            }
            if (input == SubscriptionType::SubscriptionTypeLobbyInvite)
            {
                output = Json::Value("LobbyInvite");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, SubscriptionType& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "LobbyChange")
            {
                output = SubscriptionType::SubscriptionTypeLobbyChange;
                return;
            }
            if (inputStr == "LobbyInvite")
            {
                output = SubscriptionType::SubscriptionTypeLobbyInvite;
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

            BuildAliasDetailsResponse() :
                PlayFabResultCommon(),
                AliasId(),
                AliasName(),
                BuildSelectionCriteria()
            {}

            BuildAliasDetailsResponse(const BuildAliasDetailsResponse& src) :
                PlayFabResultCommon(),
                AliasId(src.AliasId),
                AliasName(src.AliasName),
                BuildSelectionCriteria(src.BuildSelectionCriteria)
            {}

            ~BuildAliasDetailsResponse() = default;

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

        struct Schedule : public PlayFabBaseModel
        {
            std::string Description;
            time_t EndTime;
            bool IsDisabled;
            bool IsRecurringWeekly;
            time_t StartTime;
            Int32 TargetStandby;

            Schedule() :
                PlayFabBaseModel(),
                Description(),
                EndTime(),
                IsDisabled(),
                IsRecurringWeekly(),
                StartTime(),
                TargetStandby()
            {}

            Schedule(const Schedule& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                EndTime(src.EndTime),
                IsDisabled(src.IsDisabled),
                IsRecurringWeekly(src.IsRecurringWeekly),
                StartTime(src.StartTime),
                TargetStandby(src.TargetStandby)
            {}

            ~Schedule() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Description"], Description);
                FromJsonUtilT(input["EndTime"], EndTime);
                FromJsonUtilP(input["IsDisabled"], IsDisabled);
                FromJsonUtilP(input["IsRecurringWeekly"], IsRecurringWeekly);
                FromJsonUtilT(input["StartTime"], StartTime);
                FromJsonUtilP(input["TargetStandby"], TargetStandby);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                Json::Value each_EndTime; ToJsonUtilT(EndTime, each_EndTime); output["EndTime"] = each_EndTime;
                Json::Value each_IsDisabled; ToJsonUtilP(IsDisabled, each_IsDisabled); output["IsDisabled"] = each_IsDisabled;
                Json::Value each_IsRecurringWeekly; ToJsonUtilP(IsRecurringWeekly, each_IsRecurringWeekly); output["IsRecurringWeekly"] = each_IsRecurringWeekly;
                Json::Value each_StartTime; ToJsonUtilT(StartTime, each_StartTime); output["StartTime"] = each_StartTime;
                Json::Value each_TargetStandby; ToJsonUtilP(TargetStandby, each_TargetStandby); output["TargetStandby"] = each_TargetStandby;
                return output;
            }
        };

        struct ScheduledStandbySettings : public PlayFabBaseModel
        {
            bool IsEnabled;
            std::list<Schedule> ScheduleList;

            ScheduledStandbySettings() :
                PlayFabBaseModel(),
                IsEnabled(),
                ScheduleList()
            {}

            ScheduledStandbySettings(const ScheduledStandbySettings& src) :
                PlayFabBaseModel(),
                IsEnabled(src.IsEnabled),
                ScheduleList(src.ScheduleList)
            {}

            ~ScheduledStandbySettings() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["IsEnabled"], IsEnabled);
                FromJsonUtilO(input["ScheduleList"], ScheduleList);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IsEnabled; ToJsonUtilP(IsEnabled, each_IsEnabled); output["IsEnabled"] = each_IsEnabled;
                Json::Value each_ScheduleList; ToJsonUtilO(ScheduleList, each_ScheduleList); output["ScheduleList"] = each_ScheduleList;
                return output;
            }
        };

        struct BuildRegion : public PlayFabBaseModel
        {
            Boxed<CurrentServerStats> pfCurrentServerStats;
            Boxed<DynamicStandbySettings> pfDynamicStandbySettings;
            bool IsAssetReplicationComplete;
            Int32 MaxServers;
            Boxed<Int32> MultiplayerServerCountPerVm;
            std::string Region;
            Boxed<ScheduledStandbySettings> pfScheduledStandbySettings;
            Int32 StandbyServers;
            std::string Status;
            Boxed<AzureVmSize> VmSize;

            BuildRegion() :
                PlayFabBaseModel(),
                pfCurrentServerStats(),
                pfDynamicStandbySettings(),
                IsAssetReplicationComplete(),
                MaxServers(),
                MultiplayerServerCountPerVm(),
                Region(),
                pfScheduledStandbySettings(),
                StandbyServers(),
                Status(),
                VmSize()
            {}

            BuildRegion(const BuildRegion& src) :
                PlayFabBaseModel(),
                pfCurrentServerStats(src.pfCurrentServerStats),
                pfDynamicStandbySettings(src.pfDynamicStandbySettings),
                IsAssetReplicationComplete(src.IsAssetReplicationComplete),
                MaxServers(src.MaxServers),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Region(src.Region),
                pfScheduledStandbySettings(src.pfScheduledStandbySettings),
                StandbyServers(src.StandbyServers),
                Status(src.Status),
                VmSize(src.VmSize)
            {}

            ~BuildRegion() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["CurrentServerStats"], pfCurrentServerStats);
                FromJsonUtilO(input["DynamicStandbySettings"], pfDynamicStandbySettings);
                FromJsonUtilP(input["IsAssetReplicationComplete"], IsAssetReplicationComplete);
                FromJsonUtilP(input["MaxServers"], MaxServers);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilO(input["ScheduledStandbySettings"], pfScheduledStandbySettings);
                FromJsonUtilP(input["StandbyServers"], StandbyServers);
                FromJsonUtilS(input["Status"], Status);
                FromJsonUtilE(input["VmSize"], VmSize);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfCurrentServerStats; ToJsonUtilO(pfCurrentServerStats, each_pfCurrentServerStats); output["CurrentServerStats"] = each_pfCurrentServerStats;
                Json::Value each_pfDynamicStandbySettings; ToJsonUtilO(pfDynamicStandbySettings, each_pfDynamicStandbySettings); output["DynamicStandbySettings"] = each_pfDynamicStandbySettings;
                Json::Value each_IsAssetReplicationComplete; ToJsonUtilP(IsAssetReplicationComplete, each_IsAssetReplicationComplete); output["IsAssetReplicationComplete"] = each_IsAssetReplicationComplete;
                Json::Value each_MaxServers; ToJsonUtilP(MaxServers, each_MaxServers); output["MaxServers"] = each_MaxServers;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_pfScheduledStandbySettings; ToJsonUtilO(pfScheduledStandbySettings, each_pfScheduledStandbySettings); output["ScheduledStandbySettings"] = each_pfScheduledStandbySettings;
                Json::Value each_StandbyServers; ToJsonUtilP(StandbyServers, each_StandbyServers); output["StandbyServers"] = each_StandbyServers;
                Json::Value each_Status; ToJsonUtilS(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                return output;
            }
        };

        struct BuildRegionParams : public PlayFabBaseModel
        {
            Boxed<DynamicStandbySettings> pfDynamicStandbySettings;
            Int32 MaxServers;
            Boxed<Int32> MultiplayerServerCountPerVm;
            std::string Region;
            Boxed<ScheduledStandbySettings> pfScheduledStandbySettings;
            Int32 StandbyServers;
            Boxed<AzureVmSize> VmSize;

            BuildRegionParams() :
                PlayFabBaseModel(),
                pfDynamicStandbySettings(),
                MaxServers(),
                MultiplayerServerCountPerVm(),
                Region(),
                pfScheduledStandbySettings(),
                StandbyServers(),
                VmSize()
            {}

            BuildRegionParams(const BuildRegionParams& src) :
                PlayFabBaseModel(),
                pfDynamicStandbySettings(src.pfDynamicStandbySettings),
                MaxServers(src.MaxServers),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Region(src.Region),
                pfScheduledStandbySettings(src.pfScheduledStandbySettings),
                StandbyServers(src.StandbyServers),
                VmSize(src.VmSize)
            {}

            ~BuildRegionParams() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["DynamicStandbySettings"], pfDynamicStandbySettings);
                FromJsonUtilP(input["MaxServers"], MaxServers);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilO(input["ScheduledStandbySettings"], pfScheduledStandbySettings);
                FromJsonUtilP(input["StandbyServers"], StandbyServers);
                FromJsonUtilE(input["VmSize"], VmSize);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfDynamicStandbySettings; ToJsonUtilO(pfDynamicStandbySettings, each_pfDynamicStandbySettings); output["DynamicStandbySettings"] = each_pfDynamicStandbySettings;
                Json::Value each_MaxServers; ToJsonUtilP(MaxServers, each_MaxServers); output["MaxServers"] = each_MaxServers;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_pfScheduledStandbySettings; ToJsonUtilO(pfScheduledStandbySettings, each_pfScheduledStandbySettings); output["ScheduledStandbySettings"] = each_pfScheduledStandbySettings;
                Json::Value each_StandbyServers; ToJsonUtilP(StandbyServers, each_StandbyServers); output["StandbyServers"] = each_StandbyServers;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
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
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string QueueName;

            CancelAllMatchmakingTicketsForPlayerRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                QueueName()
            {}

            CancelAllMatchmakingTicketsForPlayerRequest(const CancelAllMatchmakingTicketsForPlayerRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                QueueName(src.QueueName)
            {}

            ~CancelAllMatchmakingTicketsForPlayerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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

        struct CancelAllServerBackfillTicketsForPlayerRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            std::string QueueName;

            CancelAllServerBackfillTicketsForPlayerRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                QueueName()
            {}

            CancelAllServerBackfillTicketsForPlayerRequest(const CancelAllServerBackfillTicketsForPlayerRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                QueueName(src.QueueName)
            {}

            ~CancelAllServerBackfillTicketsForPlayerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct CancelAllServerBackfillTicketsForPlayerResult : public PlayFabResultCommon
        {

            CancelAllServerBackfillTicketsForPlayerResult() :
                PlayFabResultCommon()
            {}

            CancelAllServerBackfillTicketsForPlayerResult(const CancelAllServerBackfillTicketsForPlayerResult&) :
                PlayFabResultCommon()
            {}

            ~CancelAllServerBackfillTicketsForPlayerResult() = default;

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
            std::map<std::string, std::string> CustomTags;
            std::string QueueName;
            std::string TicketId;

            CancelMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                QueueName(),
                TicketId()
            {}

            CancelMatchmakingTicketRequest(const CancelMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                QueueName(src.QueueName),
                TicketId(src.TicketId)
            {}

            ~CancelMatchmakingTicketRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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

        struct CancelServerBackfillTicketRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string QueueName;
            std::string TicketId;

            CancelServerBackfillTicketRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                QueueName(),
                TicketId()
            {}

            CancelServerBackfillTicketRequest(const CancelServerBackfillTicketRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                QueueName(src.QueueName),
                TicketId(src.TicketId)
            {}

            ~CancelServerBackfillTicketRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_TicketId; ToJsonUtilS(TicketId, each_TicketId); output["TicketId"] = each_TicketId;
                return output;
            }
        };

        struct CancelServerBackfillTicketResult : public PlayFabResultCommon
        {

            CancelServerBackfillTicketResult() :
                PlayFabResultCommon()
            {}

            CancelServerBackfillTicketResult(const CancelServerBackfillTicketResult&) :
                PlayFabResultCommon()
            {}

            ~CancelServerBackfillTicketResult() = default;

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

        struct CoreCapacityChange : public PlayFabBaseModel
        {
            Int32 NewCoreLimit;
            std::string Region;
            AzureVmFamily VmFamily;

            CoreCapacityChange() :
                PlayFabBaseModel(),
                NewCoreLimit(),
                Region(),
                VmFamily()
            {}

            CoreCapacityChange(const CoreCapacityChange& src) :
                PlayFabBaseModel(),
                NewCoreLimit(src.NewCoreLimit),
                Region(src.Region),
                VmFamily(src.VmFamily)
            {}

            ~CoreCapacityChange() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["NewCoreLimit"], NewCoreLimit);
                FromJsonUtilS(input["Region"], Region);
                FromJsonEnum(input["VmFamily"], VmFamily);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_NewCoreLimit; ToJsonUtilP(NewCoreLimit, each_NewCoreLimit); output["NewCoreLimit"] = each_NewCoreLimit;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_VmFamily; ToJsonEnum(VmFamily, each_VmFamily); output["VmFamily"] = each_VmFamily;
                return output;
            }
        };

        struct CreateBuildAliasRequest : public PlayFabRequestCommon
        {
            std::string AliasName;
            std::list<BuildSelectionCriterion> BuildSelectionCriteria;
            std::map<std::string, std::string> CustomTags;

            CreateBuildAliasRequest() :
                PlayFabRequestCommon(),
                AliasName(),
                BuildSelectionCriteria(),
                CustomTags()
            {}

            CreateBuildAliasRequest(const CreateBuildAliasRequest& src) :
                PlayFabRequestCommon(),
                AliasName(src.AliasName),
                BuildSelectionCriteria(src.BuildSelectionCriteria),
                CustomTags(src.CustomTags)
            {}

            ~CreateBuildAliasRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasName"], AliasName);
                FromJsonUtilO(input["BuildSelectionCriteria"], BuildSelectionCriteria);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasName; ToJsonUtilS(AliasName, each_AliasName); output["AliasName"] = each_AliasName;
                Json::Value each_BuildSelectionCriteria; ToJsonUtilO(BuildSelectionCriteria, each_BuildSelectionCriteria); output["BuildSelectionCriteria"] = each_BuildSelectionCriteria;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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

        struct GameSecretReferenceParams : public PlayFabBaseModel
        {
            std::string Name;

            GameSecretReferenceParams() :
                PlayFabBaseModel(),
                Name()
            {}

            GameSecretReferenceParams(const GameSecretReferenceParams& src) :
                PlayFabBaseModel(),
                Name(src.Name)
            {}

            ~GameSecretReferenceParams() = default;

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

        struct LinuxInstrumentationConfiguration : public PlayFabBaseModel
        {
            bool IsEnabled;

            LinuxInstrumentationConfiguration() :
                PlayFabBaseModel(),
                IsEnabled()
            {}

            LinuxInstrumentationConfiguration(const LinuxInstrumentationConfiguration& src) :
                PlayFabBaseModel(),
                IsEnabled(src.IsEnabled)
            {}

            ~LinuxInstrumentationConfiguration() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["IsEnabled"], IsEnabled);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IsEnabled; ToJsonUtilP(IsEnabled, each_IsEnabled); output["IsEnabled"] = each_IsEnabled;
                return output;
            }
        };

        struct MonitoringApplicationConfigurationParams : public PlayFabBaseModel
        {
            AssetReferenceParams AssetReference;
            std::string ExecutionScriptName;
            std::string InstallationScriptName;
            Boxed<double> OnStartRuntimeInMinutes;

            MonitoringApplicationConfigurationParams() :
                PlayFabBaseModel(),
                AssetReference(),
                ExecutionScriptName(),
                InstallationScriptName(),
                OnStartRuntimeInMinutes()
            {}

            MonitoringApplicationConfigurationParams(const MonitoringApplicationConfigurationParams& src) :
                PlayFabBaseModel(),
                AssetReference(src.AssetReference),
                ExecutionScriptName(src.ExecutionScriptName),
                InstallationScriptName(src.InstallationScriptName),
                OnStartRuntimeInMinutes(src.OnStartRuntimeInMinutes)
            {}

            ~MonitoringApplicationConfigurationParams() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AssetReference"], AssetReference);
                FromJsonUtilS(input["ExecutionScriptName"], ExecutionScriptName);
                FromJsonUtilS(input["InstallationScriptName"], InstallationScriptName);
                FromJsonUtilP(input["OnStartRuntimeInMinutes"], OnStartRuntimeInMinutes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AssetReference; ToJsonUtilO(AssetReference, each_AssetReference); output["AssetReference"] = each_AssetReference;
                Json::Value each_ExecutionScriptName; ToJsonUtilS(ExecutionScriptName, each_ExecutionScriptName); output["ExecutionScriptName"] = each_ExecutionScriptName;
                Json::Value each_InstallationScriptName; ToJsonUtilS(InstallationScriptName, each_InstallationScriptName); output["InstallationScriptName"] = each_InstallationScriptName;
                Json::Value each_OnStartRuntimeInMinutes; ToJsonUtilP(OnStartRuntimeInMinutes, each_OnStartRuntimeInMinutes); output["OnStartRuntimeInMinutes"] = each_OnStartRuntimeInMinutes;
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

        struct ServerResourceConstraintParams : public PlayFabBaseModel
        {
            double CpuLimit;
            double MemoryLimitGB;

            ServerResourceConstraintParams() :
                PlayFabBaseModel(),
                CpuLimit(),
                MemoryLimitGB()
            {}

            ServerResourceConstraintParams(const ServerResourceConstraintParams& src) :
                PlayFabBaseModel(),
                CpuLimit(src.CpuLimit),
                MemoryLimitGB(src.MemoryLimitGB)
            {}

            ~ServerResourceConstraintParams() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["CpuLimit"], CpuLimit);
                FromJsonUtilP(input["MemoryLimitGB"], MemoryLimitGB);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CpuLimit; ToJsonUtilP(CpuLimit, each_CpuLimit); output["CpuLimit"] = each_CpuLimit;
                Json::Value each_MemoryLimitGB; ToJsonUtilP(MemoryLimitGB, each_MemoryLimitGB); output["MemoryLimitGB"] = each_MemoryLimitGB;
                return output;
            }
        };

        struct VmStartupScriptPortRequestParams : public PlayFabBaseModel
        {
            std::string Name;
            ProtocolType Protocol;

            VmStartupScriptPortRequestParams() :
                PlayFabBaseModel(),
                Name(),
                Protocol()
            {}

            VmStartupScriptPortRequestParams(const VmStartupScriptPortRequestParams& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Protocol(src.Protocol)
            {}

            ~VmStartupScriptPortRequestParams() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
                FromJsonEnum(input["Protocol"], Protocol);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Protocol; ToJsonEnum(Protocol, each_Protocol); output["Protocol"] = each_Protocol;
                return output;
            }
        };

        struct VmStartupScriptParams : public PlayFabBaseModel
        {
            std::list<VmStartupScriptPortRequestParams> PortRequests;
            AssetReferenceParams VmStartupScriptAssetReference;

            VmStartupScriptParams() :
                PlayFabBaseModel(),
                PortRequests(),
                VmStartupScriptAssetReference()
            {}

            VmStartupScriptParams(const VmStartupScriptParams& src) :
                PlayFabBaseModel(),
                PortRequests(src.PortRequests),
                VmStartupScriptAssetReference(src.VmStartupScriptAssetReference)
            {}

            ~VmStartupScriptParams() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["PortRequests"], PortRequests);
                FromJsonUtilO(input["VmStartupScriptAssetReference"], VmStartupScriptAssetReference);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PortRequests; ToJsonUtilO(PortRequests, each_PortRequests); output["PortRequests"] = each_PortRequests;
                Json::Value each_VmStartupScriptAssetReference; ToJsonUtilO(VmStartupScriptAssetReference, each_VmStartupScriptAssetReference); output["VmStartupScriptAssetReference"] = each_VmStartupScriptAssetReference;
                return output;
            }
        };

        struct CreateBuildWithCustomContainerRequest : public PlayFabRequestCommon
        {
            Boxed<bool> AreAssetsReadonly;
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            Boxed<ContainerImageReference> pfContainerImageReference;
            std::string ContainerRunCommand;
            std::map<std::string, std::string> CustomTags;
            std::list<AssetReferenceParams> GameAssetReferences;
            std::list<GameCertificateReferenceParams> GameCertificateReferences;
            std::list<GameSecretReferenceParams> GameSecretReferences;
            Boxed<LinuxInstrumentationConfiguration> pfLinuxInstrumentationConfiguration;
            std::map<std::string, std::string> Metadata;
            Boxed<MonitoringApplicationConfigurationParams> MonitoringApplicationConfiguration;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegionParams> RegionConfigurations;
            Boxed<ServerResourceConstraintParams> ServerResourceConstraints;
            Boxed<AzureVmSize> VmSize;
            Boxed<VmStartupScriptParams> VmStartupScriptConfiguration;

            CreateBuildWithCustomContainerRequest() :
                PlayFabRequestCommon(),
                AreAssetsReadonly(),
                BuildName(),
                pfContainerFlavor(),
                pfContainerImageReference(),
                ContainerRunCommand(),
                CustomTags(),
                GameAssetReferences(),
                GameCertificateReferences(),
                GameSecretReferences(),
                pfLinuxInstrumentationConfiguration(),
                Metadata(),
                MonitoringApplicationConfiguration(),
                MultiplayerServerCountPerVm(),
                Ports(),
                RegionConfigurations(),
                ServerResourceConstraints(),
                VmSize(),
                VmStartupScriptConfiguration()
            {}

            CreateBuildWithCustomContainerRequest(const CreateBuildWithCustomContainerRequest& src) :
                PlayFabRequestCommon(),
                AreAssetsReadonly(src.AreAssetsReadonly),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                pfContainerImageReference(src.pfContainerImageReference),
                ContainerRunCommand(src.ContainerRunCommand),
                CustomTags(src.CustomTags),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                GameSecretReferences(src.GameSecretReferences),
                pfLinuxInstrumentationConfiguration(src.pfLinuxInstrumentationConfiguration),
                Metadata(src.Metadata),
                MonitoringApplicationConfiguration(src.MonitoringApplicationConfiguration),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                ServerResourceConstraints(src.ServerResourceConstraints),
                VmSize(src.VmSize),
                VmStartupScriptConfiguration(src.VmStartupScriptConfiguration)
            {}

            ~CreateBuildWithCustomContainerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["AreAssetsReadonly"], AreAssetsReadonly);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
                FromJsonUtilO(input["ContainerImageReference"], pfContainerImageReference);
                FromJsonUtilS(input["ContainerRunCommand"], ContainerRunCommand);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilO(input["GameSecretReferences"], GameSecretReferences);
                FromJsonUtilO(input["LinuxInstrumentationConfiguration"], pfLinuxInstrumentationConfiguration);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilO(input["MonitoringApplicationConfiguration"], MonitoringApplicationConfiguration);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilO(input["ServerResourceConstraints"], ServerResourceConstraints);
                FromJsonUtilE(input["VmSize"], VmSize);
                FromJsonUtilO(input["VmStartupScriptConfiguration"], VmStartupScriptConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AreAssetsReadonly; ToJsonUtilP(AreAssetsReadonly, each_AreAssetsReadonly); output["AreAssetsReadonly"] = each_AreAssetsReadonly;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_pfContainerImageReference; ToJsonUtilO(pfContainerImageReference, each_pfContainerImageReference); output["ContainerImageReference"] = each_pfContainerImageReference;
                Json::Value each_ContainerRunCommand; ToJsonUtilS(ContainerRunCommand, each_ContainerRunCommand); output["ContainerRunCommand"] = each_ContainerRunCommand;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_GameSecretReferences; ToJsonUtilO(GameSecretReferences, each_GameSecretReferences); output["GameSecretReferences"] = each_GameSecretReferences;
                Json::Value each_pfLinuxInstrumentationConfiguration; ToJsonUtilO(pfLinuxInstrumentationConfiguration, each_pfLinuxInstrumentationConfiguration); output["LinuxInstrumentationConfiguration"] = each_pfLinuxInstrumentationConfiguration;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_MonitoringApplicationConfiguration; ToJsonUtilO(MonitoringApplicationConfiguration, each_MonitoringApplicationConfiguration); output["MonitoringApplicationConfiguration"] = each_MonitoringApplicationConfiguration;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_ServerResourceConstraints; ToJsonUtilO(ServerResourceConstraints, each_ServerResourceConstraints); output["ServerResourceConstraints"] = each_ServerResourceConstraints;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                Json::Value each_VmStartupScriptConfiguration; ToJsonUtilO(VmStartupScriptConfiguration, each_VmStartupScriptConfiguration); output["VmStartupScriptConfiguration"] = each_VmStartupScriptConfiguration;
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

        struct GameSecretReference : public PlayFabBaseModel
        {
            std::string Name;

            GameSecretReference() :
                PlayFabBaseModel(),
                Name()
            {}

            GameSecretReference(const GameSecretReference& src) :
                PlayFabBaseModel(),
                Name(src.Name)
            {}

            ~GameSecretReference() = default;

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

        struct MonitoringApplicationConfiguration : public PlayFabBaseModel
        {
            AssetReference pfAssetReference;
            std::string ExecutionScriptName;
            std::string InstallationScriptName;
            Boxed<double> OnStartRuntimeInMinutes;

            MonitoringApplicationConfiguration() :
                PlayFabBaseModel(),
                pfAssetReference(),
                ExecutionScriptName(),
                InstallationScriptName(),
                OnStartRuntimeInMinutes()
            {}

            MonitoringApplicationConfiguration(const MonitoringApplicationConfiguration& src) :
                PlayFabBaseModel(),
                pfAssetReference(src.pfAssetReference),
                ExecutionScriptName(src.ExecutionScriptName),
                InstallationScriptName(src.InstallationScriptName),
                OnStartRuntimeInMinutes(src.OnStartRuntimeInMinutes)
            {}

            ~MonitoringApplicationConfiguration() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AssetReference"], pfAssetReference);
                FromJsonUtilS(input["ExecutionScriptName"], ExecutionScriptName);
                FromJsonUtilS(input["InstallationScriptName"], InstallationScriptName);
                FromJsonUtilP(input["OnStartRuntimeInMinutes"], OnStartRuntimeInMinutes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfAssetReference; ToJsonUtilO(pfAssetReference, each_pfAssetReference); output["AssetReference"] = each_pfAssetReference;
                Json::Value each_ExecutionScriptName; ToJsonUtilS(ExecutionScriptName, each_ExecutionScriptName); output["ExecutionScriptName"] = each_ExecutionScriptName;
                Json::Value each_InstallationScriptName; ToJsonUtilS(InstallationScriptName, each_InstallationScriptName); output["InstallationScriptName"] = each_InstallationScriptName;
                Json::Value each_OnStartRuntimeInMinutes; ToJsonUtilP(OnStartRuntimeInMinutes, each_OnStartRuntimeInMinutes); output["OnStartRuntimeInMinutes"] = each_OnStartRuntimeInMinutes;
                return output;
            }
        };

        struct VmStartupScriptPortRequest : public PlayFabRequestCommon
        {
            std::string Name;
            ProtocolType Protocol;

            VmStartupScriptPortRequest() :
                PlayFabRequestCommon(),
                Name(),
                Protocol()
            {}

            VmStartupScriptPortRequest(const VmStartupScriptPortRequest& src) :
                PlayFabRequestCommon(),
                Name(src.Name),
                Protocol(src.Protocol)
            {}

            ~VmStartupScriptPortRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
                FromJsonEnum(input["Protocol"], Protocol);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Protocol; ToJsonEnum(Protocol, each_Protocol); output["Protocol"] = each_Protocol;
                return output;
            }
        };

        struct VmStartupScriptConfiguration : public PlayFabBaseModel
        {
            std::list<VmStartupScriptPortRequest> PortRequests;
            AssetReference VmStartupScriptAssetReference;

            VmStartupScriptConfiguration() :
                PlayFabBaseModel(),
                PortRequests(),
                VmStartupScriptAssetReference()
            {}

            VmStartupScriptConfiguration(const VmStartupScriptConfiguration& src) :
                PlayFabBaseModel(),
                PortRequests(src.PortRequests),
                VmStartupScriptAssetReference(src.VmStartupScriptAssetReference)
            {}

            ~VmStartupScriptConfiguration() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["PortRequests"], PortRequests);
                FromJsonUtilO(input["VmStartupScriptAssetReference"], VmStartupScriptAssetReference);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PortRequests; ToJsonUtilO(PortRequests, each_PortRequests); output["PortRequests"] = each_PortRequests;
                Json::Value each_VmStartupScriptAssetReference; ToJsonUtilO(VmStartupScriptAssetReference, each_VmStartupScriptAssetReference); output["VmStartupScriptAssetReference"] = each_VmStartupScriptAssetReference;
                return output;
            }
        };

        struct CreateBuildWithCustomContainerResponse : public PlayFabResultCommon
        {
            Boxed<bool> AreAssetsReadonly;
            std::string BuildId;
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::string ContainerRunCommand;
            Boxed<time_t> CreationTime;
            Boxed<ContainerImageReference> CustomGameContainerImage;
            std::list<AssetReference> GameAssetReferences;
            std::list<GameCertificateReference> GameCertificateReferences;
            std::list<GameSecretReference> GameSecretReferences;
            Boxed<LinuxInstrumentationConfiguration> pfLinuxInstrumentationConfiguration;
            std::map<std::string, std::string> Metadata;
            Boxed<MonitoringApplicationConfiguration> pfMonitoringApplicationConfiguration;
            Int32 MultiplayerServerCountPerVm;
            std::string OsPlatform;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            Boxed<ServerResourceConstraintParams> ServerResourceConstraints;
            std::string ServerType;
            Boxed<bool> UseStreamingForAssetDownloads;
            Boxed<AzureVmSize> VmSize;
            Boxed<VmStartupScriptConfiguration> pfVmStartupScriptConfiguration;

            CreateBuildWithCustomContainerResponse() :
                PlayFabResultCommon(),
                AreAssetsReadonly(),
                BuildId(),
                BuildName(),
                pfContainerFlavor(),
                ContainerRunCommand(),
                CreationTime(),
                CustomGameContainerImage(),
                GameAssetReferences(),
                GameCertificateReferences(),
                GameSecretReferences(),
                pfLinuxInstrumentationConfiguration(),
                Metadata(),
                pfMonitoringApplicationConfiguration(),
                MultiplayerServerCountPerVm(),
                OsPlatform(),
                Ports(),
                RegionConfigurations(),
                ServerResourceConstraints(),
                ServerType(),
                UseStreamingForAssetDownloads(),
                VmSize(),
                pfVmStartupScriptConfiguration()
            {}

            CreateBuildWithCustomContainerResponse(const CreateBuildWithCustomContainerResponse& src) :
                PlayFabResultCommon(),
                AreAssetsReadonly(src.AreAssetsReadonly),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                ContainerRunCommand(src.ContainerRunCommand),
                CreationTime(src.CreationTime),
                CustomGameContainerImage(src.CustomGameContainerImage),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                GameSecretReferences(src.GameSecretReferences),
                pfLinuxInstrumentationConfiguration(src.pfLinuxInstrumentationConfiguration),
                Metadata(src.Metadata),
                pfMonitoringApplicationConfiguration(src.pfMonitoringApplicationConfiguration),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                OsPlatform(src.OsPlatform),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                ServerResourceConstraints(src.ServerResourceConstraints),
                ServerType(src.ServerType),
                UseStreamingForAssetDownloads(src.UseStreamingForAssetDownloads),
                VmSize(src.VmSize),
                pfVmStartupScriptConfiguration(src.pfVmStartupScriptConfiguration)
            {}

            ~CreateBuildWithCustomContainerResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["AreAssetsReadonly"], AreAssetsReadonly);
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
                FromJsonUtilS(input["ContainerRunCommand"], ContainerRunCommand);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilO(input["CustomGameContainerImage"], CustomGameContainerImage);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilO(input["GameSecretReferences"], GameSecretReferences);
                FromJsonUtilO(input["LinuxInstrumentationConfiguration"], pfLinuxInstrumentationConfiguration);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilO(input["MonitoringApplicationConfiguration"], pfMonitoringApplicationConfiguration);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilS(input["OsPlatform"], OsPlatform);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilO(input["ServerResourceConstraints"], ServerResourceConstraints);
                FromJsonUtilS(input["ServerType"], ServerType);
                FromJsonUtilP(input["UseStreamingForAssetDownloads"], UseStreamingForAssetDownloads);
                FromJsonUtilE(input["VmSize"], VmSize);
                FromJsonUtilO(input["VmStartupScriptConfiguration"], pfVmStartupScriptConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AreAssetsReadonly; ToJsonUtilP(AreAssetsReadonly, each_AreAssetsReadonly); output["AreAssetsReadonly"] = each_AreAssetsReadonly;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_ContainerRunCommand; ToJsonUtilS(ContainerRunCommand, each_ContainerRunCommand); output["ContainerRunCommand"] = each_ContainerRunCommand;
                Json::Value each_CreationTime; ToJsonUtilT(CreationTime, each_CreationTime); output["CreationTime"] = each_CreationTime;
                Json::Value each_CustomGameContainerImage; ToJsonUtilO(CustomGameContainerImage, each_CustomGameContainerImage); output["CustomGameContainerImage"] = each_CustomGameContainerImage;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_GameSecretReferences; ToJsonUtilO(GameSecretReferences, each_GameSecretReferences); output["GameSecretReferences"] = each_GameSecretReferences;
                Json::Value each_pfLinuxInstrumentationConfiguration; ToJsonUtilO(pfLinuxInstrumentationConfiguration, each_pfLinuxInstrumentationConfiguration); output["LinuxInstrumentationConfiguration"] = each_pfLinuxInstrumentationConfiguration;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_pfMonitoringApplicationConfiguration; ToJsonUtilO(pfMonitoringApplicationConfiguration, each_pfMonitoringApplicationConfiguration); output["MonitoringApplicationConfiguration"] = each_pfMonitoringApplicationConfiguration;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_OsPlatform; ToJsonUtilS(OsPlatform, each_OsPlatform); output["OsPlatform"] = each_OsPlatform;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_ServerResourceConstraints; ToJsonUtilO(ServerResourceConstraints, each_ServerResourceConstraints); output["ServerResourceConstraints"] = each_ServerResourceConstraints;
                Json::Value each_ServerType; ToJsonUtilS(ServerType, each_ServerType); output["ServerType"] = each_ServerType;
                Json::Value each_UseStreamingForAssetDownloads; ToJsonUtilP(UseStreamingForAssetDownloads, each_UseStreamingForAssetDownloads); output["UseStreamingForAssetDownloads"] = each_UseStreamingForAssetDownloads;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                Json::Value each_pfVmStartupScriptConfiguration; ToJsonUtilO(pfVmStartupScriptConfiguration, each_pfVmStartupScriptConfiguration); output["VmStartupScriptConfiguration"] = each_pfVmStartupScriptConfiguration;
                return output;
            }
        };

        struct InstrumentationConfiguration : public PlayFabBaseModel
        {
            Boxed<bool> IsEnabled;
            std::list<std::string> ProcessesToMonitor;

            InstrumentationConfiguration() :
                PlayFabBaseModel(),
                IsEnabled(),
                ProcessesToMonitor()
            {}

            InstrumentationConfiguration(const InstrumentationConfiguration& src) :
                PlayFabBaseModel(),
                IsEnabled(src.IsEnabled),
                ProcessesToMonitor(src.ProcessesToMonitor)
            {}

            ~InstrumentationConfiguration() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["IsEnabled"], IsEnabled);
                FromJsonUtilS(input["ProcessesToMonitor"], ProcessesToMonitor);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IsEnabled; ToJsonUtilP(IsEnabled, each_IsEnabled); output["IsEnabled"] = each_IsEnabled;
                Json::Value each_ProcessesToMonitor; ToJsonUtilS(ProcessesToMonitor, each_ProcessesToMonitor); output["ProcessesToMonitor"] = each_ProcessesToMonitor;
                return output;
            }
        };

        struct WindowsCrashDumpConfiguration : public PlayFabBaseModel
        {
            Boxed<Int32> CustomDumpFlags;
            Boxed<Int32> DumpType;
            bool IsEnabled;

            WindowsCrashDumpConfiguration() :
                PlayFabBaseModel(),
                CustomDumpFlags(),
                DumpType(),
                IsEnabled()
            {}

            WindowsCrashDumpConfiguration(const WindowsCrashDumpConfiguration& src) :
                PlayFabBaseModel(),
                CustomDumpFlags(src.CustomDumpFlags),
                DumpType(src.DumpType),
                IsEnabled(src.IsEnabled)
            {}

            ~WindowsCrashDumpConfiguration() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["CustomDumpFlags"], CustomDumpFlags);
                FromJsonUtilP(input["DumpType"], DumpType);
                FromJsonUtilP(input["IsEnabled"], IsEnabled);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomDumpFlags; ToJsonUtilP(CustomDumpFlags, each_CustomDumpFlags); output["CustomDumpFlags"] = each_CustomDumpFlags;
                Json::Value each_DumpType; ToJsonUtilP(DumpType, each_DumpType); output["DumpType"] = each_DumpType;
                Json::Value each_IsEnabled; ToJsonUtilP(IsEnabled, each_IsEnabled); output["IsEnabled"] = each_IsEnabled;
                return output;
            }
        };

        struct CreateBuildWithManagedContainerRequest : public PlayFabRequestCommon
        {
            Boxed<bool> AreAssetsReadonly;
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::map<std::string, std::string> CustomTags;
            std::list<AssetReferenceParams> GameAssetReferences;
            std::list<GameCertificateReferenceParams> GameCertificateReferences;
            std::list<GameSecretReferenceParams> GameSecretReferences;
            std::string GameWorkingDirectory;
            Boxed<InstrumentationConfiguration> pfInstrumentationConfiguration;
            std::map<std::string, std::string> Metadata;
            Boxed<MonitoringApplicationConfigurationParams> MonitoringApplicationConfiguration;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegionParams> RegionConfigurations;
            Boxed<ServerResourceConstraintParams> ServerResourceConstraints;
            std::string StartMultiplayerServerCommand;
            Boxed<AzureVmSize> VmSize;
            Boxed<VmStartupScriptParams> VmStartupScriptConfiguration;
            Boxed<WindowsCrashDumpConfiguration> pfWindowsCrashDumpConfiguration;

            CreateBuildWithManagedContainerRequest() :
                PlayFabRequestCommon(),
                AreAssetsReadonly(),
                BuildName(),
                pfContainerFlavor(),
                CustomTags(),
                GameAssetReferences(),
                GameCertificateReferences(),
                GameSecretReferences(),
                GameWorkingDirectory(),
                pfInstrumentationConfiguration(),
                Metadata(),
                MonitoringApplicationConfiguration(),
                MultiplayerServerCountPerVm(),
                Ports(),
                RegionConfigurations(),
                ServerResourceConstraints(),
                StartMultiplayerServerCommand(),
                VmSize(),
                VmStartupScriptConfiguration(),
                pfWindowsCrashDumpConfiguration()
            {}

            CreateBuildWithManagedContainerRequest(const CreateBuildWithManagedContainerRequest& src) :
                PlayFabRequestCommon(),
                AreAssetsReadonly(src.AreAssetsReadonly),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                CustomTags(src.CustomTags),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                GameSecretReferences(src.GameSecretReferences),
                GameWorkingDirectory(src.GameWorkingDirectory),
                pfInstrumentationConfiguration(src.pfInstrumentationConfiguration),
                Metadata(src.Metadata),
                MonitoringApplicationConfiguration(src.MonitoringApplicationConfiguration),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                ServerResourceConstraints(src.ServerResourceConstraints),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize),
                VmStartupScriptConfiguration(src.VmStartupScriptConfiguration),
                pfWindowsCrashDumpConfiguration(src.pfWindowsCrashDumpConfiguration)
            {}

            ~CreateBuildWithManagedContainerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["AreAssetsReadonly"], AreAssetsReadonly);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilO(input["GameSecretReferences"], GameSecretReferences);
                FromJsonUtilS(input["GameWorkingDirectory"], GameWorkingDirectory);
                FromJsonUtilO(input["InstrumentationConfiguration"], pfInstrumentationConfiguration);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilO(input["MonitoringApplicationConfiguration"], MonitoringApplicationConfiguration);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilO(input["ServerResourceConstraints"], ServerResourceConstraints);
                FromJsonUtilS(input["StartMultiplayerServerCommand"], StartMultiplayerServerCommand);
                FromJsonUtilE(input["VmSize"], VmSize);
                FromJsonUtilO(input["VmStartupScriptConfiguration"], VmStartupScriptConfiguration);
                FromJsonUtilO(input["WindowsCrashDumpConfiguration"], pfWindowsCrashDumpConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AreAssetsReadonly; ToJsonUtilP(AreAssetsReadonly, each_AreAssetsReadonly); output["AreAssetsReadonly"] = each_AreAssetsReadonly;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_GameSecretReferences; ToJsonUtilO(GameSecretReferences, each_GameSecretReferences); output["GameSecretReferences"] = each_GameSecretReferences;
                Json::Value each_GameWorkingDirectory; ToJsonUtilS(GameWorkingDirectory, each_GameWorkingDirectory); output["GameWorkingDirectory"] = each_GameWorkingDirectory;
                Json::Value each_pfInstrumentationConfiguration; ToJsonUtilO(pfInstrumentationConfiguration, each_pfInstrumentationConfiguration); output["InstrumentationConfiguration"] = each_pfInstrumentationConfiguration;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_MonitoringApplicationConfiguration; ToJsonUtilO(MonitoringApplicationConfiguration, each_MonitoringApplicationConfiguration); output["MonitoringApplicationConfiguration"] = each_MonitoringApplicationConfiguration;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_ServerResourceConstraints; ToJsonUtilO(ServerResourceConstraints, each_ServerResourceConstraints); output["ServerResourceConstraints"] = each_ServerResourceConstraints;
                Json::Value each_StartMultiplayerServerCommand; ToJsonUtilS(StartMultiplayerServerCommand, each_StartMultiplayerServerCommand); output["StartMultiplayerServerCommand"] = each_StartMultiplayerServerCommand;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                Json::Value each_VmStartupScriptConfiguration; ToJsonUtilO(VmStartupScriptConfiguration, each_VmStartupScriptConfiguration); output["VmStartupScriptConfiguration"] = each_VmStartupScriptConfiguration;
                Json::Value each_pfWindowsCrashDumpConfiguration; ToJsonUtilO(pfWindowsCrashDumpConfiguration, each_pfWindowsCrashDumpConfiguration); output["WindowsCrashDumpConfiguration"] = each_pfWindowsCrashDumpConfiguration;
                return output;
            }
        };

        struct CreateBuildWithManagedContainerResponse : public PlayFabResultCommon
        {
            Boxed<bool> AreAssetsReadonly;
            std::string BuildId;
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            Boxed<time_t> CreationTime;
            std::list<AssetReference> GameAssetReferences;
            std::list<GameCertificateReference> GameCertificateReferences;
            std::list<GameSecretReference> GameSecretReferences;
            std::string GameWorkingDirectory;
            Boxed<InstrumentationConfiguration> pfInstrumentationConfiguration;
            std::map<std::string, std::string> Metadata;
            Boxed<MonitoringApplicationConfiguration> pfMonitoringApplicationConfiguration;
            Int32 MultiplayerServerCountPerVm;
            std::string OsPlatform;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            Boxed<ServerResourceConstraintParams> ServerResourceConstraints;
            std::string ServerType;
            std::string StartMultiplayerServerCommand;
            Boxed<bool> UseStreamingForAssetDownloads;
            Boxed<AzureVmSize> VmSize;
            Boxed<VmStartupScriptConfiguration> pfVmStartupScriptConfiguration;

            CreateBuildWithManagedContainerResponse() :
                PlayFabResultCommon(),
                AreAssetsReadonly(),
                BuildId(),
                BuildName(),
                pfContainerFlavor(),
                CreationTime(),
                GameAssetReferences(),
                GameCertificateReferences(),
                GameSecretReferences(),
                GameWorkingDirectory(),
                pfInstrumentationConfiguration(),
                Metadata(),
                pfMonitoringApplicationConfiguration(),
                MultiplayerServerCountPerVm(),
                OsPlatform(),
                Ports(),
                RegionConfigurations(),
                ServerResourceConstraints(),
                ServerType(),
                StartMultiplayerServerCommand(),
                UseStreamingForAssetDownloads(),
                VmSize(),
                pfVmStartupScriptConfiguration()
            {}

            CreateBuildWithManagedContainerResponse(const CreateBuildWithManagedContainerResponse& src) :
                PlayFabResultCommon(),
                AreAssetsReadonly(src.AreAssetsReadonly),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                CreationTime(src.CreationTime),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                GameSecretReferences(src.GameSecretReferences),
                GameWorkingDirectory(src.GameWorkingDirectory),
                pfInstrumentationConfiguration(src.pfInstrumentationConfiguration),
                Metadata(src.Metadata),
                pfMonitoringApplicationConfiguration(src.pfMonitoringApplicationConfiguration),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                OsPlatform(src.OsPlatform),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                ServerResourceConstraints(src.ServerResourceConstraints),
                ServerType(src.ServerType),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                UseStreamingForAssetDownloads(src.UseStreamingForAssetDownloads),
                VmSize(src.VmSize),
                pfVmStartupScriptConfiguration(src.pfVmStartupScriptConfiguration)
            {}

            ~CreateBuildWithManagedContainerResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["AreAssetsReadonly"], AreAssetsReadonly);
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilO(input["GameSecretReferences"], GameSecretReferences);
                FromJsonUtilS(input["GameWorkingDirectory"], GameWorkingDirectory);
                FromJsonUtilO(input["InstrumentationConfiguration"], pfInstrumentationConfiguration);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilO(input["MonitoringApplicationConfiguration"], pfMonitoringApplicationConfiguration);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilS(input["OsPlatform"], OsPlatform);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilO(input["ServerResourceConstraints"], ServerResourceConstraints);
                FromJsonUtilS(input["ServerType"], ServerType);
                FromJsonUtilS(input["StartMultiplayerServerCommand"], StartMultiplayerServerCommand);
                FromJsonUtilP(input["UseStreamingForAssetDownloads"], UseStreamingForAssetDownloads);
                FromJsonUtilE(input["VmSize"], VmSize);
                FromJsonUtilO(input["VmStartupScriptConfiguration"], pfVmStartupScriptConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AreAssetsReadonly; ToJsonUtilP(AreAssetsReadonly, each_AreAssetsReadonly); output["AreAssetsReadonly"] = each_AreAssetsReadonly;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_CreationTime; ToJsonUtilT(CreationTime, each_CreationTime); output["CreationTime"] = each_CreationTime;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_GameSecretReferences; ToJsonUtilO(GameSecretReferences, each_GameSecretReferences); output["GameSecretReferences"] = each_GameSecretReferences;
                Json::Value each_GameWorkingDirectory; ToJsonUtilS(GameWorkingDirectory, each_GameWorkingDirectory); output["GameWorkingDirectory"] = each_GameWorkingDirectory;
                Json::Value each_pfInstrumentationConfiguration; ToJsonUtilO(pfInstrumentationConfiguration, each_pfInstrumentationConfiguration); output["InstrumentationConfiguration"] = each_pfInstrumentationConfiguration;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_pfMonitoringApplicationConfiguration; ToJsonUtilO(pfMonitoringApplicationConfiguration, each_pfMonitoringApplicationConfiguration); output["MonitoringApplicationConfiguration"] = each_pfMonitoringApplicationConfiguration;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_OsPlatform; ToJsonUtilS(OsPlatform, each_OsPlatform); output["OsPlatform"] = each_OsPlatform;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_ServerResourceConstraints; ToJsonUtilO(ServerResourceConstraints, each_ServerResourceConstraints); output["ServerResourceConstraints"] = each_ServerResourceConstraints;
                Json::Value each_ServerType; ToJsonUtilS(ServerType, each_ServerType); output["ServerType"] = each_ServerType;
                Json::Value each_StartMultiplayerServerCommand; ToJsonUtilS(StartMultiplayerServerCommand, each_StartMultiplayerServerCommand); output["StartMultiplayerServerCommand"] = each_StartMultiplayerServerCommand;
                Json::Value each_UseStreamingForAssetDownloads; ToJsonUtilP(UseStreamingForAssetDownloads, each_UseStreamingForAssetDownloads); output["UseStreamingForAssetDownloads"] = each_UseStreamingForAssetDownloads;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                Json::Value each_pfVmStartupScriptConfiguration; ToJsonUtilO(pfVmStartupScriptConfiguration, each_pfVmStartupScriptConfiguration); output["VmStartupScriptConfiguration"] = each_pfVmStartupScriptConfiguration;
                return output;
            }
        };

        struct CreateBuildWithProcessBasedServerRequest : public PlayFabRequestCommon
        {
            Boxed<bool> AreAssetsReadonly;
            std::string BuildName;
            std::map<std::string, std::string> CustomTags;
            std::list<AssetReferenceParams> GameAssetReferences;
            std::list<GameCertificateReferenceParams> GameCertificateReferences;
            std::list<GameSecretReferenceParams> GameSecretReferences;
            std::string GameWorkingDirectory;
            Boxed<InstrumentationConfiguration> pfInstrumentationConfiguration;
            Boxed<bool> IsOSPreview;
            Boxed<LinuxInstrumentationConfiguration> pfLinuxInstrumentationConfiguration;
            std::map<std::string, std::string> Metadata;
            Boxed<MonitoringApplicationConfigurationParams> MonitoringApplicationConfiguration;
            Int32 MultiplayerServerCountPerVm;
            std::string OsPlatform;
            std::list<Port> Ports;
            std::list<BuildRegionParams> RegionConfigurations;
            std::string StartMultiplayerServerCommand;
            Boxed<AzureVmSize> VmSize;
            Boxed<VmStartupScriptParams> VmStartupScriptConfiguration;

            CreateBuildWithProcessBasedServerRequest() :
                PlayFabRequestCommon(),
                AreAssetsReadonly(),
                BuildName(),
                CustomTags(),
                GameAssetReferences(),
                GameCertificateReferences(),
                GameSecretReferences(),
                GameWorkingDirectory(),
                pfInstrumentationConfiguration(),
                IsOSPreview(),
                pfLinuxInstrumentationConfiguration(),
                Metadata(),
                MonitoringApplicationConfiguration(),
                MultiplayerServerCountPerVm(),
                OsPlatform(),
                Ports(),
                RegionConfigurations(),
                StartMultiplayerServerCommand(),
                VmSize(),
                VmStartupScriptConfiguration()
            {}

            CreateBuildWithProcessBasedServerRequest(const CreateBuildWithProcessBasedServerRequest& src) :
                PlayFabRequestCommon(),
                AreAssetsReadonly(src.AreAssetsReadonly),
                BuildName(src.BuildName),
                CustomTags(src.CustomTags),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                GameSecretReferences(src.GameSecretReferences),
                GameWorkingDirectory(src.GameWorkingDirectory),
                pfInstrumentationConfiguration(src.pfInstrumentationConfiguration),
                IsOSPreview(src.IsOSPreview),
                pfLinuxInstrumentationConfiguration(src.pfLinuxInstrumentationConfiguration),
                Metadata(src.Metadata),
                MonitoringApplicationConfiguration(src.MonitoringApplicationConfiguration),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                OsPlatform(src.OsPlatform),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize),
                VmStartupScriptConfiguration(src.VmStartupScriptConfiguration)
            {}

            ~CreateBuildWithProcessBasedServerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["AreAssetsReadonly"], AreAssetsReadonly);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilO(input["GameSecretReferences"], GameSecretReferences);
                FromJsonUtilS(input["GameWorkingDirectory"], GameWorkingDirectory);
                FromJsonUtilO(input["InstrumentationConfiguration"], pfInstrumentationConfiguration);
                FromJsonUtilP(input["IsOSPreview"], IsOSPreview);
                FromJsonUtilO(input["LinuxInstrumentationConfiguration"], pfLinuxInstrumentationConfiguration);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilO(input["MonitoringApplicationConfiguration"], MonitoringApplicationConfiguration);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilS(input["OsPlatform"], OsPlatform);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilS(input["StartMultiplayerServerCommand"], StartMultiplayerServerCommand);
                FromJsonUtilE(input["VmSize"], VmSize);
                FromJsonUtilO(input["VmStartupScriptConfiguration"], VmStartupScriptConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AreAssetsReadonly; ToJsonUtilP(AreAssetsReadonly, each_AreAssetsReadonly); output["AreAssetsReadonly"] = each_AreAssetsReadonly;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_GameSecretReferences; ToJsonUtilO(GameSecretReferences, each_GameSecretReferences); output["GameSecretReferences"] = each_GameSecretReferences;
                Json::Value each_GameWorkingDirectory; ToJsonUtilS(GameWorkingDirectory, each_GameWorkingDirectory); output["GameWorkingDirectory"] = each_GameWorkingDirectory;
                Json::Value each_pfInstrumentationConfiguration; ToJsonUtilO(pfInstrumentationConfiguration, each_pfInstrumentationConfiguration); output["InstrumentationConfiguration"] = each_pfInstrumentationConfiguration;
                Json::Value each_IsOSPreview; ToJsonUtilP(IsOSPreview, each_IsOSPreview); output["IsOSPreview"] = each_IsOSPreview;
                Json::Value each_pfLinuxInstrumentationConfiguration; ToJsonUtilO(pfLinuxInstrumentationConfiguration, each_pfLinuxInstrumentationConfiguration); output["LinuxInstrumentationConfiguration"] = each_pfLinuxInstrumentationConfiguration;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_MonitoringApplicationConfiguration; ToJsonUtilO(MonitoringApplicationConfiguration, each_MonitoringApplicationConfiguration); output["MonitoringApplicationConfiguration"] = each_MonitoringApplicationConfiguration;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_OsPlatform; ToJsonUtilS(OsPlatform, each_OsPlatform); output["OsPlatform"] = each_OsPlatform;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_StartMultiplayerServerCommand; ToJsonUtilS(StartMultiplayerServerCommand, each_StartMultiplayerServerCommand); output["StartMultiplayerServerCommand"] = each_StartMultiplayerServerCommand;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                Json::Value each_VmStartupScriptConfiguration; ToJsonUtilO(VmStartupScriptConfiguration, each_VmStartupScriptConfiguration); output["VmStartupScriptConfiguration"] = each_VmStartupScriptConfiguration;
                return output;
            }
        };

        struct CreateBuildWithProcessBasedServerResponse : public PlayFabResultCommon
        {
            Boxed<bool> AreAssetsReadonly;
            std::string BuildId;
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            Boxed<time_t> CreationTime;
            std::list<AssetReference> GameAssetReferences;
            std::list<GameCertificateReference> GameCertificateReferences;
            std::list<GameSecretReference> GameSecretReferences;
            std::string GameWorkingDirectory;
            Boxed<InstrumentationConfiguration> pfInstrumentationConfiguration;
            Boxed<bool> IsOSPreview;
            Boxed<LinuxInstrumentationConfiguration> pfLinuxInstrumentationConfiguration;
            std::map<std::string, std::string> Metadata;
            Boxed<MonitoringApplicationConfiguration> pfMonitoringApplicationConfiguration;
            Int32 MultiplayerServerCountPerVm;
            std::string OsPlatform;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            std::string ServerType;
            std::string StartMultiplayerServerCommand;
            Boxed<bool> UseStreamingForAssetDownloads;
            Boxed<AzureVmSize> VmSize;
            Boxed<VmStartupScriptConfiguration> pfVmStartupScriptConfiguration;

            CreateBuildWithProcessBasedServerResponse() :
                PlayFabResultCommon(),
                AreAssetsReadonly(),
                BuildId(),
                BuildName(),
                pfContainerFlavor(),
                CreationTime(),
                GameAssetReferences(),
                GameCertificateReferences(),
                GameSecretReferences(),
                GameWorkingDirectory(),
                pfInstrumentationConfiguration(),
                IsOSPreview(),
                pfLinuxInstrumentationConfiguration(),
                Metadata(),
                pfMonitoringApplicationConfiguration(),
                MultiplayerServerCountPerVm(),
                OsPlatform(),
                Ports(),
                RegionConfigurations(),
                ServerType(),
                StartMultiplayerServerCommand(),
                UseStreamingForAssetDownloads(),
                VmSize(),
                pfVmStartupScriptConfiguration()
            {}

            CreateBuildWithProcessBasedServerResponse(const CreateBuildWithProcessBasedServerResponse& src) :
                PlayFabResultCommon(),
                AreAssetsReadonly(src.AreAssetsReadonly),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                CreationTime(src.CreationTime),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                GameSecretReferences(src.GameSecretReferences),
                GameWorkingDirectory(src.GameWorkingDirectory),
                pfInstrumentationConfiguration(src.pfInstrumentationConfiguration),
                IsOSPreview(src.IsOSPreview),
                pfLinuxInstrumentationConfiguration(src.pfLinuxInstrumentationConfiguration),
                Metadata(src.Metadata),
                pfMonitoringApplicationConfiguration(src.pfMonitoringApplicationConfiguration),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                OsPlatform(src.OsPlatform),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                ServerType(src.ServerType),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                UseStreamingForAssetDownloads(src.UseStreamingForAssetDownloads),
                VmSize(src.VmSize),
                pfVmStartupScriptConfiguration(src.pfVmStartupScriptConfiguration)
            {}

            ~CreateBuildWithProcessBasedServerResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["AreAssetsReadonly"], AreAssetsReadonly);
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilE(input["ContainerFlavor"], pfContainerFlavor);
                FromJsonUtilT(input["CreationTime"], CreationTime);
                FromJsonUtilO(input["GameAssetReferences"], GameAssetReferences);
                FromJsonUtilO(input["GameCertificateReferences"], GameCertificateReferences);
                FromJsonUtilO(input["GameSecretReferences"], GameSecretReferences);
                FromJsonUtilS(input["GameWorkingDirectory"], GameWorkingDirectory);
                FromJsonUtilO(input["InstrumentationConfiguration"], pfInstrumentationConfiguration);
                FromJsonUtilP(input["IsOSPreview"], IsOSPreview);
                FromJsonUtilO(input["LinuxInstrumentationConfiguration"], pfLinuxInstrumentationConfiguration);
                FromJsonUtilS(input["Metadata"], Metadata);
                FromJsonUtilO(input["MonitoringApplicationConfiguration"], pfMonitoringApplicationConfiguration);
                FromJsonUtilP(input["MultiplayerServerCountPerVm"], MultiplayerServerCountPerVm);
                FromJsonUtilS(input["OsPlatform"], OsPlatform);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilS(input["ServerType"], ServerType);
                FromJsonUtilS(input["StartMultiplayerServerCommand"], StartMultiplayerServerCommand);
                FromJsonUtilP(input["UseStreamingForAssetDownloads"], UseStreamingForAssetDownloads);
                FromJsonUtilE(input["VmSize"], VmSize);
                FromJsonUtilO(input["VmStartupScriptConfiguration"], pfVmStartupScriptConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AreAssetsReadonly; ToJsonUtilP(AreAssetsReadonly, each_AreAssetsReadonly); output["AreAssetsReadonly"] = each_AreAssetsReadonly;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_pfContainerFlavor; ToJsonUtilE(pfContainerFlavor, each_pfContainerFlavor); output["ContainerFlavor"] = each_pfContainerFlavor;
                Json::Value each_CreationTime; ToJsonUtilT(CreationTime, each_CreationTime); output["CreationTime"] = each_CreationTime;
                Json::Value each_GameAssetReferences; ToJsonUtilO(GameAssetReferences, each_GameAssetReferences); output["GameAssetReferences"] = each_GameAssetReferences;
                Json::Value each_GameCertificateReferences; ToJsonUtilO(GameCertificateReferences, each_GameCertificateReferences); output["GameCertificateReferences"] = each_GameCertificateReferences;
                Json::Value each_GameSecretReferences; ToJsonUtilO(GameSecretReferences, each_GameSecretReferences); output["GameSecretReferences"] = each_GameSecretReferences;
                Json::Value each_GameWorkingDirectory; ToJsonUtilS(GameWorkingDirectory, each_GameWorkingDirectory); output["GameWorkingDirectory"] = each_GameWorkingDirectory;
                Json::Value each_pfInstrumentationConfiguration; ToJsonUtilO(pfInstrumentationConfiguration, each_pfInstrumentationConfiguration); output["InstrumentationConfiguration"] = each_pfInstrumentationConfiguration;
                Json::Value each_IsOSPreview; ToJsonUtilP(IsOSPreview, each_IsOSPreview); output["IsOSPreview"] = each_IsOSPreview;
                Json::Value each_pfLinuxInstrumentationConfiguration; ToJsonUtilO(pfLinuxInstrumentationConfiguration, each_pfLinuxInstrumentationConfiguration); output["LinuxInstrumentationConfiguration"] = each_pfLinuxInstrumentationConfiguration;
                Json::Value each_Metadata; ToJsonUtilS(Metadata, each_Metadata); output["Metadata"] = each_Metadata;
                Json::Value each_pfMonitoringApplicationConfiguration; ToJsonUtilO(pfMonitoringApplicationConfiguration, each_pfMonitoringApplicationConfiguration); output["MonitoringApplicationConfiguration"] = each_pfMonitoringApplicationConfiguration;
                Json::Value each_MultiplayerServerCountPerVm; ToJsonUtilP(MultiplayerServerCountPerVm, each_MultiplayerServerCountPerVm); output["MultiplayerServerCountPerVm"] = each_MultiplayerServerCountPerVm;
                Json::Value each_OsPlatform; ToJsonUtilS(OsPlatform, each_OsPlatform); output["OsPlatform"] = each_OsPlatform;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_ServerType; ToJsonUtilS(ServerType, each_ServerType); output["ServerType"] = each_ServerType;
                Json::Value each_StartMultiplayerServerCommand; ToJsonUtilS(StartMultiplayerServerCommand, each_StartMultiplayerServerCommand); output["StartMultiplayerServerCommand"] = each_StartMultiplayerServerCommand;
                Json::Value each_UseStreamingForAssetDownloads; ToJsonUtilP(UseStreamingForAssetDownloads, each_UseStreamingForAssetDownloads); output["UseStreamingForAssetDownloads"] = each_UseStreamingForAssetDownloads;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                Json::Value each_pfVmStartupScriptConfiguration; ToJsonUtilO(pfVmStartupScriptConfiguration, each_pfVmStartupScriptConfiguration); output["VmStartupScriptConfiguration"] = each_pfVmStartupScriptConfiguration;
                return output;
            }
        };

        struct Member : public PlayFabBaseModel
        {
            std::map<std::string, std::string> MemberData;
            Boxed<EntityKey> MemberEntity;
            std::string PubSubConnectionHandle;

            Member() :
                PlayFabBaseModel(),
                MemberData(),
                MemberEntity(),
                PubSubConnectionHandle()
            {}

            Member(const Member& src) :
                PlayFabBaseModel(),
                MemberData(src.MemberData),
                MemberEntity(src.MemberEntity),
                PubSubConnectionHandle(src.PubSubConnectionHandle)
            {}

            ~Member() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["MemberData"], MemberData);
                FromJsonUtilO(input["MemberEntity"], MemberEntity);
                FromJsonUtilS(input["PubSubConnectionHandle"], PubSubConnectionHandle);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MemberData; ToJsonUtilS(MemberData, each_MemberData); output["MemberData"] = each_MemberData;
                Json::Value each_MemberEntity; ToJsonUtilO(MemberEntity, each_MemberEntity); output["MemberEntity"] = each_MemberEntity;
                Json::Value each_PubSubConnectionHandle; ToJsonUtilS(PubSubConnectionHandle, each_PubSubConnectionHandle); output["PubSubConnectionHandle"] = each_PubSubConnectionHandle;
                return output;
            }
        };

        struct CreateLobbyRequest : public PlayFabRequestCommon
        {
            Boxed<AccessPolicy> pfAccessPolicy;
            std::map<std::string, std::string> CustomTags;
            std::map<std::string, std::string> LobbyData;
            Uint32 MaxPlayers;
            std::list<Member> Members;
            EntityKey Owner;
            Boxed<OwnerMigrationPolicy> pfOwnerMigrationPolicy;
            bool RestrictInvitesToLobbyOwner;
            std::map<std::string, std::string> SearchData;
            bool UseConnections;

            CreateLobbyRequest() :
                PlayFabRequestCommon(),
                pfAccessPolicy(),
                CustomTags(),
                LobbyData(),
                MaxPlayers(),
                Members(),
                Owner(),
                pfOwnerMigrationPolicy(),
                RestrictInvitesToLobbyOwner(),
                SearchData(),
                UseConnections()
            {}

            CreateLobbyRequest(const CreateLobbyRequest& src) :
                PlayFabRequestCommon(),
                pfAccessPolicy(src.pfAccessPolicy),
                CustomTags(src.CustomTags),
                LobbyData(src.LobbyData),
                MaxPlayers(src.MaxPlayers),
                Members(src.Members),
                Owner(src.Owner),
                pfOwnerMigrationPolicy(src.pfOwnerMigrationPolicy),
                RestrictInvitesToLobbyOwner(src.RestrictInvitesToLobbyOwner),
                SearchData(src.SearchData),
                UseConnections(src.UseConnections)
            {}

            ~CreateLobbyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilE(input["AccessPolicy"], pfAccessPolicy);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["LobbyData"], LobbyData);
                FromJsonUtilP(input["MaxPlayers"], MaxPlayers);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilO(input["Owner"], Owner);
                FromJsonUtilE(input["OwnerMigrationPolicy"], pfOwnerMigrationPolicy);
                FromJsonUtilP(input["RestrictInvitesToLobbyOwner"], RestrictInvitesToLobbyOwner);
                FromJsonUtilS(input["SearchData"], SearchData);
                FromJsonUtilP(input["UseConnections"], UseConnections);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfAccessPolicy; ToJsonUtilE(pfAccessPolicy, each_pfAccessPolicy); output["AccessPolicy"] = each_pfAccessPolicy;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_LobbyData; ToJsonUtilS(LobbyData, each_LobbyData); output["LobbyData"] = each_LobbyData;
                Json::Value each_MaxPlayers; ToJsonUtilP(MaxPlayers, each_MaxPlayers); output["MaxPlayers"] = each_MaxPlayers;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_Owner; ToJsonUtilO(Owner, each_Owner); output["Owner"] = each_Owner;
                Json::Value each_pfOwnerMigrationPolicy; ToJsonUtilE(pfOwnerMigrationPolicy, each_pfOwnerMigrationPolicy); output["OwnerMigrationPolicy"] = each_pfOwnerMigrationPolicy;
                Json::Value each_RestrictInvitesToLobbyOwner; ToJsonUtilP(RestrictInvitesToLobbyOwner, each_RestrictInvitesToLobbyOwner); output["RestrictInvitesToLobbyOwner"] = each_RestrictInvitesToLobbyOwner;
                Json::Value each_SearchData; ToJsonUtilS(SearchData, each_SearchData); output["SearchData"] = each_SearchData;
                Json::Value each_UseConnections; ToJsonUtilP(UseConnections, each_UseConnections); output["UseConnections"] = each_UseConnections;
                return output;
            }
        };

        struct CreateLobbyResult : public PlayFabResultCommon
        {
            std::string ConnectionString;
            std::string LobbyId;

            CreateLobbyResult() :
                PlayFabResultCommon(),
                ConnectionString(),
                LobbyId()
            {}

            CreateLobbyResult(const CreateLobbyResult& src) :
                PlayFabResultCommon(),
                ConnectionString(src.ConnectionString),
                LobbyId(src.LobbyId)
            {}

            ~CreateLobbyResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ConnectionString"], ConnectionString);
                FromJsonUtilS(input["LobbyId"], LobbyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionString; ToJsonUtilS(ConnectionString, each_ConnectionString); output["ConnectionString"] = each_ConnectionString;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
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
            std::map<std::string, std::string> CustomTags;
            Int32 GiveUpAfterSeconds;
            std::list<EntityKey> MembersToMatchWith;
            std::string QueueName;

            CreateMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                Creator(),
                CustomTags(),
                GiveUpAfterSeconds(),
                MembersToMatchWith(),
                QueueName()
            {}

            CreateMatchmakingTicketRequest(const CreateMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                Creator(src.Creator),
                CustomTags(src.CustomTags),
                GiveUpAfterSeconds(src.GiveUpAfterSeconds),
                MembersToMatchWith(src.MembersToMatchWith),
                QueueName(src.QueueName)
            {}

            ~CreateMatchmakingTicketRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Creator"], Creator);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["GiveUpAfterSeconds"], GiveUpAfterSeconds);
                FromJsonUtilO(input["MembersToMatchWith"], MembersToMatchWith);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Creator; ToJsonUtilO(Creator, each_Creator); output["Creator"] = each_Creator;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::map<std::string, std::string> CustomTags;
            Boxed<time_t> ExpirationTime;
            std::string Region;
            std::string Username;
            std::string VmId;

            CreateRemoteUserRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                CustomTags(),
                ExpirationTime(),
                Region(),
                Username(),
                VmId()
            {}

            CreateRemoteUserRequest(const CreateRemoteUserRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                CustomTags(src.CustomTags),
                ExpirationTime(src.ExpirationTime),
                Region(src.Region),
                Username(src.Username),
                VmId(src.VmId)
            {}

            ~CreateRemoteUserRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilT(input["ExpirationTime"], ExpirationTime);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["Username"], Username);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::string Fqdn;
            std::string IPV4Address;
            std::list<Port> Ports;
            std::string Region;
            std::string ServerId;

            ServerDetails() :
                PlayFabBaseModel(),
                Fqdn(),
                IPV4Address(),
                Ports(),
                Region(),
                ServerId()
            {}

            ServerDetails(const ServerDetails& src) :
                PlayFabBaseModel(),
                Fqdn(src.Fqdn),
                IPV4Address(src.IPV4Address),
                Ports(src.Ports),
                Region(src.Region),
                ServerId(src.ServerId)
            {}

            ~ServerDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Fqdn"], Fqdn);
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["ServerId"], ServerId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Fqdn; ToJsonUtilS(Fqdn, each_Fqdn); output["Fqdn"] = each_Fqdn;
                Json::Value each_IPV4Address; ToJsonUtilS(IPV4Address, each_IPV4Address); output["IPV4Address"] = each_IPV4Address;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_ServerId; ToJsonUtilS(ServerId, each_ServerId); output["ServerId"] = each_ServerId;
                return output;
            }
        };

        struct CreateServerBackfillTicketRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Int32 GiveUpAfterSeconds;
            std::list<MatchmakingPlayerWithTeamAssignment> Members;
            std::string QueueName;
            Boxed<ServerDetails> pfServerDetails;

            CreateServerBackfillTicketRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                GiveUpAfterSeconds(),
                Members(),
                QueueName(),
                pfServerDetails()
            {}

            CreateServerBackfillTicketRequest(const CreateServerBackfillTicketRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                GiveUpAfterSeconds(src.GiveUpAfterSeconds),
                Members(src.Members),
                QueueName(src.QueueName),
                pfServerDetails(src.pfServerDetails)
            {}

            ~CreateServerBackfillTicketRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["GiveUpAfterSeconds"], GiveUpAfterSeconds);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilO(input["ServerDetails"], pfServerDetails);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_GiveUpAfterSeconds; ToJsonUtilP(GiveUpAfterSeconds, each_GiveUpAfterSeconds); output["GiveUpAfterSeconds"] = each_GiveUpAfterSeconds;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_pfServerDetails; ToJsonUtilO(pfServerDetails, each_pfServerDetails); output["ServerDetails"] = each_pfServerDetails;
                return output;
            }
        };

        struct CreateServerBackfillTicketResult : public PlayFabResultCommon
        {
            std::string TicketId;

            CreateServerBackfillTicketResult() :
                PlayFabResultCommon(),
                TicketId()
            {}

            CreateServerBackfillTicketResult(const CreateServerBackfillTicketResult& src) :
                PlayFabResultCommon(),
                TicketId(src.TicketId)
            {}

            ~CreateServerBackfillTicketResult() = default;

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

        struct CreateServerMatchmakingTicketRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Int32 GiveUpAfterSeconds;
            std::list<MatchmakingPlayer> Members;
            std::string QueueName;

            CreateServerMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                GiveUpAfterSeconds(),
                Members(),
                QueueName()
            {}

            CreateServerMatchmakingTicketRequest(const CreateServerMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                GiveUpAfterSeconds(src.GiveUpAfterSeconds),
                Members(src.Members),
                QueueName(src.QueueName)
            {}

            ~CreateServerMatchmakingTicketRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["GiveUpAfterSeconds"], GiveUpAfterSeconds);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_GiveUpAfterSeconds; ToJsonUtilP(GiveUpAfterSeconds, each_GiveUpAfterSeconds); output["GiveUpAfterSeconds"] = each_GiveUpAfterSeconds;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct CreateTitleMultiplayerServersQuotaChangeRequest : public PlayFabRequestCommon
        {
            std::string ChangeDescription;
            std::list<CoreCapacityChange> Changes;
            std::string ContactEmail;
            std::map<std::string, std::string> CustomTags;
            std::string Notes;
            Boxed<time_t> StartDate;

            CreateTitleMultiplayerServersQuotaChangeRequest() :
                PlayFabRequestCommon(),
                ChangeDescription(),
                Changes(),
                ContactEmail(),
                CustomTags(),
                Notes(),
                StartDate()
            {}

            CreateTitleMultiplayerServersQuotaChangeRequest(const CreateTitleMultiplayerServersQuotaChangeRequest& src) :
                PlayFabRequestCommon(),
                ChangeDescription(src.ChangeDescription),
                Changes(src.Changes),
                ContactEmail(src.ContactEmail),
                CustomTags(src.CustomTags),
                Notes(src.Notes),
                StartDate(src.StartDate)
            {}

            ~CreateTitleMultiplayerServersQuotaChangeRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChangeDescription"], ChangeDescription);
                FromJsonUtilO(input["Changes"], Changes);
                FromJsonUtilS(input["ContactEmail"], ContactEmail);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Notes"], Notes);
                FromJsonUtilT(input["StartDate"], StartDate);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChangeDescription; ToJsonUtilS(ChangeDescription, each_ChangeDescription); output["ChangeDescription"] = each_ChangeDescription;
                Json::Value each_Changes; ToJsonUtilO(Changes, each_Changes); output["Changes"] = each_Changes;
                Json::Value each_ContactEmail; ToJsonUtilS(ContactEmail, each_ContactEmail); output["ContactEmail"] = each_ContactEmail;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Notes; ToJsonUtilS(Notes, each_Notes); output["Notes"] = each_Notes;
                Json::Value each_StartDate; ToJsonUtilT(StartDate, each_StartDate); output["StartDate"] = each_StartDate;
                return output;
            }
        };

        struct CreateTitleMultiplayerServersQuotaChangeResponse : public PlayFabResultCommon
        {
            std::string RequestId;
            bool WasApproved;

            CreateTitleMultiplayerServersQuotaChangeResponse() :
                PlayFabResultCommon(),
                RequestId(),
                WasApproved()
            {}

            CreateTitleMultiplayerServersQuotaChangeResponse(const CreateTitleMultiplayerServersQuotaChangeResponse& src) :
                PlayFabResultCommon(),
                RequestId(src.RequestId),
                WasApproved(src.WasApproved)
            {}

            ~CreateTitleMultiplayerServersQuotaChangeResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["RequestId"], RequestId);
                FromJsonUtilP(input["WasApproved"], WasApproved);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_RequestId; ToJsonUtilS(RequestId, each_RequestId); output["RequestId"] = each_RequestId;
                Json::Value each_WasApproved; ToJsonUtilP(WasApproved, each_WasApproved); output["WasApproved"] = each_WasApproved;
                return output;
            }
        };

        struct DeleteAssetRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string FileName;

            DeleteAssetRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                FileName()
            {}

            DeleteAssetRequest(const DeleteAssetRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                FileName(src.FileName)
            {}

            ~DeleteAssetRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["FileName"], FileName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                return output;
            }
        };

        struct DeleteBuildAliasRequest : public PlayFabRequestCommon
        {
            std::string AliasId;
            std::map<std::string, std::string> CustomTags;

            DeleteBuildAliasRequest() :
                PlayFabRequestCommon(),
                AliasId(),
                CustomTags()
            {}

            DeleteBuildAliasRequest(const DeleteBuildAliasRequest& src) :
                PlayFabRequestCommon(),
                AliasId(src.AliasId),
                CustomTags(src.CustomTags)
            {}

            ~DeleteBuildAliasRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasId"], AliasId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasId; ToJsonUtilS(AliasId, each_AliasId); output["AliasId"] = each_AliasId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct DeleteBuildRegionRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::map<std::string, std::string> CustomTags;
            std::string Region;

            DeleteBuildRegionRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                CustomTags(),
                Region()
            {}

            DeleteBuildRegionRequest(const DeleteBuildRegionRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                CustomTags(src.CustomTags),
                Region(src.Region)
            {}

            ~DeleteBuildRegionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Region"], Region);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                return output;
            }
        };

        struct DeleteBuildRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::map<std::string, std::string> CustomTags;

            DeleteBuildRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                CustomTags()
            {}

            DeleteBuildRequest(const DeleteBuildRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                CustomTags(src.CustomTags)
            {}

            ~DeleteBuildRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct DeleteCertificateRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            DeleteCertificateRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            DeleteCertificateRequest(const DeleteCertificateRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~DeleteCertificateRequest() = default;

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

        struct DeleteContainerImageRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string ImageName;

            DeleteContainerImageRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                ImageName()
            {}

            DeleteContainerImageRequest(const DeleteContainerImageRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                ImageName(src.ImageName)
            {}

            ~DeleteContainerImageRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["ImageName"], ImageName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_ImageName; ToJsonUtilS(ImageName, each_ImageName); output["ImageName"] = each_ImageName;
                return output;
            }
        };

        struct DeleteLobbyRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string LobbyId;

            DeleteLobbyRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                LobbyId()
            {}

            DeleteLobbyRequest(const DeleteLobbyRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                LobbyId(src.LobbyId)
            {}

            ~DeleteLobbyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["LobbyId"], LobbyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                return output;
            }
        };

        struct DeleteRemoteUserRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::map<std::string, std::string> CustomTags;
            std::string Region;
            std::string Username;
            std::string VmId;

            DeleteRemoteUserRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                CustomTags(),
                Region(),
                Username(),
                VmId()
            {}

            DeleteRemoteUserRequest(const DeleteRemoteUserRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                CustomTags(src.CustomTags),
                Region(src.Region),
                Username(src.Username),
                VmId(src.VmId)
            {}

            ~DeleteRemoteUserRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["Username"], Username);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_Username; ToJsonUtilS(Username, each_Username); output["Username"] = each_Username;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
                return output;
            }
        };

        struct DeleteSecretRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            DeleteSecretRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            DeleteSecretRequest(const DeleteSecretRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~DeleteSecretRequest() = default;

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
            std::map<std::string, std::string> CustomTags;

            EnableMultiplayerServersForTitleRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            EnableMultiplayerServersForTitleRequest(const EnableMultiplayerServersForTitleRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~EnableMultiplayerServersForTitleRequest() = default;

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

        struct PaginationRequest : public PlayFabRequestCommon
        {
            std::string ContinuationToken;
            Boxed<Uint32> PageSizeRequested;

            PaginationRequest() :
                PlayFabRequestCommon(),
                ContinuationToken(),
                PageSizeRequested()
            {}

            PaginationRequest(const PaginationRequest& src) :
                PlayFabRequestCommon(),
                ContinuationToken(src.ContinuationToken),
                PageSizeRequested(src.PageSizeRequested)
            {}

            ~PaginationRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["PageSizeRequested"], PageSizeRequested);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_PageSizeRequested; ToJsonUtilP(PageSizeRequested, each_PageSizeRequested); output["PageSizeRequested"] = each_PageSizeRequested;
                return output;
            }
        };

        struct FindFriendLobbiesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<ExternalFriendSources> ExternalPlatformFriends;
            std::string Filter;
            std::string OrderBy;
            Boxed<PaginationRequest> Pagination;
            std::string XboxToken;

            FindFriendLobbiesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                ExternalPlatformFriends(),
                Filter(),
                OrderBy(),
                Pagination(),
                XboxToken()
            {}

            FindFriendLobbiesRequest(const FindFriendLobbiesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                ExternalPlatformFriends(src.ExternalPlatformFriends),
                Filter(src.Filter),
                OrderBy(src.OrderBy),
                Pagination(src.Pagination),
                XboxToken(src.XboxToken)
            {}

            ~FindFriendLobbiesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilE(input["ExternalPlatformFriends"], ExternalPlatformFriends);
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilO(input["Pagination"], Pagination);
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_ExternalPlatformFriends; ToJsonUtilE(ExternalPlatformFriends, each_ExternalPlatformFriends); output["ExternalPlatformFriends"] = each_ExternalPlatformFriends;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Pagination; ToJsonUtilO(Pagination, each_Pagination); output["Pagination"] = each_Pagination;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct FriendLobbySummary : public PlayFabBaseModel
        {
            std::string ConnectionString;
            Uint32 CurrentPlayers;
            std::list<EntityKey> Friends;
            std::string LobbyId;
            Uint32 MaxPlayers;
            Boxed<MembershipLock> pfMembershipLock;
            EntityKey Owner;
            std::map<std::string, std::string> SearchData;

            FriendLobbySummary() :
                PlayFabBaseModel(),
                ConnectionString(),
                CurrentPlayers(),
                Friends(),
                LobbyId(),
                MaxPlayers(),
                pfMembershipLock(),
                Owner(),
                SearchData()
            {}

            FriendLobbySummary(const FriendLobbySummary& src) :
                PlayFabBaseModel(),
                ConnectionString(src.ConnectionString),
                CurrentPlayers(src.CurrentPlayers),
                Friends(src.Friends),
                LobbyId(src.LobbyId),
                MaxPlayers(src.MaxPlayers),
                pfMembershipLock(src.pfMembershipLock),
                Owner(src.Owner),
                SearchData(src.SearchData)
            {}

            ~FriendLobbySummary() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ConnectionString"], ConnectionString);
                FromJsonUtilP(input["CurrentPlayers"], CurrentPlayers);
                FromJsonUtilO(input["Friends"], Friends);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilP(input["MaxPlayers"], MaxPlayers);
                FromJsonUtilE(input["MembershipLock"], pfMembershipLock);
                FromJsonUtilO(input["Owner"], Owner);
                FromJsonUtilS(input["SearchData"], SearchData);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionString; ToJsonUtilS(ConnectionString, each_ConnectionString); output["ConnectionString"] = each_ConnectionString;
                Json::Value each_CurrentPlayers; ToJsonUtilP(CurrentPlayers, each_CurrentPlayers); output["CurrentPlayers"] = each_CurrentPlayers;
                Json::Value each_Friends; ToJsonUtilO(Friends, each_Friends); output["Friends"] = each_Friends;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_MaxPlayers; ToJsonUtilP(MaxPlayers, each_MaxPlayers); output["MaxPlayers"] = each_MaxPlayers;
                Json::Value each_pfMembershipLock; ToJsonUtilE(pfMembershipLock, each_pfMembershipLock); output["MembershipLock"] = each_pfMembershipLock;
                Json::Value each_Owner; ToJsonUtilO(Owner, each_Owner); output["Owner"] = each_Owner;
                Json::Value each_SearchData; ToJsonUtilS(SearchData, each_SearchData); output["SearchData"] = each_SearchData;
                return output;
            }
        };

        struct PaginationResponse : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            Boxed<Uint32> TotalMatchedLobbyCount;

            PaginationResponse() :
                PlayFabResultCommon(),
                ContinuationToken(),
                TotalMatchedLobbyCount()
            {}

            PaginationResponse(const PaginationResponse& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                TotalMatchedLobbyCount(src.TotalMatchedLobbyCount)
            {}

            ~PaginationResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["TotalMatchedLobbyCount"], TotalMatchedLobbyCount);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_TotalMatchedLobbyCount; ToJsonUtilP(TotalMatchedLobbyCount, each_TotalMatchedLobbyCount); output["TotalMatchedLobbyCount"] = each_TotalMatchedLobbyCount;
                return output;
            }
        };

        struct FindFriendLobbiesResult : public PlayFabResultCommon
        {
            std::list<FriendLobbySummary> Lobbies;
            PaginationResponse Pagination;

            FindFriendLobbiesResult() :
                PlayFabResultCommon(),
                Lobbies(),
                Pagination()
            {}

            FindFriendLobbiesResult(const FindFriendLobbiesResult& src) :
                PlayFabResultCommon(),
                Lobbies(src.Lobbies),
                Pagination(src.Pagination)
            {}

            ~FindFriendLobbiesResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Lobbies"], Lobbies);
                FromJsonUtilO(input["Pagination"], Pagination);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Lobbies; ToJsonUtilO(Lobbies, each_Lobbies); output["Lobbies"] = each_Lobbies;
                Json::Value each_Pagination; ToJsonUtilO(Pagination, each_Pagination); output["Pagination"] = each_Pagination;
                return output;
            }
        };

        struct FindLobbiesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Filter;
            std::string OrderBy;
            Boxed<PaginationRequest> Pagination;

            FindLobbiesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Filter(),
                OrderBy(),
                Pagination()
            {}

            FindLobbiesRequest(const FindLobbiesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Filter(src.Filter),
                OrderBy(src.OrderBy),
                Pagination(src.Pagination)
            {}

            ~FindLobbiesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilO(input["Pagination"], Pagination);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Pagination; ToJsonUtilO(Pagination, each_Pagination); output["Pagination"] = each_Pagination;
                return output;
            }
        };

        struct LobbySummary : public PlayFabBaseModel
        {
            std::string ConnectionString;
            Uint32 CurrentPlayers;
            std::string LobbyId;
            Uint32 MaxPlayers;
            Boxed<MembershipLock> pfMembershipLock;
            EntityKey Owner;
            std::map<std::string, std::string> SearchData;

            LobbySummary() :
                PlayFabBaseModel(),
                ConnectionString(),
                CurrentPlayers(),
                LobbyId(),
                MaxPlayers(),
                pfMembershipLock(),
                Owner(),
                SearchData()
            {}

            LobbySummary(const LobbySummary& src) :
                PlayFabBaseModel(),
                ConnectionString(src.ConnectionString),
                CurrentPlayers(src.CurrentPlayers),
                LobbyId(src.LobbyId),
                MaxPlayers(src.MaxPlayers),
                pfMembershipLock(src.pfMembershipLock),
                Owner(src.Owner),
                SearchData(src.SearchData)
            {}

            ~LobbySummary() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ConnectionString"], ConnectionString);
                FromJsonUtilP(input["CurrentPlayers"], CurrentPlayers);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilP(input["MaxPlayers"], MaxPlayers);
                FromJsonUtilE(input["MembershipLock"], pfMembershipLock);
                FromJsonUtilO(input["Owner"], Owner);
                FromJsonUtilS(input["SearchData"], SearchData);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionString; ToJsonUtilS(ConnectionString, each_ConnectionString); output["ConnectionString"] = each_ConnectionString;
                Json::Value each_CurrentPlayers; ToJsonUtilP(CurrentPlayers, each_CurrentPlayers); output["CurrentPlayers"] = each_CurrentPlayers;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_MaxPlayers; ToJsonUtilP(MaxPlayers, each_MaxPlayers); output["MaxPlayers"] = each_MaxPlayers;
                Json::Value each_pfMembershipLock; ToJsonUtilE(pfMembershipLock, each_pfMembershipLock); output["MembershipLock"] = each_pfMembershipLock;
                Json::Value each_Owner; ToJsonUtilO(Owner, each_Owner); output["Owner"] = each_Owner;
                Json::Value each_SearchData; ToJsonUtilS(SearchData, each_SearchData); output["SearchData"] = each_SearchData;
                return output;
            }
        };

        struct FindLobbiesResult : public PlayFabResultCommon
        {
            std::list<LobbySummary> Lobbies;
            PaginationResponse Pagination;

            FindLobbiesResult() :
                PlayFabResultCommon(),
                Lobbies(),
                Pagination()
            {}

            FindLobbiesResult(const FindLobbiesResult& src) :
                PlayFabResultCommon(),
                Lobbies(src.Lobbies),
                Pagination(src.Pagination)
            {}

            ~FindLobbiesResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Lobbies"], Lobbies);
                FromJsonUtilO(input["Pagination"], Pagination);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Lobbies; ToJsonUtilO(Lobbies, each_Lobbies); output["Lobbies"] = each_Lobbies;
                Json::Value each_Pagination; ToJsonUtilO(Pagination, each_Pagination); output["Pagination"] = each_Pagination;
                return output;
            }
        };

        struct GetAssetDownloadUrlRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string FileName;

            GetAssetDownloadUrlRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                FileName()
            {}

            GetAssetDownloadUrlRequest(const GetAssetDownloadUrlRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                FileName(src.FileName)
            {}

            ~GetAssetDownloadUrlRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["FileName"], FileName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                return output;
            }
        };

        struct GetAssetDownloadUrlResponse : public PlayFabResultCommon
        {
            std::string AssetDownloadUrl;
            std::string FileName;

            GetAssetDownloadUrlResponse() :
                PlayFabResultCommon(),
                AssetDownloadUrl(),
                FileName()
            {}

            GetAssetDownloadUrlResponse(const GetAssetDownloadUrlResponse& src) :
                PlayFabResultCommon(),
                AssetDownloadUrl(src.AssetDownloadUrl),
                FileName(src.FileName)
            {}

            ~GetAssetDownloadUrlResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AssetDownloadUrl"], AssetDownloadUrl);
                FromJsonUtilS(input["FileName"], FileName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AssetDownloadUrl; ToJsonUtilS(AssetDownloadUrl, each_AssetDownloadUrl); output["AssetDownloadUrl"] = each_AssetDownloadUrl;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                return output;
            }
        };

        struct GetAssetUploadUrlRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string FileName;

            GetAssetUploadUrlRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                FileName()
            {}

            GetAssetUploadUrlRequest(const GetAssetUploadUrlRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                FileName(src.FileName)
            {}

            ~GetAssetUploadUrlRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["FileName"], FileName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::map<std::string, std::string> CustomTags;

            GetBuildAliasRequest() :
                PlayFabRequestCommon(),
                AliasId(),
                CustomTags()
            {}

            GetBuildAliasRequest(const GetBuildAliasRequest& src) :
                PlayFabRequestCommon(),
                AliasId(src.AliasId),
                CustomTags(src.CustomTags)
            {}

            ~GetBuildAliasRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasId"], AliasId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasId; ToJsonUtilS(AliasId, each_AliasId); output["AliasId"] = each_AliasId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct GetBuildRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::map<std::string, std::string> CustomTags;

            GetBuildRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                CustomTags()
            {}

            GetBuildRequest(const GetBuildRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                CustomTags(src.CustomTags)
            {}

            ~GetBuildRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct GetBuildResponse : public PlayFabResultCommon
        {
            Boxed<bool> AreAssetsReadonly;
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
            std::string OsPlatform;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            Boxed<ServerResourceConstraintParams> ServerResourceConstraints;
            std::string ServerType;
            std::string StartMultiplayerServerCommand;
            Boxed<AzureVmSize> VmSize;
            Boxed<VmStartupScriptConfiguration> pfVmStartupScriptConfiguration;

            GetBuildResponse() :
                PlayFabResultCommon(),
                AreAssetsReadonly(),
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
                OsPlatform(),
                Ports(),
                RegionConfigurations(),
                ServerResourceConstraints(),
                ServerType(),
                StartMultiplayerServerCommand(),
                VmSize(),
                pfVmStartupScriptConfiguration()
            {}

            GetBuildResponse(const GetBuildResponse& src) :
                PlayFabResultCommon(),
                AreAssetsReadonly(src.AreAssetsReadonly),
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
                OsPlatform(src.OsPlatform),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                ServerResourceConstraints(src.ServerResourceConstraints),
                ServerType(src.ServerType),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize),
                pfVmStartupScriptConfiguration(src.pfVmStartupScriptConfiguration)
            {}

            ~GetBuildResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["AreAssetsReadonly"], AreAssetsReadonly);
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
                FromJsonUtilS(input["OsPlatform"], OsPlatform);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["RegionConfigurations"], RegionConfigurations);
                FromJsonUtilO(input["ServerResourceConstraints"], ServerResourceConstraints);
                FromJsonUtilS(input["ServerType"], ServerType);
                FromJsonUtilS(input["StartMultiplayerServerCommand"], StartMultiplayerServerCommand);
                FromJsonUtilE(input["VmSize"], VmSize);
                FromJsonUtilO(input["VmStartupScriptConfiguration"], pfVmStartupScriptConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AreAssetsReadonly; ToJsonUtilP(AreAssetsReadonly, each_AreAssetsReadonly); output["AreAssetsReadonly"] = each_AreAssetsReadonly;
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
                Json::Value each_OsPlatform; ToJsonUtilS(OsPlatform, each_OsPlatform); output["OsPlatform"] = each_OsPlatform;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_RegionConfigurations; ToJsonUtilO(RegionConfigurations, each_RegionConfigurations); output["RegionConfigurations"] = each_RegionConfigurations;
                Json::Value each_ServerResourceConstraints; ToJsonUtilO(ServerResourceConstraints, each_ServerResourceConstraints); output["ServerResourceConstraints"] = each_ServerResourceConstraints;
                Json::Value each_ServerType; ToJsonUtilS(ServerType, each_ServerType); output["ServerType"] = each_ServerType;
                Json::Value each_StartMultiplayerServerCommand; ToJsonUtilS(StartMultiplayerServerCommand, each_StartMultiplayerServerCommand); output["StartMultiplayerServerCommand"] = each_StartMultiplayerServerCommand;
                Json::Value each_VmSize; ToJsonUtilE(VmSize, each_VmSize); output["VmSize"] = each_VmSize;
                Json::Value each_pfVmStartupScriptConfiguration; ToJsonUtilO(pfVmStartupScriptConfiguration, each_pfVmStartupScriptConfiguration); output["VmStartupScriptConfiguration"] = each_pfVmStartupScriptConfiguration;
                return output;
            }
        };

        struct GetContainerRegistryCredentialsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            GetContainerRegistryCredentialsRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            GetContainerRegistryCredentialsRequest(const GetContainerRegistryCredentialsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~GetContainerRegistryCredentialsRequest() = default;

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

        struct GetLobbyRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string LobbyId;

            GetLobbyRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                LobbyId()
            {}

            GetLobbyRequest(const GetLobbyRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                LobbyId(src.LobbyId)
            {}

            ~GetLobbyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["LobbyId"], LobbyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                return output;
            }
        };

        struct LobbyServer : public PlayFabBaseModel
        {
            std::string PubSubConnectionHandle;
            std::map<std::string, std::string> ServerData;
            Boxed<EntityKey> ServerEntity;

            LobbyServer() :
                PlayFabBaseModel(),
                PubSubConnectionHandle(),
                ServerData(),
                ServerEntity()
            {}

            LobbyServer(const LobbyServer& src) :
                PlayFabBaseModel(),
                PubSubConnectionHandle(src.PubSubConnectionHandle),
                ServerData(src.ServerData),
                ServerEntity(src.ServerEntity)
            {}

            ~LobbyServer() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["PubSubConnectionHandle"], PubSubConnectionHandle);
                FromJsonUtilS(input["ServerData"], ServerData);
                FromJsonUtilO(input["ServerEntity"], ServerEntity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PubSubConnectionHandle; ToJsonUtilS(PubSubConnectionHandle, each_PubSubConnectionHandle); output["PubSubConnectionHandle"] = each_PubSubConnectionHandle;
                Json::Value each_ServerData; ToJsonUtilS(ServerData, each_ServerData); output["ServerData"] = each_ServerData;
                Json::Value each_ServerEntity; ToJsonUtilO(ServerEntity, each_ServerEntity); output["ServerEntity"] = each_ServerEntity;
                return output;
            }
        };

        struct Lobby : public PlayFabBaseModel
        {
            AccessPolicy pfAccessPolicy;
            Uint32 ChangeNumber;
            std::string ConnectionString;
            std::map<std::string, std::string> LobbyData;
            std::string LobbyId;
            Uint32 MaxPlayers;
            std::list<Member> Members;
            MembershipLock pfMembershipLock;
            Boxed<EntityKey> Owner;
            Boxed<OwnerMigrationPolicy> pfOwnerMigrationPolicy;
            std::string PubSubConnectionHandle;
            bool RestrictInvitesToLobbyOwner;
            std::map<std::string, std::string> SearchData;
            Boxed<LobbyServer> Server;
            bool UseConnections;

            Lobby() :
                PlayFabBaseModel(),
                pfAccessPolicy(),
                ChangeNumber(),
                ConnectionString(),
                LobbyData(),
                LobbyId(),
                MaxPlayers(),
                Members(),
                pfMembershipLock(),
                Owner(),
                pfOwnerMigrationPolicy(),
                PubSubConnectionHandle(),
                RestrictInvitesToLobbyOwner(),
                SearchData(),
                Server(),
                UseConnections()
            {}

            Lobby(const Lobby& src) :
                PlayFabBaseModel(),
                pfAccessPolicy(src.pfAccessPolicy),
                ChangeNumber(src.ChangeNumber),
                ConnectionString(src.ConnectionString),
                LobbyData(src.LobbyData),
                LobbyId(src.LobbyId),
                MaxPlayers(src.MaxPlayers),
                Members(src.Members),
                pfMembershipLock(src.pfMembershipLock),
                Owner(src.Owner),
                pfOwnerMigrationPolicy(src.pfOwnerMigrationPolicy),
                PubSubConnectionHandle(src.PubSubConnectionHandle),
                RestrictInvitesToLobbyOwner(src.RestrictInvitesToLobbyOwner),
                SearchData(src.SearchData),
                Server(src.Server),
                UseConnections(src.UseConnections)
            {}

            ~Lobby() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonEnum(input["AccessPolicy"], pfAccessPolicy);
                FromJsonUtilP(input["ChangeNumber"], ChangeNumber);
                FromJsonUtilS(input["ConnectionString"], ConnectionString);
                FromJsonUtilS(input["LobbyData"], LobbyData);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilP(input["MaxPlayers"], MaxPlayers);
                FromJsonUtilO(input["Members"], Members);
                FromJsonEnum(input["MembershipLock"], pfMembershipLock);
                FromJsonUtilO(input["Owner"], Owner);
                FromJsonUtilE(input["OwnerMigrationPolicy"], pfOwnerMigrationPolicy);
                FromJsonUtilS(input["PubSubConnectionHandle"], PubSubConnectionHandle);
                FromJsonUtilP(input["RestrictInvitesToLobbyOwner"], RestrictInvitesToLobbyOwner);
                FromJsonUtilS(input["SearchData"], SearchData);
                FromJsonUtilO(input["Server"], Server);
                FromJsonUtilP(input["UseConnections"], UseConnections);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfAccessPolicy; ToJsonEnum(pfAccessPolicy, each_pfAccessPolicy); output["AccessPolicy"] = each_pfAccessPolicy;
                Json::Value each_ChangeNumber; ToJsonUtilP(ChangeNumber, each_ChangeNumber); output["ChangeNumber"] = each_ChangeNumber;
                Json::Value each_ConnectionString; ToJsonUtilS(ConnectionString, each_ConnectionString); output["ConnectionString"] = each_ConnectionString;
                Json::Value each_LobbyData; ToJsonUtilS(LobbyData, each_LobbyData); output["LobbyData"] = each_LobbyData;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_MaxPlayers; ToJsonUtilP(MaxPlayers, each_MaxPlayers); output["MaxPlayers"] = each_MaxPlayers;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_pfMembershipLock; ToJsonEnum(pfMembershipLock, each_pfMembershipLock); output["MembershipLock"] = each_pfMembershipLock;
                Json::Value each_Owner; ToJsonUtilO(Owner, each_Owner); output["Owner"] = each_Owner;
                Json::Value each_pfOwnerMigrationPolicy; ToJsonUtilE(pfOwnerMigrationPolicy, each_pfOwnerMigrationPolicy); output["OwnerMigrationPolicy"] = each_pfOwnerMigrationPolicy;
                Json::Value each_PubSubConnectionHandle; ToJsonUtilS(PubSubConnectionHandle, each_PubSubConnectionHandle); output["PubSubConnectionHandle"] = each_PubSubConnectionHandle;
                Json::Value each_RestrictInvitesToLobbyOwner; ToJsonUtilP(RestrictInvitesToLobbyOwner, each_RestrictInvitesToLobbyOwner); output["RestrictInvitesToLobbyOwner"] = each_RestrictInvitesToLobbyOwner;
                Json::Value each_SearchData; ToJsonUtilS(SearchData, each_SearchData); output["SearchData"] = each_SearchData;
                Json::Value each_Server; ToJsonUtilO(Server, each_Server); output["Server"] = each_Server;
                Json::Value each_UseConnections; ToJsonUtilP(UseConnections, each_UseConnections); output["UseConnections"] = each_UseConnections;
                return output;
            }
        };

        struct GetLobbyResult : public PlayFabResultCommon
        {
            Lobby pfLobby;

            GetLobbyResult() :
                PlayFabResultCommon(),
                pfLobby()
            {}

            GetLobbyResult(const GetLobbyResult& src) :
                PlayFabResultCommon(),
                pfLobby(src.pfLobby)
            {}

            ~GetLobbyResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Lobby"], pfLobby);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfLobby; ToJsonUtilO(pfLobby, each_pfLobby); output["Lobby"] = each_pfLobby;
                return output;
            }
        };

        struct GetMatchmakingTicketRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            bool EscapeObject;
            std::string QueueName;
            std::string TicketId;

            GetMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                EscapeObject(),
                QueueName(),
                TicketId()
            {}

            GetMatchmakingTicketRequest(const GetMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                EscapeObject(src.EscapeObject),
                QueueName(src.QueueName),
                TicketId(src.TicketId)
            {}

            ~GetMatchmakingTicketRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["EscapeObject"], EscapeObject);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EscapeObject; ToJsonUtilP(EscapeObject, each_EscapeObject); output["EscapeObject"] = each_EscapeObject;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_TicketId; ToJsonUtilS(TicketId, each_TicketId); output["TicketId"] = each_TicketId;
                return output;
            }
        };

        struct GetMatchmakingTicketResult : public PlayFabResultCommon
        {
            std::string CancellationReasonString;
            Boxed<Uint32> ChangeNumber;
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
                CancellationReasonString(),
                ChangeNumber(),
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
                CancellationReasonString(src.CancellationReasonString),
                ChangeNumber(src.ChangeNumber),
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
                FromJsonUtilS(input["CancellationReasonString"], CancellationReasonString);
                FromJsonUtilP(input["ChangeNumber"], ChangeNumber);
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
                Json::Value each_CancellationReasonString; ToJsonUtilS(CancellationReasonString, each_CancellationReasonString); output["CancellationReasonString"] = each_CancellationReasonString;
                Json::Value each_ChangeNumber; ToJsonUtilP(ChangeNumber, each_ChangeNumber); output["ChangeNumber"] = each_ChangeNumber;
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
            std::map<std::string, std::string> CustomTags;
            bool EscapeObject;
            std::string MatchId;
            std::string QueueName;
            bool ReturnMemberAttributes;

            GetMatchRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                EscapeObject(),
                MatchId(),
                QueueName(),
                ReturnMemberAttributes()
            {}

            GetMatchRequest(const GetMatchRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                EscapeObject(src.EscapeObject),
                MatchId(src.MatchId),
                QueueName(src.QueueName),
                ReturnMemberAttributes(src.ReturnMemberAttributes)
            {}

            ~GetMatchRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["EscapeObject"], EscapeObject);
                FromJsonUtilS(input["MatchId"], MatchId);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilP(input["ReturnMemberAttributes"], ReturnMemberAttributes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EscapeObject; ToJsonUtilP(EscapeObject, each_EscapeObject); output["EscapeObject"] = each_EscapeObject;
                Json::Value each_MatchId; ToJsonUtilS(MatchId, each_MatchId); output["MatchId"] = each_MatchId;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_ReturnMemberAttributes; ToJsonUtilP(ReturnMemberAttributes, each_ReturnMemberAttributes); output["ReturnMemberAttributes"] = each_ReturnMemberAttributes;
                return output;
            }
        };

        struct GetMatchResult : public PlayFabResultCommon
        {
            std::string ArrangementString;
            std::string MatchId;
            std::list<MatchmakingPlayerWithTeamAssignment> Members;
            std::list<std::string> RegionPreferences;
            Boxed<ServerDetails> pfServerDetails;

            GetMatchResult() :
                PlayFabResultCommon(),
                ArrangementString(),
                MatchId(),
                Members(),
                RegionPreferences(),
                pfServerDetails()
            {}

            GetMatchResult(const GetMatchResult& src) :
                PlayFabResultCommon(),
                ArrangementString(src.ArrangementString),
                MatchId(src.MatchId),
                Members(src.Members),
                RegionPreferences(src.RegionPreferences),
                pfServerDetails(src.pfServerDetails)
            {}

            ~GetMatchResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ArrangementString"], ArrangementString);
                FromJsonUtilS(input["MatchId"], MatchId);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["RegionPreferences"], RegionPreferences);
                FromJsonUtilO(input["ServerDetails"], pfServerDetails);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ArrangementString; ToJsonUtilS(ArrangementString, each_ArrangementString); output["ArrangementString"] = each_ArrangementString;
                Json::Value each_MatchId; ToJsonUtilS(MatchId, each_MatchId); output["MatchId"] = each_MatchId;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_RegionPreferences; ToJsonUtilS(RegionPreferences, each_RegionPreferences); output["RegionPreferences"] = each_RegionPreferences;
                Json::Value each_pfServerDetails; ToJsonUtilO(pfServerDetails, each_pfServerDetails); output["ServerDetails"] = each_pfServerDetails;
                return output;
            }
        };

        struct GetMultiplayerServerDetailsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string SessionId;

            GetMultiplayerServerDetailsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                SessionId()
            {}

            GetMultiplayerServerDetailsRequest(const GetMultiplayerServerDetailsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                SessionId(src.SessionId)
            {}

            ~GetMultiplayerServerDetailsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["SessionId"], SessionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                return output;
            }
        };

        struct PublicIpAddress : public PlayFabBaseModel
        {
            std::string FQDN;
            std::string IpAddress;
            std::string RoutingType;

            PublicIpAddress() :
                PlayFabBaseModel(),
                FQDN(),
                IpAddress(),
                RoutingType()
            {}

            PublicIpAddress(const PublicIpAddress& src) :
                PlayFabBaseModel(),
                FQDN(src.FQDN),
                IpAddress(src.IpAddress),
                RoutingType(src.RoutingType)
            {}

            ~PublicIpAddress() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["FQDN"], FQDN);
                FromJsonUtilS(input["IpAddress"], IpAddress);
                FromJsonUtilS(input["RoutingType"], RoutingType);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FQDN; ToJsonUtilS(FQDN, each_FQDN); output["FQDN"] = each_FQDN;
                Json::Value each_IpAddress; ToJsonUtilS(IpAddress, each_IpAddress); output["IpAddress"] = each_IpAddress;
                Json::Value each_RoutingType; ToJsonUtilS(RoutingType, each_RoutingType); output["RoutingType"] = each_RoutingType;
                return output;
            }
        };

        struct GetMultiplayerServerDetailsResponse : public PlayFabResultCommon
        {
            std::string BuildId;
            std::list<ConnectedPlayer> ConnectedPlayers;
            std::string FQDN;
            std::string IPV4Address;
            Boxed<time_t> LastStateTransitionTime;
            std::list<Port> Ports;
            std::list<PublicIpAddress> PublicIPV4Addresses;
            std::string Region;
            std::string ServerId;
            std::string SessionId;
            std::string State;
            std::string VmId;

            GetMultiplayerServerDetailsResponse() :
                PlayFabResultCommon(),
                BuildId(),
                ConnectedPlayers(),
                FQDN(),
                IPV4Address(),
                LastStateTransitionTime(),
                Ports(),
                PublicIPV4Addresses(),
                Region(),
                ServerId(),
                SessionId(),
                State(),
                VmId()
            {}

            GetMultiplayerServerDetailsResponse(const GetMultiplayerServerDetailsResponse& src) :
                PlayFabResultCommon(),
                BuildId(src.BuildId),
                ConnectedPlayers(src.ConnectedPlayers),
                FQDN(src.FQDN),
                IPV4Address(src.IPV4Address),
                LastStateTransitionTime(src.LastStateTransitionTime),
                Ports(src.Ports),
                PublicIPV4Addresses(src.PublicIPV4Addresses),
                Region(src.Region),
                ServerId(src.ServerId),
                SessionId(src.SessionId),
                State(src.State),
                VmId(src.VmId)
            {}

            ~GetMultiplayerServerDetailsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilO(input["ConnectedPlayers"], ConnectedPlayers);
                FromJsonUtilS(input["FQDN"], FQDN);
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilT(input["LastStateTransitionTime"], LastStateTransitionTime);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["PublicIPV4Addresses"], PublicIPV4Addresses);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["ServerId"], ServerId);
                FromJsonUtilS(input["SessionId"], SessionId);
                FromJsonUtilS(input["State"], State);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_ConnectedPlayers; ToJsonUtilO(ConnectedPlayers, each_ConnectedPlayers); output["ConnectedPlayers"] = each_ConnectedPlayers;
                Json::Value each_FQDN; ToJsonUtilS(FQDN, each_FQDN); output["FQDN"] = each_FQDN;
                Json::Value each_IPV4Address; ToJsonUtilS(IPV4Address, each_IPV4Address); output["IPV4Address"] = each_IPV4Address;
                Json::Value each_LastStateTransitionTime; ToJsonUtilT(LastStateTransitionTime, each_LastStateTransitionTime); output["LastStateTransitionTime"] = each_LastStateTransitionTime;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_PublicIPV4Addresses; ToJsonUtilO(PublicIPV4Addresses, each_PublicIPV4Addresses); output["PublicIPV4Addresses"] = each_PublicIPV4Addresses;
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
            std::map<std::string, std::string> CustomTags;
            std::string ServerId;

            GetMultiplayerServerLogsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                ServerId()
            {}

            GetMultiplayerServerLogsRequest(const GetMultiplayerServerLogsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                ServerId(src.ServerId)
            {}

            ~GetMultiplayerServerLogsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["ServerId"], ServerId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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

        struct GetMultiplayerSessionLogsBySessionIdRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string SessionId;

            GetMultiplayerSessionLogsBySessionIdRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                SessionId()
            {}

            GetMultiplayerSessionLogsBySessionIdRequest(const GetMultiplayerSessionLogsBySessionIdRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                SessionId(src.SessionId)
            {}

            ~GetMultiplayerSessionLogsBySessionIdRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["SessionId"], SessionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                return output;
            }
        };

        struct GetQueueStatisticsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string QueueName;

            GetQueueStatisticsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                QueueName()
            {}

            GetQueueStatisticsRequest(const GetQueueStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                QueueName(src.QueueName)
            {}

            ~GetQueueStatisticsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::map<std::string, std::string> CustomTags;
            std::string Region;
            std::string VmId;

            GetRemoteLoginEndpointRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                CustomTags(),
                Region(),
                VmId()
            {}

            GetRemoteLoginEndpointRequest(const GetRemoteLoginEndpointRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                CustomTags(src.CustomTags),
                Region(src.Region),
                VmId(src.VmId)
            {}

            ~GetRemoteLoginEndpointRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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

        struct GetServerBackfillTicketRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            bool EscapeObject;
            std::string QueueName;
            std::string TicketId;

            GetServerBackfillTicketRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                EscapeObject(),
                QueueName(),
                TicketId()
            {}

            GetServerBackfillTicketRequest(const GetServerBackfillTicketRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                EscapeObject(src.EscapeObject),
                QueueName(src.QueueName),
                TicketId(src.TicketId)
            {}

            ~GetServerBackfillTicketRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["EscapeObject"], EscapeObject);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_EscapeObject; ToJsonUtilP(EscapeObject, each_EscapeObject); output["EscapeObject"] = each_EscapeObject;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_TicketId; ToJsonUtilS(TicketId, each_TicketId); output["TicketId"] = each_TicketId;
                return output;
            }
        };

        struct GetServerBackfillTicketResult : public PlayFabResultCommon
        {
            std::string CancellationReasonString;
            time_t Created;
            Int32 GiveUpAfterSeconds;
            std::string MatchId;
            std::list<MatchmakingPlayerWithTeamAssignment> Members;
            std::string QueueName;
            ServerDetails pfServerDetails;
            std::string Status;
            std::string TicketId;

            GetServerBackfillTicketResult() :
                PlayFabResultCommon(),
                CancellationReasonString(),
                Created(),
                GiveUpAfterSeconds(),
                MatchId(),
                Members(),
                QueueName(),
                pfServerDetails(),
                Status(),
                TicketId()
            {}

            GetServerBackfillTicketResult(const GetServerBackfillTicketResult& src) :
                PlayFabResultCommon(),
                CancellationReasonString(src.CancellationReasonString),
                Created(src.Created),
                GiveUpAfterSeconds(src.GiveUpAfterSeconds),
                MatchId(src.MatchId),
                Members(src.Members),
                QueueName(src.QueueName),
                pfServerDetails(src.pfServerDetails),
                Status(src.Status),
                TicketId(src.TicketId)
            {}

            ~GetServerBackfillTicketResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CancellationReasonString"], CancellationReasonString);
                FromJsonUtilT(input["Created"], Created);
                FromJsonUtilP(input["GiveUpAfterSeconds"], GiveUpAfterSeconds);
                FromJsonUtilS(input["MatchId"], MatchId);
                FromJsonUtilO(input["Members"], Members);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilO(input["ServerDetails"], pfServerDetails);
                FromJsonUtilS(input["Status"], Status);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CancellationReasonString; ToJsonUtilS(CancellationReasonString, each_CancellationReasonString); output["CancellationReasonString"] = each_CancellationReasonString;
                Json::Value each_Created; ToJsonUtilT(Created, each_Created); output["Created"] = each_Created;
                Json::Value each_GiveUpAfterSeconds; ToJsonUtilP(GiveUpAfterSeconds, each_GiveUpAfterSeconds); output["GiveUpAfterSeconds"] = each_GiveUpAfterSeconds;
                Json::Value each_MatchId; ToJsonUtilS(MatchId, each_MatchId); output["MatchId"] = each_MatchId;
                Json::Value each_Members; ToJsonUtilO(Members, each_Members); output["Members"] = each_Members;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                Json::Value each_pfServerDetails; ToJsonUtilO(pfServerDetails, each_pfServerDetails); output["ServerDetails"] = each_pfServerDetails;
                Json::Value each_Status; ToJsonUtilS(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_TicketId; ToJsonUtilS(TicketId, each_TicketId); output["TicketId"] = each_TicketId;
                return output;
            }
        };

        struct GetTitleEnabledForMultiplayerServersStatusRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            GetTitleEnabledForMultiplayerServersStatusRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            GetTitleEnabledForMultiplayerServersStatusRequest(const GetTitleEnabledForMultiplayerServersStatusRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~GetTitleEnabledForMultiplayerServersStatusRequest() = default;

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

        struct GetTitleMultiplayerServersQuotaChangeRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string RequestId;

            GetTitleMultiplayerServersQuotaChangeRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                RequestId()
            {}

            GetTitleMultiplayerServersQuotaChangeRequest(const GetTitleMultiplayerServersQuotaChangeRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                RequestId(src.RequestId)
            {}

            ~GetTitleMultiplayerServersQuotaChangeRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["RequestId"], RequestId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_RequestId; ToJsonUtilS(RequestId, each_RequestId); output["RequestId"] = each_RequestId;
                return output;
            }
        };

        struct QuotaChange : public PlayFabBaseModel
        {
            std::string ChangeDescription;
            std::list<CoreCapacityChange> Changes;
            bool IsPendingReview;
            std::string Notes;
            std::string RequestId;
            std::string ReviewComments;
            bool WasApproved;

            QuotaChange() :
                PlayFabBaseModel(),
                ChangeDescription(),
                Changes(),
                IsPendingReview(),
                Notes(),
                RequestId(),
                ReviewComments(),
                WasApproved()
            {}

            QuotaChange(const QuotaChange& src) :
                PlayFabBaseModel(),
                ChangeDescription(src.ChangeDescription),
                Changes(src.Changes),
                IsPendingReview(src.IsPendingReview),
                Notes(src.Notes),
                RequestId(src.RequestId),
                ReviewComments(src.ReviewComments),
                WasApproved(src.WasApproved)
            {}

            ~QuotaChange() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ChangeDescription"], ChangeDescription);
                FromJsonUtilO(input["Changes"], Changes);
                FromJsonUtilP(input["IsPendingReview"], IsPendingReview);
                FromJsonUtilS(input["Notes"], Notes);
                FromJsonUtilS(input["RequestId"], RequestId);
                FromJsonUtilS(input["ReviewComments"], ReviewComments);
                FromJsonUtilP(input["WasApproved"], WasApproved);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ChangeDescription; ToJsonUtilS(ChangeDescription, each_ChangeDescription); output["ChangeDescription"] = each_ChangeDescription;
                Json::Value each_Changes; ToJsonUtilO(Changes, each_Changes); output["Changes"] = each_Changes;
                Json::Value each_IsPendingReview; ToJsonUtilP(IsPendingReview, each_IsPendingReview); output["IsPendingReview"] = each_IsPendingReview;
                Json::Value each_Notes; ToJsonUtilS(Notes, each_Notes); output["Notes"] = each_Notes;
                Json::Value each_RequestId; ToJsonUtilS(RequestId, each_RequestId); output["RequestId"] = each_RequestId;
                Json::Value each_ReviewComments; ToJsonUtilS(ReviewComments, each_ReviewComments); output["ReviewComments"] = each_ReviewComments;
                Json::Value each_WasApproved; ToJsonUtilP(WasApproved, each_WasApproved); output["WasApproved"] = each_WasApproved;
                return output;
            }
        };

        struct GetTitleMultiplayerServersQuotaChangeResponse : public PlayFabResultCommon
        {
            Boxed<QuotaChange> Change;

            GetTitleMultiplayerServersQuotaChangeResponse() :
                PlayFabResultCommon(),
                Change()
            {}

            GetTitleMultiplayerServersQuotaChangeResponse(const GetTitleMultiplayerServersQuotaChangeResponse& src) :
                PlayFabResultCommon(),
                Change(src.Change)
            {}

            ~GetTitleMultiplayerServersQuotaChangeResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Change"], Change);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Change; ToJsonUtilO(Change, each_Change); output["Change"] = each_Change;
                return output;
            }
        };

        struct GetTitleMultiplayerServersQuotasRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            GetTitleMultiplayerServersQuotasRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            GetTitleMultiplayerServersQuotasRequest(const GetTitleMultiplayerServersQuotasRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~GetTitleMultiplayerServersQuotasRequest() = default;

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

        struct InviteToLobbyRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> InviteeEntity;
            std::string LobbyId;
            Boxed<EntityKey> MemberEntity;

            InviteToLobbyRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                InviteeEntity(),
                LobbyId(),
                MemberEntity()
            {}

            InviteToLobbyRequest(const InviteToLobbyRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                InviteeEntity(src.InviteeEntity),
                LobbyId(src.LobbyId),
                MemberEntity(src.MemberEntity)
            {}

            ~InviteToLobbyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["InviteeEntity"], InviteeEntity);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilO(input["MemberEntity"], MemberEntity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_InviteeEntity; ToJsonUtilO(InviteeEntity, each_InviteeEntity); output["InviteeEntity"] = each_InviteeEntity;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_MemberEntity; ToJsonUtilO(MemberEntity, each_MemberEntity); output["MemberEntity"] = each_MemberEntity;
                return output;
            }
        };

        struct JoinArrangedLobbyRequest : public PlayFabRequestCommon
        {
            Boxed<AccessPolicy> pfAccessPolicy;
            std::string ArrangementString;
            std::map<std::string, std::string> CustomTags;
            Uint32 MaxPlayers;
            std::map<std::string, std::string> MemberData;
            EntityKey MemberEntity;
            Boxed<OwnerMigrationPolicy> pfOwnerMigrationPolicy;
            bool RestrictInvitesToLobbyOwner;
            bool UseConnections;

            JoinArrangedLobbyRequest() :
                PlayFabRequestCommon(),
                pfAccessPolicy(),
                ArrangementString(),
                CustomTags(),
                MaxPlayers(),
                MemberData(),
                MemberEntity(),
                pfOwnerMigrationPolicy(),
                RestrictInvitesToLobbyOwner(),
                UseConnections()
            {}

            JoinArrangedLobbyRequest(const JoinArrangedLobbyRequest& src) :
                PlayFabRequestCommon(),
                pfAccessPolicy(src.pfAccessPolicy),
                ArrangementString(src.ArrangementString),
                CustomTags(src.CustomTags),
                MaxPlayers(src.MaxPlayers),
                MemberData(src.MemberData),
                MemberEntity(src.MemberEntity),
                pfOwnerMigrationPolicy(src.pfOwnerMigrationPolicy),
                RestrictInvitesToLobbyOwner(src.RestrictInvitesToLobbyOwner),
                UseConnections(src.UseConnections)
            {}

            ~JoinArrangedLobbyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilE(input["AccessPolicy"], pfAccessPolicy);
                FromJsonUtilS(input["ArrangementString"], ArrangementString);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["MaxPlayers"], MaxPlayers);
                FromJsonUtilS(input["MemberData"], MemberData);
                FromJsonUtilO(input["MemberEntity"], MemberEntity);
                FromJsonUtilE(input["OwnerMigrationPolicy"], pfOwnerMigrationPolicy);
                FromJsonUtilP(input["RestrictInvitesToLobbyOwner"], RestrictInvitesToLobbyOwner);
                FromJsonUtilP(input["UseConnections"], UseConnections);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfAccessPolicy; ToJsonUtilE(pfAccessPolicy, each_pfAccessPolicy); output["AccessPolicy"] = each_pfAccessPolicy;
                Json::Value each_ArrangementString; ToJsonUtilS(ArrangementString, each_ArrangementString); output["ArrangementString"] = each_ArrangementString;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_MaxPlayers; ToJsonUtilP(MaxPlayers, each_MaxPlayers); output["MaxPlayers"] = each_MaxPlayers;
                Json::Value each_MemberData; ToJsonUtilS(MemberData, each_MemberData); output["MemberData"] = each_MemberData;
                Json::Value each_MemberEntity; ToJsonUtilO(MemberEntity, each_MemberEntity); output["MemberEntity"] = each_MemberEntity;
                Json::Value each_pfOwnerMigrationPolicy; ToJsonUtilE(pfOwnerMigrationPolicy, each_pfOwnerMigrationPolicy); output["OwnerMigrationPolicy"] = each_pfOwnerMigrationPolicy;
                Json::Value each_RestrictInvitesToLobbyOwner; ToJsonUtilP(RestrictInvitesToLobbyOwner, each_RestrictInvitesToLobbyOwner); output["RestrictInvitesToLobbyOwner"] = each_RestrictInvitesToLobbyOwner;
                Json::Value each_UseConnections; ToJsonUtilP(UseConnections, each_UseConnections); output["UseConnections"] = each_UseConnections;
                return output;
            }
        };

        struct JoinLobbyAsServerRequest : public PlayFabRequestCommon
        {
            std::string ConnectionString;
            std::map<std::string, std::string> CustomTags;
            std::map<std::string, std::string> ServerData;
            EntityKey ServerEntity;

            JoinLobbyAsServerRequest() :
                PlayFabRequestCommon(),
                ConnectionString(),
                CustomTags(),
                ServerData(),
                ServerEntity()
            {}

            JoinLobbyAsServerRequest(const JoinLobbyAsServerRequest& src) :
                PlayFabRequestCommon(),
                ConnectionString(src.ConnectionString),
                CustomTags(src.CustomTags),
                ServerData(src.ServerData),
                ServerEntity(src.ServerEntity)
            {}

            ~JoinLobbyAsServerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ConnectionString"], ConnectionString);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["ServerData"], ServerData);
                FromJsonUtilO(input["ServerEntity"], ServerEntity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionString; ToJsonUtilS(ConnectionString, each_ConnectionString); output["ConnectionString"] = each_ConnectionString;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_ServerData; ToJsonUtilS(ServerData, each_ServerData); output["ServerData"] = each_ServerData;
                Json::Value each_ServerEntity; ToJsonUtilO(ServerEntity, each_ServerEntity); output["ServerEntity"] = each_ServerEntity;
                return output;
            }
        };

        struct JoinLobbyAsServerResult : public PlayFabResultCommon
        {
            std::string LobbyId;

            JoinLobbyAsServerResult() :
                PlayFabResultCommon(),
                LobbyId()
            {}

            JoinLobbyAsServerResult(const JoinLobbyAsServerResult& src) :
                PlayFabResultCommon(),
                LobbyId(src.LobbyId)
            {}

            ~JoinLobbyAsServerResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["LobbyId"], LobbyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                return output;
            }
        };

        struct JoinLobbyRequest : public PlayFabRequestCommon
        {
            std::string ConnectionString;
            std::map<std::string, std::string> CustomTags;
            std::map<std::string, std::string> MemberData;
            Boxed<EntityKey> MemberEntity;

            JoinLobbyRequest() :
                PlayFabRequestCommon(),
                ConnectionString(),
                CustomTags(),
                MemberData(),
                MemberEntity()
            {}

            JoinLobbyRequest(const JoinLobbyRequest& src) :
                PlayFabRequestCommon(),
                ConnectionString(src.ConnectionString),
                CustomTags(src.CustomTags),
                MemberData(src.MemberData),
                MemberEntity(src.MemberEntity)
            {}

            ~JoinLobbyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ConnectionString"], ConnectionString);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["MemberData"], MemberData);
                FromJsonUtilO(input["MemberEntity"], MemberEntity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionString; ToJsonUtilS(ConnectionString, each_ConnectionString); output["ConnectionString"] = each_ConnectionString;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_MemberData; ToJsonUtilS(MemberData, each_MemberData); output["MemberData"] = each_MemberData;
                Json::Value each_MemberEntity; ToJsonUtilO(MemberEntity, each_MemberEntity); output["MemberEntity"] = each_MemberEntity;
                return output;
            }
        };

        struct JoinLobbyResult : public PlayFabResultCommon
        {
            std::string LobbyId;

            JoinLobbyResult() :
                PlayFabResultCommon(),
                LobbyId()
            {}

            JoinLobbyResult(const JoinLobbyResult& src) :
                PlayFabResultCommon(),
                LobbyId(src.LobbyId)
            {}

            ~JoinLobbyResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["LobbyId"], LobbyId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                return output;
            }
        };

        struct JoinMatchmakingTicketRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            MatchmakingPlayer Member;
            std::string QueueName;
            std::string TicketId;

            JoinMatchmakingTicketRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Member(),
                QueueName(),
                TicketId()
            {}

            JoinMatchmakingTicketRequest(const JoinMatchmakingTicketRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Member(src.Member),
                QueueName(src.QueueName),
                TicketId(src.TicketId)
            {}

            ~JoinMatchmakingTicketRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Member"], Member);
                FromJsonUtilS(input["QueueName"], QueueName);
                FromJsonUtilS(input["TicketId"], TicketId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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

        struct LeaveLobbyAsServerRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string LobbyId;
            EntityKey ServerEntity;

            LeaveLobbyAsServerRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                LobbyId(),
                ServerEntity()
            {}

            LeaveLobbyAsServerRequest(const LeaveLobbyAsServerRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                LobbyId(src.LobbyId),
                ServerEntity(src.ServerEntity)
            {}

            ~LeaveLobbyAsServerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilO(input["ServerEntity"], ServerEntity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_ServerEntity; ToJsonUtilO(ServerEntity, each_ServerEntity); output["ServerEntity"] = each_ServerEntity;
                return output;
            }
        };

        struct LeaveLobbyRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string LobbyId;
            Boxed<EntityKey> MemberEntity;

            LeaveLobbyRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                LobbyId(),
                MemberEntity()
            {}

            LeaveLobbyRequest(const LeaveLobbyRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                LobbyId(src.LobbyId),
                MemberEntity(src.MemberEntity)
            {}

            ~LeaveLobbyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilO(input["MemberEntity"], MemberEntity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_MemberEntity; ToJsonUtilO(MemberEntity, each_MemberEntity); output["MemberEntity"] = each_MemberEntity;
                return output;
            }
        };

        struct ListAssetSummariesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListAssetSummariesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                PageSize(),
                SkipToken()
            {}

            ListAssetSummariesRequest(const ListAssetSummariesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListAssetSummariesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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

        struct ListBuildAliasesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListBuildAliasesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                PageSize(),
                SkipToken()
            {}

            ListBuildAliasesRequest(const ListBuildAliasesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListBuildAliasesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListBuildAliasesResponse : public PlayFabResultCommon
        {
            std::list<BuildAliasDetailsResponse> BuildAliases;
            Int32 PageSize;
            std::string SkipToken;

            ListBuildAliasesResponse() :
                PlayFabResultCommon(),
                BuildAliases(),
                PageSize(),
                SkipToken()
            {}

            ListBuildAliasesResponse(const ListBuildAliasesResponse& src) :
                PlayFabResultCommon(),
                BuildAliases(src.BuildAliases),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListBuildAliasesResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["BuildAliases"], BuildAliases);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildAliases; ToJsonUtilO(BuildAliases, each_BuildAliases); output["BuildAliases"] = each_BuildAliases;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListBuildSummariesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListBuildSummariesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                PageSize(),
                SkipToken()
            {}

            ListBuildSummariesRequest(const ListBuildSummariesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListBuildSummariesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::map<std::string, std::string> CustomTags;
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListCertificateSummariesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                PageSize(),
                SkipToken()
            {}

            ListCertificateSummariesRequest(const ListCertificateSummariesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListCertificateSummariesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::map<std::string, std::string> CustomTags;
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListContainerImagesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                PageSize(),
                SkipToken()
            {}

            ListContainerImagesRequest(const ListContainerImagesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListContainerImagesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::map<std::string, std::string> CustomTags;
            std::string ImageName;
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListContainerImageTagsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                ImageName(),
                PageSize(),
                SkipToken()
            {}

            ListContainerImageTagsRequest(const ListContainerImageTagsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                ImageName(src.ImageName),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListContainerImageTagsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["ImageName"], ImageName);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_ImageName; ToJsonUtilS(ImageName, each_ImageName); output["ImageName"] = each_ImageName;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListContainerImageTagsResponse : public PlayFabResultCommon
        {
            Int32 PageSize;
            std::string SkipToken;
            std::list<std::string> Tags;

            ListContainerImageTagsResponse() :
                PlayFabResultCommon(),
                PageSize(),
                SkipToken(),
                Tags()
            {}

            ListContainerImageTagsResponse(const ListContainerImageTagsResponse& src) :
                PlayFabResultCommon(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken),
                Tags(src.Tags)
            {}

            ~ListContainerImageTagsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                return output;
            }
        };

        struct ListMatchmakingTicketsForPlayerRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string QueueName;

            ListMatchmakingTicketsForPlayerRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                QueueName()
            {}

            ListMatchmakingTicketsForPlayerRequest(const ListMatchmakingTicketsForPlayerRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                QueueName(src.QueueName)
            {}

            ~ListMatchmakingTicketsForPlayerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::map<std::string, std::string> CustomTags;
            Boxed<Int32> PageSize;
            std::string Region;
            std::string SkipToken;

            ListMultiplayerServersRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                CustomTags(),
                PageSize(),
                Region(),
                SkipToken()
            {}

            ListMultiplayerServersRequest(const ListMultiplayerServersRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                CustomTags(src.CustomTags),
                PageSize(src.PageSize),
                Region(src.Region),
                SkipToken(src.SkipToken)
            {}

            ~ListMultiplayerServersRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::map<std::string, std::string> CustomTags;

            ListPartyQosServersRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            ListPartyQosServersRequest(const ListPartyQosServersRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~ListPartyQosServersRequest() = default;

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
            std::map<std::string, std::string> CustomTags;
            Boxed<bool> IncludeAllRegions;
            std::string RoutingPreference;

            ListQosServersForTitleRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                IncludeAllRegions(),
                RoutingPreference()
            {}

            ListQosServersForTitleRequest(const ListQosServersForTitleRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                IncludeAllRegions(src.IncludeAllRegions),
                RoutingPreference(src.RoutingPreference)
            {}

            ~ListQosServersForTitleRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["IncludeAllRegions"], IncludeAllRegions);
                FromJsonUtilS(input["RoutingPreference"], RoutingPreference);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_IncludeAllRegions; ToJsonUtilP(IncludeAllRegions, each_IncludeAllRegions); output["IncludeAllRegions"] = each_IncludeAllRegions;
                Json::Value each_RoutingPreference; ToJsonUtilS(RoutingPreference, each_RoutingPreference); output["RoutingPreference"] = each_RoutingPreference;
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

        struct ListSecretSummariesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<Int32> PageSize;
            std::string SkipToken;

            ListSecretSummariesRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                PageSize(),
                SkipToken()
            {}

            ListSecretSummariesRequest(const ListSecretSummariesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ~ListSecretSummariesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct SecretSummary : public PlayFabBaseModel
        {
            Boxed<time_t> ExpirationDate;
            std::string Name;
            std::string Version;

            SecretSummary() :
                PlayFabBaseModel(),
                ExpirationDate(),
                Name(),
                Version()
            {}

            SecretSummary(const SecretSummary& src) :
                PlayFabBaseModel(),
                ExpirationDate(src.ExpirationDate),
                Name(src.Name),
                Version(src.Version)
            {}

            ~SecretSummary() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilT(input["ExpirationDate"], ExpirationDate);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["Version"], Version);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpirationDate; ToJsonUtilT(ExpirationDate, each_ExpirationDate); output["ExpirationDate"] = each_ExpirationDate;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Version; ToJsonUtilS(Version, each_Version); output["Version"] = each_Version;
                return output;
            }
        };

        struct ListSecretSummariesResponse : public PlayFabResultCommon
        {
            Int32 PageSize;
            std::list<SecretSummary> SecretSummaries;
            std::string SkipToken;

            ListSecretSummariesResponse() :
                PlayFabResultCommon(),
                PageSize(),
                SecretSummaries(),
                SkipToken()
            {}

            ListSecretSummariesResponse(const ListSecretSummariesResponse& src) :
                PlayFabResultCommon(),
                PageSize(src.PageSize),
                SecretSummaries(src.SecretSummaries),
                SkipToken(src.SkipToken)
            {}

            ~ListSecretSummariesResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilO(input["SecretSummaries"], SecretSummaries);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_PageSize; ToJsonUtilP(PageSize, each_PageSize); output["PageSize"] = each_PageSize;
                Json::Value each_SecretSummaries; ToJsonUtilO(SecretSummaries, each_SecretSummaries); output["SecretSummaries"] = each_SecretSummaries;
                Json::Value each_SkipToken; ToJsonUtilS(SkipToken, each_SkipToken); output["SkipToken"] = each_SkipToken;
                return output;
            }
        };

        struct ListServerBackfillTicketsForPlayerRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            std::string QueueName;

            ListServerBackfillTicketsForPlayerRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity(),
                QueueName()
            {}

            ListServerBackfillTicketsForPlayerRequest(const ListServerBackfillTicketsForPlayerRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                QueueName(src.QueueName)
            {}

            ~ListServerBackfillTicketsForPlayerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["QueueName"], QueueName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_QueueName; ToJsonUtilS(QueueName, each_QueueName); output["QueueName"] = each_QueueName;
                return output;
            }
        };

        struct ListServerBackfillTicketsForPlayerResult : public PlayFabResultCommon
        {
            std::list<std::string> TicketIds;

            ListServerBackfillTicketsForPlayerResult() :
                PlayFabResultCommon(),
                TicketIds()
            {}

            ListServerBackfillTicketsForPlayerResult(const ListServerBackfillTicketsForPlayerResult& src) :
                PlayFabResultCommon(),
                TicketIds(src.TicketIds)
            {}

            ~ListServerBackfillTicketsForPlayerResult() = default;

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

        struct ListTitleMultiplayerServersQuotaChangesRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            ListTitleMultiplayerServersQuotaChangesRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            ListTitleMultiplayerServersQuotaChangesRequest(const ListTitleMultiplayerServersQuotaChangesRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~ListTitleMultiplayerServersQuotaChangesRequest() = default;

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

        struct ListTitleMultiplayerServersQuotaChangesResponse : public PlayFabResultCommon
        {
            std::list<QuotaChange> Changes;

            ListTitleMultiplayerServersQuotaChangesResponse() :
                PlayFabResultCommon(),
                Changes()
            {}

            ListTitleMultiplayerServersQuotaChangesResponse(const ListTitleMultiplayerServersQuotaChangesResponse& src) :
                PlayFabResultCommon(),
                Changes(src.Changes)
            {}

            ~ListTitleMultiplayerServersQuotaChangesResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Changes"], Changes);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Changes; ToJsonUtilO(Changes, each_Changes); output["Changes"] = each_Changes;
                return output;
            }
        };

        struct ListVirtualMachineSummariesRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::map<std::string, std::string> CustomTags;
            Boxed<Int32> PageSize;
            std::string Region;
            std::string SkipToken;

            ListVirtualMachineSummariesRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                CustomTags(),
                PageSize(),
                Region(),
                SkipToken()
            {}

            ListVirtualMachineSummariesRequest(const ListVirtualMachineSummariesRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                CustomTags(src.CustomTags),
                PageSize(src.PageSize),
                Region(src.Region),
                SkipToken(src.SkipToken)
            {}

            ~ListVirtualMachineSummariesRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["PageSize"], PageSize);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["SkipToken"], SkipToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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

        struct LobbyEmptyResult : public PlayFabResultCommon
        {

            LobbyEmptyResult() :
                PlayFabResultCommon()
            {}

            LobbyEmptyResult(const LobbyEmptyResult&) :
                PlayFabResultCommon()
            {}

            ~LobbyEmptyResult() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct PartyInvitationConfiguration : public PlayFabBaseModel
        {
            std::list<EntityKey> EntityKeys;
            std::string Identifier;
            std::string Revocability;

            PartyInvitationConfiguration() :
                PlayFabBaseModel(),
                EntityKeys(),
                Identifier(),
                Revocability()
            {}

            PartyInvitationConfiguration(const PartyInvitationConfiguration& src) :
                PlayFabBaseModel(),
                EntityKeys(src.EntityKeys),
                Identifier(src.Identifier),
                Revocability(src.Revocability)
            {}

            ~PartyInvitationConfiguration() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["EntityKeys"], EntityKeys);
                FromJsonUtilS(input["Identifier"], Identifier);
                FromJsonUtilS(input["Revocability"], Revocability);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_EntityKeys; ToJsonUtilO(EntityKeys, each_EntityKeys); output["EntityKeys"] = each_EntityKeys;
                Json::Value each_Identifier; ToJsonUtilS(Identifier, each_Identifier); output["Identifier"] = each_Identifier;
                Json::Value each_Revocability; ToJsonUtilS(Revocability, each_Revocability); output["Revocability"] = each_Revocability;
                return output;
            }
        };

        struct PartyNetworkConfiguration : public PlayFabBaseModel
        {
            std::string DirectPeerConnectivityOptions;
            Uint32 MaxDevices;
            Uint32 MaxDevicesPerUser;
            Uint32 MaxEndpointsPerDevice;
            Uint32 MaxUsers;
            Uint32 MaxUsersPerDevice;
            Boxed<PartyInvitationConfiguration> pfPartyInvitationConfiguration;

            PartyNetworkConfiguration() :
                PlayFabBaseModel(),
                DirectPeerConnectivityOptions(),
                MaxDevices(),
                MaxDevicesPerUser(),
                MaxEndpointsPerDevice(),
                MaxUsers(),
                MaxUsersPerDevice(),
                pfPartyInvitationConfiguration()
            {}

            PartyNetworkConfiguration(const PartyNetworkConfiguration& src) :
                PlayFabBaseModel(),
                DirectPeerConnectivityOptions(src.DirectPeerConnectivityOptions),
                MaxDevices(src.MaxDevices),
                MaxDevicesPerUser(src.MaxDevicesPerUser),
                MaxEndpointsPerDevice(src.MaxEndpointsPerDevice),
                MaxUsers(src.MaxUsers),
                MaxUsersPerDevice(src.MaxUsersPerDevice),
                pfPartyInvitationConfiguration(src.pfPartyInvitationConfiguration)
            {}

            ~PartyNetworkConfiguration() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["DirectPeerConnectivityOptions"], DirectPeerConnectivityOptions);
                FromJsonUtilP(input["MaxDevices"], MaxDevices);
                FromJsonUtilP(input["MaxDevicesPerUser"], MaxDevicesPerUser);
                FromJsonUtilP(input["MaxEndpointsPerDevice"], MaxEndpointsPerDevice);
                FromJsonUtilP(input["MaxUsers"], MaxUsers);
                FromJsonUtilP(input["MaxUsersPerDevice"], MaxUsersPerDevice);
                FromJsonUtilO(input["PartyInvitationConfiguration"], pfPartyInvitationConfiguration);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DirectPeerConnectivityOptions; ToJsonUtilS(DirectPeerConnectivityOptions, each_DirectPeerConnectivityOptions); output["DirectPeerConnectivityOptions"] = each_DirectPeerConnectivityOptions;
                Json::Value each_MaxDevices; ToJsonUtilP(MaxDevices, each_MaxDevices); output["MaxDevices"] = each_MaxDevices;
                Json::Value each_MaxDevicesPerUser; ToJsonUtilP(MaxDevicesPerUser, each_MaxDevicesPerUser); output["MaxDevicesPerUser"] = each_MaxDevicesPerUser;
                Json::Value each_MaxEndpointsPerDevice; ToJsonUtilP(MaxEndpointsPerDevice, each_MaxEndpointsPerDevice); output["MaxEndpointsPerDevice"] = each_MaxEndpointsPerDevice;
                Json::Value each_MaxUsers; ToJsonUtilP(MaxUsers, each_MaxUsers); output["MaxUsers"] = each_MaxUsers;
                Json::Value each_MaxUsersPerDevice; ToJsonUtilP(MaxUsersPerDevice, each_MaxUsersPerDevice); output["MaxUsersPerDevice"] = each_MaxUsersPerDevice;
                Json::Value each_pfPartyInvitationConfiguration; ToJsonUtilO(pfPartyInvitationConfiguration, each_pfPartyInvitationConfiguration); output["PartyInvitationConfiguration"] = each_pfPartyInvitationConfiguration;
                return output;
            }
        };

        struct RemoveMemberFromLobbyRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string LobbyId;
            Boxed<EntityKey> MemberEntity;
            bool PreventRejoin;

            RemoveMemberFromLobbyRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                LobbyId(),
                MemberEntity(),
                PreventRejoin()
            {}

            RemoveMemberFromLobbyRequest(const RemoveMemberFromLobbyRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                LobbyId(src.LobbyId),
                MemberEntity(src.MemberEntity),
                PreventRejoin(src.PreventRejoin)
            {}

            ~RemoveMemberFromLobbyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilO(input["MemberEntity"], MemberEntity);
                FromJsonUtilP(input["PreventRejoin"], PreventRejoin);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_MemberEntity; ToJsonUtilO(MemberEntity, each_MemberEntity); output["MemberEntity"] = each_MemberEntity;
                Json::Value each_PreventRejoin; ToJsonUtilP(PreventRejoin, each_PreventRejoin); output["PreventRejoin"] = each_PreventRejoin;
                return output;
            }
        };

        struct RequestMultiplayerServerRequest : public PlayFabRequestCommon
        {
            Boxed<BuildAliasParams> pfBuildAliasParams;
            std::string BuildId;
            std::map<std::string, std::string> CustomTags;
            std::list<std::string> InitialPlayers;
            std::list<std::string> PreferredRegions;
            std::string SessionCookie;
            std::string SessionId;

            RequestMultiplayerServerRequest() :
                PlayFabRequestCommon(),
                pfBuildAliasParams(),
                BuildId(),
                CustomTags(),
                InitialPlayers(),
                PreferredRegions(),
                SessionCookie(),
                SessionId()
            {}

            RequestMultiplayerServerRequest(const RequestMultiplayerServerRequest& src) :
                PlayFabRequestCommon(),
                pfBuildAliasParams(src.pfBuildAliasParams),
                BuildId(src.BuildId),
                CustomTags(src.CustomTags),
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
                FromJsonUtilS(input["CustomTags"], CustomTags);
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
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_InitialPlayers; ToJsonUtilS(InitialPlayers, each_InitialPlayers); output["InitialPlayers"] = each_InitialPlayers;
                Json::Value each_PreferredRegions; ToJsonUtilS(PreferredRegions, each_PreferredRegions); output["PreferredRegions"] = each_PreferredRegions;
                Json::Value each_SessionCookie; ToJsonUtilS(SessionCookie, each_SessionCookie); output["SessionCookie"] = each_SessionCookie;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                return output;
            }
        };

        struct RequestMultiplayerServerResponse : public PlayFabResultCommon
        {
            std::string BuildId;
            std::list<ConnectedPlayer> ConnectedPlayers;
            std::string FQDN;
            std::string IPV4Address;
            Boxed<time_t> LastStateTransitionTime;
            std::list<Port> Ports;
            std::list<PublicIpAddress> PublicIPV4Addresses;
            std::string Region;
            std::string ServerId;
            std::string SessionId;
            std::string State;
            std::string VmId;

            RequestMultiplayerServerResponse() :
                PlayFabResultCommon(),
                BuildId(),
                ConnectedPlayers(),
                FQDN(),
                IPV4Address(),
                LastStateTransitionTime(),
                Ports(),
                PublicIPV4Addresses(),
                Region(),
                ServerId(),
                SessionId(),
                State(),
                VmId()
            {}

            RequestMultiplayerServerResponse(const RequestMultiplayerServerResponse& src) :
                PlayFabResultCommon(),
                BuildId(src.BuildId),
                ConnectedPlayers(src.ConnectedPlayers),
                FQDN(src.FQDN),
                IPV4Address(src.IPV4Address),
                LastStateTransitionTime(src.LastStateTransitionTime),
                Ports(src.Ports),
                PublicIPV4Addresses(src.PublicIPV4Addresses),
                Region(src.Region),
                ServerId(src.ServerId),
                SessionId(src.SessionId),
                State(src.State),
                VmId(src.VmId)
            {}

            ~RequestMultiplayerServerResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilO(input["ConnectedPlayers"], ConnectedPlayers);
                FromJsonUtilS(input["FQDN"], FQDN);
                FromJsonUtilS(input["IPV4Address"], IPV4Address);
                FromJsonUtilT(input["LastStateTransitionTime"], LastStateTransitionTime);
                FromJsonUtilO(input["Ports"], Ports);
                FromJsonUtilO(input["PublicIPV4Addresses"], PublicIPV4Addresses);
                FromJsonUtilS(input["Region"], Region);
                FromJsonUtilS(input["ServerId"], ServerId);
                FromJsonUtilS(input["SessionId"], SessionId);
                FromJsonUtilS(input["State"], State);
                FromJsonUtilS(input["VmId"], VmId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_ConnectedPlayers; ToJsonUtilO(ConnectedPlayers, each_ConnectedPlayers); output["ConnectedPlayers"] = each_ConnectedPlayers;
                Json::Value each_FQDN; ToJsonUtilS(FQDN, each_FQDN); output["FQDN"] = each_FQDN;
                Json::Value each_IPV4Address; ToJsonUtilS(IPV4Address, each_IPV4Address); output["IPV4Address"] = each_IPV4Address;
                Json::Value each_LastStateTransitionTime; ToJsonUtilT(LastStateTransitionTime, each_LastStateTransitionTime); output["LastStateTransitionTime"] = each_LastStateTransitionTime;
                Json::Value each_Ports; ToJsonUtilO(Ports, each_Ports); output["Ports"] = each_Ports;
                Json::Value each_PublicIPV4Addresses; ToJsonUtilO(PublicIPV4Addresses, each_PublicIPV4Addresses); output["PublicIPV4Addresses"] = each_PublicIPV4Addresses;
                Json::Value each_Region; ToJsonUtilS(Region, each_Region); output["Region"] = each_Region;
                Json::Value each_ServerId; ToJsonUtilS(ServerId, each_ServerId); output["ServerId"] = each_ServerId;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                Json::Value each_State; ToJsonUtilS(State, each_State); output["State"] = each_State;
                Json::Value each_VmId; ToJsonUtilS(VmId, each_VmId); output["VmId"] = each_VmId;
                return output;
            }
        };

        struct RequestPartyServiceRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            PartyNetworkConfiguration NetworkConfiguration;
            std::string PartyId;
            std::list<std::string> PreferredRegions;

            RequestPartyServiceRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                NetworkConfiguration(),
                PartyId(),
                PreferredRegions()
            {}

            RequestPartyServiceRequest(const RequestPartyServiceRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                NetworkConfiguration(src.NetworkConfiguration),
                PartyId(src.PartyId),
                PreferredRegions(src.PreferredRegions)
            {}

            ~RequestPartyServiceRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["NetworkConfiguration"], NetworkConfiguration);
                FromJsonUtilS(input["PartyId"], PartyId);
                FromJsonUtilS(input["PreferredRegions"], PreferredRegions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_NetworkConfiguration; ToJsonUtilO(NetworkConfiguration, each_NetworkConfiguration); output["NetworkConfiguration"] = each_NetworkConfiguration;
                Json::Value each_PartyId; ToJsonUtilS(PartyId, each_PartyId); output["PartyId"] = each_PartyId;
                Json::Value each_PreferredRegions; ToJsonUtilS(PreferredRegions, each_PreferredRegions); output["PreferredRegions"] = each_PreferredRegions;
                return output;
            }
        };

        struct RequestPartyServiceResponse : public PlayFabResultCommon
        {
            std::string InvitationId;
            std::string PartyId;
            std::string SerializedNetworkDescriptor;

            RequestPartyServiceResponse() :
                PlayFabResultCommon(),
                InvitationId(),
                PartyId(),
                SerializedNetworkDescriptor()
            {}

            RequestPartyServiceResponse(const RequestPartyServiceResponse& src) :
                PlayFabResultCommon(),
                InvitationId(src.InvitationId),
                PartyId(src.PartyId),
                SerializedNetworkDescriptor(src.SerializedNetworkDescriptor)
            {}

            ~RequestPartyServiceResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["InvitationId"], InvitationId);
                FromJsonUtilS(input["PartyId"], PartyId);
                FromJsonUtilS(input["SerializedNetworkDescriptor"], SerializedNetworkDescriptor);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_InvitationId; ToJsonUtilS(InvitationId, each_InvitationId); output["InvitationId"] = each_InvitationId;
                Json::Value each_PartyId; ToJsonUtilS(PartyId, each_PartyId); output["PartyId"] = each_PartyId;
                Json::Value each_SerializedNetworkDescriptor; ToJsonUtilS(SerializedNetworkDescriptor, each_SerializedNetworkDescriptor); output["SerializedNetworkDescriptor"] = each_SerializedNetworkDescriptor;
                return output;
            }
        };

        struct RolloverContainerRegistryCredentialsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            RolloverContainerRegistryCredentialsRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            RolloverContainerRegistryCredentialsRequest(const RolloverContainerRegistryCredentialsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~RolloverContainerRegistryCredentialsRequest() = default;

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

        struct Secret : public PlayFabBaseModel
        {
            Boxed<time_t> ExpirationDate;
            std::string Name;
            std::string Value;

            Secret() :
                PlayFabBaseModel(),
                ExpirationDate(),
                Name(),
                Value()
            {}

            Secret(const Secret& src) :
                PlayFabBaseModel(),
                ExpirationDate(src.ExpirationDate),
                Name(src.Name),
                Value(src.Value)
            {}

            ~Secret() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilT(input["ExpirationDate"], ExpirationDate);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilS(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExpirationDate; ToJsonUtilT(ExpirationDate, each_ExpirationDate); output["ExpirationDate"] = each_ExpirationDate;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Value; ToJsonUtilS(Value, each_Value); output["Value"] = each_Value;
                return output;
            }
        };

        struct ShutdownMultiplayerServerRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string SessionId;

            ShutdownMultiplayerServerRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                SessionId()
            {}

            ShutdownMultiplayerServerRequest(const ShutdownMultiplayerServerRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                SessionId(src.SessionId)
            {}

            ~ShutdownMultiplayerServerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["SessionId"], SessionId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_SessionId; ToJsonUtilS(SessionId, each_SessionId); output["SessionId"] = each_SessionId;
                return output;
            }
        };

        struct SubscribeToLobbyResourceRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey pfEntityKey;
            std::string PubSubConnectionHandle;
            std::string ResourceId;
            Uint32 SubscriptionVersion;
            SubscriptionType Type;

            SubscribeToLobbyResourceRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                pfEntityKey(),
                PubSubConnectionHandle(),
                ResourceId(),
                SubscriptionVersion(),
                Type()
            {}

            SubscribeToLobbyResourceRequest(const SubscribeToLobbyResourceRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                pfEntityKey(src.pfEntityKey),
                PubSubConnectionHandle(src.PubSubConnectionHandle),
                ResourceId(src.ResourceId),
                SubscriptionVersion(src.SubscriptionVersion),
                Type(src.Type)
            {}

            ~SubscribeToLobbyResourceRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["EntityKey"], pfEntityKey);
                FromJsonUtilS(input["PubSubConnectionHandle"], PubSubConnectionHandle);
                FromJsonUtilS(input["ResourceId"], ResourceId);
                FromJsonUtilP(input["SubscriptionVersion"], SubscriptionVersion);
                FromJsonEnum(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_pfEntityKey; ToJsonUtilO(pfEntityKey, each_pfEntityKey); output["EntityKey"] = each_pfEntityKey;
                Json::Value each_PubSubConnectionHandle; ToJsonUtilS(PubSubConnectionHandle, each_PubSubConnectionHandle); output["PubSubConnectionHandle"] = each_PubSubConnectionHandle;
                Json::Value each_ResourceId; ToJsonUtilS(ResourceId, each_ResourceId); output["ResourceId"] = each_ResourceId;
                Json::Value each_SubscriptionVersion; ToJsonUtilP(SubscriptionVersion, each_SubscriptionVersion); output["SubscriptionVersion"] = each_SubscriptionVersion;
                Json::Value each_Type; ToJsonEnum(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct SubscribeToLobbyResourceResult : public PlayFabResultCommon
        {
            std::string Topic;

            SubscribeToLobbyResourceResult() :
                PlayFabResultCommon(),
                Topic()
            {}

            SubscribeToLobbyResourceResult(const SubscribeToLobbyResourceResult& src) :
                PlayFabResultCommon(),
                Topic(src.Topic)
            {}

            ~SubscribeToLobbyResourceResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Topic"], Topic);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Topic; ToJsonUtilS(Topic, each_Topic); output["Topic"] = each_Topic;
                return output;
            }
        };

        struct UnsubscribeFromLobbyResourceRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey pfEntityKey;
            std::string PubSubConnectionHandle;
            std::string ResourceId;
            Uint32 SubscriptionVersion;
            SubscriptionType Type;

            UnsubscribeFromLobbyResourceRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                pfEntityKey(),
                PubSubConnectionHandle(),
                ResourceId(),
                SubscriptionVersion(),
                Type()
            {}

            UnsubscribeFromLobbyResourceRequest(const UnsubscribeFromLobbyResourceRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                pfEntityKey(src.pfEntityKey),
                PubSubConnectionHandle(src.PubSubConnectionHandle),
                ResourceId(src.ResourceId),
                SubscriptionVersion(src.SubscriptionVersion),
                Type(src.Type)
            {}

            ~UnsubscribeFromLobbyResourceRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["EntityKey"], pfEntityKey);
                FromJsonUtilS(input["PubSubConnectionHandle"], PubSubConnectionHandle);
                FromJsonUtilS(input["ResourceId"], ResourceId);
                FromJsonUtilP(input["SubscriptionVersion"], SubscriptionVersion);
                FromJsonEnum(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_pfEntityKey; ToJsonUtilO(pfEntityKey, each_pfEntityKey); output["EntityKey"] = each_pfEntityKey;
                Json::Value each_PubSubConnectionHandle; ToJsonUtilS(PubSubConnectionHandle, each_PubSubConnectionHandle); output["PubSubConnectionHandle"] = each_PubSubConnectionHandle;
                Json::Value each_ResourceId; ToJsonUtilS(ResourceId, each_ResourceId); output["ResourceId"] = each_ResourceId;
                Json::Value each_SubscriptionVersion; ToJsonUtilP(SubscriptionVersion, each_SubscriptionVersion); output["SubscriptionVersion"] = each_SubscriptionVersion;
                Json::Value each_Type; ToJsonEnum(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct UntagContainerImageRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string ImageName;
            std::string Tag;

            UntagContainerImageRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                ImageName(),
                Tag()
            {}

            UntagContainerImageRequest(const UntagContainerImageRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                ImageName(src.ImageName),
                Tag(src.Tag)
            {}

            ~UntagContainerImageRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["ImageName"], ImageName);
                FromJsonUtilS(input["Tag"], Tag);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
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
            std::map<std::string, std::string> CustomTags;

            UpdateBuildAliasRequest() :
                PlayFabRequestCommon(),
                AliasId(),
                AliasName(),
                BuildSelectionCriteria(),
                CustomTags()
            {}

            UpdateBuildAliasRequest(const UpdateBuildAliasRequest& src) :
                PlayFabRequestCommon(),
                AliasId(src.AliasId),
                AliasName(src.AliasName),
                BuildSelectionCriteria(src.BuildSelectionCriteria),
                CustomTags(src.CustomTags)
            {}

            ~UpdateBuildAliasRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AliasId"], AliasId);
                FromJsonUtilS(input["AliasName"], AliasName);
                FromJsonUtilO(input["BuildSelectionCriteria"], BuildSelectionCriteria);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AliasId; ToJsonUtilS(AliasId, each_AliasId); output["AliasId"] = each_AliasId;
                Json::Value each_AliasName; ToJsonUtilS(AliasName, each_AliasName); output["AliasName"] = each_AliasName;
                Json::Value each_BuildSelectionCriteria; ToJsonUtilO(BuildSelectionCriteria, each_BuildSelectionCriteria); output["BuildSelectionCriteria"] = each_BuildSelectionCriteria;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct UpdateBuildNameRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::string BuildName;
            std::map<std::string, std::string> CustomTags;

            UpdateBuildNameRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                BuildName(),
                CustomTags()
            {}

            UpdateBuildNameRequest(const UpdateBuildNameRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                CustomTags(src.CustomTags)
            {}

            ~UpdateBuildNameRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilS(input["BuildName"], BuildName);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildName; ToJsonUtilS(BuildName, each_BuildName); output["BuildName"] = each_BuildName;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct UpdateBuildRegionRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            BuildRegionParams BuildRegion;
            std::map<std::string, std::string> CustomTags;

            UpdateBuildRegionRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                BuildRegion(),
                CustomTags()
            {}

            UpdateBuildRegionRequest(const UpdateBuildRegionRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                BuildRegion(src.BuildRegion),
                CustomTags(src.CustomTags)
            {}

            ~UpdateBuildRegionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilO(input["BuildRegion"], BuildRegion);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildRegion; ToJsonUtilO(BuildRegion, each_BuildRegion); output["BuildRegion"] = each_BuildRegion;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct UpdateBuildRegionsRequest : public PlayFabRequestCommon
        {
            std::string BuildId;
            std::list<BuildRegionParams> BuildRegions;
            std::map<std::string, std::string> CustomTags;

            UpdateBuildRegionsRequest() :
                PlayFabRequestCommon(),
                BuildId(),
                BuildRegions(),
                CustomTags()
            {}

            UpdateBuildRegionsRequest(const UpdateBuildRegionsRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId),
                BuildRegions(src.BuildRegions),
                CustomTags(src.CustomTags)
            {}

            ~UpdateBuildRegionsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["BuildId"], BuildId);
                FromJsonUtilO(input["BuildRegions"], BuildRegions);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output["BuildId"] = each_BuildId;
                Json::Value each_BuildRegions; ToJsonUtilO(BuildRegions, each_BuildRegions); output["BuildRegions"] = each_BuildRegions;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct UpdateLobbyAsServerRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string LobbyId;
            std::map<std::string, std::string> ServerData;
            std::list<std::string> ServerDataToDelete;
            Boxed<EntityKey> ServerEntity;

            UpdateLobbyAsServerRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                LobbyId(),
                ServerData(),
                ServerDataToDelete(),
                ServerEntity()
            {}

            UpdateLobbyAsServerRequest(const UpdateLobbyAsServerRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                LobbyId(src.LobbyId),
                ServerData(src.ServerData),
                ServerDataToDelete(src.ServerDataToDelete),
                ServerEntity(src.ServerEntity)
            {}

            ~UpdateLobbyAsServerRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilS(input["ServerData"], ServerData);
                FromJsonUtilS(input["ServerDataToDelete"], ServerDataToDelete);
                FromJsonUtilO(input["ServerEntity"], ServerEntity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_ServerData; ToJsonUtilS(ServerData, each_ServerData); output["ServerData"] = each_ServerData;
                Json::Value each_ServerDataToDelete; ToJsonUtilS(ServerDataToDelete, each_ServerDataToDelete); output["ServerDataToDelete"] = each_ServerDataToDelete;
                Json::Value each_ServerEntity; ToJsonUtilO(ServerEntity, each_ServerEntity); output["ServerEntity"] = each_ServerEntity;
                return output;
            }
        };

        struct UpdateLobbyRequest : public PlayFabRequestCommon
        {
            Boxed<AccessPolicy> pfAccessPolicy;
            std::map<std::string, std::string> CustomTags;
            std::map<std::string, std::string> LobbyData;
            std::list<std::string> LobbyDataToDelete;
            std::string LobbyId;
            Boxed<Uint32> MaxPlayers;
            std::map<std::string, std::string> MemberData;
            std::list<std::string> MemberDataToDelete;
            Boxed<EntityKey> MemberEntity;
            Boxed<MembershipLock> pfMembershipLock;
            Boxed<EntityKey> Owner;
            std::map<std::string, std::string> SearchData;
            std::list<std::string> SearchDataToDelete;

            UpdateLobbyRequest() :
                PlayFabRequestCommon(),
                pfAccessPolicy(),
                CustomTags(),
                LobbyData(),
                LobbyDataToDelete(),
                LobbyId(),
                MaxPlayers(),
                MemberData(),
                MemberDataToDelete(),
                MemberEntity(),
                pfMembershipLock(),
                Owner(),
                SearchData(),
                SearchDataToDelete()
            {}

            UpdateLobbyRequest(const UpdateLobbyRequest& src) :
                PlayFabRequestCommon(),
                pfAccessPolicy(src.pfAccessPolicy),
                CustomTags(src.CustomTags),
                LobbyData(src.LobbyData),
                LobbyDataToDelete(src.LobbyDataToDelete),
                LobbyId(src.LobbyId),
                MaxPlayers(src.MaxPlayers),
                MemberData(src.MemberData),
                MemberDataToDelete(src.MemberDataToDelete),
                MemberEntity(src.MemberEntity),
                pfMembershipLock(src.pfMembershipLock),
                Owner(src.Owner),
                SearchData(src.SearchData),
                SearchDataToDelete(src.SearchDataToDelete)
            {}

            ~UpdateLobbyRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilE(input["AccessPolicy"], pfAccessPolicy);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["LobbyData"], LobbyData);
                FromJsonUtilS(input["LobbyDataToDelete"], LobbyDataToDelete);
                FromJsonUtilS(input["LobbyId"], LobbyId);
                FromJsonUtilP(input["MaxPlayers"], MaxPlayers);
                FromJsonUtilS(input["MemberData"], MemberData);
                FromJsonUtilS(input["MemberDataToDelete"], MemberDataToDelete);
                FromJsonUtilO(input["MemberEntity"], MemberEntity);
                FromJsonUtilE(input["MembershipLock"], pfMembershipLock);
                FromJsonUtilO(input["Owner"], Owner);
                FromJsonUtilS(input["SearchData"], SearchData);
                FromJsonUtilS(input["SearchDataToDelete"], SearchDataToDelete);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfAccessPolicy; ToJsonUtilE(pfAccessPolicy, each_pfAccessPolicy); output["AccessPolicy"] = each_pfAccessPolicy;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_LobbyData; ToJsonUtilS(LobbyData, each_LobbyData); output["LobbyData"] = each_LobbyData;
                Json::Value each_LobbyDataToDelete; ToJsonUtilS(LobbyDataToDelete, each_LobbyDataToDelete); output["LobbyDataToDelete"] = each_LobbyDataToDelete;
                Json::Value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output["LobbyId"] = each_LobbyId;
                Json::Value each_MaxPlayers; ToJsonUtilP(MaxPlayers, each_MaxPlayers); output["MaxPlayers"] = each_MaxPlayers;
                Json::Value each_MemberData; ToJsonUtilS(MemberData, each_MemberData); output["MemberData"] = each_MemberData;
                Json::Value each_MemberDataToDelete; ToJsonUtilS(MemberDataToDelete, each_MemberDataToDelete); output["MemberDataToDelete"] = each_MemberDataToDelete;
                Json::Value each_MemberEntity; ToJsonUtilO(MemberEntity, each_MemberEntity); output["MemberEntity"] = each_MemberEntity;
                Json::Value each_pfMembershipLock; ToJsonUtilE(pfMembershipLock, each_pfMembershipLock); output["MembershipLock"] = each_pfMembershipLock;
                Json::Value each_Owner; ToJsonUtilO(Owner, each_Owner); output["Owner"] = each_Owner;
                Json::Value each_SearchData; ToJsonUtilS(SearchData, each_SearchData); output["SearchData"] = each_SearchData;
                Json::Value each_SearchDataToDelete; ToJsonUtilS(SearchDataToDelete, each_SearchDataToDelete); output["SearchDataToDelete"] = each_SearchDataToDelete;
                return output;
            }
        };

        struct UploadCertificateRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<bool> ForceUpdate;
            Certificate GameCertificate;

            UploadCertificateRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                ForceUpdate(),
                GameCertificate()
            {}

            UploadCertificateRequest(const UploadCertificateRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                ForceUpdate(src.ForceUpdate),
                GameCertificate(src.GameCertificate)
            {}

            ~UploadCertificateRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["ForceUpdate"], ForceUpdate);
                FromJsonUtilO(input["GameCertificate"], GameCertificate);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_ForceUpdate; ToJsonUtilP(ForceUpdate, each_ForceUpdate); output["ForceUpdate"] = each_ForceUpdate;
                Json::Value each_GameCertificate; ToJsonUtilO(GameCertificate, each_GameCertificate); output["GameCertificate"] = each_GameCertificate;
                return output;
            }
        };

        struct UploadSecretRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<bool> ForceUpdate;
            Secret GameSecret;

            UploadSecretRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                ForceUpdate(),
                GameSecret()
            {}

            UploadSecretRequest(const UploadSecretRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                ForceUpdate(src.ForceUpdate),
                GameSecret(src.GameSecret)
            {}

            ~UploadSecretRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["ForceUpdate"], ForceUpdate);
                FromJsonUtilO(input["GameSecret"], GameSecret);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_ForceUpdate; ToJsonUtilP(ForceUpdate, each_ForceUpdate); output["ForceUpdate"] = each_ForceUpdate;
                Json::Value each_GameSecret; ToJsonUtilO(GameSecret, each_GameSecret); output["GameSecret"] = each_GameSecret;
                return output;
            }
        };

    }
}

#endif
