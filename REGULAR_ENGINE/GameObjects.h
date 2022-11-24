#pragma once
#include <vector>
#include <string>
using namespace std;

class GameObject {
public:
	GameObject();
	~GameObject();

	GameObject* parent;
	vector<GameObject*> Children;

	string name;

	GameObject(GameObject* parent);

};