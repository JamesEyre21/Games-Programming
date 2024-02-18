// ws_SDL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SDL.h"
#include <iostream>

int main(int argc, char* argv[])
{
    //Try to initialise.. if we can't, then exit this program:
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;

    //800X600, centre of screen
    SDL_Window* window = SDL_CreateWindow("James Eyre: 26464488 | CGP2015M", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    SDL_Event event;
    bool isFullscreen = false;
    SDL_bool isRunning = SDL_TRUE;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = SDL_FALSE;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_F)
                {
                    isFullscreen = !isFullscreen;
                    if (isFullscreen)
                    {
                        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                    }
                    else
                    {
                        SDL_SetWindowFullscreen(window, 0);
                    }
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_Q)
                {
                    isRunning = SDL_FALSE;
                }
                break;
            default: break;
            }
        }
    }
    //Finally, exit
    return 0;
}