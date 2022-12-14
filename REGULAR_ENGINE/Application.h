#pragma once

#include "p2List.h"
#include "Globals.h"
#include "Timer.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleRenderer3D.h"
#include "ModuleCamera3D.h"
#include "ModuleSceneIntro.h"
#include "imgui_menu.h"
#include "ModuleOpenGL_Primitives.h"
#include "ModuleLoadFBX.h"


class Application
{
public:
	ModuleWindow* window;
	ModuleInput* input;
	ModuleRenderer3D* renderer3D;
	ModuleCamera3D* camera;
	ModuleSceneIntro* scene_intro;
	imgui_menu* ImGui_menu;
	ModuleOpenGL_Primitives* primitives1;
	ModuleLoadFBX* loadFBX;

private:

	Timer	ms_timer;
	p2List<Module*> list_modules;

public:
	float	dt;
	Application();
	~Application();

	Timer lastSecFrameTime;
	Timer startupTime;
	Uint32 lastSecFrameCount = 0;
	Uint32 prevLastSecFrameCount = 0;
	Uint64 frameCount = 0;

	bool Init();
	update_status Update();
	bool CleanUp();

private:

	void AddModule(Module* mod);
	void PrepareUpdate();
	void FinishUpdate();
};