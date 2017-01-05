Unreal C++ Getting Started Guide
----

This guide will help you make your first API call in Unreal, using the PlayFab C++ SDK.

Unreal Project Setup
----

* OS: This guide is written for Windows 10, however steps should be similar for Mac
* This guide is created using Visual Studio 2015, and Unreal Engine 4.13
  * Unreal 4.9 requires Visual Studio 2013 (not 2015), but otherwise the steps are nearly identical
* Download Unreal Engine
  * Register and log in on the Unreal website
    * https://accounts.unrealengine.com/login/index
  * Download the Epic Games Launcher
    * https://www.unrealengine.com/dashboard
    * Open Epic Games Launcher
      * Select the "Unreal Engine" tab, and "Library" from the left-navigation-bar
      * Click "+Add Versions"
      * Select from versions: 4.9, 4.12, or 4.13 and install
        * These are the tested versions, other versions between, or after, are likely to work but not guaranteed
      * Click the "Launch" button, and run Unreal Engine
      * Select all the optons as seen here:
        * New Project tab, C++ sub-tab, No Starter Content
        * Remember your path - referenced as {UeCppLocation} for the rest of this guide
        * ![Unreal image](/images/Unreal/NewProjectCpp.png)
      * This will launch an Unreal Editor window, and Visual Studio
        * Stop, and close everything
* Install the PlayFab Plugin into your project
  * Download and extract the PlayFab UnrealCppSdk - Extracted location referenced as {PlayFabSdkLocation} for the rest of this guide
    * https://api.playfab.com/sdks/download/cpp-ue4
  * Open two windows explorer folders, {UeCppLocation} and {PlayFabSdkLocation}
    * In {UeCppLocation}, create a new subfolder called "Plugins", and open it
    * In {PlayFabSdkLocation}, navigate to the {PlayFabSdkLocation}/PlayFabSDK/Plugins subfolder
    * Select the "PlayFab" folder from {PlayFabSdkLocation}/PlayFabSDK/Plugins and copy it into {UeCppLocation}/Plugins
    * Navigate back up to {UeCppLocation}, and right-click your "GettingStartedUeCpp.uproject" (your .uproject file name will match your project name from earlier)
    * Select "Generate Visual Studio project files"
    * When the popup completes, re-open GettingStartedUeCpp.sln in Visual Studio
    * ![Unreal image](/images/Unreal/GenVsProjCpp.png)
* Run Unreal, Create a new actor, and place it in the scene
  * We are using an actor to trigger an API call - You can make API calls from any C++ code
  * From Visual Studio, Run Unreal Engine (Debug -> Start Debugging)
  * Create a new actor (This screenshot shows multiple sequential popups, you won't see all of this at once):
  * ![Unreal image](/images/Unreal/NewActorCpp.png)
  * Place the actor in the scene
  * ![Unreal image](/images/Unreal/PlaceActor.png)
  * Once again, stop and close Unreal (Keep Visual Studio open)
    * We need to modify LoginActor in Visual Studio in the next section
* PlayFab Installation Complete!

Set up your first API call
----

This guide will provide the minimum steps to make your first PlayFab API call. Confirmation will be done via a debug print in the Output Log.

* Update the contents of {UeCppLocation}/Source/GettingStartedUeCpp/GettingStartedUeCpp.Build.cs
  * Find a line that starts with: PublicDependencyModuleNames, It will look something like this:
    * PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
  * Add "PlayFab" to this list:
    * PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "PlayFab" });
  * Save and close the file
* Navigate to the LoginActor.h and LoginActor.h files created in the previous section
  * They are most likely located here: 
    * {UeCppLocation}/Source/GettingStartedUeCpp/Private/LoginActor.h
    * {UeCppLocation}/Source/GettingStartedUeCpp/Private/LoginActor.cpp
* Replace the contents of LoginActor.h with the following:

```C++
#pragma once

#include "GameFramework/Actor.h"

#include "PlayFab.h"
#include "Core/PlayFabClientDataModels.h"
#include "Core/PlayFabClientAPI.h"

#include "LoginActor.generated.h"

UCLASS()
class ALoginActor : public AActor
{
	GENERATED_BODY()
public:	
	ALoginActor();
	virtual void BeginPlay() override;
    void OnSuccess(const PlayFab::ClientModels::FLoginResult& Result) const;
    void OnError(const PlayFab::FPlayFabError& ErrorResult) const;

    virtual void Tick( float DeltaSeconds ) override;
private:
    PlayFabClientPtr clientAPI = nullptr;
};
```

* And Replace the contents of LoginActor.cpp with the following:

```C++
#include "GettingStartedUeCpp.h"
#include "LoginActor.h"

ALoginActor::ALoginActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ALoginActor::BeginPlay()
{
	Super::BeginPlay();
	
    clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
    clientAPI->SetTitleId(TEXT("144"));

    PlayFab::ClientModels::FLoginWithCustomIDRequest request;
    request.CustomId = TEXT("GettingStartedGuide");
    request.CreateAccount = true;

    clientAPI->LoginWithCustomID(request,
        PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateUObject(this, &ALoginActor::OnSuccess),
        PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ALoginActor::OnError)
    );
}

void ALoginActor::OnSuccess(const PlayFab::ClientModels::FLoginResult& Result) const
{
    UE_LOG(LogTemp, Log, TEXT("Congratulations, you made your first successful API call!"));
}

void ALoginActor::OnError(const PlayFab::FPlayFabError& ErrorResult) const
{
    UE_LOG(LogTemp, Error, TEXT("Something went wrong with your first API call.\nHere's some debug information:\n%s"), *ErrorResult.GenerateErrorReport());
}

void ALoginActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
```

* Run the Unreal Editor (Debug -> Start Debugging)


Finish and Execute
----

* Earlier, you created a level with a LoginActor entity already placed in the world
  * Load this level
* Press Play
  * You will immediately see the following in the output log:
  * LogTemp: Congratulations, you made your first successful API call!
* Done! Press any key to close

Deconstruct the code
----

This optional last section describes the code in this project line by line.

* GettingStartedUeCpp.Build.cs
  * To reference code from a plugin in your project, you have to add the plugin to your code dependencies. The Unreal build tools do all the work, if you add the "PlayFab" string to your plugins
* LoginActor.H
  * includes
    * The LoginActor includes are default includes that exist for the template file before we modified it
    * The PlayFab includes are neccessary to make PlayFab API calls
  * UCLASS ALoginActor
    * Most of this file is the default template for a new actor; the only exceptions to this are:
  * OnSuccess and OnError
    * These are the asynchronous callbacks that will be invoked after PlayFab LoginWithCustomID completes
  * PlayFabClientPtr clientAPI
    * This is an object that lets you access the PlayFab client API
* LoginActor.cpp
  * Most of this file is the default template for a new actor; the only exceptions to this are:
  * clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
    * This fetches the clientAPI object from the PlayFab plugin, so you can make API calls with it
  * clientAPI->SetTitleId(TEXT("xxxx"));
    * Every PlayFab developer creates a title in Game Manager. When you publish your game, you must code that titleId into your game. This lets the client know how to access the correct data within PlayFab. For most users, just consider it a mandatory step that makes PlayFab work.
  * PlayFab::ClientModels::FLoginWithCustomIDRequest request;
    * Most PlayFab API methods require input parameters, and those input parameters are packed into a request object
    * Every API method requires a unique request object, with a mix of optional and mandatory parameters
      * For LoginWithCustomIDRequest, there is a mandatory parameter of CustomId, which uniquely identifies a player and CreateAccount, which allows the creation of a new account with this call.
  * clientAPI->LoginWithCustomID(request, {OnSuccess delegate}, {OnFail delegate});
    * This begins the async request to "LoginWithCustomID", which will call LoginCallback when the API call is complete
    * For login, most developers will want to use a more appropriate login method
      * See the [PlayFab Login Documentation](https://api.playfab.com/Documentation/Client#Authentication) for a list of all login methods, and input parameters.  Common choices are:
        * [LoginWithAndroidDeviceID](https://api.playfab.com/Documentation/Client/method/LoginWithAndroidDeviceID)
        * [LoginWithIOSDeviceID](https://api.playfab.com/Documentation/Client/method/LoginWithIOSDeviceID)
        * [LoginWithEmailAddress](https://api.playfab.com/Documentation/Client/method/LoginWithEmailAddress)
  * {OnSuccess delegate}: PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateUObject(this, &ALoginActor::OnSuccess)
    * combined with: void ALoginActor::OnSuccess(const PlayFab::ClientModels::FLoginResult& Result) const
    * These create a UObject callback/delegate which is called if your API call is successful
    * An API Result object will contain the requested information, according to the API called
      * FLoginResult contains some basic information about the player, but for most users, login is simply a mandatory step before calling other APIs.
  * {OnFail delegate} PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ALoginActor::OnError)
    * combined with: void ALoginActor::OnError(const PlayFab::FPlayFabError& ErrorResult) const
    * API calls can fail for many reasons, and you should always attempt to handle failure
    * Why API calls fail (In order of likelihood)
      * PlayFabSettings.TitleId is not set.  If you forget to set titleId to your title, then nothing will work.
      * Request parameters.  If you have not provided the correct or required information for a particular API call, then it will fail.  See error.errorMessage, error.errorDetails, or error.GenerateErrorReport() for more info.
      * Device connectivity issue.  Cell-phones lose/regain connectivity constantly, and so any API call at any time can fail randomly, and then work immediately after.  Going into a tunnel can disconnect you completely.
      * PlayFab server issue.  As with all software, there can be issues.  See our [release notes](https://api.playfab.com/releaseNotes/) for updates.
      * The internet is not 100% reliable.  Sometimes the message is corrupted or fails to reach the PlayFab server.
    * If you are having difficulty debugging an issue, and the information within the error information is not sufficient, please visit us on our [forums](https://community.playfab.com/index.html)
