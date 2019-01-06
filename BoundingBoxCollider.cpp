//
// Created by Aron on 2019-01-04.
//

#include "BoundingBoxCollider.h"

namespace CPROGLib {
    bool BoundingBoxCollider::isColliding(Collider& c) {
        bool ycoll = (this->getBoundingBox().x <= (c.getBoundingBox().x + c.getBoundingBox().w) && (c.getBoundingBox().x <= (this->getBoundingBox().x + this->getBoundingBox().w)));
        bool xcoll = (this->getBoundingBox().y <= (c.getBoundingBox().y + c.getBoundingBox().h) && (c.getBoundingBox().y <= (this->getBoundingBox().y + this->getBoundingBox().h)));
        return ycoll && xcoll;
    };


}