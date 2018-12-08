//
// Created by Aron on 2018-11-29.
//

#include "ControlledSpriteEntity.h"


ControlledSpriteEntity::ControlledSpriteEntity(const std::string &imagePath, int x, int y, int w, int h)
:SpriteEntity(imagePath, x, y, w, h) {
}

void ControlledSpriteEntity::addKeyDownListener(const SDL_Keycode k, const std::function<void(Entity*)>& lambda) {
    std::pair<Uint32 , std::function<void(Entity*)>> p = std::make_pair(k, lambda);
    keyDownListeners.insert(p);
}
void ControlledSpriteEntity::addKeyUpListener(const SDL_Keycode k, const std::function<void(Entity*)>& lambda) {
    std::pair<Uint32 , std::function<void(Entity*)>> p = std::make_pair(k, lambda);
    keyUpListeners.insert(p);
}

void ControlledSpriteEntity::tick(SDL_Event& e) {
    if(e.key.repeat == 0){
        std::function<void(Entity*)> i;
        if(e.type == SDL_KEYDOWN)
            i = keyDownListeners[e.key.keysym.sym];
        else if(e.type == SDL_KEYUP)
            i = keyUpListeners[e.key.keysym.sym];

        if(i != nullptr){ //TODO: Error message
            i(this);
        }
    }
}

