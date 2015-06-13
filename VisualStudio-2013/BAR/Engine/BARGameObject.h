#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "BARMatrix.h"



class Scene;

//base class to represent a node in the scene Graph
class GameObject
{
public:
	GameObject();
	~GameObject();

	const Matrix4& GetTransform(void)
	{
		Matrix4 ScaleMatrix, RotationMatrix, TranslationMatrix;
		ScaleMatrix.SetScale(scale.x, scale.y, scale.z);
		RotationMatrix.SetEulerAngles(rotation.x, rotation.y, rotation.z);
		TranslationMatrix.SetTranslation(position);

		//add a mark dirty check here later for optimization
		transform = TranslationMatrix * RotationMatrix * ScaleMatrix;
		return transform;
	}

	void SetScale(Vector3 newScale)
	{
		scale = newScale;
	}

	void SetPosition(Vector3 newPosition)
	{
		position = newPosition;
	}

	void SetRotation(Vector3 newRotation)
	{
		rotation = newRotation;
	}
	
private:
	Matrix4 transform;
	Vector3 scale;
	Vector3 rotation;
	Vector3 position;

};


#endif
