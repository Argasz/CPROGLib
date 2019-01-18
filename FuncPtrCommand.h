//
// Created by Aron on 2019-01-15.
//

#ifndef CPROGLIB_FUNCPTRCOMMAND_H
#define CPROGLIB_FUNCPTRCOMMAND_H


#include <SDL_keycode.h>
#include <functional>
#include "KeyCommand.h"

namespace CPROGLib {
    template <typename T>
    class FuncPtrCommand : public KeyCommand{
    public:
        FuncPtrCommand(SDL_Keycode k, std::function<T>* f);
        void perform(SDL_Keycode kc){
            if(getKeyCode() == kc){
                f();
            }
        }
        ~FuncPtrCommand();

    private:
        std::function<T>* f;

    };
}


#endif //CPROGLIB_FUNCPTRCOMMAND_H
