#include "GameRunner.h"
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;

void GameRunner::DrawBoard()
{
	//COORD coord = { 0, 0 };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//
	//for (int x = -1; x < 20; x++) {
	//	for (int y = -1; y < 20; y++) {
	//		if (x == player.X && y == player.Y) {
	//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//			std::cout << "O";
	//		}
	//		else if (x == -1 || x == 19 || y == -1 || y == 19) {
	//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	//			std::cout << "#";
	//		}
	//		else {
	//			
	//			std::cout << " ";
	//		}
	//	}
	//	std::cout << endl;
	//}
}

GameRunner::GameRunner()
{
	playerDirection = Direction::RIGHT;
	player = { 10, 0 };

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
		player.X--;
		break;
	case Direction::DOWN:
		player.X++;
		break;
	case Direction::LEFT:
		player.Y--;
		break;
	case Direction::RIGHT:
		player.Y++;
		break;
	case Direction::NONE:
	default:
		break;
	}

	DrawBoard();
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

Point GameRunner::GetBuffer()
{
	return player;
}
