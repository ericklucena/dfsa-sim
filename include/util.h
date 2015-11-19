#ifndef DFSA_SIMULATOR_INCLUDE_UTIL_H_
#define DFSA_SIMULATOR_INCLUDE_UTIL_H_ 1

#include <stdbool.h>
#include <string.h>

void startRand();

int nextRand(int max);

double absolute(double num);

double power(double num, int exp);

bool startsWith(char *string, char *substring);

char* append(char *string, char *sufix);

#endif