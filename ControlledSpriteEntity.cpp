//
// Created by Aron on 2018-11-29.
//

#include "ControlledSpriteEntity.h"


ControlledSpriteEntity::ControlledSpriteEntity(const std::string &imagePath, int x, int y, int w, int h)
:SpriteEntity(imagePath, x, y, w, h) {
}

void ControlledSpriteEntity::addListener(const Uint32 e, InputListener* ipl) {
    std::pair<Uint32, InputListener*> p = std::make_pair(e, ipl);
    listeners.insert(p);
}

void ControlledSpriteEntity::tick(SDL_Event e) {
    InputListener* i = listeners[e.type];
    if(i != nullptr){
        i->react(e);
    }
}