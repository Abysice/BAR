#ifndef GAME_H
#define GAME_H

#include "BAREngine.h"


extern "C"
{
	BARMODULEEXPORT Application *ConstructApplication(void);
}


class Game : public Application, public Singleton<Game>
{
public:
	Game();

};




extern Game * TheGame;


#endif