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
        int xw = camera.x+camera.w;
        if(xw > width){
            int newW = (xw - width) % width;
            SDL_Rect right = {0, camera.y,newW,camera.h};
            SDL_Rect rightDst {rect.w - newW,0,newW,rect.h};
            SDL_Rect left = {camera.x % width,camera.y, camera.w - newW, camera.h};
            SDL_Rect leftDst = {0,0,rect.w-newW,rect.h};
            SDL_RenderCopy(rend,texture,&left,&leftDst);
            SDL_RenderCopy(rend,texture,&right,&rightDst);
        }else{
            SDL_RenderCopy(rend, texture, &camera, &rect);
        }
    }

    Background::~Background(){
        SDL_DestroyTexture(texture);
    }

}