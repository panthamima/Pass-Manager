LIBS          = -lX11 -lsodium -lSDL2
BUILD_FLAGS   = -Os -Wformat=2 -ggdb#-std=c99
DEBUG_FLAGS   = -Wall -O # -Werror

build: 
	gcc $(BUILD_FLAGS) -o awe.out main.c src/*.c crypt/*.c $(LIBS)
	rm -rf *.o

debug: 
	gcc $(DEBUG_FLAGS) -o awe.out main.c src/*.c crypt/*.c $(LIBS) 

buildw:
	gcc -o awe main.c src/*.c crypt/*.c $(LIBS) 