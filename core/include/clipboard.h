#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_clipboard.h>

void copy(char *text);
void paste(char* text);
void set_keypress(void);
void reset_keypress(void);

#endif