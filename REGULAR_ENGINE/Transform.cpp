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