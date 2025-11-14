#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "fileWrite.h"

int write(FILE *fpointer, char *handle) {
    char userText[100];
    char line[256];
    char *result;
    char letter;
    bool overwrite = false;
    
    printf("Type [EXIT] or [END] to stop writing mode.\n");
    printf("\n\n[WRITING MODE ON]\n\n");

    if (strcmp(handle, "w") == 0) {
        while (fscanf(fpointer, "%c", &letter) != EOF && overwrite == false) {
            printf("%c", letter);
        }
    }

    while (fgets(userText, sizeof(userText), stdin) != NULL) {
        userText[strcspn(userText, "\n")] = 0; //Removes new line at the end of the user input

        if ((strcmp(userText, "[EXIT]") == 0) || (strcmp(userText, "[END]") == 0)) {
            break;
        }

        fprintf(fpointer, "%s\n", userText);
    }

    printf("\n[WRITING MODE OFF]\n\n");

    rewind(fpointer);
}