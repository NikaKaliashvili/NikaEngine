#pragma once

#include <Windows.h>
#include <string>
#include <process.h>

#define NikaWindow HWND
using callBack = void(*)();
inline extern HDC hdc = nullptr;
inline extern HDC hdcMem = nullptr;

#include "math/vec2.h"
#include "window/nika_window.h"
#include "graphics/create_object.h"
#include "physics/physics.h"