#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>


FILE *pm; // pass-manager

void format();

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

void format() {
    int id = 0; 
    char info[256];
    char str[256];
    char colon = ':';

    fgets(info, 255, stdin);
    scanf("%s", info);
    fputs(info, pm);
}