#include "BARMatrix.h"

enum NodeType
{
	baseType = 0,
	GeometryNode
};


//base class to represent a node in the scene Graph
class Node
{
private:
	Matrix4 transform;
	Scene *NodeScene;
	NodeType type;
public:
	Node(NodeType t);
	~Node();
};