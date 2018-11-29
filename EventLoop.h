//
// Created by Aron on 2018-11-23.
//


#ifndef CPROGLIB_EVENTLOOP_H
#define CPROGLIB_EVENTLOOP_H


#include <vector>
#include "Sprite.h"
#include "Entity.h"

class EventLoop {
private:
    SDL_Event event;
    int fps;
    std::vector<Entity*> entities;
    Window* win;
    bool running;

    int mainLoop();
    void tickEntities(){

    }
public:
    EventLoop(int fps, std::vector<Entity*> entities, Window* win);
    ~EventLoop();

    void start();
    void stop();
};




#endif //CPROGLIB_EVENTLOOP_H
