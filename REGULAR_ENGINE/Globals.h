#pragma once

// Warning disabled ---
#pragma warning( disable : 4577 ) // Warning that exceptions are disabled
#pragma warning( disable : 4530 ) // Warning that exceptions are disabled

#include <windows.h>
#include <stdio.h>

#define LOG(type, format, ...) log(__FILE__, __LINE__, format,type, __VA_ARGS__);
enum class LogType
{
	LOGS,
	ERRORS,
	WARNING,
};
enum class GameObjectType
{
	PPLANE,
	QUAD,
	PYRAMIDE,
};
void log(const char file[], int line, const char* format,LogType type, ...);

#define CAP(n) ((n <= 0.0f) ? n=0.0f : (n >= 1.0f) ? n=1.0f : n=n)

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#define HAVE_M_PI


typedef unsigned int uint;

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};



// Configuration -----------
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 1080
#define SCREEN_SIZE 1
#define WIN_FULLSCREEN false
#define WIN_RESIZABLE true
#define WIN_BORDERLESS false
#define WIN_FULLSCREEN_DESKTOP false
#define VSYNC true
#define TITLE "3D Physics Playground"