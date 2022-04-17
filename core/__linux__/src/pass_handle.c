#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#include "../include/global.h"
#include "../include/defs.h"
#include "../include/pass_handle.h"

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

void hide_pass() {
    run();
}

int getchar_supressed(void) {
  int return_value = 0;
  int error_code = 0;
  int ch = 0;
  
  struct termios x_old;
  struct termios x_new;
  
  do {
    memset(&x_old, 0, sizeof(x_old));
    memset(&x_new, 0, sizeof(x_new));
    
    /* getting current terminal settings */
    return_value = tcgetattr(STDIN_FILENO, &x_old);
    if (error_code != 0) {
      return_value = -1;
      break;
    }
    
    memcpy(&x_new, &x_old, sizeof(x_new));
    
    /* suppressing echoing of input to output, likely dropping canonical as
    well */
    x_new.c_lflag &= ~ECHO;
    x_new.c_lflag &= (~ICANON);
    
    /* applying new settings with suppression */
    error_code = tcsetattr(STDIN_FILENO, TCSANOW, &x_new);
    if (error_code != 0) {
      return_value = -1;
      break;
    }
    
    /* reading symbol */
    ch = getchar();
    
    /* restoring old settings */
    error_code = tcsetattr(STDIN_FILENO, TCSANOW, &x_old);
    if (error_code != 0) {
      return_value = -1;
      break;
    }
    
    return_value = ch;
  }
  while (0);
  
  return return_value;
}
 
 
int get_password(char* const pszBuffer, const int nBufferLength) {
  int return_value = 0;
  int error_code = 0;
  int N = 0;
  
  char* pszTemp = NULL;
  
  const char chBackspace = 127;
  const char chReturn = 10;
  
  unsigned char ch = 0;
  
  /* allocating temp buffer to store password */
  pszTemp = malloc(nBufferLength * sizeof(*pszTemp));
  if (pszTemp == NULL) {
    error_code = -1;
  } 
  
  while ((error_code != -1) && (ch != chReturn)) {
    /* trying to read character from stdin with suppression */
    error_code = getchar_supressed();
    if (error_code != -1) {
      /* we actually read something valid */
      ch = error_code;
      
      if (ch == chBackspace) {
        if (N != 0) {
          printf("\b \b");
          N--;
        }
      }
      else if (ch == chReturn) {
        /* string input is complete */
        pszTemp[N] = '\0';
        N++;
        printf("\n");
      }
      else {
        pszTemp[N] = ch;
        printf("*");
        N++;
      }
    }
  } 
   
  if (error_code != -1) {
    /* no error occured -- we can export read string */
    strncpy(pszBuffer, pszTemp, nBufferLength);
    pszBuffer[nBufferLength - 1] = '\0';
  }
  else {
    return_value = 1;
  }
  
  free(pszTemp);
  pszTemp = NULL;
  
  return return_value;
}
 
void run(void) {
  char sz_pass[256];
  printf("Enter password:\n");
  get_password(&sz_pass[0], sizeof(sz_pass));
  printf("pass:\n%s\n", sz_pass);
}