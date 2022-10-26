/*
* DEUTERIUM UNIX 2022
*
* AUTHORS:
* AREG HARUTYUNYAN
* JASE WILLIAMS
*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../commands.h"

void error(char* text) {
    printf("\033[0;31merror: ");
    printf("\033[0m%s", text);
}

int main(int argc, char** argv) {
    // check argv

    if (argc < 2) {
        printf("Usage: %s <command>", argv[0]);
    } else {
        //check if argv[1] was defined in commands.h
        if (strcmp(argv[1], NEW_FILE) == 0) {
            //create new file using argv[2]

            if(argv[2] == NULL) {
                printf("Usage: %s %s <filename>", argv[0], argv[1]);
                return 1;
            } else {
                int f = open(argv[2], O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);

                if (f != -1) {
                    printf("File successfully created.");
                } else {
                    printf("File could not be created.");
                }
            }
        } else if (strcmp(argv[1], DELETE_FILE) == 0) {
            //delete file using argv[2]

            if(argv[2] == NULL) {
                printf("Usage: %s %s <filename>", argv[0], argv[1]);
                return 1;
            } else {
                if (remove(argv[2]) == 0) {
                    printf("File successfully removed");
                } else {
                    error("Could not delete file.");
                }
            }
        } else if (strcmp(argv[1], NEW_DIRECTORY) == 0) {
            printf("not implemented");
        } else if (strcmp(argv[1], DELETE_DIRECTORY) == 0) {
            printf("not implemented");
        } else if (strcmp(argv[1], NEW_DIRECTORY_SWITCH) == 0) {
            printf("not implemented");
        } else if (strcmp(argv[1], SAVE_TEMPLATE) == 0) {
            printf("not implemented");
        } else if (strcmp(argv[1], LOAD_TEMPLATE) == 0) {
            printf("not implemented");
        
        } else if (strcmp(argv[1], HELP) == 0) {
            printf("not implemented");
        } else {
            printf("FATAL: %s is not a valid command", argv[1]);
            return 1;
        }
    }
    
}
