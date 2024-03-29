#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#include "../include/pass_handle.h"
#include "../include/dir_handle.h"
#include "../include/global.h"
#include "../include/tools.h"
#include "../include/defs.h"

DIR *list_dir;
struct dirent *dir;

void create_cat() { 
    char cat_name[SIZE];
    char   buffer[SIZE];
    int i, j, k = 0;

    if(confirm());
    show_dir();
    get_path(buffer, storage);
    if(k++ == 1) {
        show_dir();
    }
    get_line("enter a category name without '.txt'\n\t- ", cat_name, SIZE); 
    remove_x_char(cat_name);

    if(!strcmp(cat_name, "")) {
        printf("Error: enter filename\n");
        exit(1);
    }
    strlcat(buffer, cat_name, SIZE);
    AWE = fopen(buffer, "r");
    if(!AWE) {
        AWE = fopen(buffer, "a");
        printf("%s - name of category\n", cat_name);
    }
    else {
        printf("ERROR: the file already exists\n");
    }
    fclose(AWE);
}

// удаление категории 
void delete_cat() {
    char filename[SIZE];
    char path[SIZE];

    if(confirm() == FALSE) {
        exit(1);
    }

    get_path(path, storage);
    show_dir();
    get_line("enter file what you want to delete: ", filename, SIZE);
    strlcat(path, filename, SIZE);
    remove(path);
}

// показать сществующие категории
int show_dir() { 
    char path[SIZE];
    get_path(path, storage);
    list_dir = opendir(path);
    int showed_dir = 0;
    int hidden_dir = 0;
    while ((dir = readdir(list_dir)) != NULL) {
        hidden_dir++;
        if(!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..")) {
            continue;
        }
        printf("[%d] %s\n", ++showed_dir, dir->d_name); // функции выхода  из директории . и ..
    }
    // printf("%d", hidden_dir);
    if(hidden_dir <= 2) {
        printf("[!] You haven't any categories for your entry. Creating...\n");
        create_cat();
    }
    closedir(list_dir);
}