#ifndef CPROGLIB_LIBRARY_H
#define CPROGLIB_LIBRARY_H

#include "EventLoop.h"
#include "Sprite.h"
#include "Window.h"
#include "Entity.h"
#include "SpriteEntity.h"
#include "ControlledSpriteEntity.h"
#include "Map.h"
#include "Tile.h"
#include "PerPixelCollider.h"
#include "Background.h"
#include "AnimatedSprite.h"
#include "AnimatedSpriteEntity.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


namespace CPROGLib{
    void CPROG_init();
    void CPROG_quit();
}
#endif