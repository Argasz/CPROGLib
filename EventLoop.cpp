//
// Created by Aron on 2018-11-23.
//

#include "EventLoop.h"

namespace CPROGLib{
    EventLoop::EventLoop(int fps, const std::string& bgImgPath, Map* m){
        bg = new Background(bgImgPath);
        this->fps = fps;
        running = false;
        camera = {0, 0, window->getWidth(), window->getHeight()};
        map = m;
        physicsObject = nullptr;
        currentScene = nullptr;
        debug = false;
    }
    EventLoop::EventLoop(int fps, Scene* s) {
        loadScene(s);
        this->fps = fps;
        running = false;
        camera = {0, 0, window->getWidth(), window->getHeight()};
        physicsObject = nullptr;
        debug = false;
    }

    void EventLoop::loadScene(CPROGLib::Scene *s) {
        camera = s->cameraStart;
        map = s->map;
        bg = s->bg;
        if(currentScene){
            for(auto e: currentScene->entities){
                removeEntity(e);
                clearRemoved();
            }
        }
        currentScene = s;
        for(auto e : currentScene->entities){
            addEntity(e);
            e->setEventLoop(this);
        }
        s->resetPos();
    }

    void EventLoop::clearEntities() {
        for(Entity* e : entities){
            removeEntity(e);
        }
    }

    void EventLoop::readKeyCommands(SDL_Event& ev) {
        for(auto c : commands){
            c->perform(ev);
        }
    }


    EventLoop::~EventLoop() {
        for(auto e : entities){
            delete e;
        }
        delete bg;
        delete map;
    }

    void EventLoop::start() {
        running = true;
        mainLoop();
    }

    void EventLoop::stop(){
        running = false;
        SDL_Quit();
        IMG_Quit();
        TTF_Quit();
    }
    void EventLoop::addEntity(Entity *e) {
        added.push_back(e);
        e->setEventLoop(this);
    }

    void EventLoop::attachCameraToEntity(Entity &e) {
        e.trackWithCamera();
    }

    void EventLoop::adjustCamera(Entity &e) {
        SDL_Rect er = e.getRect();
        camera.x = er.x + (er.w/2) - (window->getWidth()/2);
        camera.y = er.y + (er.h/2) - (window->getHeight()/2);
        if(camera.x + camera.w > (map->getW())){
            camera.x = map->getW() - camera.w;
        }
        if(camera.y + camera.h > (map->getH())){
            camera.y = map->getH() - camera.h;
        }
        if(camera.x < 0){
            camera.x = 0;
        }
        if(camera.y < 0){
            camera.y = 0;
        }
    }

    void EventLoop::removeEntity(Entity* e) {
        removed.push_back(e);
    }



    void EventLoop::clearRemoved() {
        for (Entity *e : removed) {
            for (auto i = entities.begin(); i != entities.end();)
                if (*i == e) {
                    i = entities.erase(i);
                    if(!currentScene->hasEntity(e)) {
                        delete e;
                    }
                } else {
                    i++;
                }
            removed.clear();
        }
    }

    void EventLoop::addAdded() {
        for(Entity* e : added) {
            entities.push_back(e);
        }
        added.clear();
    }


    int EventLoop::mainLoop() {
        const int tickInterval = 1000/fps;
        Uint32 nextTick;
        int delay;
        SDL_Event ev;
        while(running) {
            if (!paused) {
                addAdded();
                clearRemoved();

                nextTick = SDL_GetTicks() + tickInterval;

                while (SDL_PollEvent(&ev) != 0) {
                    if (ev.type == SDL_QUIT) {
                        stop();
                    }
                    readKeyCommands(ev);
                    for (auto e : entities) {
                        e->listen(ev);
                    }
                    /*
                    if (currentScene) {
                        for (auto e : currentScene->entities) {
                            e->listen(ev);
                        }
                    }*/

                }

                for (int i = 0; i < entities.size(); i++) {
                    if (debug) {
                        std::string tmp = entities[i]->debugText();
                        debugInfo->addText(tmp);
                        auto s = physicsObject->gfc();
                        debugInfo->addText(s);
                    }
                    if (entities[i]->isTracked()) {
                        adjustCamera(*entities[i]);
                    }
                }


                window->clear();
                bg->draw(camera);
                map->draw(camera);
                if (debug) {
                    map->drawRects(camera);
                }


                for (auto e: entities) {
                    e->tick();
                    if (debug) {
                        SDL_Rect r = {e->getRect().x - camera.x, e->getRect().y - camera.y, e->getRect().w,
                                      e->getRect().h};
                        SDL_RenderDrawRect(window->getRenderer(), &r);
                    }
                }
                physicsObject->dec();

                if (debug) {
                    debugInfo->print();
                }

                window->render();
                delay = nextTick - SDL_GetTicks();
                if (delay > 0) {
                    SDL_Delay(delay);
                }


            }else{
                while (SDL_PollEvent(&ev) != 0) {
                    if (ev.type == SDL_QUIT) {
                        stop();
                    }
                }
            }
        }

    }
}