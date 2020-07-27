#pragma once
#include "gameobject.h"
#include "shooter.h"

class Player : public Shooter{
public:
    enum class Direction { 
        kLeft = -1, 
        kRight = 1 
    };

    Player(int grid_width, int grid_height) : 
        Shooter(grid_width, grid_height, grid_width / 2, grid_height - 1),
        lives(5),
        should_move(false), 
        direction_(Direction::kLeft),
        should_shoot(false)
    {}

    int lives;

    void Update() override;
    void Move(Player::Direction direction);
    void EnableShooting();
    void DecreaseHealth();
    bool IsAlive() { return lives > 0; }

    std::unique_ptr<Bullet> Shoot() override;
    
    bool BeenShot(std::unique_ptr<Bullet> &bullet) override;
        
private:
    bool should_move;
    Direction direction_;
    bool should_shoot;

};