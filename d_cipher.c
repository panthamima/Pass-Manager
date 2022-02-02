#include <stdio.h>
#include <string.h>

#define SIZE 255

// int xor(char xor_str[255], char *xor_key);

// int encrypt(char xorplus_str[255], char xorplus_key[255]) {
//     char buf;
//     int i;


//     for(i = 0; xorplus_str[i] != '\0'; ++i){
//         buf = xorplus_str[i];
//         if(buf >= '!' && buf <= '~'){
//             buf += strlen(xorplus_key);
//             if(buf > '~'){
//                 buf = buf - '~' + '!' - 1;
//             }
//             xorplus_str[i] = buf;
//         }
//     }
//     printf("\nEncrypted message before: %s\n", xorplus_str);

//     xor(xorplus_str, xorplus_key); 

//     printf("\nEncrypted message after: %s\n", xorplus_str);
//     return 0;
// }

// int decrypt(char xorplus_str[], char *xorplus_key) {
//     char buf;
//     int i;
//     xor(xorplus_str, xorplus_key);
//     printf("Decrypted message: %s\n", xorplus_str);

//     for(i = 0; xorplus_str[i] != '\0'; ++i){
//         buf = xorplus_str[i];
//         if(buf >= '!' && buf <= '~'){
//             buf -= strlen(xorplus_key);
// 			if(buf < '!') {
// 				buf = buf + ('~' - '!') + 1;
// 			}
//             xorplus_str[i] = buf;
//         }
//     }
//     printf("Decrypted message: %s\n", xorplus_str);
//     return 0;
// }
int caeXorEnc(char xor_str[255], char *xor_key) {
    int i, k, l, j;
    i = k = l = j =0;
    char buf;
    char count[255];
    char output[255];
    for(i = 0; xor_str[i] != '\0'; ++i){
        buf = xor_str[i];
        if(buf >= '!' && buf <= '~'){
            buf += strlen(xor_key);
            if(buf > '~'){
                buf = buf - '~' + '!' - 1;
            }
        }
        count[j] = buf;
        output[l] = count[j++] ^ xor_key[k % strlen(xor_key)];
        k++;
        printf("%c", output[l++]);
    }
}

int caeXorDec(char xor_str[255], char *xor_key) {
    char buf;
    int i, k, l;
    i = k = l =0;
    char output[255];

    for(i = 0; xor_str[i] != '\0'; ++i){
        output[l] = xor_str[i] ^ xor_key[k % strlen(xor_key)];
        k++;
        buf = output[l];
        printf("%c", output[l]);

        if(buf >= '!' && buf <= '~'){
            buf -= strlen(xor_key);
			if(buf < '!') {
				buf = buf + ('~' - '!') + 1;
			}
            xor_str[i] = buf;
        }
        printf("%c|", xor_str[i]);
    }
}

int main() {
    char message[255];
    char key[] = "1123123312";

    scanf("%s", message);

    caeXorEnc(message, key);
    

    return 0;
}

