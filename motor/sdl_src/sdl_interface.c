/*******************/
/* sdl_interface.c */
/*******************/
/* author: RoLo    */
/* date:   16/9/01 */
/* ver:    0.1     */
/*******************/
/*****************************************************/
/* Este es el source de un interface temporero,      */
/*   el cual abre una pantalla con controles basicos */
/*   que hacen mover el motor en ambas direcciones a */
/*   diferentes velocidades.                         */
/*****************************************************/

#include "include/sdl_interface.h"
#include "include/motor.h"
#include "linux/include/linux_motor_ligero.h"
#include "linux/include/linux_motor_lento.h"

#define BASEPORT0 0x3bc /* lp0 */
#define BASEPORT 0x378 /* lp1 */
#define BASEPORT2 0x278 /* lp2 */

int main(void)
{
  static SDL_Surface *temp, *icon;
  SDL_Surface *a[12];
  int i = 0;
  int low_or_high = 10000;
  SDL_Event event; 

  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, 0);

  /* Get access to the ports */
  if (ioperm(BASEPORT, 3, 1)) { printf("Debes tener privilegios de root para usar este programa.\n");perror("ioperm"); exit(1); 
}

  /* Set the data signals (D0-7) of the port to all low (0) */
  outb(0x0, BASEPORT); 
  printf("\nAll lines set to OFF.\n");

  /* Initialize SDL's video system and check for errors. */
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Unable to initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }

  /* Make sure SDL_Quit gets called when the program exits! */
  atexit(SDL_Quit);

  /* Attempt to set name and icon for the window that we will use. */
  SDL_WM_SetCaption("Motor Test Program", "IMGS/mtp.png");
  icon = IMG_Load("IMGS/mtp.png");
  SDL_WM_SetIcon(icon, NULL);

  /* Attempt to set a 300x80 hicolor (16-bit) video mode. */
  screen = SDL_SetVideoMode(300, 80, 16, SDL_DOUBLEBUF);
  if (screen == NULL) {
    printf("Unable to set video mode: %s\n", SDL_GetError());
    exit(1);
  }

  /* Load the background. */
  temp = IMG_Load("IMGS/background.png");
  background = SDL_DisplayFormat(temp);
  if (background == NULL) {
    printf("Unable to load background: %s\n", SDL_GetError());
    exit(1);
  }
  SDL_FreeSurface(temp);

  Load_images(a);

  /* Handle Events. */
  while ( SDL_WaitEvent(&event) != 0 ) {
    SDL_keysym keysym;
    /* Draw the background. */
    
    src.x = 0;
    src.y = 0;
    src.w = background->w;
    src.h = background->h;
    dest = src;
    
    SDL_BlitSurface(background, &src, screen, &dest);
    
    /* Draw the buttons. */
    src.w = a[11]->w;
    src.h = a[11]->h;
    dest.y = 5;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(a[11], &src, screen, &dest);
    
    src.w = a[11]->w;
    src.h = a[11]->h;
    dest.x = 242;
    dest.y = 5;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(a[11], &src, screen, &dest);
    
    src.w = a[2]->w;
    src.h = a[2]->h;
    dest.x = 63;
    dest.y = 0;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(a[2], &src, screen, &dest);
    
    src.w = a[3]->w;
    src.h = a[3]->h;
    dest.x = 180;
    dest.y = 0;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(a[3], &src, screen, &dest);
    
    src.w = a[6]->w;
    src.h = a[6]->h;
    dest.x = 63;
    dest.y = 44;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(a[6], &src, screen, &dest);
    
    src.w = a[7]->w;
    src.h = a[7]->h;
    dest.x = 180;
    dest.y = 44;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(a[7], &src, screen, &dest);
    
    /* Handle Events. */
    switch (event.type) {
    case SDL_KEYDOWN:

      keysym = event.key.keysym;

      switch(keysym.sym) {

      case SDLK_PAGEUP:

	src.w = a[10]->w;
	src.h = a[10]->h;
	dest.x = 242;
	dest.y = 5;
	dest.w = src.w;
	dest.h = src.h;
	SDL_BlitSurface(a[10], &src, screen, &dest);

	if (low_or_high != 100000) low_or_high += 10000;

	usleep(100000);

	printf("usleep %d\n", low_or_high);
	break;

      case SDLK_PAGEDOWN:

	src.w = a[10]->w;
	src.h = a[10]->h;
	dest.x = 0;
	dest.y = 5;
	dest.w = src.w;
	dest.h = src.h;
	SDL_BlitSurface(a[10], &src, screen, &dest);

	if (low_or_high != 10000) low_or_high -= 10000;

	usleep(100000);

	printf("usleep %d\n", low_or_high);
	break;

      case SDLK_KP0:

	printf("Boton 0\n"); usleep(low_or_high);
	break;

      case SDLK_KP1:

	src.w = a[8]->w;
	src.h = a[8]->h;
	dest.x = 63;
	dest.y = 44;
	dest.w = src.w;
	dest.h = src.h;
	SDL_BlitSurface(a[8], &src, screen, &dest);

	motor_lento(BASEPORT, -1);

	printf("Boton 1\n"); usleep(low_or_high);
	break;

      case SDLK_KP2:

	printf("Boton 2\n"); usleep(low_or_high);
	break;

      case SDLK_KP3:

	src.w = a[9]->w;
	src.h = a[9]->h;
	dest.x = 180;
	dest.y = 44;
	dest.w = src.w;
	dest.h = src.h;
	SDL_BlitSurface(a[9], &src, screen, &dest);

	motor_lento(BASEPORT, 1);
	
	printf("Boton 3\n"); usleep(low_or_high);
	break;

      case SDLK_KP4:

	src.w = a[4]->w;
	src.h = a[4]->h;
	dest.x = 63;
	dest.y = 0;
	dest.w = src.w;
	dest.h = src.h;
	SDL_BlitSurface(a[4], &src, screen, &dest);

	motor_ligero(BASEPORT, 1);

	printf("Boton 4\n"); usleep(low_or_high);
	break;

      case SDLK_KP5:

	printf("Boton 5\n"); usleep(low_or_high);
	break;

      case SDLK_KP6:

	src.w = a[5]->w;
	src.h = a[5]->h;
	dest.x = 180;
	dest.y = 0;
	dest.w = src.w;
	dest.h = src.h;
	SDL_BlitSurface(a[5], &src, screen, &dest);

	motor_ligero(BASEPORT, -1);

	printf("Boton 6\n"); usleep(low_or_high);
	break;

      case SDLK_KP7:

	printf("Boton 7\n"); usleep(low_or_high);
	break;

      case SDLK_KP8:

	printf("Boton 8\n"); usleep(low_or_high);
	break;

      case SDLK_KP9:

	printf("Boton 9\n"); usleep(low_or_high);
	break;

      case SDLK_ESCAPE:  /* If Esc is pressed return 0. */

	exit(0);
	break;
      }
      break;
    case SDL_QUIT: /* If the close window button from the */
      exit(0);
      break;
    }

    SDL_UpdateRect(screen, 0, 0, 0, 0);
  }
  
  /* Free memory used by Drawings. */
  for (i = 0; i < 12; i++) SDL_FreeSurface(a[i]);
  SDL_FreeSurface(icon);
  if ( Free_images()){printf("\nError liberando memoria.\n"); exit(1);}

  outb(0x0, BASEPORT);
  fprintf(stderr,"\nAll lines set to OFF again.\n");

  /* We don't need the ports anymore */
  if (ioperm(BASEPORT, 3, 0)) {perror("ioperm"); exit(1);}

  return 0;
}
