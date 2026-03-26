#pragma once
#include "cstdio"

#include "ext/minhook/include/MinHook.h"
#if defined _M_IX86
#pragma comment(lib, "ext/minhook/lib/libMinHook.x86.lib")
#endif

template <typename T>
inline MH_STATUS MH_CreateHookEx(LPVOID pTarget, LPVOID pDetour, T** ppOriginal)
{
	return MH_CreateHook(pTarget, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
}

namespace Hook
{
	void HookGame();

	void HookDR1();
	void HookDR2();

	template <typename T>
	inline MH_STATUS InitHook(const char* name, LPVOID pTarget, LPVOID pDetour, T** ppOriginal)
	{

		MH_STATUS result = MH_CreateHookEx(pTarget, pDetour, ppOriginal);
		if (result != MH_OK)
		{
			printf("Failed to create hook %s", name);
			return result;
		}

		result = MH_EnableHook(pTarget);

		if (result != MH_OK)
			printf("Failed to init hook %s", name);
		else
			printf("Hooked %s at %i", name, (int)pTarget);
		return result;
	}
}