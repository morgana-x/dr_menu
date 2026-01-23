#pragma once
using namespace DrLib::Types::Common;
using namespace DrLib::Types::Dr1;
namespace DrLib
{
	namespace Dr1
	{
		namespace Values
		{
			namespace Map
			{
				Vec3* Pos = (Vec3*)(baseAddr + 0x33cc8c);

				short* CurrentMap = (short*)(baseAddr + 0x2a4ce8);
			}

			namespace Player
			{
				Vec3* Pos = (Vec3*)(baseAddr + 0x33cc80);

				char* MovementMode = (char*)(baseAddr + 0x33cc4c);
			}

			namespace Camera
			{
				char* Enabled = (char*)(baseAddr + 0x2a5dd8);

				Vec3* Pos = (Vec3*)(baseAddr + 0x2a5de0);

				Vec2* Rot = (Vec2*)(baseAddr + 0x2a5dec);

				float* Rot_Up = (float*)(baseAddr + 0x2a5df8);

				float* Fov = (float*)(baseAddr + 0x2a5df4);
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

				Vec3* Pos = (Vec3*)(baseAddr + 0x2a5f60);

				float* Scale = (float*)(baseAddr + 0x2a5f6c);
				float* Rot = (float*)(baseAddr + 0x2a5f70);
			}

			namespace Script
			{
				//	short* Speaker = (short*)(baseAddr + 0x33ea44);

				Types::Common::ScriptId* ScriptId = (Types::Common::ScriptId*)(baseAddr + 0x2e4666);
			}

			namespace Game
			{
				GameState* State = (GameState*)(baseAddr + 0x2e47a8);
			}
			namespace Collectables
			{
				unsigned short* Monocoins = (unsigned short*)(baseAddr + 0x2e47c8);
			}

			namespace Audio
			{
				unsigned short* CurrentSong = (unsigned short*)(baseAddr + 0x295da0);
			}

			namespace Debug
			{
				unsigned char* SelectedMenu = (unsigned char*)(baseAddr + 0x2a84b0);
			}


			namespace HUD
			{
				char* ChapterState = (char*)(baseAddr + 0x33c3c0);
				char* InteractPopupState = (char*)(baseAddr + 0x33c3e8);
				char* HelpIconState = (char*)(baseAddr + 0x33c536);
				char* ObservingState = (char*)(baseAddr + 0x33c53a);

				int* RadioVisible = (int*)(baseAddr + 0x33cb78);

			}

			namespace Render
			{
				char* RenderingEnabled = (char*)(baseAddr + 0x2879ec);
			}
		}
	}
};