/*******************/
/*     motor.c     */
/*******************/
/* author: RoLo    */
/* date:   28/9/01 */
/* ver:    0.1     */
/*******************/

#include "include/motor.h"
#include "linux/include/linux_motor_ligero.h"
#include "linux/include/linux_motor_lento.h"
#include <curses.h>
#include <term.h>

#define BASEPORT0 0x3bc /* lp0 */
#define BASEPORT 0x378 /* lp1 */
#define BASEPORT2 0x278 /* lp2 */
#define KEYBOARD 0x60 /* keyboard */

/* Keyboard Scan Codes that we will use. */
#define KEY_UPARROW   0x48
#define KEY_DOWNARROW 0x50
#define KEY_LEFTARROW 0x4b
#define KEY_RIGHTARROW 0x4d
#define KEY_PAGE_DOWN 0x51
#define KEY_PAGE_UP 0x49
#define KEY_PAD_0 0x52
#define KEY_PAD_1 0x4f
#define KEY_PAD_2 0x50
#define KEY_PAD_3 0x51
#define KEY_PAD_4 0x4b
#define KEY_PAD_5 0x4c
#define KEY_PAD_6 0x4d
#define KEY_PAD_7 0x47
#define KEY_PAD_8 0x48
#define KEY_PAD_9 0x49
#define KEY_ESC 0x01

void KeyPress(void)
{
  printf(" <Press any key to continue>");
  while (!getchar()); /* wait for key press */
  printf("\n");
}

int main(void)
{
//  int i;
  unsigned key;

  /* Get access to the ports */
  if (ioperm(BASEPORT, 3, 1)) { perror("ioperm"); exit(1); }
  if (ioperm(KEYBOARD, 1, 1)) { perror("ioperm"); exit(1); }

  /* Set the data signals (D0-7) of the port to all low (0) */
  outb(0x0, BASEPORT); 
  fprintf(stderr,"\nAll lines set to OFF.");
  KeyPress();

//  initscr();
//  cbreak();

  key = inb(0x60);

  while (key != 1)
    {
      switch (key) 
	{
	case KEY_PAD_4:
	  {
	    motor_ligero(BASEPORT, -1);
	    break;
	  }
	case KEY_PAD_6:
	  {
	    motor_ligero(BASEPORT, 1);
	    break;
	  }
	case KEY_PAD_3:
	  {
	    motor_lento(BASEPORT, 1);
	    break;
	  }
	case KEY_PAD_1:
	  {
	    motor_lento(BASEPORT, -1);
	    break;
	  }
	}
      printf("%d\n", inb(BASEPORT+1));
      key = inb(0x60);
    }
  outb(0x0, BASEPORT); 

//  endwin();

  fprintf(stderr,"\nAll lines set to OFF again.");
  KeyPress();

  /* We don't need the ports anymore */
  if (ioperm(BASEPORT, 3, 0)) {perror("ioperm"); exit(1);}
  if (ioperm(KEYBOARD, 1, 0)) {perror("ioperm"); exit(1);}

  exit(0);
}
