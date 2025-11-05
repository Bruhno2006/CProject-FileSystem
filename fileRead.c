#include <stdio.h>
#include <string.h>
#include "fileRead.h"

int read(FILE *fpointer) {
    char letter;

    printf("\n\n");
    while (fscanf(fpointer, "%c", &letter) != EOF) {
        printf("%c", letter);
    }

    printf("\n\n[END OF FILE]");
}