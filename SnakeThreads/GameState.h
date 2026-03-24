#pragma once
#include "Point.h"
class GameState
{
private:
	int BoardSize;
public:
	GameState();
	Point player;
	int GetBoardSize();
};

