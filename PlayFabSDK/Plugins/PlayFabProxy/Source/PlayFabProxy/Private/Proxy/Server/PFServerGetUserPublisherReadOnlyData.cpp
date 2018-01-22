// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetUserPublisherReadOnlyData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetUserPublisherReadOnlyData::UPFServerGetUserPublisherReadOnlyData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetUserPublisherReadOnlyDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetUserPublisherReadOnlyData* UPFServerGetUserPublisherReadOnlyData::GetUserPublisherReadOnlyData(class APlayerController* PlayerController, const FBPServerGetUserDataRequest& InGetUserDataRequest)
{
    UPFServerGetUserPublisherReadOnlyData* Proxy = NewObject<UPFServerGetUserPublisherReadOnlyData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetUserDataRequest;
    
    return Proxy;
}

void UPFServerGetUserPublisherReadOnlyData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetUserPublisherReadOnlyData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetUserPublisherReadOnlyData::OnSuccessCallback(const PlayFab::ServerModels::FGetUserDataResult& Result)
{
    FBPServerGetUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
