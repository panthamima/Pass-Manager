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
    int i, j;
    get_path(buffer, storage);

    if(confirm() == FALSE) {
        exit(1);
    }
    printf("enter a category name without '.txt'\n\t- ");
    scanf("%s", cat_name); // if segfult == my_scanf(cat_name)
    remove_x_char(cat_name);

    if(!strcmp(cat_name, "")) {
        printf("Error: enter filename\n");
        exit(1);
    }
    strlcat(buffer, cat_name, SIZE);
    AWE = fopen(buffer, "r");
    if(!AWE) {
        AWE = fopen(buffer, "a");
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
    char path[SIZE];
    
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

void remove_file() {
    
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
        if(strlen(dir->d_name) > 2) { // if dirname > 2  то не будет показаны 
            printf("[%d] %s\n", ++showed_dir, dir->d_name); // функции выхода  из директории . и ..
        }
    }
    printf("%d", hidden_dir);
    if(hidden_dir <= 2) {
        create_cat();
    }
    closedir(list_dir);
}