CC=gcc
CPP=g++
CFLAGS=-O -W -Wall
DEBFLAGS=-ggdb
LIBS=`sdl-config --cflags --libs` -LSDL_image
LINSRC=linux/

motor: $(LINSRC)linux_motor_ligero.o $(LINSRC)linux_motor_lento.o delay.o motor.o
	$(CC) $(LINSRC)linux_motor_ligero.o $(LINSRC)linux_motor_lento.o delay.o motor.o -o motor

motor.o: motor.c
	$(CC) $(CFLAGS) -c motor.c

delay.o: delay.c
	$(CC) $(CFLAGS) -c delay.c

linux_motor_ligero.o: linux_motor_ligero.c
	$(CC) $(CFLAGS) -c $(LINSRC)linux_motor_ligero.c

linux_motor_lento.o: linux_motor_lento.c
	$(CC) $(CFLAGS) -c $(LINSRC)linux_motor_lento.c

.PHONY: clean

clean:
	rm *.o motor
	rm linux/*.o
