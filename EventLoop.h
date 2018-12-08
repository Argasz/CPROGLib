//
// Created by Aron on 2018-11-23.
//


#ifndef CPROGLIB_EVENTLOOP_H
#define CPROGLIB_EVENTLOOP_H


#include <vector>
#include "Sprite.h"
#include "Entity.h"
#include "Window.h"
#include "Background.h"


class EventLoop {
private:
    SDL_Event event;
    int fps;
    std::vector<Entity*> entities;
    Window* win;
    bool running;
    int mainLoop();
    SDL_Rect camera;
    Background* bg;
public:
    EventLoop(int fps, Window* win, const std::string& bgImgPath);
    ~EventLoop();
    void addEntity(Entity* e);
    void start();
    void stop();
    void attachCameraToEntity(Entity& ent);
};




#endif //CPROGLIB_EVENTLOOP_H
