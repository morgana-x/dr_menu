#include "Hook.hpp"
#include "Core.hpp"
namespace Hook
{
	void HookGame()
	{
		MH_Initialize();
		switch (Core::Game)
		{
			case Core::DR1:
				HookDR1();
				break;
			case Core::DR2:
				HookDR2();
				break;
		}
	}
}