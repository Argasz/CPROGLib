//
// Created by Aron on 2018-11-25.
//

#ifndef CPROGLIB_ENTITY_H
#define CPROGLIB_ENTITY_H


#include <SDL_render.h>
#include "Sprite.h"

class Entity {
public:
    virtual void tick(SDL_Event ev) = 0;
    virtual void draw(SDL_Renderer* rend) = 0;
    virtual void move(){};
    virtual void addVel(int dx, int dy) {};
    virtual bool isColliding(const Entity& e) const {};
    virtual const SDL_Rect& getRect() const{};
    virtual ~Entity() = default;
    Entity(const Entity& obj) = delete;
    Entity& operator=(const Entity&) = delete;
protected:
    Entity() = default;
};


#endif //CPROGLIB_ENTITY_H
