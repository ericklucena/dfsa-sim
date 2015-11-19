#include "generator.h"
#include "util.h"
#include "io.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* createTag()
{
	int i;
	char *tag = malloc(sizeof(char)*GENERATOR_TAG_SIZE);

	if (tag != NULL)
	{
		startRand();
		for( i=0; i<GENERATOR_TAG_LENGTH; i++)
		{
			tag[i] = nextRand(2)==0?'0':'1';
		}
		tag[GENERATOR_TAG_LENGTH] = '\0';
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Generator: Failed tag malloc\n");
		#endif
	}
	return tag;
}



bool hasTag(char **insertedTags, char *tag)
{
	int i;
	bool tagFound = false;

	for ( i=0; (i<GENERATOR_NUM_TAGS) && (insertedTags[i] != NULL) && !tagFound; i++)
	{
		if (strcmp(tag, insertedTags[i]) == 0)
		{
			tagFound = true;
		}
	}

	return tagFound;
}

void generator()
{
	int i;
	int numFile;
	int numTags;
	int tagsInserted;
	char file[256];
	char subfolder[256];
	char *tag;
	char *insertedTags[GENERATOR_NUM_TAGS];

	//Init insertedTags DB
	for ( i = 0; i<GENERATOR_NUM_TAGS; i++)
	{
		insertedTags[i]=NULL;
	}

	createFolderIfNotExists(GENERATOR_FOLDER);

	for ( numTags=100; numTags <= GENERATOR_NUM_TAGS; numTags+=100)
	{
		sprintf(subfolder, "%s/%d", GENERATOR_FOLDER, numTags);
		createFolderIfNotExists(subfolder);

		for ( numFile = 0; numFile < GENERATOR_NUM_TAGS; numFile++) 
		{
			tagsInserted = 0;

			while (tagsInserted != numTags)
			{
				//fprintf(stderr, "%d-%d\n", numTags,tagsInserted);
				tag = createTag();

				if (!hasTag(insertedTags, tag))
				{
					insertedTags[tagsInserted++] = tag;
				}
				else
				{
					free(tag);
				}
			}
			sprintf(file, "%s/%04d.txt", subfolder, numFile+1);
			writeTagsOnFile(insertedTags, numTags, file);

			for ( i = 0; i<GENERATOR_NUM_TAGS && (insertedTags[i]!= NULL); i++)
			{
				free(insertedTags[i]);
				insertedTags[i]=NULL;
			}

		}
	}
}
