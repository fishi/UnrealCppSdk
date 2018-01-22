// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminAddUserVirtualCurrency.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminAddUserVirtualCurrency::UPFAdminAddUserVirtualCurrency(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FAddUserVirtualCurrencyDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminAddUserVirtualCurrency* UPFAdminAddUserVirtualCurrency::AddUserVirtualCurrency(class APlayerController* PlayerController, const FBPAdminAddUserVirtualCurrencyRequest& InAddUserVirtualCurrencyRequest)
{
    UPFAdminAddUserVirtualCurrency* Proxy = NewObject<UPFAdminAddUserVirtualCurrency>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InAddUserVirtualCurrencyRequest;
    
    return Proxy;
}

void UPFAdminAddUserVirtualCurrency::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->AddUserVirtualCurrency(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminAddUserVirtualCurrency::OnSuccessCallback(const PlayFab::AdminModels::FModifyUserVirtualCurrencyResult& Result)
{
    FBPAdminModifyUserVirtualCurrencyResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
