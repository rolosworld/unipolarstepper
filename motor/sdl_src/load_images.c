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

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void Load_images(SDL_Surface *(a[]))
{
  SDL_Surface *temp;
  /*  Load images to memory in a temp place,*/
  /* then convert the image to the correct  */
  /* display format in a different location */
  /* in memory and free the temp memory, so */
  /* we can use it again to load more       */
  /* images.                                */

  /* temp = IMG_Load("IMGS/fast.png");
  a[0] = SDL_DisplayFormat(temp);    
  if (a[0] == NULL) {
    printf("Unable to load image IMGS/fast.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);
  */
  /*******************************************************/
  /*
  temp = IMG_Load("IMGS/low.png");
  a[1] = SDL_DisplayFormat(temp);
  if (a[1] == NULL) {
    printf("Unable to load image IMGS/low.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);
  */
  /*******************************************************/

  temp = IMG_Load("IMGS/fast_left.png");
  a[2] = SDL_DisplayFormat(temp);
  if (a[2] == NULL) {
    printf("Unable to load image IMGS/fast_left.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);

  /*******************************************************/

  temp = IMG_Load("IMGS/fast_right.png");
  a[3] = SDL_DisplayFormat(temp);
  if (a[3] == NULL) {
    printf("Unable to load image IMGS/fast_right.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);

  /*******************************************************/

  temp = IMG_Load("IMGS/fast_left_pressed.png");
  a[4] = SDL_DisplayFormat(temp);
  if (a[4] == NULL) {
    printf("Unable to load image IMGS/fast_left_pressed.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);

  /*******************************************************/

  temp = IMG_Load("IMGS/fast_right_pressed.png");
  a[5] = SDL_DisplayFormat(temp);
  if (a[5] == NULL) {
    printf("Unable to load image IMGS/fast_right_pressed.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);

  /*******************************************************/

  temp = IMG_Load("IMGS/low_left.png");
  a[6] = SDL_DisplayFormat(temp);
  if (a[6] == NULL) {
    printf("Unable to load image IMGS/low_left.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);

  /*******************************************************/
  temp = IMG_Load("IMGS/low_right.png");
  a[7] = SDL_DisplayFormat(temp);
  if (a[7] == NULL) {
    printf("Unable to load image IMGS/low_right.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);

  /*******************************************************/

  temp = IMG_Load("IMGS/low_left_pressed.png");
  a[8] = SDL_DisplayFormat(temp);
  if (a[8] == NULL) {
    printf("Unable to load image IMGS/low_left_pressed.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);

  /*******************************************************/

  temp = IMG_Load("IMGS/low_right_pressed.png");
  a[9] = SDL_DisplayFormat(temp);
  if (a[9] == NULL) {
    printf("Unable to load image IMGS/low_right_pressed.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);

  /*******************************************************/

  temp = IMG_Load("IMGS/green_circle.png");
  a[10] = SDL_DisplayFormat(temp);
  if (a[10] == NULL) {
    printf("Unable to load image IMGS/green_circle.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);

  /*******************************************************/

  temp = IMG_Load("IMGS/red_circle.png");
  a[11] = SDL_DisplayFormat(temp);
  if (a[11] == NULL) {
    printf("Unable to load image IMGS/red_circle.png .\n");
    exit(0);
  }
  SDL_FreeSurface(temp);
}















