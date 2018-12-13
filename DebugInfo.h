//
// Created by Aron on 2018-12-13.
//

#ifndef CPROGLIB_DEBUGINFO_H
#define CPROGLIB_DEBUGINFO_H


#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "Window.h"
namespace CPROGLib{
    class DebugInfo {
    public:
        DebugInfo(int x, int y, int w, int h, std::string& fontPath);
        ~DebugInfo();
        void addText(std::string& txt);
        void print();
        void clear();
    private:
        SDL_Rect rect;
        std::string text;
        TTF_Font* font;
        void drawArea();
    };

}


#endif //CPROGLIB_DEBUGINFO_H
