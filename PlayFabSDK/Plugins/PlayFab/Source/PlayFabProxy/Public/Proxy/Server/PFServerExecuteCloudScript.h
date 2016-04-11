// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerExecuteCloudScript.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerExecuteCloudScript : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerExecuteCloudScriptResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerExecuteCloudScriptResultDelegate OnFailure;
	
	// Executes a CloudScript function, with the 'currentPlayerId' variable set to the specified PlayFabId parameter value.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Server-Side Cloud Script")
	static UPFServerExecuteCloudScript* ExecuteCloudScript(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InFunctionName, const int32& InSpecificRevision, const bool& InGeneratePlayStreamEvent);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FExecuteCloudScriptServerRequest Request;

	PlayFab::UPlayFabServerAPI::FExecuteCloudScriptDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FExecuteCloudScriptResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
