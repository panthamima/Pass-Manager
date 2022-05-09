#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#include "../include/global.h"
#include "../include/defs.h"
#include "../include/tools.h"
#include "../include/pass_handle.h"
#include "../crypt/sha256.h"

// генерирует случайный пароль
char* random_pass(char *password) {
    int pass_len = 24;
    char rand_ch;
    char pool[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

    srand(time(NULL));
    for(int i = 0; i < pass_len; i++) {
        rand_ch = rand()%62;
        *password++ = pool[rand_ch]; 
    }
    sha256(password);
}

// void get_pass(char* password) {
    
// }

// создание мастер пароля
// запрашивать имя пользвоателя if linux /home/..../init_struct
// else C:/programfiles/initstruct
void master_seed() { 
    char answer[2];
    char path[SIZE];
    char master_pass[SIZE], 
         re_master_pass[SIZE];
    get_path(path, master);
    init_struct();
    
    AWE = fopen(path, "a+"); 
    fseek(AWE, 0, SEEK_END);
    long pos = ftell(AWE);

    if(pos > 0) {
        get_line("[!] The password already exists. Change password?[y/n] ", answer, 2);
        if(answer[0] == 'Y' || answer[0] == 'y') {
            if(confirm() == FALSE) {
                fclose(AWE);
                exit(1);
            }
            AWE = fopen(path, "w");
        }
        else {
            printf(TCOLOR_R"[×]%s Aborted...\n", TCOLOR_RESET);
            exit(1);
        }
    }
    //awestruck
    awe_print_logo();
    printf("Enter the master password:~# ");
    hide_pass(master_pass);
    sha256(master_pass);

    if(master_pass != NULL) {
        printf("Confirm your master password: ");
        hide_pass(re_master_pass);
        sha256(re_master_pass);
        if(!memcmp(master_pass, re_master_pass, strlen(master_pass))) {
            printf(TCOLOR_G"[✔]%s The password has been saved.\n", TCOLOR_RESET);
            fputs(re_master_pass, AWE);
        }
        else {
            printf(TCOLOR_R "[×]%s Error: Passwords don't match.\n", TCOLOR_RESET);
            exit(1);
        }
    }
}

// подтверждение мастер пароля
int confirm() {  // сделать количество попыток
    char pas_confirm[SIZE], buffer[SIZE], path[SIZE];
    char* out;
    get_path(path, master);
    static unsigned int requests = 0;

    if(requests > 0) {
        return TRUE;
    }

    AWE = fopen(path, "r");
    if(!AWE) {
        AWE = fopen(path, "w+");
    }
    fseek(AWE, 0, SEEK_END);
    long pos = ftell(AWE);

    if(pos > 0) {
        AWE = fopen(path, "r+");
        printf("Enter master password to confirm: ");
        hide_pass(pas_confirm);
        sha256(pas_confirm);
        fgets(buffer, SIZE, AWE);
        if(!memcmp(pas_confirm, buffer, strlen(buffer))) {
            printf("Success.\n");
            requests += 1;
            return TRUE;
        }
        printf(TCOLOR_R "[×]%s Passwords are not match. Cancelling...\n", TCOLOR_RESET);
        return FALSE;
    } 
    printf(TCOLOR_R "[×]%s Enter awe init, and create password\n", TCOLOR_RESET);
    return FALSE;
}

void hide_pass(char* buffer) {
    char sz_pass[256];
    hide_password(&sz_pass[0], sizeof(sz_pass));
    for(int i = 0; i < strlen(sz_pass); i++) {
        buffer[i] = sz_pass[i];
    }
}