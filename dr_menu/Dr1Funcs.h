#pragma once
namespace DrLib
{
	namespace Dr1
	{
		namespace Funcs
		{
			namespace Map
			{
				typedef void MapLoadFunc(unsigned int);
				inline MapLoadFunc* Load = (MapLoadFunc*)(baseAddr + 0x1ac10);
			}

			namespace Player
			{
				typedef void PlayerSetPosFunc(float, float, float, float);
				inline PlayerSetPosFunc* SetPos = (PlayerSetPosFunc*)(baseAddr + 0x6c120);
			}

			namespace Camera
			{
				typedef void CameraSetPosFunc(float, float, float);
				inline CameraSetPosFunc* SetPos = (CameraSetPosFunc*)(baseAddr + 0x1e900);

				typedef void CameraSetYaw(float);
				inline CameraSetYaw* SetYaw = (CameraSetYaw*)(baseAddr + 0x1e9c0);

				typedef void CameraSetFov(float);
				inline CameraSetFov* SetFov = (CameraSetFov*)(baseAddr + 0x1e740);
			}

			namespace Movie
			{
				typedef void MovieLoadFunc(int);
				inline MovieLoadFunc* Load = (MovieLoadFunc*)(baseAddr + 0xd65c0);
			}

			namespace Achievement
			{
				typedef void UnlockAchievementFunc(int);
				inline UnlockAchievementFunc* UnlockAchievement = (UnlockAchievementFunc*)(baseAddr + 0xd65c0);
			}

			namespace File
			{
				typedef void FileLoadFunc(char*, int, int);
				inline FileLoadFunc* Load = (FileLoadFunc*)(baseAddr + 0xc5d30);
			}


			namespace Character
			{
				typedef void LoadBustupFunc(int, int, int);
				inline LoadBustupFunc* LoadBustup = (LoadBustupFunc*)(baseAddr + 0x20300);

				typedef void LoadStandFunc(int, int);
				inline LoadStandFunc* LoadStand = (LoadStandFunc*)(baseAddr + 0x22b30);

				typedef void SetPosFunc(unsigned int, float, float, float);
				inline SetPosFunc* SetPos = (SetPosFunc*)(baseAddr + 0x23200);

				typedef void SpawnCharFunc(unsigned int, char);
				inline SpawnCharFunc* SpawnChar = (SpawnCharFunc*)(baseAddr + 0x22840);

				typedef void DespawnCharFunc(unsigned int);
				inline DespawnCharFunc* DespawnChar = (DespawnCharFunc*)(baseAddr + 0x22980);
			}

			namespace Script
			{
				// https://github.com/SpiralFramework/SpiralNeo/blob/main/Info.SpiralFramework.Neo.Interfaces/Dr1Delegates.cs
				// (int param1, uint scriptChapter, uint scriptScene, uint scriptVariant);
				// param1 usually zero
				typedef void LoadScriptFunc(int, int, int, int);
				inline LoadScriptFunc* LoadAndRun = (LoadScriptFunc*)(baseAddr + 0x4bf30);

				inline void LoadAndRunWrapper(int chapter, int scene, int variant)
				{
					LoadAndRun(0, chapter, scene, variant);
				}
			}

			namespace Game
			{
			}

			namespace Audio
			{
				typedef int PlaySongFunc(int, unsigned int, int, int, int, int);
				inline PlaySongFunc* PlaySong = (PlaySongFunc*)(baseAddr + 0x62e70);

				inline bool PlaySongWrapper(int track, int volume = 100)
				{
					return 1 == PlaySong(0, track, volume, 0, 0xffffffff, 0);
				}
			}

			namespace Debug
			{
				typedef void EnableDebugMenuFunc();
				inline EnableDebugMenuFunc* EnableDebugMenu = (EnableDebugMenuFunc*)(baseAddr + 0x2c3a0);
			}

			namespace HUD
			{
				typedef void RenderHudFunc(); // Called by rendering loop
				inline RenderHudFunc* RenderHud = (RenderHudFunc*)(baseAddr + 0x411e0);

				typedef void HideChapterFunc();
				inline HideChapterFunc* HideChapterAnim = (HideChapterFunc*)(baseAddr + 0x41d90);

				// Time Of Day, chapter, 0
				typedef void EnableChapterFunc(unsigned int, char, char);
				inline EnableChapterFunc* ShowChapter = (EnableChapterFunc*)(baseAddr + 0x41e60);

				typedef void HideInvestigatePopupFunc();
				inline HideInvestigatePopupFunc* HideInvestigatePopupAnim = (HideInvestigatePopupFunc*)(baseAddr + 0x41520);

				typedef void SetRadioVisibleFunc(char);
				inline SetRadioVisibleFunc* SetRadioVisible = (SetRadioVisibleFunc*)(baseAddr + 0x63980);
			}
		}
	}
};