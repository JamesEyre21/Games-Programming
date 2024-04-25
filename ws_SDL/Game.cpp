#include "Game.h"


Game::Game()
{
	width = 800;
	height = 600;
	isRunning = true;
	isFullscreen = false;
}

Game::~Game()
{

}

/*Initialises the window and renderer*/
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		isFullscreen = true;
		flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Things initialised!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_RenderSetLogicalSize(renderer, width, height);
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

/*Handles events, such as inputs*/
void Game::input()
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
			if (isRunning && !isFullscreen)
			{
				SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
				isFullscreen = true;
 			}
			else
			{
				SDL_SetWindowFullscreen(window, 0);
				isFullscreen = false;
			}
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		{
			isRunning = false;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
		{
			player.isMoving = !player.isMoving;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_W)
		{
			player.isMoving = true;
			player.playerRect.y -= player.moveSpeed;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_S)
		{
			player.isMoving = true;
			player.playerRect.y += player.moveSpeed;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_A)
		{
			player.isMoving = true;
			player.playerRect.x -= player.moveSpeed;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_D)
		{
			player.isMoving = true;
			player.playerRect.x += player.moveSpeed;
		}


		break;
	}
}

void Game::update()
{
	
	
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &player.playerRect);

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