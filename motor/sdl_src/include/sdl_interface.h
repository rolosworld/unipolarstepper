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

short int HandleEvent(SDL_Surface *, SDL_Surface *);
void Load_images(SDL_Surface *);

inline int Free_images(void);
