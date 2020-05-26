// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActionBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class DIALOGSYSTEMRUNTIME_API UActionBase : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable)
    void Execute();

    UFUNCTION(BlueprintCallable)
    class AGameModeBase* GetGameMode();

    UFUNCTION(BlueprintPure, Category = "Gameplay|StoryKey")
    class UStoryKeyManager* GetStoryKeyManager();

protected:
    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnExecute"))
    void ReceiveExecute();
};
