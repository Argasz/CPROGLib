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
        std::unordered_map<SDL_Keycode, std::function<void(ControlledSpriteEntity*)>> keyDownListeners;
        std::unordered_map<SDL_Keycode, std::function<void(ControlledSpriteEntity*)>> keyUpListeners;
    public:
        static ControlledSpriteEntity* getInstance(const std::string& imagePath, int x, int y, int w, int h, std::string& id, int collType = 0){
            return new ControlledSpriteEntity(imagePath,x,y,w,h,id,collType);
        }
        void addKeyDownListener(SDL_Keycode k, const std::function<void(ControlledSpriteEntity*)> lambda);
        void addKeyUpListener(SDL_Keycode k, const std::function<void(ControlledSpriteEntity*)> lambda);
        void listen(SDL_Event &e);
    protected:
        ControlledSpriteEntity(const std::string& imagePath, int x, int y, int w, int h, std::string& id, int collType = 0) :SpriteEntity(imagePath, x, y, w, h, id, collType){};


    };
}

#endif //CPROGLIB_CONTROLLEDSPRITEENTITY_H
