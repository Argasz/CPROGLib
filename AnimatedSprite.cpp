//
// Created by Aron on 2019-01-11.
//

#include "AnimatedSprite.h"

namespace CPROGLib {
    AnimatedSprite::AnimatedSprite(const std::string &imagePath, int freq, int frameWidth, int frameHeight, int rows, int cols) : Sprite(imagePath){
        this->freq = freq;
        this->cur = 0;
        this->cols = cols;
        this->rows = rows;
        this->frameW = frameWidth;
        this->frameH = frameHeight;
        this->frame = 0;
        for(int c = 0; c < cols; c++){
            for(int r = 0; r < rows; r++){
                srcRects.push_back({c*frameW,r*frameH,frameW, frameH});
            }
        }


    }
    void AnimatedSprite::draw(const SDL_Rect& rect) {
        if(cur == 0){
            SDL_RenderCopy(window->getRenderer(), getTexture(), &srcRects[frame], &rect);
            frame++;
            if(frame >= srcRects.size()){
                frame = 0;
            }
            cur = freq;
        }
        cur--;

    }
}