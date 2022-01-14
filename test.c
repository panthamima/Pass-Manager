#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

#define N 256 // размер массива

FILE *pm; // pass-manager
char line[N];
char filename[] = "p.txt";

void format() { // функция вставляющая форматированную строку в файл
    char info[256];

    fgets(info, 255, stdin);
    scanf("%s", info);
    fputs(info, pm);
}

int addition() { // добавление в файл
    printf("enter login: ");
    format();
    fputs(":", pm);

    printf("enter password: ");
    format();

    fputs("\n", pm);
    fclose(pm);
}

void show() { // 
    pm = fopen(filename, "r");
	char sym[N], c = 0;
	while( (c = fgetc(pm)) != EOF) {
		printf("%c", c);
	}
    printf("\n");
}

void shred() {
    pm = fopen(filename, "w");
    fclose(pm);
}

int main() {
    char id[N]; 
    char enter = '\n';

    // if((pm = fopen(filename, "a")) == NULL) {
    //     printf("error");
    // }
    system("clear");
    printf("1[add]\n2[show passwords]\n3[remove]\n4[rename login or pass] \
            \n5[shred]\n6[add an existing file]\n\n:>> ");

    int command = getchar();
    if(command == '1') {
        addition();
    }
    else if(command == '2') {
        system("clear");
        printf("your accounts:\n\n");
        show();
    }
    else if(command == '3') {

    }
    else if(command == '4') {

    }
    else if(command == '5') {
        char i;
        printf("do you really wan't to delete your accs? [y/n]\n");
        scanf("%d", i);
        printf("%d", i);
        // getchar();
        // getchar();
        // shred(); // need fix
    } 
    else if(command == '6') {

    }
    // show();
}



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
