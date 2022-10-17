#pragma once
#include "Module.h"
#include "Globals.h"

struct Quads {
	~Quads();
	Quads() {}

	uint id_indices = 0; // index in VRAM
	uint num_indices = 0;
	uint* indices = nullptr;
	uint id_vertices = 0; // unique vertex in VRAM
	uint num_vertices = 0;
	float* vertices = nullptr;

	void Render();
};

class ModuleOpenGL_Primitives : public Module {
	struct Triangle
	{
		float v0[3] = { 0.f,0.f,0.f };
		float v1[3] = { 2.f,0.f,0.f };
		float v2[3] = { 1.f,2.f,-1.f };
		float v3[3] = { 2.f, 0.f, -2.f };
		float v4[3] = { 0.f, 0.f, -2.f };
	};
public:
	ModuleOpenGL_Primitives(Application* app, bool start_enabled = true);
	~ModuleOpenGL_Primitives();

	bool Start();
	bool PostUpdate();
	update_status Update(float dt);
	void DrawCube();
	void DrawPiramid();
	bool PreUpdate();
	bool CleanUp();
	void DrawCilindre(float radius, float leght);
	float Quad;

	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
	
private:
	bool wireFrameView = false;
	bool depthTest = false;
	bool cullFace = false;
	bool lighting = true;
	bool colorMaterial = false;
	bool texture2D = false;
	bool renderMode = false;
	bool normalize = false; 
private:
		//vector<Quads*> Cubes;
};
