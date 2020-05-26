// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/StoryGameInstanceSubsystem.h"
#include "StoryInformation/StoryInformationManager.h"

void UStoryGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    StoryKeyManager = UStoryKeyManager::GetStoryKeyManager(this);
}

UStoryKeyManager* UStoryGameInstanceSubsystem::GetStoryKeyManager() const
{
    return StoryKeyManager;
}