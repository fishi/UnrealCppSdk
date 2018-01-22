// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetPaymentToken.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetPaymentToken::UPFClientGetPaymentToken(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPaymentTokenDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetPaymentToken* UPFClientGetPaymentToken::GetPaymentToken(class APlayerController* PlayerController, const FBPClientGetPaymentTokenRequest& InGetPaymentTokenRequest)
{
    UPFClientGetPaymentToken* Proxy = NewObject<UPFClientGetPaymentToken>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPaymentTokenRequest;
    
    return Proxy;
}

void UPFClientGetPaymentToken::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetPaymentToken(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientGetPaymentToken::OnSuccessCallback(const PlayFab::ClientModels::FGetPaymentTokenResult& Result)
{
    FBPClientGetPaymentTokenResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}