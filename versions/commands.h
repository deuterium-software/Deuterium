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

#define TEMPLATE_INIT "tinit"
#define SAVE_TEMPLATE "st"
#define LOAD_TEMPLATE "lt"
#define DELETE_TEMPLATE "dt"

// other

#define HELP "help"

#define SET_TIME_EASTER "set-time-easter"

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
    "--[ File", "Commands ]--",
    NEW_FILE, "Create new file",
    DELETE_FILE, "Delete file",
    "--[ Directory", "Commands ]--",
    NEW_DIRECTORY, "Create new directory",
    DELETE_DIRECTORY, "Delete directory",
    NEW_DIRECTORY_SWITCH, "Make new directory and switch to it",
    "--[ Template", "Commands ]--",
    TEMPLATE_INIT, "Initialize template in either ~/.deuterium/dt or \%USERPROFILE\%/.deuterium/dt",
    SAVE_TEMPLATE, "Save template from current directory",
    LOAD_TEMPLATE, "Loads template into current directory",
    DELETE_TEMPLATE, "Deletes template (not implemented)",
    "--[ ETC", "Commands ]--",
    HELP, "Show this help menu",
    "easter eggs", "They are easter eggs. Try to find them. \033[0;31mThis is not optional.\033[0m"
};