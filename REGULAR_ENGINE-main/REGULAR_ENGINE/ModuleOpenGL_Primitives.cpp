#include <ctype.h>          // toupper
#include <limits.h>         // INT_MIN, INT_MAX
#include <math.h>           // sqrtf, powf, cosf, sinf, floorf, ceilf
#include <stdio.h>          // vsnprintf, sscanf, printf
#include <stdlib.h>  
#include "Globals.h"
#include <string>
#include "SDL/include/SDL_cpuinfo.h"
#include "Timer.h"
#include <iostream>
#include "ModuleRenderer3D.h"
#include "ModuleWindow.h"
#include "imgui_menu.h"
#include "Application.h"
#include "Primitive.h"
#include "ModuleInput.h"
#include <gl/GL.h>
#include "ModuleOpenGL_Primitives.h"

ModuleOpenGL_Primitives::ModuleOpenGL_Primitives(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleOpenGL_Primitives::~ModuleOpenGL_Primitives()
{
}

bool ModuleOpenGL_Primitives::Start()
{
    LOG("Loading Intro assets");
    bool ret = true;

    return ret;
}

bool ModuleOpenGL_Primitives::PreUpdate() {


    return true;
}

update_status ModuleOpenGL_Primitives::Update(float dt)
{
    
    float Quad[] = { 0.f + x,1.f + y,0.f + z,//X    Plane 1
                     0.f + x,0.f + y,0.f + z,//Y 
                     0.f + x,0.f + y,1.f + z,//Z

                     0.0f + x,1.f + y,1.f + z,
                     0.f + x,1.f + y,0.f + z,
                     0.f + x,0.f + y,1.f + z,

                     1.f + x,1.f + y,0.f + z,
                     0.f + x,1.f + y,0.f + z,
                     0.f + x,1.f + y,1.f + z,

                     1.f + x,1.f + y,0.f + z,
                     0.f + x,1.f + y,1.f + z,
                     1.f + x,1.f + y,1.f + z,

                     0.f + x,0.f + y,1.f + z,
                     1.f + x,0.f + y,1.f + z,
                     0.f + x,1.f + y,1.f + z,

                     1.f + x,0.f + y,1.f + z,
                     1.f + x,1.f + y,1.f + z,
                     0.f + x,1.f + y,1.f + z,

                     1.f + x, 0.f + y, 1.f + z,
                     1.f + x, 0.f + y, 0.f + z,
                     1.f + x, 1.f + y, 0.f + z,

                     1.f + x, 0.f + y, 1.f + z,
                     1.f + x, 1.f + y, 0.f + z,
                     1.f + x, 1.f + y, 1.f + z,

                     0.f + x, 0.f + y, 0.f + z,
                     0.f + x, 1.f + y, 0.f + z,
                     1.f + x, 1.f + y, 0.f + z,

                     0.f + x, 0.f + y, 0.f + z,
                     1.f + x, 1.f + y, 0.f + z,
                     1.f + x, 0.f + y, 0.f + z,

                     0.f + x, 0.f + y, 0.f + z,
                     1.f + x, 0.f + y, 0.f + z,
                     1.f + x, 0.f + y, 1.f + z,

                     1.f + x, 0.f + y, 1.f + z,
                     0.f + x, 0.f + y, 1.f + z,
                     0.f + x, 0.f + y, 0.f + z,
    };

    if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
        x++;
    }
    if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
        y++;
    }
    if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
        z++;
    }
    
    if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
        x--;
    }
    if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
        y--;
    }
    if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
        z--;
    }
    
    if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_DOWN) {
        wireFrameView = !wireFrameView;
    }
    if (wireFrameView == true) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
    }

    if(App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN) {
        depthTest = !depthTest;
    }
    if (depthTest == true) {
        glEnable(GL_DEPTH_TEST);

    }
    else {
        glDisable(GL_DEPTH_TEST);
    }
    
    if(App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN) {
        cullFace = !cullFace;
    }
    if (cullFace == true) {
        glEnable(GL_CULL_FACE);

    }
    else {
        glDisable(GL_CULL_FACE);
    }
    
    if(App->input->GetKey(SDL_SCANCODE_F4) == KEY_DOWN) {
        lighting = !lighting;
    }
    if (lighting == true) {
        glEnable(GL_LIGHTING);

    }
    else {
        glDisable(GL_LIGHTING);
    }
    
    if(App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN) {
        colorMaterial = !colorMaterial;
    }
    if (colorMaterial == true) {
        glEnable(GL_COLOR_MATERIAL);

    }
    else {
        glDisable(GL_COLOR_MATERIAL);
    }
    
    if(App->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN) {
        texture2D = !texture2D;
    }
    if (texture2D == true) {
        glEnable(GL_TEXTURE_2D);

    }
    else {
        glDisable(GL_TEXTURE_2D);
    }
    
    if(App->input->GetKey(SDL_SCANCODE_F7) == KEY_DOWN) {
        renderMode = !renderMode;
    }
    if (renderMode == true) {
        glEnable(GL_RENDER_MODE);

    }
    else {
        glDisable(GL_RENDER_MODE);
    }
    
    if(App->input->GetKey(SDL_SCANCODE_F8) == KEY_DOWN) {
        normalize = !normalize;
    }
    if (normalize == true) {
        glEnable(GL_NORMALIZE);

    }
    else {
        glDisable(GL_NORMALIZE);
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, Quad);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDisableClientState(GL_VERTEX_ARRAY);
    // front face =================


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