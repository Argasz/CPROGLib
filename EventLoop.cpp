//
// Created by Aron on 2018-11-23.
//

#include "EventLoop.h"
#include "SDL.h"



EventLoop::EventLoop(int fps, Window* win, const std::string& bgImgPath){
    bg = new Background(bgImgPath);
    this->fps = fps;
    this->win = win;
    running = false;
    camera = {0, 0, win->getWidth(), win->getHeight()};
}


EventLoop::~EventLoop() {
    for(auto e : entities){
        delete e;
    }
}

void EventLoop::start() {
    running = true;
    mainLoop();
}

void EventLoop::stop(){
    running = false;
}
void EventLoop::addEntity(Entity *e) {
    entities.push_back(e); //TODO:Changes during iteration
}

void EventLoop::attachCameraToEntity(Entity &e) {
    e.trackWithCamera();
}


int EventLoop::mainLoop() {
    const int tickInterval = 1000/fps;
    Uint32 nextTick;
    int delay;
    SDL_Event ev;
    while(running){
        nextTick = SDL_GetTicks() + tickInterval;

        while( SDL_PollEvent( &ev ) != 0 )
        {
            if( ev.type == SDL_QUIT ) {
                stop();
            }

            for(auto e : entities){
                e->tick(ev);
            }
        }
        for(int i = 0; i < entities.size(); i++){
            if(entities[i]->isTracked()){
                SDL_Rect er = entities[i]->getRect();
                camera.x = er.x - (win->getWidth()/2); //TODO: top corner thing
                camera.y = er.y - (win->getHeight()/2);
                if(camera.x > (bg->getWidth()-camera.w)){
                    camera.x = bg->getWidth()-camera.w;
                }
                if(camera.y > (bg->getHeight() - camera.h)){
                    camera.y = bg->getHeight() - camera.h;
                }
                if(camera.x < 0){
                    camera.x = 0;
                }
                if(camera.y < 0){
                    camera.y = 0;
                }
            }
            for(int k = i+1; k < entities.size();k++){
                if(entities[i]->isColliding(*entities[k])){
                    entities[i]->collide(*entities[k]);
                    entities[k]->collide(*entities[i]);
                }
            }
        }
        win->clear();

        bg->draw(camera, *win);

        for(auto e: entities){
            SDL_Rect bounds = {0, 0, bg->getWidth(), bg->getHeight()};
            e->move(bounds);
            e->draw(win->getRenderer(), camera);
        }

        win->render();
        delay = nextTick - SDL_GetTicks();
        if(delay > 0){
            SDL_Delay(delay);
        }


    }

}