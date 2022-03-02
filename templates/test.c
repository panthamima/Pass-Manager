    // printf("1[add]\n2[get password]\n3[remove]\n4[rename login or password] \
            // \n6[show password list]\n7[delete file with accounts]\n\n:>> ");
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#include <dirent.h>
WINDOW *mainwin;
 mainwin = initscr();   /* start the curses mode with default window */
 clear()    /* clear the default window */
 raw();     /* stop terminal driver from interpreting key strokes */ 
 cbreak();  /* input chars without waiting for newline */
 
 nodelay( mainwin, true); /* causes getch() to wait for a key rather than returning ERR */
 keypad( mainwin, true ); /* program must handle all meta keys including newline */

 noecho();  /* stop terminal echo while entering password */

 size_t i = 0;
 while( i < (sizeof( pwd ) -1) && ( ch = getch() ) != ENTER )
 {
     pwd[i] = ch;
     i++;

     printw( "*" );
     refresh();
 }

 echo();               /* resume echoing characters on terminal */
 keypad( mainwin, false );      /* stop passing keypad chars to program */
 noraw();              /* terminal driver resumes interpreting key strokes */

 pwd[i] = '\0';        /* NUL terminate the string */   
 endwin();

// #include <stdlib.h>
// #include <stdio.h>
// #include <ncurses.h>
// #include <string.h>
// #include <ctype.h>
// #include "../d_cipher.h"

// #define SIZE 255


// int encrypt();
// int decrypt();

// FILE *PM; // Password-Manager
// char fn[] = "p.txt";

// void prepareString() { // создание строки для записи в файл
//     char buffer[SIZE];

//     fgets(buffer, 255, stdin);
//     scanf("%s", buffer);
//     fputs(buffer, PM);
// }

// void addition() { // добавление строки в файл
//     printf("enter login: ");
//     prepareString();
//     fputs(":", PM);

//     printf("enter password: ");
//     prepareString();

//     fputs("\n", PM);
//     fclose(PM);

// }

// void pasRemove() { // удаление строки из файла

// }

// void formatting() { // форматирование базы данных
// 	char sym[SIZE];
//     int c = 0;
//     int id = 1;

//     PM = fopen("p.txt", "r");
//     while((c = fgetc(PM)) != EOF) {
//         if(c == '\n') {
//             id++;
//         }
//     }
// }

// void showList() { // показать весь файл с паролями

// }

// int main() { 
//     int command = getchar();

//     if(command == '1') {
//         PM = fopen(fn, "a");
//         addition();
//     }
//     else if (command == '2') {
//         encrypt();
//     }

// }
// int main() { 
//     char id[SIZE]; 
//     char enter = '\n';
//     system("clear");
//     printf("1[add]\n2[get password]\n3[remove]\n4[rename login or password] \
//             \n6[show password list]\n7[delete file with accounts]\n\n:>> ");

//     int command = getchar();

//     if(command == '1') { // add
//         addition();
//     } 
//     else if(command == '2') { // get password
//         // shred();
//     } 
// }


// void show() { // 
//     pm = fopen(filename, "r");
// 	char sym[N], c = 0;
// 	while( (c = fgetc(pm)) != EOF) {
// 		printf("%c", c);
// 	}
//     printf("\n");
// }

// int shred() {
//     pm = fopen("p.txt", "a");
// 	char sym[N];
//     int c = 0;
//     int id = 1;

//         pm = fopen("p.txt", "r");
//     while((c = fgetc(pm)) != EOF) {
//         if(c == '\n') {
//             id++;
//         }
//     }
//         printf("%d", id);
//     // while( !feof(pm)){
//     //     fscanf(pm,"%s",sym);
//     //     id = (strlen(sym));
//     //     printf("%c %c ", sym[0], sym[id-1]);
//     // }
//     	// 	file = fopen("p.txt", "r");
// 	// while( !feof(file)){
// 	// 	fscanf(file,"%s",sym);
// 	// 	i = (strlen(sym));
// 	// 	printf("%c  %c     ", sym[0], sym[i-1]);
// }



// int addition() {

// 		// pm = fopen("p.txt", "r");
// 		// while( !feof(pm)){
// 		// fscanf(pm,"%s",str);
// 		//  = (strlen(str));
// 		// printf("%c  %c     ", sym[0], sym[i-1]);

//         printf("enter login: ");
//         format();
//         fputs(":", pm);

//         printf("enter password: ");
//         format();

//         fputs("\n", pm);
//         fclose(pm);
// }

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


//reading file + first and last char on the line
// #define N 200
// int test(void) {
// 	int i = 0;
// 	FILE *file;
// 	file = fopen("p.txt", "r");
// 	char sym[N], c = 0;
// 	while( (c = fgetc(file)) != EOF){
// 		printf("%c", c);
// 	}
//     fclose(file);
// 	printf("\n");
// 	file = fopen("p.txt", "r");
// 	while( !feof(file)){
// 		fscanf(file,"%s",sym);
// 		i = (strlen(sym));
// 		printf("%3c%3c", sym[0], sym[i-1]);

// 	}
// 	fclose(file);
// 	return EXIT_SUCCESS;
// }


// вывод всей информавции из файла
	// file = fopen("p.txt", "r");
	// char sym[N], c = 0;
	// while( (c = fgetc(file)) != EOF){
	// 	printf("%c", c);
	// }

// вывод первого и последнего чара из файла
	// 	file = fopen("p.txt", "r");
	// while( !feof(file)){
	// 	fscanf(file,"%s",sym);
	// 	i = (strlen(sym));
	// 	printf("%c  %c     ", sym[0], sym[i-1]);

// #include <stdio.h>
// #include <ncurses.h>
// #include <string.h>

// /* Структура для хранения информации про одного человека */
// typedef struct tagITEM
// {
//   char Surname[20], Name[20];
//   int Age;
// } ITEM;

// /* Массив максимум на 20 человек */
// ITEM Men[20];

// /* Количество занятых элементов в массиве */
// int Number;

// /* Функция для вывода всех элеиентов */
// void Print( void )
// {
//   int i;

//   printf(" N  Фамилия              Имя                  Возраст\n");
//   for (i = 0; i < Number; i ++)
//     printf("%2i. %-20s %-20s %3i\n", i + 1, Men[i].Surname,
//            Men[i].Name, Men[i].Age);
// } /* End of 'Print' function */

// /* Функция для добавления элемента */
// void Add( void )
// {
//   if (Number == 19)
//   {
//     fprintf(stderr, "Невозможно добавить еще один элемент\n");
//     return;
//   }

//   printf("Введите фамилию > ");
//   scanf("%s", Men[Number].Surname);
//   printf("Введите имя > ");
//   scanf("%s", Men[Number].Name);
//   printf("Введите возраст > ");
//   scanf("%i", &Men[Number].Age);

//   Number ++;
// } /* End of 'Add' function */

// /* Функция для удаления элемента */
// void Del( void )
// {
//   int i;

//   Print();
//   printf("Введите номер удаляемого элемента > ");
//   scanf("%i", &i);
//   if (i < 1 || i > Number)
//   {
//     fprintf(stderr, "Элемент с номером %i не существует\n", i);
//     return;
//   }

//   for (i --; i < Number - 1; i ++)
//     Men[i] = Men[i + 1];

//   Number --;
// } /* End of 'Del' function */

// /* Функция для сохранения массива в файле */
// void Save( void )
// {
//   FILE *F;
//   int i;

//   if ((F = fopen("1.txt", "wt")) == NULL)
//   {
//     fprintf(stderr, "Невозможно открыть для записи файл 'task1.dta'\n");
//     return;
//   }

//   fprintf(F, "%i\n", Number);
//   for (i = 0; i < Number; i ++)
//     fprintf(F, "%s\n%s\n%i\n", Men[i].Surname, Men[i].Name, Men[i].Age);

//   fclose(F);
// } /* End of 'Save' function */

// /* Функция для чтения массива из файла */
// void Load( void )
// {
//   FILE *F;
//   int i;

//   if ((F = fopen("1.txt", "rt")) == NULL)
//   {
//     fprintf(stderr, "Невозможно открыть для чтения файл 'task1.dta'\n");
//     return;
//   }

//   fscanf(F, "%i", &Number);
//   for (i = 0; i < Number; i ++)
//     fscanf(F, "%s%s%i", Men[i].Surname, Men[i].Name, &Men[i].Age);

//   fclose(F);
// } /* End of 'Load' function */

// /* Функция для упорядочивания массива по фамилии */
// void Sort( void )
// {
//   int i, j;
//   ITEM Temp;

//   for (j = Number - 1; j > 0; j --)
//     for (i = 0; i < j; i ++)
//       if (strcmp(Men[i].Surname, Men[i + 1].Surname) > 0)
//       {
//         Temp = Men[i];
//         Men[i] = Men[i + 1];
//         Men[i + 1] = Temp;
//       }
// } /* End of 'Sort' function */

// /* Вывод меню и чтение номера выбранного пункта */
// int Menu( void )
// {
//   int c = 0;

//   while ((c < '0' || c > '6') && c != 27)
//   {
//     printf("0 : выход\n"
//            "1 : добавить\n"
//            "2 : сохранить\n"
//            "3 : загрузить\n"
//            "4 : вывести\n"
//            "5 : упорядочить\n"
//            "6 : удалить\n"
//            ">");
//     c = getchar();
//     printf("%c\n", c);
//   }
//   return c;
// } /* End of 'Menu' function */

// /* Основная функция */
// void main( void )
// {
//   int Selection;

//   Number = 0;
//   while ((Selection = Menu()) != '0' && Selection != 27)
//     switch (Selection)
//     {
//     case '1':
//       Add();
//       break;
//     case '2':
//       Save();
//       break;
//     case '3':
//       Load();
//       break;
//     case '4':
//       Print();
//       break;
//     case '5':
//       Sort();
//       break;
//     case '6':
//       Del();
//       break;
//     }
// } /* End of 'main' function */

