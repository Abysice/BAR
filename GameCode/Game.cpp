#include "Game.h"

//these need to be here to link to the engine
Game *TheGame = nullptr;

//these need to be here to link to the engine
Application *ConstructApplication(void)
{
	return (new Game);
}

///////////////////////////////////////////////////////////////////////////////////////////

Game::Game() : Singleton<Game>(TheGame)
{

}

