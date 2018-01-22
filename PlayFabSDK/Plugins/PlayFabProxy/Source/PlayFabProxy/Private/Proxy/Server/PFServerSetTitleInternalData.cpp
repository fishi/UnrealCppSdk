// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerSetTitleInternalData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerSetTitleInternalData::UPFServerSetTitleInternalData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FSetTitleInternalDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerSetTitleInternalData* UPFServerSetTitleInternalData::SetTitleInternalData(class APlayerController* PlayerController, const FBPServerSetTitleDataRequest& InSetTitleDataRequest)
{
    UPFServerSetTitleInternalData* Proxy = NewObject<UPFServerSetTitleInternalData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSetTitleDataRequest;
    
    return Proxy;
}

void UPFServerSetTitleInternalData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->SetTitleInternalData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerSetTitleInternalData::OnSuccessCallback(const PlayFab::ServerModels::FSetTitleDataResult& Result)
{
    OnSuccess.Broadcast();
}
