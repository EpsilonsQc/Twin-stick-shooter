// © 2023 - Beyond Prophecy

using UnrealBuildTool;
using System.Collections.Generic;

public class H23_UEJ3_Equipe04EditorTarget : TargetRules
{
	public H23_UEJ3_Equipe04EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "H23_UEJ3_Equipe04" } );
	}
}
