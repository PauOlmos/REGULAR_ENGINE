#include "GameObjects.h"
#include "Application.h"
#include "imgui_menu.h"
#include "Transform.h"

GameObject::GameObject()
{
	name = "rootGameObject";
	parent = nullptr;
	transform = new Transform(this);
	ComponentsList.push_back(transform);
}

GameObject::GameObject(GameObject* parent, string name)
{
	this->name = name;
	this->parent = parent;
	transform = new Transform(this);
	ComponentsList.push_back(transform);
	
	if (parent != nullptr) {
		parent->Children.push_back(this);
	}
}

GameObject::~GameObject()
{
}

