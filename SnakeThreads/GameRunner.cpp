#include "GameRunner.h"
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

GameRunner::GameRunner()
{
	playerDirection = Direction::RIGHT;

	_isRunning = true;

	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//CONSOLE_CURSOR_INFO cursorInfo;
	//GetConsoleCursorInfo(hConsole, &cursorInfo);
	//cursorInfo.bVisible = FALSE;
	//SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void GameRunner::Tick()
{
	
	//cout << playerDirection << endl;

	switch (playerDirection)
	{
	case Direction::UP:
		state.player.X--;
		break;
	case Direction::DOWN:
		state.player.X++;
		break;
	case Direction::LEFT:
		state.player.Y--;
		break;
	case Direction::RIGHT:
		state.player.Y++;
		break;
	case Direction::NONE:
	default:
		break;
	}
}


void GameRunner::SetDirection(Direction d)
{
	playerDirection = d;
}

void GameRunner::Run()
{
	while (_isRunning)
	{
		Tick();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
}

void GameRunner::Quit()
{
	_isRunning = false;
}

bool GameRunner::IsRunning()
{
	return _isRunning;
}

GameState GameRunner::GetBuffer()
{
	return state;
}
