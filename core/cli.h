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

char help[] = "                               \
\ngetting started with awestruck\n\t          \
reg\tcreate a master password\n\n             \
work with entries\n\t                         \
add\tadding an entry\n\t                      \
rem\tdeleting an entry\n\t                    \
get\tgetting information about an entry\n\t   \
edit\tedit an entry\n\n                       \
global actions\n\t                            \
list\tshow the full list of entries\n\t       \
rem+\tdeleting category or all entries\n\n    ";

void prepareString(); 	    // создание строки для записи в файл
void addition();		        // добавление строки в файл
int  counting();            // подсчет строк
void extradition();         // выдача информации о записи (строке)
void logging();             // создание мастер аккаунта
void removing();            // удаление записи из файла
void showTheList();         // показать все пароли из файла
void shred();               // удалить все пароли
void iToc(int n, char s[]); // int to char
void reverse(char s[]);     // reverse string
int randomPass();           // создание случайного пароля
void masterSeed();          // создание мастер пароля
int confirm();              // подтверждение мастер пароля
void createCat();           // создание категории

#endif