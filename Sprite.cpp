//
// Created by Aron on 2018-11-23.
//

#include <stdexcept>
#include "SDL_image.h"
#include "Sprite.h"
#include "Window.h"
#include "SDL.h"

Sprite::Sprite(const std::string& imagePath){
    surface = IMG_Load(imagePath.c_str());
    this->imagePath = imagePath;
    if(surface == nullptr){
        printf( "Unable to load image %s! SDL_image Error: %s\n", imagePath.c_str(), IMG_GetError() );
        throw std::runtime_error("Error loading image.");
    }
}

void Sprite::draw(SDL_Renderer* rend, const SDL_Rect rect) {
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_RenderCopy(rend, tex, nullptr, &rect);
    SDL_DestroyTexture(tex);
}

Sprite::~Sprite(){
    SDL_FreeSurface(surface);
}

