#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

//reverse string
void reverse(char s[]) { 
    int i, j;
    char c;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
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

// создание категории
void validate_txt(char *filename) {
    reverse(filename);
    if(!strncmp(filename, "txt.", 4)) {
        reverse(filename);
    } else {
        strcmp(filename, ".txt");
    }
}
