#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "fileRead.h"
#include "fileCheck.h"
#include "fileWrite.h"

#include "fileConsole.h"

int console(FILE *fpointer) {
    while (true) {
        char userInput[20];

        printf("\nCOMMANDS: 'read' / 'r' | 'write' / 'w' / 'exit' / 'e'\n");
        printf("Type in your command: ");
        fgets(userInput, sizeof(userInput), stdin);

        if (strcmp(userInput, "read\n") == 0 || strcmp(userInput, "r\n") == 0) {
            read(fpointer);
        } else if (strcmp(userInput, "write\n") == 0 || strcmp(userInput, "w\n") == 0) {
            write(fpointer);
        } else if (strcmp(userInput, "exit\n") == 0 || strcmp(userInput, "e\n") == 0) {
            break;
        } else {
            printf("Command unrecognisable\n");
        }
    }
}