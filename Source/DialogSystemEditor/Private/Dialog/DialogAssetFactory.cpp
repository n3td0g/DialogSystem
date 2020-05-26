
#include "Dialog/DialogAssetFactory.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Dialog/DialogAsset.h"


UDialogAssetFactory::UDialogAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UDialogAsset::StaticClass();
}

UObject* UDialogAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UDialogAsset* asset = NewObject<UDialogAsset>(InParent, Class, Name, Flags | RF_Transactional);
	asset->Name = Name;

	return asset;
}

bool UDialogAssetFactory::CanCreateNew() const
{
	return true;
}