#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


// int main() {
//     unsigned int key = 0;
//     char corp[100];
//     char pass[100];

//     FILE *pm;
//     char name[] = "p.txt";

//     if(pm = fopen(name, "a")) {
//         printf("enter corp:pass\n");
//         fscanf(pm, "%d %s:%s", key, corp, pass);
//         fclose(pm);
//     }
// }

// int main()
// {
//   FILE *pm;
//   unsigned int key = 0;
//   char* corp = "aaa";
//   char* pass;

//   system("clear");

//   printf("corp: ");
//   fputs(corp, pm);
//   fclose(pm);

//   return 0;
// }

int main(void)
{
    char * filename = "p.txt";
    char cc[256];
    FILE *fp;
     
    // запись в файл
    if((fp= fopen(filename, "w"))==NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    // записываем строку
    char message = getchar();
    fputs(message, fp);
 
    fclose(fp);
     
    // чтение из файла
    if((fp= fopen(filename, "r"))==NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    // пока не дойдем до конца, считываем по 256 байт
    while((fgets(cc, 256, fp))!=NULL) {
        printf("%s", cc);
    }
     
    fclose(fp);
    return 0;
}

