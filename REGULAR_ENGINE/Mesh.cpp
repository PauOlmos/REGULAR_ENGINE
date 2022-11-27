#include "Mesh.h"
#include "imgui.h"

Meshes::Meshes():Meshes(nullptr)
{
}

Meshes::Meshes(GameObject* GOMesh) : Components(GOMesh)
{
	MyFirstGO = GOMesh;
	Mesh = nullptr;
	KLK = Type::MESH;

}


Meshes::~Meshes()
{
	MyFirstGO = nullptr;
	Mesh = nullptr;
}

void Meshes::Inspector()
{
	ImGui::Text("Number Vertices: %d", Mesh->num_vertices / 3);
	ImGui::Text("Number Indices: %d", Mesh->num_indices);
}

