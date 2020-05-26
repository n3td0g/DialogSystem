// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Dialog/DialogPhrase.h"
#include "DialogBaseWidget.generated.h"

USTRUCT(BlueprintType)
struct FWidgetPhraseShortInfo
{
    GENERATED_BODY()
public:
    FWidgetPhraseShortInfo() {}
    FWidgetPhraseShortInfo(const FText& InPhraseText, const FName& InID)
    {
        PhraseText = InPhraseText;
        PhraseID = InID;
    }

    UPROPERTY(BlueprintReadOnly)
    FText PhraseText;

    UPROPERTY(BlueprintReadOnly)
    FName PhraseID;
};

/**
 * 
 */
UCLASS(Blueprintable)
class DIALOGSYSTEMRUNTIME_API UDialogBaseWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable)
    void StartDialog(class UDialogAsset* DialogAsset, AActor* NPC);

    UFUNCTION(BlueprintCallable)
    void PlayerPhraseSelect(const FName& SelectedPhraseID);

    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnChangePhraseVariant"))
    void ReceiveOnChangePhraseVariant(const TArray<FWidgetPhraseShortInfo> &Phrases);

    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnPlayerPhraseChanged"))
    void ReceiveOnShowPlayerPhrase(const FText& PlayerText);

    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnNPCPhraseChanged"))
    void ReceiveOnShowNPCPhrase(const FText& PlayerText);

    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnDialogEnded"))
    void ReceiveOnDialogEnded();

protected:
    UFUNCTION()
    void OnDialogEnded();

    UFUNCTION()
    void OnShowPlayerPhrase(FDialogPhraseInfo Phrase);

    UFUNCTION()
    void OnShowNPCPhrase(FDialogPhraseInfo Phrase);

    UFUNCTION()
    void OnChangePhraseVariant(const TArray<FDialogPhraseShortInfo>& Variants);

private:
    UPROPERTY()
    class UDialogProcessor* DialogProcessor;
};
