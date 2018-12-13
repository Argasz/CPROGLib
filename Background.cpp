//
// Created by Aron on 2018-12-06.
//

#include "Background.h"

namespace CPROGLib{
    Background::Background(const std::string& bgImgPath) {
        texture = IMG_LoadTexture(window->getRenderer(),bgImgPath.c_str());
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }

    void Background::draw(SDL_Rect &camera) {
        SDL_Renderer* rend = window->getRenderer();
        SDL_Rect rect = {0, 0, window->getWidth(), window->getHeight()};
        SDL_RenderCopy(rend, texture, &camera, &rect);
    }

    Background::~Background(){
        SDL_DestroyTexture(texture);
    }

}