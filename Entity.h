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
        virtual void listen(SDL_Event &ev) = 0; //TODO:move?
        virtual void trackWithCamera(){}; //SpriteEntity?
        virtual void untrack() {}; //SpriteEntity?
        virtual bool isTracked() {}; //SpriteEntity?
        virtual SDL_Rect& getRect(){};
        virtual ~Entity() = default;
        virtual std::string debugText() = 0;
        std::string getId() const {
            return id;
        }
        Entity(const Entity& obj) = delete;
        Entity& operator=(const Entity&) = delete;
    protected:
        Entity(EventLoop& el, std::string& id) {this->id = id; this->el = &el;};
        EventLoop* getEventLoop(){
            return el;
        };
    private:
        EventLoop* el;
        std::string id;
    };
}

#endif //CPROGLIB_ENTITY_H
