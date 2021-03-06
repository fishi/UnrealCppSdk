// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminRevokeBans.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminRevokeBans::UPFAdminRevokeBans(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FRevokeBansDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminRevokeBans* UPFAdminRevokeBans::RevokeBans(class APlayerController* PlayerController, const FBPAdminRevokeBansRequest& InRevokeBansRequest)
{
    UPFAdminRevokeBans* Proxy = NewObject<UPFAdminRevokeBans>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRevokeBansRequest;
    
    return Proxy;
}

void UPFAdminRevokeBans::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->RevokeBans(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminRevokeBans::OnSuccessCallback(const PlayFab::AdminModels::FRevokeBansResult& Result)
{
    FBPAdminRevokeBansResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
