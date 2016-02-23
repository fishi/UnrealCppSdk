// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "PlayFabAdminBPDataModels.h"
#include "PlayFabAdminBPLibrary.generated.h"

UCLASS()
class UPFAdminProxyLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:

	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminAddNewsRequest(
		const FBPAdminAddNewsRequest& In
        ,FDateTime& OutTimestamp
        ,FString& OutTitle
        ,FString& OutBody
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminAddNewsResult(
		const FBPAdminAddNewsResult& In
        ,FString& OutNewsId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminAddServerBuildRequest(
		const FBPAdminAddServerBuildRequest& In
        ,FString& OutBuildId
        ,FString& OutCommandLineTemplate
        ,FString& OutExecutablePath
        ,FString& OutComment
        ,int32& OutMaxGamesPerHost
        ,int32& OutMinFreeGameSlots
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminAddServerBuildResult(
		const FBPAdminAddServerBuildResult& In
        ,FString& OutBuildId
        ,int32& OutMaxGamesPerHost
        ,int32& OutMinFreeGameSlots
        ,FString& OutCommandLineTemplate
        ,FString& OutExecutablePath
        ,FString& OutComment
        ,FDateTime& OutTimestamp
        ,FString& OutTitleId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminAddUserVirtualCurrencyRequest(
		const FBPAdminAddUserVirtualCurrencyRequest& In
        ,FString& OutPlayFabId
        ,FString& OutVirtualCurrency
        ,int32& OutAmount
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminAddVirtualCurrencyTypesRequest(
		const FBPAdminAddVirtualCurrencyTypesRequest& In
        ,TArray<FBPAdminVirtualCurrencyData>& OutVirtualCurrencies
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminBlankResult(
		const FBPAdminBlankResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminCatalogItem(
		const FBPAdminCatalogItem& In
        ,FString& OutItemId
        ,FString& OutItemClass
        ,FString& OutCatalogVersion
        ,FString& OutDisplayName
        ,FString& OutDescription
        ,TArray<FString>& OutTags
        ,FString& OutCustomData
        ,FBPAdminCatalogItemConsumableInfo& OutConsumable
        ,FBPAdminCatalogItemContainerInfo& OutContainer
        ,FBPAdminCatalogItemBundleInfo& OutBundle
        ,bool& OutCanBecomeCharacter
        ,bool& OutIsStackable
        ,bool& OutIsTradable
        ,FString& OutItemImageUrl
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminCatalogItemBundleInfo(
		const FBPAdminCatalogItemBundleInfo& In
        ,TArray<FString>& OutBundledItems
        ,TArray<FString>& OutBundledResultTables
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminCatalogItemConsumableInfo(
		const FBPAdminCatalogItemConsumableInfo& In
        ,int32& OutUsageCount
        ,int32& OutUsagePeriod
        ,FString& OutUsagePeriodGroup
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminCatalogItemContainerInfo(
		const FBPAdminCatalogItemContainerInfo& In
        ,FString& OutKeyItemId
        ,TArray<FString>& OutItemContents
        ,TArray<FString>& OutResultTableContents
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminCloudScriptFile(
		const FBPAdminCloudScriptFile& In
        ,FString& OutFilename
        ,FString& OutFileContents
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminCloudScriptVersionStatus(
		const FBPAdminCloudScriptVersionStatus& In
        ,int32& OutVersion
        ,int32& OutPublishedRevision
        ,int32& OutLatestRevision
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminContentInfo(
		const FBPAdminContentInfo& In
        ,FString& OutKey
        ,int32& OutSize
        ,FDateTime& OutLastModified
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminCreatePlayerStatisticDefinitionRequest(
		const FBPAdminCreatePlayerStatisticDefinitionRequest& In
        ,FString& OutStatisticName
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminCreatePlayerStatisticDefinitionResult(
		const FBPAdminCreatePlayerStatisticDefinitionResult& In
        ,FBPAdminPlayerStatisticDefinition& OutStatistic
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminCurrency(
		const FBPAdminCurrency& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminDeleteContentRequest(
		const FBPAdminDeleteContentRequest& In
        ,FString& OutKey
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminDeleteUsersRequest(
		const FBPAdminDeleteUsersRequest& In
        ,TArray<FString>& OutPlayFabIds
        ,FString& OutTitleId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminDeleteUsersResult(
		const FBPAdminDeleteUsersResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGameBuildStatus(
		const FBPAdminGameBuildStatus& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGameModeInfo(
		const FBPAdminGameModeInfo& In
        ,FString& OutGamemode
        ,int32& OutMinPlayerCount
        ,int32& OutMaxPlayerCount
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetCatalogItemsRequest(
		const FBPAdminGetCatalogItemsRequest& In
        ,FString& OutCatalogVersion
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetCatalogItemsResult(
		const FBPAdminGetCatalogItemsResult& In
        ,TArray<FBPAdminCatalogItem>& OutCatalog
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetCloudScriptRevisionRequest(
		const FBPAdminGetCloudScriptRevisionRequest& In
        ,int32& OutVersion
        ,int32& OutRevision
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetCloudScriptRevisionResult(
		const FBPAdminGetCloudScriptRevisionResult& In
        ,int32& OutVersion
        ,int32& OutRevision
        ,FDateTime& OutCreatedAt
        ,TArray<FBPAdminCloudScriptFile>& OutFiles
        ,bool& OutIsPublished
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetCloudScriptVersionsRequest(
		const FBPAdminGetCloudScriptVersionsRequest& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetCloudScriptVersionsResult(
		const FBPAdminGetCloudScriptVersionsResult& In
        ,TArray<FBPAdminCloudScriptVersionStatus>& OutVersions
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetContentListRequest(
		const FBPAdminGetContentListRequest& In
        ,FString& OutPrefix
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetContentListResult(
		const FBPAdminGetContentListResult& In
        ,int32& OutItemCount
        ,int32& OutTotalSize
        ,TArray<FBPAdminContentInfo>& OutContents
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetContentUploadUrlRequest(
		const FBPAdminGetContentUploadUrlRequest& In
        ,FString& OutKey
        ,FString& OutContentType
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetContentUploadUrlResult(
		const FBPAdminGetContentUploadUrlResult& In
        ,FString& OutURL
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetDataReportRequest(
		const FBPAdminGetDataReportRequest& In
        ,FString& OutReportName
        ,int32& OutYear
        ,int32& OutMonth
        ,int32& OutDay
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetDataReportResult(
		const FBPAdminGetDataReportResult& In
        ,FString& OutDownloadUrl
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetMatchmakerGameInfoRequest(
		const FBPAdminGetMatchmakerGameInfoRequest& In
        ,FString& OutLobbyId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetMatchmakerGameInfoResult(
		const FBPAdminGetMatchmakerGameInfoResult& In
        ,FString& OutLobbyId
        ,FString& OutTitleId
        ,FDateTime& OutStartTime
        ,FDateTime& OutEndTime
        ,FString& OutMode
        ,FString& OutBuildVersion
        ,TArray<FString>& OutPlayers
        ,FString& OutServerAddress
        ,int32& OutServerPort
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetMatchmakerGameModesRequest(
		const FBPAdminGetMatchmakerGameModesRequest& In
        ,FString& OutBuildVersion
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetMatchmakerGameModesResult(
		const FBPAdminGetMatchmakerGameModesResult& In
        ,TArray<FBPAdminGameModeInfo>& OutGameModes
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetPlayerStatisticDefinitionsRequest(
		const FBPAdminGetPlayerStatisticDefinitionsRequest& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetPlayerStatisticDefinitionsResult(
		const FBPAdminGetPlayerStatisticDefinitionsResult& In
        ,TArray<FBPAdminPlayerStatisticDefinition>& OutStatistics
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetPlayerStatisticVersionsRequest(
		const FBPAdminGetPlayerStatisticVersionsRequest& In
        ,FString& OutStatisticName
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetPlayerStatisticVersionsResult(
		const FBPAdminGetPlayerStatisticVersionsResult& In
        ,TArray<FBPAdminPlayerStatisticVersion>& OutStatisticVersions
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetPublisherDataRequest(
		const FBPAdminGetPublisherDataRequest& In
        ,TArray<FString>& OutKeys
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetPublisherDataResult(
		const FBPAdminGetPublisherDataResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetRandomResultTablesRequest(
		const FBPAdminGetRandomResultTablesRequest& In
        ,FString& OutCatalogVersion
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetRandomResultTablesResult(
		const FBPAdminGetRandomResultTablesResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetServerBuildInfoRequest(
		const FBPAdminGetServerBuildInfoRequest& In
        ,FString& OutBuildId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetServerBuildInfoResult(
		const FBPAdminGetServerBuildInfoResult& In
        ,FString& OutBuildId
        ,int32& OutMaxGamesPerHost
        ,int32& OutMinFreeGameSlots
        ,FString& OutComment
        ,FDateTime& OutTimestamp
        ,FString& OutTitleId
        ,FString& OutErrorMessage
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetServerBuildUploadURLRequest(
		const FBPAdminGetServerBuildUploadURLRequest& In
        ,FString& OutBuildId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetServerBuildUploadURLResult(
		const FBPAdminGetServerBuildUploadURLResult& In
        ,FString& OutURL
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetStoreItemsRequest(
		const FBPAdminGetStoreItemsRequest& In
        ,FString& OutCatalogVersion
        ,FString& OutStoreId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetStoreItemsResult(
		const FBPAdminGetStoreItemsResult& In
        ,TArray<FBPAdminStoreItem>& OutStore
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetTitleDataRequest(
		const FBPAdminGetTitleDataRequest& In
        ,TArray<FString>& OutKeys
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetTitleDataResult(
		const FBPAdminGetTitleDataResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetUserDataRequest(
		const FBPAdminGetUserDataRequest& In
        ,FString& OutPlayFabId
        ,TArray<FString>& OutKeys
        ,int32& OutIfChangedFromDataVersion
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetUserDataResult(
		const FBPAdminGetUserDataResult& In
        ,FString& OutPlayFabId
        ,int32& OutDataVersion
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetUserInventoryRequest(
		const FBPAdminGetUserInventoryRequest& In
        ,FString& OutPlayFabId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGetUserInventoryResult(
		const FBPAdminGetUserInventoryResult& In
        ,FString& OutPlayFabId
        ,TArray<FBPAdminItemInstance>& OutInventory
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGrantedItemInstance(
		const FBPAdminGrantedItemInstance& In
        ,FString& OutPlayFabId
        ,FString& OutCharacterId
        ,bool& OutResult
        ,FString& OutItemId
        ,FString& OutItemInstanceId
        ,FString& OutItemClass
        ,FDateTime& OutPurchaseDate
        ,FDateTime& OutExpiration
        ,int32& OutRemainingUses
        ,int32& OutUsesIncrementedBy
        ,FString& OutAnnotation
        ,FString& OutCatalogVersion
        ,FString& OutBundleParent
        ,FString& OutDisplayName
        ,FString& OutUnitCurrency
        ,int32& OutUnitPrice
        ,TArray<FString>& OutBundleContents
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGrantItemsToUsersRequest(
		const FBPAdminGrantItemsToUsersRequest& In
        ,FString& OutCatalogVersion
        ,TArray<FBPAdminItemGrant>& OutItemGrants
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminGrantItemsToUsersResult(
		const FBPAdminGrantItemsToUsersResult& In
        ,TArray<FBPAdminGrantedItemInstance>& OutItemGrantResults
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminIncrementPlayerStatisticVersionRequest(
		const FBPAdminIncrementPlayerStatisticVersionRequest& In
        ,FString& OutStatisticName
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminIncrementPlayerStatisticVersionResult(
		const FBPAdminIncrementPlayerStatisticVersionResult& In
        ,FBPAdminPlayerStatisticVersion& OutStatisticVersion
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminItemGrant(
		const FBPAdminItemGrant& In
        ,FString& OutPlayFabId
        ,FString& OutItemId
        ,FString& OutAnnotation
        ,FString& OutCharacterId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminItemInstance(
		const FBPAdminItemInstance& In
        ,FString& OutItemId
        ,FString& OutItemInstanceId
        ,FString& OutItemClass
        ,FDateTime& OutPurchaseDate
        ,FDateTime& OutExpiration
        ,int32& OutRemainingUses
        ,int32& OutUsesIncrementedBy
        ,FString& OutAnnotation
        ,FString& OutCatalogVersion
        ,FString& OutBundleParent
        ,FString& OutDisplayName
        ,FString& OutUnitCurrency
        ,int32& OutUnitPrice
        ,TArray<FString>& OutBundleContents
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminListBuildsRequest(
		const FBPAdminListBuildsRequest& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminListBuildsResult(
		const FBPAdminListBuildsResult& In
        ,TArray<FBPAdminGetServerBuildInfoResult>& OutBuilds
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminListVirtualCurrencyTypesRequest(
		const FBPAdminListVirtualCurrencyTypesRequest& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminListVirtualCurrencyTypesResult(
		const FBPAdminListVirtualCurrencyTypesResult& In
        ,TArray<FBPAdminVirtualCurrencyData>& OutVirtualCurrencies
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminLookupUserAccountInfoRequest(
		const FBPAdminLookupUserAccountInfoRequest& In
        ,FString& OutPlayFabId
        ,FString& OutEmail
        ,FString& OutUsername
        ,FString& OutTitleDisplayName
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminLookupUserAccountInfoResult(
		const FBPAdminLookupUserAccountInfoResult& In
        ,FBPAdminUserAccountInfo& OutUserInfo
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminModifyMatchmakerGameModesRequest(
		const FBPAdminModifyMatchmakerGameModesRequest& In
        ,FString& OutBuildVersion
        ,TArray<FBPAdminGameModeInfo>& OutGameModes
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminModifyMatchmakerGameModesResult(
		const FBPAdminModifyMatchmakerGameModesResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminModifyServerBuildRequest(
		const FBPAdminModifyServerBuildRequest& In
        ,FString& OutBuildId
        ,FDateTime& OutTimestamp
        ,int32& OutMaxGamesPerHost
        ,int32& OutMinFreeGameSlots
        ,FString& OutCommandLineTemplate
        ,FString& OutExecutablePath
        ,FString& OutComment
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminModifyServerBuildResult(
		const FBPAdminModifyServerBuildResult& In
        ,FString& OutBuildId
        ,int32& OutMaxGamesPerHost
        ,int32& OutMinFreeGameSlots
        ,FString& OutCommandLineTemplate
        ,FString& OutExecutablePath
        ,FString& OutComment
        ,FDateTime& OutTimestamp
        ,FString& OutTitleId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminModifyUserVirtualCurrencyResult(
		const FBPAdminModifyUserVirtualCurrencyResult& In
        ,FString& OutPlayFabId
        ,FString& OutVirtualCurrency
        ,int32& OutBalanceChange
        ,int32& OutBalance
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminPlayerStatisticDefinition(
		const FBPAdminPlayerStatisticDefinition& In
        ,FString& OutStatisticName
        ,int32& OutCurrentVersion
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminPlayerStatisticVersion(
		const FBPAdminPlayerStatisticVersion& In
        ,FString& OutStatisticName
        ,int32& OutVersion
        ,FDateTime& OutScheduledActivationTime
        ,FDateTime& OutActivationTime
        ,FDateTime& OutScheduledDeactivationTime
        ,FDateTime& OutDeactivationTime
        ,FString& OutArchiveDownloadUrl
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminRandomResultTable(
		const FBPAdminRandomResultTable& In
        ,FString& OutTableId
        ,TArray<FBPAdminResultTableNode>& OutNodes
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminRandomResultTableListing(
		const FBPAdminRandomResultTableListing& In
        ,FString& OutCatalogVersion
        ,FString& OutTableId
        ,TArray<FBPAdminResultTableNode>& OutNodes
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminRegion(
		const FBPAdminRegion& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminRemoveServerBuildRequest(
		const FBPAdminRemoveServerBuildRequest& In
        ,FString& OutBuildId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminRemoveServerBuildResult(
		const FBPAdminRemoveServerBuildResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminResetCharacterStatisticsRequest(
		const FBPAdminResetCharacterStatisticsRequest& In
        ,FString& OutPlayFabId
        ,FString& OutCharacterId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminResetCharacterStatisticsResult(
		const FBPAdminResetCharacterStatisticsResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminResetUsersRequest(
		const FBPAdminResetUsersRequest& In
        ,TArray<FBPAdminUserCredentials>& OutUsers
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminResetUserStatisticsRequest(
		const FBPAdminResetUserStatisticsRequest& In
        ,FString& OutPlayFabId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminResetUserStatisticsResult(
		const FBPAdminResetUserStatisticsResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminResultTableNode(
		const FBPAdminResultTableNode& In
        ,FString& OutResultItem
        ,int32& OutWeight
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminResultTableNodeType(
		const FBPAdminResultTableNodeType& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminRevokeInventoryItemRequest(
		const FBPAdminRevokeInventoryItemRequest& In
        ,FString& OutPlayFabId
        ,FString& OutCharacterId
        ,FString& OutItemInstanceId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminRevokeInventoryResult(
		const FBPAdminRevokeInventoryResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSendAccountRecoveryEmailRequest(
		const FBPAdminSendAccountRecoveryEmailRequest& In
        ,FString& OutEmail
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSendAccountRecoveryEmailResult(
		const FBPAdminSendAccountRecoveryEmailResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSetPublishedRevisionRequest(
		const FBPAdminSetPublishedRevisionRequest& In
        ,int32& OutVersion
        ,int32& OutRevision
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSetPublishedRevisionResult(
		const FBPAdminSetPublishedRevisionResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSetPublisherDataRequest(
		const FBPAdminSetPublisherDataRequest& In
        ,FString& OutKey
        ,FString& OutValue
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSetPublisherDataResult(
		const FBPAdminSetPublisherDataResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSetTitleDataRequest(
		const FBPAdminSetTitleDataRequest& In
        ,FString& OutKey
        ,FString& OutValue
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSetTitleDataResult(
		const FBPAdminSetTitleDataResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSetupPushNotificationRequest(
		const FBPAdminSetupPushNotificationRequest& In
        ,FString& OutName
        ,FString& OutPlatform
        ,FString& OutKey
        ,FString& OutCredential
        ,bool& OutOverwriteOldARN
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSetupPushNotificationResult(
		const FBPAdminSetupPushNotificationResult& In
        ,FString& OutARN
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminStatisticResetIntervalOption(
		const FBPAdminStatisticResetIntervalOption& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminStatisticVersionArchivalStatus(
		const FBPAdminStatisticVersionArchivalStatus& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminStoreItem(
		const FBPAdminStoreItem& In
        ,FString& OutItemId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminSubtractUserVirtualCurrencyRequest(
		const FBPAdminSubtractUserVirtualCurrencyRequest& In
        ,FString& OutPlayFabId
        ,FString& OutVirtualCurrency
        ,int32& OutAmount
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminTitleActivationStatus(
		const FBPAdminTitleActivationStatus& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateCatalogItemsRequest(
		const FBPAdminUpdateCatalogItemsRequest& In
        ,FString& OutCatalogVersion
        ,TArray<FBPAdminCatalogItem>& OutCatalog
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateCatalogItemsResult(
		const FBPAdminUpdateCatalogItemsResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateCloudScriptRequest(
		const FBPAdminUpdateCloudScriptRequest& In
        ,int32& OutVersion
        ,TArray<FBPAdminCloudScriptFile>& OutFiles
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateCloudScriptResult(
		const FBPAdminUpdateCloudScriptResult& In
        ,int32& OutVersion
        ,int32& OutRevision
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdatePlayerStatisticDefinitionRequest(
		const FBPAdminUpdatePlayerStatisticDefinitionRequest& In
        ,FString& OutStatisticName
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdatePlayerStatisticDefinitionResult(
		const FBPAdminUpdatePlayerStatisticDefinitionResult& In
        ,FBPAdminPlayerStatisticDefinition& OutStatistic
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateRandomResultTablesRequest(
		const FBPAdminUpdateRandomResultTablesRequest& In
        ,FString& OutCatalogVersion
        ,TArray<FBPAdminRandomResultTable>& OutTables
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateRandomResultTablesResult(
		const FBPAdminUpdateRandomResultTablesResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateStoreItemsRequest(
		const FBPAdminUpdateStoreItemsRequest& In
        ,FString& OutCatalogVersion
        ,FString& OutStoreId
        ,TArray<FBPAdminStoreItem>& OutStore
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateStoreItemsResult(
		const FBPAdminUpdateStoreItemsResult& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateUserDataRequest(
		const FBPAdminUpdateUserDataRequest& In
        ,FString& OutPlayFabId
        ,TArray<FString>& OutKeysToRemove
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateUserDataResult(
		const FBPAdminUpdateUserDataResult& In
        ,int32& OutDataVersion
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateUserInternalDataRequest(
		const FBPAdminUpdateUserInternalDataRequest& In
        ,FString& OutPlayFabId
        ,TArray<FString>& OutKeysToRemove
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateUserTitleDisplayNameRequest(
		const FBPAdminUpdateUserTitleDisplayNameRequest& In
        ,FString& OutPlayFabId
        ,FString& OutDisplayName
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUpdateUserTitleDisplayNameResult(
		const FBPAdminUpdateUserTitleDisplayNameResult& In
        ,FString& OutDisplayName
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserAccountInfo(
		const FBPAdminUserAccountInfo& In
        ,FString& OutPlayFabId
        ,FDateTime& OutCreated
        ,FString& OutUsername
        ,FBPAdminUserTitleInfo& OutTitleInfo
        ,FBPAdminUserPrivateAccountInfo& OutPrivateInfo
        ,FBPAdminUserFacebookInfo& OutFacebookInfo
        ,FBPAdminUserSteamInfo& OutSteamInfo
        ,FBPAdminUserGameCenterInfo& OutGameCenterInfo
        ,FBPAdminUserIosDeviceInfo& OutIosDeviceInfo
        ,FBPAdminUserAndroidDeviceInfo& OutAndroidDeviceInfo
        ,FBPAdminUserKongregateInfo& OutKongregateInfo
        ,FBPAdminUserPsnInfo& OutPsnInfo
        ,FBPAdminUserGoogleInfo& OutGoogleInfo
        ,FBPAdminUserXboxInfo& OutXboxInfo
        ,FBPAdminUserCustomIdInfo& OutCustomIdInfo
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserAndroidDeviceInfo(
		const FBPAdminUserAndroidDeviceInfo& In
        ,FString& OutAndroidDeviceId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserCredentials(
		const FBPAdminUserCredentials& In
        ,FString& OutUsername
        ,FString& OutPassword
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserCustomIdInfo(
		const FBPAdminUserCustomIdInfo& In
        ,FString& OutCustomId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserDataPermission(
		const FBPAdminUserDataPermission& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserDataRecord(
		const FBPAdminUserDataRecord& In
        ,FString& OutValue
        ,FDateTime& OutLastUpdated
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserFacebookInfo(
		const FBPAdminUserFacebookInfo& In
        ,FString& OutFacebookId
        ,FString& OutFullName
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserGameCenterInfo(
		const FBPAdminUserGameCenterInfo& In
        ,FString& OutGameCenterId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserGoogleInfo(
		const FBPAdminUserGoogleInfo& In
        ,FString& OutGoogleId
        ,FString& OutGoogleEmail
        ,FString& OutGoogleLocale
        ,FString& OutGoogleGender
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserIosDeviceInfo(
		const FBPAdminUserIosDeviceInfo& In
        ,FString& OutIosDeviceId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserKongregateInfo(
		const FBPAdminUserKongregateInfo& In
        ,FString& OutKongregateId
        ,FString& OutKongregateName
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserOrigination(
		const FBPAdminUserOrigination& In
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserPrivateAccountInfo(
		const FBPAdminUserPrivateAccountInfo& In
        ,FString& OutEmail
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserPsnInfo(
		const FBPAdminUserPsnInfo& In
        ,FString& OutPsnAccountId
        ,FString& OutPsnOnlineId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserSteamInfo(
		const FBPAdminUserSteamInfo& In
        ,FString& OutSteamId
        ,FString& OutSteamCountry
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserTitleInfo(
		const FBPAdminUserTitleInfo& In
        ,FString& OutDisplayName
        ,FDateTime& OutCreated
        ,FDateTime& OutLastLogin
        ,FDateTime& OutFirstLogin
        ,bool& OutisBanned
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminUserXboxInfo(
		const FBPAdminUserXboxInfo& In
        ,FString& OutXboxUserId
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminVirtualCurrencyData(
		const FBPAdminVirtualCurrencyData& In
        ,FString& OutCurrencyCode
        ,FString& OutDisplayName
        ,int32& OutInitialDeposit
        ,int32& OutRechargeRate
        ,int32& OutRechargeMax
	);
	
	UFUNCTION(BlueprintPure, Category = "PlayFab|Admin", meta = (NativeBreakFunc))
	static void BreakBPAdminVirtualCurrencyRechargeTime(
		const FBPAdminVirtualCurrencyRechargeTime& In
        ,int32& OutSecondsToRecharge
        ,FDateTime& OutRechargeTime
        ,int32& OutRechargeMax
	);
	


};