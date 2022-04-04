#include "include/defs.h"
#include "include/tools.h"
#include <stdio.h>

int main(int argc, char **argv){
    // init_struct();

    char filename[SIZE] = "asdasd";
    identify_txt(filename);
    printf("%s", filename);

    // /****/ if (argc < 2) {
    //     printf("command not found. Enter: awe help\n");
    // } else if (!strcmp(argv[1], "reg")) {
    //     master_seed();
    // } else if (!strcmp(argv[1], "add")) {
    //     addition();
    // } else if (!strcmp(argv[1], "rem")) {
    //     removing();
    // } else if (!strcmp(argv[1], "get")) {
    //     extradition();
    // } else if (!strcmp(argv[1], "list")) {
    //     show_the_list();
    // } else if (!strcmp(argv[1], "rem+")) {
    //     shred();
    // } else if (!strcmp(argv[1], "test")) {
    //     delete_cat();
    // } else if (!strcmp(argv[1], "help")) {
    //     system("clear");
    //     printf("%s", help);
    // } else if (!strcmp(argv[1], "cat")) {
    //     create_cat(); // добавить проверку на добвление .txt
    // } else {
    //     printf("command not found. Enter: awe help\n");
    // }
}