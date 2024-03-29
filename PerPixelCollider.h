//
// Created by Aron on 2019-01-04.
//

#ifndef CPROGLIB_PERPIXELCOLLIDER_H
#define CPROGLIB_PERPIXELCOLLIDER_H


#include <string>
#include <SDL_surface.h>
#include <vector>
#include "Collider.h"

namespace CPROGLib {
    class PerPixelCollider : public Collider{
    public:
        PerPixelCollider(int x, int y, SDL_Surface& img);
        ~PerPixelCollider() = default;
        virtual bool isColliding(Collider& c); //TODO: TEMP
        virtual bool isCollidingBounding(SDL_Rect& r);
        SDL_Rect rectCollideWithRects(SDL_Rect &r);
        void setX(int x) override;
        void setY(int y) override;
    private:
        std::vector<SDL_Rect> rects;
        void generateRects(SDL_Surface& img);
    };
}


#endif //CPROGLIB_PERPIXELCOLLIDER_H
