/*******************/
/* handle_events.c */
/*******************/
/* author: RoLo    */
/* date:   16/9/01 */
/* ver:    0.1     */
/*******************/
/* This source tries to handle all the comands send to the */
/* program while running.                                  */
/*************************/ /*******************************/
/*  SDL Numeric keypad   */ /*  SDL Arrows + Home/End pad  */
/*************************/ /*******************************/
/*	SDLK_KP0	 */ /*         SDLK_UP             */
/*      SDLK_KP1         */ /*         SDLK_DOWN           */
/*	SDLK_KP2	 */ /*         SDLK_RIGHT          */
/*	SDLK_KP3	 */ /* 	       SDLK_LEFT           */
/*	SDLK_KP4	 */ /* 	       SDLK_INSERT         */
/*	SDLK_KP5	 */ /* 	       SDLK_HOME           */
/*	SDLK_KP6	 */ /* 	       SDLK_END	           */
/*	SDLK_KP7	 */ /*         SDLK_PAGEUP	   */
/*	SDLK_KP8	 */ /*         SDLK_PAGEDOWN       */
/*	SDLK_KP9	 */ /*******************************/
/*	SDLK_KP_PERIOD	 */
/*	SDLK_KP_DIVIDE	 */
/*	SDLK_KP_MULTIPLY */
/*	SDLK_KP_MINUS	 */
/*	SDLK_KP_PLUS	 */
/*	SDLK_KP_ENTER	 */
/*	SDLK_KP_EQUALS	 */
/*************************/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "include/motor.h"

SDL_Rect src, dest;
int low_or_high = 10000;

short int HandleEvent(SDL_Surface *(a[]), SDL_Surface *screen)
{
  SDL_Event event; 
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, 0);
  /* Check for events */
  /* If a key is pressed do something. */
  while ( SDL_WaitEvent(&event) != 0 ) {
    SDL_keysym keysym;
    switch (event.type) {
    case SDL_KEYDOWN:
      keysym = event.key.keysym;
      switch(keysym.sym) {
      case SDLK_PAGEUP:
	if (low_or_high != 100000) low_or_high += 10000;
	usleep(100000);
	printf("usleep %d\n", low_or_high);
	break;
      case SDLK_PAGEDOWN:
	if (low_or_high != 10000) low_or_high -= 10000;
	usleep(100000);
	printf("usleep %d\n", low_or_high);
	break;
      case SDLK_KP0:
	printf("Boton 0\n"); usleep(low_or_high);
	break;
      case SDLK_KP1:
	printf("Boton 1\n"); usleep(low_or_high);
	break;
      case SDLK_KP2:
	printf("Boton 2\n"); usleep(low_or_high);
	break;
      case SDLK_KP3:
	printf("Boton 3\n"); usleep(low_or_high);
	break;
      case SDLK_KP4:
	printf("Boton 4\n"); usleep(low_or_high);
	break;
      case SDLK_KP5:
	printf("Boton 5\n"); usleep(low_or_high);
	break;
      case SDLK_KP6:
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
	return 0;
	break;
      }
      break;
    case SDL_QUIT: /* If the close window button from the */
      return 0;    /* X server is pressed, then return 0. */
      break;
    }
  }
}
