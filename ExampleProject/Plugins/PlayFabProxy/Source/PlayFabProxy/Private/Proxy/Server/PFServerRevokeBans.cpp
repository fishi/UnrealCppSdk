// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerRevokeBans.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerRevokeBans::UPFServerRevokeBans(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FRevokeBansDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerRevokeBans* UPFServerRevokeBans::RevokeBans(class APlayerController* PlayerController, const FBPServerRevokeBansRequest& InRevokeBansRequest)
{
    UPFServerRevokeBans* Proxy = NewObject<UPFServerRevokeBans>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRevokeBansRequest;
    
    return Proxy;
}

void UPFServerRevokeBans::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->RevokeBans(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerRevokeBans::OnSuccessCallback(const PlayFab::ServerModels::FRevokeBansResult& Result)
{
    FBPServerRevokeBansResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}