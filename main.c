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

    char filename1[100];

    strcpy(filename1, argv[1]);

    if (strstr(filename1, ".txt") == NULL) {
        printf("Adding .txt behind the user input.\n");
        strcat(filename1, ".txt");
    } else {
        printf("Not adding .txt behind the user input\n");
    }

    if (check(filename1) == 1) {
        printf("\nThere is no text file found. Creating new %s file...\n", filename1);
    }

    fpointer = fopen(filename1, "a+");

    console(fpointer);

    fclose(fpointer);

    return 0;
}