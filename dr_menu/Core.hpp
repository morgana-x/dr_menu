#pragma once
namespace Core
{
	enum DrGame
	{
		None,
		DR1,
		DR2
	};

	inline DrGame Game;
	inline extern void Init();
	inline extern void Uninit();
}