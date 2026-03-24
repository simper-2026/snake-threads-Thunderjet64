#include "KeyboardInput.h"
#include "GameRunner.h"
#include <thread>
#include <chrono>

using namespace std;


int main() {

	GameRunner game;
	KeyboardInput input(&game);

	
	thread inputThread(&KeyboardInput::Run, &input);
	thread gameThread(&GameRunner::Run, &game);
		//input.CheckInput();
		
	

	inputThread.join();
	gameThread.join();
	
}