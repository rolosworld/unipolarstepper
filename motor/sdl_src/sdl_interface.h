/*******************/
/* sdl_interface.h */
/*******************/
/* author: RoLo    */
/* date:   16/9/01 */
/* ver:    0.1     */
/*******************/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Rect src, dest;

static SDL_Surface *screen;
static SDL_Surface *background;
static SDL_Surface *temp;

static SDL_Surface *fast;
static SDL_Surface *fast_left;
static SDL_Surface *fast_left_pressed;
static SDL_Surface *fast_right;
static SDL_Surface *fast_right_pressed;
static SDL_Surface *green_circle;
static SDL_Surface *low;
static SDL_Surface *low_left;
static SDL_Surface *low_left_pressed;
static SDL_Surface *low_right;
static SDL_Surface *low_right_pressed;
static SDL_Surface *red_circle;


/* void Load_images(void); */


void HandleEvent(void);


