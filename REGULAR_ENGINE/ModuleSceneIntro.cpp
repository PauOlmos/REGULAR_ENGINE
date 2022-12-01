#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "imgui_menu.h"
#include "Primitive.h"
#include "Camera.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG(LogType::LOGS, "Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG(LogType::LOGS, "Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	//Camera global
	ImGui::Begin("Scene");
	{
		// Using a Child allow to fill all the space of the window.
		// It also alows customization
		ImGui::BeginChild("GameRender");
		// Get the size of the child (i.e. the whole draw size of the windows).
		ImVec2 wsize = ImGui::GetWindowSize();
		// Because I use the texture from OpenGL, I need to invert the V from the UV.
		ImGui::Image((ImTextureID)App->renderer3D->cameraBuffer, wsize, ImVec2(0, 1), ImVec2(1, 0));
		ImGui::EndChild();
	}
	ImGui::End();

	//Camera en funci� de l'objecte seleccionat
	ImGui::Begin("GameWindow");
	{
		
		// Using a Child allow to fill all the space of the window.
		// It also alows customization
		ImGui::BeginChild("GameRender");
		// Get the size of the child (i.e. the whole draw size of the windows).
		ImVec2 wsize = ImGui::GetWindowSize();
		
		// Because I use the texture from OpenGL, I need to invert the V from the UV.
		
		if (App->ImGui_menu->firstGO != nullptr && App->ImGui_menu->firstGO != App->ImGui_menu->rootGO) {
			ImGui::Image((ImTextureID)App->ImGui_menu->firstGO->GOCam->cameraGO->cameraBuffer2, wsize, ImVec2(0, 1), ImVec2(1, 0));
		}
		ImGui::EndChild();
	}
	ImGui::End();
	return UPDATE_CONTINUE;
}

