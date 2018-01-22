// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerModifyItemUses.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerModifyItemUses::UPFServerModifyItemUses(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FModifyItemUsesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerModifyItemUses* UPFServerModifyItemUses::ModifyItemUses(class APlayerController* PlayerController, const FBPServerModifyItemUsesRequest& InModifyItemUsesRequest)
{
    UPFServerModifyItemUses* Proxy = NewObject<UPFServerModifyItemUses>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InModifyItemUsesRequest;
    
    return Proxy;
}

void UPFServerModifyItemUses::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->ModifyItemUses(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerModifyItemUses::OnSuccessCallback(const PlayFab::ServerModels::FModifyItemUsesResult& Result)
{
    FBPServerModifyItemUsesResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
