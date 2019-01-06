//
// Created by Aron on 2018-11-29.
//

#ifndef CPROGLIB_SPRITEENTITY_H
#define CPROGLIB_SPRITEENTITY_H


#include <functional>
#include "Entity.h"
#include "Sprite.h"
#include "Collider.h"

namespace CPROGLib{
    class SpriteEntity : public Entity{
    private:
        Sprite* sprite;
        SDL_Rect rect;
        int xvel, yvel;
        int maxVel = 50;
        std::function<void(Entity& self, Entity& other)> collideFunc = {};
        bool tracked = false;
        int collType;
    public:
        SpriteEntity(const std::string& imagePath, int x, int y, int w, int h, std::string& id, EventLoop& el, int collType); //TODO: Constants
        void draw(SDL_Rect& camera) override;
        SDL_Rect& getRect() override;
        void listen(SDL_Event &ev) override;
        void move(SDL_Rect& bounds) override;
        ~SpriteEntity() override;
        void addVel(int dx, int dy) override;
        void setXVel(int dx){
            xvel = dx;
        };
        void setYVel(int dy){
            yvel = dy;
        };
        bool isColliding(Collider& c) const override;
        void collide(Entity& e) override{
            collideFunc(*this, e);
        }
        void setMaxVel(int vel){
            maxVel = vel;
        }
        int getMaxVel(){
            return maxVel;
        }
        virtual void setCollideFunc(std::function<void(Entity&, Entity&)> f);
        void trackWithCamera() override{tracked = true;}
        void untrack() override {tracked = false;}
        bool isTracked() override {return tracked;}
        virtual void tick();
        std::string debugText();
        int getXVel(){
            return xvel;
        }
        int getYVel(){
            return yvel;
        }
        void setY(int y){
            rect.y = y;
        }
        void setX(int x){ //TODO: Check bounds?
            rect.x = x;
        }
        int getCollType(){
            return collType;
        }

    protected:
        Collider* c;

    };
}

#endif //CPROGLIB_SPRITEENTITY_H
