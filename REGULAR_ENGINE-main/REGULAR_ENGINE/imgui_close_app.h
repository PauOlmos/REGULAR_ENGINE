#pragma once
#include "Module.h"
#include "Globals.h"

class imgui_close_app : public Module {
public:
	imgui_close_app(Application* app, bool start_enabled = true);
	~imgui_close_app();

public:
	bool KLK(bool* p_open);
	float fps = 0.f;
	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	double delta = 0;
	bool fullscreen = false;
	bool Vsync = true;

	bool help_ = false;
	bool About_ = false;
	bool Application_ = false;
	bool Configuration_ = false;
	bool Window_ = false;
};