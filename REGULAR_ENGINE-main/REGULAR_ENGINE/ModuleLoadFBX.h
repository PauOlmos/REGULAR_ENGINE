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

};