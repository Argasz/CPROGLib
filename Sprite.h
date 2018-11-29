//
// Created by Aron on 2018-11-23.
//

#ifndef CPROGLIB_SPRITE_H
#define CPROGLIB_SPRITE_H


#include <string>
#include "SDL.h"

class Window;
class Sprite {
private:
    std::string imagePath;
    SDL_Surface* surface;
public:
    Sprite(const std::string& imagePath);
    virtual void draw(SDL_Renderer* rend, const SDL_Rect rect);
    ~Sprite();
};


#endif //CPROGLIB_SPRITE_H
