#include "util.h"
#include <stdlib.h>
#include <time.h>


void initRand()
{
	srand(time(NULL));
}


int nextRand(int max){

	return rand()%max;
}