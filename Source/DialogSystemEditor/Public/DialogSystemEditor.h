#pragma once


#include "Developer/AssetTools/Public/AssetTypeCategories.h"
#include "Modules/ModuleInterface.h"

DECLARE_LOG_CATEGORY_EXTERN(DialogModuleLog, All, All)

class FDialogSystemEditorModule : public IModuleInterface
{
public:
	EAssetTypeCategories::Type AssetCategory;

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedRef<class SDockTab> SpawnStoryKeyTab(const class FSpawnTabArgs&);
};