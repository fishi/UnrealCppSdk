// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminDeleteStore.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminDeleteStore::UPFAdminDeleteStore(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FDeleteStoreDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminDeleteStore* UPFAdminDeleteStore::DeleteStore(class APlayerController* PlayerController, const FBPAdminDeleteStoreRequest& InDeleteStoreRequest)
{
    UPFAdminDeleteStore* Proxy = NewObject<UPFAdminDeleteStore>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InDeleteStoreRequest;
    
    return Proxy;
}

void UPFAdminDeleteStore::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->DeleteStore(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminDeleteStore::OnSuccessCallback(const PlayFab::AdminModels::FDeleteStoreResult& Result)
{
    OnSuccess.Broadcast();
}