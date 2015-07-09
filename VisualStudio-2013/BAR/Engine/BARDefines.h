#ifndef BARDEFINES_H
#define BARDEFINES_H

//clean these up later


#include <stdlib.h>
#include <iostream>
#include <fstream>



#define DEBUG_MODE 1

#ifdef C4ENGINEMODULE
	#define BARAPI __declspec(dllexport)
#else
	#define BARAPI __declspec(dllimport)
#endif


#define BARMODULEEXPORT __declspec(dllexport)
#define BARMODULEIMPORT __declspec(dllimport)

#endif