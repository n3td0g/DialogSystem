#include "TypeEditorCustomization/QuestStageCustomization.h"
#include "UObject/UnrealType.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SViewport.h"
#include "Animation/DebugSkelMeshComponent.h"
#include "Viewports.h"
#include "PropertyHandle.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "DetailCategoryBuilder.h"
#include "IDetailsView.h"
#include "Slate/SceneViewport.h"
#include "DetailLayoutBuilder.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Editor/UnrealEd/Public/Toolkits/AssetEditorManager.h"
#include "Quest/QuestEditorNodes.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Layout/SBox.h"
#include "GenericPlatform/GenericApplication.h"


#define LOCTEXT_NAMESPACE "QuestStageEventCustomization"

TSharedRef<IDetailCustomization> FQuestStageDetails::MakeInstance()
{
	return MakeShareable(new FQuestStageDetails());
}

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void FQuestStageDetails::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	auto StageProperty = DetailLayout.GetProperty(GET_MEMBER_NAME_CHECKED(UQuestStageEdGraphNode, Stage));

	uint32 StagePropertyCount;
	StageProperty->GetNumChildren(StagePropertyCount);

	DetailLayout.HideProperty(StageProperty);
	
	for (uint32 i = 0; i < StagePropertyCount; i++)
	{
		auto prop = StageProperty->GetChildHandle(i);
		auto name = prop->GetProperty()->GetName();

		auto& categoty = DetailLayout.EditCategory(FName(*prop->GetMetaData("Category")));

		if (name == "Description")
		{
			FText Text;
			prop->GetValue(Text);

			categoty.AddCustomRow(prop->GetPropertyDisplayName()).NameContent()
			[
				prop->CreatePropertyNameWidget()
			]
			.ValueContent()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SBox)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.MinDesiredHeight(150)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					[
						SNew(SMultiLineEditableTextBox)
						.Text(Text)
						.AutoWrapText(true)
						.SelectAllTextOnCommit(false)
						.SelectAllTextWhenFocused(false)
						.ClearKeyboardFocusOnCommit(true)
						.OnTextCommitted_Lambda([prop](const FText& NewText, ETextCommit::Type Type) 
						{
							prop->SetValue(NewText);
						})
						.ModiferKeyForNewLine(EModifierKey::None)
					]
				]
			];
		}
		else
		{
			categoty.AddProperty(prop);
		}
	}
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE