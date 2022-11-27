#include "Transform.h"

Transform::Transform() : Components(nullptr)
{

}

Transform::Transform(GameObject* Transform) : Components(Transform)
{
	MyFirstGO = Transform;

	KLK = Type::TRANSFORM;
}

Transform::~Transform()
{
}

void Transform::Inspector()
{
	ImGui::Text("position");
	ImGui::InputFloat3("Position", &position);
	ImGui::Text("Scale:");
	ImGui::InputFloat3("Scale", &scale);
	ImGui::Text("Rotation:");
	ImGui::InputFloat3("Rotate", &rotation);
	Tranformation();
}

void Transform::Tranformation()
{

	transformationMatrix.translate(position.x, position.y, position.z);


	transformationMatrix.scale(scale.x, scale.y, scale.z);

}