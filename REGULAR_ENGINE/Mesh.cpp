#include "Mesh.h"

Meshes::Meshes():Meshes(nullptr)
{
}

Meshes::Meshes(GameObject* GOMesh) : Components(GOMesh)
{
	Mesh = nullptr;
	MeshGO = GOMesh;
}

Meshes::~Meshes()
{
}

