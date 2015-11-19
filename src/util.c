#include "util.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void startRand()
{
	static bool initialized = false;

	if(!initialized)
	{
		srand(time(NULL));
		initialized = true;
	}
}


int nextRand(int max){

	return rand()%max;
}

double absolute(double num)
{
	if(num < 0)
	{
		num*= -1;
	}

	return num;
}

double power(double num, int n)
{
	double result = num;
	if (n==0){
		result = 1;
	}else{
		for(;n>1;n-=1)
		{
			result *= num;
		}

	}
	
	return result;
}

