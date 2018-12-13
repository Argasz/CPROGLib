//
// Created by Aron on 2018-11-24.
//

#ifndef CPROGLIB_WINDOW_H
#define CPROGLIB_WINDOW_H

#include "SDL.h"
#include "string"
#include "Sprite.h"
namespace CPROGLib{
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
        static void createWindow(std::string& title, int w, int h, int posx, int posy);
        ~Window();
        void close();
        void render();
        void clear();
        int getHeight(){
            return height;
        }
        int getWidth(){
            return width;
        }
        SDL_Renderer* getRenderer();
    protected:
        Window(std::string& title, int w, int h, int posx, int posy);

    };

    extern Window* window;
}


#endif //CPROGLIB_WINDOW_H
