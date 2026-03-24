#include "ConsoleDisplay.h"
#include <thread>
#include <chrono>
#include <windows.h>
#include <iostream>

using namespace std;

void ConsoleDisplay::DrawBoard()
{
	Point player = game->GetBuffer();

	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	for (int x = -1; x < 20; x++) {
		for (int y = -1; y < 20; y++) {
			if (x == player.X && y == player.Y) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "O";
			}
			else if (x == -1 || x == 19 || y == -1 || y == 19) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				std::cout << "#";
			}
			else {

				std::cout << " ";
			}
		}
		std::cout << endl;
	}

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cursorInfo);


}

ConsoleDisplay::ConsoleDisplay(GameRunner* g)
{
	game = g;
}

void ConsoleDisplay::Run()
{
	while (game->IsRunning())
	{
		//CheckInput();
		DrawBoard();
		this_thread::sleep_for(chrono::milliseconds(65));

	}
}
