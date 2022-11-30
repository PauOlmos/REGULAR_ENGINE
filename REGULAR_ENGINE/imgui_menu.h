#pragma once
#include "Module.h"
#include "Globals.h"
#include "GameObjects.h"

#include<vector>
#include <imgui.h>

class imgui_menu : public Module {
public:
	bool Start();

	imgui_menu(Application* app, bool start_enabled = true);
	~imgui_menu();
	void HistogramFps();
	void HistogramMs();
	//bool CleanUp();
	void HierarchyTree(GameObject* rootGO_);

public:
	int selectedQ;
	int selectedP;
	int selectedPP;
	int selectedC;
	int selectedType = -1;
	bool testing = false;
	bool DrawGui(bool* p_open);
	void DeleteGO(GameObject* deleting);
	float FPSStart;
	float averageFps = 0.f;
	float frameTicks = 0.f;
	float showDelay = 0.f;
	float _maxFPS = 30.f;
	float start_time = 0;
	float frame_time = 0;
	double delta = 0;
	bool fullscreen = false;
	bool active16_9 = false;

	bool BakerHouseRenderer = true;
	bool GiantShpereRenderer = false;
	bool CubeRenderer = false;
	bool CilindreRenderer = false;
	bool PiramidRenderer = false;
	bool PPlaneRenderer = false;

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
	float WindowSize;

	bool released = true;

	float WindowHeightInit;
	float WindowWidthInit;

	GameObject* rootGO = nullptr;
	GameObject* firstGO = nullptr;

	bool deleteGameObjects = false;

	bool movingGO = false;
	int klk = -1;
private:

	std::vector<float> FPS;
	std::vector<float> Miliseconds;
};