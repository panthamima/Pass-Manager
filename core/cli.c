#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "cli.h"
#include "xorplus.h"

FILE *AWE;
char fn[] = "base.db";
char mf[] = "mas.txt";

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
        createCat();
    } else if (!strcmp(argv[1], "help")) {
        system("clear");
        printf("%s", help);
    } else {
        printf(":ERROR COMMAND: enter awe help\n");
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
            AWE = fopen(mf, "w");
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

char* removeXChar(char* str) {
    char* temp = str;
    char* add, *buffer;
    for(add = str, buffer = str; *buffer = *add; *add++) {
        if(isalnum(*add))
            *buffer++;
        }
    return temp;
}

// создание категории
char* createCat() {
    char catName[SIZE];
    char buffer[SIZE];
    char xPool[] = "!@#$%^&*()_+-=\":?/\\{}[]'.,<>~`;|";
    char dotTxt[] = ".txt";
    int i, j;

    if(confirm() == TRUE) {
        printf("enter a category name without a special symbols(#/.&! etc)\n\t- ");
        scanf("%s", &catName);

        removeXChar(catName);
        printf("%s - name of category\n", catName);
        AWE = fopen(strcat(catName, dotTxt), "a");
        fclose(AWE);
    } // не записывается пробел, нет проверки на существование файла
    exit(1);
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
void iToc(int n, char s[]) { 
    int i, sign;
    i = 0;

    if ((sign = n) < 0) { /* записываем знак */
        n = -n;          /* делаем n положительным числом */
    } 
    
    do {       /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0';   /* берем следующую цифру */
    } while ((n /= 10) > 0);     /* удаляем */

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
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

int randomPass() {
    int i;
    int passLen = 24;
    char randPass[23];
    char randCh;
    char pool[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

    srand(time(NULL));
    for(i = 0; i < passLen; i++) {
        randCh = rand()%62;
        randPass[i] = pool[randCh];
    }
}

// выдача информации о записи (строке)
void extradition() { 

}