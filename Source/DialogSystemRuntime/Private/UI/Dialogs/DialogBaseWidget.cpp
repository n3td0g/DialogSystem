// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Dialogs/DialogBaseWidget.h"
#include "Dialog/DialogAsset.h"
#include "Dialog/DialogProcessor.h"

void UDialogBaseWidget::StartDialog(class UDialogAsset* DialogAsset, AActor* NPC)
{
    if (!IsValid(DialogAsset))
    {
        return;
    }
    DialogProcessor = UDialogProcessor::CreateDialogProcessor(DialogAsset, NPC);

    if (IsValid(DialogProcessor))
    {
        DialogProcessor->OnChangePhraseVariant.AddDynamic(this, &UDialogBaseWidget::OnChangePhraseVariant);
        DialogProcessor->OnEndDialog.AddDynamic(this, &UDialogBaseWidget::OnDialogEnded);
        DialogProcessor->OnShowPlayerPhrase.AddDynamic(this, &UDialogBaseWidget::OnShowPlayerPhrase);
        DialogProcessor->OnShowNPCPhrase.AddDynamic(this, &UDialogBaseWidget::OnShowNPCPhrase);

        DialogProcessor->StartDialog();
    }
}

void UDialogBaseWidget::PlayerPhraseSelect(const FName& SelectedPhraseID)
{
    if (IsValid(DialogProcessor))
    {
        DialogProcessor->Next(SelectedPhraseID);
    }
}

void UDialogBaseWidget::OnDialogEnded()
{
    ReceiveOnDialogEnded();
}

void UDialogBaseWidget::OnShowPlayerPhrase(FDialogPhraseInfo Phrase)
{
    ReceiveOnShowPlayerPhrase(Phrase.Text);
}

void UDialogBaseWidget::OnShowNPCPhrase(FDialogPhraseInfo Phrase)
{
    ReceiveOnShowNPCPhrase(Phrase.Text);
}

void UDialogBaseWidget::OnChangePhraseVariant(const TArray<FDialogPhraseShortInfo>& Variants)
{
    TArray<FWidgetPhraseShortInfo> Phrases;
    for (const auto& Variant : Variants)
    {
        Phrases.Add(FWidgetPhraseShortInfo(Variant.Text, Variant.UID));
    }
    ReceiveOnChangePhraseVariant(Phrases);
}
