#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <stdio.h> // printf
#include <string.h> // strndup, strlen
#include <X11/Xlib.h>

static void XCopy(Atom selection, unsigned char * text, int size);
void copy();
char * XPasteType(Atom atom);
void paste();

#endif