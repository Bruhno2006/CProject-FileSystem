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
    FILE *fp = fpointer;
    char userInput[20];
    size_t index;

    printf("-- WELCOME TO THE C-PROGRAM FILE SYSTEM -- \n");
    printf("Go to commands (commands) (c) to find command list\n\n");

    while (true) {
        printf("> ");
        fgets(userInput, sizeof(userInput), stdin);

        if (strcmp(userInput, "commands\n") == 0 || strcmp(userInput, "c\n") == 0) {
            commands();
        } else if (strcmp(userInput, "read\n") == 0 || strcmp(userInput, "r\n") == 0) {
            fp = change_handling(fp, "r");
            read(fp);
        } else if (strcmp(userInput, "write\n") == 0 || strcmp(userInput, "w\n") == 0) {
            fp = change_handling(fp, "w");
            write(fp, "w");
        } else if (strcmp(userInput, "close\n") == 0) {
            fclose(fp);
        } else if (strcmp(userInput, "open\n") == 0) {
            fclose(fp);
            printf("Type out the filename: ");
            fgets(userInput, sizeof(userInput), stdin);
            if (userInput != NULL) {      
                index = strcspn(userInput, "\n");
                userInput[index] = '\0';
                fp = open(userInput);
            } else {
                printf("\nCan't create a file with NULL.\n");
            }
        } else if (strcmp(userInput, "overwrite\n") == 0 || strcmp(userInput, "ow\n") == 0) {
            fp = change_handling(fp, "w+");
            write(fp, "w+");
        } else if (strcmp(userInput, "exit\n") == 0 || strcmp(userInput, "e\n") == 0) {
            break;
        } else {
            printf("Command unrecognisable\n");
        }
    }
}