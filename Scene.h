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
        Scene(Background* bg,Map* m,std::vector<Entity*> ent):bg(bg),map(m),entities(ent){}
    private:
        Background* bg;
        std::vector<Entity*> entities;
        Map* map;

    };
}


#endif //CPROGLIB_SCENE_H
