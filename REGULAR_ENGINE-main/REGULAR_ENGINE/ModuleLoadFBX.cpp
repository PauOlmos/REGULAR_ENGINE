#include "Globals.h"
#include "Application.h"
#include "ModuleLoadFBX.h"
#include <gl/GL.h>
#include "scene.h"

#include "Assimp/include/cimport.h"
#include "Assimp/include/scene.h"
#include "Assimp/include/postprocess.h"
#include "ModuleLoadFBX.h"
#pragma comment (lib, "Assimp/libx86/assimp.lib")

ModuleLoadFBX::ModuleLoadFBX(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleLoadFBX::~ModuleLoadFBX()
{
}

bool ModuleLoadFBX::Start()
{
    LOG("Loading Intro assets");

    const char* file_path;
    const aiScene* scene;
    bool ret = true;
    struct aiLogStream stream;
    stream = aiGetPredefinedLogStream(aiDefaultLogStream_DEBUGGER, nullptr);
    aiAttachLogStream(&stream);
    file_path = ("Assets/Ganivet.fbx");
    scene = aiImportFile(file_path, aiProcessPreset_TargetRealtime_MaxQuality);
    M_mesh* ourMesh = new M_mesh;
    if (scene != nullptr && scene->HasMeshes())
    {
        aiReleaseImport(scene);
    }
    ourMesh.num_vertices = aiMesh->mNumVertices;
    ourMesh.vertices = new float[ourMesh.num_vertices * 3];
    memcpy(ourMesh.vertices, aiMesh->mVertices, sizeof(float) * ourMesh.num_vertices * 3);
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

