#include <stdio.h>
#include <string.h>

#include "fileConsole.h"
#include "fileCheck.h"

int main(int argc, char* argv[]) {
    FILE *fpointer;

    if (argc-1 < 1) {
        printf("\nThere is no file inputted in the command line\n");
        return 1;
    } else if (argc-1 > 1 ) {
        printf("\nProgram can only handle one file at a time\n");
        return 1;
    }

    char filename[100];
    char filename2[105];

    strcpy(filename, argv[1]);
    strcpy(filename2, argv[1]);

    strcat(filename2, ".txt");

    if (strcmp(filename, filename2) != 0) {
        printf("Success\n");
        strcat(filename, ".txt");
    } else {
        printf("Failure");
    }

    if (check(filename) == 1) {
        printf("\nThere is no text file found. Creating new %s file...\n", filename);
    }

    fpointer = fopen(filename, "a+");

    console(fpointer);

    fclose(fpointer);
}