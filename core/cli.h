#ifndef CLI_H
#define CLI_H

#define SIZE 256
#define FALSE 0
#define TRUE 1

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
 rem+\tdeleting category or all entries\n\n";

void prepareString(); 	      // создание строки для записи в файл
void addition();		          // добавление строки в файл
void extradition();           // выдача информации о записи (строке)
void removing();              // удаление записи из файла
void showTheList();           // показать все пароли из файла
void shred();                 // удалить все пароли
void iToc(int n, char s[]);   // int to char
void reverse(char s[]);       // reverse string
int randomPass();             // создание случайного пароля
void masterSeed();            // создание мастер пароля
int confirm();                // подтверждение мастер пароля
char* createCat();            // создание категории
char* removeXChar(char* str); // удаление запрещенного символа из массива
void initStruct();            // развертка структуры программы


#endif