//
// Created by Aron on 2018-11-29.
//

#include "ControlledSpriteEntity.h"


void ControlledSpriteEntity::addListener(void (*listen)(SDL_Event, ControlledSpriteEntity) ) {
    listeners.push_back(listen);
}

void ControlledSpriteEntity::tick(SDL_Event e) {
    for(auto f : listeners){
        f(e, this);
    }//TODO: RETHINK
}