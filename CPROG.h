#ifndef CPROGLIB_LIBRARY_H
#define CPROGLIB_LIBRARY_H

#include "EventLoop.h"
#include "Sprite.h"
#include "Window.h"
#include "Entity.h"
#include "SpriteEntity.h"
#include "ControlledSpriteEntity.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>



void CPROG_init();
void CPROG_quit();

#endif