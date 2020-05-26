#pragma once

#include "DialogEditorNodes.h"
#include "QaDSEditor/QaDSAssetEditor.h"

class UDialogPhraseNode;
class UDialogEdGraphNode;
class UDialogRootEdGraphNode;

class DIALOGSYSTEMEDITOR_API FDialogAssetEditor : public FQaDSAssetEditor
{
	UDialogAsset* EditedAsset;

public:
	void InitDialogAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UDialogAsset* Object);
	void BuildToolbar(FToolBarBuilder &builder);

protected:
	FName GetEditorName() const override;

	UEdGraph* CreateGraphFromAsset();
	UDialogRootEdGraphNode* GetRootNode();

	void Compile() override;
	UDialogNode* Compile(UDialogEdGraphNode* Node);
};

struct DIALOGSYSTEMEDITOR_API FDialogCommands : public TCommands<FDialogCommands>
{
	TSharedPtr<FUICommandInfo> Compile;
	TSharedPtr<FUICommandInfo> Find;
	TSharedPtr<FUICommandInfo> Import;
	TSharedPtr<FUICommandInfo> Export;

	FDialogCommands()
		: TCommands<FDialogCommands>(TEXT("Dialog Graph Commands"), FText::FromString("Dialog Graph Commands"), NAME_None, FEditorStyle::GetStyleSetName())
	{
	}

	virtual void RegisterCommands() override;
};