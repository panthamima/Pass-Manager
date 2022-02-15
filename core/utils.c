#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

FILE *AWE;
extern char *fn;


char* removeXChar(char* str) {
    char* temp = str;
    char* add, *buffer;
    for(add = str, buffer = str; *buffer = *add; *add++) {
        if(isalnum(*add))
            *buffer++;
        }
    return temp;
}

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

void reverse(char s[]) { 
    int i, j;
    char c;
    
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

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