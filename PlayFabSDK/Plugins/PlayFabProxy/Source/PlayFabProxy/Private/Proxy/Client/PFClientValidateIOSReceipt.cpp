// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientValidateIOSReceipt.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientValidateIOSReceipt::UPFClientValidateIOSReceipt(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FValidateIOSReceiptDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientValidateIOSReceipt* UPFClientValidateIOSReceipt::ValidateIOSReceipt(class APlayerController* PlayerController, const FBPClientValidateIOSReceiptRequest& InValidateIOSReceiptRequest)
{
    UPFClientValidateIOSReceipt* Proxy = NewObject<UPFClientValidateIOSReceipt>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InValidateIOSReceiptRequest;
    
    return Proxy;
}

void UPFClientValidateIOSReceipt::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->ValidateIOSReceipt(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientValidateIOSReceipt::OnSuccessCallback(const PlayFab::ClientModels::FValidateIOSReceiptResult& Result)
{
    OnSuccess.Broadcast();
}
