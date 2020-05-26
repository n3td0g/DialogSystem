#include "Dialog/DialogNodes/DialogSubGraphNode.h"
#include "Dialog/DialogProcessor.h"
#include "Dialog/DialogNodes/DialogPhraseNode.h"
#include "DialogSystemRuntime.h"
#include "Dialog/DialogAsset.h"


void UDialogSubGraphNode::Invoke(UDialogProcessor* processor)
{
	check(processor);

	if (TargetDialog == NULL)
		TargetDialog = TargetDialogAsset.Get();

	if (TargetDialog == NULL)
	{
		UE_LOG(DialogModuleLog, Error, TEXT("Sub dialog is empty in dialog %s"), *processor->Asset->GetPathName());
		return;
	}

	if (TargetDialog->RootNode == NULL)
	{
		UE_LOG(DialogModuleLog, Error, TEXT("Sub dialog %s have not root node"), *TargetDialog->GetPathName());
		return;
	}

	processor->SetDialogAsset(TargetDialog);
	processor->SetCurrentNode(TargetDialog->RootNode);
}

bool UDialogSubGraphNode::Check(UDialogProcessor* processor)
{
	return true;
}

TArray<UDialogPhraseNode*> UDialogSubGraphNode::GetNextPhrases(UDialogProcessor* processor)
{
	check(processor);

	TArray<UDialogPhraseNode*> result;

	if (TargetDialog == NULL)		
		TargetDialog = TargetDialogAsset.LoadSynchronous();

	if (TargetDialog != NULL && TargetDialog->RootNode != NULL)
	{
		auto next = TargetDialog->RootNode->GetNextPhrases(processor);
		result.Append(next);
	}

    return result;
}
