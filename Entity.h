//
// Created by Aron on 2018-11-25.
//

#ifndef CPROGLIB_ENTITY_H
#define CPROGLIB_ENTITY_H


#include <vector>
#include "Sprite.h"

class Entity {
private:
    int posx;
    int posy;
    Sprite* sprite;
    std::vector<Entity> entities;
public:
    Entity(Sprite* sprite, int posx, int posy);
    void tick();
    void draw(Window* win);
};


#endif //CPROGLIB_ENTITY_H
