// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Core.hpp"
#include "Draw.hpp"
#include "stdio.h"
HANDLE hCurrentUIThread = nullptr;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        Draw::hCurrentModule = hModule;

        hCurrentUIThread = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)Core::Init, nullptr, NULL, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        TerminateThread(hCurrentUIThread, 0);
        Core::Uninit();
        break;
    }
    return TRUE;
}

/*
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    Draw::Init();
    return 0;
}*/