using UnrealBuildTool;

public class DialogSystemEditor : ModuleRules
{
    public DialogSystemEditor(ReadOnlyTargetRules Target) : base(Target)
    {

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "TargetPlatform",
            }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "InputCore",
                "UnrealEd",
                "PropertyEditor",
                "LevelEditor",
                "EditorStyle",
                "GraphEditor",
                "BlueprintGraph",
                "Projects",
                "ApplicationCore",
                "DesktopPlatform",
                "XmlParser",
                "ToolMenus",

                "DialogSystemRuntime",
            }
        );
    }
}