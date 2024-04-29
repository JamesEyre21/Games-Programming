#include "Game.h"

Game* game = nullptr;


int SDL_main(int argc, char* argv[])
{
    const int fps = 60;
    const int frameDelay = 100 / fps;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->width = 820;
    game->height = 620;
    game->init("James Eyre, CGP2015M, 26464488, Game Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game->width, game->height, false);

    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->input();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();

    return 0;
}