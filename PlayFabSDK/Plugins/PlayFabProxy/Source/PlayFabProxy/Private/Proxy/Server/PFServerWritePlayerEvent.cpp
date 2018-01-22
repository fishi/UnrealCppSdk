// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerWritePlayerEvent.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerWritePlayerEvent::UPFServerWritePlayerEvent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FWritePlayerEventDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerWritePlayerEvent* UPFServerWritePlayerEvent::WritePlayerEvent(class APlayerController* PlayerController, const FBPServerWriteServerPlayerEventRequest& InWriteServerPlayerEventRequest)
{
    UPFServerWritePlayerEvent* Proxy = NewObject<UPFServerWritePlayerEvent>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InWriteServerPlayerEventRequest;
    
    return Proxy;
}

void UPFServerWritePlayerEvent::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->WritePlayerEvent(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerWritePlayerEvent::OnSuccessCallback(const PlayFab::ServerModels::FWriteEventResponse& Result)
{
    FBPServerWriteEventResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
