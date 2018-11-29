//
// Created by Aron on 2018-11-23.
//

#include "EventLoop.h"
#include "SDL.h"
#include "Entity.h"
#include "Window.h"


EventLoop::EventLoop(int fps, std::vector <Entity> entities, Window* win){
    this->entities = entities;
    this->fps = fps;
    this->win = win;
    running = false;
}

EventLoop::~EventLoop() {
    win = nullptr;
}

void EventLoop::start() {
    running = true;
    mainLoop();
}

int EventLoop::mainLoop() {
    while(running){
        win->clear();
        for(Entity e : entities){
            e.draw(win);
        }

        win->render();
    }

}