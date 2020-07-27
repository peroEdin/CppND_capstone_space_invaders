#pragma once

#include "gameobject.h"

class Bullet : public GameObject{
public:
    enum class Direction{
        kUP = -1,
        kDown = 1
    };

    Bullet(int grid_width, int grid_height, float x, float y, Direction direction) : 
        GameObject(grid_width, grid_height, x, y), 
        speed(0.1), 
        direction_(direction)
    {}
    
    void Update();
    bool OutOfScreen();
    bool CollisionDetected(Bullet &bullet);

private:
    float speed;
    Direction direction_;
};