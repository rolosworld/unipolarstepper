/************************/
/* linux_motor_ligero.c */
/************************/

#include "include/linux_motor_ligero.h"

int i = 0;
/*
   Funcion para mover el motor hacia la direccion dada por "rotacion"
   si rotacion es igual a 1 el motor se mueve counterclockwise (creo, jajaja),
   de lo contrario gira clockwise, asumo q en este caso rotacion seria igual a -1
*/

void motor_ligero(unsigned long int bport, signed short int rotacion)
{
  if (rotacion == 1){
    switch(i)
      {
      case 0 : { outb(1, bport); i += 1; break; }
      case 1 : { outb(2, bport); i += 1; break; }
      case 2 : { outb(4, bport); i += 1; break; }
      case 3 : { outb(8, bport); i = 0; break; }
      }
  }
  else {
    switch(i)
      {
      case 0 : { outb(8, bport); i += 1; break; }
      case 1 : { outb(4, bport); i += 1; break; }
      case 2 : { outb(2, bport); i += 1; break; }
      case 3 : { outb(1, bport); i = 0; break; }
      }
  }
}
