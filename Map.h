//
// Created by Aron on 2018-12-09.
//

#ifndef CPROGLIB_MAP_H
#define CPROGLIB_MAP_H


#include "Tile.h"
#include <vector>
#include "Window.h"
#include "PerPixelCollider.h"
#include "MapCollisionObj.h"

namespace CPROGLib{
    class Map {
    public:
        Map(std::string& tileSetPath, int width, int height, SDL_Rect& bounds);
        Map(std::string& tileSetPath, int width, int height, int tileW, int tileH);
        void draw(SDL_Rect& camera);
        ~Map();
        void loadMap(std::string& path);
        bool collidesWithType(SDL_Rect& r, int type);
        MapCollisionObj collidesWithTypePerPixel(PerPixelCollider& ppc, const int type);
        std::string debugText();
        void drawRects(SDL_Rect& camera);
        SDL_Rect& getBounds(){
            return bounds;
        }
        void setBounds(SDL_Rect& bounds){
            this->bounds = bounds;
        }
        int getW() const { return width * tileW;}
        int getH() const {return height * tileH;}
    private:
        std::vector<Tile*> tiles;
        SDL_Texture* tileset;
        int width, height;
        int tileW, tileH;
        SDL_Rect bounds;

    };
}


#endif //CPROGLIB_MAP_H
