#include <utility>

#include <utility>

//
// Created by Aron on 2019-01-18.
//

#ifndef CPROGLIB_SCENE_H
#define CPROGLIB_SCENE_H


#include <vector>
#include "Background.h"
#include "Entity.h"
#include "Map.h"

namespace CPROGLib {
    class Scene {
        friend class EventLoop;
    public:
        Scene(Background* bg,Map* m,std::vector<Entity*>& ent,SDL_Rect& cam):bg(bg),map(m),entities(ent),cameraStart(cam){
            for(auto e : entities){
                startPos.push_back(e->getRect());
            }
        }
        void resetPos();
        Scene(const Scene&) = delete;
        Scene& operator=(const Scene&) = delete;
        ~Scene();
    private:
        Background* bg;
        std::vector<Entity*> entities;
        std::vector<SDL_Rect> startPos;
        Map* map;
        SDL_Rect cameraStart;
    };
}


#endif //CPROGLIB_SCENE_H
