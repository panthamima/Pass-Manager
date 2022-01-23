#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

#define N 256

FILE *pm; // pass-manager
char line[N];
char filename[] = "p.txt";

void format();
void show();
int addition(); 
void show();
void shred();

int main() {
    int id = 0; 
    char enter = '\n';

    char filename[] = "p.txt";
    if((pm = fopen(filename, "a")) == NULL) {
        printf("error");
    }

    printf("1[add]\n2[show passwords]\n3[remove]\n4[rename login or pass]\n5[shred]\n6[add an existing file]\n\nenter command: ");
    int token = getchar();
    if(token == '1') {
        printf("enter login: ");
        format();
        fputs(":", pm);

        printf("enter password: ");
        format();

        fputs("\n", pm);
        fclose(pm);
    }
}

void format() { // функция вставляющая форматированную строку в файл
    char info[256];

    fgets(info, 255, stdin);
    scanf("%s", info);
    fputs(info, pm);
}

int addition() { // добавление в файл
    printf("enter login: ");
    format();
    fputs(":", pm);

    printf("enter password: ");
    format();

    fputs("\n", pm);
    fclose(pm);
}

void show() { // 
    pm = fopen(filename, "r");
	char sym[N], c = 0;
	while( (c = fgetc(pm)) != EOF) {
		printf("%c", c);
	}
    printf("\n");
}

void shred() {
    pm = fopen(filename, "w");
    fclose(pm);
}
