#pragma once
#include <vector>
#include <string>
using namespace std;

class Meshes;
class Components;
class Transform;

class GameObject {
public:
	GameObject();
	~GameObject();
	GameObject* parent;
	vector<GameObject*> Children;
	vector<Components*> ComponentsList;
	string name;
	Transform* transform;

	GameObject(GameObject* parent, string name);


};