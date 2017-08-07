// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminDeletePlayer.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminDeletePlayer : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Removes a user's player account from a title and deletes all associated data
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Account Management")
	static UPFAdminDeletePlayer* DeletePlayer(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FDeletePlayerRequest Request;

	PlayFab::UPlayFabAdminAPI::FDeletePlayerDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FDeletePlayerResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
