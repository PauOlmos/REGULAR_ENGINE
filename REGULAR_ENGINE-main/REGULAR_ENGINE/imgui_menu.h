#pragma once
#include "Module.h"
#include "Globals.h"
class imgui_menu : public Module {
public:
	bool Start();

	imgui_menu(Application* app, bool start_enabled = true);
	~imgui_menu();

public:
	bool KLK(bool* p_open);
	float fps = 0.f;
	float start_time = 0;
	float frame_time = 0;
	double delta = 0;
	bool fullscreen = false;
	bool Vsync = true;
	float Brightness = 1.f;

	bool help_ = false;
	bool showExample = false;
	bool about_ = false;
	bool application_ = false;
	bool configuration_ = false;
	bool window_ = false;
	bool initedScreenSizes = false;
	bool hardware_ = false;


	float WindowHeight;
	float WindowWidth;

	float WindowHeightInit;
	float WindowWidthInit;

};