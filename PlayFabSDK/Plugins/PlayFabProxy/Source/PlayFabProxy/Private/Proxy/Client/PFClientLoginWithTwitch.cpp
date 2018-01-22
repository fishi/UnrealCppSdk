// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientLoginWithTwitch.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientLoginWithTwitch::UPFClientLoginWithTwitch(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FLoginWithTwitchDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientLoginWithTwitch* UPFClientLoginWithTwitch::LoginWithTwitch(class APlayerController* PlayerController, const FBPClientLoginWithTwitchRequest& InLoginWithTwitchRequest)
{
    UPFClientLoginWithTwitch* Proxy = NewObject<UPFClientLoginWithTwitch>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InLoginWithTwitchRequest;
    
    return Proxy;
}

void UPFClientLoginWithTwitch::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->LoginWithTwitch(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientLoginWithTwitch::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
    FBPClientLoginResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
