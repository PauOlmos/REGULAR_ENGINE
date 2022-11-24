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
	Type KLK;
	GameObject* MyFirstGO = nullptr;

};