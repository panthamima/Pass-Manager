#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

#include "../include/pass_handle.h"
#include "../include/entries_handle.h"
#include "../include/dir_handle.h"
#include "../include/validation.h"
#include "../include/global.h"

const char* const allowed_flags[] = {"init", "add", "rem", "get", "list", "clear", "cat", "--help", "--version"};
void (*commands_store[])(void)    = { master_seed, addition, removing, extradition, show_the_list, shred, create_cat, awe_help, awe_version };
const int const allowed_flags_length = sizeof allowed_flags / sizeof allowed_flags[0]; // prim: array[elements] / element

void validate_flags(const char * const flags[], const int const lenth) {
    int i,j;
    int incorrect_flag_index = -2;

    for (i = 1; i < lenth; i++) {
        for(j = 0; j < allowed_flags_length; j++) {
            if(!strcmp(flags[i], allowed_flags[j])) {
                incorrect_flag_index = -1;
                break;
            }
            else {
                incorrect_flag_index = i;    
            }
        }
        if(incorrect_flag_index > -1) {
            printf(TCOLOR_R "[×]%s Invalid argument '%s'. Usage: awe --help\n", TCOLOR_RESET, flags[incorrect_flag_index]);
            exit(INCORRECT_FLAG);
        }
    }
}

void invoke_commands(const char* const commands[], const unsigned int count) {
    int i, j;
    
    for(i = 1; i < count; i++) {
        for(j = 0; j < allowed_flags_length; j++) {
            if(!strcmp(commands[i], allowed_flags[j])) {
                commands_store[j]();
            }
        }
    }
}