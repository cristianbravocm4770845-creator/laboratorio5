// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NavesUSFX_02_2026 : ModuleRules
{
	public NavesUSFX_02_2026(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
