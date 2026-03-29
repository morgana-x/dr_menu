#pragma once
namespace DrLib
{
	namespace Dr2
	{
		inline unsigned long baseAddr = (unsigned long)GetModuleHandle(NULL);
		namespace Funcs
		{
			namespace Map
			{
				typedef void MapLoadFunc(unsigned int);
				inline extern  MapLoadFunc* Load = (MapLoadFunc*)(baseAddr + 0x5b1e0);
			}

			namespace Audio
			{
				typedef void PlaySongFunc(unsigned int, int);
				inline extern  PlaySongFunc* PlaySong = (PlaySongFunc*)(baseAddr + 0x34430);
				inline extern  void PlaySongWrapper(unsigned int track, int volume = 100)
				{
					PlaySong(track, volume);
				}
			}

			namespace Character
			{
				typedef void LoadStandFunc(unsigned int chara, int emote);
				inline extern LoadStandFunc* LoadStand = (LoadStandFunc*)(baseAddr + 0x615d0);


				typedef void SpawnCharFunc(unsigned int chara, char roomPos);
				inline SpawnCharFunc* SpawnChar = (SpawnCharFunc*)(baseAddr + 0x61180);


				typedef void CreateCharFunc(unsigned int chara);
				inline CreateCharFunc* CreateChar = (CreateCharFunc*)(baseAddr + 0x5f030);
			}

			namespace Debug
			{
				typedef void LogFunc(char* fmt, ...);
				inline LogFunc* Log = (LogFunc*)(baseAddr + 0x158c40);

				typedef void (__cdecl* DrawTextFunc)(int x, int y, const char* TextDebug);
				inline DrawTextFunc DrawDebugText = (DrawTextFunc)(baseAddr + 0x135b0);

			}
			namespace TextRender
			{
				typedef int(__cdecl* DrawText)(int layer, int posX, int posY, short character, int colorIndex);
				inline DrawText Draw = (DrawText)(baseAddr + 0x154310);


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
}
