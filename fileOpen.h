#ifndef FOPEN_H
#define FOPEN_H

#include <stdio.h>

FILE* opentype(char* file, char* fileType); 

FILE* open(char* file);

FILE* change_handling(FILE* fpointer, char *handle);

char* getFile();

void wipeSaveFile();

#endif