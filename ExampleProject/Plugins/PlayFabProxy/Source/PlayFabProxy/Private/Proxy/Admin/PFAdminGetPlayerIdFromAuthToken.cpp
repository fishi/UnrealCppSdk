// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetPlayerIdFromAuthToken.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetPlayerIdFromAuthToken::UPFAdminGetPlayerIdFromAuthToken(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetPlayerIdFromAuthTokenDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetPlayerIdFromAuthToken* UPFAdminGetPlayerIdFromAuthToken::GetPlayerIdFromAuthToken(class APlayerController* PlayerController, const FBPAdminGetPlayerIdFromAuthTokenRequest& InGetPlayerIdFromAuthTokenRequest)
{
    UPFAdminGetPlayerIdFromAuthToken* Proxy = NewObject<UPFAdminGetPlayerIdFromAuthToken>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayerIdFromAuthTokenRequest;
    
    return Proxy;
}

void UPFAdminGetPlayerIdFromAuthToken::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetPlayerIdFromAuthToken(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminGetPlayerIdFromAuthToken::OnSuccessCallback(const PlayFab::AdminModels::FGetPlayerIdFromAuthTokenResult& Result)
{
    FBPAdminGetPlayerIdFromAuthTokenResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
