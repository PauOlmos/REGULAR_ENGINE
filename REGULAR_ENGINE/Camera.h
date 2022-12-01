#pragma once
#include "Globals.h"
#include "GOComponents.h"
#include "GameObjects.h"
#include "ModuleLoadFBX.h"
#include "Mesh.h"
#include "Camera.h"
#include "glmath.h"

class GameObject;
class Components;


struct MyCamera {

	MyCamera();
	~MyCamera();
	vec3 newPos = { 0, 2, 4 };
	vec3 newRef = { 0, 2, 4 };

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	bool freeMovement = true;
	void Look(const vec3& Position, const vec3& Reference, bool RotateAroundReference = false);
	void LookAt(const vec3& Spot);
	void Move(const vec3& Movement);
	float* GetViewMatrix();
	float zoomSensitivity = 5.0f;
public:

	void CalculateViewMatrices();

public:

	vec3 X, Y, Z, Position, Reference;

private:

	mat4x4 ViewMatrix, ViewMatrixInverse;
};


class Camera : public Components {
public:

	Camera();
	Camera(GameObject* GOCamera);

	~Camera();
	MyCamera* cameraGO;
};


