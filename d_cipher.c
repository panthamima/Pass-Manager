#include<stdio.h>
 
int encrypt() {
    char message[100], ch;
    int i, key;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%d", &key);

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
        message[i] = ch;
        }
    }
    printf("Encrypted message: %s\n", message);
    return 0;
}

int decrypt() {
    char message[100], ch;
    int i, key;

    printf("Enter a message to decrypt: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%d", &key);

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch -= key;
			if(ch < 'a') {
				ch = ch + ('z' - 'a') + 1;
			}
			else if(ch > 'z'){
                ch = ch - 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch -= key;
            if(ch < 'A') {
				ch = ch + ('Z' - 'A') +1;
			}
            else if(ch > 'Z'){
                ch = ch - 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }

    printf("Decrypted message: %s\n", message);
    return 0;
}

int main() {
    char command;
    command = getchar();

    if(command == '1') {
        encrypt();
    }
    else if(command == '2') {
        decrypt();
    }
}

// #include <stdio.h>
// #include <stdlib.h>
    
// int main()
// {
//     int x,y;
//     int k = 1; //начальный ключ
//     int n = 64; //мощность алфавита, оно же количество символов (в данном варианте без буквы Ё) 64 - 32 от "а" до "я" и 32 от "А" до "Я"
    
    
    
//     FILE *input = fopen("ceaser.txt","rt"); //открываем файл для чтения
//     FILE *encode = fopen("encoded_ceaser.txt","w+t"); //создаём файл для записи и чтения
//     FILE *decode = fopen("decoded_ceaser.txt","wt"); //создаём файл для записи
    
//     //Проверяем удалось ли нам открыть файл
//     if(!input)
//     {
//         perror("ceaser.txt"); //выводим сообщение об ошибке
//         exit(1); //выходим из программы
//     }
    
//     printf("Coding text!\n");
    
//     //Шифрование
//     while((x=fgetc(input)) != EOF) //считываем из файла по символу сдвигая его согласно ключу
//     {
//         if(x >= 192 && x<= 255)
//         {
//             y = (x-192+k)%n+192;
//             k++;
//             if(k>3)
//                 k=1;      
//         }
//         else
//         {
//             y = x;
//         }
//         fputc(y,encode); //вывод зашифрованного символа в файл
//     }
    
//     printf("Coding complete!\n");
    
//     //Расшифровка
    
//     fseek(encode,0,SEEK_SET); //откатываем указатель на начало файла, чтобы чтение шло с начала файла
    
//     printf("Decoding encoded text!\n");
    
//     k = 1; //снова устанавливаем начальное значение ключа
//     while((x=fgetc(encode)) != EOF) //считываем из файла по символу сдвигая его в противоположенную сторону согласно ключу
//     {   
//         if(x >= 192 && x<= 255)
//         {
//             y = (x-192-k+n)%n+192;
//             k++;
//             if(k>3)
//                 k=1;    
//         }
//         else
//         {
//             y = x;
//         }
//         fputc(y,decode); //выводим расшифрованный символ в файл
//     }
//     printf("Decoding complete!\n");
//     //закрываем файлы
//     fclose(input);
//     fclose(encode);
//     fclose(decode);
    
//     //ждём подтверждение пользователя любой клавишей для выхода
// }






// example

/*************************************************************************
 * Caesar Encryptor.
 * code by Destr0yd.
 *
 * usage: cipher <text> <key>
 *
 *************************************************************************
 * size of pe: 41,2K
 * gcc -v: 6.3.0 (mingw)
 * gcc cipher.c -o cipher.exe
 *************************************************************************/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define MAXMESSAGESIZE 256
// #define ENGLISHALPHABETLENGTH 26

// #define DEBUG 1

// typedef char* String;
// typedef unsigned int UINT;

// String EncryptMessage(char Message[], UINT Key);
// String EncryptMessage(char Message[], UINT Key)
// {
// 	for(UINT i = 0; i < strlen(Message); i++)
// 	{
// 		#ifdef DEBUG
// 		printf("symbol %c is going to be encrypted.\n", Message[i]);
// 		#endif
		
// 		if(isalpha(Message[i]) == 0)
// 		{
// 			#ifdef DEBUG
// 			printf("warning: symbol %c isn't a letter.\n\n", Message[i]);
// 			#endif
// 			continue;
// 		}

// 		else if(isalpha(Message[i] + Key) == 0)
// 			Message[i] = (Message[i] - ENGLISHALPHABETLENGTH) + Key;	// x = (l - 26) + k
// 																		//
// 		else Message[i] += Key;											// x = k + l
// 	}

// 	return Message;
// }

// int main(int argc, String argv[])	// third update, now no scanf only args
	// long int UserKey;

	// if(argc < 3) {
	// 	exit(EXIT_FAILURE);
	// }
	// UserKey = atoi(argv[2]);

	// printf("\nCaesar Cipher.\n\ntext - %s\nkey - %d", argv[1], UserKey);

	// if((UserKey <= 0) || (UserKey > 26)) {
	// 	exit(EXIT_FAILURE);
	// }

	// printf("\n"); puts(EncryptMessage(argv[1], UserKey));
	// return 0;
// ;}
