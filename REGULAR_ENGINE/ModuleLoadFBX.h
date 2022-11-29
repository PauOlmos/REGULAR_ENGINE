#pragma once
#include "Module.h"
#include "Globals.h"
#include "cimport.h"
#include "scene.h"
#include "postprocess.h"
#include "GOComponents.h"

#include <string>
using namespace std;

class GameObject;
class Transform;

enum class Primitive_Type {
	CUBE,CILINDRE,PYRAMIDE,PLANE,SPHERE,LOADED
};

struct MyMesh {

	MyMesh();
	~MyMesh();

	uint id_indices = 0; // index in VRAM
	uint num_indices = 0;
	uint* indices = nullptr;
	uint id_vertices = 0; // unique vertex in VRAM
	uint num_vertices = 0;
	float* vertices = nullptr;
	GameObject* meshK = nullptr;

	bool auxiliar = false;
	void Render();
};

class ModuleLoadFBX : public Module
{
public:
	ModuleLoadFBX(Application* app, bool start_enabled = true);
	bool Start();
	GameObject* LoadFile(string file_path, Primitive_Type TYPE, GameObject* thisRoot);
	GameObject* CreatePrimitives(Primitive_Type TYPE);
	void LoadMesh(MyMesh* mesh);
	
	update_status PostUpdate(float dt);
	//bool Init();
	bool CleanUp();
	GameObject* PrimitiveMesh = nullptr;
	GameObject* PrimitivePlaneMesh = nullptr;
	GameObject* PrimitiveCubeMesh = nullptr;
	GameObject* PrimitivePyramideMesh = nullptr;
	GameObject* PrimitiveCilindreMesh = nullptr;
	GameObject* PrimitiveSphereMesh = nullptr;
	

private:
	vector<MyMesh*> meshes;
};