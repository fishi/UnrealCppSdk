// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetUserReadOnlyData.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetUserReadOnlyData : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetUserDataResultDelegate OnSuccess;

    // Retrieves the title-specific custom data for the user which can only be read by the client
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Player Data Management")
        static UPFAdminGetUserReadOnlyData* GetUserReadOnlyData(class APlayerController* PlayerController, const FBPAdminGetUserDataRequest& InGetUserDataRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetUserDataRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetUserReadOnlyDataDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetUserDataResult& Result);
};