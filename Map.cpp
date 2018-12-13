//
// Created by Aron on 2018-12-09.
//

#include <fstream>
#include <SDL_image.h>
#include "Map.h"
namespace CPROGLib{
    Map::Map(std::string& tileSetPath, int w, int h) {
        tileset = IMG_LoadTexture(window->getRenderer(), tileSetPath.c_str());
        width = w;
        height = h;

    }

    Tile* Map::isColliding(SDL_Rect &r) {
        for(auto tile : tiles){
            if(tile->isColliding(r)){
                return tile;
            }
        }
        return nullptr;
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

            if(cur < TILE_TYPES::GROUND+'0' || cur > TILE_TYPES::AIR+'0'){
                map.close();
                throw std::runtime_error("Error reading file.");//TODO:DO ERROR STUFF
            }else{
                typ = cur - '0';
            }

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

            TILE_TYPES t;
            t = static_cast<TILE_TYPES>(typ);
            Tile* tile = new Tile(dst,t,*tileset,src);
            tiles.push_back(tile);

        }


    }
}