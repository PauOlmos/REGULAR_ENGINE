#pragma once
#include "Module.h"
#include "Globals.h"
#include <vector>
using std::vector;


class ModuleLoadFBX : public Module {
public:
	ModuleLoadFBX(Application* app, bool start_enabled = true);
	~ModuleLoadFBX();

	bool Start();
	bool PostUpdate();
	update_status Update(float dt);
	bool PreUpdate();
	bool CleanUp();

	/*void LoadMesh(aiMesh* mesh, aiMesh* mymesh);
	void CopyVertices(aiMesh* mesh, aiMesh* mymesh);
	void CopyFaces(aiMesh* mesh, aiMesh* mymesh);*/

	/*
	uint id_index = 0; // index in VRAM
	uint num_index = 0;
	uint* index = nullptr;
	uint id_vertex = 0; // unique vertex in VRAM
	uint num_vertex = 0;
	float* vertex = nullptr;*/
};
