CC=gcc
CPP=g++
CFLAGS= -O -W -Wall
DEB=-ggdb
LIBS=`sdl-config --cflags --libs` -lSDL_image
LINSRC=linux/

interface: load_images.o handle_events.o free_images.o sdl_interface.o
	$(CC) $(LIBS) $(DEB) load_images.o handle_events.o free_images.o sdl_interface.o -o interface

sdl_interface.o: sdl_interface.c
	$(CC) $(DEB) -c sdl_interface.c

load_images.o: load_images.c
	$(CC) $(DEB) -c load_images.c

handle_events.o: handle_events.c
	$(CC) $(DEB) -c handle_events.c

free_images.o: free_images.c
	$(CC) $(DEB) -c free_images.c

.PHONY: clean

clean:
	rm *.o interface
