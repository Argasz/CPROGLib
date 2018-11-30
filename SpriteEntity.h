//
// Created by Aron on 2018-11-29.
//

#ifndef CPROGLIB_SPRITEENTITY_H
#define CPROGLIB_SPRITEENTITY_H


#include "Entity.h"

class SpriteEntity : public Entity{
private:
    Sprite* sprite;
    SDL_Rect rect;
public:
    SpriteEntity(const std::string& imagePath, int x, int y, int w, int h);
    virtual void draw(SDL_Renderer* rend){
        sprite->draw(rend, rect);
    };
    virtual void tick();
    virtual void move(int dx, int dy);
    virtual ~SpriteEntity();

};


#endif //CPROGLIB_SPRITEENTITY_H
