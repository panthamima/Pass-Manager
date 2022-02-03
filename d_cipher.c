#include <stdio.h>
#include <string.h>

#define SIZE 255

int caeXorEnc(char xor_str[SIZE], char *xor_key) {
    int i, k, l, j;
    i = k = l = j = 0;
    char buf;
    char count[SIZE];
    char output[SIZE];
    for(i = 0; xor_str[i] != '\0'; ++i){
        buf = xor_str[i];
        if(buf >= '!' && buf <= '~'){
            buf += strlen(xor_key);
            if(buf > '}'){
                buf = buf - '}' + '!' - 1;
            }
        }
        count[j] = buf;
        count[j] = count[j++] ^ xor_key[k % strlen(xor_key)];
        printf("%c|", count[j]);
        k++;
    }
}

int caeXorDec(char xor_str[SIZE], char *xor_key) {
    char buf;
    char count[SIZE];
    int i, k, l, j;
    i = k = l = j =0;
    char output[SIZE];

    for(i = 0; xor_str[i] != '\0'; ++i){
        output[l] = xor_str[i] ^ xor_key[k % strlen(xor_key)];
        i++;
        k++;
        buf = output[l];
        if(buf >= '!' && buf <= '~'){
            buf -= strlen(xor_key);
			if(buf < '!') {
				buf = buf + ('}' - '!') + 1;
			}
        }
        printf("%c|", buf);
    }
}

int main() {
    char message[SIZE];
    char key[] = "aa33dss";

    scanf("%s", message);

    caeXorDec(message, key);
    

    return 0;
}

