#include "KeyboardInput.h"
#include "GameRunner.h"
#include <thread>
#include <chrono>

using namespace std;


int main() {

	GameRunner game;
	KeyboardInput input(&game);

	
	thread inputThread(&KeyboardInput::Run, &input);

		//input.CheckInput();
		
	while (true)
	{
		game.Tick();
		this_thread::sleep_for(chrono::milliseconds(200));
	}

	inputThread.join();

	
}