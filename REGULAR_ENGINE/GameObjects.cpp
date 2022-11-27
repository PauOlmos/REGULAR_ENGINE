#include "GameObjects.h"
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

	name = nullptr;
	this->parent = nullptr;

	transform = nullptr;

	for (size_t i = 0; i < Children.size(); i++)
	{
		delete Children[i];
		Children[i] = nullptr;
	}
	ComponentsList.clear();


}

