#ifndef XORPLUS_CRYPT_H
#define XORPLUS_CRYPT_H

char *caeXorEnc(char *xor_str, char *xor_key, char *value);
char *caeXorDec(char *xor_str, char *xor_key, char *value);

#endif