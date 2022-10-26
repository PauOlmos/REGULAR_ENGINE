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
    LOG("Loading Intro assets");
    bool ret = true;

    return ret;
}

bool ModuleOpenGL_Primitives::PreUpdate() {


    return true;
}

update_status ModuleOpenGL_Primitives::Update(float dt)
{

    if (App->close_app->CubeRenderer) {
        for (int i = 0; i < App->primitives1->numQuads; i++) {
            App->primitives1->DrawCube(App->primitives1->QuadList[i]);
        }
    }
    if (App->close_app->PiramidRenderer) {
        for (int i = 0; i < App->primitives1->numPyramides; i++) {
            App->primitives1->DrawPiramid(App->primitives1->PyramideList[i]);
        }
    }
    if (App->close_app->PPlaneRenderer) {
        for (int i = 0; i < App->primitives1->numPPlanes; i++) {
            App->primitives1->DrawPPlane(App->primitives1->PPlaneList[i]);
        }
    }

    if (App->close_app->CilindreRenderer) {
        DrawCilindre(2, 2);
    }

    if (App->close_app->selectedQ >= 0 && App->close_app->selectedType == 0) {
        if (App->input->GetKey(SDL_SCANCODE_DELETE) == KEY_DOWN) {
            if (App->close_app->selectedQ+1 != numQuads) {
                for (int i = App->close_app->selectedQ; i == numQuads; i++) {
                    QuadList.insert(QuadList.begin() + i, QuadList[i + 1]);
                }
            }
            App->close_app->selectedQ = -1;
            QuadList.pop_back();
            numQuads--;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            QuadList[App->close_app->selectedQ]->positon.x--;
            QuadList[App->close_app->selectedQ]->v0[0] -= 1;
            QuadList[App->close_app->selectedQ]->v1[0] -= 1;
            QuadList[App->close_app->selectedQ]->v2[0] -= 1;
            QuadList[App->close_app->selectedQ]->v3[0] -= 1;
            QuadList[App->close_app->selectedQ]->v4[0] -= 1;
            QuadList[App->close_app->selectedQ]->v5[0] -= 1;
            QuadList[App->close_app->selectedQ]->v6[0] -= 1;
            QuadList[App->close_app->selectedQ]->v7[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            QuadList[App->close_app->selectedQ]->positon.y--;
            QuadList[App->close_app->selectedQ]->v0[1] -= 1;
            QuadList[App->close_app->selectedQ]->v1[1] -= 1;
            QuadList[App->close_app->selectedQ]->v2[1] -= 1;
            QuadList[App->close_app->selectedQ]->v3[1] -= 1;
            QuadList[App->close_app->selectedQ]->v4[1] -= 1;
            QuadList[App->close_app->selectedQ]->v5[1] -= 1;
            QuadList[App->close_app->selectedQ]->v6[1] -= 1;
            QuadList[App->close_app->selectedQ]->v7[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            QuadList[App->close_app->selectedQ]->positon.z--;
            QuadList[App->close_app->selectedQ]->v0[2] -= 1;
            QuadList[App->close_app->selectedQ]->v1[2] -= 1;
            QuadList[App->close_app->selectedQ]->v2[2] -= 1;
            QuadList[App->close_app->selectedQ]->v3[2] -= 1;
            QuadList[App->close_app->selectedQ]->v4[2] -= 1;
            QuadList[App->close_app->selectedQ]->v5[2] -= 1;
            QuadList[App->close_app->selectedQ]->v6[2] -= 1;
            QuadList[App->close_app->selectedQ]->v7[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            QuadList[App->close_app->selectedQ]->positon.x++;
            QuadList[App->close_app->selectedQ]->v0[0] += 1;
            QuadList[App->close_app->selectedQ]->v1[0] += 1;
            QuadList[App->close_app->selectedQ]->v2[0] += 1;
            QuadList[App->close_app->selectedQ]->v3[0] += 1;
            QuadList[App->close_app->selectedQ]->v4[0] += 1;
            QuadList[App->close_app->selectedQ]->v5[0] += 1;
            QuadList[App->close_app->selectedQ]->v6[0] += 1;
            QuadList[App->close_app->selectedQ]->v7[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            QuadList[App->close_app->selectedQ]->positon.y++;
            QuadList[App->close_app->selectedQ]->v0[1] += 1;
            QuadList[App->close_app->selectedQ]->v1[1] += 1;
            QuadList[App->close_app->selectedQ]->v2[1] += 1;
            QuadList[App->close_app->selectedQ]->v3[1] += 1;
            QuadList[App->close_app->selectedQ]->v4[1] += 1;
            QuadList[App->close_app->selectedQ]->v5[1] += 1;
            QuadList[App->close_app->selectedQ]->v6[1] += 1;
            QuadList[App->close_app->selectedQ]->v7[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            QuadList[App->close_app->selectedQ]->positon.z++;
            QuadList[App->close_app->selectedQ]->v0[2] += 1;
            QuadList[App->close_app->selectedQ]->v1[2] += 1;
            QuadList[App->close_app->selectedQ]->v2[2] += 1;
            QuadList[App->close_app->selectedQ]->v3[2] += 1;
            QuadList[App->close_app->selectedQ]->v4[2] += 1;
            QuadList[App->close_app->selectedQ]->v5[2] += 1;
            QuadList[App->close_app->selectedQ]->v6[2] += 1;
            QuadList[App->close_app->selectedQ]->v7[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            QuadList[App->close_app->selectedQ]->scale.x++;
            QuadList[App->close_app->selectedQ]->scale.y++;
            QuadList[App->close_app->selectedQ]->scale.z++;
            QuadList[App->close_app->selectedQ]->v2[2] += 1;
            QuadList[App->close_app->selectedQ]->v3[1] += 1;
            QuadList[App->close_app->selectedQ]->v3[2] += 1;
            QuadList[App->close_app->selectedQ]->v0[1] += 1;
            QuadList[App->close_app->selectedQ]->v7[0] += 1;
            QuadList[App->close_app->selectedQ]->v6[0] += 1;
            QuadList[App->close_app->selectedQ]->v6[2] += 1;
            QuadList[App->close_app->selectedQ]->v5[0] += 1;
            QuadList[App->close_app->selectedQ]->v5[1] += 1;
            QuadList[App->close_app->selectedQ]->v5[2] += 1;
            QuadList[App->close_app->selectedQ]->v4[0] += 1;
            QuadList[App->close_app->selectedQ]->v4[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            QuadList[App->close_app->selectedQ]->scale.x--;
            QuadList[App->close_app->selectedQ]->scale.y--;
            QuadList[App->close_app->selectedQ]->scale.z--;
            QuadList[App->close_app->selectedQ]->v2[2] -= 1;
            QuadList[App->close_app->selectedQ]->v3[1] -= 1;
            QuadList[App->close_app->selectedQ]->v3[2] -= 1;
            QuadList[App->close_app->selectedQ]->v0[1] -= 1;
            QuadList[App->close_app->selectedQ]->v7[0] -= 1;
            QuadList[App->close_app->selectedQ]->v6[0] -= 1;
            QuadList[App->close_app->selectedQ]->v6[2] -= 1;
            QuadList[App->close_app->selectedQ]->v5[0] -= 1;
            QuadList[App->close_app->selectedQ]->v5[1] -= 1;
            QuadList[App->close_app->selectedQ]->v5[2] -= 1;
            QuadList[App->close_app->selectedQ]->v4[0] -= 1;
            QuadList[App->close_app->selectedQ]->v4[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            QuadList[App->close_app->selectedQ]->scale.x++;
            QuadList[App->close_app->selectedQ]->v7[0] += 1;
            QuadList[App->close_app->selectedQ]->v6[0] += 1;
            QuadList[App->close_app->selectedQ]->v5[0] += 1;
            QuadList[App->close_app->selectedQ]->v4[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            QuadList[App->close_app->selectedQ]->scale.x--;
            QuadList[App->close_app->selectedQ]->v7[0] -= 1;
            QuadList[App->close_app->selectedQ]->v6[0] -= 1;
            QuadList[App->close_app->selectedQ]->v5[0] -= 1;
            QuadList[App->close_app->selectedQ]->v4[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            QuadList[App->close_app->selectedQ]->scale.y++;
            QuadList[App->close_app->selectedQ]->v3[1] += 1;
            QuadList[App->close_app->selectedQ]->v0[1] += 1;
            QuadList[App->close_app->selectedQ]->v5[1] += 1;
            QuadList[App->close_app->selectedQ]->v4[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            QuadList[App->close_app->selectedQ]->scale.y--;

            QuadList[App->close_app->selectedQ]->v3[1] -= 1;
            QuadList[App->close_app->selectedQ]->v0[1] -= 1;
            QuadList[App->close_app->selectedQ]->v5[1] -= 1;
            QuadList[App->close_app->selectedQ]->v4[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            QuadList[App->close_app->selectedQ]->scale.z++;

            QuadList[App->close_app->selectedQ]->v2[2] += 1;
            QuadList[App->close_app->selectedQ]->v3[2] += 1;
            QuadList[App->close_app->selectedQ]->v6[2] += 1;
            QuadList[App->close_app->selectedQ]->v5[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            QuadList[App->close_app->selectedQ]->scale.z--;
            QuadList[App->close_app->selectedQ]->v2[2] -= 1;
            QuadList[App->close_app->selectedQ]->v3[2] -= 1;
            QuadList[App->close_app->selectedQ]->v6[2] -= 1;
            QuadList[App->close_app->selectedQ]->v5[2] -= 1;
        }
    }
    if (App->close_app->selectedP >= 0 && App->close_app->selectedType == 1) {
        if (App->input->GetKey(SDL_SCANCODE_DELETE) == KEY_DOWN) {
            if (App->close_app->selectedP + 1 != numPyramides) {
                for (int i = App->close_app->selectedP; i == numPyramides; i++) {
                    PyramideList.insert(PyramideList.begin() + i, PyramideList[i + 1]);
                }
            }
            PyramideList.pop_back();
            App->close_app->selectedP = -1;

            numPyramides--;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PyramideList[App->close_app->selectedP]->positon.x--;
            PyramideList[App->close_app->selectedP]->v0[0] -= 1;
            PyramideList[App->close_app->selectedP]->v1[0] -= 1;
            PyramideList[App->close_app->selectedP]->v2[0] -= 1;
            PyramideList[App->close_app->selectedP]->v3[0] -= 1;
            PyramideList[App->close_app->selectedP]->v4[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PyramideList[App->close_app->selectedP]->positon.y--;
            PyramideList[App->close_app->selectedP]->v0[1] -= 1;
            PyramideList[App->close_app->selectedP]->v1[1] -= 1;
            PyramideList[App->close_app->selectedP]->v2[1] -= 1;
            PyramideList[App->close_app->selectedP]->v3[1] -= 1;
            PyramideList[App->close_app->selectedP]->v4[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PyramideList[App->close_app->selectedP]->positon.z--;
            PyramideList[App->close_app->selectedP]->v0[2] -= 1;
            PyramideList[App->close_app->selectedP]->v1[2] -= 1;
            PyramideList[App->close_app->selectedP]->v2[2] -= 1;
            PyramideList[App->close_app->selectedP]->v3[2] -= 1;
            PyramideList[App->close_app->selectedP]->v4[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PyramideList[App->close_app->selectedP]->positon.x++;
            PyramideList[App->close_app->selectedP]->v0[0] += 1;
            PyramideList[App->close_app->selectedP]->v1[0] += 1;
            PyramideList[App->close_app->selectedP]->v2[0] += 1;
            PyramideList[App->close_app->selectedP]->v3[0] += 1;
            PyramideList[App->close_app->selectedP]->v4[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PyramideList[App->close_app->selectedP]->positon.y++;
            PyramideList[App->close_app->selectedP]->v0[1] += 1;
            PyramideList[App->close_app->selectedP]->v1[1] += 1;
            PyramideList[App->close_app->selectedP]->v2[1] += 1;
            PyramideList[App->close_app->selectedP]->v3[1] += 1;
            PyramideList[App->close_app->selectedP]->v4[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PyramideList[App->close_app->selectedP]->positon.z++;
            PyramideList[App->close_app->selectedP]->v0[2] += 1;
            PyramideList[App->close_app->selectedP]->v1[2] += 1;
            PyramideList[App->close_app->selectedP]->v2[2] += 1;
            PyramideList[App->close_app->selectedP]->v3[2] += 1;
            PyramideList[App->close_app->selectedP]->v4[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            PyramideList[App->close_app->selectedP]->scale.x++;
            PyramideList[App->close_app->selectedP]->scale.y++;
            PyramideList[App->close_app->selectedP]->scale.z++;
            PyramideList[App->close_app->selectedP]->v1[0] += 1;
            PyramideList[App->close_app->selectedP]->v2[1] += 1;
            PyramideList[App->close_app->selectedP]->v2[0] += 0.5f;
            PyramideList[App->close_app->selectedP]->v2[2] += 0.5f;
            PyramideList[App->close_app->selectedP]->v3[0] += 1;
            PyramideList[App->close_app->selectedP]->v3[2] += 1;
            PyramideList[App->close_app->selectedP]->v4[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            PyramideList[App->close_app->selectedP]->scale.x--;
            PyramideList[App->close_app->selectedP]->scale.y--;
            PyramideList[App->close_app->selectedP]->scale.z--;
            PyramideList[App->close_app->selectedP]->v1[0] -= 1;
            PyramideList[App->close_app->selectedP]->v2[1] -= 1;
            PyramideList[App->close_app->selectedP]->v2[0] -= 0.5f;
            PyramideList[App->close_app->selectedP]->v2[2] -= 0.5f;
            PyramideList[App->close_app->selectedP]->v3[0] -= 1;
            PyramideList[App->close_app->selectedP]->v3[2] -= 1;
            PyramideList[App->close_app->selectedP]->v4[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            PyramideList[App->close_app->selectedP]->scale.x++;
            PyramideList[App->close_app->selectedP]->v1[0] += 1;
            PyramideList[App->close_app->selectedP]->v2[0] += 0.5f;
            PyramideList[App->close_app->selectedP]->v3[0] += 1;

        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            PyramideList[App->close_app->selectedP]->scale.x--;
            PyramideList[App->close_app->selectedP]->v1[0] -= 1;
            PyramideList[App->close_app->selectedP]->v2[0] -= 0.5f;
            PyramideList[App->close_app->selectedP]->v3[0] -= 1;

        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            PyramideList[App->close_app->selectedP]->scale.y++;
            PyramideList[App->close_app->selectedP]->v2[1] += 1;


        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            PyramideList[App->close_app->selectedP]->scale.y--;
            PyramideList[App->close_app->selectedP]->v2[1] -= 1;

        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            PyramideList[App->close_app->selectedP]->scale.z++;
            PyramideList[App->close_app->selectedP]->v2[2] += 0.5f;
            PyramideList[App->close_app->selectedP]->v3[2] += 1;
            PyramideList[App->close_app->selectedP]->v4[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            PyramideList[App->close_app->selectedP]->scale.z--;

            PyramideList[App->close_app->selectedP]->v2[2] -= 0.5f;
            PyramideList[App->close_app->selectedP]->v3[2] -= 1;
            PyramideList[App->close_app->selectedP]->v4[2] -= 1;
        }
    }


    if (App->close_app->selectedPP >= 0 && App->close_app->selectedType == 2) {
        if (App->input->GetKey(SDL_SCANCODE_DELETE) == KEY_DOWN) {
            if (App->close_app->selectedPP + 1 != numPPlanes) {
                for (int i = App->close_app->selectedPP; i == numPPlanes; i++) {
                    PPlaneList.insert(PPlaneList.begin() + i, PPlaneList[i + 1]);
                }
            }
            PPlaneList.pop_back();
            App->close_app->selectedPP = -1;

            numPPlanes--;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PPlaneList[App->close_app->selectedPP]->positon.x--;
            PPlaneList[App->close_app->selectedPP]->v0[0] -= 1;
            PPlaneList[App->close_app->selectedPP]->v1[0] -= 1;
            PPlaneList[App->close_app->selectedPP]->v2[0] -= 1;
            PPlaneList[App->close_app->selectedPP]->v3[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PPlaneList[App->close_app->selectedPP]->positon.y--;
            PPlaneList[App->close_app->selectedPP]->v0[1] -= 1;
            PPlaneList[App->close_app->selectedPP]->v1[1] -= 1;
            PPlaneList[App->close_app->selectedPP]->v2[1] -= 1;
            PPlaneList[App->close_app->selectedPP]->v3[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PPlaneList[App->close_app->selectedPP]->positon.z--;
            PPlaneList[App->close_app->selectedPP]->v0[2] -= 1;
            PPlaneList[App->close_app->selectedPP]->v1[2] -= 1;
            PPlaneList[App->close_app->selectedPP]->v2[2] -= 1;
            PPlaneList[App->close_app->selectedPP]->v3[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PPlaneList[App->close_app->selectedPP]->positon.x++;
            PPlaneList[App->close_app->selectedPP]->v0[0] += 1;
            PPlaneList[App->close_app->selectedPP]->v1[0] += 1;
            PPlaneList[App->close_app->selectedPP]->v2[0] += 1;
            PPlaneList[App->close_app->selectedPP]->v3[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PPlaneList[App->close_app->selectedPP]->positon.y++;
            PPlaneList[App->close_app->selectedPP]->v0[1] += 1;
            PPlaneList[App->close_app->selectedPP]->v1[1] += 1;
            PPlaneList[App->close_app->selectedPP]->v2[1] += 1;
            PPlaneList[App->close_app->selectedPP]->v3[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PPlaneList[App->close_app->selectedPP]->positon.z++;
            PPlaneList[App->close_app->selectedPP]->v0[2] += 1;
            PPlaneList[App->close_app->selectedPP]->v1[2] += 1;
            PPlaneList[App->close_app->selectedPP]->v2[2] += 1;
            PPlaneList[App->close_app->selectedPP]->v3[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            PPlaneList[App->close_app->selectedPP]->scale.x++;
            PPlaneList[App->close_app->selectedPP]->scale.z++;
            PPlaneList[App->close_app->selectedPP]->v1[0] += 1;
            PPlaneList[App->close_app->selectedPP]->v2[0] += 1;
            PPlaneList[App->close_app->selectedPP]->v1[2] += 1;
            PPlaneList[App->close_app->selectedPP]->v3[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            PPlaneList[App->close_app->selectedPP]->scale.x--;
            PPlaneList[App->close_app->selectedPP]->scale.z--;
            PPlaneList[App->close_app->selectedPP]->v1[0] -= 1;
            PPlaneList[App->close_app->selectedPP]->v2[0] -= 1;
            PPlaneList[App->close_app->selectedPP]->v1[2] -= 1;
            PPlaneList[App->close_app->selectedPP]->v3[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            PPlaneList[App->close_app->selectedPP]->scale.x++;
            PPlaneList[App->close_app->selectedPP]->v1[0] += 1;
            PPlaneList[App->close_app->selectedPP]->v2[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            PPlaneList[App->close_app->selectedPP]->scale.x--;
            PPlaneList[App->close_app->selectedPP]->v1[0] -= 1;
            PPlaneList[App->close_app->selectedPP]->v2[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            PPlaneList[App->close_app->selectedPP]->scale.z++;
            PPlaneList[App->close_app->selectedPP]->v1[2] += 1;
            PPlaneList[App->close_app->selectedPP]->v3[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            PPlaneList[App->close_app->selectedPP]->scale.z--;
            PPlaneList[App->close_app->selectedPP]->v1[2] -= 1;
            PPlaneList[App->close_app->selectedPP]->v3[2] -= 1;
        }
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
