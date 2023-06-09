CC = gcc
CFLAGS = -Wall -I/usr/local/sx/include
LDFLAGS = -L/usr/local/sx/lib
LIBS = -lsx -lX11 -lXt 

.PHONY: all clean

all: main

main: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f main
