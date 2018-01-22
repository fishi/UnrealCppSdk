// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerSetTitleData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerSetTitleData::UPFServerSetTitleData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FSetTitleDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerSetTitleData* UPFServerSetTitleData::SetTitleData(class APlayerController* PlayerController, const FBPServerSetTitleDataRequest& InSetTitleDataRequest)
{
    UPFServerSetTitleData* Proxy = NewObject<UPFServerSetTitleData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSetTitleDataRequest;
    
    return Proxy;
}

void UPFServerSetTitleData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->SetTitleData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerSetTitleData::OnSuccessCallback(const PlayFab::ServerModels::FSetTitleDataResult& Result)
{
    OnSuccess.Broadcast();
}
