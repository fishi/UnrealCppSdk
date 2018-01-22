// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerRevokeInventoryItem.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerRevokeInventoryItem::UPFServerRevokeInventoryItem(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FRevokeInventoryItemDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerRevokeInventoryItem* UPFServerRevokeInventoryItem::RevokeInventoryItem(class APlayerController* PlayerController, const FBPServerRevokeInventoryItemRequest& InRevokeInventoryItemRequest)
{
    UPFServerRevokeInventoryItem* Proxy = NewObject<UPFServerRevokeInventoryItem>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRevokeInventoryItemRequest;
    
    return Proxy;
}

void UPFServerRevokeInventoryItem::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->RevokeInventoryItem(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerRevokeInventoryItem::OnSuccessCallback(const PlayFab::ServerModels::FRevokeInventoryResult& Result)
{
    OnSuccess.Broadcast();
}
