#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#include <dirent.h>
// #include <X11/Xlib.h>
// #include <sys/stat.h>
// #include <sys/types.h>

#include "cli.h"
#include "../xorplus.h"

FILE *AWE, *TEMP;
char mf[] = "__awebase/mas.txt";
char path[SIZE] = "__awebase/categories/";
char temp_buffer[] = "__awebase/categories/_tmp.txt";

int main(int argc, char **argv){
    init_struct();

    /****/ if (argc < 2) {
        printf("command not found. Enter: awe help\n");
    } else if (!strcmp(argv[1], "reg")) {
        master_seed();
    } else if (!strcmp(argv[1], "add")) {
        addition();
    } else if (!strcmp(argv[1], "rem")) {
        removing();
    } else if (!strcmp(argv[1], "get")) {
        extradition();
    } else if (!strcmp(argv[1], "list")) {
        show_the_list();
    } else if (!strcmp(argv[1], "rem+")) {
        shred();
    } else if (!strcmp(argv[1], "test")) {
        tmp_stor(TEMP, AWE, temp_buffer, "a");
    } else if (!strcmp(argv[1], "help")) {
        system("clear");
        printf("%s", help);
    } else if (!strcmp(argv[1], "cat")) {
        create_cat(); // добавить проверку на добвление .txt
    } else {
        printf("command not found. Enter: awe help\n");
    }
}

// создание мастер пароля
void master_seed() { 
    char answer;
    char master_pass[SIZE], 
         re_master_pass[SIZE];
    system("clear");
    AWE = fopen(mf, "a+"); 
    fseek(AWE, 0, SEEK_END);
    long pos = ftell(AWE);

    if(pos > 0) {
        printf("the password already exists. change password?[y/n]\n");
        answer = getchar();
        if(answer == 'Y' || answer == 'y') {
            if(confirm() == FALSE) {
                exit(1);
            }
            AWE = fopen(mf, "w"); // 
        }
        else {
            printf("Canselling...\n");
            exit(1);
        }
    }
    //awestruck
    printf("%sHello in Awestruck! \nEnter a master password: ~$ ", logotype);
    scanf("%s", &master_pass);


    if(master_pass != NULL) {
        printf("confirm your master password: ");
        scanf("%s", &re_master_pass);
        if(strcmp(master_pass, re_master_pass) == 0) {
            printf("the password has been saved.\n");
            // caeXorEnc(re_master_pass, "asd");
            printf("%s", re_master_pass);
            fputs(re_master_pass, AWE);
        }
        else {
            printf("Error: Passwords don't match.\n");
            exit(1);
        }
    }
}

// подтверждение мастер пароля
int confirm() {  // сделать количество попыток
    char pas_confirm[SIZE], buffer[SIZE];
    int i;
    AWE = fopen(mf, "r");
    if(!AWE) {
        AWE = fopen(mf, "w+");
    }
    fseek(AWE, 0, SEEK_END);
    long pos = ftell(AWE);

    if(pos > 0) {
        AWE = fopen(mf, "r+");
        printf("Enter master password to confirm: ");
        scanf("%s", pas_confirm);
        fgets(buffer, SIZE, AWE);
        if(strcmp(pas_confirm, buffer) == 0) {
            printf("Success.\n");
            return TRUE;
        }
        printf("passwords are not match. Cancelling...\n");
        return FALSE;
    } 
    printf("Enter awestruck reg, and create password\n");
    return FALSE;
}

// удаление запрещенных символов
char* remove_x_char(char* str) {
    char* temp = str;
    char* add, *buffer;
    for(add = str, buffer = str; *buffer = *add; *add++) {
        if(isspace(*add)) {
            *buffer++;
            continue;
        }
        else if (isalnum(*add)) {
            *buffer++;
        }
    }
    return temp;
}

// analog scanf
void my_scanf(char *string) {
    char c;
    while ((c = getchar()) != '\n') { 
        *string++ = c;
    }
}

void handler_io(char *filename, char *crypt_action) {
    int i = 0;
    unsigned file_size = 524288;
    char file_buf[file_size];

    AWE = fopen(strcat(path, filename), "a");
    while(!feof(AWE)) {
        file_buf[i++] = getc(AWE);
    }

    if(!strcmp(crypt_action, "encrypt")) {
        
        // caeXorEnc(file_buf, "bebra", ); // соеденить с confirmom и взять от туда мастер пас ЙЙЙ
    }

    if(strcmp(crypt_action, "decrypt")) {
        // do smthng decrypt
    }

}

void output(char *filename) {

}

// создание категории
char* create_cat() { 
    char cat_name[SIZE];
    char buffer[SIZE];
    int i, j;

    if(confirm() == FALSE) {
        exit(1);
    }
    printf("enter a category name without '.txt'\n\t- ");
    my_scanf(cat_name);
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
    CLOSE_FILE;
}

// удаление категории 40m
void delete_cat(char *fileN) {

}

//reverse string
void reverse(char s[]) { 
    int i, j;
    char c;
    
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// int to char
void itoc(int num, char str[]) { 
    int i, sign;
    i = 0;

    if ((sign = num) < 0) { /* записываем знак */
        num = -num;          /* делаем n положительным числом */
    }

    do {       /* генерируем цифры в обратном порядке */
        str[i++] = num % 10 + '0';   /* берем следующую цифру */
    } while ((num /= 10) > 0);     /* удаляем */

    if (sign < 0) {
        str[i++] = '-';
    }
    str[i] = '\0';
    reverse(str);
}

// подсчет строк в файле
int counting(const char* f_name, int n, char* buf, int len){
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
    CLOSE_FILE;

    return (int)(*buf != '\0');
}

// показать все пароли из файла
void show_the_list() {
    int i = 0;
    int j = 1;
    char c;
    char line[SIZE];
    char buffer[SIZE];
    DIR *list_dir;
    struct dirent *dir;

    if(!confirm()) {
        exit(1);
    }
    
    list_dir = opendir(path);
    while ((dir = readdir(list_dir)) != NULL) {
        if(strlen(dir->d_name) > 2) { // if dirname > 3 то не будут показаны . и .. 
            memcpy(buffer, path, 22); // копирование path в buffer 
            AWE = fopen(strcat(buffer, dir->d_name), "r"); 
            printf("\n%s\n", dir->d_name);
            
            while(fscanf(AWE, "%s", line) != EOF) {
                printf("[%d] %s\n",j++, line);
            }
            i = 1;
            printf("\n+------------------------------------+\n");
        }
    } 
    closedir(list_dir);
}
// СДЕЛАТЬ СОХРАНИНЕ ЗАПИСИ В ВИДЕ PANTHAMA:PASSWORED а выводить добавляя цифру = 1)poanthamima:bebra

// создание строки для записи в файл
void prepare_string(char path_file[SIZE], char symbol) { 
    AWE = fopen(path_file, "r");
    if(AWE == NULL) {
        printf("file doesnt exist\n");
        exit(1);
    }
    char buffer[SIZE];
    scanf("%255s", &buffer);
    fprintf(AWE, "%s%c", buffer, symbol);
    CLOSE_FILE;
}

// добавление строки в файл
void addition() { // если нажать пробел запись багается
    char filename[SIZE];
    show_dir();
    printf("enter filename\n\t- ");
    scanf("%s", &filename);
    strcat(path, filename);

    printf("Enter login\n\t- ");
    prepare_string(path, ':');

    printf("Enter password\n\t- ");
    prepare_string(path, '\n');
}

// удалить все пароли
void shred() {
    // need fix!!
    char answer;
    printf("do you really want to delete passwords?[y/n] ");
    answer = getchar();
    if(answer == 'Y' || answer == 'y') {
        // printf("passwords in %s", fn);
        // showTheList();
        // if(confirm() == TRUE) {
        //     AWE = fopen(fn, "w");
        //     CLOSE_FILE;
        // } 
        exit(1);
    }
}

void tmp_stor(FILE *name, FILE *output, char *file_way, char* mode) {
    name = fopen(file_way, mode);

    while(!feof(name)) {
        if((fgets(ch_buf, 256, AWE) != NULL) && lines != d) {
            fprintf(TEMP, "%s", ch_buf);
        }
        lines++;
    }

    fclose(name);
}

// удалить выбранную запись
void removing() { // брать слово вычитать все символы до последних четырех , если она равно .txt то SUCCESS
    char filename[SIZE];
    char ext[] = ".txt";    
    char ch_buf[256];

    unsigned lines = 1;
    int i,j,k;
    int d = 0;
    i = j = k = 0;

    show_dir();
    printf("enter file where delete\n\t- ");
    scanf("%s", filename);

    AWE = fopen(strcat(path, filename), "r");
    if(!AWE) {
        printf("Error: file doesn't exist\n");
        exit(1);
    }

    printf("Enter number of line\n\t- ");
    scanf("%d", &d);
  
    TEMP = fopen(temp_buffer, "a");
    while(!feof(AWE)) {
        if((fgets(ch_buf, 256, AWE) != NULL) && lines != d) {
            fprintf(TEMP, "%s", ch_buf);
        }
        lines++;
    }

    // AWE = freopen(path, "w", stdout);

    // while(!feof(TEMP)) {
        // if(fgets(ch_buf, 256, TEMP) != NULL) {
            // fprintf(AWE, "%s", ch_buf);
        // }
        // lines++;
    // }
    printf("eee");

    TEMP = freopen(temp_buffer, "w", stdout);
    fclose(TEMP);
    CLOSE_FILE;    
    // закидывать все во временный файл читать по строкам -> нужную удалять остальное возвращать tmpfile create !! не знабыть что хтел ептааа
}

// генерирует случайный пароль
int random_pass() {
    int pass_len = 24;
    char rand_ch, rand_pass[23];
    char pool[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

    srand(time(NULL));
    for(int i = 0; i < pass_len; i++) {
        rand_ch = rand()%62;
        rand_pass[i] = pool[rand_ch];
    }
}

// развертка структуры приложения
void init_struct() {
    DIR *list_dir;
    struct dirent *dir;
    list_dir = opendir("__awebase/categories/");
    if(list_dir == NULL) {
        system("mkdir -p __awebase/categories");
    }
}

// показать сществующие категории
void show_dir() { // for windows https://learnc.info/c/libuv_directories.html
    DIR *list_dir;
    struct dirent *dir;
    list_dir = opendir("__awebase/categories/");

    if (list_dir) {
        while ((dir = readdir(list_dir)) != NULL) {
            if(strlen(dir->d_name) > 3) { // if dirname > 3 то не будет показаны 
                printf("-- %s\n", dir->d_name); // функции выхода  из директории . и ..
            }
        }
        closedir(list_dir);
    }
}

// выдача информации о записи (строке)
void extradition() {
    unsigned line;
    char entry[SIZE];
    char category[SIZE];

    system("clear");

    if(confirm() == FALSE) {
        exit(1);
    }

    show_dir();
    printf("enter category name: ");
    scanf("%s", &category);
    strcat(path, category);
    if(!(AWE = fopen(path, "r"))) {
        printf("error. the category doesn't exist\n");
        exit(1);
    }
    printf("enter number of entry: ");
    scanf("%d", &line);

    counting(path, line-1, entry, sizeof(entry));
    puts(entry);
    CLOSE_FILE;
}