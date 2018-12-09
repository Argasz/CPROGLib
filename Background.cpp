//
// Created by Aron on 2018-12-06.
//

#include "Background.h"

Background::Background(const std::string& bgImgPath) {
    surf = IMG_Load(bgImgPath.c_str());
}

void Background::draw(SDL_Rect &camera, Window& win) {
    SDL_Renderer* rend = win.getRenderer();
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surf);
    SDL_Rect rect = {0, 0, win.getWidth(), win.getHeight()};
    SDL_RenderCopy(rend, tex, &camera, &rect);
    SDL_DestroyTexture(tex);
}

Background::~Background(){
    SDL_FreeSurface(surf);
}