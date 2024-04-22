#include "Game.h"

Game* game = nullptr;


int SDL_main(int argc, char* argv[])
{
    game = new Game();

    game->width = 800;
    game->height = 600;
    game->init("Game Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game->width, game->height, false);

    while (game->running())
    {
        game->input();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}