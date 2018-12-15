//
// Created by Aron on 2018-12-14.
//

#include "PhysicsObject.h"

namespace CPROGLib {
    PhysicsObject::PhysicsObject(int gravity) {
        this->gravity = gravity;
    }

    void PhysicsObject::applyPhysics(CPROGLib::Entity &e) {
        e.addVel(0,gravity);
    }

    PhysicsObject::~PhysicsObject() {
    }

}