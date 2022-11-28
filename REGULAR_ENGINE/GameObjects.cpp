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

void GameObject::CreateInspector()
{
	if (ImGui::Begin("Inspector")) {
		for (size_t i = 0; i < ComponentsList.size(); i++)
		{
			ComponentsList[i]->Inspector();
		}
	}
	ImGui::End();
}

GameObject::~GameObject()
{
	if (parent != nullptr)
	{
		for (size_t i = 0; i < Children.size(); i++)
		{
			delete Children[i];
			Children[i] = nullptr;
		}
	}

	//transform = nullptr;
	Children.clear();
	for (size_t i = 0; i < ComponentsList.size(); i++)
	{
		delete ComponentsList[i];
		ComponentsList[i] = nullptr;
	}

}
