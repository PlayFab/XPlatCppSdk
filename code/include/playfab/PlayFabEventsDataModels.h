#pragma once

#if !defined(DISABLE_PLAYFABENTITY_API)

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFab
{
    namespace EventsModels
    {
        // Events Enums
        enum class DataConnectionErrorState
        {
            DataConnectionErrorStateOK,
            DataConnectionErrorStateError
        };

        inline void ToJsonEnum(const DataConnectionErrorState input, Json::Value& output)
        {
            if (input == DataConnectionErrorState::DataConnectionErrorStateOK)
            {
                output = Json::Value("OK");
                return;
            }
            if (input == DataConnectionErrorState::DataConnectionErrorStateError)
            {
                output = Json::Value("Error");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, DataConnectionErrorState& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "OK")
            {
                output = DataConnectionErrorState::DataConnectionErrorStateOK;
                return;
            }
            if (inputStr == "Error")
            {
                output = DataConnectionErrorState::DataConnectionErrorStateError;
                return;
            }
        }

        enum class DataConnectionType
        {
            DataConnectionTypeAzureBlobStorage,
            DataConnectionTypeAzureDataExplorer,
            DataConnectionTypeFabricKQL
        };

        inline void ToJsonEnum(const DataConnectionType input, Json::Value& output)
        {
            if (input == DataConnectionType::DataConnectionTypeAzureBlobStorage)
            {
                output = Json::Value("AzureBlobStorage");
                return;
            }
            if (input == DataConnectionType::DataConnectionTypeAzureDataExplorer)
            {
                output = Json::Value("AzureDataExplorer");
                return;
            }
            if (input == DataConnectionType::DataConnectionTypeFabricKQL)
            {
                output = Json::Value("FabricKQL");
                return;
            }
        }
        inline void FromJsonEnum(const Json::Value& input, DataConnectionType& output)
        {
            if (!input.isString())
            {
                return;
            }
            const std::string& inputStr = input.asString();
            if (inputStr == "AzureBlobStorage")
            {
                output = DataConnectionType::DataConnectionTypeAzureBlobStorage;
                return;
            }
            if (inputStr == "AzureDataExplorer")
            {
                output = DataConnectionType::DataConnectionTypeAzureDataExplorer;
                return;
            }
            if (inputStr == "FabricKQL")
            {
                output = DataConnectionType::DataConnectionTypeFabricKQL;
                return;
            }
        }

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

        struct DataConnectionAzureBlobSettings : public PlayFabBaseModel
        {
            std::string AccountName;
            std::string ContainerName;
            std::string TenantId;

            DataConnectionAzureBlobSettings() :
                PlayFabBaseModel(),
                AccountName(),
                ContainerName(),
                TenantId()
            {}

            DataConnectionAzureBlobSettings(const DataConnectionAzureBlobSettings& src) :
                PlayFabBaseModel(),
                AccountName(src.AccountName),
                ContainerName(src.ContainerName),
                TenantId(src.TenantId)
            {}

            ~DataConnectionAzureBlobSettings() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["AccountName"], AccountName);
                FromJsonUtilS(input["ContainerName"], ContainerName);
                FromJsonUtilS(input["TenantId"], TenantId);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AccountName; ToJsonUtilS(AccountName, each_AccountName); output["AccountName"] = each_AccountName;
                Json::Value each_ContainerName; ToJsonUtilS(ContainerName, each_ContainerName); output["ContainerName"] = each_ContainerName;
                Json::Value each_TenantId; ToJsonUtilS(TenantId, each_TenantId); output["TenantId"] = each_TenantId;
                return output;
            }
        };

        struct DataConnectionAzureDataExplorerSettings : public PlayFabBaseModel
        {
            std::string ClusterUri;
            std::string Database;
            std::string Table;

            DataConnectionAzureDataExplorerSettings() :
                PlayFabBaseModel(),
                ClusterUri(),
                Database(),
                Table()
            {}

            DataConnectionAzureDataExplorerSettings(const DataConnectionAzureDataExplorerSettings& src) :
                PlayFabBaseModel(),
                ClusterUri(src.ClusterUri),
                Database(src.Database),
                Table(src.Table)
            {}

            ~DataConnectionAzureDataExplorerSettings() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ClusterUri"], ClusterUri);
                FromJsonUtilS(input["Database"], Database);
                FromJsonUtilS(input["Table"], Table);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ClusterUri; ToJsonUtilS(ClusterUri, each_ClusterUri); output["ClusterUri"] = each_ClusterUri;
                Json::Value each_Database; ToJsonUtilS(Database, each_Database); output["Database"] = each_Database;
                Json::Value each_Table; ToJsonUtilS(Table, each_Table); output["Table"] = each_Table;
                return output;
            }
        };

        struct DataConnectionFabricKQLSettings : public PlayFabBaseModel
        {
            std::string ClusterUri;
            std::string Database;
            std::string Table;

            DataConnectionFabricKQLSettings() :
                PlayFabBaseModel(),
                ClusterUri(),
                Database(),
                Table()
            {}

            DataConnectionFabricKQLSettings(const DataConnectionFabricKQLSettings& src) :
                PlayFabBaseModel(),
                ClusterUri(src.ClusterUri),
                Database(src.Database),
                Table(src.Table)
            {}

            ~DataConnectionFabricKQLSettings() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["ClusterUri"], ClusterUri);
                FromJsonUtilS(input["Database"], Database);
                FromJsonUtilS(input["Table"], Table);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ClusterUri; ToJsonUtilS(ClusterUri, each_ClusterUri); output["ClusterUri"] = each_ClusterUri;
                Json::Value each_Database; ToJsonUtilS(Database, each_Database); output["Database"] = each_Database;
                Json::Value each_Table; ToJsonUtilS(Table, each_Table); output["Table"] = each_Table;
                return output;
            }
        };

        struct DataConnectionSettings : public PlayFabBaseModel
        {
            Boxed<DataConnectionAzureBlobSettings> AzureBlobSettings;
            Boxed<DataConnectionAzureDataExplorerSettings> AzureDataExplorerSettings;
            Boxed<DataConnectionFabricKQLSettings> AzureFabricKQLSettings;

            DataConnectionSettings() :
                PlayFabBaseModel(),
                AzureBlobSettings(),
                AzureDataExplorerSettings(),
                AzureFabricKQLSettings()
            {}

            DataConnectionSettings(const DataConnectionSettings& src) :
                PlayFabBaseModel(),
                AzureBlobSettings(src.AzureBlobSettings),
                AzureDataExplorerSettings(src.AzureDataExplorerSettings),
                AzureFabricKQLSettings(src.AzureFabricKQLSettings)
            {}

            ~DataConnectionSettings() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["AzureBlobSettings"], AzureBlobSettings);
                FromJsonUtilO(input["AzureDataExplorerSettings"], AzureDataExplorerSettings);
                FromJsonUtilO(input["AzureFabricKQLSettings"], AzureFabricKQLSettings);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_AzureBlobSettings; ToJsonUtilO(AzureBlobSettings, each_AzureBlobSettings); output["AzureBlobSettings"] = each_AzureBlobSettings;
                Json::Value each_AzureDataExplorerSettings; ToJsonUtilO(AzureDataExplorerSettings, each_AzureDataExplorerSettings); output["AzureDataExplorerSettings"] = each_AzureDataExplorerSettings;
                Json::Value each_AzureFabricKQLSettings; ToJsonUtilO(AzureFabricKQLSettings, each_AzureFabricKQLSettings); output["AzureFabricKQLSettings"] = each_AzureFabricKQLSettings;
                return output;
            }
        };

        struct DataConnectionStatusDetails : public PlayFabBaseModel
        {
            std::string Error;
            std::string ErrorMessage;
            Boxed<time_t> MostRecentErrorTime;
            Boxed<DataConnectionErrorState> State;

            DataConnectionStatusDetails() :
                PlayFabBaseModel(),
                Error(),
                ErrorMessage(),
                MostRecentErrorTime(),
                State()
            {}

            DataConnectionStatusDetails(const DataConnectionStatusDetails& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                ErrorMessage(src.ErrorMessage),
                MostRecentErrorTime(src.MostRecentErrorTime),
                State(src.State)
            {}

            ~DataConnectionStatusDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilS(input["Error"], Error);
                FromJsonUtilS(input["ErrorMessage"], ErrorMessage);
                FromJsonUtilT(input["MostRecentErrorTime"], MostRecentErrorTime);
                FromJsonUtilE(input["State"], State);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Error; ToJsonUtilS(Error, each_Error); output["Error"] = each_Error;
                Json::Value each_ErrorMessage; ToJsonUtilS(ErrorMessage, each_ErrorMessage); output["ErrorMessage"] = each_ErrorMessage;
                Json::Value each_MostRecentErrorTime; ToJsonUtilT(MostRecentErrorTime, each_MostRecentErrorTime); output["MostRecentErrorTime"] = each_MostRecentErrorTime;
                Json::Value each_State; ToJsonUtilE(State, each_State); output["State"] = each_State;
                return output;
            }
        };

        struct DataConnectionDetails : public PlayFabBaseModel
        {
            DataConnectionSettings ConnectionSettings;
            bool IsActive;
            std::string Name;
            Boxed<DataConnectionStatusDetails> Status;
            DataConnectionType Type;

            DataConnectionDetails() :
                PlayFabBaseModel(),
                ConnectionSettings(),
                IsActive(),
                Name(),
                Status(),
                Type()
            {}

            DataConnectionDetails(const DataConnectionDetails& src) :
                PlayFabBaseModel(),
                ConnectionSettings(src.ConnectionSettings),
                IsActive(src.IsActive),
                Name(src.Name),
                Status(src.Status),
                Type(src.Type)
            {}

            ~DataConnectionDetails() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["ConnectionSettings"], ConnectionSettings);
                FromJsonUtilP(input["IsActive"], IsActive);
                FromJsonUtilS(input["Name"], Name);
                FromJsonUtilO(input["Status"], Status);
                FromJsonEnum(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionSettings; ToJsonUtilO(ConnectionSettings, each_ConnectionSettings); output["ConnectionSettings"] = each_ConnectionSettings;
                Json::Value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output["IsActive"] = each_IsActive;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Status; ToJsonUtilO(Status, each_Status); output["Status"] = each_Status;
                Json::Value each_Type; ToJsonEnum(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct DeleteDataConnectionRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            DeleteDataConnectionRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            DeleteDataConnectionRequest(const DeleteDataConnectionRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~DeleteDataConnectionRequest() = default;

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

        struct DeleteDataConnectionResponse : public PlayFabResultCommon
        {
            bool WasDeleted;

            DeleteDataConnectionResponse() :
                PlayFabResultCommon(),
                WasDeleted()
            {}

            DeleteDataConnectionResponse(const DeleteDataConnectionResponse& src) :
                PlayFabResultCommon(),
                WasDeleted(src.WasDeleted)
            {}

            ~DeleteDataConnectionResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["WasDeleted"], WasDeleted);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_WasDeleted; ToJsonUtilP(WasDeleted, each_WasDeleted); output["WasDeleted"] = each_WasDeleted;
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

        struct GetDataConnectionRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            GetDataConnectionRequest() :
                PlayFabRequestCommon(),
                CustomTags(),
                Name()
            {}

            GetDataConnectionRequest(const GetDataConnectionRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~GetDataConnectionRequest() = default;

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

        struct GetDataConnectionResponse : public PlayFabResultCommon
        {
            Boxed<DataConnectionDetails> DataConnection;

            GetDataConnectionResponse() :
                PlayFabResultCommon(),
                DataConnection()
            {}

            GetDataConnectionResponse(const GetDataConnectionResponse& src) :
                PlayFabResultCommon(),
                DataConnection(src.DataConnection)
            {}

            ~GetDataConnectionResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["DataConnection"], DataConnection);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DataConnection; ToJsonUtilO(DataConnection, each_DataConnection); output["DataConnection"] = each_DataConnection;
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

        struct ListDataConnectionsRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> CustomTags;

            ListDataConnectionsRequest() :
                PlayFabRequestCommon(),
                CustomTags()
            {}

            ListDataConnectionsRequest(const ListDataConnectionsRequest& src) :
                PlayFabRequestCommon(),
                CustomTags(src.CustomTags)
            {}

            ~ListDataConnectionsRequest() = default;

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

        struct ListDataConnectionsResponse : public PlayFabResultCommon
        {
            std::list<DataConnectionDetails> DataConnections;

            ListDataConnectionsResponse() :
                PlayFabResultCommon(),
                DataConnections()
            {}

            ListDataConnectionsResponse(const ListDataConnectionsResponse& src) :
                PlayFabResultCommon(),
                DataConnections(src.DataConnections)
            {}

            ~ListDataConnectionsResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["DataConnections"], DataConnections);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DataConnections; ToJsonUtilO(DataConnections, each_DataConnections); output["DataConnections"] = each_DataConnections;
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

        struct SetDataConnectionActiveRequest : public PlayFabRequestCommon
        {
            bool Active;
            std::map<std::string, std::string> CustomTags;
            std::string Name;

            SetDataConnectionActiveRequest() :
                PlayFabRequestCommon(),
                Active(),
                CustomTags(),
                Name()
            {}

            SetDataConnectionActiveRequest(const SetDataConnectionActiveRequest& src) :
                PlayFabRequestCommon(),
                Active(src.Active),
                CustomTags(src.CustomTags),
                Name(src.Name)
            {}

            ~SetDataConnectionActiveRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilP(input["Active"], Active);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilS(input["Name"], Name);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Active; ToJsonUtilP(Active, each_Active); output["Active"] = each_Active;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                return output;
            }
        };

        struct SetDataConnectionActiveResponse : public PlayFabResultCommon
        {
            Boxed<DataConnectionDetails> DataConnection;
            bool WasUpdated;

            SetDataConnectionActiveResponse() :
                PlayFabResultCommon(),
                DataConnection(),
                WasUpdated()
            {}

            SetDataConnectionActiveResponse(const SetDataConnectionActiveResponse& src) :
                PlayFabResultCommon(),
                DataConnection(src.DataConnection),
                WasUpdated(src.WasUpdated)
            {}

            ~SetDataConnectionActiveResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["DataConnection"], DataConnection);
                FromJsonUtilP(input["WasUpdated"], WasUpdated);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DataConnection; ToJsonUtilO(DataConnection, each_DataConnection); output["DataConnection"] = each_DataConnection;
                Json::Value each_WasUpdated; ToJsonUtilP(WasUpdated, each_WasUpdated); output["WasUpdated"] = each_WasUpdated;
                return output;
            }
        };

        struct SetDataConnectionRequest : public PlayFabRequestCommon
        {
            DataConnectionSettings ConnectionSettings;
            std::map<std::string, std::string> CustomTags;
            bool IsActive;
            std::string Name;
            DataConnectionType Type;

            SetDataConnectionRequest() :
                PlayFabRequestCommon(),
                ConnectionSettings(),
                CustomTags(),
                IsActive(),
                Name(),
                Type()
            {}

            SetDataConnectionRequest(const SetDataConnectionRequest& src) :
                PlayFabRequestCommon(),
                ConnectionSettings(src.ConnectionSettings),
                CustomTags(src.CustomTags),
                IsActive(src.IsActive),
                Name(src.Name),
                Type(src.Type)
            {}

            ~SetDataConnectionRequest() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["ConnectionSettings"], ConnectionSettings);
                FromJsonUtilS(input["CustomTags"], CustomTags);
                FromJsonUtilP(input["IsActive"], IsActive);
                FromJsonUtilS(input["Name"], Name);
                FromJsonEnum(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ConnectionSettings; ToJsonUtilO(ConnectionSettings, each_ConnectionSettings); output["ConnectionSettings"] = each_ConnectionSettings;
                Json::Value each_CustomTags; ToJsonUtilS(CustomTags, each_CustomTags); output["CustomTags"] = each_CustomTags;
                Json::Value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output["IsActive"] = each_IsActive;
                Json::Value each_Name; ToJsonUtilS(Name, each_Name); output["Name"] = each_Name;
                Json::Value each_Type; ToJsonEnum(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct SetDataConnectionResponse : public PlayFabResultCommon
        {
            Boxed<DataConnectionDetails> DataConnection;

            SetDataConnectionResponse() :
                PlayFabResultCommon(),
                DataConnection()
            {}

            SetDataConnectionResponse(const SetDataConnectionResponse& src) :
                PlayFabResultCommon(),
                DataConnection(src.DataConnection)
            {}

            ~SetDataConnectionResponse() = default;

            void FromJson(const Json::Value& input) override
            {
                FromJsonUtilO(input["DataConnection"], DataConnection);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_DataConnection; ToJsonUtilO(DataConnection, each_DataConnection); output["DataConnection"] = each_DataConnection;
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
