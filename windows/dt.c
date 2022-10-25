#include <stdio.h>
#include <string.h>
#include "../commands.h"
#include <windows.h>

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
                CreateFile(argv[2], GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
            }
        } else if (strcmp(argv[1], DELETE_FILE) == 0) {
            //delete file using argv[2]

            if(argv[2] == NULL) {
                printf("Usage: %s %s <filename>", argv[0], argv[1]);
                return 1;
            } else {
                DeleteFile(argv[2]);
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
