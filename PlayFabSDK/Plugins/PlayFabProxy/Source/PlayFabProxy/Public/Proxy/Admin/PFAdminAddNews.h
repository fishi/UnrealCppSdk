// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminAddNews.generated.h"

UCLASS(MinimalAPI)
class UPFAdminAddNews : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminAddNewsResultDelegate OnSuccess;

    // Adds a new news item to the title's news feed
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Title-Wide Data Management")
        static UPFAdminAddNews* AddNews(class APlayerController* PlayerController, const FBPAdminAddNewsRequest& InAddNewsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminAddNewsRequest Request;
    PlayFab::UPlayFabAdminAPI::FAddNewsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FAddNewsResult& Result);
};