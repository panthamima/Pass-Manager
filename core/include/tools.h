#ifndef TOOLS_H
#define TOOLS_H

#include "defs.h"

int validate_txt(char *filename);
char* remove_x_char(char* str);
void reverse(char s[]);
void itoc(int num, char str[]);
void safe_scanf();
int get_password(char* const pszBuffer, const int nBufferLength);
size_t strlcpy (char * dst, const char * src, size_t dstsize);
size_t strlcat (char* dst, const char* src, size_t dstsize);
int get_line(const char *prompt, char *buf, size_t sz);

#endif