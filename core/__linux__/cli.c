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

FILE *AWE;
char mf[] = "__awebase/mas.txt";
char path[SIZE] = "__awebase/categories/";

int main(int argc,char **argv){
    initStruct();

    /****/ if (argc < 2) {
        printf("command not found. Enter: awe help\n");
    } else if (!strcmp(argv[1], "reg")) {
        masterSeed();
    } else if (!strcmp(argv[1], "add")) {
        addition();
    } else if (!strcmp(argv[1], "rem")) {
        removing();
    } else if (!strcmp(argv[1], "get")) {
        extradition();
    } else if (!strcmp(argv[1], "list")) {
        showTheList();
    } else if (!strcmp(argv[1], "rem+")) {
        shred();
    } else if (!strcmp(argv[1], "test")) {

    } else if (!strcmp(argv[1], "help")) {
        system("clear");
        printf("%s", help);
    } else if (!strcmp(argv[1], "cat")) {
        createCat(); // добавить проверку на добвление .txt
    } else {
        printf("command not found. Enter: awe help\n");
    }
}

// создание мастер пароля
void masterSeed() { 
    char answer;
    char masterPass[SIZE], 
         reMasterPass[SIZE];
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
    scanf("%s", &masterPass);

    if(masterPass != NULL) {
        printf("confirm your master password: ");
        scanf("%s", &reMasterPass);
        if(strcmp(masterPass, reMasterPass) == 0) {
            printf("the password has been saved.\n");
            fputs(reMasterPass, AWE);
        }
        else {
            printf("Error: Passwords don't match.\n");
            exit(1);
        }
    }
}

// подтверждение мастер пароля
int confirm() {  // сделать количество попыток
    char pasConfirm[SIZE], buffer[SIZE];
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
        scanf("%s", pasConfirm);
        fgets(buffer, SIZE, AWE);
        if(strcmp(pasConfirm, buffer) == 0) {
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
char* removeXChar(char* str) {
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
void myScan(char *string) {
    char c;
    while ((c = getchar()) != '\n') { 
        *string++ = c;
    }
}

// создание категории
char* createCat() { 
    char catName[SIZE];
    char buffer[SIZE];
    int i, j;

    if(confirm() == FALSE) {
        exit(1);
    }
    printf("enter a category name without '.txt'\n\t- ");
    myScan(catName);
    removeXChar(catName);

    if(!strcmp(catName, "")) {
        printf("Error: enter filename\n");
        exit(1);
    }

    strcat(path, catName);
    AWE = fopen(strcat(path, ".txt"), "rb+");
    if(!AWE) {
        AWE = fopen(path, "a");
        printf("%s.txt - name of category\n", catName);
    }
    else {
        printf("ERROR: the file already exists\n");
    }
    CLOSE_FILE;
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
void iToc(int num, char str[]) { 
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
int counting(const char* fname, int n, char* buf, int len){
    char  c;
    FILE* AWE = fopen(fname, "rt");
    if(AWE == NULL)
        return 0;

    while(! feof(AWE) && (n > 0)){
       fscanf(AWE, "%*[^\n\r]%c", &c);
       --n;
    }

    if(! feof(AWE))
        fgets(buf, len-1, AWE);
    else
       *buf = '\0';

    CLOSE_FILE;
    return (int)(*buf != '\0');
}

// показать все пароли из файла
void showTheList() {
    int i = 0;
    int j = 1;
    char c;
    char line[SIZE];
    char buffer[SIZE];
    DIR *listDir;
    struct dirent *dir;

    if(!confirm()) {
        exit(1);
    }
    
    listDir = opendir(path);
    while ((dir = readdir(listDir)) != NULL) {
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
    closedir(listDir);
}
// СДЕЛАТЬ СОХРАНИНЕ ЗАПИСИ В ВИДЕ PANTHAMA:PASSWORED а выводить добавляя цифру = 1)poanthamima:bebra

// создание строки для записи в файл
void prepareString(char pathfile[SIZE]) { 
    AWE = fopen(path, "a"); //pass -> login FIX!!
    if(AWE == NULL) {
        printf("file doesnt exist\n");
        exit(1);
    }
    char buffer[SIZE];
    scanf("%255s", &buffer);
    fputs(buffer, AWE);
}

// добавление строки в файл
void addition() { // если нажать пробел запись багается
    char filename[SIZE];
    showDir();
    printf("enter filename\n\t- ");
    scanf("%s", &filename);
    AWE = fopen(strcat(path, filename), "a");

    printf("Enter login\n\t- ");
    prepareString(path);
    fputc(':', AWE);

    printf("Enter password\n\t- ");
    prepareString(path);
    fputc('\n', AWE);
    
    CLOSE_FILE;
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

// удалить выбранную запись
void removing() { // брать слово вычитать все символы до последних четырех , если она равно .txt то SUCCESS
    char filename[SIZE];
    char ext[] = ".txt";
    showDir();
    printf("enter file where delete\n\t- ");
    myScan(filename);
    reverse(filename);
    if(strncmp(filename, "txt.", 4) != 0) {
        reverse(filename);
    } else {
        reverse(filename);
    }
    AWE = fopen(strcat(path, filename), "r");
    if(!AWE) {
        printf("Error: file doesn't exist\n");
        exit(1);
    }
    AWE = fopen(path, "a");

}

// генерирует случайный пароль
int randomPass() {
    int passLen = 24;
    char randCh, randPass[23];
    char pool[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

    srand(time(NULL));
    for(int i = 0; i < passLen; i++) {
        randCh = rand()%62;
        randPass[i] = pool[randCh];
    }
}

// развертка структуры приложения
void initStruct() {
    DIR *listDir;
    struct dirent *dir;
    listDir = opendir("__awebase/categories/");
    if(listDir == NULL) {
        system("mkdir -p __awebase/categories");
    }
}

// показать сществующие категории
void showDir() { // for windows https://learnc.info/c/libuv_directories.html
    DIR *listDir;
    struct dirent *dir;
    listDir = opendir("__awebase/categories/");

    if (listDir) {
        while ((dir = readdir(listDir)) != NULL) {
            if(strlen(dir->d_name) > 3) { // if dirname > 3 то не будет показаны 
                printf("-- %s\n", dir->d_name); // функции выхода  из директории . и ..
            }
        }
        closedir(listDir);
    }
}

// выдача информации о записи (строке)
void extradition() {
    unsigned line;
    char buffer[SIZE];
    char category[SIZE];

    system("clear");

    if(confirm() == FALSE) {
        exit(1);
    }

    showDir();
    printf("enter category name: ");
    scanf("%s", &category);
    strcat(path, category);
    if(!(AWE = fopen(path, "r"))) {
        printf("error. the category doesn't exist\n");
        exit(1);
    }
    printf("enter number of entry: ");
    scanf("%d", &line);

    counting(path, line-1, buffer, sizeof(buffer));
    puts(buffer);
}