//
// Created by Aron on 2018-11-23.
//

#include "EventLoop.h"
#include "SDL.h"
#include "Entity.h"
#include "Window.h"


EventLoop::EventLoop(int fps, std::vector <Entity*> entities, Window* win){
    this->entities = entities;
    this->fps = fps;
    this->win = win;
    running = false;
}

EventLoop::~EventLoop() {
    for(auto e : entities){
        delete e;
    }
}

void EventLoop::start() {
    running = true;
    mainLoop();
}

void EventLoop::stop(){
    running = false;
}

int EventLoop::mainLoop() {
    const int tickInterval = 1000/fps;
    Uint32 nextTick;
    int delay;
    SDL_Event e;
    while(running){
        nextTick = SDL_GetTicks() + tickInterval;
        win->clear();
        for(auto e : entities){
            e->draw(win->getRenderer());
            e->tick();
        }

        win->render();
        delay = nextTick - SDL_GetTicks();
        if(delay > 0){
            SDL_Delay(delay);
        }
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT ) {
                stop();
            }
        }

    }

}