#include "delay.h"

void Delay(uint16 xms) { // @11.0592MHz
    uint8 data i, j;
    for (; xms; xms--) {
        i = 2;
        j = 199;
        do {
            while (--j);
        } while (--i);
    }
}

