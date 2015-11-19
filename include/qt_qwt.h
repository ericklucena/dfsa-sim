#ifndef DFSA_SIMULATOR_INCLUDE_QT_H_
#define DFSA_SIMULATOR_INCLUDE_QT_H_ 1

typedef struct dataInfo
{
	int reader;
	int tags;
	int steps;
} DataInfo;

DataInfo qt(char **tags, int size);

DataInfo qwt(char **tags, int size);

#endif
