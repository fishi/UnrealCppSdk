// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetPlayerStatisticVersions.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetPlayerStatisticVersions::UPFAdminGetPlayerStatisticVersions(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetPlayerStatisticVersionsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetPlayerStatisticVersions* UPFAdminGetPlayerStatisticVersions::GetPlayerStatisticVersions(class APlayerController* PlayerController, const FBPAdminGetPlayerStatisticVersionsRequest& InGetPlayerStatisticVersionsRequest)
{
    UPFAdminGetPlayerStatisticVersions* Proxy = NewObject<UPFAdminGetPlayerStatisticVersions>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayerStatisticVersionsRequest;
    
    return Proxy;
}

void UPFAdminGetPlayerStatisticVersions::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetPlayerStatisticVersions(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminGetPlayerStatisticVersions::OnSuccessCallback(const PlayFab::AdminModels::FGetPlayerStatisticVersionsResult& Result)
{
    FBPAdminGetPlayerStatisticVersionsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
