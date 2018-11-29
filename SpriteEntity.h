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
    void draw(SDL_Renderer* rend){
        sprite->draw(rend, rect);
    };
    void tick();
    ~SpriteEntity();

};


#endif //CPROGLIB_SPRITEENTITY_H
