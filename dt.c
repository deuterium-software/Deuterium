#include <stdio.h>
#include <string.h>
#include "commands.h"

int main(int argc, char** argv) {
    // check argv

    if (argc < 2) {
        printf("Usage: %s <command>", argv[0]);
    } else {
        //check if argv[1] was defined in commands.h
        if (strcmp(argv[1], NEW_FILE) == 0) {
            printf("New file command");
        } else if (strcmp(argv[1], DELETE_FILE) == 0) {
            printf("Delete file command");
        } else if (strcmp(argv[1], NEW_DIRECTORY) == 0) {
            printf("New directory command");
        } else if (strcmp(argv[1], DELETE_DIRECTORY) == 0) {
            printf("Delete directory command");
        } else if (strcmp(argv[1], NEW_DIRECTORY_SWITCH) == 0) {
            printf("New directory switch command");
        } else if (strcmp(argv[1], SAVE_TEMPLATE) == 0) {
            printf("Save template command");
        } else if (strcmp(argv[1], LOAD_TEMPLATE) == 0) {
            printf("Load template command");
        } else {
            printf("FATAL: %s is not a valid command", argv[1]);
        }
    }
    
}
