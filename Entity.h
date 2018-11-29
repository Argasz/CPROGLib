//
// Created by Aron on 2018-11-25.
//

#ifndef CPROGLIB_ENTITY_H
#define CPROGLIB_ENTITY_H


#include <SDL_render.h>
#include "Sprite.h"

class Entity {
public:
    virtual void tick() = 0;
    virtual void draw(SDL_Renderer* rend) {};
    virtual ~Entity() = default;
    Entity(const Entity& obj) = delete;
    Entity& operator=(const Entity&) = delete;
protected:
    Entity() = default;
};


#endif //CPROGLIB_ENTITY_H
