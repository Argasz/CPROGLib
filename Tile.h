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
    enum TILE_TYPES {
        GROUND = 0,
        WALL,
        AIR
    };

    class Tile {
    public:
        Tile(const SDL_Rect& dst, const TILE_TYPES t,SDL_Texture& tx, SDL_Rect &src);
        ~Tile(){
            SDL_DestroyTexture(tex);
        };
        TILE_TYPES getType()const {
            return type;
        };
        void draw(SDL_Rect& camera);
        bool isColliding(SDL_Rect& r);
    private:
        TILE_TYPES type;
        SDL_Rect rect;
        SDL_Rect clip;
        SDL_Texture* tex;

    };
}


#endif //CPROGLIB_TILE_H
