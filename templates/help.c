// #define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
// #define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

// #define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
// #define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
// #define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
// #define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
// #define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
// #define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))


// #include <stdio.h>
// #define MAX_FILE_NAME 100
// int main()
// {
//     FILE* fp;
//     int count = 0;
//     char filename[MAX_FILE_NAME];
//     char c;
//     printf("Enter file name: ");
//     scanf("%s", filename);
//     fp = fopen(filename, "r");
//     if (fp == NULL) {
//         printf("Could not open file %s",filename);
//         return 0;
//     }
//     for (c = getc(fp); c != EOF; c = getc(fp)){
//         count += 1;
//     }
//     fclose(fp);
//     printf("The file %s has %d characters\n ", filename, count);
//     return 0;
// } 

// #include <stdio.h>
// #include <stdlib.h>
 
// struct person
// {
//     char name[1622];
//     int age;
//     int height;
// };
 
// int save(char * filename, struct person *p);
// int load(char * filename);
 
// int main(void)
// {
//     char * filename = "person.txt";
//     struct person tom = { "bebadsadsadsadsdasdasadsadsra", 22, 177};
 
//     save(filename, &tom);
//     load(filename);
     
//     return 0;
// }
 
// // запись структуры в файл
// int save(char * filename, struct person *p)
// {
//     FILE * fp;
//     char *c;
//     int size = sizeof(struct person); // количество записываемых байтов
 
//     fp = fopen(filename, "wb");
//     // устанавливаем указатель на начало структуры
//     c = (char *)p;
//     // посимвольно записываем в файл структуру
//     for (int i = 0; i < size; i++)
//     {
//         putc(*c++, fp);
//     }
//     fclose(fp);
//     return 0;
// }
 
// // загрузка из файла структуры
// int load(char * filename)
// {
//     FILE * fp;
//     char *c;
//     int i; // для считывания одного символа
//     // количество считываемых байтов
//     int size = sizeof(struct person);
//     // выделяем память для считываемой структуры
//     struct person * ptr = (struct person *) malloc(size);
 
//     if ((fp = fopen(filename, "rb")) == NULL)
//     {
//         perror("Error occured while opening file");
//         return 1;
//     }
 
//     // устанавливаем указатель на начало блока выделенной памяти
//     c = (char *)ptr;
//     // считываем посимвольно из файла
//     while ((i = getc(fp))!=EOF)
//     {
//         *c = i;
//         c++;
//     }
 
//     fclose(fp);
//     // вывод на консоль загруженной структуры
//     printf("%-20s %5d \n", ptr->name, ptr->age);
//     free(ptr);
//     return 0;
// }


// #include <stdio.h>
// #include <ncurses.h>
// #include <stdlib.h>
    
// int vvod(void);
// int vvod_razmera(void);
// void vvod_massiva(int);
// int punkt_menu(void);
// void vyvod_massiva(int);
// int vyvod(void);
// void vyhod(void);
    
// struct touring
// {char country[50];
//     char city [50];
//     int tour_duration ;
//     int cost ;
    
    
// };
// // глобальные переменные
// struct touring tour[8];
// // char punky_menu [8];
//     //-------------------
// int main (void)
// {
//     int razmer;
//     int razmer1;
//     int p;//e;
//     p=punkt_menu();
//     printf("%d",p);
//     switch(p)
//     {case 1 :
//             razmer=vvod();
//             break;
//     case 2:
//             razmer1=vyvod();
//             break;
//     case 3:
//             vyhod();
//             break;
//     default: printf("\n\t Any of points isn't chosen");
//     }
//     getch();
// }
    
// int punkt_menu(void)
// {int p; 
// printf("\n\t Enter 1 if you want to enter data\n");
// printf("\n\t Enter 2 if you want to look at data\n");
// printf("\n\t Enter 3 if you want to finish work with application\n");
// scanf("%d",&p);
// return(p);
// }
    
// int vvod (void)
    
// {
//     int razmer;
//     razmer=vvod_razmera();
//     vvod_massiva(razmer);
//     return(razmer);
// }
    
// int vvod_razmera()
// {
//     int n;
//     printf("Enter number of tours \n");
//     scanf("%d",&n);
//     return (n);   
// }
    
// void vvod_massiva(int n)              //71   'n' was not declared in this scope  //variable or field 'vvod_massiva' declared void
// {
//     int i;
//     for(i=1;i<=n;i++)
//     {
//     printf("Enter element number &d\n",i);
//     printf("Enter country of tour:");
//     scanf("%s",&tour[i].country);
//     printf("\n Enter city of tour:");
//     scanf("%s",&tour[i].city);
//     printf("\n Enter number of days of tour:");
//     scanf("%d",&tour[i].tour_duration);
//     printf("Enter cost of tour:");
//     scanf("ds",&tour[i].cost);
    
//     }
//     }
    
//     int vyvod(void)
//     {
//     int razmer1;
    
//     razmer1=vvod_razmera();
//     vyvod_massiva(razmer1);
//     return(razmer1);
//     }
//     void vyvod_massiva(int n)
//     {
//     int i;
//     for(i=1;i<=n;i++)
//         {
//         printf("Country of tour:%s\n",&tour[i].country);
//         printf("City of tour:%s\n",&tour[i].city);
//         printf("Number of days of tour :%d\n",&tour[i].tour_duration);
//         printf("Cost of tour:%d\n",&tour[i].cost);
//         }
//     }
//     void vyhod(void)
// {
//     exit(0);
// }

// #include <stdio.h>
// #include <stdlib.h>
 
// typedef struct Node{
//     int number;
//     float age;
//     char group;
//     struct Node *next;
//     struct Node *prev;
// }Node;
 
// typedef struct List{
//     int amount;
//     Node *head;
//     Node *tail;
// }List;
 
// void pushBack(List *list, int Number, float Age, char Group){
//     Node *tmp = (Node*) malloc(sizeof(Node));
//     if(tmp == NULL){exit(3);}
 
//     tmp->number = Number;
//     tmp->age = Age;
//     tmp->group = Group;
 
//     tmp->next = NULL;
//     tmp->prev = list->tail;
//     if(list->tail){list->tail->next = tmp;}
//     list->tail = tmp;
 
//     if(list->head == NULL){list->head = tmp;}
//     list->amount++;}
 
// void printList(Node *root){
//   if(root == NULL){printf("\nList is empty!\n"); return 0;}
//   Node *p;
//   p = root;
//   do{
//     printf("Number: %d\n", p->number);
//     printf("Age: %4.1f\n", p->age);
//     printf("Group: %c\n\n", p->group);
//     p = p->next;
//   }while (p != NULL);}
 
// Node* getNth(List *list, size_t index){
//     if(list->head == NULL){printf("\nList is empty!\n"); return 0;}
//     Node *tmp = list->head;
//     size_t i = 0;
//     while (tmp && i < index){
//         tmp = tmp->next;
//         i++;}
//     return tmp;}
 
// void* deleteNth(List *list, size_t index){
//     if(list->head == NULL){printf("\nList is empty!\n"); return 0;}
//     Node *elm = NULL;
//     void *tmp = NULL;
//     elm = getNth(list, index);
//     if(elm == NULL){exit(5);}
//     if(elm->prev){elm->prev->next = elm->next;}
//     if(elm->next){elm->next->prev = elm->prev;}
//     tmp = elm->number;
 
//     if(!elm->prev){list->head = elm->next;}
//     if(!elm->next){list->tail = elm->prev;}
 
//     free(elm);
//     list->amount--;
//     return tmp;}
 
// void changeEl(List *list, int number){
//     if(list->head == NULL){printf("\nList is empty!\n"); return 0;}
//     float newAge; int newNumber; char newGroup, choice;
//     Node *tmp = getNth(list, number);
//     printf("What parameter do you want to change(group/age/number): ");
//     scanf("%s", &choice);
//     if(choice == 'g'){
//         printf("\nEnter new group: ");
//         scanf("%s", &newGroup);
//         tmp->group = newGroup;}
//     else if(choice == 'a'){
//         printf("\nEnter new age: ");
//         scanf("%f", &newAge);
//         tmp->age = newAge;}
//     else if(choice == 'n'){
//         printf("\nEnter new number: ");
//         scanf("%d", &newNumber);
//         tmp->number = newNumber;}
// }
 
// void menuPrint(){
//     printf("\nChoose an action:\n");
//     printf("\t>a - add new element\n");
//     printf("\t>p - display all list elements\n");
//     printf("\t>d - delete element\n");
//     printf("\t>c - find element and change its value\n");
//     printf("\t>s - save list to text file\n");
//     printf("\t> ");
// }
 
// void saveListToFile(Node *root){
//   if(root == NULL){printf("\nList is empty!\n"); return 0;}
//   FILE *f = fopen("asd.txt", "r+");
//   if(f == NULL){printf("\nERROR!!! Cannot open the file!\n"); return 0;}
//   Node *p;
//   p = root;
//   do{
//     fprintf(f, "%d %4.1f %c\n", p->number, p->age, p->group);
//     p = p->next;
//   }while (p != NULL);
//   fclose(f);}
 
 
 
// int main(){
//     List *list = (List*)malloc(sizeof(List));
//     list->head = NULL;  list->tail = NULL; list->amount = 0;
//     float age = 0; int number = 0;
//     char choice, group; void *toChange;
//     for(;;){
//     menuPrint();
//     scanf("%s", &choice);
//     if(choice == 'a'){
//         printf("Enter number, age and group: ");
//         scanf("%d %f %c", &number, &age, &group);
//         pushBack(list, number, age, group);}
//     else if(choice == 'p'){
//         printf("\n");
//         printList(list->head);
//     }
//     else if(choice == 's'){
//         saveListToFile(list->head);
//     }
//     else if(choice == 'd'){
//         printf("Enter value of el: ");
//         scanf("%d", &number);
//         deleteNth(list, number);
//     }
//     else if(choice == 'c'){
//         printf("Enter number of el: ");
//         scanf("%d", &number);
//         changeEl(list, number);
//         }
// 	}
// 	return 0;
// }
#include <stdio.h>

int n_readline(const char* fname, int n, char* buf, int len){
    char  c;
    FILE* fp = fopen(fname, "rt");
    if(fp == NULL)
        return 0;

    while(! feof(fp) && (n > 0)){
       fscanf(fp, "%*[^\n\r]%c", &c);
       --n;
    }

    if(! feof(fp))
        fgets(buf, len-1, fp);
    else
       *buf = '\0';

    fclose(fp);
    return (int)(*buf != '\0');
  }



 int main(void){
   char buf[255];

   //считать 2-строку
   if(n_readline("1.txt", 4, buf, sizeof(buf)))
         puts(buf);

   //считать 3-строку
   if(n_readline("levels.txt", 2, buf, sizeof(buf)))
         puts(buf);
   return 0;
 }

// #include <stdio.h>
 
// size_t count_lines(const char* filename) {
//    FILE* fp;
//    size_t cnt = 0u;
//    if((fp = fopen(filename, "r")) == NULL)
//          return 0u;
//    while(! feof(fp)) {
//          fscanf(fp, "%*[^\n]%*c");
//          cnt++;
//    }
//    fclose(fp);
//    return cnt;
// }
 
// int main(void){
//     printf("file lines: %u\n", count_lines("../core/__awebase/categories/zxczxc.txt") );
//     getchar();
//     return 0;
// }

// #include <stdio.h>
// #include <ctype.h>

// char* str_remove(char* s) {
//    char* t = s;
//    char* a, *b;
//    for(a = s, b = s; *b = *a; *a++) {
//       if(! isalnum(*a))
//           *b++;
//    }
//    return t;
// }

// int main(void) {
//    char s[128] = "[ops]<123405006>.(opsabweABSDE)";
//    /*
//    printf("enter str: ");
//    scanf("%127[^\n]", s);
//    */
//    puts( str_remove(s) );
   
//    getchar();
//    return 0;
// }