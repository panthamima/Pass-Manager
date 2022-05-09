#ifndef TOOLS_H
#define TOOLS_H

#include "defs.h"

int validate_txt(char *filename);
char* remove_x_char(char* str);
void reverse(char s[]);
void itoc(int num, char str[]);
size_t strlcpy (char * dst, const char * src, size_t dstsize);
size_t strlcat (char* dst, const char* src, size_t dstsize);
int get_line(const char *prompt, char *buf, size_t sz);
void set_keypress(void);
void reset_keypress(void);
int getchar_supressed();
int hide_password(char* const pszBuffer, const int nBufferLength);

#endif