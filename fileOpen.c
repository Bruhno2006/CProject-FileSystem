#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "fileCheck.h"
#include "fileOpen.h"

char currentFile[256];

bool valid_extension(const char *fileInput) {
    char *dot = strrchr(fileInput, '.');
    if (!dot) {
        return false;
    }

    char *valid_ext[] = {".txt", ".py", ".c", ".java"};
    long num_valid = sizeof(valid_ext) / sizeof(valid_ext[0]);

    for (long i = 0; i < num_valid; i++) {
        if (strcmp(dot, valid_ext[i]) == 0) {
            return true;
        }
    }

    return false;
}

void getFile() {
    if (currentFile[0] != '\0') {
        printf("Currently using %s\n\n", currentFile);
    } else {
        perror("CAN'T GET FILE");
    }
}

bool splitFile(const char *filepath, char *name, char *ext) {
    const char *dot = strrchr(filepath, '.');

    if (!dot || dot == filepath) {
        strcpy(name, filepath);
        ext[0] = '\0';
        return false;
    }

    size_t name_len = dot - filepath;
    strncpy(name, filepath, name_len);
    name[name_len] = '\0';

    strcpy(ext, dot + 1);

    return true;
}

FILE* opentype(char* file, char* filetype) {
    FILE *fpointer;

    char filename[100];

    strcpy(filename, file);

    if (!valid_extension(filetype)) {
        return NULL;
    }

    if (strstr(filename, filetype) == NULL) {
        strcat(filename, filetype);
    }

    if (check(filename) == 1) {
        printf("\nThere is no %s file found. Creating new %s file...\n", filetype, filename);
    }

    strcpy(currentFile, filename);

    return fopen(filename, "a+");
}

FILE* open(char* file) {
    FILE *fpointer;

    char filename[100], filetype[50];

    splitFile(file, filename, filetype);

    if (!valid_extension(file)) {
        return NULL;
    }

    strcat(filename, ".");
    strcat(filename, filetype);

    strcpy(currentFile, filename);

    if (check(filename) == 1) {
        printf("\nThere is no text file found. Creating new %s file...\n", filename);
    }

    return fopen(filename, "a+");
}