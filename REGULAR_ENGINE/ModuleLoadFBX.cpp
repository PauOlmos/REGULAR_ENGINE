#include "Globals.h"
#include "Application.h"
#include "ModuleLoadFBX.h"
#include "Transform.h"
#include "scene.h"
#include "Glew/include/glew.h"
#include "Mesh.h"
#include <vector>
#include <string>

#pragma comment (lib, "Assimp/libx86/assimp.lib")

ModuleLoadFBX::ModuleLoadFBX(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}
bool ModuleLoadFBX::Start()
{
	bool ret = true;
	PrimitiveMesh = LoadFile("Assets/BakerHouse.fbx",Primitive_Type::LOADED, App->ImGui_menu->rootGO);

	return ret;
}

MyMesh::MyMesh() : id_indices(0), id_vertices(0)
{
}

MyMesh::~MyMesh() {
	delete[] vertices;
	delete[] indices;
	vertices = nullptr;
	indices = nullptr;
	glDeleteBuffers(1, &id_vertices);
	glDeleteBuffers(1, &id_indices);
	id_vertices = 0;
	id_indices = 0;
}
void MyMesh::Render()
{

	glBindBuffer(GL_ARRAY_BUFFER, id_vertices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_indices);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, NULL);

	glPushMatrix();
	


	meshK->transform->transformationMatrix.translate(meshK->parent->transform->position.x + meshK->transform->position.x, meshK->parent->transform->position.y + meshK->transform->position.y, meshK->parent->transform->position.z + meshK->transform->position.z);
	meshK->transform->transformationMatrix.scale(meshK->parent->transform->scale.x + meshK->transform->scale.x, meshK->parent->transform->scale.y + meshK->transform->scale.y, meshK->parent->transform->scale.z + meshK->transform->scale.z);
	glMultMatrixf(&meshK->transform->transformationMatrix);


	glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, NULL);

	glPopMatrix();
	glDisableClientState(GL_VERTEX_ARRAY);

}
void MyMesh::TransformChildren(GameObject* &parent)
{
	if (parent->Children.size() > 0) { 
		if (auxiliar == true) {
			parent->transform->transformationMatrix.translate((parent->parent->transform->position.x + parent->transform->position.x)/2, parent->parent->transform->position.y, parent->parent->transform->position.z);
			parent->transform->transformationMatrix.scale(parent->parent->transform->scale.x, parent->parent->transform->scale.y, parent->parent->transform->scale.z);
			glMultMatrixf(&parent->transform->transformationMatrix);

		}
		for (int i = 0; i < parent->Children.size(); i++) {
			auxiliar = true;
			TransformChildren(parent->Children[i]);
		}
		
	}
	else {

		parent->transform->transformationMatrix.translate(parent->parent->transform->position.x, parent->parent->transform->position.y, parent->parent->transform->position.z);
		parent->transform->transformationMatrix.scale(parent->parent->transform->scale.x, parent->parent->transform->scale.y, parent->parent->transform->scale.z);
		glMultMatrixf(&parent->transform->transformationMatrix);

	}


}
GameObject* ModuleLoadFBX::LoadFile(string file_path, Primitive_Type TYPE, GameObject* thisRoot)
{
	const aiScene* scene = aiImportFile(file_path.c_str(), aiProcessPreset_TargetRealtime_MaxQuality);
	GameObject* GO = nullptr;
	if (scene != nullptr && scene->HasMeshes())
	{
		switch (TYPE)
		{
		case Primitive_Type::PLANE:
			GO = new GameObject(thisRoot, "Plane");
			break;
		case Primitive_Type::CUBE:
			GO = new GameObject(thisRoot, "Cube");

			break;
		case Primitive_Type::PYRAMIDE:
			GO = new GameObject(thisRoot, "Pyramide");

			break;
		case Primitive_Type::CILINDRE:
			GO = new GameObject(thisRoot, "Cilindre");

			break;
		case Primitive_Type::SPHERE:
			GO = new GameObject(thisRoot, "Sphere");
			break;
		default:
			GO = new GameObject(App->ImGui_menu->rootGO, "GameObject");
			break;
		}
		
		//Iterate scene meshes
		for (int i = 0; i < scene->mNumMeshes; i++) {
			MyMesh* mesh = new MyMesh();

			mesh->num_vertices = scene->mMeshes[i]->mNumVertices;
			mesh->vertices = new float[mesh->num_vertices * 3];
			memcpy(mesh->vertices, scene->mMeshes[i]->mVertices, sizeof(float) * mesh->num_vertices * 3);

			if (scene->mMeshes[i]->HasFaces())
			{

				mesh->num_indices = scene->mMeshes[i]->mNumFaces * 3;
				mesh->indices = new uint[mesh->num_indices]; 


				for (uint j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
				{

					if (scene->mMeshes[i]->mFaces[j].mNumIndices != 3) {
					}
					else {
						memcpy(&mesh->indices[j * 3], scene->mMeshes[i]->mFaces[j].mIndices, 3 * sizeof(uint));
					}
				}
				LoadMesh(mesh);
				Meshes* component = new Meshes(GO);
				mesh->meshK = GO;
				component->Mesh = mesh;
				if (GO->ComponentsList.size() == 1) {
					GO->ComponentsList.push_back(component);
				}
			}
			else {
				delete mesh;
			}
		}
		App->ImGui_menu->firstGO = App->ImGui_menu->rootGO;
		aiReleaseImport(scene);
		return GO;
	}
}


GameObject* ModuleLoadFBX::CreatePrimitives(Primitive_Type TYPE)
{
	GameObject* child;
	switch (TYPE)
	{
	case Primitive_Type::PLANE:
		if (PrimitiveMesh != nullptr) {
			PrimitiveMesh = LoadFile("Assets/Primitives/Plane.fbx", Primitive_Type::PLANE, App->ImGui_menu->firstGO);
		}
		else{
			PrimitiveMesh = LoadFile("Assets/Primitives/Plane.fbx", Primitive_Type::PLANE, App->ImGui_menu->rootGO);
		}
		break;
	case Primitive_Type::CUBE:
		if (PrimitiveMesh != nullptr) {
			PrimitiveMesh = LoadFile("Assets/Primitives/Cube.fbx", Primitive_Type::CUBE, App->ImGui_menu->firstGO);
		}
		else {
			PrimitiveMesh = LoadFile("Assets/Primitives/Cube.fbx", Primitive_Type::CUBE, App->ImGui_menu->rootGO);
		}
		break;	
	case Primitive_Type::PYRAMIDE:
		if (PrimitiveMesh != nullptr) {
			PrimitiveMesh = LoadFile("Assets/Primitives/Pyramide.fbx", Primitive_Type::PYRAMIDE, App->ImGui_menu->firstGO);
		}
		else {
			PrimitiveMesh = LoadFile("Assets/Primitives/Pyramide.fbx", Primitive_Type::PYRAMIDE, App->ImGui_menu->rootGO);
		}
		break;
	case Primitive_Type::CILINDRE:
		if (PrimitiveMesh != nullptr) {
			PrimitiveMesh = LoadFile("Assets/Primitives/Cilindre.fbx", Primitive_Type::CILINDRE, App->ImGui_menu->firstGO);
		}
		else {
			PrimitiveMesh = LoadFile("Assets/Primitives/Cilindre.fbx", Primitive_Type::CILINDRE, App->ImGui_menu->rootGO);
		}
		break;
	case Primitive_Type::SPHERE:
		if (PrimitiveMesh != nullptr) {
			PrimitiveMesh = LoadFile("Assets/Primitives/Sphere.fbx", Primitive_Type::SPHERE, App->ImGui_menu->firstGO);
		}
		else{
		PrimitiveMesh = LoadFile("Assets/Primitives/Sphere.fbx", Primitive_Type::SPHERE, App->ImGui_menu->rootGO);
		}
		break;
	}
	return nullptr;
}

void ModuleLoadFBX::LoadMesh(MyMesh* mesh) {

	glGenBuffers(1, (GLuint*)&(mesh->id_vertices));
	glGenBuffers(1, (GLuint*)&(mesh->id_indices));

	glBindBuffer(GL_ARRAY_BUFFER, mesh->id_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh->num_vertices * 3, mesh->vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->id_indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * mesh->num_indices, mesh->indices, GL_STATIC_DRAW);

	glDisableClientState(GL_VERTEX_ARRAY);

	meshes.push_back(mesh);
}

update_status ModuleLoadFBX::PostUpdate(float dt)
{
	for (int i = 0; i < meshes.size(); i++) {
		meshes[i]->Render();
	}
	return UPDATE_CONTINUE;
}
bool ModuleLoadFBX::CleanUp()
{
	for (int i = 0; i < meshes.size(); i++) {
		delete meshes[i];
		meshes[i] = nullptr;
	}
	meshes.clear();
	aiDetachAllLogStreams();
	return true;
}