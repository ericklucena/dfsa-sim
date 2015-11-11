CC=gcc
CPPFLAGS=
CFLAGS= -std=c99 -Wall -pedantic -Iinclude -lm -g `pkg-config --cflags python3` -fPIC
LDFLAGS= `pkg-config --libs python3`

all: src/*.c
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o bin/runMe

DFSA.so: src/pyconnector.o src/aloha.o src/util.o src/result.o
	$(CC) $^ -shared $(CFLAGS) $(LDFLAGS) -o DFSA.so
	make all	

pyconnector.c: src/pyconnector.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<

clean: 
	rm bin/runMe
