#include "../include/defs.h"
#include "../include/clipboard.h"
#include "../include/global.h"
#include "../include/validation.h"
#include "../crypt/rijndael.h"
#include "../include/pass_handle.h"
#include "../crypt/sha256.h"
#include "../include/tools.h"

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>

#define MAIN     "/awestruck/"
#define STORAGE  "categories/" 

void test() {
    copy("asdasd");
}

#ifdef unix
char* get_path(char* path, int path_type) {
    strlcpy(path, getenv("HOME"), SIZE);
    strlcat(path, MAIN, SIZE);

    switch (path_type) {
    case init:
        return 0;
    case storage:
        strlcat(path, STORAGE,     SIZE); break;
    case master:
        strlcat(path, master_file, SIZE); break;
    case temp:
        strlcat(path, tmp_file,    SIZE); break;
    default:
        EXIT_FAILURE;
    }
}

void init_struct() {
    char  path[SIZE];
    DIR *list_dir;
    struct dirent *dir;

    get_path(path, init);
    if((list_dir = opendir(path)) == NULL) {
        printf("The password storage folder was not found. Creating.\n");
        mkdir(path, 0777);
    }
    closedir(list_dir);

    get_path(path, storage);
    if((list_dir = opendir(path)) == NULL) {
        mkdir(path, 0777);
    }
    closedir(list_dir);
}
#elif _WIN64
    char* get_home_directory(char* directory) {
        directory = "C:\\Users\\path\\Desktop";
    }

    char* get_path(char* path) {
        path = "\\awestruck\\storage";
    }
#endif

void awe_version() {
    printf("Awestruck version: %s\n", VERSION);
}

void awe_print_logo() {
    static char logotype[] = "                                   __                            __       \n\
  ____ _ _      __  ___    _____  / /_   _____  __  __  _____   / /__       \n\
 / __ `/| | /| / / / _ \\  / ___/ / __/  / ___/ / / / / / ___/  / //_/      \n\
/ /_/ / | |/ |/ / /  __/ (__  ) / /_   / /    / /_/ / / /__   / ,<          \n\
\\__,_/  |__/|__/  \\___/ /____/  \\__/  /_/     \\__,_/  \\___/  /_/|_|    \n\n";

    printf("%s", logotype);
}

void awe_help() {
    char info[] = "\n\n\
Getting started with awestruck\n\
    \tinit    -  create a master password\n\
Work with entries\n\
    \tadd     -  adding an entry\n\
    \trem     -  deleting an entry\n\
    \tget     -  getting information about an entry\n\
    \tedit    -  edit an entry\n\
Global actions\n\
    \tlist    -  show the full list of entries\n\
    \tclear   -  deleting category or all entries\n\
    \tcat     -  create a new category\n\
App information\n\
    \thelp    -  awestruck usage help\n\
    \tversion -  show awestruk version\n\n";
    printf("%s", info);
}
