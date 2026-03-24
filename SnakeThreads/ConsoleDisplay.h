#pragma once
#include "GameRunner.h"
#include "GameState.h"
class ConsoleDisplay
{
private:
	GameRunner* game;
	void DrawBoard();
public:
	ConsoleDisplay(GameRunner* g);
	void Run();
};

