#include <stdio.h>
#include <string.h>
#include "../commands.h"
#include <windows.h>

/*
* DEUTERIUM WINDOWS 2022
*
* AUTHORS:
* AREG HARUTYUNYAN
* JASE WILLIAMS
* Github Copilot <3
*/

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
            //create new file using argv[2] for name and directory

            if(argv[2] == NULL) {
                printf("Usage: %s %s <filename>", argv[0], argv[1]);
                return 1;
            } else {
                int* NewFile = CreateFile(argv[2], GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

                if (NewFile != INVALID_HANDLE_VALUE) {
                    printf("File successfully created.");
                } else {
                    error("File could not be created.");
                }
            }
        } else if (strcmp(argv[1], DELETE_FILE) == 0) {
            //delete a file with argv[2] as name

            if(argv[2] == NULL) {
                printf("Usage: %s %s <filename>", argv[0], argv[1]);
                return 1;
            } else {
                int DelFile = DeleteFile(argv[2]);

                if (DelFile == 1) {
                    printf("File successfully removed");
                } else {
                    error("Could not delete file.");
                }
            }
        } else if (strcmp(argv[1], NEW_DIRECTORY) == 0) {
            // create new directory using argv[2] as path

            if(argv[2] == NULL) {
                printf("Usage: %s %s <directoryname>", argv[0], argv[1]);
                return 1;
            } else {
                int NewDir = CreateDirectory(argv[2], NULL);

                if (NewDir == 1) {
                    printf("Directory successfully created.");
                } else {
                    error("Could not create directory.");
                }
            }
        } else if (strcmp(argv[1], DELETE_DIRECTORY) == 0) {
            //delete a directory with argv[2] as path to directory

            if(argv[2] == NULL) {
                printf("Usage: %s %s <directoryname>", argv[0], argv[1]);
                return 1;
            } else {
                int RmDir = RemoveDirectory(argv[2]);

                if (RmDir == 1) {
                    printf("Directory successfully removed.");
                } else {
                    error("Could not remove directory.");
                }
            }
        } else if (strcmp(argv[1], NEW_DIRECTORY_SWITCH) == 0) {
            error("not implemented");
        } else if (strcmp(argv[1], SAVE_TEMPLATE) == 0) {
            error("not implemented");
        } else if (strcmp(argv[1], LOAD_TEMPLATE) == 0) {
            error("not implemented");
        } else if (strcmp(argv[1], HELP) == 0) {
            error("not implemented");
        } else {
            error("command not found.");
            return 1;
        }
    }
    
}
