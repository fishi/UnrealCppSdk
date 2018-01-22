// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetPublisherData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetPublisherData::UPFServerGetPublisherData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetPublisherDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetPublisherData* UPFServerGetPublisherData::GetPublisherData(class APlayerController* PlayerController, const FBPServerGetPublisherDataRequest& InGetPublisherDataRequest)
{
    UPFServerGetPublisherData* Proxy = NewObject<UPFServerGetPublisherData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPublisherDataRequest;
    
    return Proxy;
}

void UPFServerGetPublisherData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetPublisherData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetPublisherData::OnSuccessCallback(const PlayFab::ServerModels::FGetPublisherDataResult& Result)
{
    FBPServerGetPublisherDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
