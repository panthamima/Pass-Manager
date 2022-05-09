#ifndef ENTRIES_HANDLE_H
#define ENTRIES_HANDLE_H

#include "../include/defs.h"

void removing();
void shred();
void addition();
void prepare_string(char path_file[SIZE], char symbol);
void show_the_list();
int  counting(const char* f_name, int n, char* buf, int len);
void extradition();

#endif