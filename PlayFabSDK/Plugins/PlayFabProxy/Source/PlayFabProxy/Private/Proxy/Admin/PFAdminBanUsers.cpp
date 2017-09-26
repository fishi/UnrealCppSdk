// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminBanUsers.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminBanUsers::UPFAdminBanUsers(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FBanUsersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminBanUsers* UPFAdminBanUsers::BanUsers(class APlayerController* PlayerController, const FBPAdminBanUsersRequest& InBanUsersRequest)
{
    UPFAdminBanUsers* Proxy = NewObject<UPFAdminBanUsers>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InBanUsersRequest;
    
    return Proxy;
}

void UPFAdminBanUsers::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->BanUsers(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminBanUsers::OnSuccessCallback(const PlayFab::AdminModels::FBanUsersResult& Result)
{
    FBPAdminBanUsersResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}