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


#include "sdl_interface.h"

unsigned short int low_or_high = 0;

void HandleEvent(void)
{
    SDL_Event event; 
    
    /* Check for events */
    while ( SDL_WaitEvent(&event) != 0 ) {
	SDL_keysym keysym;
	switch (event.type) {
	    case SDL_KEYDOWN:
		keysym = event.key.keysym;
		switch(keysym.sym) {
		    case SDLK_PAGEUP:
			low_or_high = 0;
			printf("Boton PU\n");
			break;
		    case SDLK_PAGEDOWN:
			low_or_high = 1;
			printf("Boton PD\n");
			break;
		    case SDLK_KP0:
			printf("Boton 0\n");
			break;
		    case SDLK_KP1:
			printf("Boton 1\n");
			break;
		    case SDLK_KP2:
			printf("Boton 2\n");
			break;
		    case SDLK_KP3:
			printf("Boton 3\n");
			break;
		    case SDLK_KP4:
			printf("Boton 4\n");
			break;
		    case SDLK_KP5:
			printf("Boton 5\n");
			break;
		    case SDLK_KP6:
			printf("Boton 6\n");
			break;
		    case SDLK_KP7:
			printf("Boton 7\n");
			break;
		    case SDLK_KP8:
			printf("Boton 8\n");
			break;
		    case SDLK_KP9:
			printf("Boton 9\n");
			break;
		}
		break;
	    case SDL_QUIT:
		Free_images();
		exit(0);
		break;
	}
    }
}



