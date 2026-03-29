#include "../Hook.hpp"
#include "../drlib/Dr2.h"
#include "cstdio"
#include <iostream>

DrLib::Dr2::Funcs::Debug::LogFunc* Dr2LogFuncOriginal;

char dr2buffer[256];
void Dr2LogDetour(char* format, ...)
{

	va_list args;
	va_start(args, format);
	vsprintf_s(dr2buffer, format, args);
	std::cout << dr2buffer << "\n";
	va_end(args);
}

namespace Hook
{
	void HookDR2()
	{
		printf("Hooking Dr2...\n");

		Hook::InitHook("Log", DrLib::Dr2::Funcs::Debug::Log, &Dr2LogDetour, &Dr2LogFuncOriginal);
		
	}
}