// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminCreatePlayerSharedSecret.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminCreatePlayerSharedSecret : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminCreatePlayerSharedSecretResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminCreatePlayerSharedSecretResultDelegate OnFailure;
	
	// Creates a new Player Shared Secret Key. It may take up to 5 minutes for this key to become generally available after this API returns.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Authentication")
	static UPFAdminCreatePlayerSharedSecret* CreatePlayerSharedSecret(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InFriendlyName);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FCreatePlayerSharedSecretRequest Request;

	PlayFab::UPlayFabAdminAPI::FCreatePlayerSharedSecretDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FCreatePlayerSharedSecretResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
