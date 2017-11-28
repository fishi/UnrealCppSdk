// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerSendEmailFromTemplate.generated.h"

UCLASS(MinimalAPI)
class UPFServerSendEmailFromTemplate : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Sends an email based on an email template to a player's contact email 
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Account Management")
        static UPFServerSendEmailFromTemplate* SendEmailFromTemplate(class APlayerController* PlayerController, const FBPServerSendEmailFromTemplateRequest& InSendEmailFromTemplateRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerSendEmailFromTemplateRequest Request;
    PlayFab::UPlayFabServerAPI::FSendEmailFromTemplateDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FSendEmailFromTemplateResult& Result);
};
