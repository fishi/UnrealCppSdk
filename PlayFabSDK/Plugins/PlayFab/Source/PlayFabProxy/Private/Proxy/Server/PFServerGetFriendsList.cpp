// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerGetFriendsList.h"

UPFServerGetFriendsList::UPFServerGetFriendsList(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetFriendsListDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetFriendsList* UPFServerGetFriendsList::GetFriendsList(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const bool& InIncludeSteamFriends, const bool& InIncludeFacebookFriends)
{
	UPFServerGetFriendsList* Proxy = NewObject<UPFServerGetFriendsList>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.IncludeSteamFriends = InIncludeSteamFriends;
	Proxy->Request.IncludeFacebookFriends = InIncludeFacebookFriends;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetFriendsList::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetFriendsList(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetFriendsListResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetFriendsList::OnSuccessCallback(const PlayFab::ServerModels::FGetFriendsListResult& Result)
{
	FBPServerGetFriendsListResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetFriendsList::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetFriendsListResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
