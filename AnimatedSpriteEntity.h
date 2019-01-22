//
// Created by Aron on 2019-01-18.
//

#ifndef CPROGLIB_ANIMATEDSPRITEENTITY_H
#define CPROGLIB_ANIMATEDSPRITEENTITY_H


#include "SpriteEntity.h"
#include "AnimatedSprite.h"

namespace CPROGLib {
    class AnimatedSpriteEntity : public SpriteEntity{
    public:
        static AnimatedSpriteEntity* getInstance(AnimatedSprite* as, int x, int y, int w, int h, std::string& id){
            return new AnimatedSpriteEntity(as,x,y,w,h,id);

        }
        void draw(SDL_Rect& camera) override;
        ~AnimatedSpriteEntity() override {
        };
    protected:
        AnimatedSpriteEntity(AnimatedSprite* as, int x, int y, int w, int h, std::string& id);



    };
}


#endif //CPROGLIB_ANIMATEDSPRITEENTITY_H
