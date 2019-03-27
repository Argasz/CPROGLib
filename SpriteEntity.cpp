//
// Created by Aron on 2018-11-29.
//

#include "SpriteEntity.h"
#include "EventLoop.h"
#include "PerPixelCollider.h"
#include "AnimatedSprite.h"
#include <typeinfo>
namespace CPROGLib{
    SpriteEntity::SpriteEntity(const std::string& imagePath, int x, int y, int w, int h, std::string& id, int collType) : Entity(id) {
        sprite = Sprite::getInstance(imagePath);
        rect = {x, y, w, h};
        xvel = 0;
        yvel = 0;
        this->collType = collType;
        if(collType == BOUNDING_BOX){
            c = new Collider(x,y,w,h);
        }else if(collType == PER_PIXEL){
            SDL_Surface* tmp = IMG_Load(imagePath.c_str());
            c =  new PerPixelCollider(x,y,*tmp);
            SDL_FreeSurface(tmp);
        }
    }
    SpriteEntity::SpriteEntity(Sprite *sprite, int x, int y, int w, int h, std::string &id) : Entity(id) { //Use for animated sprite in subclass
        this->sprite = sprite;
        rect = {x,y,w,h};
        xvel = 0;
        yvel = 0;
        this->collType = BOUNDING_BOX;
        c = new Collider(x,y,w,h);
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
        delete c;
    }

    void SpriteEntity::setCollideFunc(std::function<void(Entity&, Entity&)> f) {
        collideFunc = f;
    }

    std::string SpriteEntity::debugText() {
        std::string txt;
        txt.append("id: ");
        txt.append(getId());
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
        if( Collider::collideRects(camera,this->rect)){
            SDL_Rect adj = {rect.x - camera.x, rect.y - camera.y, rect.w, rect.h};
            sprite->draw(adj);
        }
    }

    void SpriteEntity::tick() {
        auto eLoop = getEventLoop();
        Map& m = eLoop->getMap();
        for(Entity* e: eLoop->getEntities()){
            if(auto se = dynamic_cast<SpriteEntity*>(e)){
                if(se != this){
                    if(se->isColliding(*c)){
                        collide(*se);
                    }
                }
            }
        }
        /*for(Entity* e: eLoop->getSceneEntities()){
            if(auto se = dynamic_cast<SpriteEntity*>(e)){
                if(se != this){
                    if(se->isColliding(*c)){
                        collide(*se);
                    }
                }
            }
        }*/
        move(m.getBounds());
        eLoop->getPhys().applyPhysics(*this,true);
        draw(eLoop->getCamera());

    }
}
