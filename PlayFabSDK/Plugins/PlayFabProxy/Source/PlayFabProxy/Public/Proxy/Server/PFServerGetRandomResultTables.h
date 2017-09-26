// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerGetRandomResultTables.generated.h"

UCLASS(MinimalAPI)
class UPFServerGetRandomResultTables : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerGetRandomResultTablesResultDelegate OnSuccess;

    // Retrieves the configuration information for the specified random results tables for the title, including all ItemId values and weights
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Player Item Management")
        static UPFServerGetRandomResultTables* GetRandomResultTables(class APlayerController* PlayerController, const FBPServerGetRandomResultTablesRequest& InGetRandomResultTablesRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerGetRandomResultTablesRequest Request;
    PlayFab::UPlayFabServerAPI::FGetRandomResultTablesDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FGetRandomResultTablesResult& Result);
};