#pragma once

#include "DialogNode.generated.h"

class UDialogProcessor;
class UDialogPhraseNode;
class UDialogAsset;

UCLASS()
class DIALOGSYSTEMRUNTIME_API UDialogNode : public UObject
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TArray<UDialogNode*> Childs;

	UPROPERTY()
	UDialogAsset* OwnerDialog;

	virtual void Invoke(UDialogProcessor* processor);
	virtual bool Check(UDialogProcessor* processor);
	virtual TArray<UDialogPhraseNode*> GetNextPhrases(UDialogProcessor* processor);
};
