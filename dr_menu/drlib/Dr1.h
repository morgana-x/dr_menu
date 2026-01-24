#pragma once
#include "windows.h"
namespace DrLib
{
	namespace Dr1
	{
		inline extern unsigned long baseAddr = (unsigned long)GetModuleHandle(NULL);
	}
}
#include "DrTypes.h"
#include "Dr1Values.h"
#include "Dr1Funcs.h"