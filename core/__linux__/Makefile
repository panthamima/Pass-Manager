LIBS    = -lX11 -lsodium
BUILD_FLAGS   = -Os -Wformat=2 -ggdb#-std=c99
DEBUG_FLAGS   = -Wall -O # -Werror

buildw: 
	gcc $(BUILD_FLAGS) -o awe.out main.c src/*.c crypt/*.c $(LIBS) 
	rm -rf *.o

debug: 
	gcc $(DEBUG_FLAGS) -o awe.out main.c src/*.c crypt/*.c $(LIBS) 

build:
	gcc -o awe.out main.c src/*.c crypt/*.c $(LIBS) 