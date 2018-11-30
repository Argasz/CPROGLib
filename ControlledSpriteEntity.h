//
// Created by Aron on 2018-11-29.
//

#ifndef CPROGLIB_CONTROLLEDSPRITEENTITY_H
#define CPROGLIB_CONTROLLEDSPRITEENTITY_H


#include "SpriteEntity.h"
#include <SDL.h>
#include <vector>

class ControlledSpriteEntity : public SpriteEntity {
private:
    std::vector<void()> listeners;
public:
    void addListener();
    void tick(SDL_Event e);
};


#endif //CPROGLIB_CONTROLLEDSPRITEENTITY_H
