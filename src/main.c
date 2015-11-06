#include <stdio.h>
#include <stdlib.h>

#include "aloha.h"

int main ()
{
    int slotInfo[3] = {1,2,3};
    
    
    printf("%d\n", lowerBound(slotInfo));
    
    return 0;
}