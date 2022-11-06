char help_all[13][100] = {
    "\e[1;37m---[ File Commands ]---\e[0m",
    "nf <filename> - Create a new file",
    "df <filename> - Delete a file",
    "\e[1;37m---[ Directory Commands ]---\e[0m",
    "nd <directory name> - Create a new directory",
    "dd <directory name> - Delete directory",
    "\e[1;37m---[ Template Commands ]---\e[0m",
    "st <template name> - Saves the current directory as a template named <template name>",
    "lt <template name> - Load template in current directory",
    "dt <template name> - Delete template",
    "\e[1;37m---[ ETC Commands ]---\e[0m",
    "? - Help menu",
    "Easter eggs? There are many easter eggs in Deuterium. Find them. \e[0;31mthis is not optional (/j)\e[0m"
};

char help_nf[100][100] = {
    "nf <filename> - Create new file",
    "",
    "Create a new file named <filename>",
    "",
    "Examples:",
    "dt nf test.c",
    "dt nf Makefile"
};

#define HELP_NF &help_nf
