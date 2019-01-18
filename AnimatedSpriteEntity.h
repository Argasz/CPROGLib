//
// Created by Aron on 2019-01-18.
//

#ifndef CPROGLIB_ANIMATEDSPRITEENTITY_H
#define CPROGLIB_ANIMATEDSPRITEENTITY_H


#include "SpriteEntity.h"

namespace CPROGLib {
    class AnimatedSpriteEntity : public SpriteEntity{
    public:
        static AnimatedSpriteEntity* getInstance(const std::string& imagePath, int x, int y, int w, int h, std::string& id, EventLoop& el,
                                                 int freq, int frameWidth,int frameHeight, int rows, int cols){
            return new AnimatedSpriteEntity(imagePath,x,y,w,h,id,el,freq,frameWidth,frameHeight,rows,cols);

        }
        void draw(SDL_Rect& camera) override;
        ~AnimatedSpriteEntity() override {};
    protected:
        AnimatedSpriteEntity(const std::string& imagePath, int x, int y, int w, int h, std::string& id, EventLoop& el,
                int freq, int frameWidth,int frameHeight, int rows, int cols);



    };
}


#endif //CPROGLIB_ANIMATEDSPRITEENTITY_H
