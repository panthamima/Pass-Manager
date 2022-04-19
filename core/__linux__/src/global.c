#include "../include/defs.h"
#include "../include/global.h"
#include "../include/validation.h"
#include "../include/pass_handle.h"
#include "../include/clipboard.h"

#include <dirent.h>
#include <stdlib.h>
#include <string.h>

void test() {
    char buffer[256];
    get_path(buffer);
}

#ifdef unix
    
    char* get_path(char* path) {
        const char main_folder[SIZE] = "/awestruck/storage/";
        path = getenv("HOME"); // get home linux directory
        
        strcat(path, main_folder);
        printf("%s", path);
    }
#elif _WIN64
    char* get_home_directory(char* directory) {
        directory = "C:\\Users\\path\\Desktop";
    }

    char* get_path(char* path) {
        path = "\\awestruck\\storage";
    }
#endif

// развертка структуры приложения
void init_struct() {
    char* path;
    DIR *list_dir;
    struct dirent *dir;

    list_dir = opendir(get_path(path));
    
    if(list_dir == NULL) {
        // system("mkdir -p /home/panthamima/__awebase/categories");
    }
}

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
 getting started with awestruck\n\
    \tinit  -  create a master password\n\
 work with entries\n\
    \tadd   -  adding an entry\n\
    \trem   -  deleting an entry\n\
    \tget   -  getting information about an entry\n\
    \tedit  -  edit an entry\n\
 global actions\n\
    \tlist  -  show the full list of entries\n\
    \tclear -  deleting category or all entries\n\
    \tcat   -  create a new category\n\n";
    printf("%s", info);
}
