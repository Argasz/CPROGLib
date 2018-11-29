//
// Created by Aron on 2018-11-24.
//

#ifndef CPROGLIB_WINDOW_H
#define CPROGLIB_WINDOW_H

#include "SDL.h"
#include "string"
#include "Sprite.h"

class Window {
private:
    int width;
    int height;
    int posx;
    int posy;
    std::string title;
    SDL_Window* win;
    SDL_Renderer* rend;
public:
    Window(std::string& title, int w, int h, int posx, int posy);
    ~Window();
    void close();
    void render();
    void clear();
    SDL_Renderer* getRenderer();

};

#endif //CPROGLIB_WINDOW_H
