#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>


FILE *pm; // pass-manager

void format();

int main() {
    int id = 0; 
    // char corp[256];
    // char pass[256];
    // char str[256];
    char enter = '\n';
    // int command[] = {1, // addition
    //                  2, // remove
    //                  3, // re-addition
    //                  4, // shred
    //                  5};// add existing file

    char filename[] = "p.txt";
    if((pm = fopen(filename, "a")) == NULL) {
        printf("error");
    }

    printf("1[add]\n2[show passwords]\n3[remove]\n4[rename corp or pass]\n5[shred]\n6[add an existing file]\n\nenter command: ");
    int token = getchar();
    if(token == '1') {
        // id++;
        // fputs(id, pm);
        printf("enter corp name: ");
        format();
        fputs(":", pm);

        printf("enter password: ");
        format();

        fputs("\n", pm);
        fclose(pm);
    }

        // fgets(corp, 255, stdin);
        // scanf("%s:", corp);

        // fgets(pass, 255, stdin);
        // scanf("%s", pass);
        // fputs(corp, pm);
        // fputs(pass, pm);


}

void format() {
    int id = 0; 
    char info[256];
    // char pass[256];
    char str[256];
    char colon = ':';

    fgets(info, 255, stdin);
    scanf("%s", info);
    fputs(info, pm);

    // fgets(pass, 255, stdin);
    // scanf("%s", pass);
    // fputs(pass, pm);   
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

