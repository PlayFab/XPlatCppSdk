#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace EconomyModels
    {
        // Economy Enums
        enum class ConcernCategory
        {
            ConcernCategoryNone,
            ConcernCategoryOffensiveContent,
            ConcernCategoryChildExploitation,
            ConcernCategoryMalwareOrVirus,
            ConcernCategoryPrivacyConcerns,
            ConcernCategoryMisleadingApp,
            ConcernCategoryPoorPerformance,
            ConcernCategoryReviewResponse,
            ConcernCategorySpamAdvertising,
            ConcernCategoryProfanity
        };

        inline void ToJsonEnum(const ConcernCategory input, Json::Value& output)
        {
            if (input == ConcernCategory::ConcernCategoryNone)
            {
                output = Json::Value("None");
                return;
            }
            if (input == ConcernCategory::ConcernCategoryOffensiveContent)
            {
                output = Json::Value("OffensiveContent");
                return;
            }
            if (input == ConcernCategory::ConcernCategoryChildExploitation)
            {
                output = Json::Value("ChildExploitation");
                return;
            }
            if (input == ConcernCategory::ConcernCategoryMalwareOrVirus)
            {
                output = Json::Value("MalwareOrVirus");
                return;
            }
            if (input == ConcernCategory::ConcernCategoryPrivacyConcerns)
            {
                output = Json::Value("PrivacyConcerns");
                return;
            }
            if (input == ConcernCategory::ConcernCategoryMisleadingApp)
            {
                output = Json::Value("MisleadingApp");
                return;
            }
            if (input == ConcernCategory::ConcernCategoryPoorPerformance)
            {
                output = Json::Value("PoorPerformance");
                return;
            }
            if (input == ConcernCategory::ConcernCategoryReviewResponse)
            {
                output = Json::Value("ReviewResponse");
                return;
            }
            if (input == ConcernCategory::ConcernCategorySpamAdvertising)
            {
                output = Json::Value("SpamAdvertising");
                return;
            }
            if (input == ConcernCategory::ConcernCategoryProfanity)
            {
                output = Json::Value("Profanity");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, ConcernCategory& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "None")
            {
                output = ConcernCategory::ConcernCategoryNone;
                return;
            }
            if (inputStr == "OffensiveContent")
            {
                output = ConcernCategory::ConcernCategoryOffensiveContent;
                return;
            }
            if (inputStr == "ChildExploitation")
            {
                output = ConcernCategory::ConcernCategoryChildExploitation;
                return;
            }
            if (inputStr == "MalwareOrVirus")
            {
                output = ConcernCategory::ConcernCategoryMalwareOrVirus;
                return;
            }
            if (inputStr == "PrivacyConcerns")
            {
                output = ConcernCategory::ConcernCategoryPrivacyConcerns;
                return;
            }
            if (inputStr == "MisleadingApp")
            {
                output = ConcernCategory::ConcernCategoryMisleadingApp;
                return;
            }
            if (inputStr == "PoorPerformance")
            {
                output = ConcernCategory::ConcernCategoryPoorPerformance;
                return;
            }
            if (inputStr == "ReviewResponse")
            {
                output = ConcernCategory::ConcernCategoryReviewResponse;
                return;
            }
            if (inputStr == "SpamAdvertising")
            {
                output = ConcernCategory::ConcernCategorySpamAdvertising;
                return;
            }
            if (inputStr == "Profanity")
            {
                output = ConcernCategory::ConcernCategoryProfanity;
                return;
            }
        }

        enum class CountryCode
        {
            CountryCodeAF,
            CountryCodeAX,
            CountryCodeAL,
            CountryCodeDZ,
            CountryCodeAS,
            CountryCodeAD,
            CountryCodeAO,
            CountryCodeAI,
            CountryCodeAQ,
            CountryCodeAG,
            CountryCodeAR,
            CountryCodeAM,
            CountryCodeAW,
            CountryCodeAU,
            CountryCodeAT,
            CountryCodeAZ,
            CountryCodeBS,
            CountryCodeBH,
            CountryCodeBD,
            CountryCodeBB,
            CountryCodeBY,
            CountryCodeBE,
            CountryCodeBZ,
            CountryCodeBJ,
            CountryCodeBM,
            CountryCodeBT,
            CountryCodeBO,
            CountryCodeBQ,
            CountryCodeBA,
            CountryCodeBW,
            CountryCodeBV,
            CountryCodeBR,
            CountryCodeIO,
            CountryCodeBN,
            CountryCodeBG,
            CountryCodeBF,
            CountryCodeBI,
            CountryCodeKH,
            CountryCodeCM,
            CountryCodeCA,
            CountryCodeCV,
            CountryCodeKY,
            CountryCodeCF,
            CountryCodeTD,
            CountryCodeCL,
            CountryCodeCN,
            CountryCodeCX,
            CountryCodeCC,
            CountryCodeCO,
            CountryCodeKM,
            CountryCodeCG,
            CountryCodeCD,
            CountryCodeCK,
            CountryCodeCR,
            CountryCodeCI,
            CountryCodeHR,
            CountryCodeCU,
            CountryCodeCW,
            CountryCodeCY,
            CountryCodeCZ,
            CountryCodeDK,
            CountryCodeDJ,
            CountryCodeDM,
            CountryCodeDO,
            CountryCodeEC,
            CountryCodeEG,
            CountryCodeSV,
            CountryCodeGQ,
            CountryCodeER,
            CountryCodeEE,
            CountryCodeET,
            CountryCodeFK,
            CountryCodeFO,
            CountryCodeFJ,
            CountryCodeFI,
            CountryCodeFR,
            CountryCodeGF,
            CountryCodePF,
            CountryCodeTF,
            CountryCodeGA,
            CountryCodeGM,
            CountryCodeGE,
            CountryCodeDE,
            CountryCodeGH,
            CountryCodeGI,
            CountryCodeGR,
            CountryCodeGL,
            CountryCodeGD,
            CountryCodeGP,
            CountryCodeGU,
            CountryCodeGT,
            CountryCodeGG,
            CountryCodeGN,
            CountryCodeGW,
            CountryCodeGY,
            CountryCodeHT,
            CountryCodeHM,
            CountryCodeVA,
            CountryCodeHN,
            CountryCodeHK,
            CountryCodeHU,
            CountryCodeIS,
            CountryCodeIN,
            CountryCodeID,
            CountryCodeIR,
            CountryCodeIQ,
            CountryCodeIE,
            CountryCodeIM,
            CountryCodeIL,
            CountryCodeIT,
            CountryCodeJM,
            CountryCodeJP,
            CountryCodeJE,
            CountryCodeJO,
            CountryCodeKZ,
            CountryCodeKE,
            CountryCodeKI,
            CountryCodeKP,
            CountryCodeKR,
            CountryCodeKW,
            CountryCodeKG,
            CountryCodeLA,
            CountryCodeLV,
            CountryCodeLB,
            CountryCodeLS,
            CountryCodeLR,
            CountryCodeLY,
            CountryCodeLI,
            CountryCodeLT,
            CountryCodeLU,
            CountryCodeMO,
            CountryCodeMK,
            CountryCodeMG,
            CountryCodeMW,
            CountryCodeMY,
            CountryCodeMV,
            CountryCodeML,
            CountryCodeMT,
            CountryCodeMH,
            CountryCodeMQ,
            CountryCodeMR,
            CountryCodeMU,
            CountryCodeYT,
            CountryCodeMX,
            CountryCodeFM,
            CountryCodeMD,
            CountryCodeMC,
            CountryCodeMN,
            CountryCodeME,
            CountryCodeMS,
            CountryCodeMA,
            CountryCodeMZ,
            CountryCodeMM,
            CountryCodeNA,
            CountryCodeNR,
            CountryCodeNP,
            CountryCodeNL,
            CountryCodeNC,
            CountryCodeNZ,
            CountryCodeNI,
            CountryCodeNE,
            CountryCodeNG,
            CountryCodeNU,
            CountryCodeNF,
            CountryCodeMP,
            CountryCodeNO,
            CountryCodeOM,
            CountryCodePK,
            CountryCodePW,
            CountryCodePS,
            CountryCodePA,
            CountryCodePG,
            CountryCodePY,
            CountryCodePE,
            CountryCodePH,
            CountryCodePN,
            CountryCodePL,
            CountryCodePT,
            CountryCodePR,
            CountryCodeQA,
            CountryCodeRE,
            CountryCodeRO,
            CountryCodeRU,
            CountryCodeRW,
            CountryCodeBL,
            CountryCodeSH,
            CountryCodeKN,
            CountryCodeLC,
            CountryCodeMF,
            CountryCodePM,
            CountryCodeVC,
            CountryCodeWS,
            CountryCodeSM,
            CountryCodeST,
            CountryCodeSA,
            CountryCodeSN,
            CountryCodeRS,
            CountryCodeSC,
            CountryCodeSL,
            CountryCodeSG,
            CountryCodeSX,
            CountryCodeSK,
            CountryCodeSI,
            CountryCodeSB,
            CountryCodeSO,
            CountryCodeZA,
            CountryCodeGS,
            CountryCodeSS,
            CountryCodeES,
            CountryCodeLK,
            CountryCodeSD,
            CountryCodeSR,
            CountryCodeSJ,
            CountryCodeSZ,
            CountryCodeSE,
            CountryCodeCH,
            CountryCodeSY,
            CountryCodeTW,
            CountryCodeTJ,
            CountryCodeTZ,
            CountryCodeTH,
            CountryCodeTL,
            CountryCodeTG,
            CountryCodeTK,
            CountryCodeTO,
            CountryCodeTT,
            CountryCodeTN,
            CountryCodeTR,
            CountryCodeTM,
            CountryCodeTC,
            CountryCodeTV,
            CountryCodeUG,
            CountryCodeUA,
            CountryCodeAE,
            CountryCodeGB,
            CountryCodeUS,
            CountryCodeUM,
            CountryCodeUY,
            CountryCodeUZ,
            CountryCodeVU,
            CountryCodeVE,
            CountryCodeVN,
            CountryCodeVG,
            CountryCodeVI,
            CountryCodeWF,
            CountryCodeEH,
            CountryCodeYE,
            CountryCodeZM,
            CountryCodeZW
        };

        inline void ToJsonEnum(const CountryCode input, Json::Value& output)
        {
            if (input == CountryCode::CountryCodeAF)
            {
                output = Json::Value("AF");
                return;
            }
            if (input == CountryCode::CountryCodeAX)
            {
                output = Json::Value("AX");
                return;
            }
            if (input == CountryCode::CountryCodeAL)
            {
                output = Json::Value("AL");
                return;
            }
            if (input == CountryCode::CountryCodeDZ)
            {
                output = Json::Value("DZ");
                return;
            }
            if (input == CountryCode::CountryCodeAS)
            {
                output = Json::Value("AS");
                return;
            }
            if (input == CountryCode::CountryCodeAD)
            {
                output = Json::Value("AD");
                return;
            }
            if (input == CountryCode::CountryCodeAO)
            {
                output = Json::Value("AO");
                return;
            }
            if (input == CountryCode::CountryCodeAI)
            {
                output = Json::Value("AI");
                return;
            }
            if (input == CountryCode::CountryCodeAQ)
            {
                output = Json::Value("AQ");
                return;
            }
            if (input == CountryCode::CountryCodeAG)
            {
                output = Json::Value("AG");
                return;
            }
            if (input == CountryCode::CountryCodeAR)
            {
                output = Json::Value("AR");
                return;
            }
            if (input == CountryCode::CountryCodeAM)
            {
                output = Json::Value("AM");
                return;
            }
            if (input == CountryCode::CountryCodeAW)
            {
                output = Json::Value("AW");
                return;
            }
            if (input == CountryCode::CountryCodeAU)
            {
                output = Json::Value("AU");
                return;
            }
            if (input == CountryCode::CountryCodeAT)
            {
                output = Json::Value("AT");
                return;
            }
            if (input == CountryCode::CountryCodeAZ)
            {
                output = Json::Value("AZ");
                return;
            }
            if (input == CountryCode::CountryCodeBS)
            {
                output = Json::Value("BS");
                return;
            }
            if (input == CountryCode::CountryCodeBH)
            {
                output = Json::Value("BH");
                return;
            }
            if (input == CountryCode::CountryCodeBD)
            {
                output = Json::Value("BD");
                return;
            }
            if (input == CountryCode::CountryCodeBB)
            {
                output = Json::Value("BB");
                return;
            }
            if (input == CountryCode::CountryCodeBY)
            {
                output = Json::Value("BY");
                return;
            }
            if (input == CountryCode::CountryCodeBE)
            {
                output = Json::Value("BE");
                return;
            }
            if (input == CountryCode::CountryCodeBZ)
            {
                output = Json::Value("BZ");
                return;
            }
            if (input == CountryCode::CountryCodeBJ)
            {
                output = Json::Value("BJ");
                return;
            }
            if (input == CountryCode::CountryCodeBM)
            {
                output = Json::Value("BM");
                return;
            }
            if (input == CountryCode::CountryCodeBT)
            {
                output = Json::Value("BT");
                return;
            }
            if (input == CountryCode::CountryCodeBO)
            {
                output = Json::Value("BO");
                return;
            }
            if (input == CountryCode::CountryCodeBQ)
            {
                output = Json::Value("BQ");
                return;
            }
            if (input == CountryCode::CountryCodeBA)
            {
                output = Json::Value("BA");
                return;
            }
            if (input == CountryCode::CountryCodeBW)
            {
                output = Json::Value("BW");
                return;
            }
            if (input == CountryCode::CountryCodeBV)
            {
                output = Json::Value("BV");
                return;
            }
            if (input == CountryCode::CountryCodeBR)
            {
                output = Json::Value("BR");
                return;
            }
            if (input == CountryCode::CountryCodeIO)
            {
                output = Json::Value("IO");
                return;
            }
            if (input == CountryCode::CountryCodeBN)
            {
                output = Json::Value("BN");
                return;
            }
            if (input == CountryCode::CountryCodeBG)
            {
                output = Json::Value("BG");
                return;
            }
            if (input == CountryCode::CountryCodeBF)
            {
                output = Json::Value("BF");
                return;
            }
            if (input == CountryCode::CountryCodeBI)
            {
                output = Json::Value("BI");
                return;
            }
            if (input == CountryCode::CountryCodeKH)
            {
                output = Json::Value("KH");
                return;
            }
            if (input == CountryCode::CountryCodeCM)
            {
                output = Json::Value("CM");
                return;
            }
            if (input == CountryCode::CountryCodeCA)
            {
                output = Json::Value("CA");
                return;
            }
            if (input == CountryCode::CountryCodeCV)
            {
                output = Json::Value("CV");
                return;
            }
            if (input == CountryCode::CountryCodeKY)
            {
                output = Json::Value("KY");
                return;
            }
            if (input == CountryCode::CountryCodeCF)
            {
                output = Json::Value("CF");
                return;
            }
            if (input == CountryCode::CountryCodeTD)
            {
                output = Json::Value("TD");
                return;
            }
            if (input == CountryCode::CountryCodeCL)
            {
                output = Json::Value("CL");
                return;
            }
            if (input == CountryCode::CountryCodeCN)
            {
                output = Json::Value("CN");
                return;
            }
            if (input == CountryCode::CountryCodeCX)
            {
                output = Json::Value("CX");
                return;
            }
            if (input == CountryCode::CountryCodeCC)
            {
                output = Json::Value("CC");
                return;
            }
            if (input == CountryCode::CountryCodeCO)
            {
                output = Json::Value("CO");
                return;
            }
            if (input == CountryCode::CountryCodeKM)
            {
                output = Json::Value("KM");
                return;
            }
            if (input == CountryCode::CountryCodeCG)
            {
                output = Json::Value("CG");
                return;
            }
            if (input == CountryCode::CountryCodeCD)
            {
                output = Json::Value("CD");
                return;
            }
            if (input == CountryCode::CountryCodeCK)
            {
                output = Json::Value("CK");
                return;
            }
            if (input == CountryCode::CountryCodeCR)
            {
                output = Json::Value("CR");
                return;
            }
            if (input == CountryCode::CountryCodeCI)
            {
                output = Json::Value("CI");
                return;
            }
            if (input == CountryCode::CountryCodeHR)
            {
                output = Json::Value("HR");
                return;
            }
            if (input == CountryCode::CountryCodeCU)
            {
                output = Json::Value("CU");
                return;
            }
            if (input == CountryCode::CountryCodeCW)
            {
                output = Json::Value("CW");
                return;
            }
            if (input == CountryCode::CountryCodeCY)
            {
                output = Json::Value("CY");
                return;
            }
            if (input == CountryCode::CountryCodeCZ)
            {
                output = Json::Value("CZ");
                return;
            }
            if (input == CountryCode::CountryCodeDK)
            {
                output = Json::Value("DK");
                return;
            }
            if (input == CountryCode::CountryCodeDJ)
            {
                output = Json::Value("DJ");
                return;
            }
            if (input == CountryCode::CountryCodeDM)
            {
                output = Json::Value("DM");
                return;
            }
            if (input == CountryCode::CountryCodeDO)
            {
                output = Json::Value("DO");
                return;
            }
            if (input == CountryCode::CountryCodeEC)
            {
                output = Json::Value("EC");
                return;
            }
            if (input == CountryCode::CountryCodeEG)
            {
                output = Json::Value("EG");
                return;
            }
            if (input == CountryCode::CountryCodeSV)
            {
                output = Json::Value("SV");
                return;
            }
            if (input == CountryCode::CountryCodeGQ)
            {
                output = Json::Value("GQ");
                return;
            }
            if (input == CountryCode::CountryCodeER)
            {
                output = Json::Value("ER");
                return;
            }
            if (input == CountryCode::CountryCodeEE)
            {
                output = Json::Value("EE");
                return;
            }
            if (input == CountryCode::CountryCodeET)
            {
                output = Json::Value("ET");
                return;
            }
            if (input == CountryCode::CountryCodeFK)
            {
                output = Json::Value("FK");
                return;
            }
            if (input == CountryCode::CountryCodeFO)
            {
                output = Json::Value("FO");
                return;
            }
            if (input == CountryCode::CountryCodeFJ)
            {
                output = Json::Value("FJ");
                return;
            }
            if (input == CountryCode::CountryCodeFI)
            {
                output = Json::Value("FI");
                return;
            }
            if (input == CountryCode::CountryCodeFR)
            {
                output = Json::Value("FR");
                return;
            }
            if (input == CountryCode::CountryCodeGF)
            {
                output = Json::Value("GF");
                return;
            }
            if (input == CountryCode::CountryCodePF)
            {
                output = Json::Value("PF");
                return;
            }
            if (input == CountryCode::CountryCodeTF)
            {
                output = Json::Value("TF");
                return;
            }
            if (input == CountryCode::CountryCodeGA)
            {
                output = Json::Value("GA");
                return;
            }
            if (input == CountryCode::CountryCodeGM)
            {
                output = Json::Value("GM");
                return;
            }
            if (input == CountryCode::CountryCodeGE)
            {
                output = Json::Value("GE");
                return;
            }
            if (input == CountryCode::CountryCodeDE)
            {
                output = Json::Value("DE");
                return;
            }
            if (input == CountryCode::CountryCodeGH)
            {
                output = Json::Value("GH");
                return;
            }
            if (input == CountryCode::CountryCodeGI)
            {
                output = Json::Value("GI");
                return;
            }
            if (input == CountryCode::CountryCodeGR)
            {
                output = Json::Value("GR");
                return;
            }
            if (input == CountryCode::CountryCodeGL)
            {
                output = Json::Value("GL");
                return;
            }
            if (input == CountryCode::CountryCodeGD)
            {
                output = Json::Value("GD");
                return;
            }
            if (input == CountryCode::CountryCodeGP)
            {
                output = Json::Value("GP");
                return;
            }
            if (input == CountryCode::CountryCodeGU)
            {
                output = Json::Value("GU");
                return;
            }
            if (input == CountryCode::CountryCodeGT)
            {
                output = Json::Value("GT");
                return;
            }
            if (input == CountryCode::CountryCodeGG)
            {
                output = Json::Value("GG");
                return;
            }
            if (input == CountryCode::CountryCodeGN)
            {
                output = Json::Value("GN");
                return;
            }
            if (input == CountryCode::CountryCodeGW)
            {
                output = Json::Value("GW");
                return;
            }
            if (input == CountryCode::CountryCodeGY)
            {
                output = Json::Value("GY");
                return;
            }
            if (input == CountryCode::CountryCodeHT)
            {
                output = Json::Value("HT");
                return;
            }
            if (input == CountryCode::CountryCodeHM)
            {
                output = Json::Value("HM");
                return;
            }
            if (input == CountryCode::CountryCodeVA)
            {
                output = Json::Value("VA");
                return;
            }
            if (input == CountryCode::CountryCodeHN)
            {
                output = Json::Value("HN");
                return;
            }
            if (input == CountryCode::CountryCodeHK)
            {
                output = Json::Value("HK");
                return;
            }
            if (input == CountryCode::CountryCodeHU)
            {
                output = Json::Value("HU");
                return;
            }
            if (input == CountryCode::CountryCodeIS)
            {
                output = Json::Value("IS");
                return;
            }
            if (input == CountryCode::CountryCodeIN)
            {
                output = Json::Value("IN");
                return;
            }
            if (input == CountryCode::CountryCodeID)
            {
                output = Json::Value("ID");
                return;
            }
            if (input == CountryCode::CountryCodeIR)
            {
                output = Json::Value("IR");
                return;
            }
            if (input == CountryCode::CountryCodeIQ)
            {
                output = Json::Value("IQ");
                return;
            }
            if (input == CountryCode::CountryCodeIE)
            {
                output = Json::Value("IE");
                return;
            }
            if (input == CountryCode::CountryCodeIM)
            {
                output = Json::Value("IM");
                return;
            }
            if (input == CountryCode::CountryCodeIL)
            {
                output = Json::Value("IL");
                return;
            }
            if (input == CountryCode::CountryCodeIT)
            {
                output = Json::Value("IT");
                return;
            }
            if (input == CountryCode::CountryCodeJM)
            {
                output = Json::Value("JM");
                return;
            }
            if (input == CountryCode::CountryCodeJP)
            {
                output = Json::Value("JP");
                return;
            }
            if (input == CountryCode::CountryCodeJE)
            {
                output = Json::Value("JE");
                return;
            }
            if (input == CountryCode::CountryCodeJO)
            {
                output = Json::Value("JO");
                return;
            }
            if (input == CountryCode::CountryCodeKZ)
            {
                output = Json::Value("KZ");
                return;
            }
            if (input == CountryCode::CountryCodeKE)
            {
                output = Json::Value("KE");
                return;
            }
            if (input == CountryCode::CountryCodeKI)
            {
                output = Json::Value("KI");
                return;
            }
            if (input == CountryCode::CountryCodeKP)
            {
                output = Json::Value("KP");
                return;
            }
            if (input == CountryCode::CountryCodeKR)
            {
                output = Json::Value("KR");
                return;
            }
            if (input == CountryCode::CountryCodeKW)
            {
                output = Json::Value("KW");
                return;
            }
            if (input == CountryCode::CountryCodeKG)
            {
                output = Json::Value("KG");
                return;
            }
            if (input == CountryCode::CountryCodeLA)
            {
                output = Json::Value("LA");
                return;
            }
            if (input == CountryCode::CountryCodeLV)
            {
                output = Json::Value("LV");
                return;
            }
            if (input == CountryCode::CountryCodeLB)
            {
                output = Json::Value("LB");
                return;
            }
            if (input == CountryCode::CountryCodeLS)
            {
                output = Json::Value("LS");
                return;
            }
            if (input == CountryCode::CountryCodeLR)
            {
                output = Json::Value("LR");
                return;
            }
            if (input == CountryCode::CountryCodeLY)
            {
                output = Json::Value("LY");
                return;
            }
            if (input == CountryCode::CountryCodeLI)
            {
                output = Json::Value("LI");
                return;
            }
            if (input == CountryCode::CountryCodeLT)
            {
                output = Json::Value("LT");
                return;
            }
            if (input == CountryCode::CountryCodeLU)
            {
                output = Json::Value("LU");
                return;
            }
            if (input == CountryCode::CountryCodeMO)
            {
                output = Json::Value("MO");
                return;
            }
            if (input == CountryCode::CountryCodeMK)
            {
                output = Json::Value("MK");
                return;
            }
            if (input == CountryCode::CountryCodeMG)
            {
                output = Json::Value("MG");
                return;
            }
            if (input == CountryCode::CountryCodeMW)
            {
                output = Json::Value("MW");
                return;
            }
            if (input == CountryCode::CountryCodeMY)
            {
                output = Json::Value("MY");
                return;
            }
            if (input == CountryCode::CountryCodeMV)
            {
                output = Json::Value("MV");
                return;
            }
            if (input == CountryCode::CountryCodeML)
            {
                output = Json::Value("ML");
                return;
            }
            if (input == CountryCode::CountryCodeMT)
            {
                output = Json::Value("MT");
                return;
            }
            if (input == CountryCode::CountryCodeMH)
            {
                output = Json::Value("MH");
                return;
            }
            if (input == CountryCode::CountryCodeMQ)
            {
                output = Json::Value("MQ");
                return;
            }
            if (input == CountryCode::CountryCodeMR)
            {
                output = Json::Value("MR");
                return;
            }
            if (input == CountryCode::CountryCodeMU)
            {
                output = Json::Value("MU");
                return;
            }
            if (input == CountryCode::CountryCodeYT)
            {
                output = Json::Value("YT");
                return;
            }
            if (input == CountryCode::CountryCodeMX)
            {
                output = Json::Value("MX");
                return;
            }
            if (input == CountryCode::CountryCodeFM)
            {
                output = Json::Value("FM");
                return;
            }
            if (input == CountryCode::CountryCodeMD)
            {
                output = Json::Value("MD");
                return;
            }
            if (input == CountryCode::CountryCodeMC)
            {
                output = Json::Value("MC");
                return;
            }
            if (input == CountryCode::CountryCodeMN)
            {
                output = Json::Value("MN");
                return;
            }
            if (input == CountryCode::CountryCodeME)
            {
                output = Json::Value("ME");
                return;
            }
            if (input == CountryCode::CountryCodeMS)
            {
                output = Json::Value("MS");
                return;
            }
            if (input == CountryCode::CountryCodeMA)
            {
                output = Json::Value("MA");
                return;
            }
            if (input == CountryCode::CountryCodeMZ)
            {
                output = Json::Value("MZ");
                return;
            }
            if (input == CountryCode::CountryCodeMM)
            {
                output = Json::Value("MM");
                return;
            }
            if (input == CountryCode::CountryCodeNA)
            {
                output = Json::Value("NA");
                return;
            }
            if (input == CountryCode::CountryCodeNR)
            {
                output = Json::Value("NR");
                return;
            }
            if (input == CountryCode::CountryCodeNP)
            {
                output = Json::Value("NP");
                return;
            }
            if (input == CountryCode::CountryCodeNL)
            {
                output = Json::Value("NL");
                return;
            }
            if (input == CountryCode::CountryCodeNC)
            {
                output = Json::Value("NC");
                return;
            }
            if (input == CountryCode::CountryCodeNZ)
            {
                output = Json::Value("NZ");
                return;
            }
            if (input == CountryCode::CountryCodeNI)
            {
                output = Json::Value("NI");
                return;
            }
            if (input == CountryCode::CountryCodeNE)
            {
                output = Json::Value("NE");
                return;
            }
            if (input == CountryCode::CountryCodeNG)
            {
                output = Json::Value("NG");
                return;
            }
            if (input == CountryCode::CountryCodeNU)
            {
                output = Json::Value("NU");
                return;
            }
            if (input == CountryCode::CountryCodeNF)
            {
                output = Json::Value("NF");
                return;
            }
            if (input == CountryCode::CountryCodeMP)
            {
                output = Json::Value("MP");
                return;
            }
            if (input == CountryCode::CountryCodeNO)
            {
                output = Json::Value("NO");
                return;
            }
            if (input == CountryCode::CountryCodeOM)
            {
                output = Json::Value("OM");
                return;
            }
            if (input == CountryCode::CountryCodePK)
            {
                output = Json::Value("PK");
                return;
            }
            if (input == CountryCode::CountryCodePW)
            {
                output = Json::Value("PW");
                return;
            }
            if (input == CountryCode::CountryCodePS)
            {
                output = Json::Value("PS");
                return;
            }
            if (input == CountryCode::CountryCodePA)
            {
                output = Json::Value("PA");
                return;
            }
            if (input == CountryCode::CountryCodePG)
            {
                output = Json::Value("PG");
                return;
            }
            if (input == CountryCode::CountryCodePY)
            {
                output = Json::Value("PY");
                return;
            }
            if (input == CountryCode::CountryCodePE)
            {
                output = Json::Value("PE");
                return;
            }
            if (input == CountryCode::CountryCodePH)
            {
                output = Json::Value("PH");
                return;
            }
            if (input == CountryCode::CountryCodePN)
            {
                output = Json::Value("PN");
                return;
            }
            if (input == CountryCode::CountryCodePL)
            {
                output = Json::Value("PL");
                return;
            }
            if (input == CountryCode::CountryCodePT)
            {
                output = Json::Value("PT");
                return;
            }
            if (input == CountryCode::CountryCodePR)
            {
                output = Json::Value("PR");
                return;
            }
            if (input == CountryCode::CountryCodeQA)
            {
                output = Json::Value("QA");
                return;
            }
            if (input == CountryCode::CountryCodeRE)
            {
                output = Json::Value("RE");
                return;
            }
            if (input == CountryCode::CountryCodeRO)
            {
                output = Json::Value("RO");
                return;
            }
            if (input == CountryCode::CountryCodeRU)
            {
                output = Json::Value("RU");
                return;
            }
            if (input == CountryCode::CountryCodeRW)
            {
                output = Json::Value("RW");
                return;
            }
            if (input == CountryCode::CountryCodeBL)
            {
                output = Json::Value("BL");
                return;
            }
            if (input == CountryCode::CountryCodeSH)
            {
                output = Json::Value("SH");
                return;
            }
            if (input == CountryCode::CountryCodeKN)
            {
                output = Json::Value("KN");
                return;
            }
            if (input == CountryCode::CountryCodeLC)
            {
                output = Json::Value("LC");
                return;
            }
            if (input == CountryCode::CountryCodeMF)
            {
                output = Json::Value("MF");
                return;
            }
            if (input == CountryCode::CountryCodePM)
            {
                output = Json::Value("PM");
                return;
            }
            if (input == CountryCode::CountryCodeVC)
            {
                output = Json::Value("VC");
                return;
            }
            if (input == CountryCode::CountryCodeWS)
            {
                output = Json::Value("WS");
                return;
            }
            if (input == CountryCode::CountryCodeSM)
            {
                output = Json::Value("SM");
                return;
            }
            if (input == CountryCode::CountryCodeST)
            {
                output = Json::Value("ST");
                return;
            }
            if (input == CountryCode::CountryCodeSA)
            {
                output = Json::Value("SA");
                return;
            }
            if (input == CountryCode::CountryCodeSN)
            {
                output = Json::Value("SN");
                return;
            }
            if (input == CountryCode::CountryCodeRS)
            {
                output = Json::Value("RS");
                return;
            }
            if (input == CountryCode::CountryCodeSC)
            {
                output = Json::Value("SC");
                return;
            }
            if (input == CountryCode::CountryCodeSL)
            {
                output = Json::Value("SL");
                return;
            }
            if (input == CountryCode::CountryCodeSG)
            {
                output = Json::Value("SG");
                return;
            }
            if (input == CountryCode::CountryCodeSX)
            {
                output = Json::Value("SX");
                return;
            }
            if (input == CountryCode::CountryCodeSK)
            {
                output = Json::Value("SK");
                return;
            }
            if (input == CountryCode::CountryCodeSI)
            {
                output = Json::Value("SI");
                return;
            }
            if (input == CountryCode::CountryCodeSB)
            {
                output = Json::Value("SB");
                return;
            }
            if (input == CountryCode::CountryCodeSO)
            {
                output = Json::Value("SO");
                return;
            }
            if (input == CountryCode::CountryCodeZA)
            {
                output = Json::Value("ZA");
                return;
            }
            if (input == CountryCode::CountryCodeGS)
            {
                output = Json::Value("GS");
                return;
            }
            if (input == CountryCode::CountryCodeSS)
            {
                output = Json::Value("SS");
                return;
            }
            if (input == CountryCode::CountryCodeES)
            {
                output = Json::Value("ES");
                return;
            }
            if (input == CountryCode::CountryCodeLK)
            {
                output = Json::Value("LK");
                return;
            }
            if (input == CountryCode::CountryCodeSD)
            {
                output = Json::Value("SD");
                return;
            }
            if (input == CountryCode::CountryCodeSR)
            {
                output = Json::Value("SR");
                return;
            }
            if (input == CountryCode::CountryCodeSJ)
            {
                output = Json::Value("SJ");
                return;
            }
            if (input == CountryCode::CountryCodeSZ)
            {
                output = Json::Value("SZ");
                return;
            }
            if (input == CountryCode::CountryCodeSE)
            {
                output = Json::Value("SE");
                return;
            }
            if (input == CountryCode::CountryCodeCH)
            {
                output = Json::Value("CH");
                return;
            }
            if (input == CountryCode::CountryCodeSY)
            {
                output = Json::Value("SY");
                return;
            }
            if (input == CountryCode::CountryCodeTW)
            {
                output = Json::Value("TW");
                return;
            }
            if (input == CountryCode::CountryCodeTJ)
            {
                output = Json::Value("TJ");
                return;
            }
            if (input == CountryCode::CountryCodeTZ)
            {
                output = Json::Value("TZ");
                return;
            }
            if (input == CountryCode::CountryCodeTH)
            {
                output = Json::Value("TH");
                return;
            }
            if (input == CountryCode::CountryCodeTL)
            {
                output = Json::Value("TL");
                return;
            }
            if (input == CountryCode::CountryCodeTG)
            {
                output = Json::Value("TG");
                return;
            }
            if (input == CountryCode::CountryCodeTK)
            {
                output = Json::Value("TK");
                return;
            }
            if (input == CountryCode::CountryCodeTO)
            {
                output = Json::Value("TO");
                return;
            }
            if (input == CountryCode::CountryCodeTT)
            {
                output = Json::Value("TT");
                return;
            }
            if (input == CountryCode::CountryCodeTN)
            {
                output = Json::Value("TN");
                return;
            }
            if (input == CountryCode::CountryCodeTR)
            {
                output = Json::Value("TR");
                return;
            }
            if (input == CountryCode::CountryCodeTM)
            {
                output = Json::Value("TM");
                return;
            }
            if (input == CountryCode::CountryCodeTC)
            {
                output = Json::Value("TC");
                return;
            }
            if (input == CountryCode::CountryCodeTV)
            {
                output = Json::Value("TV");
                return;
            }
            if (input == CountryCode::CountryCodeUG)
            {
                output = Json::Value("UG");
                return;
            }
            if (input == CountryCode::CountryCodeUA)
            {
                output = Json::Value("UA");
                return;
            }
            if (input == CountryCode::CountryCodeAE)
            {
                output = Json::Value("AE");
                return;
            }
            if (input == CountryCode::CountryCodeGB)
            {
                output = Json::Value("GB");
                return;
            }
            if (input == CountryCode::CountryCodeUS)
            {
                output = Json::Value("US");
                return;
            }
            if (input == CountryCode::CountryCodeUM)
            {
                output = Json::Value("UM");
                return;
            }
            if (input == CountryCode::CountryCodeUY)
            {
                output = Json::Value("UY");
                return;
            }
            if (input == CountryCode::CountryCodeUZ)
            {
                output = Json::Value("UZ");
                return;
            }
            if (input == CountryCode::CountryCodeVU)
            {
                output = Json::Value("VU");
                return;
            }
            if (input == CountryCode::CountryCodeVE)
            {
                output = Json::Value("VE");
                return;
            }
            if (input == CountryCode::CountryCodeVN)
            {
                output = Json::Value("VN");
                return;
            }
            if (input == CountryCode::CountryCodeVG)
            {
                output = Json::Value("VG");
                return;
            }
            if (input == CountryCode::CountryCodeVI)
            {
                output = Json::Value("VI");
                return;
            }
            if (input == CountryCode::CountryCodeWF)
            {
                output = Json::Value("WF");
                return;
            }
            if (input == CountryCode::CountryCodeEH)
            {
                output = Json::Value("EH");
                return;
            }
            if (input == CountryCode::CountryCodeYE)
            {
                output = Json::Value("YE");
                return;
            }
            if (input == CountryCode::CountryCodeZM)
            {
                output = Json::Value("ZM");
                return;
            }
            if (input == CountryCode::CountryCodeZW)
            {
                output = Json::Value("ZW");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, CountryCode& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "AF")
            {
                output = CountryCode::CountryCodeAF;
                return;
            }
            if (inputStr == "AX")
            {
                output = CountryCode::CountryCodeAX;
                return;
            }
            if (inputStr == "AL")
            {
                output = CountryCode::CountryCodeAL;
                return;
            }
            if (inputStr == "DZ")
            {
                output = CountryCode::CountryCodeDZ;
                return;
            }
            if (inputStr == "AS")
            {
                output = CountryCode::CountryCodeAS;
                return;
            }
            if (inputStr == "AD")
            {
                output = CountryCode::CountryCodeAD;
                return;
            }
            if (inputStr == "AO")
            {
                output = CountryCode::CountryCodeAO;
                return;
            }
            if (inputStr == "AI")
            {
                output = CountryCode::CountryCodeAI;
                return;
            }
            if (inputStr == "AQ")
            {
                output = CountryCode::CountryCodeAQ;
                return;
            }
            if (inputStr == "AG")
            {
                output = CountryCode::CountryCodeAG;
                return;
            }
            if (inputStr == "AR")
            {
                output = CountryCode::CountryCodeAR;
                return;
            }
            if (inputStr == "AM")
            {
                output = CountryCode::CountryCodeAM;
                return;
            }
            if (inputStr == "AW")
            {
                output = CountryCode::CountryCodeAW;
                return;
            }
            if (inputStr == "AU")
            {
                output = CountryCode::CountryCodeAU;
                return;
            }
            if (inputStr == "AT")
            {
                output = CountryCode::CountryCodeAT;
                return;
            }
            if (inputStr == "AZ")
            {
                output = CountryCode::CountryCodeAZ;
                return;
            }
            if (inputStr == "BS")
            {
                output = CountryCode::CountryCodeBS;
                return;
            }
            if (inputStr == "BH")
            {
                output = CountryCode::CountryCodeBH;
                return;
            }
            if (inputStr == "BD")
            {
                output = CountryCode::CountryCodeBD;
                return;
            }
            if (inputStr == "BB")
            {
                output = CountryCode::CountryCodeBB;
                return;
            }
            if (inputStr == "BY")
            {
                output = CountryCode::CountryCodeBY;
                return;
            }
            if (inputStr == "BE")
            {
                output = CountryCode::CountryCodeBE;
                return;
            }
            if (inputStr == "BZ")
            {
                output = CountryCode::CountryCodeBZ;
                return;
            }
            if (inputStr == "BJ")
            {
                output = CountryCode::CountryCodeBJ;
                return;
            }
            if (inputStr == "BM")
            {
                output = CountryCode::CountryCodeBM;
                return;
            }
            if (inputStr == "BT")
            {
                output = CountryCode::CountryCodeBT;
                return;
            }
            if (inputStr == "BO")
            {
                output = CountryCode::CountryCodeBO;
                return;
            }
            if (inputStr == "BQ")
            {
                output = CountryCode::CountryCodeBQ;
                return;
            }
            if (inputStr == "BA")
            {
                output = CountryCode::CountryCodeBA;
                return;
            }
            if (inputStr == "BW")
            {
                output = CountryCode::CountryCodeBW;
                return;
            }
            if (inputStr == "BV")
            {
                output = CountryCode::CountryCodeBV;
                return;
            }
            if (inputStr == "BR")
            {
                output = CountryCode::CountryCodeBR;
                return;
            }
            if (inputStr == "IO")
            {
                output = CountryCode::CountryCodeIO;
                return;
            }
            if (inputStr == "BN")
            {
                output = CountryCode::CountryCodeBN;
                return;
            }
            if (inputStr == "BG")
            {
                output = CountryCode::CountryCodeBG;
                return;
            }
            if (inputStr == "BF")
            {
                output = CountryCode::CountryCodeBF;
                return;
            }
            if (inputStr == "BI")
            {
                output = CountryCode::CountryCodeBI;
                return;
            }
            if (inputStr == "KH")
            {
                output = CountryCode::CountryCodeKH;
                return;
            }
            if (inputStr == "CM")
            {
                output = CountryCode::CountryCodeCM;
                return;
            }
            if (inputStr == "CA")
            {
                output = CountryCode::CountryCodeCA;
                return;
            }
            if (inputStr == "CV")
            {
                output = CountryCode::CountryCodeCV;
                return;
            }
            if (inputStr == "KY")
            {
                output = CountryCode::CountryCodeKY;
                return;
            }
            if (inputStr == "CF")
            {
                output = CountryCode::CountryCodeCF;
                return;
            }
            if (inputStr == "TD")
            {
                output = CountryCode::CountryCodeTD;
                return;
            }
            if (inputStr == "CL")
            {
                output = CountryCode::CountryCodeCL;
                return;
            }
            if (inputStr == "CN")
            {
                output = CountryCode::CountryCodeCN;
                return;
            }
            if (inputStr == "CX")
            {
                output = CountryCode::CountryCodeCX;
                return;
            }
            if (inputStr == "CC")
            {
                output = CountryCode::CountryCodeCC;
                return;
            }
            if (inputStr == "CO")
            {
                output = CountryCode::CountryCodeCO;
                return;
            }
            if (inputStr == "KM")
            {
                output = CountryCode::CountryCodeKM;
                return;
            }
            if (inputStr == "CG")
            {
                output = CountryCode::CountryCodeCG;
                return;
            }
            if (inputStr == "CD")
            {
                output = CountryCode::CountryCodeCD;
                return;
            }
            if (inputStr == "CK")
            {
                output = CountryCode::CountryCodeCK;
                return;
            }
            if (inputStr == "CR")
            {
                output = CountryCode::CountryCodeCR;
                return;
            }
            if (inputStr == "CI")
            {
                output = CountryCode::CountryCodeCI;
                return;
            }
            if (inputStr == "HR")
            {
                output = CountryCode::CountryCodeHR;
                return;
            }
            if (inputStr == "CU")
            {
                output = CountryCode::CountryCodeCU;
                return;
            }
            if (inputStr == "CW")
            {
                output = CountryCode::CountryCodeCW;
                return;
            }
            if (inputStr == "CY")
            {
                output = CountryCode::CountryCodeCY;
                return;
            }
            if (inputStr == "CZ")
            {
                output = CountryCode::CountryCodeCZ;
                return;
            }
            if (inputStr == "DK")
            {
                output = CountryCode::CountryCodeDK;
                return;
            }
            if (inputStr == "DJ")
            {
                output = CountryCode::CountryCodeDJ;
                return;
            }
            if (inputStr == "DM")
            {
                output = CountryCode::CountryCodeDM;
                return;
            }
            if (inputStr == "DO")
            {
                output = CountryCode::CountryCodeDO;
                return;
            }
            if (inputStr == "EC")
            {
                output = CountryCode::CountryCodeEC;
                return;
            }
            if (inputStr == "EG")
            {
                output = CountryCode::CountryCodeEG;
                return;
            }
            if (inputStr == "SV")
            {
                output = CountryCode::CountryCodeSV;
                return;
            }
            if (inputStr == "GQ")
            {
                output = CountryCode::CountryCodeGQ;
                return;
            }
            if (inputStr == "ER")
            {
                output = CountryCode::CountryCodeER;
                return;
            }
            if (inputStr == "EE")
            {
                output = CountryCode::CountryCodeEE;
                return;
            }
            if (inputStr == "ET")
            {
                output = CountryCode::CountryCodeET;
                return;
            }
            if (inputStr == "FK")
            {
                output = CountryCode::CountryCodeFK;
                return;
            }
            if (inputStr == "FO")
            {
                output = CountryCode::CountryCodeFO;
                return;
            }
            if (inputStr == "FJ")
            {
                output = CountryCode::CountryCodeFJ;
                return;
            }
            if (inputStr == "FI")
            {
                output = CountryCode::CountryCodeFI;
                return;
            }
            if (inputStr == "FR")
            {
                output = CountryCode::CountryCodeFR;
                return;
            }
            if (inputStr == "GF")
            {
                output = CountryCode::CountryCodeGF;
                return;
            }
            if (inputStr == "PF")
            {
                output = CountryCode::CountryCodePF;
                return;
            }
            if (inputStr == "TF")
            {
                output = CountryCode::CountryCodeTF;
                return;
            }
            if (inputStr == "GA")
            {
                output = CountryCode::CountryCodeGA;
                return;
            }
            if (inputStr == "GM")
            {
                output = CountryCode::CountryCodeGM;
                return;
            }
            if (inputStr == "GE")
            {
                output = CountryCode::CountryCodeGE;
                return;
            }
            if (inputStr == "DE")
            {
                output = CountryCode::CountryCodeDE;
                return;
            }
            if (inputStr == "GH")
            {
                output = CountryCode::CountryCodeGH;
                return;
            }
            if (inputStr == "GI")
            {
                output = CountryCode::CountryCodeGI;
                return;
            }
            if (inputStr == "GR")
            {
                output = CountryCode::CountryCodeGR;
                return;
            }
            if (inputStr == "GL")
            {
                output = CountryCode::CountryCodeGL;
                return;
            }
            if (inputStr == "GD")
            {
                output = CountryCode::CountryCodeGD;
                return;
            }
            if (inputStr == "GP")
            {
                output = CountryCode::CountryCodeGP;
                return;
            }
            if (inputStr == "GU")
            {
                output = CountryCode::CountryCodeGU;
                return;
            }
            if (inputStr == "GT")
            {
                output = CountryCode::CountryCodeGT;
                return;
            }
            if (inputStr == "GG")
            {
                output = CountryCode::CountryCodeGG;
                return;
            }
            if (inputStr == "GN")
            {
                output = CountryCode::CountryCodeGN;
                return;
            }
            if (inputStr == "GW")
            {
                output = CountryCode::CountryCodeGW;
                return;
            }
            if (inputStr == "GY")
            {
                output = CountryCode::CountryCodeGY;
                return;
            }
            if (inputStr == "HT")
            {
                output = CountryCode::CountryCodeHT;
                return;
            }
            if (inputStr == "HM")
            {
                output = CountryCode::CountryCodeHM;
                return;
            }
            if (inputStr == "VA")
            {
                output = CountryCode::CountryCodeVA;
                return;
            }
            if (inputStr == "HN")
            {
                output = CountryCode::CountryCodeHN;
                return;
            }
            if (inputStr == "HK")
            {
                output = CountryCode::CountryCodeHK;
                return;
            }
            if (inputStr == "HU")
            {
                output = CountryCode::CountryCodeHU;
                return;
            }
            if (inputStr == "IS")
            {
                output = CountryCode::CountryCodeIS;
                return;
            }
            if (inputStr == "IN")
            {
                output = CountryCode::CountryCodeIN;
                return;
            }
            if (inputStr == "ID")
            {
                output = CountryCode::CountryCodeID;
                return;
            }
            if (inputStr == "IR")
            {
                output = CountryCode::CountryCodeIR;
                return;
            }
            if (inputStr == "IQ")
            {
                output = CountryCode::CountryCodeIQ;
                return;
            }
            if (inputStr == "IE")
            {
                output = CountryCode::CountryCodeIE;
                return;
            }
            if (inputStr == "IM")
            {
                output = CountryCode::CountryCodeIM;
                return;
            }
            if (inputStr == "IL")
            {
                output = CountryCode::CountryCodeIL;
                return;
            }
            if (inputStr == "IT")
            {
                output = CountryCode::CountryCodeIT;
                return;
            }
            if (inputStr == "JM")
            {
                output = CountryCode::CountryCodeJM;
                return;
            }
            if (inputStr == "JP")
            {
                output = CountryCode::CountryCodeJP;
                return;
            }
            if (inputStr == "JE")
            {
                output = CountryCode::CountryCodeJE;
                return;
            }
            if (inputStr == "JO")
            {
                output = CountryCode::CountryCodeJO;
                return;
            }
            if (inputStr == "KZ")
            {
                output = CountryCode::CountryCodeKZ;
                return;
            }
            if (inputStr == "KE")
            {
                output = CountryCode::CountryCodeKE;
                return;
            }
            if (inputStr == "KI")
            {
                output = CountryCode::CountryCodeKI;
                return;
            }
            if (inputStr == "KP")
            {
                output = CountryCode::CountryCodeKP;
                return;
            }
            if (inputStr == "KR")
            {
                output = CountryCode::CountryCodeKR;
                return;
            }
            if (inputStr == "KW")
            {
                output = CountryCode::CountryCodeKW;
                return;
            }
            if (inputStr == "KG")
            {
                output = CountryCode::CountryCodeKG;
                return;
            }
            if (inputStr == "LA")
            {
                output = CountryCode::CountryCodeLA;
                return;
            }
            if (inputStr == "LV")
            {
                output = CountryCode::CountryCodeLV;
                return;
            }
            if (inputStr == "LB")
            {
                output = CountryCode::CountryCodeLB;
                return;
            }
            if (inputStr == "LS")
            {
                output = CountryCode::CountryCodeLS;
                return;
            }
            if (inputStr == "LR")
            {
                output = CountryCode::CountryCodeLR;
                return;
            }
            if (inputStr == "LY")
            {
                output = CountryCode::CountryCodeLY;
                return;
            }
            if (inputStr == "LI")
            {
                output = CountryCode::CountryCodeLI;
                return;
            }
            if (inputStr == "LT")
            {
                output = CountryCode::CountryCodeLT;
                return;
            }
            if (inputStr == "LU")
            {
                output = CountryCode::CountryCodeLU;
                return;
            }
            if (inputStr == "MO")
            {
                output = CountryCode::CountryCodeMO;
                return;
            }
            if (inputStr == "MK")
            {
                output = CountryCode::CountryCodeMK;
                return;
            }
            if (inputStr == "MG")
            {
                output = CountryCode::CountryCodeMG;
                return;
            }
            if (inputStr == "MW")
            {
                output = CountryCode::CountryCodeMW;
                return;
            }
            if (inputStr == "MY")
            {
                output = CountryCode::CountryCodeMY;
                return;
            }
            if (inputStr == "MV")
            {
                output = CountryCode::CountryCodeMV;
                return;
            }
            if (inputStr == "ML")
            {
                output = CountryCode::CountryCodeML;
                return;
            }
            if (inputStr == "MT")
            {
                output = CountryCode::CountryCodeMT;
                return;
            }
            if (inputStr == "MH")
            {
                output = CountryCode::CountryCodeMH;
                return;
            }
            if (inputStr == "MQ")
            {
                output = CountryCode::CountryCodeMQ;
                return;
            }
            if (inputStr == "MR")
            {
                output = CountryCode::CountryCodeMR;
                return;
            }
            if (inputStr == "MU")
            {
                output = CountryCode::CountryCodeMU;
                return;
            }
            if (inputStr == "YT")
            {
                output = CountryCode::CountryCodeYT;
                return;
            }
            if (inputStr == "MX")
            {
                output = CountryCode::CountryCodeMX;
                return;
            }
            if (inputStr == "FM")
            {
                output = CountryCode::CountryCodeFM;
                return;
            }
            if (inputStr == "MD")
            {
                output = CountryCode::CountryCodeMD;
                return;
            }
            if (inputStr == "MC")
            {
                output = CountryCode::CountryCodeMC;
                return;
            }
            if (inputStr == "MN")
            {
                output = CountryCode::CountryCodeMN;
                return;
            }
            if (inputStr == "ME")
            {
                output = CountryCode::CountryCodeME;
                return;
            }
            if (inputStr == "MS")
            {
                output = CountryCode::CountryCodeMS;
                return;
            }
            if (inputStr == "MA")
            {
                output = CountryCode::CountryCodeMA;
                return;
            }
            if (inputStr == "MZ")
            {
                output = CountryCode::CountryCodeMZ;
                return;
            }
            if (inputStr == "MM")
            {
                output = CountryCode::CountryCodeMM;
                return;
            }
            if (inputStr == "NA")
            {
                output = CountryCode::CountryCodeNA;
                return;
            }
            if (inputStr == "NR")
            {
                output = CountryCode::CountryCodeNR;
                return;
            }
            if (inputStr == "NP")
            {
                output = CountryCode::CountryCodeNP;
                return;
            }
            if (inputStr == "NL")
            {
                output = CountryCode::CountryCodeNL;
                return;
            }
            if (inputStr == "NC")
            {
                output = CountryCode::CountryCodeNC;
                return;
            }
            if (inputStr == "NZ")
            {
                output = CountryCode::CountryCodeNZ;
                return;
            }
            if (inputStr == "NI")
            {
                output = CountryCode::CountryCodeNI;
                return;
            }
            if (inputStr == "NE")
            {
                output = CountryCode::CountryCodeNE;
                return;
            }
            if (inputStr == "NG")
            {
                output = CountryCode::CountryCodeNG;
                return;
            }
            if (inputStr == "NU")
            {
                output = CountryCode::CountryCodeNU;
                return;
            }
            if (inputStr == "NF")
            {
                output = CountryCode::CountryCodeNF;
                return;
            }
            if (inputStr == "MP")
            {
                output = CountryCode::CountryCodeMP;
                return;
            }
            if (inputStr == "NO")
            {
                output = CountryCode::CountryCodeNO;
                return;
            }
            if (inputStr == "OM")
            {
                output = CountryCode::CountryCodeOM;
                return;
            }
            if (inputStr == "PK")
            {
                output = CountryCode::CountryCodePK;
                return;
            }
            if (inputStr == "PW")
            {
                output = CountryCode::CountryCodePW;
                return;
            }
            if (inputStr == "PS")
            {
                output = CountryCode::CountryCodePS;
                return;
            }
            if (inputStr == "PA")
            {
                output = CountryCode::CountryCodePA;
                return;
            }
            if (inputStr == "PG")
            {
                output = CountryCode::CountryCodePG;
                return;
            }
            if (inputStr == "PY")
            {
                output = CountryCode::CountryCodePY;
                return;
            }
            if (inputStr == "PE")
            {
                output = CountryCode::CountryCodePE;
                return;
            }
            if (inputStr == "PH")
            {
                output = CountryCode::CountryCodePH;
                return;
            }
            if (inputStr == "PN")
            {
                output = CountryCode::CountryCodePN;
                return;
            }
            if (inputStr == "PL")
            {
                output = CountryCode::CountryCodePL;
                return;
            }
            if (inputStr == "PT")
            {
                output = CountryCode::CountryCodePT;
                return;
            }
            if (inputStr == "PR")
            {
                output = CountryCode::CountryCodePR;
                return;
            }
            if (inputStr == "QA")
            {
                output = CountryCode::CountryCodeQA;
                return;
            }
            if (inputStr == "RE")
            {
                output = CountryCode::CountryCodeRE;
                return;
            }
            if (inputStr == "RO")
            {
                output = CountryCode::CountryCodeRO;
                return;
            }
            if (inputStr == "RU")
            {
                output = CountryCode::CountryCodeRU;
                return;
            }
            if (inputStr == "RW")
            {
                output = CountryCode::CountryCodeRW;
                return;
            }
            if (inputStr == "BL")
            {
                output = CountryCode::CountryCodeBL;
                return;
            }
            if (inputStr == "SH")
            {
                output = CountryCode::CountryCodeSH;
                return;
            }
            if (inputStr == "KN")
            {
                output = CountryCode::CountryCodeKN;
                return;
            }
            if (inputStr == "LC")
            {
                output = CountryCode::CountryCodeLC;
                return;
            }
            if (inputStr == "MF")
            {
                output = CountryCode::CountryCodeMF;
                return;
            }
            if (inputStr == "PM")
            {
                output = CountryCode::CountryCodePM;
                return;
            }
            if (inputStr == "VC")
            {
                output = CountryCode::CountryCodeVC;
                return;
            }
            if (inputStr == "WS")
            {
                output = CountryCode::CountryCodeWS;
                return;
            }
            if (inputStr == "SM")
            {
                output = CountryCode::CountryCodeSM;
                return;
            }
            if (inputStr == "ST")
            {
                output = CountryCode::CountryCodeST;
                return;
            }
            if (inputStr == "SA")
            {
                output = CountryCode::CountryCodeSA;
                return;
            }
            if (inputStr == "SN")
            {
                output = CountryCode::CountryCodeSN;
                return;
            }
            if (inputStr == "RS")
            {
                output = CountryCode::CountryCodeRS;
                return;
            }
            if (inputStr == "SC")
            {
                output = CountryCode::CountryCodeSC;
                return;
            }
            if (inputStr == "SL")
            {
                output = CountryCode::CountryCodeSL;
                return;
            }
            if (inputStr == "SG")
            {
                output = CountryCode::CountryCodeSG;
                return;
            }
            if (inputStr == "SX")
            {
                output = CountryCode::CountryCodeSX;
                return;
            }
            if (inputStr == "SK")
            {
                output = CountryCode::CountryCodeSK;
                return;
            }
            if (inputStr == "SI")
            {
                output = CountryCode::CountryCodeSI;
                return;
            }
            if (inputStr == "SB")
            {
                output = CountryCode::CountryCodeSB;
                return;
            }
            if (inputStr == "SO")
            {
                output = CountryCode::CountryCodeSO;
                return;
            }
            if (inputStr == "ZA")
            {
                output = CountryCode::CountryCodeZA;
                return;
            }
            if (inputStr == "GS")
            {
                output = CountryCode::CountryCodeGS;
                return;
            }
            if (inputStr == "SS")
            {
                output = CountryCode::CountryCodeSS;
                return;
            }
            if (inputStr == "ES")
            {
                output = CountryCode::CountryCodeES;
                return;
            }
            if (inputStr == "LK")
            {
                output = CountryCode::CountryCodeLK;
                return;
            }
            if (inputStr == "SD")
            {
                output = CountryCode::CountryCodeSD;
                return;
            }
            if (inputStr == "SR")
            {
                output = CountryCode::CountryCodeSR;
                return;
            }
            if (inputStr == "SJ")
            {
                output = CountryCode::CountryCodeSJ;
                return;
            }
            if (inputStr == "SZ")
            {
                output = CountryCode::CountryCodeSZ;
                return;
            }
            if (inputStr == "SE")
            {
                output = CountryCode::CountryCodeSE;
                return;
            }
            if (inputStr == "CH")
            {
                output = CountryCode::CountryCodeCH;
                return;
            }
            if (inputStr == "SY")
            {
                output = CountryCode::CountryCodeSY;
                return;
            }
            if (inputStr == "TW")
            {
                output = CountryCode::CountryCodeTW;
                return;
            }
            if (inputStr == "TJ")
            {
                output = CountryCode::CountryCodeTJ;
                return;
            }
            if (inputStr == "TZ")
            {
                output = CountryCode::CountryCodeTZ;
                return;
            }
            if (inputStr == "TH")
            {
                output = CountryCode::CountryCodeTH;
                return;
            }
            if (inputStr == "TL")
            {
                output = CountryCode::CountryCodeTL;
                return;
            }
            if (inputStr == "TG")
            {
                output = CountryCode::CountryCodeTG;
                return;
            }
            if (inputStr == "TK")
            {
                output = CountryCode::CountryCodeTK;
                return;
            }
            if (inputStr == "TO")
            {
                output = CountryCode::CountryCodeTO;
                return;
            }
            if (inputStr == "TT")
            {
                output = CountryCode::CountryCodeTT;
                return;
            }
            if (inputStr == "TN")
            {
                output = CountryCode::CountryCodeTN;
                return;
            }
            if (inputStr == "TR")
            {
                output = CountryCode::CountryCodeTR;
                return;
            }
            if (inputStr == "TM")
            {
                output = CountryCode::CountryCodeTM;
                return;
            }
            if (inputStr == "TC")
            {
                output = CountryCode::CountryCodeTC;
                return;
            }
            if (inputStr == "TV")
            {
                output = CountryCode::CountryCodeTV;
                return;
            }
            if (inputStr == "UG")
            {
                output = CountryCode::CountryCodeUG;
                return;
            }
            if (inputStr == "UA")
            {
                output = CountryCode::CountryCodeUA;
                return;
            }
            if (inputStr == "AE")
            {
                output = CountryCode::CountryCodeAE;
                return;
            }
            if (inputStr == "GB")
            {
                output = CountryCode::CountryCodeGB;
                return;
            }
            if (inputStr == "US")
            {
                output = CountryCode::CountryCodeUS;
                return;
            }
            if (inputStr == "UM")
            {
                output = CountryCode::CountryCodeUM;
                return;
            }
            if (inputStr == "UY")
            {
                output = CountryCode::CountryCodeUY;
                return;
            }
            if (inputStr == "UZ")
            {
                output = CountryCode::CountryCodeUZ;
                return;
            }
            if (inputStr == "VU")
            {
                output = CountryCode::CountryCodeVU;
                return;
            }
            if (inputStr == "VE")
            {
                output = CountryCode::CountryCodeVE;
                return;
            }
            if (inputStr == "VN")
            {
                output = CountryCode::CountryCodeVN;
                return;
            }
            if (inputStr == "VG")
            {
                output = CountryCode::CountryCodeVG;
                return;
            }
            if (inputStr == "VI")
            {
                output = CountryCode::CountryCodeVI;
                return;
            }
            if (inputStr == "WF")
            {
                output = CountryCode::CountryCodeWF;
                return;
            }
            if (inputStr == "EH")
            {
                output = CountryCode::CountryCodeEH;
                return;
            }
            if (inputStr == "YE")
            {
                output = CountryCode::CountryCodeYE;
                return;
            }
            if (inputStr == "ZM")
            {
                output = CountryCode::CountryCodeZM;
                return;
            }
            if (inputStr == "ZW")
            {
                output = CountryCode::CountryCodeZW;
                return;
            }
        }

        enum class DisplayPropertyType
        {
            DisplayPropertyTypeNone,
            DisplayPropertyTypeQueryDateTime,
            DisplayPropertyTypeQueryDouble,
            DisplayPropertyTypeQueryString,
            DisplayPropertyTypeSearchString
        };

        inline void ToJsonEnum(const DisplayPropertyType input, Json::Value& output)
        {
            if (input == DisplayPropertyType::DisplayPropertyTypeNone)
            {
                output = Json::Value("None");
                return;
            }
            if (input == DisplayPropertyType::DisplayPropertyTypeQueryDateTime)
            {
                output = Json::Value("QueryDateTime");
                return;
            }
            if (input == DisplayPropertyType::DisplayPropertyTypeQueryDouble)
            {
                output = Json::Value("QueryDouble");
                return;
            }
            if (input == DisplayPropertyType::DisplayPropertyTypeQueryString)
            {
                output = Json::Value("QueryString");
                return;
            }
            if (input == DisplayPropertyType::DisplayPropertyTypeSearchString)
            {
                output = Json::Value("SearchString");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, DisplayPropertyType& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "None")
            {
                output = DisplayPropertyType::DisplayPropertyTypeNone;
                return;
            }
            if (inputStr == "QueryDateTime")
            {
                output = DisplayPropertyType::DisplayPropertyTypeQueryDateTime;
                return;
            }
            if (inputStr == "QueryDouble")
            {
                output = DisplayPropertyType::DisplayPropertyTypeQueryDouble;
                return;
            }
            if (inputStr == "QueryString")
            {
                output = DisplayPropertyType::DisplayPropertyTypeQueryString;
                return;
            }
            if (inputStr == "SearchString")
            {
                output = DisplayPropertyType::DisplayPropertyTypeSearchString;
                return;
            }
        }

        enum class HelpfulnessVote
        {
            HelpfulnessVoteNone,
            HelpfulnessVoteUnHelpful,
            HelpfulnessVoteHelpful
        };

        inline void ToJsonEnum(const HelpfulnessVote input, Json::Value& output)
        {
            if (input == HelpfulnessVote::HelpfulnessVoteNone)
            {
                output = Json::Value("None");
                return;
            }
            if (input == HelpfulnessVote::HelpfulnessVoteUnHelpful)
            {
                output = Json::Value("UnHelpful");
                return;
            }
            if (input == HelpfulnessVote::HelpfulnessVoteHelpful)
            {
                output = Json::Value("Helpful");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, HelpfulnessVote& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "None")
            {
                output = HelpfulnessVote::HelpfulnessVoteNone;
                return;
            }
            if (inputStr == "UnHelpful")
            {
                output = HelpfulnessVote::HelpfulnessVoteUnHelpful;
                return;
            }
            if (inputStr == "Helpful")
            {
                output = HelpfulnessVote::HelpfulnessVoteHelpful;
                return;
            }
        }

        enum class ModerationStatus
        {
            ModerationStatusUnknown,
            ModerationStatusAwaitingModeration,
            ModerationStatusApproved,
            ModerationStatusRejected
        };

        inline void ToJsonEnum(const ModerationStatus input, Json::Value& output)
        {
            if (input == ModerationStatus::ModerationStatusUnknown)
            {
                output = Json::Value("Unknown");
                return;
            }
            if (input == ModerationStatus::ModerationStatusAwaitingModeration)
            {
                output = Json::Value("AwaitingModeration");
                return;
            }
            if (input == ModerationStatus::ModerationStatusApproved)
            {
                output = Json::Value("Approved");
                return;
            }
            if (input == ModerationStatus::ModerationStatusRejected)
            {
                output = Json::Value("Rejected");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, ModerationStatus& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown")
            {
                output = ModerationStatus::ModerationStatusUnknown;
                return;
            }
            if (inputStr == "AwaitingModeration")
            {
                output = ModerationStatus::ModerationStatusAwaitingModeration;
                return;
            }
            if (inputStr == "Approved")
            {
                output = ModerationStatus::ModerationStatusApproved;
                return;
            }
            if (inputStr == "Rejected")
            {
                output = ModerationStatus::ModerationStatusRejected;
                return;
            }
        }

        enum class PublishResult
        {
            PublishResultUnknown,
            PublishResultPending,
            PublishResultSucceeded,
            PublishResultFailed,
            PublishResultCanceled
        };

        inline void ToJsonEnum(const PublishResult input, Json::Value& output)
        {
            if (input == PublishResult::PublishResultUnknown)
            {
                output = Json::Value("Unknown");
                return;
            }
            if (input == PublishResult::PublishResultPending)
            {
                output = Json::Value("Pending");
                return;
            }
            if (input == PublishResult::PublishResultSucceeded)
            {
                output = Json::Value("Succeeded");
                return;
            }
            if (input == PublishResult::PublishResultFailed)
            {
                output = Json::Value("Failed");
                return;
            }
            if (input == PublishResult::PublishResultCanceled)
            {
                output = Json::Value("Canceled");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, PublishResult& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "Unknown")
            {
                output = PublishResult::PublishResultUnknown;
                return;
            }
            if (inputStr == "Pending")
            {
                output = PublishResult::PublishResultPending;
                return;
            }
            if (inputStr == "Succeeded")
            {
                output = PublishResult::PublishResultSucceeded;
                return;
            }
            if (inputStr == "Failed")
            {
                output = PublishResult::PublishResultFailed;
                return;
            }
            if (inputStr == "Canceled")
            {
                output = PublishResult::PublishResultCanceled;
                return;
            }
        }

        // Economy Classes
        struct AlternateId : public PlayFabBaseModel
        {
            std::string Type;
            std::string Value;

            AlternateId() :
                PlayFabBaseModel(),
                Type(),
                Value()
            {}

            AlternateId(const AlternateId& src) :
                PlayFabBaseModel(),
                Type(src.Type),
                Value(src.Value)
            {}

            ~AlternateId() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Type"], Type);
                FromJsonUtilS(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                Json::Value each_Value; ToJsonUtilS(Value, each_Value); output["Value"] = each_Value;
                return output;
            }
        };

        struct InventoryItemReference : public PlayFabBaseModel
        {
            Boxed<AlternateId> pfAlternateId;
            std::string Id;
            std::string StackId;

            InventoryItemReference() :
                PlayFabBaseModel(),
                pfAlternateId(),
                Id(),
                StackId()
            {}

            InventoryItemReference(const InventoryItemReference& src) :
                PlayFabBaseModel(),
                pfAlternateId(src.pfAlternateId),
                Id(src.Id),
                StackId(src.StackId)
            {}

            ~InventoryItemReference() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], pfAlternateId);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["StackId"], StackId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfAlternateId; ToJsonUtilO(pfAlternateId, each_pfAlternateId); output["AlternateId"] = each_pfAlternateId;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_StackId; ToJsonUtilS(StackId, each_StackId); output["StackId"] = each_StackId;
                return output;
            }
        };

        struct AddInventoryItemsOperation : public PlayFabBaseModel
        {
            Int32 Amount;
            Boxed<InventoryItemReference> Item;

            AddInventoryItemsOperation() :
                PlayFabBaseModel(),
                Amount(),
                Item()
            {}

            AddInventoryItemsOperation(const AddInventoryItemsOperation& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                Item(src.Item)
            {}

            ~AddInventoryItemsOperation() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
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

        struct AddInventoryItemsRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            Boxed<InventoryItemReference> Item;

            AddInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Amount(),
                CollectionId(),
                CustomTags(),
                Entity(),
                IdempotencyId(),
                Item()
            {}

            AddInventoryItemsRequest(const AddInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Item(src.Item)
            {}

            ~AddInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct AddInventoryItemsResponse : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<std::string> TransactionIds;

            AddInventoryItemsResponse() :
                PlayFabResultCommon(),
                IdempotencyId(),
                TransactionIds()
            {}

            AddInventoryItemsResponse(const AddInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                TransactionIds(src.TransactionIds)
            {}

            ~AddInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct CatalogAlternateId : public PlayFabBaseModel
        {
            std::string Type;
            std::string Value;

            CatalogAlternateId() :
                PlayFabBaseModel(),
                Type(),
                Value()
            {}

            CatalogAlternateId(const CatalogAlternateId& src) :
                PlayFabBaseModel(),
                Type(src.Type),
                Value(src.Value)
            {}

            ~CatalogAlternateId() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Type"], Type);
                FromJsonUtilS(input["Value"], Value);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                Json::Value each_Value; ToJsonUtilS(Value, each_Value); output["Value"] = each_Value;
                return output;
            }
        };

        struct CatalogSpecificConfig : public PlayFabBaseModel
        {
            std::list<std::string> ContentTypes;
            std::list<std::string> Tags;

            CatalogSpecificConfig() :
                PlayFabBaseModel(),
                ContentTypes(),
                Tags()
            {}

            CatalogSpecificConfig(const CatalogSpecificConfig& src) :
                PlayFabBaseModel(),
                ContentTypes(src.ContentTypes),
                Tags(src.Tags)
            {}

            ~CatalogSpecificConfig() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContentTypes"], ContentTypes);
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContentTypes; ToJsonUtilS(ContentTypes, each_ContentTypes); output["ContentTypes"] = each_ContentTypes;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                return output;
            }
        };

        struct DeepLinkFormat : public PlayFabBaseModel
        {
            std::string Format;
            std::string Platform;

            DeepLinkFormat() :
                PlayFabBaseModel(),
                Format(),
                Platform()
            {}

            DeepLinkFormat(const DeepLinkFormat& src) :
                PlayFabBaseModel(),
                Format(src.Format),
                Platform(src.Platform)
            {}

            ~DeepLinkFormat() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Format"], Format);
                FromJsonUtilS(input["Platform"], Platform);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Format; ToJsonUtilS(Format, each_Format); output["Format"] = each_Format;
                Json::Value each_Platform; ToJsonUtilS(Platform, each_Platform); output["Platform"] = each_Platform;
                return output;
            }
        };

        struct DisplayPropertyIndexInfo : public PlayFabBaseModel
        {
            std::string Name;
            Boxed<DisplayPropertyType> Type;

            DisplayPropertyIndexInfo() :
                PlayFabBaseModel(),
                Name(),
                Type()
            {}

            DisplayPropertyIndexInfo(const DisplayPropertyIndexInfo& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Type(src.Type)
            {}

            ~DisplayPropertyIndexInfo() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilE(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Type; ToJsonUtilE(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct FileConfig : public PlayFabBaseModel
        {
            std::list<std::string> ContentTypes;
            std::list<std::string> Tags;

            FileConfig() :
                PlayFabBaseModel(),
                ContentTypes(),
                Tags()
            {}

            FileConfig(const FileConfig& src) :
                PlayFabBaseModel(),
                ContentTypes(src.ContentTypes),
                Tags(src.Tags)
            {}

            ~FileConfig() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContentTypes"], ContentTypes);
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContentTypes; ToJsonUtilS(ContentTypes, each_ContentTypes); output["ContentTypes"] = each_ContentTypes;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                return output;
            }
        };

        struct ImageConfig : public PlayFabBaseModel
        {
            std::list<std::string> Tags;

            ImageConfig() :
                PlayFabBaseModel(),
                Tags()
            {}

            ImageConfig(const ImageConfig& src) :
                PlayFabBaseModel(),
                Tags(src.Tags)
            {}

            ~ImageConfig() = default;

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

        struct UserGeneratedContentSpecificConfig : public PlayFabBaseModel
        {
            std::list<std::string> ContentTypes;
            std::list<std::string> Tags;

            UserGeneratedContentSpecificConfig() :
                PlayFabBaseModel(),
                ContentTypes(),
                Tags()
            {}

            UserGeneratedContentSpecificConfig(const UserGeneratedContentSpecificConfig& src) :
                PlayFabBaseModel(),
                ContentTypes(src.ContentTypes),
                Tags(src.Tags)
            {}

            ~UserGeneratedContentSpecificConfig() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContentTypes"], ContentTypes);
                FromJsonUtilS(input["Tags"], Tags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContentTypes; ToJsonUtilS(ContentTypes, each_ContentTypes); output["ContentTypes"] = each_ContentTypes;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                return output;
            }
        };

        struct CatalogConfig : public PlayFabBaseModel
        {
            std::list<EntityKey> AdminEntities;
            Boxed<CatalogSpecificConfig> Catalog;
            std::list<DeepLinkFormat> DeepLinkFormats;
            std::list<DisplayPropertyIndexInfo> DisplayPropertyIndexInfos;
            Boxed<FileConfig> File;
            Boxed<ImageConfig> Image;
            bool IsCatalogEnabled;
            std::list<std::string> Platforms;
            std::list<EntityKey> ReviewerEntities;
            Boxed<UserGeneratedContentSpecificConfig> UserGeneratedContent;

            CatalogConfig() :
                PlayFabBaseModel(),
                AdminEntities(),
                Catalog(),
                DeepLinkFormats(),
                DisplayPropertyIndexInfos(),
                File(),
                Image(),
                IsCatalogEnabled(),
                Platforms(),
                ReviewerEntities(),
                UserGeneratedContent()
            {}

            CatalogConfig(const CatalogConfig& src) :
                PlayFabBaseModel(),
                AdminEntities(src.AdminEntities),
                Catalog(src.Catalog),
                DeepLinkFormats(src.DeepLinkFormats),
                DisplayPropertyIndexInfos(src.DisplayPropertyIndexInfos),
                File(src.File),
                Image(src.Image),
                IsCatalogEnabled(src.IsCatalogEnabled),
                Platforms(src.Platforms),
                ReviewerEntities(src.ReviewerEntities),
                UserGeneratedContent(src.UserGeneratedContent)
            {}

            ~CatalogConfig() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AdminEntities"], AdminEntities);
                FromJsonUtilO(input["Catalog"], Catalog);
                FromJsonUtilO(input["DeepLinkFormats"], DeepLinkFormats);
                FromJsonUtilO(input["DisplayPropertyIndexInfos"], DisplayPropertyIndexInfos);
                FromJsonUtilO(input["File"], File);
                FromJsonUtilO(input["Image"], Image);
                FromJsonUtilP(input["IsCatalogEnabled"], IsCatalogEnabled);
                FromJsonUtilS(input["Platforms"], Platforms);
                FromJsonUtilO(input["ReviewerEntities"], ReviewerEntities);
                FromJsonUtilO(input["UserGeneratedContent"], UserGeneratedContent);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AdminEntities; ToJsonUtilO(AdminEntities, each_AdminEntities); output["AdminEntities"] = each_AdminEntities;
                Json::Value each_Catalog; ToJsonUtilO(Catalog, each_Catalog); output["Catalog"] = each_Catalog;
                Json::Value each_DeepLinkFormats; ToJsonUtilO(DeepLinkFormats, each_DeepLinkFormats); output["DeepLinkFormats"] = each_DeepLinkFormats;
                Json::Value each_DisplayPropertyIndexInfos; ToJsonUtilO(DisplayPropertyIndexInfos, each_DisplayPropertyIndexInfos); output["DisplayPropertyIndexInfos"] = each_DisplayPropertyIndexInfos;
                Json::Value each_File; ToJsonUtilO(File, each_File); output["File"] = each_File;
                Json::Value each_Image; ToJsonUtilO(Image, each_Image); output["Image"] = each_Image;
                Json::Value each_IsCatalogEnabled; ToJsonUtilP(IsCatalogEnabled, each_IsCatalogEnabled); output["IsCatalogEnabled"] = each_IsCatalogEnabled;
                Json::Value each_Platforms; ToJsonUtilS(Platforms, each_Platforms); output["Platforms"] = each_Platforms;
                Json::Value each_ReviewerEntities; ToJsonUtilO(ReviewerEntities, each_ReviewerEntities); output["ReviewerEntities"] = each_ReviewerEntities;
                Json::Value each_UserGeneratedContent; ToJsonUtilO(UserGeneratedContent, each_UserGeneratedContent); output["UserGeneratedContent"] = each_UserGeneratedContent;
                return output;
            }
        };

        struct Content : public PlayFabBaseModel
        {
            std::string Id;
            std::string MaxClientVersion;
            std::string MinClientVersion;
            std::list<std::string> Tags;
            std::string Type;
            std::string Url;

            Content() :
                PlayFabBaseModel(),
                Id(),
                MaxClientVersion(),
                MinClientVersion(),
                Tags(),
                Type(),
                Url()
            {}

            Content(const Content& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                MaxClientVersion(src.MaxClientVersion),
                MinClientVersion(src.MinClientVersion),
                Tags(src.Tags),
                Type(src.Type),
                Url(src.Url)
            {}

            ~Content() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["MaxClientVersion"], MaxClientVersion);
                FromJsonUtilS(input["MinClientVersion"], MinClientVersion);
                FromJsonUtilS(input["Tags"], Tags);
                FromJsonUtilS(input["Type"], Type);
                FromJsonUtilS(input["Url"], Url);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_MaxClientVersion; ToJsonUtilS(MaxClientVersion, each_MaxClientVersion); output["MaxClientVersion"] = each_MaxClientVersion;
                Json::Value each_MinClientVersion; ToJsonUtilS(MinClientVersion, each_MinClientVersion); output["MinClientVersion"] = each_MinClientVersion;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                Json::Value each_Url; ToJsonUtilS(Url, each_Url); output["Url"] = each_Url;
                return output;
            }
        };

        struct DeepLink : public PlayFabBaseModel
        {
            std::string Platform;
            std::string Url;

            DeepLink() :
                PlayFabBaseModel(),
                Platform(),
                Url()
            {}

            DeepLink(const DeepLink& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                Url(src.Url)
            {}

            ~DeepLink() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Platform"], Platform);
                FromJsonUtilS(input["Url"], Url);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Platform; ToJsonUtilS(Platform, each_Platform); output["Platform"] = each_Platform;
                Json::Value each_Url; ToJsonUtilS(Url, each_Url); output["Url"] = each_Url;
                return output;
            }
        };

        struct Image : public PlayFabBaseModel
        {
            std::string Id;
            std::string Tag;
            std::string Type;
            std::string Url;

            Image() :
                PlayFabBaseModel(),
                Id(),
                Tag(),
                Type(),
                Url()
            {}

            Image(const Image& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Tag(src.Tag),
                Type(src.Type),
                Url(src.Url)
            {}

            ~Image() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Tag"], Tag);
                FromJsonUtilS(input["Type"], Type);
                FromJsonUtilS(input["Url"], Url);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Tag; ToJsonUtilS(Tag, each_Tag); output["Tag"] = each_Tag;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                Json::Value each_Url; ToJsonUtilS(Url, each_Url); output["Url"] = each_Url;
                return output;
            }
        };

        struct CatalogPriceAmount : public PlayFabBaseModel
        {
            Int32 Amount;
            std::string ItemId;

            CatalogPriceAmount() :
                PlayFabBaseModel(),
                Amount(),
                ItemId()
            {}

            CatalogPriceAmount(const CatalogPriceAmount& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                ItemId(src.ItemId)
            {}

            ~CatalogPriceAmount() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["ItemId"], ItemId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                return output;
            }
        };

        struct CatalogPrice : public PlayFabBaseModel
        {
            std::list<CatalogPriceAmount> Amounts;

            CatalogPrice() :
                PlayFabBaseModel(),
                Amounts()
            {}

            CatalogPrice(const CatalogPrice& src) :
                PlayFabBaseModel(),
                Amounts(src.Amounts)
            {}

            ~CatalogPrice() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Amounts"], Amounts);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amounts; ToJsonUtilO(Amounts, each_Amounts); output["Amounts"] = each_Amounts;
                return output;
            }
        };

        struct CatalogPriceOptions : public PlayFabBaseModel
        {
            std::list<CatalogPrice> Prices;

            CatalogPriceOptions() :
                PlayFabBaseModel(),
                Prices()
            {}

            CatalogPriceOptions(const CatalogPriceOptions& src) :
                PlayFabBaseModel(),
                Prices(src.Prices)
            {}

            ~CatalogPriceOptions() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Prices"], Prices);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Prices; ToJsonUtilO(Prices, each_Prices); output["Prices"] = each_Prices;
                return output;
            }
        };

        struct CatalogItemReference : public PlayFabBaseModel
        {
            Boxed<Int32> Amount;
            std::string Id;
            Boxed<CatalogPriceOptions> PriceOptions;

            CatalogItemReference() :
                PlayFabBaseModel(),
                Amount(),
                Id(),
                PriceOptions()
            {}

            CatalogItemReference(const CatalogItemReference& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                Id(src.Id),
                PriceOptions(src.PriceOptions)
            {}

            ~CatalogItemReference() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["PriceOptions"], PriceOptions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_PriceOptions; ToJsonUtilO(PriceOptions, each_PriceOptions); output["PriceOptions"] = each_PriceOptions;
                return output;
            }
        };

        struct KeywordSet : public PlayFabBaseModel
        {
            std::list<std::string> Values;

            KeywordSet() :
                PlayFabBaseModel(),
                Values()
            {}

            KeywordSet(const KeywordSet& src) :
                PlayFabBaseModel(),
                Values(src.Values)
            {}

            ~KeywordSet() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Values"], Values);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Values; ToJsonUtilS(Values, each_Values); output["Values"] = each_Values;
                return output;
            }
        };

        struct ModerationState : public PlayFabBaseModel
        {
            Boxed<time_t> LastModifiedDate;
            std::string Reason;
            Boxed<ModerationStatus> Status;

            ModerationState() :
                PlayFabBaseModel(),
                LastModifiedDate(),
                Reason(),
                Status()
            {}

            ModerationState(const ModerationState& src) :
                PlayFabBaseModel(),
                LastModifiedDate(src.LastModifiedDate),
                Reason(src.Reason),
                Status(src.Status)
            {}

            ~ModerationState() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilT(input["LastModifiedDate"], LastModifiedDate);
                FromJsonUtilS(input["Reason"], Reason);
                FromJsonUtilE(input["Status"], Status);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LastModifiedDate; ToJsonUtilT(LastModifiedDate, each_LastModifiedDate); output["LastModifiedDate"] = each_LastModifiedDate;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                return output;
            }
        };

        struct Rating : public PlayFabBaseModel
        {
            Boxed<float> Average;
            Boxed<Int32> Count1Star;
            Boxed<Int32> Count2Star;
            Boxed<Int32> Count3Star;
            Boxed<Int32> Count4Star;
            Boxed<Int32> Count5Star;
            Boxed<Int32> TotalCount;

            Rating() :
                PlayFabBaseModel(),
                Average(),
                Count1Star(),
                Count2Star(),
                Count3Star(),
                Count4Star(),
                Count5Star(),
                TotalCount()
            {}

            Rating(const Rating& src) :
                PlayFabBaseModel(),
                Average(src.Average),
                Count1Star(src.Count1Star),
                Count2Star(src.Count2Star),
                Count3Star(src.Count3Star),
                Count4Star(src.Count4Star),
                Count5Star(src.Count5Star),
                TotalCount(src.TotalCount)
            {}

            ~Rating() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Average"], Average);
                FromJsonUtilP(input["Count1Star"], Count1Star);
                FromJsonUtilP(input["Count2Star"], Count2Star);
                FromJsonUtilP(input["Count3Star"], Count3Star);
                FromJsonUtilP(input["Count4Star"], Count4Star);
                FromJsonUtilP(input["Count5Star"], Count5Star);
                FromJsonUtilP(input["TotalCount"], TotalCount);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Average; ToJsonUtilP(Average, each_Average); output["Average"] = each_Average;
                Json::Value each_Count1Star; ToJsonUtilP(Count1Star, each_Count1Star); output["Count1Star"] = each_Count1Star;
                Json::Value each_Count2Star; ToJsonUtilP(Count2Star, each_Count2Star); output["Count2Star"] = each_Count2Star;
                Json::Value each_Count3Star; ToJsonUtilP(Count3Star, each_Count3Star); output["Count3Star"] = each_Count3Star;
                Json::Value each_Count4Star; ToJsonUtilP(Count4Star, each_Count4Star); output["Count4Star"] = each_Count4Star;
                Json::Value each_Count5Star; ToJsonUtilP(Count5Star, each_Count5Star); output["Count5Star"] = each_Count5Star;
                Json::Value each_TotalCount; ToJsonUtilP(TotalCount, each_TotalCount); output["TotalCount"] = each_TotalCount;
                return output;
            }
        };

        struct FilterOptions : public PlayFabBaseModel
        {
            std::string Filter;
            Boxed<bool> IncludeAllItems;

            FilterOptions() :
                PlayFabBaseModel(),
                Filter(),
                IncludeAllItems()
            {}

            FilterOptions(const FilterOptions& src) :
                PlayFabBaseModel(),
                Filter(src.Filter),
                IncludeAllItems(src.IncludeAllItems)
            {}

            ~FilterOptions() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilP(input["IncludeAllItems"], IncludeAllItems);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_IncludeAllItems; ToJsonUtilP(IncludeAllItems, each_IncludeAllItems); output["IncludeAllItems"] = each_IncludeAllItems;
                return output;
            }
        };

        struct CatalogPriceAmountOverride : public PlayFabBaseModel
        {
            Boxed<Int32> FixedValue;
            std::string ItemId;
            Boxed<double> Multiplier;

            CatalogPriceAmountOverride() :
                PlayFabBaseModel(),
                FixedValue(),
                ItemId(),
                Multiplier()
            {}

            CatalogPriceAmountOverride(const CatalogPriceAmountOverride& src) :
                PlayFabBaseModel(),
                FixedValue(src.FixedValue),
                ItemId(src.ItemId),
                Multiplier(src.Multiplier)
            {}

            ~CatalogPriceAmountOverride() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["FixedValue"], FixedValue);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilP(input["Multiplier"], Multiplier);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FixedValue; ToJsonUtilP(FixedValue, each_FixedValue); output["FixedValue"] = each_FixedValue;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Multiplier; ToJsonUtilP(Multiplier, each_Multiplier); output["Multiplier"] = each_Multiplier;
                return output;
            }
        };

        struct CatalogPriceOverride : public PlayFabBaseModel
        {
            std::list<CatalogPriceAmountOverride> Amounts;

            CatalogPriceOverride() :
                PlayFabBaseModel(),
                Amounts()
            {}

            CatalogPriceOverride(const CatalogPriceOverride& src) :
                PlayFabBaseModel(),
                Amounts(src.Amounts)
            {}

            ~CatalogPriceOverride() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Amounts"], Amounts);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amounts; ToJsonUtilO(Amounts, each_Amounts); output["Amounts"] = each_Amounts;
                return output;
            }
        };

        struct CatalogPriceOptionsOverride : public PlayFabBaseModel
        {
            std::list<CatalogPriceOverride> Prices;

            CatalogPriceOptionsOverride() :
                PlayFabBaseModel(),
                Prices()
            {}

            CatalogPriceOptionsOverride(const CatalogPriceOptionsOverride& src) :
                PlayFabBaseModel(),
                Prices(src.Prices)
            {}

            ~CatalogPriceOptionsOverride() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Prices"], Prices);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Prices; ToJsonUtilO(Prices, each_Prices); output["Prices"] = each_Prices;
                return output;
            }
        };

        struct StoreDetails : public PlayFabBaseModel
        {
            Boxed<FilterOptions> pfFilterOptions;
            Boxed<CatalogPriceOptionsOverride> PriceOptionsOverride;

            StoreDetails() :
                PlayFabBaseModel(),
                pfFilterOptions(),
                PriceOptionsOverride()
            {}

            StoreDetails(const StoreDetails& src) :
                PlayFabBaseModel(),
                pfFilterOptions(src.pfFilterOptions),
                PriceOptionsOverride(src.PriceOptionsOverride)
            {}

            ~StoreDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["FilterOptions"], pfFilterOptions);
                FromJsonUtilO(input["PriceOptionsOverride"], PriceOptionsOverride);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfFilterOptions; ToJsonUtilO(pfFilterOptions, each_pfFilterOptions); output["FilterOptions"] = each_pfFilterOptions;
                Json::Value each_PriceOptionsOverride; ToJsonUtilO(PriceOptionsOverride, each_PriceOptionsOverride); output["PriceOptionsOverride"] = each_PriceOptionsOverride;
                return output;
            }
        };

        struct CatalogItem : public PlayFabBaseModel
        {
            std::list<CatalogAlternateId> AlternateIds;
            std::list<Content> Contents;
            std::string ContentType;
            Boxed<time_t> CreationDate;
            Boxed<EntityKey> CreatorEntity;
            std::list<DeepLink> DeepLinks;
            std::map<std::string, std::string> Description;
            Json::Value DisplayProperties;
            std::string DisplayVersion;
            Boxed<time_t> EndDate;
            std::string ETag;
            std::string Id;
            std::list<Image> Images;
            Boxed<bool> IsHidden;
            std::list<CatalogItemReference> ItemReferences;
            std::map<std::string, KeywordSet> Keywords;
            Boxed<time_t> LastModifiedDate;
            Boxed<ModerationState> Moderation;
            std::list<std::string> Platforms;
            Boxed<CatalogPriceOptions> PriceOptions;
            Boxed<Rating> pfRating;
            Boxed<time_t> StartDate;
            Boxed<StoreDetails> pfStoreDetails;
            std::list<std::string> Tags;
            std::map<std::string, std::string> Title;
            std::string Type;

            CatalogItem() :
                PlayFabBaseModel(),
                AlternateIds(),
                Contents(),
                ContentType(),
                CreationDate(),
                CreatorEntity(),
                DeepLinks(),
                Description(),
                DisplayProperties(),
                DisplayVersion(),
                EndDate(),
                ETag(),
                Id(),
                Images(),
                IsHidden(),
                ItemReferences(),
                Keywords(),
                LastModifiedDate(),
                Moderation(),
                Platforms(),
                PriceOptions(),
                pfRating(),
                StartDate(),
                pfStoreDetails(),
                Tags(),
                Title(),
                Type()
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                AlternateIds(src.AlternateIds),
                Contents(src.Contents),
                ContentType(src.ContentType),
                CreationDate(src.CreationDate),
                CreatorEntity(src.CreatorEntity),
                DeepLinks(src.DeepLinks),
                Description(src.Description),
                DisplayProperties(src.DisplayProperties),
                DisplayVersion(src.DisplayVersion),
                EndDate(src.EndDate),
                ETag(src.ETag),
                Id(src.Id),
                Images(src.Images),
                IsHidden(src.IsHidden),
                ItemReferences(src.ItemReferences),
                Keywords(src.Keywords),
                LastModifiedDate(src.LastModifiedDate),
                Moderation(src.Moderation),
                Platforms(src.Platforms),
                PriceOptions(src.PriceOptions),
                pfRating(src.pfRating),
                StartDate(src.StartDate),
                pfStoreDetails(src.pfStoreDetails),
                Tags(src.Tags),
                Title(src.Title),
                Type(src.Type)
            {}

            ~CatalogItem() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateIds"], AlternateIds);
                FromJsonUtilO(input["Contents"], Contents);
                FromJsonUtilS(input["ContentType"], ContentType);
                FromJsonUtilT(input["CreationDate"], CreationDate);
                FromJsonUtilO(input["CreatorEntity"], CreatorEntity);
                FromJsonUtilO(input["DeepLinks"], DeepLinks);
                FromJsonUtilS(input["Description"], Description);
                DisplayProperties = input["DisplayProperties"];
                FromJsonUtilS(input["DisplayVersion"], DisplayVersion);
                FromJsonUtilT(input["EndDate"], EndDate);
                FromJsonUtilS(input["ETag"], ETag);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["Images"], Images);
                FromJsonUtilP(input["IsHidden"], IsHidden);
                FromJsonUtilO(input["ItemReferences"], ItemReferences);
                FromJsonUtilO(input["Keywords"], Keywords);
                FromJsonUtilT(input["LastModifiedDate"], LastModifiedDate);
                FromJsonUtilO(input["Moderation"], Moderation);
                FromJsonUtilS(input["Platforms"], Platforms);
                FromJsonUtilO(input["PriceOptions"], PriceOptions);
                FromJsonUtilO(input["Rating"], pfRating);
                FromJsonUtilT(input["StartDate"], StartDate);
                FromJsonUtilO(input["StoreDetails"], pfStoreDetails);
                FromJsonUtilS(input["Tags"], Tags);
                FromJsonUtilS(input["Title"], Title);
                FromJsonUtilS(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateIds; ToJsonUtilO(AlternateIds, each_AlternateIds); output["AlternateIds"] = each_AlternateIds;
                Json::Value each_Contents; ToJsonUtilO(Contents, each_Contents); output["Contents"] = each_Contents;
                Json::Value each_ContentType; ToJsonUtilS(ContentType, each_ContentType); output["ContentType"] = each_ContentType;
                Json::Value each_CreationDate; ToJsonUtilT(CreationDate, each_CreationDate); output["CreationDate"] = each_CreationDate;
                Json::Value each_CreatorEntity; ToJsonUtilO(CreatorEntity, each_CreatorEntity); output["CreatorEntity"] = each_CreatorEntity;
                Json::Value each_DeepLinks; ToJsonUtilO(DeepLinks, each_DeepLinks); output["DeepLinks"] = each_DeepLinks;
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                output["DisplayProperties"] = DisplayProperties;
                Json::Value each_DisplayVersion; ToJsonUtilS(DisplayVersion, each_DisplayVersion); output["DisplayVersion"] = each_DisplayVersion;
                Json::Value each_EndDate; ToJsonUtilT(EndDate, each_EndDate); output["EndDate"] = each_EndDate;
                Json::Value each_ETag; ToJsonUtilS(ETag, each_ETag); output["ETag"] = each_ETag;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Images; ToJsonUtilO(Images, each_Images); output["Images"] = each_Images;
                Json::Value each_IsHidden; ToJsonUtilP(IsHidden, each_IsHidden); output["IsHidden"] = each_IsHidden;
                Json::Value each_ItemReferences; ToJsonUtilO(ItemReferences, each_ItemReferences); output["ItemReferences"] = each_ItemReferences;
                Json::Value each_Keywords; ToJsonUtilO(Keywords, each_Keywords); output["Keywords"] = each_Keywords;
                Json::Value each_LastModifiedDate; ToJsonUtilT(LastModifiedDate, each_LastModifiedDate); output["LastModifiedDate"] = each_LastModifiedDate;
                Json::Value each_Moderation; ToJsonUtilO(Moderation, each_Moderation); output["Moderation"] = each_Moderation;
                Json::Value each_Platforms; ToJsonUtilS(Platforms, each_Platforms); output["Platforms"] = each_Platforms;
                Json::Value each_PriceOptions; ToJsonUtilO(PriceOptions, each_PriceOptions); output["PriceOptions"] = each_PriceOptions;
                Json::Value each_pfRating; ToJsonUtilO(pfRating, each_pfRating); output["Rating"] = each_pfRating;
                Json::Value each_StartDate; ToJsonUtilT(StartDate, each_StartDate); output["StartDate"] = each_StartDate;
                Json::Value each_pfStoreDetails; ToJsonUtilO(pfStoreDetails, each_pfStoreDetails); output["StoreDetails"] = each_pfStoreDetails;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                Json::Value each_Title; ToJsonUtilS(Title, each_Title); output["Title"] = each_Title;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct ContentFeed : public PlayFabBaseModel
        {

            ContentFeed() :
                PlayFabBaseModel()
            {}

            ContentFeed(const ContentFeed&) :
                PlayFabBaseModel()
            {}

            ~ContentFeed() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct CreateDraftItemRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<CatalogItem> Item;
            bool Publish;

            CreateDraftItemRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Item(),
                Publish()
            {}

            CreateDraftItemRequest(const CreateDraftItemRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Item(src.Item),
                Publish(src.Publish)
            {}

            ~CreateDraftItemRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Item"], Item);
                FromJsonUtilP(input["Publish"], Publish);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                Json::Value each_Publish; ToJsonUtilP(Publish, each_Publish); output["Publish"] = each_Publish;
                return output;
            }
        };

        struct CreateDraftItemResponse : public PlayFabResultCommon
        {
            Boxed<CatalogItem> Item;

            CreateDraftItemResponse() :
                PlayFabResultCommon(),
                Item()
            {}

            CreateDraftItemResponse(const CreateDraftItemResponse& src) :
                PlayFabResultCommon(),
                Item(src.Item)
            {}

            ~CreateDraftItemResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct UploadInfo : public PlayFabBaseModel
        {
            std::string FileName;

            UploadInfo() :
                PlayFabBaseModel(),
                FileName()
            {}

            UploadInfo(const UploadInfo& src) :
                PlayFabBaseModel(),
                FileName(src.FileName)
            {}

            ~UploadInfo() = default;

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

        struct CreateUploadUrlsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::list<UploadInfo> Files;

            CreateUploadUrlsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Files()
            {}

            CreateUploadUrlsRequest(const CreateUploadUrlsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Files(src.Files)
            {}

            ~CreateUploadUrlsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Files"], Files);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Files; ToJsonUtilO(Files, each_Files); output["Files"] = each_Files;
                return output;
            }
        };

        struct UploadUrlMetadata : public PlayFabBaseModel
        {
            std::string FileName;
            std::string Id;
            std::string Url;

            UploadUrlMetadata() :
                PlayFabBaseModel(),
                FileName(),
                Id(),
                Url()
            {}

            UploadUrlMetadata(const UploadUrlMetadata& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                Id(src.Id),
                Url(src.Url)
            {}

            ~UploadUrlMetadata() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["FileName"], FileName);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Url"], Url);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FileName; ToJsonUtilS(FileName, each_FileName); output["FileName"] = each_FileName;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Url; ToJsonUtilS(Url, each_Url); output["Url"] = each_Url;
                return output;
            }
        };

        struct CreateUploadUrlsResponse : public PlayFabResultCommon
        {
            std::list<UploadUrlMetadata> UploadUrls;

            CreateUploadUrlsResponse() :
                PlayFabResultCommon(),
                UploadUrls()
            {}

            CreateUploadUrlsResponse(const CreateUploadUrlsResponse& src) :
                PlayFabResultCommon(),
                UploadUrls(src.UploadUrls)
            {}

            ~CreateUploadUrlsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["UploadUrls"], UploadUrls);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_UploadUrls; ToJsonUtilO(UploadUrls, each_UploadUrls); output["UploadUrls"] = each_UploadUrls;
                return output;
            }
        };

        struct DeleteEntityItemReviewsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteEntityItemReviewsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Entity()
            {}

            DeleteEntityItemReviewsRequest(const DeleteEntityItemReviewsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteEntityItemReviewsRequest() = default;

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

        struct DeleteEntityItemReviewsResponse : public PlayFabResultCommon
        {

            DeleteEntityItemReviewsResponse() :
                PlayFabResultCommon()
            {}

            DeleteEntityItemReviewsResponse(const DeleteEntityItemReviewsResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteEntityItemReviewsResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteInventoryCollectionRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            DeleteInventoryCollectionRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                CustomTags(),
                Entity()
            {}

            DeleteInventoryCollectionRequest(const DeleteInventoryCollectionRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~DeleteInventoryCollectionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct DeleteInventoryCollectionResponse : public PlayFabResultCommon
        {

            DeleteInventoryCollectionResponse() :
                PlayFabResultCommon()
            {}

            DeleteInventoryCollectionResponse(const DeleteInventoryCollectionResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteInventoryCollectionResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct DeleteInventoryItemsOperation : public PlayFabBaseModel
        {
            Boxed<InventoryItemReference> Item;

            DeleteInventoryItemsOperation() :
                PlayFabBaseModel(),
                Item()
            {}

            DeleteInventoryItemsOperation(const DeleteInventoryItemsOperation& src) :
                PlayFabBaseModel(),
                Item(src.Item)
            {}

            ~DeleteInventoryItemsOperation() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct DeleteInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            Boxed<InventoryItemReference> Item;

            DeleteInventoryItemsRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                CustomTags(),
                Entity(),
                IdempotencyId(),
                Item()
            {}

            DeleteInventoryItemsRequest(const DeleteInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Item(src.Item)
            {}

            ~DeleteInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct DeleteInventoryItemsResponse : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<std::string> TransactionIds;

            DeleteInventoryItemsResponse() :
                PlayFabResultCommon(),
                IdempotencyId(),
                TransactionIds()
            {}

            DeleteInventoryItemsResponse(const DeleteInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                TransactionIds(src.TransactionIds)
            {}

            ~DeleteInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct DeleteItemRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Id;

            DeleteItemRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Entity(),
                Id()
            {}

            DeleteItemRequest(const DeleteItemRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Id(src.Id)
            {}

            ~DeleteItemRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct DeleteItemResponse : public PlayFabResultCommon
        {

            DeleteItemResponse() :
                PlayFabResultCommon()
            {}

            DeleteItemResponse(const DeleteItemResponse&) :
                PlayFabResultCommon()
            {}

            ~DeleteItemResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct PurchasePriceAmount : public PlayFabBaseModel
        {
            Int32 Amount;
            std::string ItemId;
            std::string StackId;

            PurchasePriceAmount() :
                PlayFabBaseModel(),
                Amount(),
                ItemId(),
                StackId()
            {}

            PurchasePriceAmount(const PurchasePriceAmount& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                ItemId(src.ItemId),
                StackId(src.StackId)
            {}

            ~PurchasePriceAmount() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["StackId"], StackId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_StackId; ToJsonUtilS(StackId, each_StackId); output["StackId"] = each_StackId;
                return output;
            }
        };

        struct PurchaseInventoryItemsOperation : public PlayFabBaseModel
        {
            Int32 Amount;
            bool DeleteEmptyStacks;
            Boxed<InventoryItemReference> Item;
            std::list<PurchasePriceAmount> PriceAmounts;
            std::string StoreId;

            PurchaseInventoryItemsOperation() :
                PlayFabBaseModel(),
                Amount(),
                DeleteEmptyStacks(),
                Item(),
                PriceAmounts(),
                StoreId()
            {}

            PurchaseInventoryItemsOperation(const PurchaseInventoryItemsOperation& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                DeleteEmptyStacks(src.DeleteEmptyStacks),
                Item(src.Item),
                PriceAmounts(src.PriceAmounts),
                StoreId(src.StoreId)
            {}

            ~PurchaseInventoryItemsOperation() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilP(input["DeleteEmptyStacks"], DeleteEmptyStacks);
                FromJsonUtilO(input["Item"], Item);
                FromJsonUtilO(input["PriceAmounts"], PriceAmounts);
                FromJsonUtilS(input["StoreId"], StoreId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_DeleteEmptyStacks; ToJsonUtilP(DeleteEmptyStacks, each_DeleteEmptyStacks); output["DeleteEmptyStacks"] = each_DeleteEmptyStacks;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                Json::Value each_PriceAmounts; ToJsonUtilO(PriceAmounts, each_PriceAmounts); output["PriceAmounts"] = each_PriceAmounts;
                Json::Value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output["StoreId"] = each_StoreId;
                return output;
            }
        };

        struct SubtractInventoryItemsOperation : public PlayFabBaseModel
        {
            Int32 Amount;
            bool DeleteEmptyStacks;
            Boxed<InventoryItemReference> Item;

            SubtractInventoryItemsOperation() :
                PlayFabBaseModel(),
                Amount(),
                DeleteEmptyStacks(),
                Item()
            {}

            SubtractInventoryItemsOperation(const SubtractInventoryItemsOperation& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                DeleteEmptyStacks(src.DeleteEmptyStacks),
                Item(src.Item)
            {}

            ~SubtractInventoryItemsOperation() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilP(input["DeleteEmptyStacks"], DeleteEmptyStacks);
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_DeleteEmptyStacks; ToJsonUtilP(DeleteEmptyStacks, each_DeleteEmptyStacks); output["DeleteEmptyStacks"] = each_DeleteEmptyStacks;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct TransferInventoryItemsOperation : public PlayFabBaseModel
        {
            Int32 Amount;
            bool DeleteEmptyStacks;
            Boxed<InventoryItemReference> GivingItem;
            Boxed<InventoryItemReference> ReceivingItem;

            TransferInventoryItemsOperation() :
                PlayFabBaseModel(),
                Amount(),
                DeleteEmptyStacks(),
                GivingItem(),
                ReceivingItem()
            {}

            TransferInventoryItemsOperation(const TransferInventoryItemsOperation& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                DeleteEmptyStacks(src.DeleteEmptyStacks),
                GivingItem(src.GivingItem),
                ReceivingItem(src.ReceivingItem)
            {}

            ~TransferInventoryItemsOperation() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilP(input["DeleteEmptyStacks"], DeleteEmptyStacks);
                FromJsonUtilO(input["GivingItem"], GivingItem);
                FromJsonUtilO(input["ReceivingItem"], ReceivingItem);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_DeleteEmptyStacks; ToJsonUtilP(DeleteEmptyStacks, each_DeleteEmptyStacks); output["DeleteEmptyStacks"] = each_DeleteEmptyStacks;
                Json::Value each_GivingItem; ToJsonUtilO(GivingItem, each_GivingItem); output["GivingItem"] = each_GivingItem;
                Json::Value each_ReceivingItem; ToJsonUtilO(ReceivingItem, each_ReceivingItem); output["ReceivingItem"] = each_ReceivingItem;
                return output;
            }
        };

        struct InventoryItem : public PlayFabBaseModel
        {
            Int32 Amount;
            std::string Id;
            std::string StackId;
            std::string Type;

            InventoryItem() :
                PlayFabBaseModel(),
                Amount(),
                Id(),
                StackId(),
                Type()
            {}

            InventoryItem(const InventoryItem& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                Id(src.Id),
                StackId(src.StackId),
                Type(src.Type)
            {}

            ~InventoryItem() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["StackId"], StackId);
                FromJsonUtilS(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_StackId; ToJsonUtilS(StackId, each_StackId); output["StackId"] = each_StackId;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct UpdateInventoryItemsOperation : public PlayFabBaseModel
        {
            Boxed<InventoryItem> Item;

            UpdateInventoryItemsOperation() :
                PlayFabBaseModel(),
                Item()
            {}

            UpdateInventoryItemsOperation(const UpdateInventoryItemsOperation& src) :
                PlayFabBaseModel(),
                Item(src.Item)
            {}

            ~UpdateInventoryItemsOperation() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct InventoryOperation : public PlayFabBaseModel
        {
            Boxed<AddInventoryItemsOperation> Add;
            Boxed<DeleteInventoryItemsOperation> Delete;
            Boxed<PurchaseInventoryItemsOperation> Purchase;
            Boxed<SubtractInventoryItemsOperation> Subtract;
            Boxed<TransferInventoryItemsOperation> Transfer;
            Boxed<UpdateInventoryItemsOperation> Update;

            InventoryOperation() :
                PlayFabBaseModel(),
                Add(),
                Delete(),
                Purchase(),
                Subtract(),
                Transfer(),
                Update()
            {}

            InventoryOperation(const InventoryOperation& src) :
                PlayFabBaseModel(),
                Add(src.Add),
                Delete(src.Delete),
                Purchase(src.Purchase),
                Subtract(src.Subtract),
                Transfer(src.Transfer),
                Update(src.Update)
            {}

            ~InventoryOperation() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Add"], Add);
                FromJsonUtilO(input["Delete"], Delete);
                FromJsonUtilO(input["Purchase"], Purchase);
                FromJsonUtilO(input["Subtract"], Subtract);
                FromJsonUtilO(input["Transfer"], Transfer);
                FromJsonUtilO(input["Update"], Update);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Add; ToJsonUtilO(Add, each_Add); output["Add"] = each_Add;
                Json::Value each_Delete; ToJsonUtilO(Delete, each_Delete); output["Delete"] = each_Delete;
                Json::Value each_Purchase; ToJsonUtilO(Purchase, each_Purchase); output["Purchase"] = each_Purchase;
                Json::Value each_Subtract; ToJsonUtilO(Subtract, each_Subtract); output["Subtract"] = each_Subtract;
                Json::Value each_Transfer; ToJsonUtilO(Transfer, each_Transfer); output["Transfer"] = each_Transfer;
                Json::Value each_Update; ToJsonUtilO(Update, each_Update); output["Update"] = each_Update;
                return output;
            }
        };

        struct ExecuteInventoryOperationsRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            std::list<InventoryOperation> Operations;

            ExecuteInventoryOperationsRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                CustomTags(),
                Entity(),
                IdempotencyId(),
                Operations()
            {}

            ExecuteInventoryOperationsRequest(const ExecuteInventoryOperationsRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Operations(src.Operations)
            {}

            ~ExecuteInventoryOperationsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Operations"], Operations);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Operations; ToJsonUtilO(Operations, each_Operations); output["Operations"] = each_Operations;
                return output;
            }
        };

        struct ExecuteInventoryOperationsResponse : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<std::string> TransactionIds;

            ExecuteInventoryOperationsResponse() :
                PlayFabResultCommon(),
                IdempotencyId(),
                TransactionIds()
            {}

            ExecuteInventoryOperationsResponse(const ExecuteInventoryOperationsResponse& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                TransactionIds(src.TransactionIds)
            {}

            ~ExecuteInventoryOperationsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct GetCatalogConfigRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            GetCatalogConfigRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            GetCatalogConfigRequest(const GetCatalogConfigRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~GetCatalogConfigRequest() = default;

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

        struct GetCatalogConfigResponse : public PlayFabResultCommon
        {
            Boxed<CatalogConfig> Config;

            GetCatalogConfigResponse() :
                PlayFabResultCommon(),
                Config()
            {}

            GetCatalogConfigResponse(const GetCatalogConfigResponse& src) :
                PlayFabResultCommon(),
                Config(src.Config)
            {}

            ~GetCatalogConfigResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Config"], Config);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Config; ToJsonUtilO(Config, each_Config); output["Config"] = each_Config;
                return output;
            }
        };

        struct GetDraftItemRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Id;

            GetDraftItemRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Entity(),
                Id()
            {}

            GetDraftItemRequest(const GetDraftItemRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Id(src.Id)
            {}

            ~GetDraftItemRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct GetDraftItemResponse : public PlayFabResultCommon
        {
            Boxed<CatalogItem> Item;

            GetDraftItemResponse() :
                PlayFabResultCommon(),
                Item()
            {}

            GetDraftItemResponse(const GetDraftItemResponse& src) :
                PlayFabResultCommon(),
                Item(src.Item)
            {}

            ~GetDraftItemResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct GetDraftItemsRequest : public PlayFabRequestCommon
        {
            std::list<CatalogAlternateId> AlternateIds;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::list<std::string> Ids;

            GetDraftItemsRequest() :
                PlayFabRequestCommon(),
                AlternateIds(),
                CustomTags(),
                Entity(),
                Ids()
            {}

            GetDraftItemsRequest(const GetDraftItemsRequest& src) :
                PlayFabRequestCommon(),
                AlternateIds(src.AlternateIds),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Ids(src.Ids)
            {}

            ~GetDraftItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateIds"], AlternateIds);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Ids"], Ids);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateIds; ToJsonUtilO(AlternateIds, each_AlternateIds); output["AlternateIds"] = each_AlternateIds;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Ids; ToJsonUtilS(Ids, each_Ids); output["Ids"] = each_Ids;
                return output;
            }
        };

        struct GetDraftItemsResponse : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            std::list<CatalogItem> Items;

            GetDraftItemsResponse() :
                PlayFabResultCommon(),
                ContinuationToken(),
                Items()
            {}

            GetDraftItemsResponse(const GetDraftItemsResponse& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                Items(src.Items)
            {}

            ~GetDraftItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct GetEntityDraftItemsRequest : public PlayFabRequestCommon
        {
            std::string ContinuationToken;
            Int32 Count;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Filter;

            GetEntityDraftItemsRequest() :
                PlayFabRequestCommon(),
                ContinuationToken(),
                Count(),
                CustomTags(),
                Entity(),
                Filter()
            {}

            GetEntityDraftItemsRequest(const GetEntityDraftItemsRequest& src) :
                PlayFabRequestCommon(),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Filter(src.Filter)
            {}

            ~GetEntityDraftItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Filter"], Filter);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                return output;
            }
        };

        struct GetEntityDraftItemsResponse : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            std::list<CatalogItem> Items;

            GetEntityDraftItemsResponse() :
                PlayFabResultCommon(),
                ContinuationToken(),
                Items()
            {}

            GetEntityDraftItemsResponse(const GetEntityDraftItemsResponse& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                Items(src.Items)
            {}

            ~GetEntityDraftItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct GetEntityItemReviewRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Id;

            GetEntityItemReviewRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Entity(),
                Id()
            {}

            GetEntityItemReviewRequest(const GetEntityItemReviewRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Id(src.Id)
            {}

            ~GetEntityItemReviewRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct Review : public PlayFabBaseModel
        {
            Int32 HelpfulNegative;
            Int32 HelpfulPositive;
            bool IsInstalled;
            std::string ItemId;
            std::string ItemVersion;
            std::string Locale;
            Int32 Rating;
            Boxed<EntityKey> ReviewerEntity;
            std::string ReviewerId;
            std::string ReviewId;
            std::string ReviewText;
            time_t Submitted;
            std::string Title;

            Review() :
                PlayFabBaseModel(),
                HelpfulNegative(),
                HelpfulPositive(),
                IsInstalled(),
                ItemId(),
                ItemVersion(),
                Locale(),
                Rating(),
                ReviewerEntity(),
                ReviewerId(),
                ReviewId(),
                ReviewText(),
                Submitted(),
                Title()
            {}

            Review(const Review& src) :
                PlayFabBaseModel(),
                HelpfulNegative(src.HelpfulNegative),
                HelpfulPositive(src.HelpfulPositive),
                IsInstalled(src.IsInstalled),
                ItemId(src.ItemId),
                ItemVersion(src.ItemVersion),
                Locale(src.Locale),
                Rating(src.Rating),
                ReviewerEntity(src.ReviewerEntity),
                ReviewerId(src.ReviewerId),
                ReviewId(src.ReviewId),
                ReviewText(src.ReviewText),
                Submitted(src.Submitted),
                Title(src.Title)
            {}

            ~Review() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["HelpfulNegative"], HelpfulNegative);
                FromJsonUtilP(input["HelpfulPositive"], HelpfulPositive);
                FromJsonUtilP(input["IsInstalled"], IsInstalled);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ItemVersion"], ItemVersion);
                FromJsonUtilS(input["Locale"], Locale);
                FromJsonUtilP(input["Rating"], Rating);
                FromJsonUtilO(input["ReviewerEntity"], ReviewerEntity);
                FromJsonUtilS(input["ReviewerId"], ReviewerId);
                FromJsonUtilS(input["ReviewId"], ReviewId);
                FromJsonUtilS(input["ReviewText"], ReviewText);
                FromJsonUtilT(input["Submitted"], Submitted);
                FromJsonUtilS(input["Title"], Title);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_HelpfulNegative; ToJsonUtilP(HelpfulNegative, each_HelpfulNegative); output["HelpfulNegative"] = each_HelpfulNegative;
                Json::Value each_HelpfulPositive; ToJsonUtilP(HelpfulPositive, each_HelpfulPositive); output["HelpfulPositive"] = each_HelpfulPositive;
                Json::Value each_IsInstalled; ToJsonUtilP(IsInstalled, each_IsInstalled); output["IsInstalled"] = each_IsInstalled;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ItemVersion; ToJsonUtilS(ItemVersion, each_ItemVersion); output["ItemVersion"] = each_ItemVersion;
                Json::Value each_Locale; ToJsonUtilS(Locale, each_Locale); output["Locale"] = each_Locale;
                Json::Value each_Rating; ToJsonUtilP(Rating, each_Rating); output["Rating"] = each_Rating;
                Json::Value each_ReviewerEntity; ToJsonUtilO(ReviewerEntity, each_ReviewerEntity); output["ReviewerEntity"] = each_ReviewerEntity;
                Json::Value each_ReviewerId; ToJsonUtilS(ReviewerId, each_ReviewerId); output["ReviewerId"] = each_ReviewerId;
                Json::Value each_ReviewId; ToJsonUtilS(ReviewId, each_ReviewId); output["ReviewId"] = each_ReviewId;
                Json::Value each_ReviewText; ToJsonUtilS(ReviewText, each_ReviewText); output["ReviewText"] = each_ReviewText;
                Json::Value each_Submitted; ToJsonUtilT(Submitted, each_Submitted); output["Submitted"] = each_Submitted;
                Json::Value each_Title; ToJsonUtilS(Title, each_Title); output["Title"] = each_Title;
                return output;
            }
        };

        struct GetEntityItemReviewResponse : public PlayFabResultCommon
        {
            Boxed<Review> pfReview;

            GetEntityItemReviewResponse() :
                PlayFabResultCommon(),
                pfReview()
            {}

            GetEntityItemReviewResponse(const GetEntityItemReviewResponse& src) :
                PlayFabResultCommon(),
                pfReview(src.pfReview)
            {}

            ~GetEntityItemReviewResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Review"], pfReview);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_pfReview; ToJsonUtilO(pfReview, each_pfReview); output["Review"] = each_pfReview;
                return output;
            }
        };

        struct GetInventoryCollectionIdsRequest : public PlayFabRequestCommon
        {
            std::string ContinuationToken;
            Int32 Count;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            GetInventoryCollectionIdsRequest() :
                PlayFabRequestCommon(),
                ContinuationToken(),
                Count(),
                CustomTags(),
                Entity()
            {}

            GetInventoryCollectionIdsRequest(const GetInventoryCollectionIdsRequest& src) :
                PlayFabRequestCommon(),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetInventoryCollectionIdsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct GetInventoryCollectionIdsResponse : public PlayFabResultCommon
        {
            std::list<std::string> CollectionIds;
            std::string ContinuationToken;

            GetInventoryCollectionIdsResponse() :
                PlayFabResultCommon(),
                CollectionIds(),
                ContinuationToken()
            {}

            GetInventoryCollectionIdsResponse(const GetInventoryCollectionIdsResponse& src) :
                PlayFabResultCommon(),
                CollectionIds(src.CollectionIds),
                ContinuationToken(src.ContinuationToken)
            {}

            ~GetInventoryCollectionIdsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionIds"], CollectionIds);
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionIds; ToJsonUtilS(CollectionIds, each_CollectionIds); output["CollectionIds"] = each_CollectionIds;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                return output;
            }
        };

        struct GetInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::string ContinuationToken;
            Int32 Count;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Filter;

            GetInventoryItemsRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                ContinuationToken(),
                Count(),
                CustomTags(),
                Entity(),
                Filter()
            {}

            GetInventoryItemsRequest(const GetInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Filter(src.Filter)
            {}

            ~GetInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Filter"], Filter);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                return output;
            }
        };

        struct GetInventoryItemsResponse : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            std::list<InventoryItem> Items;

            GetInventoryItemsResponse() :
                PlayFabResultCommon(),
                ContinuationToken(),
                Items()
            {}

            GetInventoryItemsResponse(const GetInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                Items(src.Items)
            {}

            ~GetInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct GetItemContainersRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::string ContinuationToken;
            Int32 Count;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Id;

            GetItemContainersRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                ContinuationToken(),
                Count(),
                CustomTags(),
                Entity(),
                Id()
            {}

            GetItemContainersRequest(const GetItemContainersRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Id(src.Id)
            {}

            ~GetItemContainersRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct GetItemContainersResponse : public PlayFabResultCommon
        {
            std::list<CatalogItem> Containers;
            std::string ContinuationToken;

            GetItemContainersResponse() :
                PlayFabResultCommon(),
                Containers(),
                ContinuationToken()
            {}

            GetItemContainersResponse(const GetItemContainersResponse& src) :
                PlayFabResultCommon(),
                Containers(src.Containers),
                ContinuationToken(src.ContinuationToken)
            {}

            ~GetItemContainersResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Containers"], Containers);
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Containers; ToJsonUtilO(Containers, each_Containers); output["Containers"] = each_Containers;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                return output;
            }
        };

        struct GetItemModerationStateRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            std::string Id;

            GetItemModerationStateRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Id()
            {}

            GetItemModerationStateRequest(const GetItemModerationStateRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Id(src.Id)
            {}

            ~GetItemModerationStateRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct GetItemModerationStateResponse : public PlayFabResultCommon
        {
            Boxed<ModerationState> State;

            GetItemModerationStateResponse() :
                PlayFabResultCommon(),
                State()
            {}

            GetItemModerationStateResponse(const GetItemModerationStateResponse& src) :
                PlayFabResultCommon(),
                State(src.State)
            {}

            ~GetItemModerationStateResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["State"], State);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_State; ToJsonUtilO(State, each_State); output["State"] = each_State;
                return output;
            }
        };

        struct GetItemPublishStatusRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Id;

            GetItemPublishStatusRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Entity(),
                Id()
            {}

            GetItemPublishStatusRequest(const GetItemPublishStatusRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Id(src.Id)
            {}

            ~GetItemPublishStatusRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct GetItemPublishStatusResponse : public PlayFabResultCommon
        {
            Boxed<PublishResult> Result;
            std::string StatusMessage;

            GetItemPublishStatusResponse() :
                PlayFabResultCommon(),
                Result(),
                StatusMessage()
            {}

            GetItemPublishStatusResponse(const GetItemPublishStatusResponse& src) :
                PlayFabResultCommon(),
                Result(src.Result),
                StatusMessage(src.StatusMessage)
            {}

            ~GetItemPublishStatusResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilE(input["Result"], Result);
                FromJsonUtilS(input["StatusMessage"], StatusMessage);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Result; ToJsonUtilE(Result, each_Result); output["Result"] = each_Result;
                Json::Value each_StatusMessage; ToJsonUtilS(StatusMessage, each_StatusMessage); output["StatusMessage"] = each_StatusMessage;
                return output;
            }
        };

        struct GetItemRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Id;

            GetItemRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Entity(),
                Id()
            {}

            GetItemRequest(const GetItemRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Id(src.Id)
            {}

            ~GetItemRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct GetItemResponse : public PlayFabResultCommon
        {
            Boxed<CatalogItem> Item;

            GetItemResponse() :
                PlayFabResultCommon(),
                Item()
            {}

            GetItemResponse(const GetItemResponse& src) :
                PlayFabResultCommon(),
                Item(src.Item)
            {}

            ~GetItemResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct GetItemReviewsRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::string ContinuationToken;
            Int32 Count;
            std::map<std::string, std::string> CustomTags;
            std::string Id;
            std::string OrderBy;

            GetItemReviewsRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                ContinuationToken(),
                Count(),
                CustomTags(),
                Id(),
                OrderBy()
            {}

            GetItemReviewsRequest(const GetItemReviewsRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                CustomTags(src.CustomTags),
                Id(src.Id),
                OrderBy(src.OrderBy)
            {}

            ~GetItemReviewsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["OrderBy"], OrderBy);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                return output;
            }
        };

        struct GetItemReviewsResponse : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            std::list<Review> Reviews;

            GetItemReviewsResponse() :
                PlayFabResultCommon(),
                ContinuationToken(),
                Reviews()
            {}

            GetItemReviewsResponse(const GetItemReviewsResponse& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                Reviews(src.Reviews)
            {}

            ~GetItemReviewsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilO(input["Reviews"], Reviews);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Reviews; ToJsonUtilO(Reviews, each_Reviews); output["Reviews"] = each_Reviews;
                return output;
            }
        };

        struct GetItemReviewSummaryRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            std::string Id;

            GetItemReviewSummaryRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Id()
            {}

            GetItemReviewSummaryRequest(const GetItemReviewSummaryRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Id(src.Id)
            {}

            ~GetItemReviewSummaryRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct GetItemReviewSummaryResponse : public PlayFabResultCommon
        {
            Boxed<Review> LeastFavorableReview;
            Boxed<Review> MostFavorableReview;
            Boxed<Rating> pfRating;
            Int32 ReviewsCount;

            GetItemReviewSummaryResponse() :
                PlayFabResultCommon(),
                LeastFavorableReview(),
                MostFavorableReview(),
                pfRating(),
                ReviewsCount()
            {}

            GetItemReviewSummaryResponse(const GetItemReviewSummaryResponse& src) :
                PlayFabResultCommon(),
                LeastFavorableReview(src.LeastFavorableReview),
                MostFavorableReview(src.MostFavorableReview),
                pfRating(src.pfRating),
                ReviewsCount(src.ReviewsCount)
            {}

            ~GetItemReviewSummaryResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["LeastFavorableReview"], LeastFavorableReview);
                FromJsonUtilO(input["MostFavorableReview"], MostFavorableReview);
                FromJsonUtilO(input["Rating"], pfRating);
                FromJsonUtilP(input["ReviewsCount"], ReviewsCount);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_LeastFavorableReview; ToJsonUtilO(LeastFavorableReview, each_LeastFavorableReview); output["LeastFavorableReview"] = each_LeastFavorableReview;
                Json::Value each_MostFavorableReview; ToJsonUtilO(MostFavorableReview, each_MostFavorableReview); output["MostFavorableReview"] = each_MostFavorableReview;
                Json::Value each_pfRating; ToJsonUtilO(pfRating, each_pfRating); output["Rating"] = each_pfRating;
                Json::Value each_ReviewsCount; ToJsonUtilP(ReviewsCount, each_ReviewsCount); output["ReviewsCount"] = each_ReviewsCount;
                return output;
            }
        };

        struct GetItemsRequest : public PlayFabRequestCommon
        {
            std::list<CatalogAlternateId> AlternateIds;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::list<std::string> Ids;

            GetItemsRequest() :
                PlayFabRequestCommon(),
                AlternateIds(),
                CustomTags(),
                Entity(),
                Ids()
            {}

            GetItemsRequest(const GetItemsRequest& src) :
                PlayFabRequestCommon(),
                AlternateIds(src.AlternateIds),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Ids(src.Ids)
            {}

            ~GetItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateIds"], AlternateIds);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Ids"], Ids);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateIds; ToJsonUtilO(AlternateIds, each_AlternateIds); output["AlternateIds"] = each_AlternateIds;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Ids; ToJsonUtilS(Ids, each_Ids); output["Ids"] = each_Ids;
                return output;
            }
        };

        struct GetItemsResponse : public PlayFabResultCommon
        {
            std::list<CatalogItem> Items;

            GetItemsResponse() :
                PlayFabResultCommon(),
                Items()
            {}

            GetItemsResponse(const GetItemsResponse& src) :
                PlayFabResultCommon(),
                Items(src.Items)
            {}

            ~GetItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct GetMicrosoftStoreAccessTokensRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            GetMicrosoftStoreAccessTokensRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            GetMicrosoftStoreAccessTokensRequest(const GetMicrosoftStoreAccessTokensRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~GetMicrosoftStoreAccessTokensRequest() = default;

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

        struct GetMicrosoftStoreAccessTokensResponse : public PlayFabResultCommon
        {
            std::string CollectionsAccessToken;
            time_t CollectionsAccessTokenExpirationDate;

            GetMicrosoftStoreAccessTokensResponse() :
                PlayFabResultCommon(),
                CollectionsAccessToken(),
                CollectionsAccessTokenExpirationDate()
            {}

            GetMicrosoftStoreAccessTokensResponse(const GetMicrosoftStoreAccessTokensResponse& src) :
                PlayFabResultCommon(),
                CollectionsAccessToken(src.CollectionsAccessToken),
                CollectionsAccessTokenExpirationDate(src.CollectionsAccessTokenExpirationDate)
            {}

            ~GetMicrosoftStoreAccessTokensResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionsAccessToken"], CollectionsAccessToken);
                FromJsonUtilT(input["CollectionsAccessTokenExpirationDate"], CollectionsAccessTokenExpirationDate);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionsAccessToken; ToJsonUtilS(CollectionsAccessToken, each_CollectionsAccessToken); output["CollectionsAccessToken"] = each_CollectionsAccessToken;
                Json::Value each_CollectionsAccessTokenExpirationDate; ToJsonUtilT(CollectionsAccessTokenExpirationDate, each_CollectionsAccessTokenExpirationDate); output["CollectionsAccessTokenExpirationDate"] = each_CollectionsAccessTokenExpirationDate;
                return output;
            }
        };

        struct GooglePlayProductPurchase : public PlayFabBaseModel
        {
            std::string ProductId;
            std::string Token;

            GooglePlayProductPurchase() :
                PlayFabBaseModel(),
                ProductId(),
                Token()
            {}

            GooglePlayProductPurchase(const GooglePlayProductPurchase& src) :
                PlayFabBaseModel(),
                ProductId(src.ProductId),
                Token(src.Token)
            {}

            ~GooglePlayProductPurchase() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ProductId"], ProductId);
                FromJsonUtilS(input["Token"], Token);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ProductId; ToJsonUtilS(ProductId, each_ProductId); output["ProductId"] = each_ProductId;
                Json::Value each_Token; ToJsonUtilS(Token, each_Token); output["Token"] = each_Token;
                return output;
            }
        };

        struct PayoutDetails : public PlayFabBaseModel
        {

            PayoutDetails() :
                PlayFabBaseModel()
            {}

            PayoutDetails(const PayoutDetails&) :
                PlayFabBaseModel()
            {}

            ~PayoutDetails() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct PublishDraftItemRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string ETag;
            std::string Id;

            PublishDraftItemRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Entity(),
                ETag(),
                Id()
            {}

            PublishDraftItemRequest(const PublishDraftItemRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ETag(src.ETag),
                Id(src.Id)
            {}

            ~PublishDraftItemRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ETag"], ETag);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ETag; ToJsonUtilS(ETag, each_ETag); output["ETag"] = each_ETag;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct PublishDraftItemResponse : public PlayFabResultCommon
        {

            PublishDraftItemResponse() :
                PlayFabResultCommon()
            {}

            PublishDraftItemResponse(const PublishDraftItemResponse&) :
                PlayFabResultCommon()
            {}

            ~PublishDraftItemResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct PurchaseInventoryItemsRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            bool DeleteEmptyStacks;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            Boxed<InventoryItemReference> Item;
            std::list<PurchasePriceAmount> PriceAmounts;
            std::string StoreId;

            PurchaseInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Amount(),
                CollectionId(),
                CustomTags(),
                DeleteEmptyStacks(),
                Entity(),
                IdempotencyId(),
                Item(),
                PriceAmounts(),
                StoreId()
            {}

            PurchaseInventoryItemsRequest(const PurchaseInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                DeleteEmptyStacks(src.DeleteEmptyStacks),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Item(src.Item),
                PriceAmounts(src.PriceAmounts),
                StoreId(src.StoreId)
            {}

            ~PurchaseInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["DeleteEmptyStacks"], DeleteEmptyStacks);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Item"], Item);
                FromJsonUtilO(input["PriceAmounts"], PriceAmounts);
                FromJsonUtilS(input["StoreId"], StoreId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_DeleteEmptyStacks; ToJsonUtilP(DeleteEmptyStacks, each_DeleteEmptyStacks); output["DeleteEmptyStacks"] = each_DeleteEmptyStacks;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                Json::Value each_PriceAmounts; ToJsonUtilO(PriceAmounts, each_PriceAmounts); output["PriceAmounts"] = each_PriceAmounts;
                Json::Value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output["StoreId"] = each_StoreId;
                return output;
            }
        };

        struct PurchaseInventoryItemsResponse : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<std::string> TransactionIds;

            PurchaseInventoryItemsResponse() :
                PlayFabResultCommon(),
                IdempotencyId(),
                TransactionIds()
            {}

            PurchaseInventoryItemsResponse(const PurchaseInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                TransactionIds(src.TransactionIds)
            {}

            ~PurchaseInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct PurchaseOverride : public PlayFabBaseModel
        {

            PurchaseOverride() :
                PlayFabBaseModel()
            {}

            PurchaseOverride(const PurchaseOverride&) :
                PlayFabBaseModel()
            {}

            ~PurchaseOverride() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct RedeemAppleAppStoreInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Receipt;

            RedeemAppleAppStoreInventoryItemsRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                CustomTags(),
                Entity(),
                Receipt()
            {}

            RedeemAppleAppStoreInventoryItemsRequest(const RedeemAppleAppStoreInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Receipt(src.Receipt)
            {}

            ~RedeemAppleAppStoreInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Receipt"], Receipt);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Receipt; ToJsonUtilS(Receipt, each_Receipt); output["Receipt"] = each_Receipt;
                return output;
            }
        };

        struct RedemptionFailure : public PlayFabBaseModel
        {
            std::string FailureCode;
            std::string FailureDetails;
            std::string MarketplaceTransactionId;
            std::string OfferId;

            RedemptionFailure() :
                PlayFabBaseModel(),
                FailureCode(),
                FailureDetails(),
                MarketplaceTransactionId(),
                OfferId()
            {}

            RedemptionFailure(const RedemptionFailure& src) :
                PlayFabBaseModel(),
                FailureCode(src.FailureCode),
                FailureDetails(src.FailureDetails),
                MarketplaceTransactionId(src.MarketplaceTransactionId),
                OfferId(src.OfferId)
            {}

            ~RedemptionFailure() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["FailureCode"], FailureCode);
                FromJsonUtilS(input["FailureDetails"], FailureDetails);
                FromJsonUtilS(input["MarketplaceTransactionId"], MarketplaceTransactionId);
                FromJsonUtilS(input["OfferId"], OfferId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FailureCode; ToJsonUtilS(FailureCode, each_FailureCode); output["FailureCode"] = each_FailureCode;
                Json::Value each_FailureDetails; ToJsonUtilS(FailureDetails, each_FailureDetails); output["FailureDetails"] = each_FailureDetails;
                Json::Value each_MarketplaceTransactionId; ToJsonUtilS(MarketplaceTransactionId, each_MarketplaceTransactionId); output["MarketplaceTransactionId"] = each_MarketplaceTransactionId;
                Json::Value each_OfferId; ToJsonUtilS(OfferId, each_OfferId); output["OfferId"] = each_OfferId;
                return output;
            }
        };

        struct RedemptionSuccess : public PlayFabBaseModel
        {
            std::string MarketplaceTransactionId;
            std::string OfferId;
            time_t SuccessTimestamp;

            RedemptionSuccess() :
                PlayFabBaseModel(),
                MarketplaceTransactionId(),
                OfferId(),
                SuccessTimestamp()
            {}

            RedemptionSuccess(const RedemptionSuccess& src) :
                PlayFabBaseModel(),
                MarketplaceTransactionId(src.MarketplaceTransactionId),
                OfferId(src.OfferId),
                SuccessTimestamp(src.SuccessTimestamp)
            {}

            ~RedemptionSuccess() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["MarketplaceTransactionId"], MarketplaceTransactionId);
                FromJsonUtilS(input["OfferId"], OfferId);
                FromJsonUtilT(input["SuccessTimestamp"], SuccessTimestamp);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_MarketplaceTransactionId; ToJsonUtilS(MarketplaceTransactionId, each_MarketplaceTransactionId); output["MarketplaceTransactionId"] = each_MarketplaceTransactionId;
                Json::Value each_OfferId; ToJsonUtilS(OfferId, each_OfferId); output["OfferId"] = each_OfferId;
                Json::Value each_SuccessTimestamp; ToJsonUtilT(SuccessTimestamp, each_SuccessTimestamp); output["SuccessTimestamp"] = each_SuccessTimestamp;
                return output;
            }
        };

        struct RedeemAppleAppStoreInventoryItemsResponse : public PlayFabResultCommon
        {
            std::list<RedemptionFailure> Failed;
            std::list<RedemptionSuccess> Succeeded;
            std::list<std::string> TransactionIds;

            RedeemAppleAppStoreInventoryItemsResponse() :
                PlayFabResultCommon(),
                Failed(),
                Succeeded(),
                TransactionIds()
            {}

            RedeemAppleAppStoreInventoryItemsResponse(const RedeemAppleAppStoreInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                Failed(src.Failed),
                Succeeded(src.Succeeded),
                TransactionIds(src.TransactionIds)
            {}

            ~RedeemAppleAppStoreInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Failed"], Failed);
                FromJsonUtilO(input["Succeeded"], Succeeded);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Failed; ToJsonUtilO(Failed, each_Failed); output["Failed"] = each_Failed;
                Json::Value each_Succeeded; ToJsonUtilO(Succeeded, each_Succeeded); output["Succeeded"] = each_Succeeded;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct RedeemGooglePlayInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::list<GooglePlayProductPurchase> Purchases;

            RedeemGooglePlayInventoryItemsRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                CustomTags(),
                Entity(),
                Purchases()
            {}

            RedeemGooglePlayInventoryItemsRequest(const RedeemGooglePlayInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Purchases(src.Purchases)
            {}

            ~RedeemGooglePlayInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilO(input["Purchases"], Purchases);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Purchases; ToJsonUtilO(Purchases, each_Purchases); output["Purchases"] = each_Purchases;
                return output;
            }
        };

        struct RedeemGooglePlayInventoryItemsResponse : public PlayFabResultCommon
        {
            std::list<RedemptionFailure> Failed;
            std::list<RedemptionSuccess> Succeeded;
            std::list<std::string> TransactionIds;

            RedeemGooglePlayInventoryItemsResponse() :
                PlayFabResultCommon(),
                Failed(),
                Succeeded(),
                TransactionIds()
            {}

            RedeemGooglePlayInventoryItemsResponse(const RedeemGooglePlayInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                Failed(src.Failed),
                Succeeded(src.Succeeded),
                TransactionIds(src.TransactionIds)
            {}

            ~RedeemGooglePlayInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Failed"], Failed);
                FromJsonUtilO(input["Succeeded"], Succeeded);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Failed; ToJsonUtilO(Failed, each_Failed); output["Failed"] = each_Failed;
                Json::Value each_Succeeded; ToJsonUtilO(Succeeded, each_Succeeded); output["Succeeded"] = each_Succeeded;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct RedeemMicrosoftStoreInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::string CollectionsIdKey;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string XboxToken;

            RedeemMicrosoftStoreInventoryItemsRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                CollectionsIdKey(),
                CustomTags(),
                Entity(),
                XboxToken()
            {}

            RedeemMicrosoftStoreInventoryItemsRequest(const RedeemMicrosoftStoreInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                CollectionsIdKey(src.CollectionsIdKey),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                XboxToken(src.XboxToken)
            {}

            ~RedeemMicrosoftStoreInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CollectionsIdKey"], CollectionsIdKey);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["XboxToken"], XboxToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CollectionsIdKey; ToJsonUtilS(CollectionsIdKey, each_CollectionsIdKey); output["CollectionsIdKey"] = each_CollectionsIdKey;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_XboxToken; ToJsonUtilS(XboxToken, each_XboxToken); output["XboxToken"] = each_XboxToken;
                return output;
            }
        };

        struct RedeemMicrosoftStoreInventoryItemsResponse : public PlayFabResultCommon
        {
            std::list<RedemptionFailure> Failed;
            std::list<RedemptionSuccess> Succeeded;
            std::list<std::string> TransactionIds;

            RedeemMicrosoftStoreInventoryItemsResponse() :
                PlayFabResultCommon(),
                Failed(),
                Succeeded(),
                TransactionIds()
            {}

            RedeemMicrosoftStoreInventoryItemsResponse(const RedeemMicrosoftStoreInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                Failed(src.Failed),
                Succeeded(src.Succeeded),
                TransactionIds(src.TransactionIds)
            {}

            ~RedeemMicrosoftStoreInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Failed"], Failed);
                FromJsonUtilO(input["Succeeded"], Succeeded);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Failed; ToJsonUtilO(Failed, each_Failed); output["Failed"] = each_Failed;
                Json::Value each_Succeeded; ToJsonUtilO(Succeeded, each_Succeeded); output["Succeeded"] = each_Succeeded;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct RedeemNintendoEShopInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string NintendoServiceAccountIdToken;

            RedeemNintendoEShopInventoryItemsRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                CustomTags(),
                Entity(),
                NintendoServiceAccountIdToken()
            {}

            RedeemNintendoEShopInventoryItemsRequest(const RedeemNintendoEShopInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                NintendoServiceAccountIdToken(src.NintendoServiceAccountIdToken)
            {}

            ~RedeemNintendoEShopInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["NintendoServiceAccountIdToken"], NintendoServiceAccountIdToken);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_NintendoServiceAccountIdToken; ToJsonUtilS(NintendoServiceAccountIdToken, each_NintendoServiceAccountIdToken); output["NintendoServiceAccountIdToken"] = each_NintendoServiceAccountIdToken;
                return output;
            }
        };

        struct RedeemNintendoEShopInventoryItemsResponse : public PlayFabResultCommon
        {
            std::list<RedemptionFailure> Failed;
            std::list<RedemptionSuccess> Succeeded;
            std::list<std::string> TransactionIds;

            RedeemNintendoEShopInventoryItemsResponse() :
                PlayFabResultCommon(),
                Failed(),
                Succeeded(),
                TransactionIds()
            {}

            RedeemNintendoEShopInventoryItemsResponse(const RedeemNintendoEShopInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                Failed(src.Failed),
                Succeeded(src.Succeeded),
                TransactionIds(src.TransactionIds)
            {}

            ~RedeemNintendoEShopInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Failed"], Failed);
                FromJsonUtilO(input["Succeeded"], Succeeded);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Failed; ToJsonUtilO(Failed, each_Failed); output["Failed"] = each_Failed;
                Json::Value each_Succeeded; ToJsonUtilO(Succeeded, each_Succeeded); output["Succeeded"] = each_Succeeded;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct RedeemPlayStationStoreInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::string AuthorizationCode;
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string ServiceLabel;

            RedeemPlayStationStoreInventoryItemsRequest() :
                PlayFabRequestCommon(),
                AuthorizationCode(),
                CollectionId(),
                CustomTags(),
                Entity(),
                ServiceLabel()
            {}

            RedeemPlayStationStoreInventoryItemsRequest(const RedeemPlayStationStoreInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                AuthorizationCode(src.AuthorizationCode),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ServiceLabel(src.ServiceLabel)
            {}

            ~RedeemPlayStationStoreInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AuthorizationCode"], AuthorizationCode);
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ServiceLabel"], ServiceLabel);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AuthorizationCode; ToJsonUtilS(AuthorizationCode, each_AuthorizationCode); output["AuthorizationCode"] = each_AuthorizationCode;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ServiceLabel; ToJsonUtilS(ServiceLabel, each_ServiceLabel); output["ServiceLabel"] = each_ServiceLabel;
                return output;
            }
        };

        struct RedeemPlayStationStoreInventoryItemsResponse : public PlayFabResultCommon
        {
            std::list<RedemptionFailure> Failed;
            std::list<RedemptionSuccess> Succeeded;
            std::list<std::string> TransactionIds;

            RedeemPlayStationStoreInventoryItemsResponse() :
                PlayFabResultCommon(),
                Failed(),
                Succeeded(),
                TransactionIds()
            {}

            RedeemPlayStationStoreInventoryItemsResponse(const RedeemPlayStationStoreInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                Failed(src.Failed),
                Succeeded(src.Succeeded),
                TransactionIds(src.TransactionIds)
            {}

            ~RedeemPlayStationStoreInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Failed"], Failed);
                FromJsonUtilO(input["Succeeded"], Succeeded);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Failed; ToJsonUtilO(Failed, each_Failed); output["Failed"] = each_Failed;
                Json::Value each_Succeeded; ToJsonUtilO(Succeeded, each_Succeeded); output["Succeeded"] = each_Succeeded;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct RedeemSteamInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;

            RedeemSteamInventoryItemsRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                CustomTags(),
                Entity()
            {}

            RedeemSteamInventoryItemsRequest(const RedeemSteamInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~RedeemSteamInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct RedeemSteamInventoryItemsResponse : public PlayFabResultCommon
        {
            std::list<RedemptionFailure> Failed;
            std::list<RedemptionSuccess> Succeeded;
            std::list<std::string> TransactionIds;

            RedeemSteamInventoryItemsResponse() :
                PlayFabResultCommon(),
                Failed(),
                Succeeded(),
                TransactionIds()
            {}

            RedeemSteamInventoryItemsResponse(const RedeemSteamInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                Failed(src.Failed),
                Succeeded(src.Succeeded),
                TransactionIds(src.TransactionIds)
            {}

            ~RedeemSteamInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Failed"], Failed);
                FromJsonUtilO(input["Succeeded"], Succeeded);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Failed; ToJsonUtilO(Failed, each_Failed); output["Failed"] = each_Failed;
                Json::Value each_Succeeded; ToJsonUtilO(Succeeded, each_Succeeded); output["Succeeded"] = each_Succeeded;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct ReportItemRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            Boxed<ConcernCategory> pfConcernCategory;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Id;
            std::string Reason;

            ReportItemRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                pfConcernCategory(),
                CustomTags(),
                Entity(),
                Id(),
                Reason()
            {}

            ReportItemRequest(const ReportItemRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                pfConcernCategory(src.pfConcernCategory),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Id(src.Id),
                Reason(src.Reason)
            {}

            ~ReportItemRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilE(input["ConcernCategory"], pfConcernCategory);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Reason"], Reason);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_pfConcernCategory; ToJsonUtilE(pfConcernCategory, each_pfConcernCategory); output["ConcernCategory"] = each_pfConcernCategory;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
                return output;
            }
        };

        struct ReportItemResponse : public PlayFabResultCommon
        {

            ReportItemResponse() :
                PlayFabResultCommon()
            {}

            ReportItemResponse(const ReportItemResponse&) :
                PlayFabResultCommon()
            {}

            ~ReportItemResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct ReportItemReviewRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            Boxed<ConcernCategory> pfConcernCategory;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string ItemId;
            std::string Reason;
            std::string ReviewId;

            ReportItemReviewRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                pfConcernCategory(),
                CustomTags(),
                Entity(),
                ItemId(),
                Reason(),
                ReviewId()
            {}

            ReportItemReviewRequest(const ReportItemReviewRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                pfConcernCategory(src.pfConcernCategory),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ItemId(src.ItemId),
                Reason(src.Reason),
                ReviewId(src.ReviewId)
            {}

            ~ReportItemReviewRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilE(input["ConcernCategory"], pfConcernCategory);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["Reason"], Reason);
                FromJsonUtilS(input["ReviewId"], ReviewId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_pfConcernCategory; ToJsonUtilE(pfConcernCategory, each_pfConcernCategory); output["ConcernCategory"] = each_pfConcernCategory;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
                Json::Value each_ReviewId; ToJsonUtilS(ReviewId, each_ReviewId); output["ReviewId"] = each_ReviewId;
                return output;
            }
        };

        struct ReportItemReviewResponse : public PlayFabResultCommon
        {

            ReportItemReviewResponse() :
                PlayFabResultCommon()
            {}

            ReportItemReviewResponse(const ReportItemReviewResponse&) :
                PlayFabResultCommon()
            {}

            ~ReportItemReviewResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct ReviewItemRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Id;
            Boxed<Review> pfReview;

            ReviewItemRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Entity(),
                Id(),
                pfReview()
            {}

            ReviewItemRequest(const ReviewItemRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Id(src.Id),
                pfReview(src.pfReview)
            {}

            ~ReviewItemRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["Review"], pfReview);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_pfReview; ToJsonUtilO(pfReview, each_pfReview); output["Review"] = each_pfReview;
                return output;
            }
        };

        struct ReviewItemResponse : public PlayFabResultCommon
        {

            ReviewItemResponse() :
                PlayFabResultCommon()
            {}

            ReviewItemResponse(const ReviewItemResponse&) :
                PlayFabResultCommon()
            {}

            ~ReviewItemResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct ReviewTakedown : public PlayFabBaseModel
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::string ItemId;
            std::string ReviewId;

            ReviewTakedown() :
                PlayFabBaseModel(),
                AlternateId(),
                ItemId(),
                ReviewId()
            {}

            ReviewTakedown(const ReviewTakedown& src) :
                PlayFabBaseModel(),
                AlternateId(src.AlternateId),
                ItemId(src.ItemId),
                ReviewId(src.ReviewId)
            {}

            ~ReviewTakedown() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ReviewId"], ReviewId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ReviewId; ToJsonUtilS(ReviewId, each_ReviewId); output["ReviewId"] = each_ReviewId;
                return output;
            }
        };

        struct ScanResult : public PlayFabResultCommon
        {
            std::string Url;

            ScanResult() :
                PlayFabResultCommon(),
                Url()
            {}

            ScanResult(const ScanResult& src) :
                PlayFabResultCommon(),
                Url(src.Url)
            {}

            ~ScanResult() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Url"], Url);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Url; ToJsonUtilS(Url, each_Url); output["Url"] = each_Url;
                return output;
            }
        };

        struct StoreReference : public PlayFabBaseModel
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::string Id;

            StoreReference() :
                PlayFabBaseModel(),
                AlternateId(),
                Id()
            {}

            StoreReference(const StoreReference& src) :
                PlayFabBaseModel(),
                AlternateId(src.AlternateId),
                Id(src.Id)
            {}

            ~StoreReference() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct SearchItemsRequest : public PlayFabRequestCommon
        {
            std::string ContinuationToken;
            Int32 Count;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string Filter;
            std::string OrderBy;
            std::string Search;
            std::string Select;
            Boxed<StoreReference> Store;

            SearchItemsRequest() :
                PlayFabRequestCommon(),
                ContinuationToken(),
                Count(),
                CustomTags(),
                Entity(),
                Filter(),
                OrderBy(),
                Search(),
                Select(),
                Store()
            {}

            SearchItemsRequest(const SearchItemsRequest& src) :
                PlayFabRequestCommon(),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                Filter(src.Filter),
                OrderBy(src.OrderBy),
                Search(src.Search),
                Select(src.Select),
                Store(src.Store)
            {}

            ~SearchItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilP(input["Count"], Count);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["Filter"], Filter);
                FromJsonUtilS(input["OrderBy"], OrderBy);
                FromJsonUtilS(input["Search"], Search);
                FromJsonUtilS(input["Select"], Select);
                FromJsonUtilO(input["Store"], Store);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Count; ToJsonUtilP(Count, each_Count); output["Count"] = each_Count;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_Filter; ToJsonUtilS(Filter, each_Filter); output["Filter"] = each_Filter;
                Json::Value each_OrderBy; ToJsonUtilS(OrderBy, each_OrderBy); output["OrderBy"] = each_OrderBy;
                Json::Value each_Search; ToJsonUtilS(Search, each_Search); output["Search"] = each_Search;
                Json::Value each_Select; ToJsonUtilS(Select, each_Select); output["Select"] = each_Select;
                Json::Value each_Store; ToJsonUtilO(Store, each_Store); output["Store"] = each_Store;
                return output;
            }
        };

        struct SearchItemsResponse : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            std::list<CatalogItem> Items;

            SearchItemsResponse() :
                PlayFabResultCommon(),
                ContinuationToken(),
                Items()
            {}

            SearchItemsResponse(const SearchItemsResponse& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                Items(src.Items)
            {}

            ~SearchItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ContinuationToken"], ContinuationToken);
                FromJsonUtilO(input["Items"], Items);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output["ContinuationToken"] = each_ContinuationToken;
                Json::Value each_Items; ToJsonUtilO(Items, each_Items); output["Items"] = each_Items;
                return output;
            }
        };

        struct SetItemModerationStateRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            std::string Id;
            std::string Reason;
            Boxed<ModerationStatus> Status;

            SetItemModerationStateRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Id(),
                Reason(),
                Status()
            {}

            SetItemModerationStateRequest(const SetItemModerationStateRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Id(src.Id),
                Reason(src.Reason),
                Status(src.Status)
            {}

            ~SetItemModerationStateRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Reason"], Reason);
                FromJsonUtilE(input["Status"], Status);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Reason; ToJsonUtilS(Reason, each_Reason); output["Reason"] = each_Reason;
                Json::Value each_Status; ToJsonUtilE(Status, each_Status); output["Status"] = each_Status;
                return output;
            }
        };

        struct SetItemModerationStateResponse : public PlayFabResultCommon
        {

            SetItemModerationStateResponse() :
                PlayFabResultCommon()
            {}

            SetItemModerationStateResponse(const SetItemModerationStateResponse&) :
                PlayFabResultCommon()
            {}

            ~SetItemModerationStateResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct SubmitItemReviewVoteRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string ItemId;
            std::string ReviewId;
            Boxed<HelpfulnessVote> Vote;

            SubmitItemReviewVoteRequest() :
                PlayFabRequestCommon(),
                AlternateId(),
                CustomTags(),
                Entity(),
                ItemId(),
                ReviewId(),
                Vote()
            {}

            SubmitItemReviewVoteRequest(const SubmitItemReviewVoteRequest& src) :
                PlayFabRequestCommon(),
                AlternateId(src.AlternateId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ItemId(src.ItemId),
                ReviewId(src.ReviewId),
                Vote(src.Vote)
            {}

            ~SubmitItemReviewVoteRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AlternateId"], AlternateId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["ItemId"], ItemId);
                FromJsonUtilS(input["ReviewId"], ReviewId);
                FromJsonUtilE(input["Vote"], Vote);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AlternateId; ToJsonUtilO(AlternateId, each_AlternateId); output["AlternateId"] = each_AlternateId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output["ItemId"] = each_ItemId;
                Json::Value each_ReviewId; ToJsonUtilS(ReviewId, each_ReviewId); output["ReviewId"] = each_ReviewId;
                Json::Value each_Vote; ToJsonUtilE(Vote, each_Vote); output["Vote"] = each_Vote;
                return output;
            }
        };

        struct SubmitItemReviewVoteResponse : public PlayFabResultCommon
        {

            SubmitItemReviewVoteResponse() :
                PlayFabResultCommon()
            {}

            SubmitItemReviewVoteResponse(const SubmitItemReviewVoteResponse&) :
                PlayFabResultCommon()
            {}

            ~SubmitItemReviewVoteResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct SubscriptionDetails : public PlayFabBaseModel
        {
            double DurationInSeconds;

            SubscriptionDetails() :
                PlayFabBaseModel(),
                DurationInSeconds()
            {}

            SubscriptionDetails(const SubscriptionDetails& src) :
                PlayFabBaseModel(),
                DurationInSeconds(src.DurationInSeconds)
            {}

            ~SubscriptionDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["DurationInSeconds"], DurationInSeconds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DurationInSeconds; ToJsonUtilP(DurationInSeconds, each_DurationInSeconds); output["DurationInSeconds"] = each_DurationInSeconds;
                return output;
            }
        };

        struct SubtractInventoryItemsRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            bool DeleteEmptyStacks;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            Boxed<InventoryItemReference> Item;

            SubtractInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Amount(),
                CollectionId(),
                CustomTags(),
                DeleteEmptyStacks(),
                Entity(),
                IdempotencyId(),
                Item()
            {}

            SubtractInventoryItemsRequest(const SubtractInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                DeleteEmptyStacks(src.DeleteEmptyStacks),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Item(src.Item)
            {}

            ~SubtractInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["DeleteEmptyStacks"], DeleteEmptyStacks);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_DeleteEmptyStacks; ToJsonUtilP(DeleteEmptyStacks, each_DeleteEmptyStacks); output["DeleteEmptyStacks"] = each_DeleteEmptyStacks;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct SubtractInventoryItemsResponse : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<std::string> TransactionIds;

            SubtractInventoryItemsResponse() :
                PlayFabResultCommon(),
                IdempotencyId(),
                TransactionIds()
            {}

            SubtractInventoryItemsResponse(const SubtractInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                TransactionIds(src.TransactionIds)
            {}

            ~SubtractInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

        struct TakedownItemReviewsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::list<ReviewTakedown> Reviews;

            TakedownItemReviewsRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Reviews()
            {}

            TakedownItemReviewsRequest(const TakedownItemReviewsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Reviews(src.Reviews)
            {}

            ~TakedownItemReviewsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Reviews"], Reviews);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Reviews; ToJsonUtilO(Reviews, each_Reviews); output["Reviews"] = each_Reviews;
                return output;
            }
        };

        struct TakedownItemReviewsResponse : public PlayFabResultCommon
        {

            TakedownItemReviewsResponse() :
                PlayFabResultCommon()
            {}

            TakedownItemReviewsResponse(const TakedownItemReviewsResponse&) :
                PlayFabResultCommon()
            {}

            ~TakedownItemReviewsResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct TransferInventoryItemsRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::map<std::string, std::string> CustomTags;
            bool DeleteEmptyStacks;
            std::string GivingCollectionId;
            Boxed<EntityKey> GivingEntity;
            Boxed<InventoryItemReference> GivingItem;
            std::string IdempotencyId;
            std::string ReceivingCollectionId;
            Boxed<EntityKey> ReceivingEntity;
            Boxed<InventoryItemReference> ReceivingItem;

            TransferInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Amount(),
                CustomTags(),
                DeleteEmptyStacks(),
                GivingCollectionId(),
                GivingEntity(),
                GivingItem(),
                IdempotencyId(),
                ReceivingCollectionId(),
                ReceivingEntity(),
                ReceivingItem()
            {}

            TransferInventoryItemsRequest(const TransferInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                CustomTags(src.CustomTags),
                DeleteEmptyStacks(src.DeleteEmptyStacks),
                GivingCollectionId(src.GivingCollectionId),
                GivingEntity(src.GivingEntity),
                GivingItem(src.GivingItem),
                IdempotencyId(src.IdempotencyId),
                ReceivingCollectionId(src.ReceivingCollectionId),
                ReceivingEntity(src.ReceivingEntity),
                ReceivingItem(src.ReceivingItem)
            {}

            ~TransferInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["DeleteEmptyStacks"], DeleteEmptyStacks);
                FromJsonUtilS(input["GivingCollectionId"], GivingCollectionId);
                FromJsonUtilO(input["GivingEntity"], GivingEntity);
                FromJsonUtilO(input["GivingItem"], GivingItem);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["ReceivingCollectionId"], ReceivingCollectionId);
                FromJsonUtilO(input["ReceivingEntity"], ReceivingEntity);
                FromJsonUtilO(input["ReceivingItem"], ReceivingItem);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_DeleteEmptyStacks; ToJsonUtilP(DeleteEmptyStacks, each_DeleteEmptyStacks); output["DeleteEmptyStacks"] = each_DeleteEmptyStacks;
                Json::Value each_GivingCollectionId; ToJsonUtilS(GivingCollectionId, each_GivingCollectionId); output["GivingCollectionId"] = each_GivingCollectionId;
                Json::Value each_GivingEntity; ToJsonUtilO(GivingEntity, each_GivingEntity); output["GivingEntity"] = each_GivingEntity;
                Json::Value each_GivingItem; ToJsonUtilO(GivingItem, each_GivingItem); output["GivingItem"] = each_GivingItem;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_ReceivingCollectionId; ToJsonUtilS(ReceivingCollectionId, each_ReceivingCollectionId); output["ReceivingCollectionId"] = each_ReceivingCollectionId;
                Json::Value each_ReceivingEntity; ToJsonUtilO(ReceivingEntity, each_ReceivingEntity); output["ReceivingEntity"] = each_ReceivingEntity;
                Json::Value each_ReceivingItem; ToJsonUtilO(ReceivingItem, each_ReceivingItem); output["ReceivingItem"] = each_ReceivingItem;
                return output;
            }
        };

        struct TransferInventoryItemsResponse : public PlayFabResultCommon
        {
            std::list<std::string> GivingTransactionIds;
            std::string IdempotencyId;
            std::list<std::string> ReceivingTransactionIds;

            TransferInventoryItemsResponse() :
                PlayFabResultCommon(),
                GivingTransactionIds(),
                IdempotencyId(),
                ReceivingTransactionIds()
            {}

            TransferInventoryItemsResponse(const TransferInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                GivingTransactionIds(src.GivingTransactionIds),
                IdempotencyId(src.IdempotencyId),
                ReceivingTransactionIds(src.ReceivingTransactionIds)
            {}

            ~TransferInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["GivingTransactionIds"], GivingTransactionIds);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["ReceivingTransactionIds"], ReceivingTransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_GivingTransactionIds; ToJsonUtilS(GivingTransactionIds, each_GivingTransactionIds); output["GivingTransactionIds"] = each_GivingTransactionIds;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_ReceivingTransactionIds; ToJsonUtilS(ReceivingTransactionIds, each_ReceivingTransactionIds); output["ReceivingTransactionIds"] = each_ReceivingTransactionIds;
                return output;
            }
        };

        struct UpdateCatalogConfigRequest : public PlayFabRequestCommon
        {
            Boxed<CatalogConfig> Config;
            std::map<std::string, std::string> CustomTags;

            UpdateCatalogConfigRequest() :
                PlayFabRequestCommon(),
                Config(),
                CustomTags()
            {}

            UpdateCatalogConfigRequest(const UpdateCatalogConfigRequest& src) :
                PlayFabRequestCommon(),
                Config(src.Config),
                CustomTags(src.CustomTags)
            {}

            ~UpdateCatalogConfigRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Config"], Config);
                FromJsonUtilS(input["CustomTags"], CustomTags);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Config; ToJsonUtilO(Config, each_Config); output["Config"] = each_Config;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                return output;
            }
        };

        struct UpdateCatalogConfigResponse : public PlayFabResultCommon
        {

            UpdateCatalogConfigResponse() :
                PlayFabResultCommon()
            {}

            UpdateCatalogConfigResponse(const UpdateCatalogConfigResponse&) :
                PlayFabResultCommon()
            {}

            ~UpdateCatalogConfigResponse() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct UpdateDraftItemRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            Boxed<CatalogItem> Item;
            bool Publish;

            UpdateDraftItemRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Item(),
                Publish()
            {}

            UpdateDraftItemRequest(const UpdateDraftItemRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Item(src.Item),
                Publish(src.Publish)
            {}

            ~UpdateDraftItemRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Item"], Item);
                FromJsonUtilP(input["Publish"], Publish);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                Json::Value each_Publish; ToJsonUtilP(Publish, each_Publish); output["Publish"] = each_Publish;
                return output;
            }
        };

        struct UpdateDraftItemResponse : public PlayFabResultCommon
        {
            Boxed<CatalogItem> Item;

            UpdateDraftItemResponse() :
                PlayFabResultCommon(),
                Item()
            {}

            UpdateDraftItemResponse(const UpdateDraftItemResponse& src) :
                PlayFabResultCommon(),
                Item(src.Item)
            {}

            ~UpdateDraftItemResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct UpdateInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::string CollectionId;
            std::map<std::string, std::string> CustomTags;
            Boxed<EntityKey> Entity;
            std::string IdempotencyId;
            Boxed<InventoryItem> Item;

            UpdateInventoryItemsRequest() :
                PlayFabRequestCommon(),
                CollectionId(),
                CustomTags(),
                Entity(),
                IdempotencyId(),
                Item()
            {}

            UpdateInventoryItemsRequest(const UpdateInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                CollectionId(src.CollectionId),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                IdempotencyId(src.IdempotencyId),
                Item(src.Item)
            {}

            ~UpdateInventoryItemsRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["CollectionId"], CollectionId);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilO(input["Item"], Item);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_CollectionId; ToJsonUtilS(CollectionId, each_CollectionId); output["CollectionId"] = each_CollectionId;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_Item; ToJsonUtilO(Item, each_Item); output["Item"] = each_Item;
                return output;
            }
        };

        struct UpdateInventoryItemsResponse : public PlayFabResultCommon
        {
            std::string IdempotencyId;
            std::list<std::string> TransactionIds;

            UpdateInventoryItemsResponse() :
                PlayFabResultCommon(),
                IdempotencyId(),
                TransactionIds()
            {}

            UpdateInventoryItemsResponse(const UpdateInventoryItemsResponse& src) :
                PlayFabResultCommon(),
                IdempotencyId(src.IdempotencyId),
                TransactionIds(src.TransactionIds)
            {}

            ~UpdateInventoryItemsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["IdempotencyId"], IdempotencyId);
                FromJsonUtilS(input["TransactionIds"], TransactionIds);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_IdempotencyId; ToJsonUtilS(IdempotencyId, each_IdempotencyId); output["IdempotencyId"] = each_IdempotencyId;
                Json::Value each_TransactionIds; ToJsonUtilS(TransactionIds, each_TransactionIds); output["TransactionIds"] = each_TransactionIds;
                return output;
            }
        };

    }
}

#endif
