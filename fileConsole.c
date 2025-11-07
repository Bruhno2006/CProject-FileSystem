#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "fileOpen.h"
#include "fileRead.h"
#include "fileCheck.h"
#include "fileWrite.h"
#include "fileCommands.h"

#include "fileConsole.h"

int console(FILE *fpointer) {

    printf("-- WELCOME TO THE C-PROGRAM FILE SYSTEM -- \n");
    printf("Go to commands (commands) (c) to find command list\n\n");

    while (true) {
        char userInput[20];

        fgets(userInput, sizeof(userInput), stdin);

        if (strcmp(userInput, "commands\n") == 0 || strcmp(userInput, "c\n") == 0) {
            commands();
        } else if (strcmp(userInput, "read\n") == 0 || strcmp(userInput, "r\n") == 0) {
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