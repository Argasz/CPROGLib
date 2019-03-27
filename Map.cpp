//
// Created by Aron on 2018-12-09.
//

#include <fstream>
#include <SDL_image.h>
#include "Map.h"

namespace CPROGLib{
    Map::Map(std::string& tileSetPath, int w, int h, int tileW, int tileH) {
        tileset = IMG_LoadTexture(window->getRenderer(), tileSetPath.c_str());
        width = w;
        height = h;
        this->tileH = tileH;
        this->tileW = tileW;
        bounds = {0,0,width*tileW,height*tileH};

    }
    //Collides ppc with tiles of a type
    // returns a MapCollisionObj representing the collided tiles and the corresponding rectangle from the collider as well as the "region" collided.
    MapCollisionObj Map::collidesWithTypePerPixel(PerPixelCollider& ppc, const int type) {
        MapCollisionObj m;
        for(auto tile : tiles){
            if(ppc.isCollidingBounding(tile->getRect())){
                auto r = ppc.rectCollideWithRects(tile->getRect());
                if(r.x >= 0 && tile->getType() == type){
                    m.tile = tile->getRect();
                    m.type = tile->getType();
                    m.collidedRect = r;
                    m.region = tile->collidesRegion(ppc.getBoundingBox());
                    return m;
                }
            }
        }
        m.tile = {-1,0,0,0};
        return m;
    }

    bool Map::collidesWithType(SDL_Rect &r, int type) {
        for(auto tile : tiles){
            if(tile->isColliding(r) && tile->getType() == type){
                return true;
            }
        }
        return false;
    }

    void Map::draw(SDL_Rect& camera) {
        for(auto t : tiles){
            t->draw(camera);
        }
    }

    Map::~Map(){
        for(auto t : tiles){
            delete t;
        }
        tiles.clear();
        SDL_DestroyTexture(tileset);
    }

    void Map::loadMap(std::string &path) {
        std::ifstream map(path);
        if(!map){
            throw std::runtime_error("Unable to load map file.");
        }

        int x, y,i = 0;

        while(!map.eof()){ //Space separated TYPE:OFFSETX:OFFSETY
            x = i%width;
            y = (i/width);

            int typ, offsetx, offsety;
            char cur;
            cur = map.get();
            typ = cur - '0';

            cur = map.get();
            if(cur != ':'){
                map.close();
                throw std::runtime_error("Error reading file. Expected :");
            }
            std::string offsetS;
            cur = map.get();
            while(cur >= '0' && cur <= '9'){
                offsetS.push_back(cur);
                cur = map.get();
            };

            offsetx = std::stoi(offsetS);

            if(cur != ':'){
                map.close();
                throw std::runtime_error("Error reading file. Expected :");
            }
            offsetS.clear();
            cur = map.get();
            while(cur >= '0' && cur <= '9'){
                offsetS.push_back(cur);
                cur = map.get();
            };
            offsety = std::stoi(offsetS);

            SDL_Rect dst = {x*tileW, y*tileH, tileW, tileH};
            SDL_Rect src = {offsetx*tileW, offsety*tileH, tileH, tileW};
            Tile* tile = new Tile(dst,typ,*tileset,src);
            tiles.push_back(tile);
            i++;

        }


    }

    std::string Map::debugText() {
        std::string ret;
        for(auto t : tiles){
            ret.append(t->debugText());
            ret.append("\n");
        }
        return ret;
    }

    void Map::drawRects(SDL_Rect& camera) {
        for(auto t : tiles){
            t->drawRect(camera);
        }
    }
}