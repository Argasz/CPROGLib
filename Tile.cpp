//
// Created by Aron on 2018-12-09.
//

#include "Tile.h"

namespace CPROGLib{

    //TODO:Segment rects into top,bottom,l,r.
    Tile::Tile(const SDL_Rect &dst, const int t, SDL_Texture& tx, SDL_Rect &src) {
        rect = dst;
        clip = src;
        type = t;
        tex = &tx;
        top = {rect.x+2,rect.y,rect.w-2,4};
        btm = {rect.x+2,rect.y + ((rect.h*3)/4),rect.w-2,4};
        l = {rect.x, rect.y+2,4,rect.h-2};
        r = {rect.x + ((rect.w*3)/4), rect.y+2,4,rect.h-2};
    }

    void Tile::draw(SDL_Rect &camera) {
        if(isColliding(camera)) {
            SDL_Rect adjustedPos = {rect.x - camera.x, rect.y - camera.y, rect.w, rect.h};
            SDL_RenderCopy(window->getRenderer(), tex, &clip, &adjustedPos);
        }
    }

    bool Tile::isColliding(SDL_Rect& r) {
        bool ycoll = (this->rect.x <= (r.x + r.w) && (r.x <= (this->rect.x + this->rect.w)));
        bool xcoll = (this->rect.y <= (r.y + r.h) && (r.y <= (this->rect.y + this->rect.h)));
        return ycoll && xcoll;
    }

    int Tile::collidesRegion(SDL_Rect& r) {

        //bool nXColl = (this->top.x <= (r.x + r.w) && (r.x <= (this->top.x + this->top.w)));
        //bool nYColl = (this->top.y <= (r.y + r.h) && (r.y <= (this->top.y + this->top.h)));
        bool nColl = Collider::collideRects(r, top);

        //bool eXColl = (this->r.x <= (r.x + r.w) && (r.x <= (this->r.x + this->r.w)));
        //bool eYColl = (this->r.y <= (r.y + r.h) && (r.y <= (this->r.y + this->r.h)));
        bool eColl = Collider::collideRects(r,this->r);

        //bool sXColl = (this->btm.x <= (r.x + r.w) && (r.x <= (this->btm.x + this->btm.w)));
        //bool sYColl = (this->btm.y <= (r.y + r.h) && (r.y <= (this->btm.y + this->btm.h)));
        bool sColl = Collider::collideRects(r,btm);

        //bool wXColl = (this->l.x <= (r.x + r.w) && (r.x <= (this->l.x + this->l.w)));
        //bool wYColl = (this->l.y <= (r.y + r.h) && (r.y <= (this->l.y + this->l.h)));
        bool wColl = Collider::collideRects(r,this->l);

        if(nColl){
            if(eColl){
                return NE;
            }else if(wColl){
                return NW;
            }else{
                return N;
            }
        }
        if(sColl){
            if(eColl){
                return SE;
            }else if(wColl){
                return SW;
            }else{
                return S;
            }
        }
        if(eColl){
            return E;
        }else if(wColl){
            return W;
        }else{
            return NONE;
        }
       /*
       bool w = (r.x+r.w) <= rect.x;
       bool n = (r.y + r.h) <= rect.y;
       bool e = r.x >= rect.x+rect.w;
       bool s = r.y >= rect.y + rect.h;


        if(n){
            if(w){
                return NW;
            }else if(e){
                return NE;
            }else{
                return N;
            }
        }

        if(s){
            if(w){
                return SW;
            }else if(e){
                return SE;
            }else{
                return S;
            }
        }

        if(w){
            return W;
        }else if(e){
            return E;
        }else{
            return NONE;
        }
        */

    }

    std::string Tile::debugText() {
        std::string ret;
        ret.append(std::to_string(type));
        ret.append("{");
        ret.append(" x: ");
        ret.append(std::to_string(this->rect.x));
        ret.append(" y: ");
        ret.append(std::to_string(this->rect.y));
        ret.append(" w: ");
        ret.append(std::to_string(this->rect.w));
        ret.append(" h: ");
        ret.append(std::to_string(this->rect.h));
        return ret;
    };

    void Tile::drawRect(SDL_Rect& camera) {
        SDL_Rect temp = {rect.x - camera.x, rect.y - camera.y, rect.w, rect.h};
        SDL_RenderDrawRect(window->getRenderer(), &temp);
    }
}