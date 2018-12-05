//
// Created by Aron on 2018-11-29.
//

#include "SpriteEntity.h"

SpriteEntity::SpriteEntity(const std::string& imagePath, int x, int y, int w, int h) {
    sprite = new Sprite(imagePath);
    rect = {x, y, w, h};
}

void SpriteEntity::tick() {
    move(1 ,0 );
}

void SpriteEntity::move(int dx, int dy){
    rect.x += dx;
    rect.y += dy; //TODO: STUB
}

SpriteEntity::~SpriteEntity() {
    delete sprite;
}