/************************/
/* linux_motor_lento.c */
/************************/

#include "include/linux_motor_lento.h"

int j = 0;

/*
   Funcion para mover el motor hacia la direccion daba por "rotacion"
   si rotacion == 1 el motor se mueve counterclockwise (creo, jajaja),
   de lo contrario gira clockwise, asumo q en este caso rotacion seria  == a -1
*/

void motor_lento(unsigned long int bport, signed short int rotacion)
{
  if (rotacion == 1){
    switch(j)
      {
      case 0 : {
	outb(0x01, bport); Delay();
        j += 1;
	break; }

      case 1 : {
	outb(0x03, bport); Delay();
        j += 1;
	break; }

      case 2 : {
	outb(0x02, bport); Delay();
        j += 1;
	break; }

      case 3 : {
	outb(0x06, bport); Delay();
        j += 1;
	break; }

      case 4 : {
	outb(0x04, bport); Delay();
        j += 1;
	break; }

      case 5 : {
	outb(0x12, bport); Delay();
        j += 1;
	break; }

      case 6 : {
	outb(0x08, bport); Delay();
        j += 1;
	break; }

      case 7 : {
	outb(0x09, bport); Delay();
        j = 0;
	break; }
      }
  }
  else {
    switch(j)
      {
      case 0 : {
	outb(0x09, bport); Delay();
        j += 1;
	break; }

      case 1 : {
	outb(0x08, bport); Delay();
        j += 1;
	break; }

      case 2 : {
	outb(0x12, bport); Delay();
        j += 1;
	break; }

      case 3 : {
	outb(0x04, bport); Delay();
        j += 1;
	break; }

      case 4 : {
	outb(0x06, bport); Delay();
        j += 1;
	break; }

      case 5 : {
	outb(0x02, bport); Delay();
        j += 1;
	break; }

      case 6 : {
	outb(0x03, bport); Delay();
        j += 1;
	break; }

      case 7 : {
	outb(0x01, bport); Delay();
        j = 0;
	break; }
      }
  }
  fprintf(stderr,".");
}
