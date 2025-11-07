#include <stdio.h>
#include "fileCheck.h"

int check(char* fileInput) {
    FILE *fp = fopen(fileInput, "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    return 0;
}