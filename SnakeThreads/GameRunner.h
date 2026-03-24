#pragma once
#include "Direction.h"
#include <atomic>
#include "Point.h"


class GameRunner
{
private:
	std::atomic<Direction> playerDirection;
	Point player;
	std::atomic<bool> _isRunning;
	void DrawBoard();
public:
	GameRunner();
	void Tick();
	void SetDirection(Direction d);
	void Run();
	void Quit();
	bool IsRunning();
};

