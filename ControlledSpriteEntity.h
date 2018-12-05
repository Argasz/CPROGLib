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
    std::unordered_map<Uint32 , InputListener*> listeners;
public:
    ControlledSpriteEntity(const std::string& imagePath, int x, int y, int w, int h);
    void addListener(const Uint32 e,InputListener* ipl);
    void tick(SDL_Event e);
    using SpriteEntity::draw;

};


#endif //CPROGLIB_CONTROLLEDSPRITEENTITY_H
