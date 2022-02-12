#ifndef XORPLUS_CRYPT_H
#define XORPLUS_CRYPT_H

#define SIZE 256

int caeXorEnc(char * filename, char xor_str[SIZE], char *xor_key);
int caeXorDec(char * filename, char xor_str[SIZE], char *xor_key);

#endif