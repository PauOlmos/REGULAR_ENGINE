#pragma once
#include "Module.h"
#include "Globals.h"

#include "cimport.h"
#include "scene.h"
#include "postprocess.h"

#include <string>
using namespace std;

struct Quad {
	Quad();
	~Quad();
	const char* name[25];
	int numVertices = 8;
	vec3 positon;

	vec3 scale;
	float Totalscale;
	float v0[3] = { 0.f + positon.x + scale.x, 1.f + positon.y + scale.y, 0.f + positon.z + scale.z };
	float v1[3] = { 0.f + positon.x + scale.x, 0.f + positon.y + scale.y, 0.f + positon.z + scale.y };
	float v2[3] = { 0.f + positon.x + scale.x, 0.f + positon.y + scale.y, 1.f + positon.z + scale.y };
	float v3[3] = { 0.f + positon.x + scale.x, 1.f + positon.y + scale.y, 1.f + positon.z + scale.y };
	float v4[3] = { 1.f + positon.x + scale.x, 1.f + positon.y + scale.y, 0.f + positon.z + scale.y };
	float v5[3] = { 1.f + positon.x + scale.x, 1.f + positon.y + scale.y, 1.f + positon.z + scale.y };
	float v6[3] = { 1.f + positon.x + scale.x, 0.f + positon.y + scale.y, 1.f + positon.z + scale.y };
	float v7[3] = { 1.f + positon.x + scale.x, 0.f + positon.y + scale.y, 0.f + positon.z + scale.y };
};

struct Pyramide {
	Pyramide();
	~Pyramide();
	const char* name[25];
	int numVertices = 5;
	vec3 positon;
	float v0[3] = { 0.f + positon.x,0.f + positon.y,0.f + positon.z };
	float v1[3] = { 2.f + positon.x,0.f + positon.y,0.f + positon.z };
	float v2[3] = { 1.f + positon.x,2.f + positon.y,1.f + positon.z };
	float v3[3] = { 2.f + positon.x, 0.f + positon.y, 2.f + positon.z };
	float v4[3] = { 0.f + positon.x, 0.f + positon.y, 2.f + positon.z };
};

class ModuleOpenGL_Primitives : public Module {

public:
	ModuleOpenGL_Primitives(Application* app, bool start_enabled = true);
	~ModuleOpenGL_Primitives();

	bool Start();
	bool PostUpdate();
	update_status Update(float dt);
	bool PreUpdate();
	bool CleanUp();
	void DrawCube(Quad* Q);
	void DrawPiramid(Pyramide* P);
	void DrawCilindre(float radius, float leght);

	float Objectx = 0.f;
	float Objecty = 0.f;
	float Objectz = 0.f;
	int numQuads = 0;
	int numPyramides = 0;
	vector<Quad*> QuadList;
	vector<Pyramide*> PyramideList;
	vec3 X, Y, Z;


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
