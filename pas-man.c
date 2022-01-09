#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

int main(void)
{
    FILE *pm; // pass-manager
    int id = 0; 
    char corp[256];
    char pass[256];
    char str[256];
    // int command[] = {1, // addition
    //                  2, // remove
    //                  3, // re-addition
    //                  4, // shred
    //                  5};// add existing file

    char filename[] = "p.txt";
    if((pm = fopen(filename, "a")) == NULL) {
        printf("error");
    }

    printf("1[add]\n2[show passwords]\n3[remove]\n4[rename corp or pass]\n5[shred]\n6[add an existing file]\n\nenter command:: ");
    int token = getchar();
    if(token == '1') {
        printf("enter corp name: ");
        fgets(corp, 255, stdin);
        fputs(corp, pm);

        printf("enter password: ");
        fgets(pass, 255, stdin);
        fputs(pass, pm);

        fclose(pm);
    }
    // if((pm = fopen(filename, "a")) != NULL) {
    //     // fgets(str, 255, stdin);
    //     fscanf(pm, "%d:%d", &corp,&pass);
    //     fputs(str, pm);
    //     fclose(pm);
    // }

    


    // fgets(corp, 100 ,stdin);
    // fputs(corp, pm);

    // fgets(pass,100 ,stdin);
    // fputs(pass, pm);


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

