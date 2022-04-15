#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "../include/global.h"
#include "../include/defs.h"
#include "../include/pass_handle.h"

// генерирует случайный пароль
char *random_pass(char *password) {
    int pass_len = 24;
    char rand_ch;
    char pool[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

    srand(time(NULL));
    for(int i = 0; i < pass_len; i++) {
        rand_ch = rand()%62;
        *password++ = pool[rand_ch]; 
    }
}

// создание мастер пароля
// запрашивать имя пользвоателя if linux /home/..../init_struct
// else C:/programfiles/initstruct
void master_seed() { 
    char answer;
    char master_pass[SIZE], 
         re_master_pass[SIZE];
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
            AWE = fopen(mf, "w"); // 
        }
        else {
            printf("Canselling...\n");
            exit(1);
        }
    }
    //awestruck
    awe_print_logo();
    printf("Enter the master password:~# ");
    scanf("%s", &master_pass);


    if(master_pass != NULL) {
        printf("confirm your master password: ");
        scanf("%s", &re_master_pass);
        if(strcmp(master_pass, re_master_pass) == 0) {
            printf("the password has been saved.\n");
            // caeXorEnc(re_master_pass, "asd");
            fputs(re_master_pass, AWE);
        }
        else {
            printf("Error: Passwords don't match.\n");
            exit(1);
        }
    }
}

// подтверждение мастер пароля
int confirm() {  // сделать количество попыток
    char pas_confirm[SIZE], buffer[SIZE];
    int i;
    AWE = fopen(mf, "r");
    if(!AWE) {
        AWE = fopen(mf, "w+");
    }
    fseek(AWE, 0, SEEK_END);
    long pos = ftell(AWE);

    if(pos > 0) {
        AWE = fopen(mf, "r+");
        printf("Enter master password to confirm: ");
        scanf("%s", pas_confirm);
        fgets(buffer, SIZE, AWE);
        if(strcmp(pas_confirm, buffer) == 0) {
            printf("Success.\n");
            return TRUE;
        }
        printf("passwords are not match. Cancelling...\n");
        return FALSE;
    } 
    printf("Enter awestruck reg, and create password\n");
    return FALSE;
}