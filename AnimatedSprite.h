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
        static AnimatedSprite* getInstance(const std::string& imagePath, int freq, int frameWidth,int frameHeight, int rows, int cols){
            return new AnimatedSprite(imagePath,freq,frameWidth,frameHeight,rows,cols);
        }
        void draw(const SDL_Rect& rect);
        ~AnimatedSprite();

    protected:
        AnimatedSprite(const std::string& imagePath, int freq, int frameWidth,int frameHeight, int rows, int cols);
    private:
        std::vector<SDL_Rect> srcRects;
        int freq,cur,rows, cols,frameW,frameH,frame;
    };

}


#endif //CPROGLIB_ANIMATEDSPRITE_H
