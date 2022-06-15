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

        struct CatalogItem : public PlayFabBaseModel
        {
            std::list<CatalogAlternateId> AlternateIds;
            std::list<Content> Contents;
            std::string ContentType;
            Boxed<time_t> CreationDate;
            Boxed<EntityKey> CreatorEntity;
            std::map<std::string, std::string> Description;
            Json::Value DisplayProperties;
            std::string DisplayVersion;
            Boxed<time_t> EndDate;
            std::string ETag;
            std::string Id;
            std::list<Image> Images;
            Boxed<bool> IsHidden;
            std::map<std::string, KeywordSet> Keywords;
            Boxed<time_t> LastModifiedDate;
            Boxed<ModerationState> Moderation;
            Boxed<Rating> pfRating;
            Boxed<time_t> StartDate;
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
                Description(),
                DisplayProperties(),
                DisplayVersion(),
                EndDate(),
                ETag(),
                Id(),
                Images(),
                IsHidden(),
                Keywords(),
                LastModifiedDate(),
                Moderation(),
                pfRating(),
                StartDate(),
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
                Description(src.Description),
                DisplayProperties(src.DisplayProperties),
                DisplayVersion(src.DisplayVersion),
                EndDate(src.EndDate),
                ETag(src.ETag),
                Id(src.Id),
                Images(src.Images),
                IsHidden(src.IsHidden),
                Keywords(src.Keywords),
                LastModifiedDate(src.LastModifiedDate),
                Moderation(src.Moderation),
                pfRating(src.pfRating),
                StartDate(src.StartDate),
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
                FromJsonUtilS(input["Description"], Description);
                DisplayProperties = input["DisplayProperties"];
                FromJsonUtilS(input["DisplayVersion"], DisplayVersion);
                FromJsonUtilT(input["EndDate"], EndDate);
                FromJsonUtilS(input["ETag"], ETag);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["Images"], Images);
                FromJsonUtilP(input["IsHidden"], IsHidden);
                FromJsonUtilO(input["Keywords"], Keywords);
                FromJsonUtilT(input["LastModifiedDate"], LastModifiedDate);
                FromJsonUtilO(input["Moderation"], Moderation);
                FromJsonUtilO(input["Rating"], pfRating);
                FromJsonUtilT(input["StartDate"], StartDate);
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
                Json::Value each_Description; ToJsonUtilS(Description, each_Description); output["Description"] = each_Description;
                output["DisplayProperties"] = DisplayProperties;
                Json::Value each_DisplayVersion; ToJsonUtilS(DisplayVersion, each_DisplayVersion); output["DisplayVersion"] = each_DisplayVersion;
                Json::Value each_EndDate; ToJsonUtilT(EndDate, each_EndDate); output["EndDate"] = each_EndDate;
                Json::Value each_ETag; ToJsonUtilS(ETag, each_ETag); output["ETag"] = each_ETag;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Images; ToJsonUtilO(Images, each_Images); output["Images"] = each_Images;
                Json::Value each_IsHidden; ToJsonUtilP(IsHidden, each_IsHidden); output["IsHidden"] = each_IsHidden;
                Json::Value each_Keywords; ToJsonUtilO(Keywords, each_Keywords); output["Keywords"] = each_Keywords;
                Json::Value each_LastModifiedDate; ToJsonUtilT(LastModifiedDate, each_LastModifiedDate); output["LastModifiedDate"] = each_LastModifiedDate;
                Json::Value each_Moderation; ToJsonUtilO(Moderation, each_Moderation); output["Moderation"] = each_Moderation;
                Json::Value each_pfRating; ToJsonUtilO(pfRating, each_pfRating); output["Rating"] = each_pfRating;
                Json::Value each_StartDate; ToJsonUtilT(StartDate, each_StartDate); output["StartDate"] = each_StartDate;
                Json::Value each_Tags; ToJsonUtilS(Tags, each_Tags); output["Tags"] = each_Tags;
                Json::Value each_Title; ToJsonUtilS(Title, each_Title); output["Title"] = each_Title;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct CatalogPriceAmount : public PlayFabBaseModel
        {
            Int32 Amount;
            std::string Id;

            CatalogPriceAmount() :
                PlayFabBaseModel(),
                Amount(),
                Id()
            {}

            CatalogPriceAmount(const CatalogPriceAmount& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                Id(src.Id)
            {}

            ~CatalogPriceAmount() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["Id"], Id);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                return output;
            }
        };

        struct CatalogPriceInstance : public PlayFabBaseModel
        {
            std::list<CatalogPriceAmount> Amounts;

            CatalogPriceInstance() :
                PlayFabBaseModel(),
                Amounts()
            {}

            CatalogPriceInstance(const CatalogPriceInstance& src) :
                PlayFabBaseModel(),
                Amounts(src.Amounts)
            {}

            ~CatalogPriceInstance() = default;

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

        struct CatalogPrice : public PlayFabBaseModel
        {
            std::list<CatalogPriceInstance> Prices;
            std::list<CatalogPriceInstance> RealPrices;
            Boxed<Int32> Sort;

            CatalogPrice() :
                PlayFabBaseModel(),
                Prices(),
                RealPrices(),
                Sort()
            {}

            CatalogPrice(const CatalogPrice& src) :
                PlayFabBaseModel(),
                Prices(src.Prices),
                RealPrices(src.RealPrices),
                Sort(src.Sort)
            {}

            ~CatalogPrice() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["Prices"], Prices);
                FromJsonUtilO(input["RealPrices"], RealPrices);
                FromJsonUtilP(input["Sort"], Sort);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Prices; ToJsonUtilO(Prices, each_Prices); output["Prices"] = each_Prices;
                Json::Value each_RealPrices; ToJsonUtilO(RealPrices, each_RealPrices); output["RealPrices"] = each_RealPrices;
                Json::Value each_Sort; ToJsonUtilP(Sort, each_Sort); output["Sort"] = each_Sort;
                return output;
            }
        };

        struct CatalogItemReference : public PlayFabBaseModel
        {
            Boxed<Int32> Amount;
            std::string Id;
            Boxed<CatalogPrice> Price;

            CatalogItemReference() :
                PlayFabBaseModel(),
                Amount(),
                Id(),
                Price()
            {}

            CatalogItemReference(const CatalogItemReference& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                Id(src.Id),
                Price(src.Price)
            {}

            ~CatalogItemReference() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Amount"], Amount);
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilO(input["Price"], Price);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Amount; ToJsonUtilP(Amount, each_Amount); output["Amount"] = each_Amount;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Price; ToJsonUtilO(Price, each_Price); output["Price"] = each_Price;
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

        struct FilterOptions : public PlayFabBaseModel
        {

            FilterOptions() :
                PlayFabBaseModel()
            {}

            FilterOptions(const FilterOptions&) :
                PlayFabBaseModel()
            {}

            ~FilterOptions() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
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

            GetEntityDraftItemsRequest() :
                PlayFabRequestCommon(),
                ContinuationToken(),
                Count(),
                CustomTags(),
                Entity()
            {}

            GetEntityDraftItemsRequest(const GetEntityDraftItemsRequest& src) :
                PlayFabRequestCommon(),
                ContinuationToken(src.ContinuationToken),
                Count(src.Count),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            ~GetEntityDraftItemsRequest() = default;

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

        struct PayoutDetails : public PlayFabBaseModel
        {
            std::string AccountSellerId;
            std::string TaxCode;
            std::string Uaid;

            PayoutDetails() :
                PlayFabBaseModel(),
                AccountSellerId(),
                TaxCode(),
                Uaid()
            {}

            PayoutDetails(const PayoutDetails& src) :
                PlayFabBaseModel(),
                AccountSellerId(src.AccountSellerId),
                TaxCode(src.TaxCode),
                Uaid(src.Uaid)
            {}

            ~PayoutDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AccountSellerId"], AccountSellerId);
                FromJsonUtilS(input["TaxCode"], TaxCode);
                FromJsonUtilS(input["Uaid"], Uaid);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccountSellerId; ToJsonUtilS(AccountSellerId, each_AccountSellerId); output["AccountSellerId"] = each_AccountSellerId;
                Json::Value each_TaxCode; ToJsonUtilS(TaxCode, each_TaxCode); output["TaxCode"] = each_TaxCode;
                Json::Value each_Uaid; ToJsonUtilS(Uaid, each_Uaid); output["Uaid"] = each_Uaid;
                return output;
            }
        };

        struct PriceOverride : public PlayFabBaseModel
        {

            PriceOverride() :
                PlayFabBaseModel()
            {}

            PriceOverride(const PriceOverride&) :
                PlayFabBaseModel()
            {}

            ~PriceOverride() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct PricesOverride : public PlayFabBaseModel
        {

            PricesOverride() :
                PlayFabBaseModel()
            {}

            PricesOverride(const PricesOverride&) :
                PlayFabBaseModel()
            {}

            ~PricesOverride() = default;

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

            SearchItemsRequest() :
                PlayFabRequestCommon(),
                ContinuationToken(),
                Count(),
                CustomTags(),
                Entity(),
                Filter(),
                OrderBy(),
                Search(),
                Select()
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
                Select(src.Select)
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

        struct StoreDetails : public PlayFabBaseModel
        {

            StoreDetails() :
                PlayFabBaseModel()
            {}

            StoreDetails(const StoreDetails&) :
                PlayFabBaseModel()
            {}

            ~StoreDetails() = default;

            void FromJson(const Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct StoreInfo : public PlayFabBaseModel
        {
            Boxed<CatalogAlternateId> AlternateId;
            std::string Id;

            StoreInfo() :
                PlayFabBaseModel(),
                AlternateId(),
                Id()
            {}

            StoreInfo(const StoreInfo& src) :
                PlayFabBaseModel(),
                AlternateId(src.AlternateId),
                Id(src.Id)
            {}

            ~StoreInfo() = default;

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

    }
}

#endif
