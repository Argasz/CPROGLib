//
// Created by Aron on 2018-11-23.
//

#include "EventLoop.h"

namespace CPROGLib{
    EventLoop::EventLoop(int fps, const std::string& bgImgPath, Map& m){
        bg = new Background(bgImgPath);
        this->fps = fps;
        running = false;
        camera = {0, 0, window->getWidth(), window->getHeight()};
        map = &m;
    }


    EventLoop::~EventLoop() {
        for(auto e : entities){
            delete e;
        }
        entities.clear();
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

    void EventLoop::adjustCamera(Entity &e) {
        SDL_Rect er = e.getRect();
        camera.x = er.x + (er.w/2) - (window->getWidth()/2);
        camera.y = er.y + (er.h/2) - (window->getHeight()/2);
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
                if(debug){

                }
                if(entities[i]->isTracked()){
                    adjustCamera(*entities[i]);
                }
                Tile* t = map->isColliding(entities[i]->getRect());
                if(t != nullptr && t->getType() == GROUND){
                    entities[i]->setYVel(0);
                }
                for(int k = i+1; k < entities.size();k++){
                    if(entities[i]->isColliding(entities[k]->getRect())){
                        entities[i]->collide(*entities[k]);
                        entities[k]->collide(*entities[i]);
                    }
                }
            }
            window->clear();

            bg->draw(camera);
            map->draw(camera);

            for(auto e: entities){
                SDL_Rect bounds = {0, 0, bg->getWidth(), bg->getHeight()};//TODO: LevelBounds
                e->move(bounds);
                e->draw(camera);
            }

            window->render();
            delay = nextTick - SDL_GetTicks();
            if(delay > 0){
                SDL_Delay(delay);
            }


        }

    }
}