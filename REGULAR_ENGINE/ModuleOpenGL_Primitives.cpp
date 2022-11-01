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

    DrawPrimitives();


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



void ModuleOpenGL_Primitives::DrawPrimitives() {
    if (App->ImGui_menu->CubeRenderer) {
        for (int i = 0; i < App->gameObjects->numQuads; i++) {
            App->primitives1->DrawCube(App->gameObjects->QuadList[i]);
        }
    }
    if (App->ImGui_menu->PiramidRenderer) {
        for (int i = 0; i < App->gameObjects->numPyramides; i++) {
            App->primitives1->DrawPiramid(App->gameObjects->PyramideList[i]);
        }
    }
    if (App->ImGui_menu->PPlaneRenderer) {
        for (int i = 0; i < App->gameObjects->numPPlanes; i++) {
            App->primitives1->DrawPPlane(App->gameObjects->PPlaneList[i]);
        }
    }

    if (App->ImGui_menu->CilindreRenderer) {
        for (int i = 0; i < App->gameObjects->numCilindres; i++) {
            DrawCilindre(App->gameObjects->CilindreList[i], 2, 2);
        }
    }
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

void ModuleOpenGL_Primitives::DrawPPlane(PPlane* PP) {

    if (wireFrameView == true) {
        //Wireframe Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(2);
    }
    glBegin(GL_TRIANGLES);  // draw a cube with 12 triangles

    glVertex3fv(PP->v0);    //Cara1
    glVertex3fv(PP->v1);
    glVertex3fv(PP->v2);
    
    glVertex3fv(PP->v0);    //Cara1
    glVertex3fv(PP->v1);
    glVertex3fv(PP->v3);

    glEnd();
}

void ModuleOpenGL_Primitives::DrawPiramid(Pyramide* P)
{
    if (wireFrameView == true) {
        //Wireframe Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(2);
    }

    glBegin(GL_TRIANGLES);  // draw a triangle

    glVertex3fv(P->v0);    //Cara1
    glVertex3fv(P->v1);
    glVertex3fv(P->v2);

    glVertex3fv(P->v3);    //Cara2
    glVertex3fv(P->v2);
    glVertex3fv(P->v1);

    glVertex3fv(P->v3);    //Cara3
    glVertex3fv(P->v4);
    glVertex3fv(P->v2);

    glVertex3fv(P->v4);    //Cara4
    glVertex3fv(P->v0);
    glVertex3fv(P->v2);


    glVertex3fv(P->v4);    //Cara 5(base)
    glVertex3fv(P->v3);
    glVertex3fv(P->v1);

    glVertex3fv(P->v4); //Cara 6?
    glVertex3fv(P->v1);
    glVertex3fv(P->v0);

    glEnd();
}

void ModuleOpenGL_Primitives::DrawCilindre(Cilindre* C, float radius, float leght)
{
    int n = 30;

    glBegin(GL_POLYGON);
    
    if (wireFrameView == true) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
    }
    for (int i = 360; i >= 0; i -= (360 / n))
    {
        float a = i * M_PI / 180; // degrees to radians
        float X = -(leght + C->scale.x) * 0.5f;
        float Y = (radius + C->scale.y)* cos(a);
        float Z = (radius + C->scale.z) * sin(a);
        glVertex3f(X + C->positon.x, Y +C->positon.y, Z + C->positon.z);
    }
    glEnd();
    // Cylinder Top
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, 1.0f);
    for (int i = 360; i >= 0; i -= (360 / n))
    {
        float a = i * M_PI / 180; // degrees to radians
        float X = (leght + C->scale.x)* 0.5f;
        float Y = (radius + C->scale.y) * cos(a);
        float Z = -(radius + C->scale.z) * sin(a);
        glVertex3f(X + C->positon.x, Y + C->positon.y, Z + C->positon.z);
    }
    glEnd();

    // Cylinder "Cover"
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i < 480; i += (360 / n))
    {
        float a = i * M_PI / 180; // degrees to radians

        glVertex3f((leght + C->scale.x) * 0.5f + C->positon.x, (radius + C->scale.y) * cos(a) + C->positon.y, (radius + C->scale.z) * sin(a) +C->positon.z);
        glVertex3f(-(leght + C->scale.x) * 0.5f + C->positon.x, (radius + C->scale.y) * cos(a) + C->positon.y, (radius + C->scale.z) * sin(a) + C->positon.z);
    }
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

Pyramide::Pyramide()
{
}

Pyramide::~Pyramide()
{
}

PPlane::PPlane()
{
}

PPlane::~PPlane()
{
}

Cilindre::Cilindre()
{
}

Cilindre::~Cilindre()
{
}
