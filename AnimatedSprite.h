//
// Created by Aron on 2019-01-11.
//

#ifndef CPROGLIB_ANIMATEDSPRITE_H
#define CPROGLIB_ANIMATEDSPRITE_H


#include <SDL_render.h>
#include <vector>
#include "Sprite.h"

namespace CPROGLib {
    class AnimatedSprite : public Sprite{
    public:
        AnimatedSprite(const std::string& imagePath, int freq, int frameWidth,int frameHeight, int rows, int cols);
        void draw(const SDL_Rect& rect);
        ~AnimatedSprite();
    private:
        std::vector<SDL_Rect> srcRects;
        int freq,cur,rows, cols,frameW,frameH;
    };

}


#endif //CPROGLIB_ANIMATEDSPRITE_H
