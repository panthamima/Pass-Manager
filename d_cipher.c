#include <stdio.h>
#include <string.h>

#define SIZE 255

int encrypt(char caesar_str[], int caesar_key) {
    char ch;
    int i;

    for(i = 0; caesar_str[i] != '\0'; ++i){
        ch = caesar_str[i];
        if(ch >= '!' && ch <= '~'){
            ch = ch + caesar_key;
            if(ch > '~'){
                ch = ch - '~' + '!' - 1;
            }
            caesar_str[i] = ch;
        }
    }
    printf("Encrypted message: %s\n", caesar_str);
    return 0;
}

int decrypt(char caesar_str[], int caesar_key) {
    char ch;
    int i;

    for(i = 0; caesar_str[i] != '\0'; ++i){
        ch = caesar_str[i];
        if(ch >= '!' && ch <= '~'){
            ch -= caesar_key;
			if(ch < '!') {
				ch = ch + ('~' - '!') + 1;
			}
            caesar_str[i] = ch;
        }
    }
    printf("Decrypted message: %s\n", caesar_str);
    return 0;
}
int xor(char xor_str[255], char *xor_key) {
    int i, j;
    i = j = 0;
    char output;
    while(xor_str[j] != '\0') {
        output = xor_str[j] ^ xor_key[i % strlen(xor_key)];
        j++;   
        i++;
        printf("%c", output);
    }

}


int main() {
    char plaintext[] = "asaddas123347365";
    char key[] = "12";

    xor(plaintext, key);

    return 0;
}

