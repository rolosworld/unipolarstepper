/******************/
/* load_images.c  */
/******************/
/* author: RoLo   */
/* date:   16/9/01*/
/* ver:    0.1    */
/******************/

/* This file tries to load all the images to memory */
/* so we don't have to load them everytime we will  */
/* use them.                                        */

#include "sdl_interface.h"

static void Load_images(void)
{
    temp = IMG_Load("IMGS/fast.png");
    fast = SDL_DisplayFormat(temp);
    if (fast == NULL) {
	printf("Unable to load image IMGS/fast.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

    temp = IMG_Load("IMGS/low.png");
    low = SDL_DisplayFormat(temp);
    if (low == NULL) {
	printf("Unable to load image IMGS/low.png .\n");
	exit(0);
    }
    SDL_FreeSurface(temp);

/*******************************************************/

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

}















