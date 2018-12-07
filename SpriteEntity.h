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
    int xvel, yvel;
    int maxVel = 50;
public:
    SpriteEntity(const std::string& imagePath, int x, int y, int w, int h);
    virtual void draw(SDL_Renderer* rend){
        sprite->draw(rend, rect);
    };
    const SDL_Rect& getRect() const;
    virtual void tick(SDL_Event ev);
    virtual void move();
    virtual ~SpriteEntity();
    virtual void addVel(int dx, int dy);
    virtual bool isColliding(const Entity& se) const;
    void setMaxVel(int vel){
        maxVel = vel;
    }
    int getMaxVel(){
        return maxVel;
    }

};


#endif //CPROGLIB_SPRITEENTITY_H
