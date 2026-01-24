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
				inline extern Vec3* Pos = (Vec3*)(baseAddr + 0x33cc8c);

				inline extern short* CurrentMap = (short*)(baseAddr + 0x2a4ce8);
			}

			namespace Player
			{
				inline extern Vec3* Pos = (Vec3*)(baseAddr + 0x33cc80);

				inline extern char* MovementMode = (char*)(baseAddr + 0x33cc4c);
			}

			namespace Camera
			{
				inline extern char* Enabled = (char*)(baseAddr + 0x2a5dd8);

				inline extern Vec3* Pos = (Vec3*)(baseAddr + 0x2a5de0);

				inline extern Vec2* Rot = (Vec2*)(baseAddr + 0x2a5dec);

				inline extern float* Rot_Up = (float*)(baseAddr + 0x2a5df8);

				inline extern float* Fov = (float*)(baseAddr + 0x2a5df4);
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

				inline extern Vec3* Pos = (Vec3*)(baseAddr + 0x2a5f60);

				inline extern float* Scale = (float*)(baseAddr + 0x2a5f6c);
				inline extern float* Rot = (float*)(baseAddr + 0x2a5f70);
			}

			namespace Script
			{
				//	short* Speaker = (short*)(baseAddr + 0x33ea44);

				inline extern Types::Common::ScriptId* ScriptId = (Types::Common::ScriptId*)(baseAddr + 0x2e4666);
			}

			namespace Game
			{
				inline extern GameState* State = (GameState*)(baseAddr + 0x2e47a8);
			}
			namespace Collectables
			{
				inline extern unsigned short* Monocoins = (unsigned short*)(baseAddr + 0x2e47c8);
			}

			namespace Audio
			{
				inline extern unsigned short* CurrentSong = (unsigned short*)(baseAddr + 0x295da0);
			}

			namespace Debug
			{
				inline extern unsigned char* SelectedMenu = (unsigned char*)(baseAddr + 0x2a84b0);
			}


			namespace HUD
			{
				inline extern char* ChapterState = (char*)(baseAddr + 0x33c3c0);
				inline extern char* InteractPopupState = (char*)(baseAddr + 0x33c3e8);
				inline extern char* HelpIconState = (char*)(baseAddr + 0x33c536);
				inline extern char* ObservingState = (char*)(baseAddr + 0x33c53a);

				inline extern int* RadioVisible = (int*)(baseAddr + 0x33cb78);

			}

			namespace Render
			{
				inline extern char* RenderingEnabled = (char*)(baseAddr + 0x2879ec);
			}
		}
	}
};