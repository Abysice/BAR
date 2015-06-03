#ifndef ENGINE_H
#define ENGINE_H


#include "BARDefines.h"
#include "BARRendering.h"



class Engine
{
private:
	static Engine * instance;
	GLFWwindow * window;
public:
	Engine() = default;

	//Initialize the Windowing program and engine
	void Init(void);
	//Draw a frame
	void Render(void);
	//Return the singleton instance
	static Engine * GetInstance()
	{
		if (!instance)
			instance = new Engine();

		return instance;
	};


};


#endif