#include "../include/defs.h"
#include "../include/global.h"
#include <dirent.h>
#include <stdlib.h>

#ifdef unix
    char* get_home_directory(char* directory) {
        extern char *environ;
        directory = getenv("HOME");
        printf("%s", directory)
    }

    char* get_path(char* path) {
        path = "/awebase/categories";
    }
#elif _WIN64
    char* get_home_directory(char* directory) {
        directory = "C:\\Users\\path\\Desktop";
    }

    char* get_path(char* path) {
        char *directory;
        get_home_directory(directory);
        path = "\\__awebase\\categories";
        char* buffer = calloc(strlen(directory) + strlen(path) + 1, 1);
        strcat(buffer, directory);
        strcat(buffer, path);
        printf("%s\n", buffer);
        free(buffer);
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

void print_logo() {
    printf("%s", logotype);
}

void help() {
    char info[] = " getting started with awestruck\n\t\
    reg\tcreate a master password\n\n\
    work with entries\n\t\
    add\tadding an entry\n\t\
    rem\tdeleting an entry\n\t\
    get\tgetting information about an entry\n\t\
    edit\tedit an entry\n\n\
    global actions\n\t\
    list\tshow the full list of entries\n\t\
    rem+\tdeleting category or all entries\n\t\
    cat\tcreating a new category\n\n";
}
