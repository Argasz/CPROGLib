//
// Created by Aron on 2018-11-25.
//

#ifndef CPROGLIB_ENTITY_H
#define CPROGLIB_ENTITY_H


#include <SDL_render.h>
#include <functional>
#include "Sprite.h"
namespace CPROGLib{
class Entity {
    public:
        virtual void tick(SDL_Event& ev) = 0;
        virtual void draw(SDL_Rect& camera) = 0;
        virtual void setCollideFunc(std::function<void(Entity&, Entity&)> f) = 0;
        virtual void collide(Entity& e) = 0;
        virtual void trackWithCamera(){};
        virtual void untrack() {};
        virtual bool isTracked() {};
        virtual void move(SDL_Rect& bounds){};
        virtual void addVel(int dx, int dy) {};
        virtual void setXVel(int dx)= 0;
        virtual void setYVel(int dy) = 0;
        virtual bool isColliding(SDL_Rect& r) const {};
        virtual SDL_Rect& getRect(){};
        virtual ~Entity() = default;
        Entity(const Entity& obj) = delete;
        Entity& operator=(const Entity&) = delete;
        virtual std::string debugText() = 0;
    protected:
        std::string id;
        Entity(std::string& id) {this->id = id;};
    };
}

#endif //CPROGLIB_ENTITY_H
