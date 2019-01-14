//
// Created by Aron on 2019-01-04.
//

#include "PerPixelCollider.h"
#include <typeinfo>

namespace CPROGLib {
    PerPixelCollider::PerPixelCollider(int x, int y,SDL_Surface &img) : Collider(x, y, img.w, img.h) {
        generateRects(img);
    }

    void PerPixelCollider::generateRects(SDL_Surface &img) { //TODO:Ta emot texture el.dyl.
        Uint32* pixels = static_cast<Uint32*>(img.pixels);
        Uint32 pixelCount = (img.h * (img.pitch / img.format->BytesPerPixel));
        SDL_LockSurface(&img);
        bool run = false;
        int x, y, w ,h;
        for(int i = 0; i <= pixelCount; i++){
            Uint32 tmp = pixels[i] & img.format->Amask;
            Uint8 alpha;
            tmp = tmp >> img.format->Ashift;
            tmp = tmp << img.format->Aloss;
            alpha = (Uint8)tmp;

            if(alpha != 0 && (i%img.w) != img.w){
                if(!run){
                    x = boundingBox.x + (i%img.w);
                    y = boundingBox.y + (i/img.w);
                    run = true;
                }
            }else{
                if(run){
                    w = boundingBox.x + (i%img.w) - x;
                    h = boundingBox.y + (i/img.w) - y;
                    h+=1;
                    SDL_Rect tmpr = {x, y, w, h};
                    rects.push_back(tmpr);
                    run = false;
                }
            }

        }
    }

    bool PerPixelCollider::isCollidingBounding(SDL_Rect &r) {
        return collideRects(r,this->boundingBox);
    }

    bool PerPixelCollider::isColliding(Collider &c) {
        if(collideRects(c.getBoundingBox(), boundingBox)){
            if(typeid(c) == typeid(Collider)){
                return true;
            }else if (typeid(c) == typeid(PerPixelCollider)){
                PerPixelCollider* ppc = dynamic_cast<PerPixelCollider*>(&c);
                for(SDL_Rect r : rects){
                    if(ppc->rectCollideWithRects(r).x > 0){
                        return true;
                    }
                }
            }
        }
        return false;
    };

    SDL_Rect PerPixelCollider::rectCollideWithRects(SDL_Rect &r){//TODO: Back to bool?
        for(SDL_Rect r1 : rects){
            if(collideRects(r, r1)){
                return r1;
            }
        }
        return {-1,0,0,0};
    };


    void PerPixelCollider::setX(int x){
        for(int i = 0; i < rects.size(); i++){
            rects[i].x +=  x - boundingBox.x;
        }

        boundingBox.x = x;
    }

    void PerPixelCollider::setY(int y){
        for(int i = 0; i < rects.size(); i++){
            rects[i].y +=  y - boundingBox.y;
        }
        boundingBox.y = y;

    }


}