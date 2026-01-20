#pragma once
namespace DrLib
{
	namespace Types
	{
		namespace Common
		{
			struct Vec3 {
				float x;
				float y;
				float z;
			};

			struct Vec2 {
				float x;
				float y;

			};


			//https://github.com/SpiralFramework/SpiralNeo/blob/main/Info.SpiralFramework.Neo.Interfaces
			struct ScriptId {
				short Chapter;
				short Scene;
				short Variant;
			};
		}

		namespace Dr1
		{
			// https://github.com/SpiralFramework/SpiralNeo/blob/main/Info.SpiralFramework.Neo.Interfaces/Dr1GameStateData.cs
			struct GameState
			{
				short TimeOfDay;
				short NameColour;
				short VibrationLower;
				short VibrationUpper;
				short ColourSet;
				short Wait;
				short WaitForce;
				short Case;
				short MapLoadPlayerPlacement;
				short SCDATA_WAK_NONSTOP_MODE_CHK;
				short LastUsedEvidence;
				short SCDATA_WAK_MAXTIME;
				short SkillPoints;
				short SCDATA_WAK_SPEAK_ADD;
				short SCDATA_WAK_RANDOM;
				short Gamemode;
				short SCDATA_WAK_MONOKUMA_MEDAL;
				short UnlockedRulePages;
				short ActionDifficulty;
				short LogicDifficulty;
			};
		}
	}
}