#include "Globals.h"
#include "Application.h"
#include "ModuleLoadFBX.h"
#include "scene.h"
#include "Assimp/include/cimport.h"
#include "Assimp/include/scene.h"
#include "Assimp/include/postprocess.h"
#include "glew.h"
#include <vector>

#pragma comment (lib, "Assimp/libx86/assimp.lib")
#pragma comment (lib, "Glew/libx86/glew32.lib")

ModuleLoadFBX::ModuleLoadFBX(Application* app, bool start_enabled) : Module(app, start_enabled)
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

	// Binding buffers
	glBindBuffer(GL_ARRAY_BUFFER, id_vertices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_indices);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, NULL);

	// Draw
	glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, NULL);

	// Unbind buffers
	glDisableClientState(GL_VERTEX_ARRAY);
}

void ModuleLoadFBX::LoadFile(string file_path)
{
	const aiScene* scene = aiImportFile(file_path.c_str(), aiProcessPreset_TargetRealtime_MaxQuality);

	if (scene != nullptr && scene->HasMeshes())
	{
		//Iterate scene meshes
		for (int i = 0; i < scene->mNumMeshes; i++) {
			MyMesh* mesh = new MyMesh();
			//Copy fbx mesh info to Mesh struct
			mesh->num_vertices = scene->mMeshes[i]->mNumVertices;
			mesh->vertices = new float[mesh->num_vertices * 3];
			memcpy(mesh->vertices, scene->mMeshes[i]->mVertices, sizeof(float) * mesh->num_vertices * 3);

			//Load Faces
			if (scene->mMeshes[i]->HasFaces())
			{
				//Copy fbx mesh indices info to Mesh struct
				mesh->num_indices = scene->mMeshes[i]->mNumFaces * 3;
				mesh->indices = new uint[mesh->num_indices]; // assume each face is a triangle

				//Iterate mesh faces
				for (uint j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
				{
					//Check that faces are triangles
					if (scene->mMeshes[i]->mFaces[j].mNumIndices != 3) {
					}
					else {
						memcpy(&mesh->indices[j * 3], scene->mMeshes[i]->mFaces[j].mIndices, 3 * sizeof(uint));
					}
				}

				//Add mesh to array
				LoadMesh(mesh);
			}
			else {
				delete mesh;
			}
		}

		aiReleaseImport(scene);
	}
}

bool ModuleLoadFBX::CleanUp()
{
	aiDetachAllLogStreams();
	return true;
}


void ModuleLoadFBX::LoadMesh(MyMesh* mesh) {

	glGenBuffers(1, (GLuint*)&(mesh->id_vertices));
	glGenBuffers(1, (GLuint*)&(mesh->id_indices));

	//Bind and fill buffers
	glBindBuffer(GL_ARRAY_BUFFER, mesh->id_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh->num_vertices * 3, mesh->vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->id_indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * mesh->num_indices, mesh->indices, GL_STATIC_DRAW);

	//Unbind buffers
	glDisableClientState(GL_VERTEX_ARRAY);

	//Add mesh to meshes vector
	meshes.push_back(mesh);
}

update_status ModuleLoadFBX::PostUpdate(float dt)
{
	for (int i = 0; i < meshes.size(); i++) {
		meshes[i]->Render();
	}

	const char* file_path;
	file_path = ("Assets/BakerHouse.fbx");
	LoadFile(file_path);
	return UPDATE_CONTINUE;
}
