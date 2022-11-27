#pragma once
#include "Globals.h"
#include "GOComponents.h"
#include "GameObjects.h"
#include "ModuleLoadFBX.h"
#include "Mesh.h"

class GameObject;
class Components;
struct MyMesh;

class Meshes : public Components {
public: 

	Meshes();
	Meshes(GameObject* GOMesh);

	~Meshes();
	void Inspector();
	MyMesh* Mesh;
};