#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "passwd.h"
#include "cli.h"

FILE *AWE;
char fn[] = "base.db";
char mf[] = "../awebase/mas.txt";

int randomPass() {
    int i;
    int passLen = 24;
    char randPass[23];
    char randCh;
    char pool[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

    srand(time(NULL));
    for(i = 0; i < passLen; i++) {
        randCh = rand()%62;
        randPass[i] = pool[randCh];
    }
}

void masterSeed() { 
    char answer;
    char masterPass[SIZE], 
         reMasterPass[SIZE];
    system("clear");

    AWE = fopen(mf, "a+"); 
    fseek(AWE, 0, SEEK_END);
    long pos = ftell(AWE);

    if(pos > 0) {
        printf("the password already exists. change password?[y/n]\n");
        answer = getchar();
        if(answer == 'Y' || answer == 'y') {
            if(confirm() == FALSE) {
                exit(1);
            }
            AWE = fopen(mf, "w");
        }
        else {
            printf("Canselling...\n");
            exit(1);
        }
    }
    //awestruck
    printf("%sHello in Awestruck! \nEnter a master password: ~$ ", logotype);
    scanf("%s", &masterPass);

    if(masterPass != NULL) {
        printf("confirm your master password: ");
        scanf("%s", &reMasterPass);
        if(strcmp(masterPass, reMasterPass) == 0) {
            printf("the password has been saved.\n");
            fputs(reMasterPass, AWE);
        }
        else {
            printf("Error: Passwords don't match.\n");
            exit(1);
        }
    }
}

int main() {

}