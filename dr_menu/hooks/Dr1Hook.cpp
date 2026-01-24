#include "../Hook.hpp"
#include "../drlib/Dr1.h"
#include <iostream>
#include <cstdio>
namespace Hook
{
	DrLib::Dr1::Funcs::Debug::LogFunc* LogFuncOriginal;

	char buffer[256];
	void LogDetour(char* format, ...)
	{
	
		va_list args;
		va_start(args, format);
		vsprintf_s(buffer, format, args);
		std::cout << buffer << "\n";
		va_end(args);
	}

	DrLib::Dr1::Funcs::Map::MapLoadFunc* MapFuncOriginal;
	void MapDetour(int map)
	{
		MapFuncOriginal(map);
		printf("Loaded map %i\n", map);
	}

	void HookDR1()
	{
		printf("Hooking Dr1...\n");
		if (MH_CreateHookEx((LPVOID)DrLib::Dr1::Funcs::Debug::Log, (LPVOID)&LogDetour, &LogFuncOriginal) == MH_OK)
			printf("Created Hook Log\n");
		if (MH_EnableHook((LPVOID)DrLib::Dr1::Funcs::Debug::Log) == MH_OK)
			printf("Enabled Hook Log\n");

		if (MH_CreateHookEx((LPVOID)DrLib::Dr1::Funcs::Map::Load, (LPVOID)&MapDetour, &MapFuncOriginal) == MH_OK)
			printf("Created Hook Map\n");
		if (MH_EnableHook((LPVOID)DrLib::Dr1::Funcs::Map::Load) == MH_OK)
			printf("Enabled Hook Map\n");
	}
}