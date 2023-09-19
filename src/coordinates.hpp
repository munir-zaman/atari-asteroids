#pragma once

#include "constants.hpp"
#include "raylib/raylib.hpp"
#include "math.h"


Vector2 world_to_pixel_coord(Vector2 world_pos) {

    // centered coordinate system
    int pixel_coord_x = world_pos.x + WINDOW_WIDTH/2;
    int pixel_coord_y = WINDOW_HEIGHT/2 - world_pos.y;
    
    // clamp pixel_coord_x and pixel_coord_y
    if (pixel_coord_x < 0) {
        pixel_coord_x = WINDOW_WIDTH + pixel_coord_x;
    }

    if (pixel_coord_y < 0) {
        pixel_coord_y = WINDOW_HEIGHT + pixel_coord_y;
    }

    Vector2 pixel_coord = {
        pixel_coord_x % WINDOW_WIDTH,
        pixel_coord_y % WINDOW_HEIGHT
    };

    return pixel_coord;
}


Vector2 operator+(Vector2 v1, Vector2 v2) {

    Vector2 v_sum = {
        v1.x + v2.x,
        v1.y + v2.y
    };

    return v_sum;
}

double operator*(Vector2 v1, Vector2 v2) {
    double dot_prod = v1.x * v2.x + v1.y * v2.y;
    return dot_prod;
}

Vector2 operator*(double k, Vector2 v1) {
    return (Vector2){ k * v1.x, k * v1.y};
}

Vector2 polar(double r, double theta) {
    return r * (Vector2){cos(theta), sin(theta)};
}