//
// Created by Aron on 2018-11-23.
//

#ifndef CPROGLIB_SPRITE_H
#define CPROGLIB_SPRITE_H


#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Window.h"
namespace CPROGLib{
    class Sprite {
    private:
        std::string imagePath;
        SDL_Texture* texture;
    public:
        static Sprite* getInstance(const std::string& imagePath){
            return new Sprite(imagePath);
        }
        virtual void draw(const SDL_Rect& rect);
        virtual ~Sprite();

    protected:
        Sprite(const std::string& imagePath);
        SDL_Texture* getTexture(){
            return texture;
        }
    };
}

#endif //CPROGLIB_SPRITE_H
