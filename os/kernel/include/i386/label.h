/*
 * Copyright (c) 2006, 2007
 * Nintendo Co., Ltd.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Nintendo makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */

#ifndef NINTENDO_ES_KERNEL_I386_LABEL_H_INCLUDED
#define NINTENDO_ES_KERNEL_I386_LABEL_H_INCLUDED

#include <es.h>

class Label
{
    struct Frame
    {
        Frame* prev;
        void*  pc;
    };

public:
    unsigned esp;       // 0
    unsigned eip;       // 4
    unsigned ebp;       // 8
    unsigned ebx;       // 12
    unsigned esi;       // 16
    unsigned edi;       // 20
    unsigned link;      // 24: 0(%ebp)

    Label() :
        esp(0),
        eip(0),
        ebp(0),
        ebx(0),
        esi(0),
        edi(0),
        link(0)
    {
    }

    Label(void* stack, unsigned stackSize, void startUp(void* param), void* param) :
        ebp(0),
        ebx(0),
        esi(0),
        edi(0),
        link(0)
    {
        init(stack, stackSize, startUp, param);
    }

    void init(void* stack, unsigned stackSize, void startUp(void* param), void* param)
    {
        ASSERT(stackSize % sizeof(unsigned) == 0);

        unsigned* frame = static_cast<unsigned*>(stack);
        eip = (unsigned) start;
        esp = (unsigned) &frame[stackSize / sizeof(unsigned) - 1];
        ebx = (unsigned) startUp;
        frame[stackSize / sizeof(unsigned) - 1] = (unsigned) param;
    }

    int set();
    void jump();

    /* Reports whether the stack is not broken after the label is set.
     */
    bool isSane()
    {
        return (ebp == 0 || *reinterpret_cast<void**>(ebp) == reinterpret_cast<void*>(link)) ? true : false;
    }

    void where()
    {
        Frame* frame = (Frame*) ebp;
        while (frame)
        {
            esReport("%p %p\n", frame->pc, frame->prev);
            frame = frame->prev;
        }
    }

    static void start();
};

#endif  // NINTENDO_ES_KERNEL_I386_LABEL_H_INCLUDED
