// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionBaseComponent.generated.h"

class UActionBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType, EditInlineNew )
class DIALOGSYSTEMRUNTIME_API UActionBaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActionBaseComponent();

	UFUNCTION(BlueprintCallable)
	void Execute();

private:
	void ExecuteAllActions();

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Actions)
	bool bActionWithFade = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Actions, meta = (EditCondition = "bActionWithFade"))
	float FadeDuration = 0.25f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Actions, meta = (EditCondition = "bActionWithFade"))
	FLinearColor FadeColor = FLinearColor::Black;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Actions", Instanced)
	TArray<UActionBase*> Actions;

private:
	FTimerHandle ExecuteActionsTimer;
};
