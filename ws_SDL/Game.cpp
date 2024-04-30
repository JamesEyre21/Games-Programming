#include "Game.h"

Game::Game()
{	
	score = 0;
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

		isRunning = true;
	}

	else
	{
		isRunning = false;
	}

	playerSurface = IMG_Load("content/player.png");
	playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
	SDL_FreeSurface(playerSurface);

	enemySurface = IMG_Load("content/enemy.png");
	enemyTexture = SDL_CreateTextureFromSurface(renderer, enemySurface);
	SDL_FreeSurface(enemySurface);

	createEnemies(5);
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
	moveEnemies();
	checkBounds();	
}

void Game::render()
{
	SDL_RenderClear(renderer);

	//Draws the playerTexture over the playerRect
	SDL_RenderCopy(renderer, playerTexture, NULL, &player.playerRect);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (int i = 0; i < enemies.size(); i++)
	{
		//Draws the enemyTexture over the enemyRect
		SDL_RenderCopy(renderer, enemyTexture, NULL, &enemies[i]->enemyRect);
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderPresent(renderer);
}


void Game::createEnemies(int numEnemies)
{
	for (int i = 1; i <= numEnemies; i++)
	{
		Enemy* enemy = new Enemy(randNum.randomNum(0, width-20), randNum.randomNum(0, 400), 20, 40, randNum.randomNum(0, 1));
		enemies.push_back(enemy);
	}
}

void Game::moveEnemies()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->isMoving)
		{
			if (enemies[i]->enemyRect.x == width - 20)
			{
				enemies[i]->enemyDir = 1;
				enemies[i]->Move();
			}
			else if (enemies[i]->enemyRect.x == 0)
			{
				enemies[i]->enemyDir = 0;
				enemies[i]->Move();
			}
			else
			{
				enemies[i]->Move();
			}
		}
	}
}

void Game::checkBounds()
{
	if (player.isMoving)
	{
		if (player.playerRect.x > width - 20)
		{
			player.playerRect.x = width - 20;
		}
		else if (player.playerRect.x < 0)
		{
			player.playerRect.x = 0;
		}
		if (player.playerRect.y > height - 20)
		{
			player.playerRect.y = height - 20;
		}
		else if (player.playerRect.y < 0)
		{
			player.playerRect.y = 0;
		}
	}
}


/*Cleans the game ebfore closing*/
void Game::clean()
{
	SDL_DestroyWindow(window); //Destroys the window
	SDL_DestroyRenderer(renderer); //Destroys the renderer
	IMG_Quit(); //Cleans initialised IMG subsystems
	SDL_Quit(); //Cleans all initialised subsystems
}