#include "GameState.h"

GameState::GameState()
{
    player = { 10, 0 };
    BoardSize = 20;
}

int GameState::GetBoardSize()
{
    return BoardSize;
}
