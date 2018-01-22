// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetAllUsersCharacters.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetAllUsersCharacters::UPFServerGetAllUsersCharacters(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetAllUsersCharactersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetAllUsersCharacters* UPFServerGetAllUsersCharacters::GetAllUsersCharacters(class APlayerController* PlayerController, const FBPServerListUsersCharactersRequest& InListUsersCharactersRequest)
{
    UPFServerGetAllUsersCharacters* Proxy = NewObject<UPFServerGetAllUsersCharacters>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InListUsersCharactersRequest;
    
    return Proxy;
}

void UPFServerGetAllUsersCharacters::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetAllUsersCharacters(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetAllUsersCharacters::OnSuccessCallback(const PlayFab::ServerModels::FListUsersCharactersResult& Result)
{
    FBPServerListUsersCharactersResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
