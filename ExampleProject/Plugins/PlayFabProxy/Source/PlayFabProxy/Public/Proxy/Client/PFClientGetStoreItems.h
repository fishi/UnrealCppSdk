// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetStoreItems.generated.h"

UCLASS(MinimalAPI)
class UPFClientGetStoreItems : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientGetStoreItemsResultDelegate OnSuccess;

    // Retrieves the set of items defined for the specified store, including all prices defined
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Title-Wide Data Management")
        static UPFClientGetStoreItems* GetStoreItems(class APlayerController* PlayerController, const FBPClientGetStoreItemsRequest& InGetStoreItemsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientGetStoreItemsRequest Request;
    PlayFab::UPlayFabClientAPI::FGetStoreItemsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FGetStoreItemsResult& Result);
};
