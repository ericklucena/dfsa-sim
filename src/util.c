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

bool startsWith(char *string, char *substring)
{
	int i;
	int size;
	bool match = true;

	size = strlen(substring);
	if (strlen(string)<size)
	{
		match = false;
	}

	for (i = 0; i<size && match; i++)
	{
		if (string[i] != substring[i])
		{
			match = false;
		}
	}

	return match;
}

char* append(char *string, char *sufix)
{
	char *newString = malloc(sizeof(char)*(strlen(string)+strlen(sufix)+1));

	if (newString != NULL)
	{
		strcpy(newString, string);
		strcat(newString, sufix);
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Append: Failed malloc\n");
		#endif 
	}

	return newString;
}
