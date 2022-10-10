#pragma once
#include "Module.h"
#include "Globals.h"

class ModuleLoadFBX : public Module {
public:
	ModuleLoadFBX(Application* app, bool start_enabled = true);
	~ModuleLoadFBX();

	bool Start();
	bool PostUpdate();
	update_status Update(float dt);
	bool PreUpdate();
	bool CleanUp();

	uint id_index = 0; // index in VRAM
	uint num_index = 0;
	uint* index = nullptr;
	uint id_vertex = 0; // unique vertex in VRAM
	uint num_vertex = 0;
	float* vertex = nullptr;

};

class M_mesh : public Module {
public:
	M_mesh(Application* app, bool start_enabled = true);
	~M_mesh();

	int num_vertices;

};