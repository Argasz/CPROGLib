//
// Created by Aron on 2018-11-23.
//


#ifndef CPROGLIB_EVENTLOOP_H
#define CPROGLIB_EVENTLOOP_H


#include <vector>
#include <SDL.h>
#include "Sprite.h"
#include "Entity.h"
#include "Window.h"
#include "Background.h"
#include "Map.h"

namespace CPROGLib{
    class EventLoop {
    private:
        SDL_Event event;
        int fps;
        std::vector<Entity*> entities;
        bool running;
        int mainLoop();
        SDL_Rect camera;
        Background* bg;
        void adjustCamera(Entity& e);
        Map* map;
        bool debug;
    public:
        EventLoop(int fps, const std::string& bgImgPath, Map& map);
        ~EventLoop();
        void addEntity(Entity* e);
        void start();
        void stop();
        void attachCameraToEntity(Entity& ent);
    };
}



#endif //CPROGLIB_EVENTLOOP_H
