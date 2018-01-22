// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFMatchmakerStartGame.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFMatchmakerStartGame::UPFMatchmakerStartGame(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabMatchmakerAPI::FStartGameDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFMatchmakerStartGame* UPFMatchmakerStartGame::StartGame(class APlayerController* PlayerController, const FBPMatchmakerStartGameRequest& InStartGameRequest)
{
    UPFMatchmakerStartGame* Proxy = NewObject<UPFMatchmakerStartGame>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InStartGameRequest;
    
    return Proxy;
}

void UPFMatchmakerStartGame::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabMatchmakerPtr MatchmakerAPI = IPlayFabModuleInterface::Get().GetMatchmakerAPI();

    bool CallResult = false;

    if (MatchmakerAPI.IsValid())
    {
        CallResult = MatchmakerAPI->StartGame(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFMatchmakerStartGame::OnSuccessCallback(const PlayFab::MatchmakerModels::FStartGameResponse& Result)
{
    FBPMatchmakerStartGameResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
