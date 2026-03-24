#pragma once
#include "GameRunner.h"
class KeyboardInput
{
private: 
	GameRunner* game;
public:
	KeyboardInput(GameRunner* g);
	void CheckInput();
	void Run();
};

