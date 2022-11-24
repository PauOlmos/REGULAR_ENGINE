#pragma once
#include "Module.h"
#include "Globals.h"

#include "cimport.h"
#include "scene.h"
#include "postprocess.h"
#include <string>
using namespace std;

class ModuleOpenGL_Primitives : public Module {

public:
	ModuleOpenGL_Primitives(Application* app, bool start_enabled = true);
	~ModuleOpenGL_Primitives();

	bool Start();
	bool PostUpdate();
	update_status Update(float dt);
	bool PreUpdate();
	bool CleanUp();

	bool wireFrameView = false;
	bool depthTest = false;
	bool cullFace = false;
	bool lighting = false;

private:

};
