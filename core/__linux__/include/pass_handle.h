#ifndef CATS_HANDLE_
#define CATS_HANDLE_

char *random_pass(char *password);
void master_seed();
int confirm();
void hide_pass();

int getchar_supressed();
int get_password(char* const pszBuffer, const int nBufferLength);
void run();

#endif