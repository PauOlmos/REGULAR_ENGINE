#pragma once
#include "GOComponents.h"
#include "GameObjects.h"

class GameObject;
class Components;
struct MyMesh;

class Meshes : public Components {
public: 

	Meshes();
	Meshes(GameObject* GOMesh);

	~Meshes();
	GameObject* MeshGO;
	MyMesh* Mesh;
};