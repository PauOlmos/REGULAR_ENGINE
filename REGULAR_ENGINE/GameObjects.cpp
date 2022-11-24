#include "GameObjects.h"

GameObject::GameObject()
{
	name = "rootGameObject";
	parent = nullptr;
}

GameObject::~GameObject()
{
}

GameObject::GameObject(GameObject* parent)
{
	name = "GameObjectKLK";
	this->parent = parent;
	if (parent != nullptr) {
		parent->Children.push_back(this);
	}
}
