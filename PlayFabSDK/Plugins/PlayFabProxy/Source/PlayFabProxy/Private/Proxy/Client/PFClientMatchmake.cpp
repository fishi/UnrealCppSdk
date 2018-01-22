// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientMatchmake.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientMatchmake::UPFClientMatchmake(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FMatchmakeDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientMatchmake* UPFClientMatchmake::Matchmake(class APlayerController* PlayerController, const FBPClientMatchmakeRequest& InMatchmakeRequest)
{
    UPFClientMatchmake* Proxy = NewObject<UPFClientMatchmake>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InMatchmakeRequest;
    
    return Proxy;
}

void UPFClientMatchmake::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->Matchmake(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientMatchmake::OnSuccessCallback(const PlayFab::ClientModels::FMatchmakeResult& Result)
{
    FBPClientMatchmakeResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
