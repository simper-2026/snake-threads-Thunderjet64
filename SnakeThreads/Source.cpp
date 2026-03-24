#include "KeyboardInput.h"
#include "GameRunner.h"
#include "ConsoleDisplay.h"
#include <thread>
#include <chrono>

using namespace std;


int main() {

	GameRunner game;
	KeyboardInput input(&game);
	ConsoleDisplay console(&game);

	
	thread inputThread(&KeyboardInput::Run, &input);
	thread gameThread(&GameRunner::Run, &game);
	thread displayThread(&ConsoleDisplay::Run, &console);
		//input.CheckInput();
		
	

	inputThread.join();
	gameThread.join();
	displayThread.join();
	
}