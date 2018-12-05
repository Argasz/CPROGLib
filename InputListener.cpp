//
// Created by Aron on 2018-12-05.
//

#include "InputListener.h"

InputListener::InputListener(Entity* e) {
    this->entity = e;
}

InputListener::~InputListener() {
    entity = nullptr;
}