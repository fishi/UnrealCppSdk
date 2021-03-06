// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetUserPublisherReadOnlyData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetUserPublisherReadOnlyData::UPFAdminGetUserPublisherReadOnlyData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetUserPublisherReadOnlyDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetUserPublisherReadOnlyData* UPFAdminGetUserPublisherReadOnlyData::GetUserPublisherReadOnlyData(class APlayerController* PlayerController, const FBPAdminGetUserDataRequest& InGetUserDataRequest)
{
    UPFAdminGetUserPublisherReadOnlyData* Proxy = NewObject<UPFAdminGetUserPublisherReadOnlyData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetUserDataRequest;
    
    return Proxy;
}

void UPFAdminGetUserPublisherReadOnlyData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetUserPublisherReadOnlyData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminGetUserPublisherReadOnlyData::OnSuccessCallback(const PlayFab::AdminModels::FGetUserDataResult& Result)
{
    FBPAdminGetUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
