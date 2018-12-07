//
// Created by Aron on 2018-11-23.
//

#include "EventLoop.h"
#include "SDL.h"



EventLoop::EventLoop(int fps, Window* win){
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
void EventLoop::addEntity(Entity *e) {
    entities.push_back(e); //TODO:Changes during iteration
}

int EventLoop::mainLoop() {
    const int tickInterval = 1000/fps;
    Uint32 nextTick;
    int delay;
    SDL_Event ev;
    while(running){
        nextTick = SDL_GetTicks() + tickInterval;

        while( SDL_PollEvent( &ev ) != 0 )
        {
            if( ev.type == SDL_QUIT ) {
                stop();
            }
            for(auto e : entities){
                e->tick(ev);
            }
        }
        win->clear();
        for(auto e: entities){
            e->move();
            e->draw(win->getRenderer());
        }

        win->render();
        delay = nextTick - SDL_GetTicks();
        if(delay > 0){
            SDL_Delay(delay);
        }


    }

}