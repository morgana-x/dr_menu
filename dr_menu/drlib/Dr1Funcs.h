#pragma once
namespace DrLib
{
	namespace Dr1
	{
		namespace Funcs
		{
			namespace Map
			{
				typedef void MapLoadFunc(unsigned int mapId);
				inline MapLoadFunc* Load = (MapLoadFunc*)(baseAddr + 0x1ac10);
			}

			namespace Player
			{
				typedef void PlayerSetPosFunc(float x, float y, float z, float rot);
				inline PlayerSetPosFunc* SetPos = (PlayerSetPosFunc*)(baseAddr + 0x6c120);
			}

			namespace Camera
			{
				typedef void CameraSetPosFunc(float, float, float);
				inline CameraSetPosFunc* SetPos = (CameraSetPosFunc*)(baseAddr + 0x1e900);

				typedef void CameraSetYaw(float yaw);
				inline CameraSetYaw* SetYaw = (CameraSetYaw*)(baseAddr + 0x1e9c0);

				typedef void CameraSetFov(float fov);
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
				typedef void FileLoadFunc(char* path, int, int);
				inline FileLoadFunc* Load = (FileLoadFunc*)(baseAddr + 0xc5d30);
			}


			namespace Character
			{
				typedef void LoadBustupFunc(int chara, int, int);
				inline LoadBustupFunc* LoadBustup = (LoadBustupFunc*)(baseAddr + 0x20300);

				typedef void LoadStandFunc(int chara, int emote);
				inline LoadStandFunc* LoadStand = (LoadStandFunc*)(baseAddr + 0x22b30);

				typedef void SetPosFunc(unsigned int chara, float x, float y, float z);
				inline SetPosFunc* SetPos = (SetPosFunc*)(baseAddr + 0x23200);

				typedef void SpawnCharFunc(unsigned int chara, char roomPos);
				inline SpawnCharFunc* SpawnChar = (SpawnCharFunc*)(baseAddr + 0x22840);

				typedef void DespawnCharFunc(unsigned int chara);
				inline DespawnCharFunc* DespawnChar = (DespawnCharFunc*)(baseAddr + 0x22980);

				typedef void CreateCharFunc(unsigned int chara);
				inline CreateCharFunc* CreateChar = (CreateCharFunc*)(baseAddr + 0x22980);
			}

			namespace Script
			{
				// https://github.com/SpiralFramework/SpiralNeo/blob/main/Info.SpiralFramework.Neo.Interfaces/Dr1Delegates.cs
				// (int param1, uint scriptChapter, uint scriptScene, uint scriptVariant);
				// param1 usually zero
				typedef void LoadScriptFunc(int unk, int chapter, int scene, int variant);
				inline LoadScriptFunc* LoadAndRun = (LoadScriptFunc*)(baseAddr + 0x4bf30);

				inline void LoadAndRunWrapper(int chapter, int scene, int variant)
				{
					LoadAndRun(0, chapter, scene, variant);
				}
			}

			namespace Game
			{
				typedef void MainLoopFunc();
				inline MainLoopFunc* MainLoop = (MainLoopFunc*)(baseAddr + 0x447b0);
			}

			namespace Audio
			{
				typedef int PlaySongFunc(int, unsigned int track, int volume, int, int, int);
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


				typedef void LogFunc(char* fmt, ...);
				inline LogFunc* Log = (LogFunc*)(baseAddr + 0x100b00);

				typedef void DrawTextFunc(...);
				inline DrawTextFunc* DrawDebugText = (DrawTextFunc*)(baseAddr + 0x135b0);
			}

			namespace HUD
			{
				typedef void RenderHudFunc(); // Called by rendering loop
				inline RenderHudFunc* RenderHud = (RenderHudFunc*)(baseAddr + 0x411e0);

				typedef void HideChapterFunc();
				inline HideChapterFunc* HideChapterAnim = (HideChapterFunc*)(baseAddr + 0x41d90);

				// Time Of Day, chapter, 0
				typedef void ShowChapterFunc(unsigned int, char, char);
				inline ShowChapterFunc* ShowChapter = (ShowChapterFunc*)(baseAddr + 0x41e60);

				typedef void HideInvestigatePopupFunc();
				inline HideInvestigatePopupFunc* HideInvestigatePopupAnim = (HideInvestigatePopupFunc*)(baseAddr + 0x41520);

				typedef void SetRadioVisibleFunc(char);
				inline SetRadioVisibleFunc* SetRadioVisible = (SetRadioVisibleFunc*)(baseAddr + 0x63980);
			}
			namespace TextRender
			{
				typedef int(__cdecl* DrawText)(int layer, int posX, int posY, short character, int colorIndex);
				inline DrawText Draw = (DrawText)(baseAddr + 0xf38e0);


				inline void PrintString(int layer, int x, int y, const wchar_t* str, int color)
				{
					int currentX = x;
					for (int i = 0; i < wcslen(str); i++)
					{
						int width = Draw(layer, currentX, y, (short)str[i], color);
						currentX += width;
					}
				}
			}
		}
	}
};