//
// Created by Aron on 2018-12-15.
//

#ifndef CPROGLIB_KEYCOMMAND_H
#define CPROGLIB_KEYCOMMAND_H


#include <SDL_keycode.h>
#include <SDL_events.h>

namespace CPROGLib {
    class KeyCommand { //TODO: Key as argument?
    public:
        virtual void perform(SDL_Event& ev) = 0;
        virtual ~KeyCommand(){};
        KeyCommand(const KeyCommand& obj) = delete;
        KeyCommand& operator=(const KeyCommand&) = delete;
    protected:
        KeyCommand(SDL_Keycode kc): keycode(kc){};
        SDL_Keycode getKeyCode(){
            return keycode;
        };
    private:
        SDL_Keycode keycode;
    };
}


#endif //CPROGLIB_KEYCOMMAND_H
