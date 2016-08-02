// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminRemoveVirtualCurrencyTypes.h"

UPFAdminRemoveVirtualCurrencyTypes::UPFAdminRemoveVirtualCurrencyTypes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FRemoveVirtualCurrencyTypesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminRemoveVirtualCurrencyTypes* UPFAdminRemoveVirtualCurrencyTypes::RemoveVirtualCurrencyTypes(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FBPAdminVirtualCurrencyData>& InVirtualCurrencies)
{
	UPFAdminRemoveVirtualCurrencyTypes* Proxy = NewObject<UPFAdminRemoveVirtualCurrencyTypes>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	for (const FBPAdminVirtualCurrencyData& elem : InVirtualCurrencies)
    {
        Proxy->Request.VirtualCurrencies.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminRemoveVirtualCurrencyTypes::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->RemoveVirtualCurrencyTypes(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminRemoveVirtualCurrencyTypes::OnSuccessCallback(const PlayFab::AdminModels::FBlankResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminRemoveVirtualCurrencyTypes::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}