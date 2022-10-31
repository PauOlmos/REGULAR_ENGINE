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

	vec3 scale;
	float Totalscale;
	float v0[3] = { 0.f + positon.x,0.f + positon.y,0.f + positon.z };
	float v1[3] = { 2.f + positon.x,0.f + positon.y,0.f + positon.z };
	float v2[3] = { 1.f + positon.x,2.f + positon.y,1.f + positon.z };
	float v3[3] = { 2.f + positon.x, 0.f + positon.y, 2.f + positon.z };
	float v4[3] = { 0.f + positon.x, 0.f + positon.y, 2.f + positon.z };
};

struct PPlane {

	PPlane();
	~PPlane();
	const char* name[25];
	int numVertices = 4;
	vec3 positon;

	vec3 scale;
	float Totalscale;
	float v0[3] = { 0.f + positon.x,0.f + positon.y,0.f + positon.z };
	float v1[3] = { 1.f + positon.x,0.0f + positon.y,1.f + positon.z };
	float v2[3] = { 1.f + positon.x,0.f + positon.y,0.f + positon.z };
	float v3[3] = { 0.f + positon.x, 0.f + positon.y, 1.f + positon.z };
};

struct Cilindre {

	Cilindre();
	~Cilindre();

	const char* name[25];
	vec3 positon;
	vec3 scale;

};

class ModuleOpenGL_Primitives : public Module {

public:
	ModuleOpenGL_Primitives(Application* app, bool start_enabled = true);
	~ModuleOpenGL_Primitives();

	bool Start();
	bool PostUpdate();
	update_status Update(float dt);
	bool PreUpdate();
	void ModifyQuad();
	void ModifyPyramide();
	void ModifyPPlanes();
	void ModifyCilindres();
	void DrawPrimitives();
	bool CleanUp();

	void DrawCube(Quad* Q);
	void DrawPPlane(PPlane* PP);
	void DrawPiramid(Pyramide* P);
	void DrawCilindre(Cilindre* C, float radius, float leght);

	int numQuads = 0;
	int numPyramides = 0;
	int numPPlanes = 0;
	int numCilindres = 0;
	vector<Quad*> QuadList;
	vector<Pyramide*> PyramideList;
	vector<PPlane*> PPlaneList;
	vector<Cilindre*> CilindreList;
	vec3 X, Y, Z;


	bool wireFrameView = false;
	bool depthTest = false;
	bool cullFace = false;
	bool lighting = false;

private:

};
