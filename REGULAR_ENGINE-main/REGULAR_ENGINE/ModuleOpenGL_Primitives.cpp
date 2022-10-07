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
#include "ModuleOpenGL_Primitives.h"

ModuleOpenGL_Primitives::ModuleOpenGL_Primitives(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleOpenGL_Primitives::~ModuleOpenGL_Primitives()
{
}
