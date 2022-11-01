#pragma once
#include "Module.h"
#include "Globals.h"

#include "cimport.h"
#include "scene.h"
#include "postprocess.h"

class ModuleGameObjects : public Module {
public:
	ModuleGameObjects(Application* app, bool start_enabled = true);

	bool Start();
	update_status Update(float dt);

	void ModifyQuad();
	void ModifyPyramide();
	void ModifyPPlanes();
	void ModifyCilindres();
	update_status PostUpdate();



	int numQuads = 0;
	int numPyramides = 0;
	int numPPlanes = 0;
	int numCilindres = 0;
	vector<Quad*> QuadList;
	vector<Pyramide*> PyramideList;
	vector<PPlane*> PPlaneList;
	vector<Cilindre*> CilindreList;
	vec3 X, Y, Z;


	bool CleanUp();
};