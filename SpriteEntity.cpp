//
// Created by Aron on 2018-11-29.
//

#include "SpriteEntity.h"

SpriteEntity::SpriteEntity(const std::string& imagePath, int x, int y, int w, int h) {
    sprite = new Sprite(imagePath);
    rect = {x, y, w, h};
}

void SpriteEntity::tick() {
    rect.x+=1;
}

SpriteEntity::~SpriteEntity() {
    delete sprite;
}