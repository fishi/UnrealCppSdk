// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetLeaderboardAroundPlayer.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetLeaderboardAroundPlayer::UPFClientGetLeaderboardAroundPlayer(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetLeaderboardAroundPlayerDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetLeaderboardAroundPlayer* UPFClientGetLeaderboardAroundPlayer::GetLeaderboardAroundPlayer(class APlayerController* PlayerController, const FBPClientGetLeaderboardAroundPlayerRequest& InGetLeaderboardAroundPlayerRequest)
{
    UPFClientGetLeaderboardAroundPlayer* Proxy = NewObject<UPFClientGetLeaderboardAroundPlayer>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetLeaderboardAroundPlayerRequest;
    
    return Proxy;
}

void UPFClientGetLeaderboardAroundPlayer::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetLeaderboardAroundPlayer(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientGetLeaderboardAroundPlayer::OnSuccessCallback(const PlayFab::ClientModels::FGetLeaderboardAroundPlayerResult& Result)
{
    FBPClientGetLeaderboardAroundPlayerResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
