#include <stdio.h>
#include "fileCheck.h"

int check(char* fileInput) {
    FILE* fp = fopen(fileInput, "r");

    if (fp == NULL) {
        return 1;
    } else {
        return 0;
    }
}