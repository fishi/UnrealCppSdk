// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetUserBans.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetUserBans : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetUserBansResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetUserBansResultDelegate OnFailure;
	
	// Gets all bans for a user.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Account Management")
	static UPFAdminGetUserBans* GetUserBans(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetUserBansRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetUserBansDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetUserBansResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
