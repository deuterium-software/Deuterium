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
            //save a template with argv[2] as name

            //first, copy the folder and everything inside specified and paste it in the templates folder
            //templates folder = C:\Program Files\DeuTerium\templates

            if(argv[2] == NULL) {
                printf("Usage: %s %s <templatename>", argv[0], argv[1]);
                return 1;
            } else {
                int CopyDir = CopyFile(argv[2], "C:\\Program Files\\DeuTerium\\templates\\", 0);

                if (CopyDir == 1) {
                    printf("Template successfully saved.");
                } else {
                    error("Could not save template.");
                }
            }

            //now we register the template in the "pointer" file
            //pointer file = C:\Program Files\DeuTerium\templates\pointer.txt

            FILE* PointerFile = fopen("C:\\Program Files\\DeuTerium\\templates\\pointer.txt", "a");

            if (PointerFile == NULL) {
                error("Could not open pointer file. Template may not work.");
            } else {
                fprintf(PointerFile, "%s ", argv[2]);
            }

        } else if (strcmp(argv[1], LOAD_TEMPLATE) == 0) {
            //load a template with argv[2] as name
            //this basically just copies the template to the current directory

            //first, we need to check if the template exists
            //we do this by checking the pointer file

            FILE* PointerFile = fopen("C:\\Program Files\\DeuTerium\\templates\\pointer.txt", "r");

            if (PointerFile == NULL) {
                error("Could not open pointer file.");
            } else {
                char* PointerFileContents = malloc(1000); //memory leaks! :D
                fgets(PointerFileContents, 1000, PointerFile);

                if (strstr(PointerFileContents, argv[2]) == NULL) {
                    error("Template does not exist.");
                } else {
                    //now we copy the template to the current directory
                    int CopyDir = CopyFile("C:\\Program Files\\DeuTerium\\templates\\", argv[2], 0);

                    if (CopyDir == 1) {
                        printf("Template successfully loaded.");
                    } else {
                        error("Could not load template.");
                    }
                }
            }
        } else if (strcmp(argv[1], DELETE_TEMPLATE) == 0) {
            //delete a template with argv[2] as name

            //first, we need to check if the template exists
            //we do this by checking the pointer file.. again

            FILE* PointerFile = fopen("C:\\Program Files\\DeuTerium\\templates\\pointer.txt", "r");

            if (PointerFile == NULL) {
                error("Could not open pointer file.");
            } else {
                char* PointerFileContents = malloc(1000); //memory leaks! :D
                fgets(PointerFileContents, 1000, PointerFile);

                if (strstr(PointerFileContents, argv[2]) == NULL) {
                    error("Template does not exist.");
                } else {
                    //now we delete the template
                    int DelDir = RemoveDirectory("C:\\Program Files\\DeuTerium\\templates\\");

                    if (DelDir == 1) {
                        printf("Template successfully removed.");
                    } else {
                        error("Could not remove template.");
                        printf("this is a beta. understandable have a nice day");
                    }
                }
            }
        } else if (strcmp(argv[1], HELP) == 0) {
            error("not implemented");
        } else {
            error("command not found.");
            return 1;
        }
    }
    
}
