//
// Created by Aron on 2018-12-09.
//

#include "Tile.h"


Tile::Tile(const SDL_Rect &dst, const TILE_TYPES t, SDL_Texture& tx, SDL_Rect &src) {
    rect = dst;
    clip = src;
    type = t;
    tex = &tx;
}

void Tile::draw(SDL_Rect &camera, SDL_Renderer* rend) {
    if(isColliding(camera)) {
        SDL_Rect adjustedPos = {rect.x - camera.x, rect.y - camera.y, rect.w, rect.h};
        SDL_RenderCopy(rend, tex, &clip, &adjustedPos);
    }
}

bool Tile::isColliding(SDL_Rect& r) {
    SDL_Rect other = r;
    bool ycoll = (this->rect.x <= (other.x + other.w) && (other.x <= (this->rect.x + this->rect.w)));
    bool xcoll = (this->rect.y <= (other.y + other.h) && (other.y <= (this->rect.y + this->rect.h)));
    return ycoll && xcoll;
}