#include "Globals.h"
#include "SDL/include/SDL_cpuinfo.h"
#include "Timer.h"
#include "ModuleRenderer3D.h"
#include "ModuleWindow.h"
#include "imgui_menu.h"
#include "Application.h"
#include "Primitive.h"
#include "ModuleInput.h"
#include "ModuleOpenGL_Primitives.h"
#include <vector>
#include <iostream>
#include <list>
#include <ctype.h>          // toupper
#include <limits.h>         // INT_MIN, INT_MAX
#include <math.h>           // sqrtf, powf, cosf, sinf, floorf, ceilf
#include <stdio.h>          // vsnprintf, sscanf, printf
#include <stdlib.h>
#include <string>
#include <gl/GL.h>


ModuleOpenGL_Primitives::ModuleOpenGL_Primitives(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleOpenGL_Primitives::~ModuleOpenGL_Primitives()
{
}

bool ModuleOpenGL_Primitives::Start()
{
    LOG(LogType::LOGS, "Loading Intro assets");
    bool ret = true;
    return ret;
}

bool ModuleOpenGL_Primitives::PreUpdate() {


    return true;
}

update_status ModuleOpenGL_Primitives::Update(float dt)
{

    if (depthTest == true) {
        glEnable(GL_DEPTH_TEST);

    }
    else {
        glDisable(GL_DEPTH_TEST);
    }
    if (cullFace == true) {
        glEnable(GL_CULL_FACE);

    }
    else {
        glDisable(GL_CULL_FACE);
    }

    if (lighting == true) {
        glEnable(GL_LIGHTING);

    }
    else {
        glDisable(GL_LIGHTING);
    }

    glEnd();
    return UPDATE_CONTINUE;
}


bool ModuleOpenGL_Primitives::PostUpdate() {


    return true;
}

bool ModuleOpenGL_Primitives::CleanUp()
{
    return true;
}
