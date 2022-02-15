#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>

#include "cli.h"
#include "xorplus.h"
#include "passwd.h"

FILE *AWE;
char fn[] = "base.db";
char mf[] = "../awebase/mas.txt";

int main(int argc,char **argv){

    /****/ if (!strcmp(argv[1], "reg")) {
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
        initStruct();
    } else if (!strcmp(argv[1], "help")) {
        system("clear");
        printf("%s", help);
    } else if(!strcmp(argv[1], "cat")) {
        createCat();
    } else {
        printf(":ERROR COMMAND: enter awe help\n");
    }
}

// создание мастер пароля


// подтверждение мастер пароля
int confirm() {
    char pasConfirm[SIZE], buffer[SIZE];
    int i;

    AWE = fopen(mf, "r+");
    fseek(AWE, 0, SEEK_END);
    long pos = ftell(AWE);

    if(pos > 0) {
        AWE = fopen(mf, "r+");
        printf("Enter master password to confirm: ");
        scanf("%s", &pasConfirm);
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

void initStruct() {
    
}
// создание категории
char* createCat() {
    char catName[SIZE];
    char buffer[SIZE];
    int i, j;

    if(confirm() == TRUE) {
        printf("enter a category name without a special symbols(#/.&! etc)\n\t- ");
        scanf("%s", &catName);

        removeXChar(catName);
        printf("%s.txt - name of category\n", catName);
        AWE = fopen(strcat(catName, ".txt"), "a");
        fclose(AWE);
    } // не записывается пробел, нет проверки на существование файла
    exit(1);
}

// подсчет строк в файле
int counting() { 
    int lineID = 0;
    char lineChar[32]; // максиальный размер id строки
    char charCount; // счетчик символов

    AWE = fopen(fn, "r+");
    do {
        fputs("1:", AWE);
        lineID++;
    } while (lineID == 0);
    
    for (charCount = getc(AWE); charCount != EOF; charCount = getc(AWE)) {
        if (charCount == '\n') {
            lineID += 1;
            iToc(lineID, lineChar);
            fputs(lineChar, AWE);
            fputc(':', AWE);
        }
    }
}

// показать все пароли из файла
void showTheList() {
    char charCount; // счетчик чаров
    if (AWE = fopen(fn, "r+")) {
        printf("\n");
        for (charCount = getc(AWE); charCount != EOF; charCount = getc(AWE)){
            printf("%c", charCount);
        }
        printf("\n");
    }
}

// создание строки для записи в файл
void prepareString() { 
    char buffer[SIZE];
    scanf("%255s", &buffer);
    fputs(buffer, AWE);
}

// добавление строки в файл
void addition() { // если нажать пробел запись багается
    AWE = fopen(fn, "a");
    
    counting();

    printf("Enter login\n\t- ");
    prepareString();
    fputc(' ', AWE);

    printf("Enter password\n\t- ");
    prepareString();
    fputc('\n', AWE);
    
    fclose(AWE);
}

// удалить все пароли
void shred() {
    char answer;
    printf("do you really want to delete passwords?[y/n] ");
    answer = getchar();
    if(answer == 'Y' || answer == 'y') {
        printf("passwords in %s", fn);
        showTheList();
        if(confirm() == TRUE) {
            AWE = fopen(fn, "w");
            fclose(AWE);
        }
        exit(1);
    }
}

void removing() {

}

// выдача информации о записи (строке)
void extradition() { 

}