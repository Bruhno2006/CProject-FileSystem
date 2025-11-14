#include <stdio.h>
#include <string.h>

#include "fileConsole.h"
#include "fileCheck.h"
#include "fileOpen.h"

int main(int argc, char* argv[]) {
    FILE *fpointer;

    if (argc-1 < 1) {
        fpointer = NULL;
    } else if (argc-1 == 1) {
        fpointer = open(argv[1]);
    } else if (argc-1 == 2) {
        fpointer = opentype(argv[1], argv[2]);
    } else {
        printf("\nProgram can only handle one file\n");
        return 1;
    }

    console(fpointer);
    wipeSaveFile();

    return 0;
}