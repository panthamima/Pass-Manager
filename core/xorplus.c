#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 256

char *caeXorEnc(char *xor_str, char *xor_key, char *value) {
    int i, // xor_str
        j, // count 
        k; // k % strlen

    i = k = j = 0;
    char buf; 
    char count[SIZE];

    for(i = 0; xor_str[i] != '\0'; ++i){
        buf = xor_str[i];
        if(buf >= '!' && buf <= '}') { // от минимально до максимально доступного символа
            buf += strlen(xor_key); // символ + сдвиг
            if(buf > '}'){
                buf = buf - '}' + '!' - 1;
            }
        }
        count[j] = buf;
        count[j] = count[j] ^ xor_key[k % strlen(xor_key)]; // xor
        k++;
        *value++ = count[j];
    }
}

char *caeXorDec(char *xor_str, char *xor_key, char *value) {
    char buf;
    char *cipher;
    int i, k, j;
    i = k = j =0;
    char output[SIZE];
    for(i = 0; xor_str[i] != '\0'; i++){
        output[j] = xor_str[i] ^ xor_key[k % strlen(xor_key)]; //xor
        k++;
        buf = output[j];
        if(buf >= '!' && buf <= '~'){
            buf -= strlen(xor_key);
			if(buf < '!') {
				buf = buf + '}' - '!' + 1;
			}
        }
        *value++ = buf;
    }

}