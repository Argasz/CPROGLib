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

void SpriteEntity::tick(SDL_Event& ev) {
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

void SpriteEntity::move(SDL_Rect& bounds){ //TODO: check level bounds
    rect.x += xvel;
    rect.y += yvel;
    if( ( rect.x < 0 ) || ( rect.x > bounds.w) ) {
        rect.x -= xvel;
    }
    if( ( rect.y < 0 ) || ( rect.y > bounds.h) ) {
        rect.y -= yvel;
    }
}

SDL_Rect& SpriteEntity::getRect(){
    return rect;
}

bool SpriteEntity::isColliding(SDL_Rect& r) const{
    bool ycoll = (this->rect.x <= (r.x + r.w) && (r.x <= (this->rect.x + this->rect.w)));
    bool xcoll = (this->rect.y <= (r.y + r.h) && (r.y <= (this->rect.y + this->rect.h)));
    return ycoll && xcoll;
}

SpriteEntity::~SpriteEntity() {
    delete sprite;
}

void SpriteEntity::setCollideFunc(std::function<void(Entity&, Entity&)> f) {
    collideFunc = f;
}