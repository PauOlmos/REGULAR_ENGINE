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

    bool ret = true;

    return ret;
}

bool ModuleOpenGL_Primitives::PreUpdate() {


    return true;
}

update_status ModuleOpenGL_Primitives::Update(float dt)
{
    if (App->close_app->CilindreRenderer) {
        DrawCilindre(2, 2);
    }
    if (App->close_app->PiramidRenderer) {
        DrawPiramid();
    }

    if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
        App->primitives1->QuadList[0]->positon.x++;
        App->primitives1->QuadList[0]->v0[0] += App->primitives1->QuadList[0]->positon.x;
        App->primitives1->QuadList[0]->v1[0] += App->primitives1->QuadList[0]->positon.x;
        App->primitives1->QuadList[0]->v2[0] += App->primitives1->QuadList[0]->positon.x;
        App->primitives1->QuadList[0]->v3[0] += App->primitives1->QuadList[0]->positon.x;
        App->primitives1->QuadList[0]->v4[0] += App->primitives1->QuadList[0]->positon.x;
        App->primitives1->QuadList[0]->v5[0] += App->primitives1->QuadList[0]->positon.x;
        App->primitives1->QuadList[0]->v6[0] += App->primitives1->QuadList[0]->positon.x;
        App->primitives1->QuadList[0]->v7[0] += App->primitives1->QuadList[0]->positon.x;
    }
    if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
        App->primitives1->QuadList[0]->positon.y++;
        App->primitives1->QuadList[0]->v0[1] += App->primitives1->QuadList[0]->positon.y;
        App->primitives1->QuadList[0]->v1[1] += App->primitives1->QuadList[0]->positon.y;
        App->primitives1->QuadList[0]->v2[1] += App->primitives1->QuadList[0]->positon.y;
        App->primitives1->QuadList[0]->v3[1] += App->primitives1->QuadList[0]->positon.y;
        App->primitives1->QuadList[0]->v4[1] += App->primitives1->QuadList[0]->positon.y;
        App->primitives1->QuadList[0]->v5[1] += App->primitives1->QuadList[0]->positon.y;
        App->primitives1->QuadList[0]->v6[1] += App->primitives1->QuadList[0]->positon.y;
        App->primitives1->QuadList[0]->v7[1] += App->primitives1->QuadList[0]->positon.y;
    }
    if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
        App->primitives1->QuadList[0]->positon.z++;
        App->primitives1->QuadList[0]->v0[2] += App->primitives1->QuadList[0]->positon.z;
        App->primitives1->QuadList[0]->v1[2] += App->primitives1->QuadList[0]->positon.z;
        App->primitives1->QuadList[0]->v2[2] += App->primitives1->QuadList[0]->positon.z;
        App->primitives1->QuadList[0]->v3[2] += App->primitives1->QuadList[0]->positon.z;
        App->primitives1->QuadList[0]->v4[2] += App->primitives1->QuadList[0]->positon.z;
        App->primitives1->QuadList[0]->v5[2] += App->primitives1->QuadList[0]->positon.z;
        App->primitives1->QuadList[0]->v6[2] += App->primitives1->QuadList[0]->positon.z;
        App->primitives1->QuadList[0]->v7[2] += App->primitives1->QuadList[0]->positon.z;
    }

    if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
        App->primitives1->Objectx--;
    }
    if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
        App->primitives1->Objecty--;
    }
    if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
        App->primitives1->Objectz--;
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

void ModuleOpenGL_Primitives::DrawCube(Quad* Q) {

    if (wireFrameView == true) {
        //Wireframe Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(2);
    }
    glBegin(GL_TRIANGLES);  // draw a cube with 12 triangles

    glVertex3fv(Q->v0);    //Cara1
    glVertex3fv(Q->v1);
    glVertex3fv(Q->v2);

    glVertex3fv(Q->v2);    // v2-v3-v0
    glVertex3fv(Q->v3);
    glVertex3fv(Q->v0);

    glVertex3fv(Q->v0);    //Cara2
    glVertex3fv(Q->v3);
    glVertex3fv(Q->v4);

    glVertex3fv(Q->v3);
    glVertex3fv(Q->v5);
    glVertex3fv(Q->v4);


    glVertex3fv(Q->v2); //Cara3
    glVertex3fv(Q->v5);
    glVertex3fv(Q->v3);

    glVertex3fv(Q->v2);
    glVertex3fv(Q->v6);
    glVertex3fv(Q->v5);

    glVertex3fv(Q->v6);//Cara4
    glVertex3fv(Q->v4);
    glVertex3fv(Q->v5);

    glVertex3fv(Q->v6);
    glVertex3fv(Q->v7);
    glVertex3fv(Q->v4);

    glVertex3fv(Q->v7);//Cara5
    glVertex3fv(Q->v0);
    glVertex3fv(Q->v4);

    glVertex3fv(Q->v7);
    glVertex3fv(Q->v1);
    glVertex3fv(Q->v0);

    glVertex3fv(Q->v1);//Cara6
    glVertex3fv(Q->v6);
    glVertex3fv(Q->v2);

    glVertex3fv(Q->v1);
    glVertex3fv(Q->v7);
    glVertex3fv(Q->v6);
    glEnd();
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

Quad::Quad()
{
}

Quad::~Quad()
{
}
