//
// Created by Aron on 2018-12-06.
//

#ifndef CPROGLIB_BACKGROUND_H
#define CPROGLIB_BACKGROUND_H


#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Background {
public:
    Background(std::string& bgImgPath);
    void draw(int camX, int camY, SDL_Renderer* rend);
private:
    SDL_Surface surf;
};


#endif //CPROGLIB_BACKGROUND_H
