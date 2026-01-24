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
}