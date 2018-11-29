//
// Created by Aron on 2018-11-24.
//

#include <iostream>
#include "Window.h"
#include "SDL.h"

Window::Window(std::string& title, int w, int h, int posx, int posy){
    this->width = w;
    this->height = h;
    this->posx = posx;
    this->posy = posy;
    this->title = title;

    this->win = SDL_CreateWindow(title.c_str(),posx,posy,w,h,SDL_WINDOW_SHOWN);
    if(win == NULL){
        printf("Could not create window, SDL Error:%s", SDL_GetError());
    }
    this->rend = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);

    if(rend == NULL) {
        printf( "Could not create renderer, SDL Error: %s\n", SDL_GetError() );
    }

    SDL_SetRenderDrawColor( rend, 0xFF, 0xFF, 0xFF, 0xFF );
}

//TODO: Drawcolor

Window::~Window(){
    close();
}

void Window::close(){
    SDL_DestroyWindow(win);
    win = nullptr;
}

void Window::render(){
    SDL_RenderPresent(rend);
}

void Window::clear() {
    SDL_RenderClear(rend);
}
