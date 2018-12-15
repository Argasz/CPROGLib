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
#include "DebugInfo.h"
#include "PhysicsObject.h"

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
        bool debug = false;
        DebugInfo* debugInfo;
        PhysicsObject* physicsObject;
    public:
        EventLoop(int fps, const std::string& bgImgPath, Map& map);
        ~EventLoop();
        void addEntity(Entity* e);
        void start();
        void stop();
        void attachCameraToEntity(Entity& ent);
        void addDebugInfo(DebugInfo& debugInfo){
            this->debugInfo = &debugInfo;
        };
        void addPhysicsObject(PhysicsObject& p){
            this->physicsObject = &p;
        };
        void toggleDebug() {
            debug = !debug;
        };
    };
}



#endif //CPROGLIB_EVENTLOOP_H
