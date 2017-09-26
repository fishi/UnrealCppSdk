// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientRegisterWithWindowsHello.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientRegisterWithWindowsHello::UPFClientRegisterWithWindowsHello(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FRegisterWithWindowsHelloDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientRegisterWithWindowsHello* UPFClientRegisterWithWindowsHello::RegisterWithWindowsHello(class APlayerController* PlayerController, const FBPClientRegisterWithWindowsHelloRequest& InRegisterWithWindowsHelloRequest)
{
    UPFClientRegisterWithWindowsHello* Proxy = NewObject<UPFClientRegisterWithWindowsHello>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRegisterWithWindowsHelloRequest;
    
    return Proxy;
}

void UPFClientRegisterWithWindowsHello::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->RegisterWithWindowsHello(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientRegisterWithWindowsHello::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
    FBPClientLoginResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}