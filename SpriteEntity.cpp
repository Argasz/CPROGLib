//
// Created by Aron on 2018-11-29.
//

#include "SpriteEntity.h"

SpriteEntity::SpriteEntity(const std::string& imagePath, int x, int y, int w, int h) {
    sprite = new Sprite(imagePath);
    rect = {x, y, w, h};
    xvel = 0;
    yvel = 0;
}

void SpriteEntity::tick(SDL_Event ev) {
    move();
}

void SpriteEntity::addVel(int dx, int dy) {
    this->xvel += dx;
    this->yvel += dy;

    if(xvel >= maxVel || xvel <= -maxVel){
        xvel = 10;
    }
    if(yvel >= maxVel || yvel <= -maxVel){
        yvel = 10;
    }
}

void SpriteEntity::move(){
    rect.x += xvel;
    rect.y += yvel;
}

const SDL_Rect& SpriteEntity::getRect() const{
    return rect;
}

bool SpriteEntity::isColliding(const Entity &se) const{
    SDL_Rect other = se.getRect();
    bool ycoll = (this->rect.x <= (other.x + other.w) && (other.x <= (this->rect.x + this->rect.w)));
    bool xcoll = (this->rect.y <= (other.y + other.h) && (other.y <= (this->rect.y + this->rect.h)));
    return ycoll && xcoll;
}

SpriteEntity::~SpriteEntity() {
    delete sprite;
}