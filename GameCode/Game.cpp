#include "Game.h"



Game *TheGame = nullptr;



Application *ConstructApplication(void)
{
	return (new Game);
}



Game::Game() : Singleton<Game>(TheGame)
{

}

