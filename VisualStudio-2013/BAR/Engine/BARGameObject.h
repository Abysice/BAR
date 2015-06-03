#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "BARMatrix.h"



class Scene;

//base class to represent a node in the scene Graph
class GameObject
{
private:
	Matrix4 transform;
	Scene * NodeScene;
public:
	GameObject();
	~GameObject();
};


#endif
