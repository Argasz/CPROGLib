//
// Created by Aron on 2018-11-29.
//

#include "ControlledSpriteEntity.h"


void ControlledSpriteEntity::addListener(const SDL_EventType& e, const InputListener& ipl) {
    listeners.insert(e, ipl);
}

void ControlledSpriteEntity::tick(SDL_Event e) {
    InputListener* i = listeners[e.type];
    if(i != nullptr){
        i->react(e);
    }
}