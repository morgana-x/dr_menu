#pragma once
#include "pch.h"
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
				inline MapLoadFunc* Load = (MapLoadFunc*)(baseAddr + 0x5b1e0);
			}
			namespace Audio
			{
				typedef void PlaySongFunc(unsigned int, int);
				inline PlaySongFunc* PlaySong = (PlaySongFunc*)(baseAddr + 0x34430);
				inline void PlaySongWrapper(unsigned int track, int volume = 100)
				{
					PlaySong(track, volume);
				}
			}
			namespace Character
			{
				typedef void LoadStandFunc(unsigned int, int);
				inline LoadStandFunc* LoadStand = (LoadStandFunc*)(baseAddr + 0x615d0);

			}
		}
	}
}