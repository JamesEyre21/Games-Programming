#ifndef gameWorld
#define gameWorld

#include "SDL.h"
#include "SDL_image.h"
#include "RandNum.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game
{
public:
	Game();
	~Game();

	int score;
	int width;
	int height;
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void input();
	void update();
	void render();
	void clean();

	void createEnemies(int numEnemies);
	void moveEnemies();
	void checkBounds();

	bool running() { return isRunning; }

private:
	RandNum randNum;
	Player player;
	std::vector<Enemy*> enemies;

	bool isRunning;
	bool isFullscreen;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* playerSurface;
	SDL_Texture* playerTexture;
	SDL_Surface* enemySurface;
	SDL_Texture* enemyTexture;
};

#endif