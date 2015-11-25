#ifndef GAME_H
#define GAME_H

#include "BAREngine.h"

//Called by the Engine, must be as specified here
extern "C"
{
	BARMODULEEXPORT Application *ConstructApplication(void);
}


class Game : public Application, public Singleton<Game>
{
public:
	Game();

};



//these need to be here to link to the engine
extern Game * TheGame;


#endif