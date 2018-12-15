//
// Created by Aron on 2018-12-14.
//

#ifndef CPROGLIB_PHYSICSOBJECT_H
#define CPROGLIB_PHYSICSOBJECT_H

#include "Entity.h"


namespace CPROGLib {
    class PhysicsObject {
    public:
        PhysicsObject(int gravity);
        virtual void applyPhysics(Entity& e);
        virtual ~PhysicsObject();
    private:
        int gravity;
    };
}


#endif //CPROGLIB_PHYSICSOBJECT_H
