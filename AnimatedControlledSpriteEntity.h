//
// Created by Aron on 2019-01-18.
//

#ifndef CPROGLIB_ANIMATEDCONTROLLEDSPRITEENTITY_H
#define CPROGLIB_ANIMATEDCONTROLLEDSPRITEENTITY_H


#include "ControlledSpriteEntity.h"

namespace CPROGLib {
    class AnimatedControlledSpriteEntity: public ControlledSpriteEntity {
    protected:
        AnimatedControlledSpriteEntity(const std::string& imagePath, int x, int y, int w, int h, std::string& id, EventLoop& el);

    };
}


#endif //CPROGLIB_ANIMATEDCONTROLLEDSPRITEENTITY_H
