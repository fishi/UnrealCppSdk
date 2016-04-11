// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLoginWithGoogleAccount.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientLoginWithGoogleAccount : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnFailure;
	
	// Signs the user in using a Google account access token(https://developers.google.com/android/reference/com/google/android/gms/auth/GoogleAuthUtil#public-methods), returning a session identifier that can subsequently be used for API calls which require an authenticated user
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Authentication")
	static UPFClientLoginWithGoogleAccount* LoginWithGoogleAccount(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InTitleId, const FString& InAccessToken, const bool& InCreateAccount, const FString& InPublisherId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FLoginWithGoogleAccountRequest Request;

	PlayFab::UPlayFabClientAPI::FLoginWithGoogleAccountDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
