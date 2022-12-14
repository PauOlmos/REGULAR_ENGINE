#pragma once
#include "Globals.h"
#include "GOComponents.h"
#include "GameObjects.h"
#include "glmath.h"
#include "imgui.h"
#include "Application.h"
#include"MathGeoLib/include/Math/float3.h"
#include"MathGeoLib/include/Math/Quat.h"

class GameObject;
class Components;
struct MyMesh;
class aiNode;

class Transform : public Components
{
public:

	Transform();
	Transform(GameObject* Transform);
	~Transform();

	void Inspector();

	void Tranformation();

	mat4x4 transformationMatrix = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	vec3 position = { 0,0,0 };
	vec3 scale = { 1,1,1 };
	vec3 rotation = { 0,0,0.001 };

	float angle = 180;

private:

};
