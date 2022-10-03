#pragma once
#include "Module.h"
#include "Globals.h"

class imgui_close_app : public Module {
public:
	imgui_close_app(Application* app, bool start_enabled = true);
	~imgui_close_app();

public:
	bool KLK(bool* p_open);
};