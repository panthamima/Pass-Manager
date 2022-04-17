LIBS    = -lX11

buildw: 
	gcc -o awe main.c src/*.c $(LIBS) 
	rm -rf main.o dir_handle.o entries_handle.o global.o pass_handle.o tools.o validation.o

build:
	gcc -c main.c src/dir_handle.c src/entries_handle.c src/global.c src/pass_handle.c src/tools.c src/validation.c src/clipboard.c
	gcc -o awe main.o dir_handle.o entries_handle.o global.o pass_handle.o tools.o validation.o clipboard.o