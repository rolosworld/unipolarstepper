/* motor.c - control a unipolar stepper motor
 *
 * Author : Mark Chang
 * Date   : 18 July 2001
 * Description :
 *   Single coil excitation for a 5 wire 
 * for a unipolar stepper motor (rescued from a floppy drive) 
 * using a PC
 *
 *        7   6   5   4   3   2   1   0   I/O Port
 *      +---+---+---+---+---+---+---+---+ ========
 * Data |   |   |   |   | C4| C3| C2| C1| Base = 278/378/3BC Hex
 *      +---+---+---+---+---+---+---+---+
 */

#include "include/motor.h"
#include "linux/include/linux_motor_ligero.h"
#include "linux/include/linux_motor_lento.h"

#define BASEPORT0 0x3bc /* lp0 */
#define BASEPORT 0x378 /* lp1 */
#define BASEPORT2 0x278 /* lp2 */

void KeyPress(void)
{
  printf(" <Press any key to continue>");
  while (!getchar()); /* wait for key press */
  printf("\n");
}

int main()
{
  int i;

  /* Get access to the ports */
  if (ioperm(BASEPORT, 3, 1)) {perror("ioperm"); exit(1);}
  
  /* Set the data signals (D0-7) of the port to all low (0) */
  outb(0x0, BASEPORT); 
  fprintf(stderr,"\nAll lines set to OFF.");
  KeyPress();

  fprintf(stderr,"Clockwise rotation\n");
  
  for (i=1; i<=25; i++)
    {
      motor_ligero(BASEPORT, -1);
    }
  KeyPress();

  fprintf(stderr,"Anticlockwise rotation\n");

  for (i=1; i<=25; i++)
    {
      motor_ligero(BASEPORT, 1);
    }
  KeyPress();

  for (i=1; i<=25; i++)
    {
      motor_lento(BASEPORT, -1);
    }
  KeyPress();

  fprintf(stderr,"Anticlockwise rotation\n");

  for (i=1; i<=25; i++)
    {
      motor_lento(BASEPORT, 1);
    }
  KeyPress();

  outb(0x0, BASEPORT); 
  fprintf(stderr,"All lines set to OFF again.");
  KeyPress();

  /* We don't need the ports anymore */
  if (ioperm(BASEPORT, 3, 0)) {perror("ioperm"); exit(1);}

  exit(0);
}
