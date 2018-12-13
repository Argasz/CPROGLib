//
// Created by Aron on 2018-12-06.
//

#ifndef CPROGLIB_BACKGROUND_H
#define CPROGLIB_BACKGROUND_H


#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"

namespace CPROGLib{
    class Background {
    public:
        Background(const std::string& bgImgPath);
        void draw(SDL_Rect& camera);
        int getWidth(){return width;}
        int getHeight(){return height;}
        ~Background();
    private:
        SDL_Texture* texture;
        int width, height;
    };
}

#endif //CPROGLIB_BACKGROUND_H
