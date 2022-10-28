#include <stdio.h>
#include <string.h>

// DEFINE COMMANDS

//filesystem

#define NEW_FILE "nf"
#define DELETE_FILE "df"
#define NEW_DIRECTORY "nd"
#define DELETE_DIRECTORY "dd"
#define NEW_DIRECTORY_SWITCH "nds"

// templates

#define SAVE_TEMPLATE "st"
#define LOAD_TEMPLATE "lt"
#define DELETE_TEMPLATE "dt"

// other

#define HELP "?"

// define commands in list

/*
    * Format:
    * {
    *   command, function,
    *   command, function,
    *   ...
    * }
*/

char *commands[] = {
    NEW_FILE, "Create new file",
    DELETE_FILE, "Delete file",
    NEW_DIRECTORY, "Create new directory",
    DELETE_DIRECTORY, "Delete directory",
    NEW_DIRECTORY_SWITCH, "Make new directory and switch to it",
    SAVE_TEMPLATE, "Save template from current directory",
    LOAD_TEMPLATE, "Loads template into current directory",
    DELETE_TEMPLATE, "Deletes template",
    HELP, "Show this help menu"
};