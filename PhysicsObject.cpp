//
// Created by Aron on 2018-12-14.
//

#include "PhysicsObject.h"

namespace CPROGLib {
    PhysicsObject::PhysicsObject(int gravity, int freq) {
        this->gravity = gravity;
        frameCount = freq;
        this->freq = freq;
        gravityOn = true;
    }

    void PhysicsObject::applyPhysics(SpriteEntity& e) {
        if(gravityOn){//TODO:Move to function
            if(frameCount == 0){
                frameCount = freq;
                e.addVel(0,gravity);
            }else{
                --frameCount;
            }
        }
    }

    PhysicsObject::~PhysicsObject() {
    }

}