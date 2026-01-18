// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "DrValues.h"
#include "DrFuncs.h"
#include <iostream>
void init()
{
    AllocConsole();
    FILE* fDummy;
    freopen_s(&fDummy, "CONIN$", "r", stdin);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONOUT$", "w", stdout);

    std::cout << *DrValues::Dr1::Map::CurrentMap << "\n";
    DrFuncs::Dr1::Map::Load(1);
    std::cout << *DrValues::Dr1::Map::CurrentMap << "\n";
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        break;
    case DLL_THREAD_ATTACH:
        init();
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

