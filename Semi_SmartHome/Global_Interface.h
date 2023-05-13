

#ifndef GLOBAL_INTERFACE_H_
#define GLOBAL_INTERFACE_H_

#define SREG        (*(volatile u8*)0x5F)

#define GLOBAL_BIT  (u8)7

void GLobalInterruptEnable();

void GLobalInterruptDisable();
#endif
