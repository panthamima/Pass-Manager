#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

#define SIZE 256

FILE *PM; // Password-Manager
char fn[] = "manager.db";

void prepareString() { // создание строки для записи в файл
    char buffer[SIZE];

    fgets(buffer, 255, stdin);
    scanf("%s", buffer);
    fputs(buffer, PM);
}

void addition() { // добавление строки в файл
    printf("enter login: ");
    prepareString();
    fputs(":", PM);

    printf("enter password: ");
    prepareString();

    fputs("\n", PM);
    fclose(PM);

}

void pasRemove() { // удаление строки из файла

}

void formatting() { // форматирование базы данных
	char sym[SIZE];
    int c = 0;
    int id = 1;

    PM = fopen("p.txt", "r");
    while((c = fgetc(PM)) != EOF) {
        if(c == '\n') {
            id++;
        }
    }
}

void showList() { // показать весь файл с паролями

}

int main() { 
    int command = getchar();

    if(command == '1') {
        PM = fopen(fn, "a");
        addition();

    }

}