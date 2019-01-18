//
// Created by Aron on 2019-01-18.
//

#include "AnimatedSpriteEntity.h"
#include "AnimatedSprite.h"

namespace CPROGLib {
    AnimatedSpriteEntity::AnimatedSpriteEntity(const std::string &imagePath, int x, int y, int w, int h,
                                               std::string &id, CPROGLib::EventLoop &el, int freq, int frameWidth,int frameHeight, int rows, int cols) :
                                               SpriteEntity(AnimatedSprite::getInstance(imagePath,freq,frameWidth,frameHeight,rows,cols),x,y,w,h,id,el){
    }

    void AnimatedSpriteEntity::draw(SDL_Rect &camera) {
        auto r = this->getRect();
        if(Collider::collideRects(camera,r)){
            SDL_Rect adj = {r.x - camera.x, r.y - camera.y, r.w, r.h};
            AnimatedSprite* sp = dynamic_cast<AnimatedSprite*>(getSprite());
            sp->draw(adj);
        }
    }
}