#include "cli.h"

#define SIZE 255

FILE *AWE;
char fn[] = "base.db";

int main(int argc,char **argv){

    if(!strcmp(argv[1], "reg")) {
        ownPassCreate();
    }
    else if(!strcmp(argv[1], "add")) {
        addition();
    }
    else if(!strcmp(argv[1], "rem")) {
        removing();
    }
    else if(!strcmp(argv[1], "get")) {
        extradition();
    }
    else if(!strcmp(argv[1], "shw")) {
        showTheList();
    }
    else if(!strcmp(argv[1], "rem+")) {
        shred();
    }
    else if(!strcmp(argv[1], "rem+")) {

    }
    else if(!strcmp(argv[1], "help")) {
        
    }
    else {
        printf("<ERROR> enter command like: awestruck reg|add|rem|get\n");
    }

}

void ownPassCreate() {
    printf("Hello! Enter a master password: ");
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
    char lineChar[32];
    char charCount; // счетчик чаров

        AWE = fopen(fn, "r+");
    do {
        fputs("1:", AWE);
        lineID++;
    } while (lineID == 0);
    
    for (charCount = getc(AWE); charCount != EOF; charCount = getc(AWE)){
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
    scanf("%255s", buffer);
    fputs(buffer, AWE);
}

// добавление строки в файл
void addition() { // если нажать пробел запись багается
    AWE = fopen(fn, "a");
    
    counting();

    printf("Enter login\n\t- ");
    prepareString();
    fputc(':', AWE);

    printf("Enter password\n\t- ");
    prepareString();
    fputc('\n', AWE);
    
    fclose(AWE);
}


void shred() {

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
    // printf("%s\n", randPass);
}

// выдача информации о записи (строке)
void extradition() { 
    printf("");
}