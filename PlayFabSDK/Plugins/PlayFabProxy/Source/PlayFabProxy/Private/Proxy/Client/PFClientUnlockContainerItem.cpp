// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientUnlockContainerItem.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientUnlockContainerItem::UPFClientUnlockContainerItem(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FUnlockContainerItemDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientUnlockContainerItem* UPFClientUnlockContainerItem::UnlockContainerItem(class APlayerController* PlayerController, const FBPClientUnlockContainerItemRequest& InUnlockContainerItemRequest)
{
    UPFClientUnlockContainerItem* Proxy = NewObject<UPFClientUnlockContainerItem>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUnlockContainerItemRequest;
    
    return Proxy;
}

void UPFClientUnlockContainerItem::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->UnlockContainerItem(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientUnlockContainerItem::OnSuccessCallback(const PlayFab::ClientModels::FUnlockContainerItemResult& Result)
{
    FBPClientUnlockContainerItemResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
