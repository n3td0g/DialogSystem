#pragma once


#include "IDetailCustomization.h"
#include "Editor/PropertyEditor/Public/IPropertyTypeCustomization.h"

class DIALOGSYSTEMEDITOR_API FPhraseNodeDetails : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;
};