#include "Quest/QuestEditorNodeFactory.h"
#include "EdGraph/EdGraphNode.h"
#include "QaDSEditor/QaDSSlateNode.h"
#include "Quest/QuestEditorNodes.h"
#include "Quest/QuestSGraphNodes.h"
#include "QaDSEditor/QaDSEdGraphNode.h"

TSharedPtr<class SGraphNode> FQuestEditorNodeFactory::CreateNode(UEdGraphNode* Node) const
{
	TSharedPtr<SGraphNode_QaDSNodeBase> SNode;

	if (Node->IsA(UQuestRootEdGraphNode::StaticClass()))
	{
		SNode = SNew(SGraphNode_QuestRootNode, Cast<UQuestRootEdGraphNode>(Node));
	}
	else if (Node->IsA(UQuestStageEdGraphNode::StaticClass()))
	{
		SNode = SNew(SGraphNode_QuestNode, Cast<UQuestStageEdGraphNode>(Node));
	}

	if (Node != NULL && Node->IsA(UQaDSEdGraphNode::StaticClass()))
		Cast<UQaDSEdGraphNode>(Node)->PropertyObserver = SNode;
	
	return SNode;
}