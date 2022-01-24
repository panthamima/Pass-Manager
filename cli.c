#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int create_person();

int main(int argc,char **argv){
	//setlocale(LC_ALL, ""); 
	
	if (!strcmp(argv[1], "create")) {
		if (!strcmp(argv[2], "person")){
			create_person();
		}
	}
		
	return 0;
}

int create_person(){
	char login[255], passwd[255];
	FILE *fp;
	char name[] = "person.pm";
	printf("Create a new person\n\n");

	printf("Enter login\n\t- ");
	scanf("%255s", login);
	
	printf("Enter password\n\t- ");
	scanf("%255s", passwd);
	
	if ((fp = fopen(name, "w+")) == NULL){
		printf("Error: File open");
		return 0;
	}

	fputs(login, fp);
	
	fclose(fp);

	printf("New person:\n\t login: %s\n\t password: %s", login, passwd);

	return 0;
}

