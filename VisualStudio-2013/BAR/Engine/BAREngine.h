#ifndef ENGINE_H
#define ENGINE_H

#include "BARApplication.h"
#include "BARRendering.h"
#include "BARBase.h"



class Engine : public Singleton<Engine>
{
private:
	GLFWwindow * window;
public:
	Engine();

	//Initialize the Windowing program and engine
	void Init(void);
	//Draw a frame
	void Render(void);

};

extern Engine * TheEngine;

#endif