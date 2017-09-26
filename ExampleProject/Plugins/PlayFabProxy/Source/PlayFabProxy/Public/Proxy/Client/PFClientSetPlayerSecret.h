// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientSetPlayerSecret.generated.h"

UCLASS(MinimalAPI)
class UPFClientSetPlayerSecret : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Sets the player's secret if it is not already set. Player secrets are used to sign API requests. To reset a player's secret use the Admin or Server API method SetPlayerSecret.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Authentication")
        static UPFClientSetPlayerSecret* SetPlayerSecret(class APlayerController* PlayerController, const FBPClientSetPlayerSecretRequest& InSetPlayerSecretRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientSetPlayerSecretRequest Request;
    PlayFab::UPlayFabClientAPI::FSetPlayerSecretDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FSetPlayerSecretResult& Result);
};