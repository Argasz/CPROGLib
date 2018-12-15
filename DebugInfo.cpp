//
// Created by Aron on 2018-12-13.
//

#include <stdexcept>
#include "DebugInfo.h"

namespace CPROGLib{
    DebugInfo::DebugInfo(int x, int y, int w, int h, std::string& fontPath) {
        font = TTF_OpenFont(fontPath.c_str(), 14);
        if(font == nullptr){
            printf( "Unable to load font %s! SDL_TTF Error: %s\n", fontPath.c_str(), TTF_GetError() );
            throw std::runtime_error("Error loading font.");
        };
        rect = {x, y, w, h};
        text = "";
        print();
        drawArea();
    }

    void DebugInfo::print() {
        SDL_Color c;
        c = {0,0,0,255};
        int txtw;
        TTF_SizeText(font,text.c_str(),&txtw,NULL);
        SDL_Surface* tmp = TTF_RenderText_Blended_Wrapped(font, text.c_str(), c, txtw);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(window->getRenderer(),tmp);
        SDL_FreeSurface(tmp);
        drawArea();
        int w, h;
        SDL_QueryTexture(texture,NULL,NULL,&w, &h);
        SDL_Rect dst = {rect.x, rect.y, w, h};
        rect.w = w;
        rect.h = h;
        SDL_RenderCopy(window->getRenderer(),texture,NULL,&dst);
        SDL_DestroyTexture(texture);
        clear();
    }

    void DebugInfo::drawArea() {
        SDL_SetRenderDrawColor(window->getRenderer(),255,0,0,100);
        SDL_SetRenderDrawBlendMode(window->getRenderer(), SDL_BLENDMODE_BLEND);
        SDL_RenderFillRect(window->getRenderer(), &rect);
        SDL_SetRenderDrawColor(window->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF );
    }

    void DebugInfo::addText(std::string &txt) {
        text.append(txt);
    }

    void DebugInfo::clear() {
        text = "";
    }
    DebugInfo::~DebugInfo() {
        TTF_CloseFont(font);

    }

}