#include "wait.h"


void wait(double __ms) {
    double __tmp;

    uint16_t __ticks;
    __tmp = ((F_CPU) / 4e3) * __ms;
    if (__tmp < 1.0)
        __ticks = 1;
    else if (__tmp > 65535) {
        //  __ticks = requested delay in 1/10 ms
        __ticks = (uint16_t)(__ms * 10.0);
        while (__ticks) {
            // wait 1/10 ms
            _delay_loop_2(((F_CPU) / 4e3) / 10);
            __ticks--;
        }
        return;
    } else
        __ticks = (uint16_t) __tmp;
    _delay_loop_2(__ticks);
}