#pragma once
#include "Module.h"
#include "Globals.h"

class ModuleOpenGL_Primitives : public Module {
public:
	ModuleOpenGL_Primitives(Application* app, bool start_enabled = true);
	~ModuleOpenGL_Primitives();

	bool Start();
	bool PostUpdate();
	update_status Update(float dt);
	bool PreUpdate();
	bool CleanUp();

};