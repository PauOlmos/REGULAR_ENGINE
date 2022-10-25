#pragma once
#include "Module.h"
#include "Globals.h"
#include "glmath.h"

class ModuleCamera3D : public Module
{
public:
	ModuleCamera3D(Application* app, bool start_enabled = true);
	~ModuleCamera3D();
	vec3 newPos = {0, 2, 4};
	vec3 newRef = {0, 2, 4};

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	bool freeMovement = true;
	void Look(const vec3 &Position, const vec3 &Reference, bool RotateAroundReference = false);
	void LookAt(const vec3 &Spot);
	void Move(const vec3 &Movement);
	float* GetViewMatrix();
	float zoomSensitivity = 5.0f;
private:

	void CalculateViewMatrix();

public:
	
	vec3 X, Y, Z, Position, Reference;

private:

	mat4x4 ViewMatrix, ViewMatrixInverse;
};