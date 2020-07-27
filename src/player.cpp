#include "player.h"
#include <iostream>
#include <algorithm>

void Player::Update() {
    if(!should_move)
        return;

    should_move = false;
    x_ = x_ + static_cast<float>(direction_);
        
    ClampCoordinates();
}

void Player::Move(Player::Direction direction) {
    should_move = true;
    direction_ = direction;
}

void Player::EnableShooting() {
    should_shoot = true;
}

std::unique_ptr<Bullet> Player::Shoot() {
    if(!should_shoot)
        return nullptr;
    
    should_shoot = false;

    return std::make_unique<Bullet>(grid_width_, grid_height_, x_ + 0.4f, y_, Bullet::Direction::kUP);
}

void Player::DecreaseHealth() {
    lives--;
}

    
bool Player::BeenShot(std::unique_ptr<Bullet> &bullet) {

    if((bullet->x_ >= x_ - 0.1f   &&  bullet->x_ < x_ + 1.1f) &&
        bullet->y_ > grid_height_ - 1.5f) {

        return true;
    }
    return false;
}


        