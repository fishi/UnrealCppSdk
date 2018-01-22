// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientUpdateUserPublisherData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientUpdateUserPublisherData::UPFClientUpdateUserPublisherData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FUpdateUserPublisherDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientUpdateUserPublisherData* UPFClientUpdateUserPublisherData::UpdateUserPublisherData(class APlayerController* PlayerController, const FBPClientUpdateUserDataRequest& InUpdateUserDataRequest)
{
    UPFClientUpdateUserPublisherData* Proxy = NewObject<UPFClientUpdateUserPublisherData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateUserDataRequest;
    
    return Proxy;
}

void UPFClientUpdateUserPublisherData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->UpdateUserPublisherData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientUpdateUserPublisherData::OnSuccessCallback(const PlayFab::ClientModels::FUpdateUserDataResult& Result)
{
    FBPClientUpdateUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
