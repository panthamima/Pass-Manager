#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#include <dirent.h>

const char* const allowed_flags[] = {"--help", "-version"};
const int const allowed_flags_lenth = sizeof allowed_flags / sizeof allowed_flags[0];

void validate_flags(const char* const flags[], const int const lenth) {
    int i,j;
    for (i = 1; i < lenth; i++) {
        for(j = 0; j < allowed_flags_lenth; j++) {
            printf("arg: %s\nbebra: %s\n", flags[i], allowed_flags[j]);
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc > 1) {
        validate_flags(argv, argc);
    }
    return 0;
}
