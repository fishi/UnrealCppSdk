// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerUpdateAvatarUrl.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerUpdateAvatarUrl::UPFServerUpdateAvatarUrl(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FUpdateAvatarUrlDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerUpdateAvatarUrl* UPFServerUpdateAvatarUrl::UpdateAvatarUrl(class APlayerController* PlayerController, const FBPServerUpdateAvatarUrlRequest& InUpdateAvatarUrlRequest)
{
    UPFServerUpdateAvatarUrl* Proxy = NewObject<UPFServerUpdateAvatarUrl>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateAvatarUrlRequest;
    
    return Proxy;
}

void UPFServerUpdateAvatarUrl::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->UpdateAvatarUrl(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerUpdateAvatarUrl::OnSuccessCallback(const PlayFab::ServerModels::FEmptyResult& Result)
{
    OnSuccess.Broadcast();
}
