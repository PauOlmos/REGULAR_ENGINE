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

#include <iostream>
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
    LOG("Loading Intro assets");
    float Quad[] = { NULL };

    bool ret = true;

    return ret;
}

bool ModuleOpenGL_Primitives::PreUpdate() {


    return true;
}

update_status ModuleOpenGL_Primitives::Update(float dt)
{

    if (App->close_app->CubeRenderer) {
        DrawCube();
    }

    if (App->close_app->CilindreRenderer) {
        DrawCilindre(2, 2);
    }
    if (App->close_app->PiramidRenderer) {
        DrawPiramid();
    }

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



    if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN) {
        depthTest = !depthTest;
    }
    if (depthTest == true) {
        glEnable(GL_DEPTH_TEST);

    }
    else {
        glDisable(GL_DEPTH_TEST);
    }

    if (App->input->GetKey(SDL_SCANCODE_F3) == KEY_DOWN) {
        cullFace = !cullFace;
    }
    if (cullFace == true) {
        glEnable(GL_CULL_FACE);

    }
    else {
        glDisable(GL_CULL_FACE);
    }

    if (App->input->GetKey(SDL_SCANCODE_F4) == KEY_DOWN) {
        lighting = !lighting;
    }
    if (lighting == true) {
        glEnable(GL_LIGHTING);

    }
    else {
        glDisable(GL_LIGHTING);
    }

    if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN) {
        colorMaterial = !colorMaterial;
    }
    if (colorMaterial == true) {
        glEnable(GL_COLOR_MATERIAL);

    }
    else {
        glDisable(GL_COLOR_MATERIAL);
    }

    if (App->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN) {
        texture2D = !texture2D;
    }
    if (texture2D == true) {
        glEnable(GL_TEXTURE_2D);

    }
    else {
        glDisable(GL_TEXTURE_2D);
    }

    if (App->input->GetKey(SDL_SCANCODE_F7) == KEY_DOWN) {
        renderMode = !renderMode;
    }
    if (renderMode == true) {
        glEnable(GL_RENDER_MODE);

    }
    else {
        glDisable(GL_RENDER_MODE);
    }

    if (App->input->GetKey(SDL_SCANCODE_F8) == KEY_DOWN) {
        normalize = !normalize;
    }
    if (normalize == true) {
        glEnable(GL_NORMALIZE);

    }
    else {
        glDisable(GL_NORMALIZE);
    }
    // front face =================



    glEnd();
    return UPDATE_CONTINUE;
}

void ModuleOpenGL_Primitives::DrawCube() {

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
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, Quad);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDisableClientState(GL_VERTEX_ARRAY);
}
void ModuleOpenGL_Primitives::DrawCilindre(float radius, float leght)
{
    int n = 30;

    // Cylinder Bottom
    glBegin(GL_POLYGON);
    if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_DOWN) {
        wireFrameView = !wireFrameView;
    }
    if (wireFrameView == true) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
    }
    for (int i = 360; i >= 0; i -= (360 / n))
    {
        float a = i * M_PI / 180; // degrees to radians
        float X = -leght * 0.5f;
        float Y = radius * cos(a);
        float Z = radius * sin(a);
        glVertex3f(X, Y, Z);
    }
    glEnd();
    // Cylinder Top
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, 1.0f);
    for (int i = 360; i >= 0; i -= (360 / n))
    {
        float a = i * M_PI / 180; // degrees to radians
        float X = leght * 0.5f;
        float Y = radius * cos(a);
        float Z = -radius * sin(a);
        glVertex3f(X, Y, Z);
    }
    glEnd();

    // Cylinder "Cover"
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i < 480; i += (360 / n))
    {
        float a = i * M_PI / 180; // degrees to radians

        glVertex3f(leght * 0.5f, radius * cos(a), radius * sin(a));
        glVertex3f(-leght * 0.5f, radius * cos(a), radius * sin(a));
    }
    glEnd();
}
void ModuleOpenGL_Primitives::DrawPiramid()
{
    if (wireFrameView == true) {
        //Wireframe Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(2);
    }

    Triangle T;

    glBegin(GL_TRIANGLES);  // draw a triangle

    glVertex3fv(T.v0);    //Cara1
    glVertex3fv(T.v1);
    glVertex3fv(T.v2);

    glVertex3fv(T.v3);    //Cara2
    glVertex3fv(T.v2);
    glVertex3fv(T.v1);

    glVertex3fv(T.v3);    //Cara3
    glVertex3fv(T.v4);
    glVertex3fv(T.v2);

    glVertex3fv(T.v4);    //Cara4
    glVertex3fv(T.v0);
    glVertex3fv(T.v2);

    glVertex3fv(T.v4);    //Base
    glVertex3fv(T.v3);
    glVertex3fv(T.v1);

    glVertex3fv(T.v4);
    glVertex3fv(T.v1);
    glVertex3fv(T.v0);

    glEnd();
}


bool ModuleOpenGL_Primitives::PostUpdate() {


    return true;
}

bool ModuleOpenGL_Primitives::CleanUp()
{
    return true;
}

