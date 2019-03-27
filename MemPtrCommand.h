//
// Created by Aron on 2018-12-15.
//

#ifndef CPROGLIB_MEMPTRCOMMAND_H
#define CPROGLIB_MEMPTRCOMMAND_H

#include <SDL_keycode.h>
#include "KeyCommand.h"

namespace CPROGLib {
    class EventLoop;
    template <typename T>
    class MemPtrCommand : public KeyCommand{
    public:
        MemPtrCommand(void (T::*mp)(), T &obj, SDL_Keycode k):KeyCommand(k){
            this->act = mp;
            this->object = &obj;
        }
        ~MemPtrCommand(){};
        void perform(SDL_Event& ev) override{
            if(ev.key.repeat == 0){
                if(getKeyCode() == ev.key.keysym.sym && ev.type == SDL_KEYDOWN){
                    (object->*act)();
                }
            }
        };
    private:
        void (T::*act)();
        T *object;
    };
}


#endif //CPROGLIB_KEYCOMMAND_H
