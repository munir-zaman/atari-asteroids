#include "raylib/raylib.hpp"
#include "coordinates.hpp"

#include "iostream"

typedef struct
{
    Vector2 pos = {0, 0};
    Vector2 velocity = {100, 200};
    double size;


    void draw() {

        pos = pos + velocity * GetFrameTime();

        Vector2 vert1 = world_to_pixel_coord(polar(size, PI / 2) + pos);
        Vector2 vert2 = world_to_pixel_coord(polar(size, PI + PI / 4) + pos);
        Vector2 vert3 = world_to_pixel_coord(polar(size, - PI / 4) + pos);

        DrawTriangleLines(vert1, vert2, vert3, BLUE);
    }
} Player;
