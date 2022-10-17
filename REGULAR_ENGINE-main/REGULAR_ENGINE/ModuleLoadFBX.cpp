#include "Globals.h"
#include "Application.h"
#include "ModuleLoadFBX.h"
#include <gl/GL.h>
#include "scene.h"
#include "Assimp/include/cimport.h"
#include "Assimp/include/scene.h"
#include "Assimp/include/postprocess.h"
#include <vector>
#include "ModuleLoadFBX.h"
using std::vector;

#pragma comment (lib, "Assimp/libx86/assimp.lib")

ModuleLoadFBX::ModuleLoadFBX(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleLoadFBX::~ModuleLoadFBX()
{
}

void LoadMesh(aiMesh*,aiMesh*);
void CopyVertices(aiMesh*,aiMesh*);
void CopyFaces(aiMesh*,aiMesh*);

bool ModuleLoadFBX::Start()
{

    LOG("Loading Intro assets");
    const aiScene* scene;
    const vector<aiMesh*> MyMeshes;
    bool ret = true;
    const char* file_path;
    struct aiLogStream stream;
    stream = aiGetPredefinedLogStream(aiDefaultLogStream_DEBUGGER, nullptr);
    aiAttachLogStream(&stream);
    file_path = ("Assets/Ganivet.fbx");
    scene = aiImportFile(file_path, aiProcessPreset_TargetRealtime_MaxQuality);
    /*

    if (scene != nullptr && scene->HasMeshes())
    {
        if (scene->HasMeshes()) {
            for (uint i = 0; i < scene->mNumMeshes; i++) {
                LoadMesh(scene->mMeshes[i], MyMeshes[i]);
                //Posar tot en funció LoadMesh
                //Cridarla funció tants cops com meshes hi hagi i guardar la info en una llista d'mMeshes anomenada x exemple meshes.
            }
        }
        aiReleaseImport(scene);

    }*/
    return ret;
}

bool ModuleLoadFBX::PreUpdate() {
    // Stream log messages to Debug window
    
    return true;
}

update_status ModuleLoadFBX::Update(float dt)
{

   
    return UPDATE_CONTINUE;
}

bool ModuleLoadFBX::PostUpdate() {


    return true;
}

bool ModuleLoadFBX::CleanUp()
{
    aiDetachAllLogStreams();
    return true;
}


void LoadMesh(aiMesh* mesh, aiMesh* mymesh) {
    CopyVertices(mesh, mymesh);
    CopyFaces(mesh, mymesh);
}

void CopyVertices(aiMesh* mesh, aiMesh* mymesh) {

    mymesh->mNumVertices = mesh->mNumVertices;
    mymesh->mVertices = new aiVector3D[mymesh->mNumVertices * 3];
    memcpy(mymesh->mVertices, mesh->mVertices, sizeof(aiVector3D) * mymesh->mNumVertices * 3);
    //mymesh->num_vertex = mesh->mNumVertices; per demostrar que es pot fer amb uint
}

void CopyFaces(aiMesh* mesh, aiMesh* mymesh) {

    if (mesh->HasFaces()) {
        /*mymesh->mNumFaces = mesh->mNumFaces;
        mymesh->mFaces = mesh->mFaces;*/

        mymesh->mFaces->mNumIndices = mesh->mNumFaces * 3;
        mymesh->mFaces->mIndices = new uint[mymesh->mFaces->mNumIndices];
        for (uint i = 0; i < mesh->mNumFaces; ++i)
        {
            if (mesh->mFaces[i].mNumIndices != 3) {
                LOG("WARNING, geometry face with != 3 indices!");
            }
            else {
                memcpy(&mesh->mFaces->mIndices[i * 3], mymesh->mFaces[i].mIndices, 3 * sizeof(uint));
            }
        }
    }
}
