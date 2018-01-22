// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminAbortTaskInstance.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminAbortTaskInstance::UPFAdminAbortTaskInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FAbortTaskInstanceDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminAbortTaskInstance* UPFAdminAbortTaskInstance::AbortTaskInstance(class APlayerController* PlayerController, const FBPAdminAbortTaskInstanceRequest& InAbortTaskInstanceRequest)
{
    UPFAdminAbortTaskInstance* Proxy = NewObject<UPFAdminAbortTaskInstance>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InAbortTaskInstanceRequest;
    
    return Proxy;
}

void UPFAdminAbortTaskInstance::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->AbortTaskInstance(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminAbortTaskInstance::OnSuccessCallback(const PlayFab::AdminModels::FEmptyResult& Result)
{
    OnSuccess.Broadcast();
}
