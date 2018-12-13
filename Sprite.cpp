//
// Created by Aron on 2018-11-23.
//

#include <stdexcept>

#include "Sprite.h"
namespace CPROGLib{
    Sprite::Sprite(const std::string& imagePath){
        texture = IMG_LoadTexture(window->getRenderer(), imagePath.c_str());
        this->imagePath = imagePath;
        if(texture == nullptr){
            printf( "Unable to load image %s! SDL_image Error: %s\n", imagePath.c_str(), IMG_GetError() );
            throw std::runtime_error("Error loading image.");
        }
    }

    void Sprite::draw(const SDL_Rect& rect) {
        SDL_RenderCopy(window->getRenderer(), texture, nullptr, &rect);
    }

    Sprite::~Sprite(){
        SDL_DestroyTexture(texture);
    }
}
