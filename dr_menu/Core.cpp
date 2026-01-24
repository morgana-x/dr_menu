#include "Core.hpp"
#include "Hook.hpp"
#include "Draw.hpp"
#include <string>
namespace Core
{
    void AllocateConsole()
    {
        AllocConsole();
        FILE* fDummy;
        freopen_s(&fDummy, "CONIN$", "r", stdin);
        freopen_s(&fDummy, "CONOUT$", "w", stderr);
        freopen_s(&fDummy, "CONOUT$", "w", stdout);
    }

    char actualpath[2048];
    void DetectGame()
    {
        TCHAR szEXEPath[2048];

        GetModuleFileName(NULL, szEXEPath, 2048);
        for (int j = 0; szEXEPath[j] != 0; j++)
            actualpath[j] = szEXEPath[j];

        std::string filePath(actualpath);
        std::size_t found = filePath.find_last_of("/\\");
        filePath = filePath.substr(found + 1);

        Core::Game = filePath == "DR1_us.exe" ? DR1 : filePath == "DR2_us.exe" ? DR2 : None;
    }


	void Init()
	{
        AllocateConsole();
        printf("Allocated console\n");
        DetectGame();
		Hook::HookGame();
        Draw::Init();
	}

    void Uninit()
    {
        MH_Uninitialize();
    }
}