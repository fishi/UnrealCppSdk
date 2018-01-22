// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetLeaderboardAroundCharacter.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetLeaderboardAroundCharacter::UPFClientGetLeaderboardAroundCharacter(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetLeaderboardAroundCharacterDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetLeaderboardAroundCharacter* UPFClientGetLeaderboardAroundCharacter::GetLeaderboardAroundCharacter(class APlayerController* PlayerController, const FBPClientGetLeaderboardAroundCharacterRequest& InGetLeaderboardAroundCharacterRequest)
{
    UPFClientGetLeaderboardAroundCharacter* Proxy = NewObject<UPFClientGetLeaderboardAroundCharacter>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetLeaderboardAroundCharacterRequest;
    
    return Proxy;
}

void UPFClientGetLeaderboardAroundCharacter::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetLeaderboardAroundCharacter(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientGetLeaderboardAroundCharacter::OnSuccessCallback(const PlayFab::ClientModels::FGetLeaderboardAroundCharacterResult& Result)
{
    FBPClientGetLeaderboardAroundCharacterResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
