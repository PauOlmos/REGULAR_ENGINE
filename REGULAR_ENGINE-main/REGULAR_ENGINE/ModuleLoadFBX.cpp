#include "Globals.h"
#include "Application.h"
#include "ModuleLoadFBX.h"
#include <gl/GL.h>


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
    bool ret = true;

    return ret;
}

bool ModuleLoadFBX::PreUpdate() {

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
    return true;
}