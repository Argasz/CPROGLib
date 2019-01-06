//
// Created by Aron on 2019-01-04.
//

#ifndef CPROGLIB_COLLIDER_H
#define CPROGLIB_COLLIDER_H


#include <SDL_rect.h>

namespace CPROGLib {
    class Collider {
    public:
        Collider(int x, int y, int w, int h) {
            boundingBox = {x, y, w, h};
        };
        virtual bool isColliding(Collider& c);
        virtual SDL_Rect& getBoundingBox(){
            return boundingBox;
        };
        static bool collideRects(SDL_Rect& r1, SDL_Rect& r2){
            bool ycoll = (r1.x <= (r2.x + r2.w) && (r2.x <= (r1.x + r1.w)));
            bool xcoll = (r1.y <= (r2.y + r2.h) && (r2.y <= (r1.y + r1.h)));
            return ycoll && xcoll;
        };
        void setX(int x){
            boundingBox.x = x;
        };
        void setY(int y){
            boundingBox.y = y;
        }
    protected:
        SDL_Rect boundingBox;
    };
}


#endif //CPROGLIB_COLLIDER_H
