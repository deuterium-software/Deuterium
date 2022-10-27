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
                    error("Unable to be create file");
                    return 1;
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
                    error("Unable to delete file");
                    return 1;
                }
            }
        } else if (strcmp(argv[1], NEW_DIRECTORY) == 0) {
              
            int dir = mkdir(argv[2], 0777);
            
                // check if directory is created or not
            if (!dir)
                printf("Directory successfully created");
            else {
                error("Unable to create directory");
                return 1;
            }
        } else if (strcmp(argv[1], DELETE_DIRECTORY) == 0) {
            int dir = rmdir(argv[2]);
            
                // check if directory is created or not
            if (!dir)
                printf("Directory successfully deleted");
            else {
                error("Unable to delete directory");
                return 1;
            }
        } else if (strcmp(argv[1], NEW_DIRECTORY_SWITCH) == 0) {
            int dir = mkdir(argv[2], 0777);
            
            // check if directory is created or not
            if (!dir) {
                printf("Directory successfully created");

                char DEFAULT_STRING[sizeof(argv[2])+5] = "cd ";

                strcat(DEFAULT_STRING, argv[2]);

                system(DEFAULT_STRING);
                // int ch = chdir(strcat('/', argv[2]));

                // if (ch == 0) {
                //     printf("\nSuccessfully switched directory");
                // } else {
                //     error("\nUnable to switch into directory");
                //     return 1;
                // }
            } else {
                error("Unable to create directory");
                return 1;
            }
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
    };

    return 0;
}
