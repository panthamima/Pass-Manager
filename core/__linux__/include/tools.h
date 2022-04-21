#ifndef TOOLS_H
#define TOOLS_H

#include "../include/defs.h"

int validate_txt(char *filename);
char* remove_x_char(char* str);
void reverse(char s[]);
void itoc(int num, char str[]);
void safe_scanf();
size_t strlcpy (char * dst, const char * src, size_t dstsize);

#endif