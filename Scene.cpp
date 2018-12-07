//
// Created by Aron on 2018-12-06.
//

#include <SDL_image.h>
#include "Scene.h"

Scene::Scene(int w, int h, int startX, int startY, std::string &bgImgPath, Window* win) {
    SDL_Surface* s = IMG_Load(bgImgPath.c_str());
    SDL_Renderer* ren = win->getRenderer();
    bgImage = SDL_CreateTextureFromSurface(ren, s);
    int topLeftY = s->h - win->getHeight();
    SDL_Rect srcRect = {0, topLeftY, win->getWidth(), win->getHeight()};

    SDL_FreeSurface(s);
}