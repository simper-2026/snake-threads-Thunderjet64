#include "KeyboardInput.h"
#include <conio.h>
#include <chrono>
#include "Direction.h"
#include <thread>

using namespace std;

KeyboardInput::KeyboardInput(GameRunner* g)
{
	game = g;
}

void KeyboardInput::CheckInput()
{
	if (_kbhit())
	{
		int ch = _getch();
		switch (ch)
		{
		case 'w':
		case 'W':
		case 72:
			game->SetDirection(Direction::UP); 
			break;
		case 's':
		case 'S':
		case 80:
			game->SetDirection(Direction::DOWN);
			break;
		case 'a':
		case 'A':
		case 75:
			game->SetDirection(Direction::LEFT); 
			break;
		case 'd':
		case 'D':
		case 77:
			game->SetDirection(Direction::RIGHT);
			break;
		}
	}
}

void KeyboardInput::Run()
{
	while (true)
	{
		CheckInput();

		this_thread::sleep_for(chrono::milliseconds(20));

	}
}
