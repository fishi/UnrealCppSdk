// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminResolvePurchaseDispute.h"

UPFAdminResolvePurchaseDispute::UPFAdminResolvePurchaseDispute(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FResolvePurchaseDisputeDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminResolvePurchaseDispute* UPFAdminResolvePurchaseDispute::ResolvePurchaseDispute(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InOrderId, const FString& InReason)
{
	UPFAdminResolvePurchaseDispute* Proxy = NewObject<UPFAdminResolvePurchaseDispute>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.OrderId = InOrderId;
	Proxy->Request.Reason = InReason;
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminResolvePurchaseDispute::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->ResolvePurchaseDispute(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminResolvePurchaseDisputeResponse BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminResolvePurchaseDispute::OnSuccessCallback(const PlayFab::AdminModels::FResolvePurchaseDisputeResponse& Result)
{
	FBPAdminResolvePurchaseDisputeResponse BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminResolvePurchaseDispute::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminResolvePurchaseDisputeResponse BPResult;
 	OnFailure.Broadcast(BPResult);	
}
