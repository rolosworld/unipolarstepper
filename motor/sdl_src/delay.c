/*************/
/*  delay.c  */
/*************/


#include "include/motor.h"

void Delay(int low_or_high)
{
  /* Sleep for a while (in use) */
  if (SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, low_or_high));
}

/*

SDL_EnableKeyRepeat -- Set keyboard repeat rate.
Synopsis

#include "SDL.h"

int SDL_EnableKeyRepeat(int delay, int interval);

Description

Enables or disables the keyboard repeat rate. delay specifies how long the key must be pressed before it begins repeating, it then repeats at the speed specified by interval. Both delay and interval are expressed in milliseconds.

Setting delay to 0 disables key repeating completely. Good default values are SDL_DEFAULT_REPEAT_DELAY and SDL_DEFAULT_REPEAT_INTERVAL.
Return Value

Returns 0 on success and -1 on failure.

*/
