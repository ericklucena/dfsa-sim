#include "aloha.h"
#include "util.h"
#include "result.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

Result* aloha( int (*function)(SlotInfo) )
{
    int i;
    int j;
    int k;
    int numTags;
    int numTagsCount;
    int numSlots;
    int numCollision;
    int numSuccess;
    int numEmpty;
    int tag;
    int slot;
    int *slots;
    //int total;
    SlotInfo slotInfo = calloc(sizeof(int), 3);
    Result result;
    Result resultTotal;
    Result* results = calloc(sizeof(Result), 10);

    startRand();

    for (k=0, numTags = 100; numTags<=1000; numTags+=100, k++)
    {
        //printf("%d\n", numTags);
        resultTotal = initResult(numTags);
        for (i=0; i < 1000; i++)
        {
            //printf("i = %d\n", i);
            numSlots = 64;
            result = initResult(numTags);
            numTagsCount = numTags;

            while (numTagsCount != 0)
            {
                //printf("numTagsCount = %d\n", numTagsCount);
                //printf("CallocNumSlots: %d\n", numSlots);
                slots = calloc(sizeof(int), numSlots);
                numEmpty = 0;
                numSuccess = 0;
                numCollision = 0;

                for (tag = 0; tag < numTagsCount; tag++)
                {
                    slot = nextRand(numSlots);
                    //printf("slot = %d\n", slot);
                    slots[slot] += 1;
                }
                for (j=0; j<numSlots; j++)
                {
                    slot = slots[j];
                    if (slot == 0)
                    {
                        numEmpty += 1;
                    }
                    else if (slot == 1)
                    {
                        numSuccess += 1;
                    }
                    else
                    {
                        numCollision += 1;
                    }
                }

                if(numSlots > 0)
                {
                    free(slots);
                }

                result.numCollision += numCollision;
                result.numEmpty += numEmpty;
                numTagsCount -= numSuccess;
                
                //total = numCollision + numSuccess + numEmpty;
                //printf("Total: %d\n", numCollision + numSuccess + numEmpty);

                slotInfo[s_empty] = numEmpty;
                slotInfo[s_success] = numSuccess;
                slotInfo[s_collision] = numCollision;

                numSlots = function(slotInfo);
                //printf("NumSlots: %d\n", numSlots);
                //getchar();
            }
            resultTotal = addResult(resultTotal, result);
        }
        results[k] = divResult(resultTotal, 1000);
    }

    free(slotInfo);

    return results;
}

int lowerBound (SlotInfo slotInfo)
{
    return slotInfo[s_collision]*2;
}

int eomLee (SlotInfo slotInfo)
{
	double b;
	double y = 2.0;
	double t = 0.001;
    double newY;
    double f;
    int l;

	l = slotInfo[s_collision] + slotInfo[s_success] + slotInfo[s_empty];
    
    while (true)
    {
        b = l/((double)slotInfo[s_collision]*y + slotInfo[s_success]);
        newY = (1.0 - exp( (-1.0) / b)) / (b*(1.0 - (1.0 + 1.0/b)*exp((-1.0)/b)));

        if (absolute(y - newY) < t)
        {
            break;
        }

        y = newY;
    }

    f = y * slotInfo[s_collision];

    return f;   
}

int chen(SlotInfo slotInfo){
    int l = slotInfo[s_empty] + slotInfo[s_success] + slotInfo[s_collision];
    int n = slotInfo[s_success] + 2 * slotInfo[s_collision];
    double next = 0;
    double previous = -1;

    double pe;
    double ps;
    double pc;

    while (previous < next)
    {
        pe = pow((1.0 - (1.0/l)) , n);
        ps = (n/(double)l) * pow((1.0 - (1.0/(double)l)), (n - 1));
        pc = 1.0 - pe - ps;
        previous = next;
        //printf("%lf\n", chenFat(l, slotInfo[s_empty], slotInfo[s_success], slotInfo[s_collision]));
        next = chenFat(l, slotInfo[s_empty], slotInfo[s_success], slotInfo[s_collision]) * pow(pe, slotInfo[s_empty]) * pow(ps, slotInfo[s_success]) * pow(pc, slotInfo[s_collision]);
        
        n += 1;
    }

    return n - 2;
}


double chenFat(double a, double b, double c, double d){
    double res = 1.0;

    while (a > 1) {
        res *= a;
        a -= 1;

        if (b > 1) {
            res /= b;
            b -= 1;
        }

        if (c > 1) {
            res /= c;
            c -= 1;
        }

        if (d > 1) {
            res /= d;
            d -= 1;
        }
    }
    return res;
}