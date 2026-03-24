#pragma once
#include "Direction.h"
#include <atomic>
#include "Point.h"


class GameRunner
{
private:
	std::atomic<Direction> playerDirection;
	Point player;
	void DrawBoard();
public:
	GameRunner();
	void Tick();
	void SetDirection(Direction d);
	void Run();
};

