#pragma once
#include "pch.h"
#include "DrTypes.h"
namespace DrValues
{
	unsigned long baseAddr = (unsigned long)GetModuleHandle(NULL);

	namespace Dr1
	{
		namespace Map
		{
			DrTypes::Vec3* Pos = (DrTypes::Vec3*)(baseAddr + 0x33cc8c);

			short* CurrentMap = (short*)(baseAddr + 0x2a4ce8);
		}

		namespace Player
		{
			DrTypes::Vec3* Pos = (DrTypes::Vec3*)(baseAddr + 0x33cc80);
		}

		namespace Camera
		{

			DrTypes::Vec3* Pos = (DrTypes::Vec3*)(baseAddr + 0x2a5de0);

			DrTypes::Vec2* Rot = (DrTypes::Vec2*)(baseAddr + 0x2a5dec);

			float* Rot_Up = (float*)(baseAddr + 0x2a5df8);

			float* FovY = (float*)(baseAddr + 0x2a5df4);
		}

		namespace Movie
		{
		}

		namespace Achievement
		{
		}

		namespace File
		{
		}


		namespace Character
		{

			DrTypes::Vec3* Pos = (DrTypes::Vec3*)(baseAddr + 0x2a5f60);

			float* Scale = (float*)(baseAddr + 0x2a5f6c);
			float* Rot = (float*)(baseAddr + 0x2a5f70);
		}

		namespace Script
		{
		//	short* Speaker = (short*)(baseAddr + 0x33ea44);

			DrTypes::ScriptId* ScriptId = (DrTypes::ScriptId*)(baseAddr + 0x2e4666);
		}

		namespace Game
		{
			DrTypes::Dr1::GameState* State = (DrTypes::Dr1::GameState*)(baseAddr + 0x2e47a8);

			unsigned short* Monocoins = (unsigned short*)(baseAddr + 0x2e47c8);
		}
	}
};