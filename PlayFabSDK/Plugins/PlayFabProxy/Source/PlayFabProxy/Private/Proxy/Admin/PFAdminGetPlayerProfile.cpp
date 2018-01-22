// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetPlayerProfile.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetPlayerProfile::UPFAdminGetPlayerProfile(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetPlayerProfileDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetPlayerProfile* UPFAdminGetPlayerProfile::GetPlayerProfile(class APlayerController* PlayerController, const FBPAdminGetPlayerProfileRequest& InGetPlayerProfileRequest)
{
    UPFAdminGetPlayerProfile* Proxy = NewObject<UPFAdminGetPlayerProfile>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayerProfileRequest;
    
    return Proxy;
}

void UPFAdminGetPlayerProfile::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetPlayerProfile(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminGetPlayerProfile::OnSuccessCallback(const PlayFab::AdminModels::FGetPlayerProfileResult& Result)
{
    FBPAdminGetPlayerProfileResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
