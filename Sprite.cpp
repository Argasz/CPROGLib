//
// Created by Aron on 2018-11-23.
//

#include "SDL_image.h"
#include "Sprite.h"
#include "Window.h"
#include "SDL.h"

Sprite::Sprite(std::string& imagePath){
    surface = IMG_Load(imagePath.c_str());
    this->imagePath = imagePath;
    if(surface == NULL){
        printf( "Unable to load image %s! SDL_image Error: %s\n", imagePath.c_str(), IMG_GetError() );
    }
}

void Sprite::draw(Window* win, int x, int y) {
    SDL_Texture* tex = SDL_CreateTextureFromSurface(win->rend, surface);
    SDL_RenderCopy(win->rend, tex, NULL, NULL);
}
