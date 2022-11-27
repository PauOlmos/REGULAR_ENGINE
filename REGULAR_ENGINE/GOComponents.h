#pragma once
#include "GameObjects.h"

class GameObject;

enum class Type {
	NONE, TRANSFORM, MESH
};

class Components {
public:
	
	Components(GameObject* parent);
	~Components();
	virtual void Inspector();

	Type KLK;
	GameObject* MyFirstGO = nullptr;

};