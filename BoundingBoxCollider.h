//
// Created by Aron on 2019-01-04.
//

#ifndef CPROGLIB_BOUNDINGBOXCOLLIDER_H
#define CPROGLIB_BOUNDINGBOXCOLLIDER_H


#include "Collider.h"

namespace CPROGLib {
    class BoundingBoxCollider : public Collider{
    public:
        BoundingBoxCollider(int x,int y, int w,int h): Collider(x, y, w, h){};
        virtual bool isColliding(Collider& c);
        ~BoundingBoxCollider();
    };


}


#endif //CPROGLIB_BOUNDINGBOXCOLLIDER_H
