//
// Created by Aron on 2018-12-09.
//

#include <fstream>
#include <SDL_image.h>
#include "Map.h"
namespace CPROGLib{
    Map::Map(std::string& tileSetPath, int w, int h, SDL_Rect& bounds) {
        tileset = IMG_LoadTexture(window->getRenderer(), tileSetPath.c_str());
        width = w;
        height = h;
        this->bounds = bounds;

    }

    Map::Map(std::string& tileSetPath, int w, int h) {
        tileset = IMG_LoadTexture(window->getRenderer(), tileSetPath.c_str());
        width = w;
        height = h;

    }

    bool Map::collidesWithType(SDL_Rect &r, int type) {
        for(auto tile : tiles){
            if(tile->isColliding(r) && tile->getType() == type){
                return true;
            }
        }
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
        SDL_DestroyTexture(tileset);
    }

    void Map::loadMap(std::string &path, int mapSize, int tileW, int tileH) {//TODO: DEBUG
        bounds = {0,0,width*tileW,height*tileH};
        std::ifstream map(path);
        if(!map){
            throw std::runtime_error("Unable to load map file.");
        }

        int x, y = 0;

        for(int i = 0; i < mapSize; i++){ //Space separated TYPE:OFFSETX:OFFSETY
            x = i%width;
            y = (i/width);

            int typ, offsetx, offsety;
            char cur;
            cur = map.get();
            typ = cur - '0';

            cur = map.get();
            if(cur != ':'){
                map.close();
                throw std::runtime_error("Error reading file.");//TODO:DO ERROR STUFF
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
                throw std::runtime_error("Error reading file.");//TODO:DO ERROR STUFF
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

    void Map::drawRects() {
        for(auto t : tiles){
            t->drawRect();
        }
    }
}