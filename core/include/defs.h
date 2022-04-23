#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>

#define SIZE 256
#define TRUE 1
#define FALSE 0

enum types {
    init,
    storage,   // path to main folder
    master, // path to masterpass file
    temp    // path to temp file
};

static FILE *AWE, *TEMP;
static char master_file[] = "mas.xx";
static char    tmp_file[] = "_tmp.xx";

#endif