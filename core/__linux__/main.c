#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "include/dir_handle.h"
#include "include/entries_handle.h"
#include "include/global.h"
#include "include/pass_handle.h"
#include "include/tools.h"
#include "include/validation.h"

int main(const int const argc, const char* const argv[]) {
    if(argc > 1) {
        validate_flags(argc, argv);
    } else {
        printf(TCOLOR_R "[×]%s Missing argument. Usage: awe --help\n", TCOLOR_RESET);
    }
    invoke_commands(argc, argv);

    return 0;
}