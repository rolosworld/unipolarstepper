/*******************/
/* sdl_interface.c */
/*******************/
/* author: RoLo    */
/* date:   16/9/01 */
/* ver:    0.1     */
/*******************/

/* Este es el source de un interface temporero,      */
/*   el cual abre una pantalla con controles basicos */
/*   que hacen mover el motor en ambas direcciones a */
/*   diferentes velocidades.                         */

#include "sdl_interface.h"

int main(void)
{

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

/************************************************************************************/
/************************************************************************************/
/*                                   Loads images.                                  */
/*    Load_images();                                                                */
/************************************************************************************/
/*    temp = IMG_Load("IMGS/fast.png");                                             */
/*    fast = SDL_DisplayFormat(temp);                                               */
/*    if (fast == NULL) {                                                           */
/*	printf("Unable to load image IMGS/fast.png .\n");                           */
/*	exit(0);                                                                    */
/*    }                                                                             */
/*    SDL_FreeSurface(temp);                                                        */
/************************************************************************************/
/*                                                                                  */
/*    temp = IMG_Load("IMGS/low.png");                                              */
/*    low = SDL_DisplayFormat(temp);                                                */
/*    if (low == NULL) {                                                            */
/*	printf("Unable to load image IMGS/low.png .\n");                            */
/*	exit(0);                                                                    */
/*    }                                                                             */
/*    SDL_FreeSurface(temp);                                                        */
/*                                                                                  */
/************************************************************************************/

    temp = IMG_Load("IMGS/fast_left.png");
    fast_left = SDL_DisplayFormat(temp);
    if (fast_left == NULL) {
	printf("Unable to load image IMGS/fast_left.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

    temp = IMG_Load("IMGS/fast_right.png");
    fast_right = SDL_DisplayFormat(temp);
    if (fast_right == NULL) {
	printf("Unable to load image IMGS/fast_right.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

    temp = IMG_Load("IMGS/fast_left_pressed.png");
    fast_left_pressed = SDL_DisplayFormat(temp);
    if (fast_left_pressed == NULL) {
	printf("Unable to load image IMGS/fast_left_pressed.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

    temp = IMG_Load("IMGS/fast_right_pressed.png");
    fast_right_pressed = SDL_DisplayFormat(temp);
    if (fast_right_pressed == NULL) {
	printf("Unable to load image IMGS/fast_right_pressed.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

    temp = IMG_Load("IMGS/low_left.png");
    low_left = SDL_DisplayFormat(temp);
    if (low_left == NULL) {
	printf("Unable to load image IMGS/low_left.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/
    temp = IMG_Load("IMGS/low_right.png");
    low_right = SDL_DisplayFormat(temp);
    if (low_right == NULL) {
	printf("Unable to load image IMGS/low_right.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

    temp = IMG_Load("IMGS/low_left_pressed.png");
    low_left_pressed = SDL_DisplayFormat(temp);
    if (low_left_pressed == NULL) {
	printf("Unable to load image IMGS/low_left_pressed.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

    temp = IMG_Load("IMGS/low_right_pressed.png");
    low_right_pressed = SDL_DisplayFormat(temp);
    if (low_right_pressed == NULL) {
	printf("Unable to load image IMGS/low_right_pressed.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

    temp = IMG_Load("IMGS/green_circle.png");
    green_circle = SDL_DisplayFormat(temp);
    if (green_circle == NULL) {
	printf("Unable to load image IMGS/green_circle.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

    temp = IMG_Load("IMGS/red_circle.png");
    red_circle = SDL_DisplayFormat(temp);
    if (red_circle == NULL) {
	printf("Unable to load image IMGS/red_circle.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);
/***********************************************************************************/
/***********************************************************************************/

/* Draw the background. */

    src.x = 0;
    src.y = 0;
    src.w = background->w;
    src.h = background->h;
    dest = src;

    SDL_BlitSurface(background, &src, screen, &dest);

    src.w = green_circle->w;
    src.h = green_circle->h;
    dest.y = 5;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(green_circle, &src, screen, &dest);

    src.w = red_circle->w;
    src.h = red_circle->h;
    dest.x = 242;
    dest.y = 5;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(red_circle, &src, screen, &dest);

    src.w = fast_left->w;
    src.h = fast_left->h;
    dest.x = 63;
    dest.y = 0;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(fast_left, &src, screen, &dest);

    src.w = fast_right->w;
    src.h = fast_right->h;
    dest.x = 180;
    dest.y = 0;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(fast_right, &src, screen, &dest);

    src.w = low_left->w;
    src.h = low_left->h;
    dest.x = 63;
    dest.y = 44;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(low_left, &src, screen, &dest);

    src.w = low_right->w;
    src.h = low_right->h;
    dest.x = 180;
    dest.y = 44;
    dest.w = src.w;
    dest.h = src.h;
    SDL_BlitSurface(low_right, &src, screen, &dest);

    SDL_UpdateRect(screen, 0, 0, 0, 0);
/* Handle Events. */

    HandleEvent();

    return 0;
}








