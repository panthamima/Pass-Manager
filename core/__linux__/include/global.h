#ifndef GLOBAL_H
#define GLOBAL_H

#define TCOLOR_R     "\x1b[31;1m"
#define TCOLOR_Y     "\x1b[33;1m"
#define TCOLOR_G     "\x1b[32;1m"
#define TCOLOR_RESET "\x1b[0m"

char* get_home_directory(char* directory);
char* get_path(char* path);

#define VERSION "0.1.1"

void init_struct();
void awe_help();
void awe_print_logo();
void awe_version();
void test();

#endif