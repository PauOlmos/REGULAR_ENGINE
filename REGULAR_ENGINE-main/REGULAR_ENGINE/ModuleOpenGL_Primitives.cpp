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

void ModuleOpenGL_Primitives::ModifyQuad(){
    if (App->close_app->selectedQ >= 0 && App->close_app->selectedType == 0) {
        if (App->input->GetKey(SDL_SCANCODE_DELETE) == KEY_DOWN) {
            if (App->close_app->selectedQ + 1 != numQuads) {
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
}

void ModuleOpenGL_Primitives::ModifyPyramide() {
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
}

void ModuleOpenGL_Primitives::ModifyPPlanes() {
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
}

void ModuleOpenGL_Primitives::ModifyCilindres() {
    if (App->close_app->selectedC >= 0 && App->close_app->selectedType == 3) {
        if (App->input->GetKey(SDL_SCANCODE_DELETE) == KEY_DOWN) {
            if (App->close_app->selectedC + 1 != numCilindres) {
                for (int i = App->close_app->selectedC; i == numCilindres; i++) {
                    CilindreList.insert(CilindreList.begin() + i, CilindreList[i + 1]);
                }
            }
            CilindreList.pop_back();
            App->close_app->selectedC = -1;

            numCilindres--;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            CilindreList[App->close_app->selectedC]->positon.x--;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            CilindreList[App->close_app->selectedC]->positon.y--;

        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            CilindreList[App->close_app->selectedC]->positon.z--;

        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            CilindreList[App->close_app->selectedC]->positon.x++;

        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            CilindreList[App->close_app->selectedC]->positon.y++;

        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            CilindreList[App->close_app->selectedC]->positon.z++;

        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            CilindreList[App->close_app->selectedC]->scale.x++;
            CilindreList[App->close_app->selectedC]->scale.y++;
            CilindreList[App->close_app->selectedC]->scale.z++;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            CilindreList[App->close_app->selectedC]->scale.x--;
            CilindreList[App->close_app->selectedC]->scale.y--;
            CilindreList[App->close_app->selectedC]->scale.z--;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            CilindreList[App->close_app->selectedC]->scale.x++;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            CilindreList[App->close_app->selectedC]->scale.x--;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            CilindreList[App->close_app->selectedC]->scale.y++;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            CilindreList[App->close_app->selectedC]->scale.y--;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            CilindreList[App->close_app->selectedC]->scale.z++;

        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            CilindreList[App->close_app->selectedC]->scale.z--;

        }
    }
}

update_status ModuleOpenGL_Primitives::Update(float dt)
{

    DrawPrimitives();

    ModifyQuad();
    ModifyPyramide();
    ModifyPPlanes();
    ModifyCilindres();

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
        for (int i = 0; i < App->primitives1->numCilindres; i++) {
            DrawCilindre(App->primitives1->CilindreList[i], 2, 2);
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
