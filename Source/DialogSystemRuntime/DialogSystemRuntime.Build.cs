using UnrealBuildTool;

public class DialogSystemRuntime : ModuleRules
{
    public DialogSystemRuntime(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "UMG"
            }
        );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
            }
        );
    }
}