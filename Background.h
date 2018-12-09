//
// Created by Aron on 2018-12-06.
//

#ifndef CPROGLIB_BACKGROUND_H
#define CPROGLIB_BACKGROUND_H


#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"

class Background {
public:
    Background(const std::string& bgImgPath);
    void draw(SDL_Rect& camera, Window& win);
    int getWidth(){return surf->w;}
    int getHeight(){return surf->h;}
    ~Background();
private:
    SDL_Surface* surf;
};


#endif //CPROGLIB_BACKGROUND_H
