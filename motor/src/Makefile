CC=gcc
CPP=g++
CFLAGS=-O2 -W -Wall -static 
DEBFLAGS=-ggdb -O -W -Wall -static
LIBS=`sdl-config --cflags --libs` -LSDL_image
LIBS2=-lcurses
LINSRC=linux/

motor: $(LINSRC)linux_motor_ligero.o $(LINSRC)linux_motor_lento.o delay.o motor.o
	$(CC) $(LINSRC)linux_motor_ligero.o $(LINSRC)linux_motor_lento.o delay.o motor.o -o motor $(LIBS2)

motor.o: motor.c
	$(CC) $(DEBFLAGS) -c motor.c

delay.o: delay.c
	$(CC) $(DEBFLAGS) -c delay.c

linux_motor_ligero.o: linux_motor_ligero.c
	$(CC) $(DEBFLAGS) -c $(LINSRC)linux_motor_ligero.c

linux_motor_lento.o: linux_motor_lento.c
	$(CC) $(DEBFLAGS) -c $(LINSRC)linux_motor_lento.c

.PHONY: clean

clean:
	rm *.o motor
	rm linux/*.o
