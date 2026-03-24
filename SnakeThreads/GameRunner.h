#pragma once
#include "Direction.h"
#include <atomic>
#include "Point.h"
#include "GameState.h"


class GameRunner
{
private:
	std::atomic<Direction> playerDirection;
	GameState state;
	std::atomic<bool> _isRunning;
public:
	GameRunner();
	void Tick();
	void SetDirection(Direction d);
	void Run();
	void Quit();
	bool IsRunning();
	GameState GetBuffer();
};

