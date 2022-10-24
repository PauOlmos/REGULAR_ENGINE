#include "imgui.h"
// System includes
#include <ctype.h>          // toupper
#include <limits.h>         // INT_MIN, INT_MAX
#include <math.h>           // sqrtf, powf, cosf, sinf, floorf, ceilf
#include <stdio.h>          // vsnprintf, sscanf, printf
#include <stdlib.h>    
#include <vector>
// NULL, malloc, free, atoi
#if defined(_MSC_VER) && _MSC_VER <= 1500 // MSVC 2008 or earlier
#include <stddef.h>         // intptr_t
#else
#include <stdint.h>         // intptr_t
#endif
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
#include <gl/GL.h>
// Visual Studio warnings
#ifdef _MSC_VER
#pragma warning (disable: 4127)     // condition expression is constant
#pragma warning (disable: 4996)     // 'This function or variable may be unsafe': strcpy, strdup, sprintf, vsnprintf, sscanf, fopen
#pragma warning (disable: 26451)    // [Static Analyzer] Arithmetic overflow : Using operator 'xxx' on a 4 byte value and then casting the result to an 8 byte value. Cast the value to the wider type before calling operator 'xxx' to avoid overflow(io.2).
#endif

// Clang/GCC warnings with -Weverything
#if defined(__clang__)
#if __has_warning("-Wunknown-warning-option")
#pragma clang diagnostic ignored "-Wunknown-warning-option"         // warning: unknown warning group 'xxx'                     // not all warnings are known by all Clang versions and they tend to be rename-happy.. so ignoring warnings triggers new warnings on some configuration. Great!
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"                // warning: unknown warning group 'xxx'
#pragma clang diagnostic ignored "-Wold-style-cast"                 // warning: use of old-style cast                           // yes, they are more terse.
#pragma clang diagnostic ignored "-Wdeprecated-declarations"        // warning: 'xx' is deprecated: The POSIX name for this..   // for strdup used in demo code (so user can copy & paste the code)
#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"       // warning: cast to 'void *' from smaller integer type
#pragma clang diagnostic ignored "-Wformat-security"                // warning: format string is not a string literal
#pragma clang diagnostic ignored "-Wexit-time-destructors"          // warning: declaration requires an exit-time destructor    // exit-time destruction order is undefined. if MemFree() leads to users code that has been disabled before exit it might cause problems. ImGui coding style welcomes static/globals.
#pragma clang diagnostic ignored "-Wunused-macros"                  // warning: macro is not used                               // we define snprintf/vsnprintf on Windows so they are available, but not always used.
#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"  // warning: zero as null pointer constant                   // some standard header variations use #define NULL 0
#pragma clang diagnostic ignored "-Wdouble-promotion"               // warning: implicit conversion from 'float' to 'double' when passing argument to function  // using printf() is a misery with this as C++ va_arg ellipsis changes float to double.
#pragma clang diagnostic ignored "-Wreserved-id-macro"              // warning: macro name is a reserved identifier
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"  // warning: implicit conversion from 'xxx' to 'float' may lose precision
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif

// Play it nice with Windows users (Update: May 2018, Notepad now supports Unix-style carriage returns!)
#ifdef _WIN32
#define IM_NEWLINE  "\r\n"
#else
#define IM_NEWLINE  "\n"
#endif

// Helpers
#if defined(_MSC_VER) && !defined(snprintf)
#define snprintf    _snprintf
#endif
#if defined(_MSC_VER) && !defined(vsnprintf)
#define vsnprintf   _vsnprintf
#endif

// Format specifiers, printing 64-bit hasn't been decently standardized...
// In a real application you should be using PRId64 and PRIu64 from <inttypes.h> (non-windows) and on Windows define them yourself.
#ifdef _MSC_VER
#define IM_PRId64   "I64d"
#define IM_PRIu64   "I64u"
#else
#define IM_PRId64   "lld"
#define IM_PRIu64   "llu"
#endif

// Helpers macros
// We normally try to not use many helpers in imgui_demo.cpp in order to make code easier to copy and paste,
// but making an exception here as those are largely simplifying code...
// In other imgui sources we can use nicer internal functions from imgui_internal.h (ImMin/ImMax) but not in the demo.
#define IM_MIN(A, B)            (((A) < (B)) ? (A) : (B))
#define IM_MAX(A, B)            (((A) >= (B)) ? (A) : (B))
#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))

// Enforce cdecl calling convention for functions called by the standard library, in case compilation settings changed the default to e.g. __vectorcall
#ifndef IMGUI_CDECL
#ifdef _MSC_VER
#define IMGUI_CDECL __cdecl
#else
#define IMGUI_CDECL
#endif
#endif

//-----------------------------------------------------------------------------
// [SECTION] Forward Declarations, Helpers
//-----------------------------------------------------------------------------
typedef void (*ImGuiDemoMarkerCallback)(const char* file, int line, const char* section, void* user_data);
extern ImGuiDemoMarkerCallback      GImGuiDemoMarkerCallback2;
extern void* GImGuiDemoMarkerCallbackUserData2;
ImGuiDemoMarkerCallback             GImGuiDemoMarkerCallback2 = NULL;
void* GImGuiDemoMarkerCallbackUserData2 = NULL;
#define IMGUI_DEMO_MARKER(section)  do { if (GImGuiDemoMarkerCallback2 != NULL) GImGuiDemoMarkerCallback2(__FILE__, __LINE__, section, GImGuiDemoMarkerCallbackUserData2); } while (0)


imgui_menu::imgui_menu(Application* app, bool start_enabled) : Module(app, start_enabled)
{

   
}

// Destructor
imgui_menu::~imgui_menu()
{}

bool imgui_menu::Start()
{
    WindowHeight = App->window->height;
    WindowWidth = App->window->width;
    LOG("Setting up the camera");
    bool ret = true;

    return ret;
}

bool imgui_menu::KLK(bool* p_open)
{
    //Button("Close");
    // Exceptionally add an extra assert here for people confused about initial Dear ImGui setup
    // Most functions would normally just crash if the context is missing.
    IM_ASSERT(ImGui::GetCurrentContext() != NULL && "Missing dear imgui context. Refer to examples app!");
    // Examples Apps (accessible from the "Examples" menu)
    static bool show_app_main_menu_bar = false;
    static bool show_app_documents = false;
    static bool show_app_console = false;
    static bool show_app_log = false;
    static bool show_app_layout = false;
    static bool show_app_property_editor = false;
    static bool show_app_long_text = false;
    static bool show_app_auto_resize = false;
    static bool show_app_constrained_resize = false;
    static bool show_app_simple_overlay = false;
    static bool show_app_fullscreen = false;
    static bool show_app_window_titles = false;
    static bool show_app_custom_rendering = false;

    // Dear ImGui Tools/Apps (accessible from the "Tools" menu)
    static bool show_app_metrics = false;
    static bool show_app_debug_log = false;
    static bool show_app_stack_tool = false;
    static bool show_app_about = false;
    static bool show_app_style_editor = false;

    if (show_app_metrics)
        ImGui::ShowMetricsWindow(&show_app_metrics);
    if (show_app_debug_log)
        ImGui::ShowDebugLogWindow(&show_app_debug_log);
    if (show_app_stack_tool)
        ImGui::ShowStackToolWindow(&show_app_stack_tool);
    if (show_app_about)
        ImGui::ShowAboutWindow(&show_app_about);
    if (show_app_style_editor)
    {
        ImGui::Begin("Dear ImGui Style Editor", &show_app_style_editor);
        ImGui::ShowStyleEditor();
        ImGui::End();
    }

    // Demonstrate the various window flags. Typically you would just use the default!
    static bool no_titlebar = false;
    static bool no_scrollbar = false;
    static bool no_menu = false;
    static bool no_move = false;
    static bool no_resize = false;
    static bool no_collapse = false;
    static bool no_close = false;
    static bool no_nav = false;
    static bool no_background = false;
    static bool no_bring_to_front = false;
    static bool unsaved_document = false;

    ImGuiWindowFlags window_flags = 0;
    if (no_titlebar)        window_flags |= ImGuiWindowFlags_NoTitleBar;
    if (no_scrollbar)       window_flags |= ImGuiWindowFlags_NoScrollbar;
    if (!no_menu)           window_flags |= ImGuiWindowFlags_MenuBar;
    if (no_move)            window_flags |= ImGuiWindowFlags_NoMove;
    if (no_resize)          window_flags |= ImGuiWindowFlags_NoResize;
    if (no_collapse)        window_flags |= ImGuiWindowFlags_NoCollapse;
    if (no_nav)             window_flags |= ImGuiWindowFlags_NoNav;
    if (no_background)      window_flags |= ImGuiWindowFlags_NoBackground;
    if (no_bring_to_front)  window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
    if (unsaved_document)   window_flags |= ImGuiWindowFlags_UnsavedDocument;
    if (no_close)           p_open = NULL; // Don't pass our bool* to Begin

    // We specify a default position/size in case there's no data in the .ini file.
    // We only do it to make the demo applications a little more welcoming, but typically this isn't required.
    const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 650, main_viewport->WorkPos.y + 20), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_FirstUseEver);
    // Main body of the Demo window starts here.
    if (!ImGui::Begin("Menu", p_open, window_flags))
    {
        // Early out if the window is collapsed, as an optimization.
        ImGui::End();
        return UPDATE_CONTINUE;
    }
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::SmallButton("Help")) {
            help_ = !help_;
        }
        if (ImGui::SmallButton("Show Example")) {
            showExample = !showExample;
        }
        if (showExample) {
            ImGui::ShowDemoWindow();

        }
        if (ImGui::SmallButton("Close")) {
            return false;
        }
        ImGui::SameLine();

        ImGui::SameLine();
        ImGui::EndMenuBar();

        if (help_) {
            ImGui::BeginChild("Help");

            if (ImGui::SmallButton("About")) {
                about_ = !about_;
            }
            if (about_) {
                ImGui::BulletText("Regular Engine v0.01");
                ImGui::BulletText("Engine produced for practicing and developing new skills");
                ImGui::BulletText("By: Pau Olmos Serrano");
                ImGui::BulletText("External libraries: \n\n\tSDL2\n\n\tImGui v1.89\n\n\tGlew\n\n\tMathGeoLib\n\n\tAssimp\n\n\tDevIl\n\n\tPhysFS\n\n");
                ImGui::BulletText("MIT License\n\n Copyright(c) 2022 Pau Olmos\n\n");
            }
            if (ImGui::SmallButton("GitHub")) {
                SDL_OpenURL("https://github.com/PauOlmos/REGULAR_ENGINE");
            }
            if (ImGui::SmallButton("FAQs")) {
                //App->RequestBrowser("https://FAQs");

            }
            ImGui::EndChild();

        }
        char buf[25]{};
        std::string s1{ "REGULAR ENGINE" };
        std::string s2{ "UPC CITM" };
        if (ImGui::CollapsingHeader("Configuration")) {

            ImGui::BulletText("Options");
            if (ImGui::CollapsingHeader("Application")) {
                float startTicks = SDL_GetTicks();
                strncpy(buf, s1.c_str(), sizeof(buf) - 1);
                ImGui::InputText("App Name", buf, sizeof(buf));
                s1 = buf;
                strncpy(buf, s2.c_str(), sizeof(buf) - 1);
                ImGui::InputText("Organization", buf, sizeof(buf));
                s2 = buf;
                HistogramFps();
                HistogramMs();
                float frameTicks = SDL_GetTicks() - startTicks;
                ImGui::SliderFloat("Max FPS", &_maxFPS, 30.f, 120.f);
                if (1000.0f / _maxFPS > frameTicks)
                {
                    SDL_Delay(1000.0f / _maxFPS - frameTicks);
                }
            }
            if (ImGui::CollapsingHeader("Window")) {

                if (ImGui::Checkbox("Fullscreen", &fullscreen)) {
                    if (fullscreen == true) {
                        App->renderer3D->OnResize(SCREEN_WIDTH, SCREEN_HEIGHT);
                        SDL_SetWindowSize(App->window->window, SCREEN_WIDTH, SCREEN_HEIGHT);
                        SDL_SetWindowFullscreen(App->window->window, SDL_WINDOW_FULLSCREEN);
                    }
                    else {
                        SDL_SetWindowFullscreen(App->window->window, SDL_WINDOW_MAXIMIZED);
                    }
                }
                ImGui::SliderFloat("Brightness", &Brightness, 0.f, 1.f);

                SDL_SetWindowBrightness(App->window->window, Brightness);



                if (fullscreen == false) {

                    if (active16_9 == true) {

                        ImGui::SliderFloat("Size", &WindowHeight, 0.f, 2160.0f, "%.0f");

                        WindowWidth = WindowHeight * 1.3333333;

                        WindowHeight = trunc(WindowHeight);
                        if (WindowHeight > 2160.0f) {
                            WindowHeight = 2160.0f;
                        }
                        App->renderer3D->OnResize(WindowWidth, WindowHeight);
                        SDL_SetWindowSize(App->window->window, WindowWidth, WindowHeight);
                        if (WindowWidth > 2872.0f) {
                            WindowWidth = 2872.0f;
                        }
                        WindowHeight = WindowWidth / 1.333333;

                        WindowWidth = trunc(WindowWidth);

                        App->renderer3D->OnResize(WindowWidth, WindowHeight);
                        SDL_SetWindowSize(App->window->window, WindowWidth, WindowHeight);
                    }
                    else {

                        ImGui::SliderFloat("Width", &WindowWidth, 0.f, 2872.0f, "%.0f");
                        ImGui::SliderFloat("Height", &WindowHeight, 0.f, 2160.0f, "%.0f");
                        WindowHeight = trunc(WindowHeight);
                        if (WindowHeight > 2160.0f) {
                            WindowHeight = 2160.0f;
                        }
                        App->renderer3D->OnResize(WindowWidth, WindowHeight);
                        SDL_SetWindowSize(App->window->window, WindowWidth, WindowHeight);
                        if (WindowWidth > 2872.0f) {
                            WindowWidth = 2872.0f;
                        }

                        WindowWidth = trunc(WindowWidth);

                        App->renderer3D->OnResize(WindowWidth, WindowHeight);
                        SDL_SetWindowSize(App->window->window, WindowWidth, WindowHeight);
                    }

                }
                if (ImGui::Checkbox("16:9", &active16_9)) {
                    active16_9 != active16_9;
                }
                if (ImGui::Button("Predet.")) {
                    WindowWidth = SCREEN_WIDTH;
                    WindowHeight = SCREEN_HEIGHT;
                    Brightness = 1.0f;
                    SDL_SetWindowFullscreen(App->window->window, SDL_WINDOW_MAXIMIZED);
                    fullscreen = false;
                    active16_9 = false;
                }

                if (ImGui::Checkbox("Vsync", &Vsync)) {
                    SDL_GL_SetSwapInterval(0);
                }
            }

            if (ImGui::CollapsingHeader("Hardware")) {
                ImGui::BulletText("SDL Version: %d.%d.%d", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);
                ImGui::BulletText("CPUs: %d", SDL_GetCPUCount());
                ImGui::BulletText("CPU Cache: %d kb", SDL_GetCPUCacheLineSize());
                float RAM = SDL_GetSystemRAM() / 1000;
                ImGui::BulletText("System RAM %.1f Gb", RAM);
            }
            if (ImGui::CollapsingHeader("Create")) {
                if(ImGui::Checkbox("Cube",&CubeRenderer)) {
                    if (CubeRenderer == true) {
                        Quad* Q = new Quad();
                        App->primitives1->QuadList.push_back(Q);
                        App->primitives1->QuadList[App->primitives1->numQuads]->name = App->primitives1->numQuads * 10;
                        App->primitives1->numQuads++;
                    }
                }
                if(ImGui::Checkbox("Cilindre",&CilindreRenderer)) {
                    //App->primitives1->DrawCilindre(5,5);
                }
                if(ImGui::Checkbox("Piramid",&PiramidRenderer)) {
                    //App->primitives1->DrawCilindre(5,5);
                }
            }
        }
    }

    if (CubeRenderer) {
        for (int i = 0; i < App->primitives1->numQuads; i++) {
            App->primitives1->DrawCube(App->primitives1->QuadList[i]);
        }
    }

    // Most "big" widgets share a common width settings by default. See 'Demo->Layout->Widgets Width' for details.
    // e.g. Use 2/3 of the space for widgets and 1/3 for labels (right align)
    //ImGui::PushItemWidth(-ImGui::GetWindowWidth() * 0.35f);
    // e.g. Leave a fixed amount of width for labels (by passing a negative value), the rest goes to widgets.
    ImGui::PushItemWidth(ImGui::GetFontSize() * -12);

    // Menu Bar
   

    // End of ShowDemoWindow()
    ImGui::PopItemWidth();
    ImGui::End();
    //return UPDATE_CONTINUE;
}

void imgui_menu::HistogramFps()
{
    //FPS
    {
        ImGui::BulletText("Average fps: %.0f",averageFps / 1000);
        showDelay += App->dt * 1000;
        if (showDelay > App->dt * 1000) {
            showDelay = 0;
            averageFps = 0;
            for (int i = 0; i <= FPS.size(); i++) {
                averageFps += (1000 / App->dt * 1);
            }
            averageFps = averageFps / FPS.size();
        }

        if (FPS.size() < 60)
        {
            FPS.push_back(trunc(1000 / (App->dt * 1000)));
        }

        else if (FPS.size() == 60)
        {
            for (int i = 0; i <= 58; i++)
            {
                FPS[i] = FPS[i + 1];

            }

            FPS[59] = trunc(1000 / (App->dt * 1000));
        }

        SDL_GetPerformanceCounter();

        ImGui::PlotHistogram("##FPS", FPS.data(), FPS.size(), 0, NULL, 0.f, 240.f, ImVec2(310, 100));
    }
   
}

void imgui_menu::HistogramMs()
{
  
    {
        ImGui::BulletText("Ms: ");
        if (Miliseconds.size() < 60)
        {
            Miliseconds.push_back(App->dt * 1000);
        }

        else if (Miliseconds.size() == 60)
        {
            for (int i = 0; i <= 58; i++)
            {
                Miliseconds[i] = Miliseconds[i + 1];

            }
            Miliseconds[59] = App->dt * 1000;
        }

        SDL_GetPerformanceCounter();

        ImGui::PlotHistogram("##Milisecods", Miliseconds.data(), Miliseconds.size(), 0, NULL, 0.f, 80.f, ImVec2(310, 100));
    }
}
