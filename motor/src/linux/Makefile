CC=gcc
CPP=g++
CFLAGS=-O -W -Wall
DEBFLAGS=-ggdb
LIBS=`sdl-config --cflags --libs` -LSDL_image

ALL:
	$(CC) $(CFLAGS) -c linux_motor_lento.c linux_motor_ligero.c

linux_motor_lento.o: linux_motor_lento.c
	$(CC) $(CFLAGS) -c linux_motor_lento.c

linux_motor_ligero.o: linux_motor_ligero.c
	$(CC) $(CFLAGS) -c linux_motor_ligero.c
	
.PHONY: clean

clean:
	rm *.o
