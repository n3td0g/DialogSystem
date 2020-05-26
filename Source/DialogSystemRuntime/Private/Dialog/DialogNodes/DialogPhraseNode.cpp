#include "Dialog/DialogNodes/DialogPhraseNode.h"
#include "Dialog/DialogProcessor.h"
#include "Dialog/DialogPhrase.h"
#include "Quest/QuestProcessor.h"
#include "StoryInformation/StoryInformationManager.h"

void UDialogPhraseNode::Invoke(UDialogProcessor* processor)
{
	check(processor);

	for (auto key : Data.GiveKeys)
		processor->StoryKeyManager->AddKey(key);

	for (auto key : Data.RemoveKeys)
		processor->StoryKeyManager->RemoveKey(key);

	for (auto& Event : Data.Action)
		Event.Invoke(processor);
	
	if (!Data.StartQuest.ToSoftObjectPath().IsNull())
	{
		UQuestProcessor::GetQuestProcessor(processor)->StartQuest(Data.StartQuest.ToSoftObjectPath().TryLoad());
	}
	
	if (Data.Source == EDialogPhraseSource::Player)
	{
		processor->OnShowPlayerPhrase.Broadcast(Data);
	}
	else
	{
		processor->OnShowNPCPhrase.Broadcast(Data);
	}

	if (processor->IsPlayerNext)
	{
		TArray<FDialogPhraseShortInfo> playerPhrases;

		for (auto nextNode : processor->NextNodes)
		{
			FDialogPhraseShortInfo answerInfo;
			answerInfo.Text = nextNode->Data.Text;
			answerInfo.UID = nextNode->Data.UID;

			playerPhrases.Add(answerInfo);
		}

		processor->OnChangePhraseVariant.Broadcast(playerPhrases);
	}
	else
	{
		processor->DelayNext();
	}
}

bool UDialogPhraseNode::Check(UDialogProcessor* processor)
{
	check(processor);

	for (auto key : Data.CheckHasKeys)
	{
		if (processor->StoryKeyManager->DontHasKey(key))
			return false;
	}

	for (auto key : Data.CheckDontHasKeys)
	{
		if (processor->StoryKeyManager->HasKey(key))
			return false;
	}

	for (auto& Conditions : Data.Predicate)
	{
		if (!Conditions.InvokeCheck(processor))
			return false;
	}

	return true;
}

TArray<UDialogPhraseNode*> UDialogPhraseNode::GetNextPhrases(UDialogProcessor* processor)
{
	TArray<UDialogPhraseNode*> result;
	result.Add(this);

    return result;
}
