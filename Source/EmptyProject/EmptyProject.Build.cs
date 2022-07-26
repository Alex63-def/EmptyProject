// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EmptyProject : ModuleRules
{
	public EmptyProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        if (Target.Platform == UnrealTargetPlatform.Android)
        {
			PublicAdditionalLibraries.AddRange(new string[] { System.IO.Path.Combine(ModuleDirectory, "PugiXml", "pugi", "pugixml.lib") });
		}

        // ��� ������������� xml
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDependencyModuleNames.AddRange(new string[] { "Launch", "ApplicationCore" });
            PrivateIncludePaths.AddRange(new string[] { "/Source/Runtime/Launch/Private" });
            string pluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("PhotoLibrary", System.IO.Path.Combine(pluginPath, "PhotoLibrary_APL.xml")));
        }

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "ImageWrapper" });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
