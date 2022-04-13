#include "../include/defs.h"
#include "../include/global.h"
#include <dirent.h>
#include <stdlib.h>

#ifdef unix
void get_home_directory() {
    extern char *environ;
    printf("%s\n", getenv("HOME"));
}
#elif _WIN64
#endif

// развертка структуры приложения
void init_struct() {
    DIR *list_dir;
    struct dirent *dir;
    list_dir = opendir("/home/panthamima/__awebase/categories/");
    if(list_dir == NULL) {
        system("mkdir -p /home/panthamima/__awebase/categories");
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
