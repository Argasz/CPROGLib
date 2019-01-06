//
// Created by Aron on 2018-11-29.
//

#ifndef CPROGLIB_CONTROLLEDSPRITEENTITY_H
#define CPROGLIB_CONTROLLEDSPRITEENTITY_H


#include "SpriteEntity.h"
#include <functional>
#include <SDL.h>
#include <unordered_map>

namespace CPROGLib{
    class ControlledSpriteEntity : public SpriteEntity {
    private:
        std::unordered_map<SDL_Keycode, std::function<void(Entity*)>> keyDownListeners;
        std::unordered_map<SDL_Keycode, std::function<void(Entity*)>> keyUpListeners;
    public:
        ControlledSpriteEntity(const std::string& imagePath, int x, int y, int w, int h, std::string& id, EventLoop& el, int collType);
        void addKeyDownListener(SDL_Keycode k, const std::function<void(Entity*)>& lambda);
        void addKeyUpListener(SDL_Keycode k, const std::function<void(Entity*)>& lambda);
        void listen(SDL_Event &e);

    };
}

#endif //CPROGLIB_CONTROLLEDSPRITEENTITY_H
