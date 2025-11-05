#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "fileRead.h"
#include "fileCheck.h"

#include "fileConsole.h"

int console(FILE *fpointer) {
    while (true) {
        char userInput[20];

        printf("\nCOMMANDS: 'read' / 'r' | 'write' / 'w' / 'exit' / 'e'\n");
        printf("Type in your command: ");
        scanf("%s", userInput);

        if (strcmp(userInput, "read") == 0 || strcmp(userInput, "r") == 0) {
            read(fpointer);
        } else if (strcmp(userInput, "exit") == 0 || strcmp(userInput, "e") == 0) {
            break;
        } else {
            printf("Command unrecognisable\n");
        }
    }
}