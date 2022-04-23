#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "../include/defs.h"
#include "../include/dir_handle.h"
#include "../include/pass_handle.h"
#include "../include/global.h"
#include "../include/tools.h"

// удалить выбранную запись
void removing() { // брать слово вычитать все символы до последних четырех , если она равно .txt то SUCCESS
    char filename[SIZE];
    char ext[] = ".txt";
    char path[SIZE];    
    char buffer[SIZE];
    unsigned lines = 1;
    int j,k;
    int d = 0;
    j = k = 0;

    show_dir();
    printf("enter file where delete\n\t- ");
    scanf("%s", filename);
    
    strlcat(get_path(path, storage), filename, SIZE);
    AWE = fopen(path, "r");
    if(!AWE) {
        printf("Error: file doesn't exist\n");
        exit(1);
    }

    printf("Enter number of line\n\t- ");
    scanf("%d", &d);
  
    TEMP = fopen(tmp_file, "a");
    while(!feof(AWE)) {
        if((fgets(buffer, SIZE, AWE) != NULL) && lines != d) {
            fprintf(TEMP, "%s", buffer);
        }
        lines++;
    }

    fclose(AWE);
    fclose(TEMP);
    AWE = fopen(path, "w");
    TEMP = fopen(tmp_file, "r");
    
    while(!feof(TEMP)) {
        if(fgets(buffer, SIZE, TEMP) != NULL) {
            fprintf(AWE, "%s", buffer);
        }
        lines++;
    }
    TEMP = freopen(tmp_file, "w", stdin);

    fclose(TEMP);
    fclose(AWE);
}

// удалить все пароли
void shred() {

}

// создание строки для записи в файл
void prepare_string(char path_file[SIZE], char symbol) { 
    AWE = fopen(path_file, "r");
    if(AWE == NULL) {
        printf("file doesnt exist\n");
        exit(1);
    }
    AWE = fopen(path_file, "a");
    char buffer[SIZE];
    scanf("%s", buffer);
    fprintf(AWE, "%s%c", buffer, symbol);
    fclose(AWE);    
}

// добавление строки в файл
// 1.если нет файла некуда добавлять, надо вызывать функцию создания файла
// 2.если нажать пробел запись багается, если дать 
// по башке после логина -> только он остается в файле

void addition() {
    char path[SIZE]; 
    char filename[SIZE];
    show_dir();
    printf("enter filename\n\t- ");
    scanf("%s", filename);
    strlcat(get_path(path, storage), filename, SIZE);
    printf("%s", path);
    printf("Enter login\n\t- ");
    prepare_string(path, ':');

    printf("Enter password\n\t- ");
    prepare_string(path, '\n');
}

// показать все пароли из файла
void show_the_list() {
    int j = 1;
    char c;
    char path[SIZE];
    char line[SIZE];
    char buffer[SIZE];
    DIR *list_dir;
    struct dirent *dir;

    if(!confirm()) {
        exit(1);
    }
    
    list_dir = opendir(get_path(path, storage));
    while ((dir = readdir(list_dir)) != NULL) {
        if(strlen(dir->d_name) > 2) { // if dirname > 3 то не будут показаны . и .. 
            memcpy(buffer, path, (strlen(path) +1)); // копирование path в buffer 
            AWE = fopen(strcat(buffer, dir->d_name), "r"); 
            printf("\n%s\n", dir->d_name);
            
            while(fscanf(AWE, "%s", line) != EOF) {
                printf("[%d] %s\n",j++, line);
            }
            j = 1;
            printf("\n+------------------------------------+\n");
        }
    } 
    closedir(list_dir);
}

// подсчет строк в файле
int counting(const char* f_name, int n, char* buf, int len) {
    char  c;
    FILE* AWE = fopen(f_name, "r");
    if(AWE == NULL) {
        return 0;
    }

    while(! feof(AWE) && (n > 0)) {
       fscanf(AWE, "%*[^\n\r]%c", &c);
       --n;
    }

    if(! feof(AWE)) {
        fgets(buf, len-1, AWE);
    }
    else {
       *buf = '\0';
    }
    fclose(AWE);    

    return (int)(*buf != '\0');
}

// выдача информации о записи (строке)
void extradition() {
    unsigned line;
    int i = 1;
    char entry[SIZE];
    char buffer[SIZE];
    char category[SIZE];
    char path[SIZE];

    system("clear");

    if(confirm() == FALSE) {
        exit(1);
    }

    show_dir();
    printf("enter category name: ");
    scanf("%s", category);
    strlcat(get_path(path, storage), category, SIZE);
    if(!(AWE = fopen(path, "r"))) {
        printf("error. the category doesn't exist\n");
        exit(1);
    }
    while(fscanf(AWE, "%s", buffer) != EOF) {
        printf("[%d]> %s\n", i++, buffer);
    }
    printf("enter number of entry: ");
    scanf("%d", &line);

    counting(path, line-1, entry, sizeof(entry));
    puts(entry);
    fclose(AWE);    
}
