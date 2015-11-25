#ifndef APPLICATION_H
#define APPLICATION_H

#include "BARBase.h"


// Application class, to be subtyped by games pluging into the engine
class Application : public Singleton<Application>
{
public:
	BARAPI Application();
	BARAPI virtual ~Application();
};



BARAPI extern Application *TheApplication;

#endif