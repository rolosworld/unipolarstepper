CC=gcc
CPP=g++
CFLAGS= -O2
LIBS=`sdl-config --cflags --libs` -lSDL_image
LINSRC=linux/

interface: load_images.o sdl_interface.o $(LINSRC)linux_motor_ligero.o $(LINSRC)linux_motor_lento.o
	$(CC) $(LIBS) load_images.o sdl_interface.o -o interface $(LINSRC)linux_motor_ligero.o $(LINSRC)linux_motor_lento.o

sdl_interface.o: sdl_interface.c
	$(CC) -c sdl_interface.c

load_images.o: load_images.c
	$(CC) -c load_images.c

linux_motor_ligero.o: linux_motor_ligero.c
	$(CC) -c $(LINSRC)linux_motor_ligero.c

linux_motor_lento.o: linux_motor_lento.c
	$(CC) -c $(LINSRC)linux_motor_lento.c

.PHONY: clean

clean:
	rm *.o interface linux/*.o
