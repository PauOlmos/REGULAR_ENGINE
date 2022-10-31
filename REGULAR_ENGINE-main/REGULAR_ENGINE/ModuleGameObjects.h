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

	update_status PostUpdate();

	bool CleanUp();
};