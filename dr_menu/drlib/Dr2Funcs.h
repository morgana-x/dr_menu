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
				typedef void LoadStandFunc(unsigned int, int);
				inline extern LoadStandFunc* LoadStand = (LoadStandFunc*)(baseAddr + 0x615d0);

			}
		}
	}
}