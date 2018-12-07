//
// Created by Aron on 2018-12-06.
//

#ifndef CPROGLIB_SCENE_H
#define CPROGLIB_SCENE_H


#include "Entity.h"
#include "EventLoop.h"
#include <vector>

class Scene {
public:
    Scene(int w, int h, int startX, int startY, std::string& bgImgPath, Window* win);
    ~Scene();
    void addEntity(Entity& e);
private:
    std::vector<Entity*> entities;
    SDL_Rect sceneBox;
    SDL_Texture* bgImage;
    EventLoop eventLoop;
    Window* win;

};


#endif //CPROGLIB_SCENE_H
