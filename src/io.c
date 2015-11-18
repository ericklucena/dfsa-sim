#include "io.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void createFolderIfNotExists(char *folder)
{
	struct stat st = {0};

	if (stat(folder, &st) == -1) {
	    mkdir(folder, 0700);
	}
}

void writeTagsOnFile(char **tags, int numTags, char *filepath)
{
	FILE *in;
	int i;

	in = fopen(filepath, "w");

	if (in != NULL)
	{
		for (i=0; i<numTags; i++)
		{
			fprintf(in, "%s\n", tags[i]);
		}

		fclose(in);
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@IO: Can't open file\n");
		#endif
	}
}

