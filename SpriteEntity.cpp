//
// Created by Aron on 2018-11-29.
//

#include "SpriteEntity.h"
#include "EventLoop.h"
#include "PerPixelCollider.h"
#include <typeinfo>
namespace CPROGLib{
    SpriteEntity::SpriteEntity(const std::string& imagePath, int x, int y, int w, int h, std::string& id, EventLoop& el, int collType) : Entity(el,id) {
        sprite = new Sprite(imagePath);
        rect = {x, y, w, h};
        xvel = 0;
        yvel = 0;
        this->collType = collType;
        if(collType == 0){
            c = new Collider(x,y,w,h);//TODO: Collider type
        }else if(collType == 1){
            SDL_Surface* tmp = IMG_Load(imagePath.c_str());
            c =  new PerPixelCollider(x,y,*tmp);
            SDL_FreeSurface(tmp);
        }
    }

    void SpriteEntity::listen(SDL_Event &ev) {
    }


    void SpriteEntity::addVel(int dx, int dy) {
        this->xvel += dx;
        this->yvel += dy;

        if(xvel >= maxVel){
            xvel = maxVel;
        }
        if(xvel <= -maxVel){
            xvel = -maxVel;
        }
        if(yvel >= maxVel){
            yvel = maxVel;
        }
        if(yvel <= -maxVel){
            yvel = -maxVel;
        }
    }

    void SpriteEntity::move(SDL_Rect& bounds){
        rect.x += xvel;
        rect.y += yvel;

        if( ( rect.x < 0 ) || ( rect.x > bounds.w) ) {
            rect.x -= xvel;
        }
        if( ( rect.y < 0 ) || ( rect.y > bounds.h) ) {
            rect.y -= yvel;
        }
        c->setX(rect.x);
        c->setY(rect.y);
    }

    SDL_Rect& SpriteEntity::getRect(){
        return rect;
    }

    bool SpriteEntity::isColliding(Collider& other) const{
        return c->isColliding(other);
    }


    SpriteEntity::~SpriteEntity() {
        delete sprite;
    }

    void SpriteEntity::setCollideFunc(std::function<void(Entity&, Entity&)> f) {
        collideFunc = f;
    }

    std::string SpriteEntity::debugText() {
        std::string txt;
        txt.append("id: ");
        txt.append(id);
        txt.append(" x: ");
        txt.append(std::to_string(rect.x));
        txt.append(" y: ");
        txt.append(std::to_string(rect.y));
        txt.append(" w: ");
        txt.append(std::to_string(rect.w));
        txt.append(" h: ");
        txt.append(std::to_string(rect.h));
        txt.append(" xVel: ");
        txt.append(std::to_string(xvel));
        txt.append(" yVel: ");
        txt.append(std::to_string(yvel));
        txt.append(" onGround: ");
        txt.append("\n");
        return txt;
    }

    void SpriteEntity::draw(SDL_Rect &camera) {
        if( c->collideRects(camera,this->rect)){
            SDL_Rect adj = {rect.x - camera.x, rect.y - camera.y, rect.w, rect.h};
            sprite->draw(adj);
        }
    }

    void SpriteEntity::tick() {
        Map& m = el->getMap();
        for(Entity* e: el->getEntities()){
            if(e != this){
                if(e->isColliding(*c)){
                    collide(*e);
                }
            }
        }
        move(m.getBounds());
        el->getPhys().applyPhysics(*this);
        draw(el->getCamera());

    }
}
