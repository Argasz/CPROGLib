//
// Created by Aron on 2018-12-09.
//

#ifndef CPROGLIB_TILE_H
#define CPROGLIB_TILE_H

#include <SDL.h>
#include <string>
#include "Entity.h"
#include "Window.h"
namespace CPROGLib{
    class Tile {
    public:
        static const int NONE = 0, NW = 1, N = 2, NE = 3, E = 4, SE = 5, S = 6, SW = 7, W = 8;
        Tile(const SDL_Rect& dst, const int t,SDL_Texture& tx, SDL_Rect &src);
        ~Tile(){
            SDL_DestroyTexture(tex);
        };
        int getType()const {
            return type;
        };
        void draw(SDL_Rect& camera);
        bool isColliding(SDL_Rect& r);
        std::string debugText();
        void drawRect(SDL_Rect& camera);
        SDL_Rect& getRect(){
            return rect;
        }
        int collidesRegion(SDL_Rect& boundingBox);
    private:
        int type;
        SDL_Rect rect, top,btm,l,r, clip;
        SDL_Texture* tex;

    };
}


#endif //CPROGLIB_TILE_H
