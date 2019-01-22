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
    public:
        static const int BOUNDING_BOX = 0, PER_PIXEL = 1;
        static SpriteEntity* getInstance(const std::string& imagePath, int x, int y, int w, int h, std::string& id, int collType = 0){
            return new SpriteEntity(imagePath,x,y,w,h,id,collType);
        }
        virtual void draw(SDL_Rect& camera);
        SDL_Rect& getRect() override;
        void listen(SDL_Event &ev) override;
        virtual void move(SDL_Rect& bounds);
        ~SpriteEntity() override;
        void addVel(int dx, int dy);
        void setXVel(int dx){
            xvel = dx;
        };
        void setYVel(int dy){
            yvel = dy;
        };
        bool isColliding(Collider& c) const;
        void collide(Entity& e){
            if(collideFunc) {
                collideFunc(*this, e);
            }
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
        void tick() override;
        std::string debugText() override;
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
        Collider* getCollider(){
            return c;
        }
        Sprite* getSprite(){
            return sprite;
        }
        SpriteEntity(const std::string& imagePath, int x, int y, int w, int h, std::string& id, int collType = 0);
        SpriteEntity(Sprite* sprite, int x, int y, int w, int h, std::string& id);
    private:
        Sprite* sprite;
        SDL_Rect rect;
        int xvel, yvel;
        int maxVel = 50;
        std::function<void(Entity& self, Entity& other)> collideFunc = nullptr;
        bool tracked = false;
        int collType;
        Collider* c;

    };
}

#endif //CPROGLIB_SPRITEENTITY_H
