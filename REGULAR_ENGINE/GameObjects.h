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
	GameObject(GameObject* parent, string name);
	~GameObject();
	GameObject* parent;
	vector<GameObject*> Children;
	vector<Components*> ComponentsList;
	string name;
	Transform* transform;
	Meshes* GOMesh;

	void CreateInspector();


};