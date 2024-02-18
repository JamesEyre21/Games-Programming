// ws_SDL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "SDL.h"
#include <iostream>

int main(int argc, char* argv[])
{
    //Try to initialise.. if we can't, then exit this program:
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;

    //Creates 800X600 window at the centre of the screen
    SDL_Window* window = SDL_CreateWindow("James Eyre: 26464488 | CGP2015M", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    //Creates a renderer which draws to the window surface
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);

    //Clears everything on the window -- paint over with last know colour
    SDL_RenderClear(renderer);

    //Creates a rectangle
    SDL_Rect r;
    r.x = 30;
    r.y = 30;
    r.w = 100;
    r.h = 50;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &r);


    //Tell SDL we have finished drawing, SDL will actually show our changes
    SDL_RenderPresent(renderer);

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