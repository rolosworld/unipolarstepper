/******************/
/* free_images.c  */
/******************/
/* author: RoLo   */
/* date:   16/9/01*/
/* ver:    0.1    */
/******************/

/* This file tries to free all the images from memory. */

#include "include/free_images.h"

void Free_images(void)
{
    SDL_FreeSurface(background);
    SDL_FreeSurface(screen);
}
