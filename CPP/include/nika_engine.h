#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include <cmath>
#include <process.h>
#include <chrono>

#define NikaWindow HWND
using callBack = void(*)();
inline extern HWND _hwnd = nullptr;
inline extern HDC hdc = nullptr;
inline extern HDC hdcMem = nullptr;
inline extern HBITMAP hbMap = nullptr;
inline extern HBITMAP hOldBMap = nullptr;
inline extern RECT windowSize = RECT{0};

#include "math/vec2.h"
#include "math/vec3.h"
#include "structs/nika_object.h"
#include "window/nika_window.h"
#include "graphics/create_object.h"
#include "physics/physics.h"