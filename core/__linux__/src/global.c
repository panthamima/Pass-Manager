#include "../include/defs.h"
#include "../include/global.h"
#include "../include/validation.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#ifdef unix
    char* get_home_directory(char* directory) {
        directory = getenv("HOME"); // get home linux directory
    }
    
    char* get_path(char* path) {
        path = "/awestruck/awebase/categories/";
        char* buffer;
        
        get_home_directory(buffer);
        strcat(buffer, path);
        path = buffer;
    }
#elif _WIN64
    char* get_home_directory(char* directory) {
        directory = "C:\\Users\\path\\Desktop";
    }

    char* get_path(char* path) {
        path = "\\__awebase\\categories";
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
