#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <ncurses.h>
// #include <ctype.h>
// #include <math.h>

#define SIZE 255

// enum { g, c, d };

void prepareString(); 	// создание строки для записи в файл
void addition();		// добавление строки в файл
int  counting();        // подсчет строк
void extradition();     // выдача информации о записи (строке)
void logging();         // создание мастер аккаунта
void removing();
void showTheList();

FILE *AWE;
char fn[] = "base.db";

int main(int argc,char **argv){

    if(!strcmp(argv[1], "")) {
        addition();
    }
    else if(!strcmp(argv[1], "reg")) {
        logging();
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
    else {
        printf("<ERROR> enter command like: awestruck reg|add|rem|get\n");
    }

	return 0;
}

void logging() {
    addition();
}

void reverse(char s[]) { //reverse string
    int i, j;
    char c;
    
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void itoa(int n, char s[]) { // int to char
    int i, sign;

    if ((sign = n) < 0)  /* записываем знак */
        n = -n;          /* делаем n положительным числом */
    i = 0;
    do {       /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0';   /* берем следующую цифру */
    } while ((n /= 10) > 0);     /* удаляем */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int counting() { // подсчет строк в файле
    int lineID = 0;
    char lineCh[32];
    char chCnt; // счетчик чаров

    AWE = fopen(fn, "r+");
    
    fseek(AWE, 0, SEEK_END);
    unsigned pos = ftell(AWE);    
    if(pos == 0){
        fputs("0:", AWE);
    }
    for (chCnt = getc(AWE); chCnt != EOF; chCnt = getc(AWE)){
        if (chCnt == '\n') {
            lineID += 1;
            itoa(lineID, lineCh);
            fputs(lineCh, AWE);
            fputc(':', AWE);
        }
    }
}

void showTheList() {
    char chCnt; // счетчик чаров
    if (AWE = fopen(fn, "r+")) {
        printf("\n");
        for (chCnt = getc(AWE); chCnt != EOF; chCnt = getc(AWE)){
            printf("%c", chCnt);
        }
        printf("\n");
    }

}


void prepareString() { // создание строки для записи в файл
    char buffer[SIZE];
    scanf("%255s", buffer);
    fputs(buffer, AWE);
}

void addition() { // добавление строки в файл
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

void removing() {

}


void extradition() { // выдача информации о записи (строке)
    printf("");
}