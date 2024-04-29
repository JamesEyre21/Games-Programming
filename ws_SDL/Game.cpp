#include "Game.h"

Game::Game()
{	
	width = 820;
	height = 620;
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
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_RenderSetLogicalSize(renderer, width, height);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		createEnemies(3);

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
			//std::cout << player.playerRect.x << "," << player.playerRect.y << "\n";
			player.isMoving = true;
			player.playerRect.y -= player.moveSpeed;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_S)
		{
			//std::cout << player.playerRect.x << "," << player.playerRect.y << "\n";
			player.isMoving = true;
			player.playerRect.y += player.moveSpeed;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_A)
		{
			//std::cout << player.playerRect.x << "," << player.playerRect.y << "\n";
			player.isMoving = true;
			player.playerRect.x -= player.moveSpeed;
		}
		if (event.key.keysym.scancode == SDL_SCANCODE_D)
		{
			//std::cout << player.playerRect.x << "," << player.playerRect.y << "\n";
			player.isMoving = true;
			player.playerRect.x += player.moveSpeed;
		}

		break;
	}
}

void Game::update()
{
	/*if (enemy.isMoving)
	{
		if (enemy.enemyRect.x == width - 20)
		{
			enemy.direction = 1;
			enemy.Move();
		}
		else if (enemy.enemyRect.x == 0)
		{
			enemy.direction = 0;
			enemy.Move();
		}
		else
		{
			enemy.Move();
		}
	}*/
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &player.playerRect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (int i = 0; i < enemies.size(); i++)
	{
		SDL_RenderFillRect(renderer, enemies[i]);
	}
	//SDL_RenderFillRect(renderer, &enemy.enemyRect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderPresent(renderer);
}


void Game::createEnemies(int numEnemies)
{
	for (int i = 1; i <= numEnemies; i++)
	{
		Enemy* enemy = new Enemy(0, 20*i, 20, 40);
		enemies.push_back(enemy);
	}
}


/*Cleans the game ebfore closing*/
void Game::clean()
{
	SDL_DestroyWindow(window); //Destroys the window
	SDL_DestroyRenderer(renderer); //Destroys the renderer
	SDL_Quit(); //Cleans all initialised subsystems
}