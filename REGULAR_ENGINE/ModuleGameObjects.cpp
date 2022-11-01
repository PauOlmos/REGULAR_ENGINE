#include "Application.h"
#include "ModuleGameObjects.h"

ModuleGameObjects::ModuleGameObjects(Application* app, bool start_enabled):Module(app, start_enabled)
{

}

bool ModuleGameObjects::Start()
{
	return true;
}

update_status ModuleGameObjects::Update(float dt)
{

    ModifyQuad();
    ModifyPyramide();
    ModifyPPlanes();
    ModifyCilindres();

	return UPDATE_CONTINUE;
}

update_status ModuleGameObjects::PostUpdate()
{
	return UPDATE_CONTINUE;
}

void ModuleGameObjects::ModifyQuad() {
    if (App->ImGui_menu->selectedQ >= 0 && App->ImGui_menu->selectedType == 0) {
        if (App->input->GetKey(SDL_SCANCODE_DELETE) == KEY_DOWN) {
            if (App->ImGui_menu->selectedQ + 1 != numQuads) {
                for (int i = App->ImGui_menu->selectedQ; i == numQuads; i++) {
                    QuadList.insert(QuadList.begin() + i, QuadList[i + 1]);
                }
            }
            App->ImGui_menu->selectedQ = -1;
            QuadList.pop_back();
            numQuads--;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            QuadList[App->ImGui_menu->selectedQ]->positon.x--;
            QuadList[App->ImGui_menu->selectedQ]->v0[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v1[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v2[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v7[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            QuadList[App->ImGui_menu->selectedQ]->positon.y--;
            QuadList[App->ImGui_menu->selectedQ]->v0[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v1[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v2[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v7[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            QuadList[App->ImGui_menu->selectedQ]->positon.z--;
            QuadList[App->ImGui_menu->selectedQ]->v0[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v1[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v2[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v7[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            QuadList[App->ImGui_menu->selectedQ]->positon.x++;
            QuadList[App->ImGui_menu->selectedQ]->v0[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v1[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v2[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v7[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            QuadList[App->ImGui_menu->selectedQ]->positon.y++;
            QuadList[App->ImGui_menu->selectedQ]->v0[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v1[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v2[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v7[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            QuadList[App->ImGui_menu->selectedQ]->positon.z++;
            QuadList[App->ImGui_menu->selectedQ]->v0[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v1[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v2[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v7[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            QuadList[App->ImGui_menu->selectedQ]->scale.x++;
            QuadList[App->ImGui_menu->selectedQ]->scale.y++;
            QuadList[App->ImGui_menu->selectedQ]->scale.z++;
            QuadList[App->ImGui_menu->selectedQ]->v2[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v0[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v7[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            QuadList[App->ImGui_menu->selectedQ]->scale.x--;
            QuadList[App->ImGui_menu->selectedQ]->scale.y--;
            QuadList[App->ImGui_menu->selectedQ]->scale.z--;
            QuadList[App->ImGui_menu->selectedQ]->v2[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v0[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v7[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            QuadList[App->ImGui_menu->selectedQ]->scale.x++;
            QuadList[App->ImGui_menu->selectedQ]->v7[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[0] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            QuadList[App->ImGui_menu->selectedQ]->scale.x--;
            QuadList[App->ImGui_menu->selectedQ]->v7[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[0] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            QuadList[App->ImGui_menu->selectedQ]->scale.y++;
            QuadList[App->ImGui_menu->selectedQ]->v3[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v0[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[1] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            QuadList[App->ImGui_menu->selectedQ]->scale.y--;

            QuadList[App->ImGui_menu->selectedQ]->v3[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v0[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[1] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v4[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            QuadList[App->ImGui_menu->selectedQ]->scale.z++;

            QuadList[App->ImGui_menu->selectedQ]->v2[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[2] += 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            QuadList[App->ImGui_menu->selectedQ]->scale.z--;
            QuadList[App->ImGui_menu->selectedQ]->v2[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v3[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v6[2] -= 1;
            QuadList[App->ImGui_menu->selectedQ]->v5[2] -= 1;
        }
    }
}

void ModuleGameObjects::ModifyPyramide() {
    if (App->ImGui_menu->selectedP >= 0 && App->ImGui_menu->selectedType == 1) {
        if (App->input->GetKey(SDL_SCANCODE_DELETE) == KEY_DOWN) {
            if (App->ImGui_menu->selectedP + 1 != numPyramides) {
                for (int i = App->ImGui_menu->selectedP; i == numPyramides; i++) {
                    PyramideList.insert(PyramideList.begin() + i, PyramideList[i + 1]);
                }
            }
            PyramideList.pop_back();
            App->ImGui_menu->selectedP = -1;

            numPyramides--;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PyramideList[App->ImGui_menu->selectedP]->positon.x--;
            PyramideList[App->ImGui_menu->selectedP]->v0[0] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v1[0] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[0] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v3[0] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PyramideList[App->ImGui_menu->selectedP]->positon.y--;
            PyramideList[App->ImGui_menu->selectedP]->v0[1] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v1[1] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[1] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v3[1] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PyramideList[App->ImGui_menu->selectedP]->positon.z--;
            PyramideList[App->ImGui_menu->selectedP]->v0[2] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v1[2] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[2] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v3[2] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PyramideList[App->ImGui_menu->selectedP]->positon.x++;
            PyramideList[App->ImGui_menu->selectedP]->v0[0] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v1[0] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[0] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v3[0] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PyramideList[App->ImGui_menu->selectedP]->positon.y++;
            PyramideList[App->ImGui_menu->selectedP]->v0[1] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v1[1] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[1] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v3[1] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PyramideList[App->ImGui_menu->selectedP]->positon.z++;
            PyramideList[App->ImGui_menu->selectedP]->v0[2] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v1[2] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[2] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v3[2] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            PyramideList[App->ImGui_menu->selectedP]->scale.x++;
            PyramideList[App->ImGui_menu->selectedP]->scale.y++;
            PyramideList[App->ImGui_menu->selectedP]->scale.z++;
            PyramideList[App->ImGui_menu->selectedP]->v1[0] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[1] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[0] += 0.5f;
            PyramideList[App->ImGui_menu->selectedP]->v2[2] += 0.5f;
            PyramideList[App->ImGui_menu->selectedP]->v3[0] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v3[2] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            PyramideList[App->ImGui_menu->selectedP]->scale.x--;
            PyramideList[App->ImGui_menu->selectedP]->scale.y--;
            PyramideList[App->ImGui_menu->selectedP]->scale.z--;
            PyramideList[App->ImGui_menu->selectedP]->v1[0] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[1] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[0] -= 0.5f;
            PyramideList[App->ImGui_menu->selectedP]->v2[2] -= 0.5f;
            PyramideList[App->ImGui_menu->selectedP]->v3[0] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v3[2] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            PyramideList[App->ImGui_menu->selectedP]->scale.x++;
            PyramideList[App->ImGui_menu->selectedP]->v1[0] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[0] += 0.5f;
            PyramideList[App->ImGui_menu->selectedP]->v3[0] += 1;

        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            PyramideList[App->ImGui_menu->selectedP]->scale.x--;
            PyramideList[App->ImGui_menu->selectedP]->v1[0] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v2[0] -= 0.5f;
            PyramideList[App->ImGui_menu->selectedP]->v3[0] -= 1;

        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            PyramideList[App->ImGui_menu->selectedP]->scale.y++;
            PyramideList[App->ImGui_menu->selectedP]->v2[1] += 1;


        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            PyramideList[App->ImGui_menu->selectedP]->scale.y--;
            PyramideList[App->ImGui_menu->selectedP]->v2[1] -= 1;

        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            PyramideList[App->ImGui_menu->selectedP]->scale.z++;
            PyramideList[App->ImGui_menu->selectedP]->v2[2] += 0.5f;
            PyramideList[App->ImGui_menu->selectedP]->v3[2] += 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            PyramideList[App->ImGui_menu->selectedP]->scale.z--;

            PyramideList[App->ImGui_menu->selectedP]->v2[2] -= 0.5f;
            PyramideList[App->ImGui_menu->selectedP]->v3[2] -= 1;
            PyramideList[App->ImGui_menu->selectedP]->v4[2] -= 1;
        }
    }
}

void ModuleGameObjects::ModifyPPlanes() {
    if (App->ImGui_menu->selectedPP >= 0 && App->ImGui_menu->selectedType == 2) {
        if (App->input->GetKey(SDL_SCANCODE_DELETE) == KEY_DOWN) {
            if (App->ImGui_menu->selectedPP + 1 != numPPlanes) {
                for (int i = App->ImGui_menu->selectedPP; i == numPPlanes; i++) {
                    PPlaneList.insert(PPlaneList.begin() + i, PPlaneList[i + 1]);
                }
            }
            PPlaneList.pop_back();
            App->ImGui_menu->selectedPP = -1;

            numPPlanes--;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PPlaneList[App->ImGui_menu->selectedPP]->positon.x--;
            PPlaneList[App->ImGui_menu->selectedPP]->v0[0] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[0] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[0] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PPlaneList[App->ImGui_menu->selectedPP]->positon.y--;
            PPlaneList[App->ImGui_menu->selectedPP]->v0[1] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[1] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[1] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[1] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            PPlaneList[App->ImGui_menu->selectedPP]->positon.z--;
            PPlaneList[App->ImGui_menu->selectedPP]->v0[2] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[2] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[2] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PPlaneList[App->ImGui_menu->selectedPP]->positon.x++;
            PPlaneList[App->ImGui_menu->selectedPP]->v0[0] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[0] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[0] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PPlaneList[App->ImGui_menu->selectedPP]->positon.y++;
            PPlaneList[App->ImGui_menu->selectedPP]->v0[1] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[1] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[1] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[1] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            PPlaneList[App->ImGui_menu->selectedPP]->positon.z++;
            PPlaneList[App->ImGui_menu->selectedPP]->v0[2] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[2] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[2] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            PPlaneList[App->ImGui_menu->selectedPP]->scale.x++;
            PPlaneList[App->ImGui_menu->selectedPP]->scale.z++;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[0] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[0] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[2] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            PPlaneList[App->ImGui_menu->selectedPP]->scale.x--;
            PPlaneList[App->ImGui_menu->selectedPP]->scale.z--;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[0] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[0] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[2] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[2] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            PPlaneList[App->ImGui_menu->selectedPP]->scale.x++;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[0] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[0] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            PPlaneList[App->ImGui_menu->selectedPP]->scale.x--;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[0] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v2[0] -= 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            PPlaneList[App->ImGui_menu->selectedPP]->scale.z++;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[2] += 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[2] += 1;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            PPlaneList[App->ImGui_menu->selectedPP]->scale.z--;
            PPlaneList[App->ImGui_menu->selectedPP]->v1[2] -= 1;
            PPlaneList[App->ImGui_menu->selectedPP]->v3[2] -= 1;
        }
    }
}

void ModuleGameObjects::ModifyCilindres() {
    if (App->ImGui_menu->selectedC >= 0 && App->ImGui_menu->selectedType == 3) {
        if (App->input->GetKey(SDL_SCANCODE_DELETE) == KEY_DOWN) {
            if (App->ImGui_menu->selectedC + 1 != numCilindres) {
                for (int i = App->ImGui_menu->selectedC; i == numCilindres; i++) {
                    CilindreList.insert(CilindreList.begin() + i, CilindreList[i + 1]);
                }
            }
            CilindreList.pop_back();
            App->ImGui_menu->selectedC = -1;

            numCilindres--;
        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            CilindreList[App->ImGui_menu->selectedC]->positon.x--;
        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            CilindreList[App->ImGui_menu->selectedC]->positon.y--;

        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_REPEAT) {
            CilindreList[App->ImGui_menu->selectedC]->positon.z--;

        }
        if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            CilindreList[App->ImGui_menu->selectedC]->positon.x++;

        }
        if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            CilindreList[App->ImGui_menu->selectedC]->positon.y++;

        }
        if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_LSHIFT) == KEY_IDLE) {
            CilindreList[App->ImGui_menu->selectedC]->positon.z++;

        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            CilindreList[App->ImGui_menu->selectedC]->scale.x++;
            CilindreList[App->ImGui_menu->selectedC]->scale.y++;
            CilindreList[App->ImGui_menu->selectedC]->scale.z++;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == NULL && App->input->GetKey(SDL_SCANCODE_Y) == NULL && App->input->GetKey(SDL_SCANCODE_Z) == NULL) {
            CilindreList[App->ImGui_menu->selectedC]->scale.x--;
            CilindreList[App->ImGui_menu->selectedC]->scale.y--;
            CilindreList[App->ImGui_menu->selectedC]->scale.z--;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            CilindreList[App->ImGui_menu->selectedC]->scale.x++;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_X) == KEY_REPEAT) {
            CilindreList[App->ImGui_menu->selectedC]->scale.x--;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            CilindreList[App->ImGui_menu->selectedC]->scale.y++;
        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Y) == KEY_REPEAT) {
            CilindreList[App->ImGui_menu->selectedC]->scale.y--;
        }
        if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            CilindreList[App->ImGui_menu->selectedC]->scale.z++;

        }
        if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN && App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT) {
            CilindreList[App->ImGui_menu->selectedC]->scale.z--;

        }
    }
}

bool ModuleGameObjects::CleanUp()
{
	return true;
}


