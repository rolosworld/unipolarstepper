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

int main(void)
{
  static SDL_Surface *temp;
  SDL_Surface *a[12];
  int i = 0;
  /* Initialize SDL's video system and check for errors. */
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Unable to initialize SDL: %s\n", SDL_GetError());
    return 1;
  }

  /* Make sure SDL_Quit gets called when the program exits! */
  atexit(SDL_Quit);

  /* Attempt to set name and icon for the window that we will use. */
  SDL_WM_SetCaption("Motor Test Program", "IMGS/mtp.png");
  SDL_WM_SetIcon(IMG_Load("IMGS/mtp.png"), NULL);

  /* Attempt to set a 300x80 hicolor (16-bit) video mode. */
  screen = SDL_SetVideoMode(300, 80, 16, SDL_DOUBLEBUF);
  if (screen == NULL) {
    printf("Unable to set video mode: %s\n", SDL_GetError());
    return 1;
  }

  /* Load the background. */
  temp = IMG_Load("IMGS/background.png");
  background = SDL_DisplayFormat(temp);
  if (background == NULL) {
    printf("Unable to load background: %s\n", SDL_GetError());
    return 1;
  }
  SDL_FreeSurface(temp);

  Load_images(a);

  /* Draw the background. */

  src.x = 0;
  src.y = 0;
  src.w = background->w;
  src.h = background->h;
  dest = src;

  SDL_BlitSurface(background, &src, screen, &dest);

  /* Draw the buttons. */
  src.w = a[10]->w;
  src.h = a[10]->h;
  dest.y = 5;
  dest.w = src.w;
  dest.h = src.h;
  SDL_BlitSurface(a[10], &src, screen, &dest);

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

  SDL_UpdateRect(screen, 0, 0, 0, 0);

  /* Handle Events. */
  if (HandleEvent(a, &screen)) printf("Error handling events.\n") ;

  /* Free memory used by Drawings. */
  for (i = 0; i < 12; i++) SDL_FreeSurface(a[i]);
  Free_images();
  return 0;
}
