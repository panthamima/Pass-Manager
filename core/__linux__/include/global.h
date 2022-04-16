#ifndef GLOBAL_H
#define GLOBAL_H

char* get_home_directory(char* directory);
char* get_path(char* path);

#define VERSION "0.1.0"


void init_struct();
void awe_help();
void awe_print_logo();
void awe_version();
void test();

#endif