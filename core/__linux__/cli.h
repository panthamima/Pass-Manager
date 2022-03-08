#ifndef CLI_H
#define CLI_H

#define SIZE 256
#define FALSE 0
#define TRUE 1
#define CLOSE_FILE fclose(AWE)

char logotype[] = "                                                              \n\
   ▄▄▄     █     █░▓█████   ██████ ▄▄██████▓ ██▀███   █    ██  ▄ █▓█    ██ ▄█▀   \n\
  █▓ ▓█▄  ▓█░ █ ░█░▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒▓██ ▒ ██▒ ██  ▓██▒▒██  ▀█   ██▄█▒    \n\
▒██   ▀█▄ ▒█░ █ ░█ ▒███   ░ ▓██▄   ▒ ▓██░ ▒░▓██ ░▄█ ▒▓██  ▒██░▒▓█      ▓███▄░    \n\
░██▄▄▄▄██ ░█░ █ ░█ ▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ ▒██▀▀█▄  ▓▓█  ░██░▒▓▓▄ ▄  ▒▓██ █▄    \n\
 ▓█   ▓██▒░░██▒██▓ ░▒████▒▒██████▒▒  ▒██▒ ░ ░██▓ ▒██▒▒▒█████▓ ▒ ▓▒▒█▀ ░▒██▒ █▄   \n\
 ▒    ▓▒ ░░ ▓░▒ ▒  ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░   ░ ▒  ░▒▓░ ▒▓▒ ▒ ▒ ░ ░▒ ▒  ░▒ ▒   ▒   \n\
  ▒   ▒  ░  ▒   ░   ░ ░  ░  ░   ░ ░    ░      ░▒ ░ ▒    ░ ░ ░   ░  ▒   ░ ░  ▒░   \n\
  ░         ░         ░   ░  ░  ░    ░        ░    ░  ░     ░        ░  ░        \n\n";

char help[] = " getting started with awestruck\n\t\
 reg\tcreate a master password\n\n\
 work with entries\n\t\
 add\tadding an entry\n\t\
 rem\tdeleting an entry\n\t\
 get\tgetting information about an entry\n\t\
 edit\tedit an entry\n\n\
 global actions\n\t\
 list\tshow the full list of entries\n\t\
 rem+\tdeleting category or all entries\n\t\
 cat\tcreating a new category\n\n";

void   prepare_string(char pathfile[SIZE], char symbol); // создание строки для записи в файл
void   addition();		           // добавление строки в файл
void   extradition();            // выдача информации о записи (строке)
void   removing();               // удаление записи из файла
void   show_the_list();            // показать все пароли из файла
void   shred();                  // удалить все пароли
void   itoc(int n, char s[]);    // int to char
void   reverse(char s[]);        // reverse string
void   my_scanf(char *string);     // scanf
int    random_pass();             // создание случайного пароля
void   master_seed();             // создание мастер пароля
int    confirm();                // подтверждение мастер пароля
char   *create_cat();             // создание категории
void   delete_cat(char *fileN);   // удаление категории
char   *remove_x_char(char* str);  // удаление запрещенного символа из массива
void   init_struct();             // развертка структуры программы
void   show_dir();                // показывает все существующие категории 
void   handler_io(char *filename, char *crypt_action);

#endif