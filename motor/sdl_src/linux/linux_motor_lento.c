/************************/
/* linux_motor_lento.c  */
/************************/

#include "include/linux_motor_lento.h"

int j = 0;

/*
   Funcion para mover el motor hacia la direccion daba por "rotacion"
   si rotacion es igual a 1 el motor se mueve counterclockwise (creo, jajaja),
   de lo contrario gira clockwise, asumo q en este caso rotacion seria  igual a -1
*/

void motor_lento(unsigned long int bport, signed short int rotacion)
{
  if (rotacion == 1){
    switch(j)
      {
      case 0 : { outb(1, bport); j += 1; break; }
      case 1 : { outb(3, bport); j += 1; break; }
      case 2 : { outb(2, bport); j += 1; break; }
      case 3 : { outb(6, bport); j += 1; break; }
      case 4 : { outb(4, bport); j += 1; break; }
      case 5 : { outb(12, bport); j += 1; break; }
      case 6 : { outb(8, bport); j += 1; break; }
      case 7 : { outb(9, bport); j = 0; break; }
      }
  }
  else {
    switch(j)
      {
      case 0 : { outb(9, bport); j += 1; break; }
      case 1 : { outb(8, bport); j += 1; break; }
      case 2 : { outb(12, bport); j += 1; break; }
      case 3 : { outb(4, bport); j += 1; break; }
      case 4 : { outb(6, bport); j += 1; break; }
      case 5 : { outb(2, bport); j += 1; break; }
      case 6 : { outb(3, bport); j += 1; break; }
      case 7 : { outb(1, bport); j = 0; break; }
      }
  }
}
