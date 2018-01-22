// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerAddSharedGroupMembers.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerAddSharedGroupMembers::UPFServerAddSharedGroupMembers(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FAddSharedGroupMembersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerAddSharedGroupMembers* UPFServerAddSharedGroupMembers::AddSharedGroupMembers(class APlayerController* PlayerController, const FBPServerAddSharedGroupMembersRequest& InAddSharedGroupMembersRequest)
{
    UPFServerAddSharedGroupMembers* Proxy = NewObject<UPFServerAddSharedGroupMembers>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InAddSharedGroupMembersRequest;
    
    return Proxy;
}

void UPFServerAddSharedGroupMembers::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->AddSharedGroupMembers(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerAddSharedGroupMembers::OnSuccessCallback(const PlayFab::ServerModels::FAddSharedGroupMembersResult& Result)
{
    OnSuccess.Broadcast();
}
