/************************/
/* linux_motor_ligero.c */
/************************/

#include "include/linux_motor_ligero.h"

int i = 0;
/*
   Funcion para mover el motor hacia la direccion daba por "rotacion"
   si rotacion == 1 el motor se mueve counterclockwise (creo, jajaja),
   de lo contrario gira clockwise, asumo q en este caso rotacion seria  == a -1
*/

void motor_ligero(unsigned long int bport, signed short int rotacion)
{
  if (rotacion == 1){
    switch(i)
      {
      case 0 : {
	outb(1, bport); Delay();
        i += 1;
	break; }

      case 1 : {
	outb(2, bport); Delay();
        i += 1;
	break; }

      case 2 : {
	outb(4, bport); Delay();
        i += 1;
	break; }

      case 3 : {
	outb(8, bport); Delay();
        i = 0;
	break; }
      }
  }
  else {
    switch(i)
      {
      case 0 : {
	outb(8, bport); Delay();
        i += 1;
	break; }

      case 1 : {
	outb(4, bport); Delay();
        i += 1;
	break; }

      case 2 : {
	outb(2, bport); Delay();
        i += 1;
	break; }

      case 3 : {
	outb(1, bport); Delay();
        i = 0;
	break; }
      }
  }
//  fprintf(stderr,".");
}
