#include "../include/clipboard.h"
#include <stdlib.h>
#include <termios.h>
#include <string.h>


void copy(char* text) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetClipboardText(text);
	set_keypress();
    char c = getchar();
	reset_keypress();
	SDL_Quit();
}



static struct termios stored_settings;

void set_keypress(void)
{
	struct termios new_settings;

	tcgetattr(0,&stored_settings);

	new_settings = stored_settings;

	/* Disable canonical mode, and set buffer size to 1 byte */
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;

	tcsetattr(0,TCSANOW,&new_settings);
	return;
}

void reset_keypress(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);
	return;
}