CC=gcc
CPP=g++
CFLAGS= -O -W -Wall
DEB=-ggdb -O -W -Wall
LIBS=`sdl-config --cflags --libs` -lSDL_image
LINSRC=linux/

interface: load_images.o free_images.o sdl_interface.o $(LINSRC)linux_motor_ligero.o $(LINSRC)linux_motor_lento.o
	$(CC) $(LIBS) $(DEB) load_images.o free_images.o sdl_interface.o -o interface $(LINSRC)linux_motor_ligero.o $(LINSRC)linux_motor_lento.o

sdl_interface.o: sdl_interface.c
	$(CC) $(DEB) -c sdl_interface.c

load_images.o: load_images.c
	$(CC) $(DEB) -c load_images.c

handle_events.o: handle_events.c
	$(CC) $(DEB) -c handle_events.c

free_images.o: free_images.c
	$(CC) $(DEB) -c free_images.c

linux_motor_ligero.o: linux_motor_ligero.c
	$(CC) $(DEB) -c $(LINSRC)linux_motor_ligero.c

linux_motor_lento.o: linux_motor_lento.c
	$(CC) $(DEB) -c $(LINSRC)linux_motor_lento.c

.PHONY: clean

clean:
	rm *.o interface linux/*.o
