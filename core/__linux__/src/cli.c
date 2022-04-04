#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#include <dirent.h>
// #include <X11/Xlib.h>
// #include <sys/stat.h>
// #include <sys/typesnuiium .h>



const char* const allowed_flags[] = {"--help", "-version"};
const int const allowed_flags_lenth = sizeof allowed_flags / sizeof allowed_flags[0];

void validate_flags(const char * const flags[], const int const lenth) {
    int i,j;
    for (i = 1; i < lenth; i++) {
        for(j = 0; j < allowed_flags_lenth; j++) {
            printf("arg: %s\nbebra: %s\n", flags[i], allowed_flags[j]);
        }
    }
}

int main(const int const argc, const char * const argv[]) {
    if(argc > 1) {
        validate_flags(argv, argc);
    }
    return 0;
}



// #include "cli.h"

// void handler_io(char *filename, char *crypt_action) {
//     int i = 0;
//     unsigned file_size = 524288;
//     char file_buf[file_size];

//     AWE = fopen(strcat(path, filename), "a");
//     while(!feof(AWE)) {
//         file_buf[i++] = getc(AWE);
//     }

//     if(!strcmp(crypt_action, "encrypt")) {
        
//         // caeXorEnc(file_buf, "bebra", ); // соеденить с confirmom и взять от туда мастер пас ЙЙЙ
//     }

//     if(strcmp(crypt_action, "decrypt")) {
//         // do smthng decrypt
//     }

// }

// void output(char *filename) {

// }

























