#include "Game.h"


Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystems initialised!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}

		isRunning = true;
	}

	else
	{
		isRunning = false;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	
	case SDL_KEYDOWN:
		if (event.key.keysym.scancode == SDL_SCANCODE_F)
		{			
			if (isRunning)
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
			isRunning = false;
		}
		break;
	}
}

void Game::update()
{
	/*count++;
	std::cout << count << std::endl;*/
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_Rect rect;
	rect.x = 400;
	rect.y = 300;
	rect.w = 50;
	rect.h = 50;

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}