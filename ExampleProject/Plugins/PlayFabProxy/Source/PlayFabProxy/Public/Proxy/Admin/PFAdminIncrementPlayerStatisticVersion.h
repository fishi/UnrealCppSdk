// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminIncrementPlayerStatisticVersion.generated.h"

UCLASS(MinimalAPI)
class UPFAdminIncrementPlayerStatisticVersion : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminIncrementPlayerStatisticVersionResultDelegate OnSuccess;

    // Resets the indicated statistic, removing all player entries for it and backing up the old values.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Player Data Management")
        static UPFAdminIncrementPlayerStatisticVersion* IncrementPlayerStatisticVersion(class APlayerController* PlayerController, const FBPAdminIncrementPlayerStatisticVersionRequest& InIncrementPlayerStatisticVersionRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminIncrementPlayerStatisticVersionRequest Request;
    PlayFab::UPlayFabAdminAPI::FIncrementPlayerStatisticVersionDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FIncrementPlayerStatisticVersionResult& Result);
};
