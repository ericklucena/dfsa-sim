#ifndef DFSA_SIMULATOR_INCLUDE_ALOHA_H_
#define DFSA_SIMULATOR_INCLUDE_ALOHA_H_ 1

#include "result.h"

typedef enum slot{
    s_empty,
    s_success,
    s_collision
} Slot;

typedef int* SlotInfo;

Result* aloha();

int lowerBound (SlotInfo slotInfo);

int eomLee (SlotInfo slotInfo);

int chen (SlotInfo slotInfo);

double chenFat(double a, double b, double c, double d);

#endif