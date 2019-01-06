//
// Created by Aron on 2019-01-06.
//
#include "Collider.h"
namespace CPROGLib{
    bool Collider::isColliding(CPROGLib::Collider &c) {
        return collideRects(boundingBox,c.getBoundingBox());
    }
}
