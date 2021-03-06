// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerUpdateSharedGroupData.generated.h"

UCLASS(MinimalAPI)
class UPFServerUpdateSharedGroupData : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group (and the server) can update the data.  Shared Groups are designed for sharing data between a very small number of players, please see our guide:  https://api.playfab.com/docs/tutorials/landing-players/shared-groups
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Shared Group Data")
        static UPFServerUpdateSharedGroupData* UpdateSharedGroupData(class APlayerController* PlayerController, const FBPServerUpdateSharedGroupDataRequest& InUpdateSharedGroupDataRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerUpdateSharedGroupDataRequest Request;
    PlayFab::UPlayFabServerAPI::FUpdateSharedGroupDataDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FUpdateSharedGroupDataResult& Result);
};
