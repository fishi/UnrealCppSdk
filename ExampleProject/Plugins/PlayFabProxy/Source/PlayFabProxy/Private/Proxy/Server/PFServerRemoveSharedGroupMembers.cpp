// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerRemoveSharedGroupMembers.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerRemoveSharedGroupMembers::UPFServerRemoveSharedGroupMembers(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FRemoveSharedGroupMembersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerRemoveSharedGroupMembers* UPFServerRemoveSharedGroupMembers::RemoveSharedGroupMembers(class APlayerController* PlayerController, const FBPServerRemoveSharedGroupMembersRequest& InRemoveSharedGroupMembersRequest)
{
    UPFServerRemoveSharedGroupMembers* Proxy = NewObject<UPFServerRemoveSharedGroupMembers>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRemoveSharedGroupMembersRequest;
    
    return Proxy;
}

void UPFServerRemoveSharedGroupMembers::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->RemoveSharedGroupMembers(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerRemoveSharedGroupMembers::OnSuccessCallback(const PlayFab::ServerModels::FRemoveSharedGroupMembersResult& Result)
{
    OnSuccess.Broadcast();
}
