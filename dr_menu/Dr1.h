#pragma once
#include "pch.h"
namespace DrLib
{
	namespace Dr1
	{
		unsigned long baseAddr = (unsigned long)GetModuleHandle(NULL);
	}
}
#include "DrTypes.h"
#include "Dr1Values.h"
#include "Dr1Funcs.h"