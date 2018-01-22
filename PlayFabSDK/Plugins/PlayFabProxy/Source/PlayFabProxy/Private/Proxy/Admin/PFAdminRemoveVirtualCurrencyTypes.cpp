// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminRemoveVirtualCurrencyTypes.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminRemoveVirtualCurrencyTypes::UPFAdminRemoveVirtualCurrencyTypes(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FRemoveVirtualCurrencyTypesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminRemoveVirtualCurrencyTypes* UPFAdminRemoveVirtualCurrencyTypes::RemoveVirtualCurrencyTypes(class APlayerController* PlayerController, const FBPAdminRemoveVirtualCurrencyTypesRequest& InRemoveVirtualCurrencyTypesRequest)
{
    UPFAdminRemoveVirtualCurrencyTypes* Proxy = NewObject<UPFAdminRemoveVirtualCurrencyTypes>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRemoveVirtualCurrencyTypesRequest;
    
    return Proxy;
}

void UPFAdminRemoveVirtualCurrencyTypes::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->RemoveVirtualCurrencyTypes(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminRemoveVirtualCurrencyTypes::OnSuccessCallback(const PlayFab::AdminModels::FBlankResult& Result)
{
    OnSuccess.Broadcast();
}
