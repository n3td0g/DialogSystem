// Fill out your copyright notice in the Description page of Project Settings.

#include "Actions/ActionBaseComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "Actions/ActionBase.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UActionBaseComponent::UActionBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UActionBaseComponent::Execute()
{
	if (!bActionWithFade || FadeDuration <= 0.0f)
	{
		ExecuteAllActions();
		return;
	}

	if (APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0))
	{
		CameraManager->StartCameraFade(0.0f, 1.0f, FadeDuration, FadeColor);
	}

	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0))
	{
		PlayerController->SetInputMode(FInputModeUIOnly());
	}

	GetWorld()->GetTimerManager().SetTimer(ExecuteActionsTimer, this, &UActionBaseComponent::ExecuteAllActions, FadeDuration + 0.01f, false);
}

void UActionBaseComponent::ExecuteAllActions()
{
	for (UActionBase* Action : Actions)
	{
		if (IsValid(Action))
		{
			Action->Execute();
		}
	}

	if (bActionWithFade)
	{
		ExecuteActionsTimer.Invalidate();

		if (APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0))
		{
			CameraManager->StartCameraFade(1.0f, 0.0f, FadeDuration, FadeColor);
		}
		if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0))
		{
			PlayerController->SetInputMode(FInputModeGameOnly());
		}
	}
}

