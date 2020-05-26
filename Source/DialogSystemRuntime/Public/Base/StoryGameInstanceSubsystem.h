// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "StoryGameInstanceSubsystem.generated.h"

class UStoryKeyManager;

/**
 * 
 */
UCLASS()
class DIALOGSYSTEMRUNTIME_API UStoryGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
    /** Implement this for initialization of instances of the system */
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
    UStoryKeyManager* GetStoryKeyManager() const;

protected:
    UPROPERTY(BlueprintReadOnly)
    UStoryKeyManager* StoryKeyManager;
};
