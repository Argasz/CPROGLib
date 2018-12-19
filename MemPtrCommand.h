//
// Created by Aron on 2018-12-15.
//

#ifndef CPROGLIB_MEMPTRCOMMAND_H
#define CPROGLIB_MEMPTRCOMMAND_H
#include "KeyCommand.h"

namespace CPROGLib { //TODO:FuncPtrCommand
    class EventLoop;
    template <typename T>
    class MemPtrCommand : public KeyCommand{
    public:
        MemPtrCommand(void (T::*mp)(), T &obj){
            this->act = mp;
            this->object = &obj;
        }
        virtual ~MemPtrCommand(){};
        void perform() override {
            (object->*act)();
        };

    private:
        void (T::*act)();
        T *object;
    };
}


#endif //CPROGLIB_KEYCOMMAND_H
