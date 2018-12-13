//
// Created by Aron on 2018-11-29.
//

#ifndef CPROGLIB_SPRITEENTITY_H
#define CPROGLIB_SPRITEENTITY_H


#include <functional>
#include "Entity.h"
#include "Sprite.h"
namespace CPROGLib{
    class SpriteEntity : public Entity{
    private:
        Sprite* sprite;
        SDL_Rect rect;
        int xvel, yvel;
        int maxVel = 50;
        std::function<void(Entity& self, Entity& other)> collideFunc = {};
        bool tracked = false;
    public:
        SpriteEntity(const std::string& imagePath, int x, int y, int w, int h, std::string& id);
        void draw(SDL_Rect& camera) override {
            if(isColliding(camera)){
                SDL_Rect adj = {rect.x - camera.x, rect.y - camera.y, rect.w, rect.h};
                sprite->draw(adj);
            }
        };
        SDL_Rect& getRect() override;
        void tick(SDL_Event& ev) override;
        void move(SDL_Rect& bounds) override;
        ~SpriteEntity() override;
        void addVel(int dx, int dy) override;
        void setXVel(int dx){
            xvel = dx;
        };
        void setYVel(int dy){
            yvel = dy;
        };
        bool isColliding(SDL_Rect& r) const override;
        void collide(Entity& e) override{
            collideFunc(*this, e);
        }
        void setMaxVel(int vel){
            maxVel = vel;
        }
        int getMaxVel(){
            return maxVel;
        }
        void setCollideFunc(std::function<void(Entity&, Entity&)> f) override;

        void trackWithCamera() override{tracked = true;}
        void untrack() override {tracked = false;}
        bool isTracked() override {return tracked;}

    };
}

#endif //CPROGLIB_SPRITEENTITY_H
