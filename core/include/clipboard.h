#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_clipboard.h>

void copy(char* input);
void paste();
void sdl();

#endif