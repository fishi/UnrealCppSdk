// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerDeleteSharedGroup.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerDeleteSharedGroup::UPFServerDeleteSharedGroup(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FDeleteSharedGroupDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerDeleteSharedGroup* UPFServerDeleteSharedGroup::DeleteSharedGroup(class APlayerController* PlayerController, const FBPServerDeleteSharedGroupRequest& InDeleteSharedGroupRequest)
{
    UPFServerDeleteSharedGroup* Proxy = NewObject<UPFServerDeleteSharedGroup>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InDeleteSharedGroupRequest;
    
    return Proxy;
}

void UPFServerDeleteSharedGroup::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->DeleteSharedGroup(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerDeleteSharedGroup::OnSuccessCallback(const PlayFab::ServerModels::FEmptyResult& Result)
{
    OnSuccess.Broadcast();
}