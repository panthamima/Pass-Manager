#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_clipboard.h>

int copy(){
  SDL_Init(SDL_INIT_VIDEO);
  char buffer[256];
    char temp[256];
    scanf("%s", temp);
  SDL_SetClipboardText(temp);
  printf("%s", temp);
  SDL_Quit();
}