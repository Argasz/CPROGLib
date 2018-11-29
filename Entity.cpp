//
// Created by Aron on 2018-11-25.
//

#include "Entity.h"

Entity::Entity(Sprite* sprite, int posx, int posy) {
    this -> sprite = sprite;
    this -> posx = posx;
    this -> posy = posy;
}

void Entity::draw(Window *win) {
    sprite->draw(win, posx, posy);
}