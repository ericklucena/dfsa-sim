#ifndef DFSA_SIMULATOR_INCLUDE_IO_H_
#define DFSA_SIMULATOR_INCLUDE_IO_H_ 1

void createFolderIfNotExists(char *folder);

void writeTagsOnFile(char **tags, int numTags, char *filepath);

#endif
