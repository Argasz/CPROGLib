//
// Created by Aron on 2019-01-12.
//

#ifndef CPROGLIB_MAPCOLLISIONOBJ_H
#define CPROGLIB_MAPCOLLISIONOBJ_H


#include "Tile.h"

namespace CPROGLib {
    struct MapCollisionObj {
        Tile* tile;
        int region;
        SDL_Rect collidedRect;
    };
}


#endif //CPROGLIB_MAPCOLLISIONOBJ_H
