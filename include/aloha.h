#ifndef DFSA_SIMULATOR_INCLUDE_ALOHA_H_
#define DFSA_SIMULATOR_INCLUDE_ALOHA_H_ 1

typedef enum slot{
    s_empty,
    s_success,
    s_collision
} Slot;

typedef int* SlotInfo;

int* aloha();

int lowerBound (SlotInfo slotInfo);

int eomLee (SlotInfo slotInfo);

#endif