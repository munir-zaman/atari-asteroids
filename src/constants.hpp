#pragma once
#include "raylib/raylib.hpp"

#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720

#define WINDOW_TITLE "Atari Asteroids"
#define WINDOW_BG_COLOR BLACK

#define WINDOW_WIDTH GetRenderWidth()
#define WINDOW_HEIGHT GetRenderHeight()
#define WINDOW_CENTER {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}

#define ASTEROID_MAX_VELOCITY  50
#define ASTEROID_MIN_VELOCITY -50

#define PLAYER_COLOR WHITE