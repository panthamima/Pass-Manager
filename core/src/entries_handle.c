#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "../include/defs.h"
#include "../include/dir_handle.h"
#include "../include/pass_handle.h"
#include "../include/global.h"
#include "../include/tools.h"
#include "../include/clipboard.h"

// удалить выбранную запись
void removing() {
    char filename[SIZE];
    char temp_path[SIZE];    
    char  awe_path[SIZE];
    char buffer[SIZE];
    unsigned file_line = 1;
    int j, k, num_line;
    j = k = num_line = 0;
    
    if(confirm);
    show_dir();
    
    get_path(temp_path, temp);
    get_path(awe_path, storage);

    printf("Enter the file where you want to delete the entry\n\t- ");
    scanf("%s", filename);
    strlcat(awe_path, filename, SIZE);
    AWE = fopen(awe_path, "r");
    
    if(!AWE) {
        printf("Error: file doesn't exist\n");
        exit(1);
    }

    printf("Enter number of line\n\t- ");
    scanf("%d", &num_line);
  
    TEMP = fopen(temp_path, "a");
    while(!feof(AWE)) {
        if((fgets(buffer, SIZE, AWE) != NULL) && file_line != num_line) {
            fprintf(TEMP, "%s", buffer);
        }
        file_line++;
    }

    fclose(AWE);
    fclose(TEMP);

    AWE  = fopen(awe_path, "w");
    TEMP = fopen(temp_path, "r");
    
    while(!feof(TEMP)) {
        if(fgets(buffer, SIZE, TEMP) != NULL) {
            fprintf(AWE, "%s", buffer);
        }
        file_line++;
    }
    TEMP = freopen(temp_path, "w", stdin);

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
    fgets(buffer, SIZE, stdin);
    // printf("%s %ld %ld", buffer, sizeof(buffer), strlen(buffer));
    if(symbol == '(' && buffer[0] == '\n') {
        random_pass(buffer);
        printf("your random password: %s\n", buffer);
    }
    buffer[strlen(buffer)-1] = '\0';
    if(symbol == '\n' && buffer[0] != '\n') {

    }

    fprintf(AWE, "%s%c", buffer, symbol);
    if(symbol == ')') {
        fprintf(AWE, "\n");
    }
    fclose(AWE);    
}

// добавление строки в файл
void addition() {
    if(confirm());

    char path[SIZE]; 
    char filename[SIZE];
    if(show_dir());

    get_path(path, storage);

    get_line("enter filename\n\t- ", filename, SIZE);
    strlcat(path, filename, SIZE);

    printf("Enter login\n\t- ");
    prepare_string(path, ':');

    printf("Enter password\n\t- ");
    prepare_string(path, '(');

    printf("Add a note, enter if you don't need it\n");
    prepare_string(path, ')');
    
}

// показать все пароли из файла
void show_the_list() {
    if(!confirm()) {
        exit(1);
    }

    int j = 1;
    char c;
    char path[SIZE];
    char line[SIZE];
    char buffer[SIZE];
    DIR *list_dir;
    struct dirent *dir;

    get_path(path, storage);
    list_dir = opendir(path);
    while ((dir = readdir(list_dir)) != NULL) {
        if(!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..")) {
            continue;
        }
        memcpy(buffer, path, (strlen(path) +1)); // копирование path в buffer 
        AWE = fopen(strcat(buffer, dir->d_name), "r"); 
        printf("\n%s\n", dir->d_name);
            
        while(fscanf(AWE, "%s", line) != EOF) {
            printf("[%d] %s\n",j++, line);
        }
        j = 1;
        printf("\n+------------------------------------+\n");
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
    unsigned line = 0;
    int i = 1;
    int k = 0;
    char entry[SIZE];
    char entry_buf[SIZE];
    char buffer[SIZE];
    char category[SIZE];
    char path[SIZE];
    char answer[SIZE];
    char enter;

    if(confirm() == FALSE) {
        exit(1);
    }

    show_dir();
    printf("enter category name: ");
    scanf("%s", category);
    get_path(path, storage);
    strlcat(path, category, SIZE);
    if(!(AWE = fopen(path, "r"))) {
        printf("error. the category doesn't exist\n");
        exit(1);
    }
    while(fscanf(AWE, "%s", buffer) != EOF) {
        printf("[%d]> %s\n", i++, buffer);
    }
    printf("\n[!] Pass will be saved in your clipboard, after input type ctrl^C\n");
    printf("enter number of entry: ");
    scanf("%d", &line);
    // get_line("", line, SIZE);
    int j = 0;
    counting(path, line-1, entry, sizeof(entry));
    printf("choose what you want to get:\n\tf [full]\n\tp [pass]\n\tl [login]\n\t- ");
    scanf("%s", answer);

    switch (answer[0]) {
    case 'f':
    while(j < strlen(entry)) {
        entry_buf[j] = entry[j];
        j++;
    }
    entry_buf[j] = '\0';
        break;
    case 'p':
        for(j = 0; j < strlen(entry); j++) {
        if(entry[j] == ':') {
            j++;
            while(entry[j] != '(') {
                entry_buf[k++] = entry[j++];
            }
        }
        entry_buf[j] == '\0';
        }
        break;
    case 'l':
    for(j = 0; j < strlen(entry); j++) {
        while(entry[j] != ':') {
            entry_buf[k++] = entry[j++];
        }
        entry_buf[j] == '\0';
    }
        break;
    default:
        printf("unknown token\n");
        break;
    }

    copy(entry_buf);
    fclose(AWE);    
}
