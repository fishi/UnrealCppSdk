// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminRemoveServerBuild.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminRemoveServerBuild::UPFAdminRemoveServerBuild(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FRemoveServerBuildDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminRemoveServerBuild* UPFAdminRemoveServerBuild::RemoveServerBuild(class APlayerController* PlayerController, const FBPAdminRemoveServerBuildRequest& InRemoveServerBuildRequest)
{
    UPFAdminRemoveServerBuild* Proxy = NewObject<UPFAdminRemoveServerBuild>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRemoveServerBuildRequest;
    
    return Proxy;
}

void UPFAdminRemoveServerBuild::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->RemoveServerBuild(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminRemoveServerBuild::OnSuccessCallback(const PlayFab::AdminModels::FRemoveServerBuildResult& Result)
{
    OnSuccess.Broadcast();
}
