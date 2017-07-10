// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminUpdatePlayerSharedSecret.h"

UPFAdminUpdatePlayerSharedSecret::UPFAdminUpdatePlayerSharedSecret(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdatePlayerSharedSecretDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminUpdatePlayerSharedSecret* UPFAdminUpdatePlayerSharedSecret::UpdatePlayerSharedSecret(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InSecretKey, const FString& InFriendlyName, const bool& InDisabled)
{
	UPFAdminUpdatePlayerSharedSecret* Proxy = NewObject<UPFAdminUpdatePlayerSharedSecret>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.SecretKey = InSecretKey;
	Proxy->Request.FriendlyName = InFriendlyName;
	Proxy->Request.Disabled = InDisabled;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminUpdatePlayerSharedSecret::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->UpdatePlayerSharedSecret(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminUpdatePlayerSharedSecret::OnSuccessCallback(const PlayFab::AdminModels::FUpdatePlayerSharedSecretResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminUpdatePlayerSharedSecret::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
