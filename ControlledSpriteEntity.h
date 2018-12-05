//
// Created by Aron on 2018-11-29.
//

#ifndef CPROGLIB_CONTROLLEDSPRITEENTITY_H
#define CPROGLIB_CONTROLLEDSPRITEENTITY_H


#include "SpriteEntity.h"
#include "InputListener.h"
#include <SDL.h>
#include <unordered_map>


class ControlledSpriteEntity : public SpriteEntity {
private:
    std::unordered_map<SDL_EventType, InputListener> listeners;
public:
    void addListener(const SDL_EventType& e, const InputListener& ipl);
    void tick(SDL_Event e);
};


#endif //CPROGLIB_CONTROLLEDSPRITEENTITY_H
