//
// Created by Aron on 2018-12-05.
//

#ifndef CPROGLIB_INPUTLISTENER_H
#define CPROGLIB_INPUTLISTENER_H


#include <SDL.h>
#include "Entity.h"

class InputListener {
public:
    virtual void react(const SDL_Event& ev) = 0;
    ~InputListener();
    InputListener(const InputListener& obj) = delete;
    InputListener& operator=(const InputListener&) = delete;
protected:
    InputListener(Entity* e);
    Entity* entity;
};


#endif //CPROGLIB_INPUTLISTENER_H
