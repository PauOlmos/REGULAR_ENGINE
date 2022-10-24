#pragma once
#include "Module.h"
#include "Globals.h"

struct Quad
{
	float v0[3] = { 0.f, 1.f, 0.f };
	float v1[3] = { 0.f, 0.f, 0.f };
	float v2[3] = { 0.f, 0.f, 1.f };
	float v3[3] = { 0.f, 1.f, 1.f };
	float v4[3] = { 1.f, 1.f, 0.f };
	float v5[3] = { 1.f, 1.f, 1.f, };
	float v6[3] = { 1.f, 0.f, 1.f, };
	float v7[3] = { 1.f, 0.f, 0.f, };
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

	float Objectx = 0.f;
	float Objecty = 0.f;
	float Objectz = 0.f;
	
private:
	bool wireFrameView = false;
	bool depthTest = false;
	bool cullFace = false;
	bool lighting = true;
	bool colorMaterial = false;
	bool texture2D = false;
	bool renderMode = false;
	bool normalize = false; 
};
