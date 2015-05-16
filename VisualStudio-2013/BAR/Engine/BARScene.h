#include "BARNode.h"

#include <list>
#include <string>


//Class to encapsulate the scene graph and all nodes in it
class Scene
{
private:
	std::string worldName;
	std::list<Node> renderList; //list of all things to be rendered, maybe switch to a map
	//Camera * mainCamera;

public:
	Scene(std::string name);
	~Scene();


};