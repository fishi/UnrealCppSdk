// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientAttributeInstall.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientAttributeInstall : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Attributes an install for advertisment.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Advertising")
	static UPFClientAttributeInstall* AttributeInstall(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InIdfa, const FString& InAndroid_Id, const FString& InAdid);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FAttributeInstallRequest Request;

	PlayFab::UPlayFabClientAPI::FAttributeInstallDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FAttributeInstallResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
