#include "Globals.h"
#include "Application.h"
#include "ModuleOpenGL_Primitives.h"
#include "ModuleCamera3D.h"
#include <imgui_impl_sdl.h>

ModuleCamera3D::ModuleCamera3D(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	CalculateViewMatrix();

	X = vec3(1.0f, 0.0f, 0.0f);
	Y = vec3(0.0f, 1.0f, 0.0f);
	Z = vec3(0.0f, 0.0f, 1.0f);

	Position = vec3(0.0f, 0.0f, 5.0f);
	Reference = vec3(0.0f, 0.0f, 0.0f);
}

ModuleCamera3D::~ModuleCamera3D()
{}

// -----------------------------------------------------------------
bool ModuleCamera3D::Start()
{
	LOG(LogType::LOGS, "Setting up the camera");
	bool ret = true;
	return ret;
}

// -----------------------------------------------------------------
bool ModuleCamera3D::CleanUp()
{
	LOG(LogType::LOGS, "Cleaning camera");

	return true;
}

// -----------------------------------------------------------------
update_status ModuleCamera3D::Update(float dt)
{
	// Implement a debug camera with keys and mouse
	// Now we can make this movememnt frame rate independant!
	SDL_Event e;
	bool quit = false;

	float speed = 3.0f * dt;
	if (App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
		speed *= 2;

	}

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_MOUSEWHEEL)
		{
			if (event.wheel.y > 0) // scroll up
			{
				// Put code for handling "scroll up" here!
			}
			else if (event.wheel.y < 0) // scroll down
			{
				// Put code for handling "scroll down" here!
			}
		}
	}
	if(App->input->GetKey(SDL_SCANCODE_U) == KEY_REPEAT) newPos.y += speed;
	if(App->input->GetKey(SDL_SCANCODE_J) == KEY_REPEAT) newPos.y -= speed;

	if (App->input->GetMouseButton(SDL_BUTTON_RIGHT) == KEY_REPEAT) {
		if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) {
			freeMovement = true;
			newPos -= Z * speed;
		}
		if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) {
			freeMovement = true;
			newPos += Z * speed;
		} 


		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) {
			freeMovement = true;
			newPos -= X * speed;
		} 
		if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {
			freeMovement = true;
			newPos += X * speed;
		} 
	}

	if (App->input->GetMouseZ() >= 0) {
		newPos -= Z * zoomSensitivity;
	}
	if (App->input->GetMouseZ() <= 0) {
		newPos += Z * zoomSensitivity;
	}

	if (App->input->GetMouseButton(SDL_BUTTON_MIDDLE) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_LALT) == NULL)
	{
		int dx = -App->input->GetMouseXMotion();
		int dy = -App->input->GetMouseYMotion();

		float Sensitivity = 0.25f;


		if (dx != 0)
		{
			float DeltaX = (float)dx * Sensitivity;

			X = rotate(X, DeltaX, vec3(0.0f, 1.0f, 0.0f));
			Y = rotate(Y, DeltaX, vec3(0.0f, 1.0f, 0.0f));
			Z = rotate(Z, DeltaX, vec3(0.0f, 1.0f, 0.0f));
		}

		if (dy != 0)
		{
			float DeltaY = (float)dy * Sensitivity;

			Y = rotate(Y, DeltaY, X);
			Z = rotate(Z, DeltaY, X);

			if (Y.y < 0.0f)
			{
				Z = vec3(0.0f, Z.y > 0.0f ? 1.0f : -1.0f, 0.0f);
				Y = cross(Z, X);
			}
		}

		Position = Reference + Z * 4;
		freeMovement = true;
	}

	Position = newPos;

	if(App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_LALT) == KEY_REPEAT)
	{
		int dx = -App->input->GetMouseXMotion();
		int dy = -App->input->GetMouseYMotion();

		float Sensitivity = 0.25f;
		if (App->ImGui_menu->selectedType == 0) {
			newRef.x = App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->positon.x + 0.5;
			newRef.y = App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->positon.y + 0.5;
			newRef.z = App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->positon.z + 0.5;
		}
		if (App->ImGui_menu->selectedType == 1) {
			newRef.x = App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->positon.x + 1.5;
			newRef.y = App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->positon.y + 0.5;
			newRef.z = App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->positon.z + 1.5;
		}
		if(dx != 0)
		{
			float DeltaX = (float)dx * Sensitivity;

			X = rotate(X, DeltaX, vec3(0.0f, 1.0f, 0.0f));
			Y = rotate(Y, DeltaX, vec3(0.0f, 1.0f, 0.0f));
			Z = rotate(Z, DeltaX, vec3(0.0f, 1.0f, 0.0f));
		}

		if(dy != 0)
		{
			float DeltaY = (float)dy * Sensitivity;

			Y = rotate(Y, DeltaY, X);
			Z = rotate(Z, DeltaY, X);

			if(Y.y < 0.0f)
			{
				Z = vec3(0.0f, Z.y > 0.0f ? 1.0f : -1.0f, 0.0f);
				Y = cross(Z, X);
			}
		}
		if (App->ImGui_menu->selectedType == 0) {
			App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->Totalscale = (App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->scale.x + App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->scale.y + App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->scale.z);
			Position = newRef + Z * (4 + App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->Totalscale);
		}
		if (App->ImGui_menu->selectedType == 1) {
			App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->Totalscale = (App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->scale.x + App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->scale.y + App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->scale.z);
			Position = newRef + Z * (4 + App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->Totalscale);
		}
		
		freeMovement = false;
	}

	if (freeMovement == false) {
		Look(Position, newRef);
	}
	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN) {
		if (App->ImGui_menu->selectedType == 0) {
			newRef.x = App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->positon.x + 1;
			newRef.y = App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->positon.y + 2;
			newRef.z = App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->positon.z + 4;
			Look(newPos, App->gameObjects->QuadList[App->ImGui_menu->selectedQ]->positon);
			freeMovement = true;
		}
		if (App->ImGui_menu->selectedType == 1) {
			newRef.x = App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->positon.x + 1;
			newRef.y = App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->positon.y + 2;
			newRef.z = App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->positon.z + 4;
			Look(newPos, { App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->positon.x + 0.5f,App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->positon.y + 1,App->gameObjects->PyramideList[App->ImGui_menu->selectedP]->positon.z + 1 });
			freeMovement = true;
		}

	}

	// Recalculate matrix -------------
	CalculateViewMatrix();

	return UPDATE_CONTINUE;
}

// -----------------------------------------------------------------
void ModuleCamera3D::Look(const vec3 &Position, const vec3 &Reference, bool RotateAroundReference)
{
	this->Position = Position;
	this->Reference = Reference;

	Z = normalize(Position - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	if(!RotateAroundReference)
	{
		this->Reference = this->Position;
		this->Position += Z * 0.05f;
	}

	CalculateViewMatrix();
}

// -----------------------------------------------------------------
void ModuleCamera3D::LookAt( const vec3 &Spot)
{
	Reference = Spot;

	Z = normalize(Position - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	CalculateViewMatrix();
}


// -----------------------------------------------------------------
void ModuleCamera3D::Move(const vec3 &Movement)
{
	Position += Movement;
	Reference += Movement;

	CalculateViewMatrix();
}

// -----------------------------------------------------------------
float* ModuleCamera3D::GetViewMatrix()
{
	return &ViewMatrix;
}

// -----------------------------------------------------------------
void ModuleCamera3D::CalculateViewMatrix()
{
	ViewMatrix = mat4x4(X.x, Y.x, Z.x, 0.0f, X.y, Y.y, Z.y, 0.0f, X.z, Y.z, Z.z, 0.0f, -dot(X, Position), -dot(Y, Position), -dot(Z, Position), 1.0f);
	ViewMatrixInverse = inverse(ViewMatrix);
}
