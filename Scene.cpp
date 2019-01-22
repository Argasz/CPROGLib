//
// Created by Aron on 2019-01-18.
//

#include "Scene.h"
#include "SpriteEntity.h"

namespace CPROGLib {
    Scene::~Scene() {
        for( auto e : entities){
            delete e;
        }
        delete bg;
        delete map;
    }

    void Scene::resetPos() {
        for(int i = 0; i < entities.size();i++){
            auto e = entities[i];
            if(auto se = dynamic_cast<SpriteEntity*>(e)){
                se->setX(startPos[i].x);
                se->setY(startPos[i].y);
            }
        }
    }
}