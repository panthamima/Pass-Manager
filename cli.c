#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <ctype.h>

#define SIZE 255

// enum { g, c, d };

void prepareString(); 	// создание строки для записи в файл
void addition();		// добавление строки в файл
int  counting();        // подсчет строк
void extradition();     // выдача информации о записи (строке)
void logging();         // создание мастер аккаунта

FILE *AWE;
char fn[] = "base.db";

int main(int argc,char **argv){
	char g[] = "gen";
	if(!strcmp(argv[1], g)) {
		addition();
	}
    else if(!strcmp(argv[1], "reg")) {

        logging();
    }
    else if(!strcmp(argv[1], "add")) {
        addition();
    }

	return 0;
}

void logging() {
    addition();
    int lineID = 1;
    char itoa;
    char chCnt; // счетчик чаров

    for (chCnt = getc(AWE); chCnt != EOF; chCnt = getc(AWE)){

        if(chCnt == '\n'){
            lineID += 1;
            itoa = lineID + '0';
            fputc(itoa, AWE);
        }
    }
}

int counting() { // подсчет строк в файле
    int lineID = 1;
    char itoa;
    char chCnt; // счетчик чаров

    // need refactor ****************************
    if(lineID == 1) {
        fputc('1', AWE);
    }
    if (AWE = fopen(fn, "r+")) {

        for (chCnt = getc(AWE); chCnt != EOF; chCnt = getc(AWE)){

            if(chCnt == '\n'){
                lineID += 1;
                itoa = lineID + '0';
                fputc(itoa, AWE);
            }
        }
    }
    // need refactor ****************************

    printf("%d\n", lineID);
    return lineID;
}

void prepareString() { // создание строки для записи в файл
    char buffer[SIZE];

    // fgets(buffer, SIZE, stdin);
    scanf("%255s", buffer);
    fputs(buffer, AWE);
}

void addition() { // добавление строки в файл
    AWE = fopen(fn, "a");
    
    counting();

    printf("Enter login\n\t- ");
    prepareString();
    fputc(':', AWE);

    printf("Enter password\n\t- ");
    prepareString();
    fputc('\n', AWE);
    
    fclose(AWE);
}



void extradition() { // выдача информации о записи (строке)
}