// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientUpdateUserData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientUpdateUserData::UPFClientUpdateUserData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FUpdateUserDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientUpdateUserData* UPFClientUpdateUserData::UpdateUserData(class APlayerController* PlayerController, const FBPClientUpdateUserDataRequest& InUpdateUserDataRequest)
{
    UPFClientUpdateUserData* Proxy = NewObject<UPFClientUpdateUserData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateUserDataRequest;
    
    return Proxy;
}

void UPFClientUpdateUserData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->UpdateUserData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientUpdateUserData::OnSuccessCallback(const PlayFab::ClientModels::FUpdateUserDataResult& Result)
{
    FBPClientUpdateUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}