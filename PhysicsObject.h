//
// Created by Aron on 2018-12-14.
//

#ifndef CPROGLIB_PHYSICSOBJECT_H
#define CPROGLIB_PHYSICSOBJECT_H

#include "SpriteEntity.h"


namespace CPROGLib {
    class PhysicsObject {
    public:
        PhysicsObject(int gravity, int frameCount);
        virtual void applyPhysics(SpriteEntity& e,bool grav);
        virtual ~PhysicsObject();
        void setGravityOn(bool onOff){
            gravityOn = onOff;
        };
        void reset(){
            frameCount = freq;
        }
        void dec(){
            if(frameCount > 0){
                frameCount--;
            }else{
                reset();
            }
        };
        std::string gfc(){
            return std::to_string(frameCount);
        }
    private:
        int gravity;
        int frameCount;
        int freq;
        bool gravityOn;
    };
}


#endif //CPROGLIB_PHYSICSOBJECT_H
