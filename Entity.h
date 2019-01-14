//
// Created by Aron on 2018-11-25.
//

#ifndef CPROGLIB_ENTITY_H
#define CPROGLIB_ENTITY_H


#include <SDL_render.h>
#include <functional>
#include "Sprite.h"
#include "Collider.h"
namespace CPROGLib{
    class EventLoop;
    //TODO: Polymorfa klasser ska inte tillåta värdesemantik (getInstance factories)
class Entity { //TODO: Rewrite, entity has eventloop member, move methods down into hierarchy, restructure eventloop.
    public:
        virtual void tick() = 0;
        virtual void listen(SDL_Event &ev) = 0;
        virtual void draw(SDL_Rect& camera) = 0;
        virtual void collide(Entity& e) = 0;
        virtual void trackWithCamera(){};
        virtual void untrack() {};
        virtual bool isTracked() {};
        virtual void move(SDL_Rect& bounds){};
        virtual void addVel(int dx, int dy) {};
        //virtual void setXVel(int dx)= 0;
        //virtual void setYVel(int dy) = 0;
        virtual bool isColliding(Collider& c) const {};
        virtual SDL_Rect& getRect(){};
        virtual ~Entity() = default;
        virtual std::string debugText() = 0;
        Entity(const Entity& obj) = delete;
        Entity& operator=(const Entity&) = delete;
    protected:
        std::string id;//TODO:Private
        Entity(EventLoop& el, std::string& id) {this->id = id; this->el = &el;};
        EventLoop* el;//TODO:Private
    };
}

#endif //CPROGLIB_ENTITY_H
