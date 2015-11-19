#include "qt_qwt.h"
#include "queue.h"
#include "util.h"
#include "generator.h"
#include <stdbool.h>
#include <string.h>

DataInfo qt(char **tags, int size)
{
    int i;
    int bitsTags = 0;
    int bitsReader = 0;
    int tagsFound;
    char *prefix;
    Queue *queue = newQueue();
    DataInfo info;

    enqueue(append("", "0"), queue);
    enqueue(append("", "1"), queue);
    

    while (!isEmpty(queue))
    {
        prefix = dequeue(queue);
        tagsFound = 0;

        for (i=0; i<size; i++)
        {
            if(startsWith(tags[i], prefix))
            {
                tagsFound++;
            }
        }
        bitsReader += strlen(prefix);
        bitsTags += tagsFound * GENERATOR_TAG_LENGTH;

        if (tagsFound == 1)
        {
            //Tag match
        }
        else if (tagsFound > 1)
        {
            enqueue(append(prefix, "0"), queue);
            enqueue(append(prefix, "1"), queue);
            free(prefix);
        }
    }

    info.reader = bitsReader;
    info.tags = bitsTags;

    return info;
}
    