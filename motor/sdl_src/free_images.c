/******************/
/* free_images.c  */
/******************/
/* author: RoLo   */
/* date:   16/9/01*/
/* ver:    0.1    */
/******************/

/* This file tries to free all the images from memory. */

#include "free_images.h"

void Free_images(void)
{
    SDL_FreeSurface(background);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(fast);
    SDL_FreeSurface(fast_left);
    SDL_FreeSurface(fast_left_pressed);
    SDL_FreeSurface(fast_right);
    SDL_FreeSurface(fast_right_pressed);
    SDL_FreeSurface(green_circle);
    SDL_FreeSurface(low);
    SDL_FreeSurface(low_left);
    SDL_FreeSurface(low_left_pressed);
    SDL_FreeSurface(low_right);
    SDL_FreeSurface(low_right_pressed);
    SDL_FreeSurface(red_circle);
}
