// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGrantCharacterToUser.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGrantCharacterToUser::UPFClientGrantCharacterToUser(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGrantCharacterToUserDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGrantCharacterToUser* UPFClientGrantCharacterToUser::GrantCharacterToUser(class APlayerController* PlayerController, const FBPClientGrantCharacterToUserRequest& InGrantCharacterToUserRequest)
{
    UPFClientGrantCharacterToUser* Proxy = NewObject<UPFClientGrantCharacterToUser>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGrantCharacterToUserRequest;
    
    return Proxy;
}

void UPFClientGrantCharacterToUser::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GrantCharacterToUser(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientGrantCharacterToUser::OnSuccessCallback(const PlayFab::ClientModels::FGrantCharacterToUserResult& Result)
{
    FBPClientGrantCharacterToUserResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
