#ifndef APPLICATION_H
#define APPLICATION_H

#include "BARBase.h"



class Application : public Singleton<Application>
{
public:
	BARAPI Application();
	BARAPI virtual ~Application();
};



BARAPI extern Application *TheApplication;

#endif