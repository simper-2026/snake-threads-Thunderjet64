#pragma once
#include "GameRunner.h"
class ConsoleDisplay
{
private:
	GameRunner* game;
	void DrawBoard();
public:
	ConsoleDisplay(GameRunner* g);
	void Run();
};

