#ifndef GLOBAL_H
#define GLOBAL_H

char* get_home_directory(char* directory);
char* get_path(char* path);

static char logotype[] = "                                   __                            __       \n\
  ____ _ _      __  ___    _____  / /_   _____  __  __  _____   / /__       \n\
 / __ `/| | /| / / / _ \\  / ___/ / __/  / ___/ / / / / / ___/  / //_/      \n\
/ /_/ / | |/ |/ / /  __/ (__  ) / /_   / /    / /_/ / / /__   / ,<          \n\
\\__,_/  |__/|__/  \\___/ /____/  \\__/  /_/     \\__,_/  \\___/  /_/|_|    \n\n";

void init_struct();
void help();
void print_logo();

#endif