// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerSetGameServerInstanceData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerSetGameServerInstanceData::UPFServerSetGameServerInstanceData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FSetGameServerInstanceDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerSetGameServerInstanceData* UPFServerSetGameServerInstanceData::SetGameServerInstanceData(class APlayerController* PlayerController, const FBPServerSetGameServerInstanceDataRequest& InSetGameServerInstanceDataRequest)
{
    UPFServerSetGameServerInstanceData* Proxy = NewObject<UPFServerSetGameServerInstanceData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSetGameServerInstanceDataRequest;
    
    return Proxy;
}

void UPFServerSetGameServerInstanceData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->SetGameServerInstanceData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerSetGameServerInstanceData::OnSuccessCallback(const PlayFab::ServerModels::FSetGameServerInstanceDataResult& Result)
{
    OnSuccess.Broadcast();
}
