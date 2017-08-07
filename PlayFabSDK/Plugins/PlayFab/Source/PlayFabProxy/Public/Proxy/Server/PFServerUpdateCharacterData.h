// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerUpdateCharacterData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerUpdateCharacterData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerUpdateCharacterDataResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerUpdateCharacterDataResultDelegate OnFailure;
	
	// Updates the title-specific custom data for the user's character which is readable and writable by the client
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Character Data")
	static UPFServerUpdateCharacterData* UpdateCharacterData(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InCharacterId, const FString& InData, const TArray<FString>& InKeysToRemove);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FUpdateCharacterDataRequest Request;

	PlayFab::UPlayFabServerAPI::FUpdateCharacterDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FUpdateCharacterDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
