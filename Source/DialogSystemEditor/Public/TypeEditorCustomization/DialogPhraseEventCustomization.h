#pragma once

#include "Editor/PropertyEditor/Public/IPropertyTypeCustomization.h"
#include "PropertyHandle.h"

class DIALOGSYSTEMEDITOR_API FDialogPhraseEventCustomization : public IPropertyTypeCustomization
{
	TSharedPtr<IPropertyHandle> StructPropertyHandle;

public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> InStructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> InStructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

	FReply OnTitleClick();

	EVisibility GetFingTagVisibility() const;
	EVisibility GetObjectClassVisibility() const;
	FText GetTitleText() const;
};