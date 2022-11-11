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
#include "./help.h"

void error(char* text) {
    printf("\033[0;31merror: ");
    printf("\033[0m%s", text);
}

int main(int argc, char** argv) {
    // check argv

    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
    } else {
        //check if argv[1] was defined in commands.h
        if (strcmp(argv[1], NEW_FILE) == 0) {
            //create new file using argv[2]

            if(argv[2] == NULL) {
                printf("Usage: %s %s <filename>\n", argv[0], argv[1]);
                return 1;
            } else {
                int f = open(argv[2], O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);

                if (f != -1) {
                    printf("File successfully created.\n");
                } else {
                    error("Unable to be create file.\n");
                    return 1;
                }
            }
        } else if (strcmp(argv[1], DELETE_FILE) == 0) {
            //delete file using argv[2]

            if(argv[2] == NULL) {
                printf("Usage: %s %s <filename>.\n", argv[0], argv[1]);
                return 1;
            } else {
                if (remove(argv[2]) == 0) {
                    printf("File successfully removed.\n");
                } else {
                    error("Unable to delete file.\n");
                    return 1;
                }
            }
        } else if (strcmp(argv[1], NEW_DIRECTORY) == 0) {
              
            int dir = mkdir(argv[2], 0777);
            
                // check if directory is created or not
            if (!dir)
                printf("Directory successfully created.\n");
            else {
                error("Unable to create directory.\n");
                return 1;
            }
        } else if (strcmp(argv[1], DELETE_DIRECTORY) == 0) {
            int dir = rmdir(argv[2]);
            
                // check if directory is created or not
            if (!dir)
                printf("Directory successfully deleted.\n");
            else {
                error("Unable to delete directory.\n");
                return 1;
            }
        } else if (strcmp(argv[1], NEW_DIRECTORY_SWITCH) == 0) {
            printf("DEPRECATED");
        } else if (strcmp(argv[1], SAVE_TEMPLATE) == 0) {
            printf("not implemented");
        } else if (strcmp(argv[1], LOAD_TEMPLATE) == 0) {
            printf("not implemented");
        
        } else if (strcmp(argv[1], HELP) == 0) {
            if (argc <= 2) {
                for (int i = 0; i < 13; i++) { //sizeof() was being annoying af so i just decided to hard code it in
                    if (i != 12) printf("%s\n", help_all[i]);
                    if (i == 12) printf("\e[0;36m%s\n\e[0m", help_all[i]);
                }
            } else if (argc == 3) { // help on specific commands
                void print_help_command(char str[100][100]) {
                    for (size_t i = 0; i < sizeof(str); i++) {
                        printf("%s\n", str[i]);
                    }
                }
                                    
                if (strcmp(argv[2], "nf") == 0) {
                    print_help_command(help_nf);
                }
            }
        } else if (strcmp(argv[1], "easter") == 0) {
            printf("Hmm, you seem to have found it.\n");
            printf("Well, as as a reward for sifting through the awful Deuterium source code (or listening to someone else), here are all the easter eggs in Deuterium!\n");
            printf("-------------------[ EASTER EGGS ]-------------------\n");
            printf("easter - See al the available easter eggs\n");
        } else {
            printf("FATAL: %s is not a valid command", argv[1]);
            return 1;
        }
    };

    return 0;
}
