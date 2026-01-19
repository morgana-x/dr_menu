#pragma once
#include "pch.h"
namespace DrFuncs
{
	unsigned long baseAddr = (unsigned long)GetModuleHandle(NULL);

	namespace Dr1
	{
		namespace Map
		{
			typedef void MapLoadFunc(unsigned int);
			MapLoadFunc* Load = (MapLoadFunc*)(baseAddr + 0x1ac10);
		}

		namespace Player
		{
			typedef void PlayerSetPosFunc(float, float, float, float);
			PlayerSetPosFunc* SetPos = (PlayerSetPosFunc*)(baseAddr + 0x6c120);
		}

		namespace Camera
		{
			typedef void CameraSetPosFunc(float, float, float);
			CameraSetPosFunc* SetPos = (CameraSetPosFunc*)(baseAddr + 0x1e900);

			typedef void CameraSetYaw(float);
			CameraSetYaw* SetYaw = (CameraSetYaw*)(baseAddr + 0x1e9c0);

			typedef void CameraSetFov(float);
			CameraSetFov* SetFov = (CameraSetFov*)(baseAddr + 0x1e740);
		}

		namespace Movie
		{
			typedef void MovieLoadFunc(int);
			MovieLoadFunc* Load = (MovieLoadFunc*)(baseAddr + 0xd65c0);
		}

		namespace Achievement
		{
			typedef void UnlockAchievementFunc(int);
			UnlockAchievementFunc* UnlockAchievement = (UnlockAchievementFunc*)(baseAddr + 0xd65c0);
		}

		namespace File
		{
			typedef void FileLoadFunc(char*, int, int);
			FileLoadFunc* Load = (FileLoadFunc*)(baseAddr + 0xc5d30);
		}


		namespace Character
		{
			typedef void LoadBustupFunc(int, int, int);
			LoadBustupFunc* LoadBustup = (LoadBustupFunc*)(baseAddr + 0x20300);

			typedef void LoadStandFunc(int, int);
			LoadStandFunc* LoadStand = (LoadStandFunc*)(baseAddr + 0x22b30);

			typedef void SetPosFunc(unsigned int, float, float, float);
			SetPosFunc* SetPos = (SetPosFunc*)(baseAddr + 0x23200);

			typedef void SpawnCharFunc(unsigned int, char);
			SpawnCharFunc* SpawnChar = (SpawnCharFunc*)(baseAddr + 0x22840);
		}

		namespace Script
		{
			// https://github.com/SpiralFramework/SpiralNeo/blob/main/Info.SpiralFramework.Neo.Interfaces/Dr1Delegates.cs
			// (int param1, uint scriptChapter, uint scriptScene, uint scriptVariant);
			// param1 usually zero
			typedef void LoadScriptFunc(int, int, int, int);
			LoadScriptFunc* LoadAndRun = (LoadScriptFunc*)(baseAddr + 0x4bf30);

			void LoadAndRunWrapper(int chapter, int scene, int variant)
			{
				LoadAndRun(0, chapter, scene, variant);
			}
		}

		namespace Game
		{
		}

		namespace Audio
		{
			typedef int PlaySoundFunc(int, unsigned int, int, int, int, int);
			PlaySoundFunc* PlaySound = (PlaySoundFunc*)(baseAddr + 0x62e70);

			bool PlaySongWrapper(int track, int volume = 100)
			{
				return 1 == PlaySound(0, track, volume, 0, 0xffffffff, 0);
			}
		}

		namespace Debug
		{
			typedef void EnableDebugMenuFunc();
			EnableDebugMenuFunc* EnableDebugMenu = (EnableDebugMenuFunc*)(baseAddr + 0x2c3a0);
		}

		namespace HUD
		{
			typedef void RenderHudFunc(); // Called by rendering loop
			RenderHudFunc* RenderHud = (RenderHudFunc*)(baseAddr + 0x411e0);

			typedef void HideChapterFunc();
			HideChapterFunc* HideChapterAnim = (HideChapterFunc*)(baseAddr + 0x41d90);

			// Time Of Day, chapter, 0
			typedef void EnableChapterFunc(unsigned int, char, char);
			EnableChapterFunc* ShowChapter = (EnableChapterFunc*)(baseAddr + 0x41e60);

			typedef void HideInvestigatePopupFunc();
			HideInvestigatePopupFunc* HideInvestigatePopupAnim = (HideInvestigatePopupFunc*)(baseAddr + 0x41520);

			typedef void SetRadioVisibleFunc(char);
			SetRadioVisibleFunc* SetRadioVisible = (SetRadioVisibleFunc*)(baseAddr + 0x63980);
		}
	}
};