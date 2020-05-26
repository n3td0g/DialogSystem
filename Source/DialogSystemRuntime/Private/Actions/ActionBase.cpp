// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/ActionBase.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "StoryInformation/StoryInformationManager.h"

void UActionBase::Execute()
{
    ReceiveExecute();
}

AGameModeBase* UActionBase::GetGameMode()
{
    return UGameplayStatics::GetGameMode(this);
}

class UStoryKeyManager* UActionBase::GetStoryKeyManager()
{
    return UStoryKeyManager::GetStoryKeyManager(this);
}
