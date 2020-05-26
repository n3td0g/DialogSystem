#pragma once

#include "EdGraph/EdGraphNode.h"
#include "Quest/QuestStageEvent.h"
#include "Quest/QuestNode.h"
#include "QaDSEditor/XmlSerealizeHelper.h"
#include "QaDSEditor/QaDSEdGraphNode.h"
#include "QuestEditorNodes.generated.h"

class UEdGraphPin;
class FXmlNode;

FORCEINLINE void operator<<(FXmlWriteNode& node, const FXmlWriteTuple<FQuestStageEvent>& tuple);
FORCEINLINE void operator<<(FXmlWriteNode& node, const FXmlWriteTuple<FQuestStageCondition>& tuple);
FORCEINLINE void operator<<(FXmlWriteNode& node, const FXmlWriteTuple<FStoryTriggerCondition>& tuple);
FORCEINLINE void operator>>(const FXmlReadNode& node, FQuestStageEvent& value);
FORCEINLINE void operator>>(const FXmlReadNode& node, FQuestStageCondition& value);
FORCEINLINE void operator>>(const FXmlReadNode& node, FStoryTriggerCondition& value);

UCLASS()
class DIALOGSYSTEMEDITOR_API UQuestStageEdGraphNode : public UQaDSEdGraphNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FQuestStageInfo Stage;

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void AllocateDefaultPins() override;
	virtual FXmlWriteNode SaveToXml() const;
	virtual void LoadInXml(FXmlReadNode* reader, const TMap<FString, UQaDSEdGraphNode*>& nodeById);
};

UCLASS()
class DIALOGSYSTEMEDITOR_API UQuestRootEdGraphNode : public UQaDSEdGraphNode
{
	GENERATED_BODY()

public:
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void AllocateDefaultPins() override;
};