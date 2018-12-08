//
// Created by Aron on 2018-11-25.
//

#ifndef CPROGLIB_ENTITY_H
#define CPROGLIB_ENTITY_H


#include <SDL_render.h>
#include <functional>
#include "Sprite.h"

class Entity {
public:
    virtual void tick(SDL_Event& ev) = 0;
    virtual void draw(SDL_Renderer* rend, SDL_Rect& camera) = 0;
    virtual void setCollideFunc(std::function<void(Entity&, Entity&)> f) = 0;
    virtual void collide(Entity& e) = 0;
    virtual void trackWithCamera(){};
    virtual void untrack() {};
    virtual bool isTracked() {};
    virtual void move(SDL_Rect& bounds){};
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
