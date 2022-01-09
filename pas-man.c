#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int main(void)
{
    FILE *pm; // pass-manager
    int id = 0; 
    char corp[255];
    char pass[255];

    char filename[] = "p.txt";
    if((pm = fopen(filename, "a")) == NULL) {
        printf("error");
    }
    
    fgets(corp,100 ,stdin);
    fputs(corp, pm);

    fgets(pass,100 ,stdin);
    fputs(pass, pm);


    /*
        fegts[s] [s] [s]
            where(storage s s s )
            fputs(id:s:s)
    */

    // char filename[] = "p.txt";
    // if((pm = fopen(filename, "a")) == NULL) {
    //     printf("error");
    // }

    // char command[10];

    // system("clear");
    // printf("enter command: ");
    // scanf("%c", &command);
    // if(command == "r") {
    //     // pm = fopen(filename, "a");
    //     printf("enter corp name: ");
    //     fgets(corp, 39, stdin);
    //     fputs(corp, pm);
    //     fclose(pm);
    // }
    // unsigned int key = 0;
    // fgets(message, 221, stdin);
    // fputs(message, pm);
    // fclose(pm);

    // return 0;
}

