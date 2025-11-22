#ifndef __NIXIE_H__
#define __NIXIE_H__

#include "typedef.h"
#include "delay.h"

extern uint8 NixieBuffer[4];

void NixieScanIsr();
void NixieDisplayUint(uint8 num);
void NixieDisplayInt(int8 num);

#endif
