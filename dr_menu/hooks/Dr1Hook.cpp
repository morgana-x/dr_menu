#include "../Hook.hpp"
#include "../drlib/Dr1.h"
#include <iostream>
#include <cstdio>

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

DrLib::Dr1::Funcs::Debug::DrawTextFunc* DebugTextFuncOriginal;

void DebugTextDetour(int start...)
{
	return;
	/*
	va_list args;
	va_start(args, start);

	for (char* text = va_arg(args, char*); text != nullptr; text = va_arg(args, char*))
	{
		if (text != nullptr)
			std::cout << text << "\n";
	}

	va_end(args);*/
}

namespace Hook
{
	void HookDR1()
	{
		printf("Hooking Dr1...\n");

		Hook::InitHook("Log", DrLib::Dr1::Funcs::Debug::Log, &LogDetour, &LogFuncOriginal);

	//	Hook::InitHook("DrawDebugText", DrLib::Dr1::Funcs::Debug::DrawDebugText, &DebugTextDetour, &DebugTextFuncOriginal);
	}
}