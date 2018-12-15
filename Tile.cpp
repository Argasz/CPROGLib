//
// Created by Aron on 2018-12-09.
//

#include "Tile.h"

namespace CPROGLib{
    Tile::Tile(const SDL_Rect &dst, const TILE_TYPES t, SDL_Texture& tx, SDL_Rect &src) {
        rect = dst;
        clip = src;
        type = t;
        tex = &tx;
    }

    void Tile::draw(SDL_Rect &camera) {
        if(isColliding(camera)) {
            SDL_Rect adjustedPos = {rect.x - camera.x, rect.y - camera.y, rect.w, rect.h};
            SDL_RenderCopy(window->getRenderer(), tex, &clip, &adjustedPos);
        }
    }

    bool Tile::isColliding(SDL_Rect& r) {
        bool ycoll = (this->rect.x <= (r.x + r.w) && (r.x <= (this->rect.x + this->rect.w)));
        bool xcoll = (this->rect.y <= (r.y + r.h) && (r.y <= (this->rect.y + this->rect.h)));
        return ycoll && xcoll;
    }

    std::string Tile::debugText() {
        std::string ret;
        ret.append(std::to_string(type));
        ret.append("{");
        ret.append(" x: ");
        ret.append(std::to_string(this->rect.x));
        ret.append(" y: ");
        ret.append(std::to_string(this->rect.y));
        ret.append(" w: ");
        ret.append(std::to_string(this->rect.w));
        ret.append(" h: ");
        ret.append(std::to_string(this->rect.h));
        return ret;
    };

    void Tile::drawRect() {
        SDL_RenderDrawRect(window->getRenderer(), &rect);
    }
}