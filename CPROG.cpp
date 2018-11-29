#include "CPROG.h"
#include "SDL.h"
#include <iostream>

void CPROG_init(){
    int flags = SDL_Init(SDL_INIT_EVERYTHING);
    if(flags < 0 ){
        printf("SDL error: %s", SDL_GetError());
        throw std::runtime_error("SDL initialization error");
    }
}

void CPROG_quit(){
    SDL_Quit();
}