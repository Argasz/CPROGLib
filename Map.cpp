//
// Created by Aron on 2018-12-09.
//

#include <fstream>
#include <SDL_image.h>
#include "Map.h"

Map::Map(std::string& tileSetPath, SDL_Renderer& rend, int w, int h) {
    SDL_Surface* temp = IMG_Load(tileSetPath.c_str());
    tileset = SDL_CreateTextureFromSurface(&rend, temp);
    SDL_FreeSurface(temp);
    width = w;
    height = h;

}

void Map::draw(SDL_Rect& camera, SDL_Renderer& rend) {
    for(auto t : tiles){
        t->draw(camera, &rend);
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

    for(int i = 0; i < mapSize; i++){ //Space separated TYPE:OFFSET pairs
        x = i%width;
        y = (i/width);

        int typ, offset;
        char cur;
        cur = map.get();

        if(cur < TILE_TYPES::GROUND+'0' || cur > TILE_TYPES::AIR+'0'){
            map.close();
            throw std::runtime_error("Error reading file.");//TODO:DO ERROR STUFF
        }else{
            typ = cur;
        }

        cur = map.get();
        if(cur != ':'){
            map.close();
            throw std::runtime_error("Error reading file.");//TODO:DO ERROR STUFF
        }
        std::string offsetS;
        cur = map.get();
        offsetS.push_back(cur);
        while(cur >= '0' && cur <= '9'){
            cur = map.get();
            offsetS.push_back(cur);
        }

        offset = std::stoi(offsetS);
        SDL_Rect dst = {x*tileW, y*tileH, tileW, tileH};
        SDL_Rect src = {offset*tileW, offset/tileW, tileH, tileW};

        Tile* tile = new Tile(dst,TILE_TYPES(typ),*tileset,src);
        tiles.push_back(tile);

    }


}