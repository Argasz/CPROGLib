//
// Created by Aron on 2018-12-15.
//

#ifndef CPROGLIB_KEYCOMMAND_H
#define CPROGLIB_KEYCOMMAND_H


namespace CPROGLib {
    class KeyCommand {
    public:
        virtual void perform() = 0;
        virtual ~KeyCommand(){};
    protected:
        KeyCommand(){};
    };
}


#endif //CPROGLIB_KEYCOMMAND_H
