//
// Created by Aron on 2018-12-09.
//

#ifndef CPROGLIB_MAP_H
#define CPROGLIB_MAP_H


#include "Tile.h"
#include <vector>
#include "Window.h"
namespace CPROGLib{
    class Map {
    public:
        Map(std::string& tileSetPath, int width, int height);
        void draw(SDL_Rect& camera);
        ~Map();
        void loadMap(std::string& path, int mapSize, int tileW, int tileH);
        Tile* isColliding(SDL_Rect& r);

    private:
        std::vector<Tile*> tiles;
        SDL_Texture* tileset;
        int width, height;

    };
}


#endif //CPROGLIB_MAP_H
