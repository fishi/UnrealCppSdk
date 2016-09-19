// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerGetFriendLeaderboard.h"

UPFServerGetFriendLeaderboard::UPFServerGetFriendLeaderboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetFriendLeaderboardDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetFriendLeaderboard* UPFServerGetFriendLeaderboard::GetFriendLeaderboard(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InStatisticName, const int32& InStartPosition, const int32& InMaxResultsCount, const bool& InIncludeSteamFriends, const bool& InIncludeFacebookFriends)
{
	UPFServerGetFriendLeaderboard* Proxy = NewObject<UPFServerGetFriendLeaderboard>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.StatisticName = InStatisticName;
	Proxy->Request.StartPosition = InStartPosition;
	Proxy->Request.MaxResultsCount = InMaxResultsCount;
	Proxy->Request.IncludeSteamFriends = InIncludeSteamFriends;
	Proxy->Request.IncludeFacebookFriends = InIncludeFacebookFriends;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetFriendLeaderboard::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetFriendLeaderboard(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetLeaderboardResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetFriendLeaderboard::OnSuccessCallback(const PlayFab::ServerModels::FGetLeaderboardResult& Result)
{
	FBPServerGetLeaderboardResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetFriendLeaderboard::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetLeaderboardResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}