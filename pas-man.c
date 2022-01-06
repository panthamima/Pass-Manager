#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int main(void)
{
    FILE *pm;
    char corp[40];
    char pass[40];
    char message[222];
    
    

    char filename[] = "p.txt";
    if((pm = fopen(filename, "a")) == NULL) {
        printf("error");
    }

    int command;
    printf("enter command: ");
    scanf("%d", &command);
    if(command == 1) {
        printf("enter corp name: ");
        fgets(corp, 39, stdin);
        fputs(corp, pm);
        fclose(pm);
    }
    unsigned int key = 0;
    // fgets(message, 221, stdin);
    // fputs(message, pm);
    // fclose(pm);

    return 0;
}

