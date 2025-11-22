#include <REGX52.H>
#include "nixie.h"

#define NixieData P0
#define NixieSelect P2

const uint8 code NixieTable[] = {
    ~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, // 0 - 4
    ~0x6D, ~0x7D, ~0x07, ~0x7F, ~0x6F, // 5 - 9
    ~0x40, // -
    ~0x80, // .
};

uint8 NixieBuffer[4] = {
    0, 0, 0, 0,
};

void NixieScanIsr() {
    static uint8 index = 0;
    P2 |= 0x0F;
    NixieData = NixieTable[NixieBuffer[index]];
    P2 &= ~(1 << index++);
    index &= 3;
}

void NixieDisplayUint(uint8 num) {
    NixieBuffer[1] = num / 100;
    NixieBuffer[2] = (num / 10) % 10;
    NixieBuffer[3] = num % 10;
}

void NixieDisplayInt(int8 num) {
    uint8 abs;
    if (num < 0) {
        abs = -num;
        NixieBuffer[0] = 10; // -
    } else {
        abs = num;
        NixieBuffer[0] = 0;
    }
    NixieBuffer[1] = abs / 100;
    NixieBuffer[2] = (abs / 10) % 10;
    NixieBuffer[3] = abs % 10;
}
