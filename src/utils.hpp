#pragma once

#include "raylib/raylib-cpp.hpp"

Vector2 operator +(Vector2 u, Vector2 v) {
    return (Vector2){u.x + v.x, u.y + v.y};
}

Vector2 operator -(Vector2 u, Vector2 v) {
    return (Vector2){u.x - v.x, u.y - v.y};
}

template <typename T>
Vector2 operator *(T k, Vector2 u) {
    return (Vector2){k * u.x, k * u.y};
}

template <typename T>
Vector2 operator *(Vector2 u, T k) {
    return (Vector2){k * u.x, k * u.y};
}

Vector2 polar(double r, float theta) {
    return r * (Vector2){cos(theta), sin(theta)};
}