#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "aloha.h"
#include "util.h"
#include "result.h"

int main ()
{
    int initTime = time(NULL);
    int i;
    Result *results;

    printf("%d\n", initTime);
    results = aloha(lowerBound);
    for(i=0; i < 10; i++)
    {
    	printResult(results[i]);
    	printf("\n");
    }
    free(results);

    printf("%d\n", (int) time(NULL) - initTime);
    results = aloha(eomLee);
    printf("%d\n", (int) time(NULL) - initTime);
    for(i=0; i < 10; i++)
    {
    	printResult(results[i]);
    	printf("\n");
    }
    free(results);


    printf("%d\n", (int) time(NULL) - initTime);
    results = aloha(chen);
    printf("%d\n", (int) time(NULL) - initTime);
    for(i=0; i < 10; i++)
    {
    	printResult(results[i]);
    	printf("\n");
    }
    free(results);
    
    
    return 0;
}