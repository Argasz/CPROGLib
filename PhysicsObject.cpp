//
// Created by Aron on 2018-12-14.
//

#include "PhysicsObject.h"

namespace CPROGLib {
    PhysicsObject::PhysicsObject(int gravity, int freq) {
        this->gravity = gravity;
        frameCount = 0;
        this->freq = freq;
    }

    void PhysicsObject::applyPhysics(SpriteEntity& e) {
        if(frameCount == 0){
            frameCount = freq;
            e.addVel(0,gravity);
        }
        --frameCount;

    }

    PhysicsObject::~PhysicsObject() {
    }

}