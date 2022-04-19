#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#include "../include/pass_handle.h"
#include "../include/dir_handle.h"
#include "../include/tools.h"
#include "../include/defs.h"

DIR *list_dir;
struct dirent *dir;

void create_cat() { 
    char cat_name[SIZE];
    char buffer[SIZE];
    int i, j;

    if(confirm() == FALSE) {
        exit(1);
    }
    printf("enter a category name without\n\t- ");
    scanf("%s", cat_name); // if segfult == my_scanf(cat_name)
    remove_x_char(cat_name);

    if(!strcmp(cat_name, "")) {
        printf("Error: enter filename\n");
        exit(1);
    }

    strcat(path, cat_name);
    AWE = fopen(strcat(path, ".txt"), "rb+");
    if(!AWE) {
        AWE = fopen(path, "a");
        printf("%s.txt - name of category\n", cat_name);
    }
    else {
        printf("ERROR: the file already exists\n");
    }
    fclose(AWE);
}

// удаление категории 
void delete_cat() {
    char filename[SIZE];  
    if(confirm() == FALSE) {
        exit(1);
    }
    show_dir();
    printf("enter file what you want to delete: ");
    scanf("%s", filename);
    strcat(path,filename);
    remove(path);
}

void directory() {
    

}

// показать сществующие категории
void show_dir() { 
    list_dir = opendir(path);
    int i = 0;

    while ((dir = readdir(list_dir)) != NULL) {
        if(strlen(dir->d_name) > 2) { // if dirname > 3 то не будет показаны 
            printf("[%d] %s\n", ++i, dir->d_name); // функции выхода  из директории . и ..
        }
    }
    closedir(list_dir);
}