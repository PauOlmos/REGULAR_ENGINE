#pragma once
#include "Module.h"
#include "Globals.h"
#include <string>
using namespace std;
struct MyMesh {
	~MyMesh();
	MyMesh() {}

	uint id_indices = 0; // index in VRAM
	uint num_indices = 0;
	uint* indices = nullptr;
	uint id_vertices = 0; // unique vertex in VRAM
	uint num_vertices = 0;
	float* vertices = nullptr;

	void Render();
};

class ModuleLoadFBX : public Module
{
public:
	ModuleLoadFBX(Application* app, bool start_enabled = true);

	void LoadFile(string file_path);
	void LoadMesh(MyMesh* mesh);

	update_status PostUpdate(float dt);
	//bool Init();
	bool CleanUp();
	int width = 0, height = 0;
private:
	vector<MyMesh*> meshes;
};