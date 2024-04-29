#ifndef gameWorld
#define gameWorld

#include "SDL.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class Game
{
public:
	Game();
	~Game();

	int width;
	int height;
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void input();
	void update();
	void render();
	void clean();

	void createEnemies(int numEnemies);

	bool running() { return isRunning; }

private:
	Player player;
	std::vector<Enemy*> enemies;

	bool isRunning;
	bool isFullscreen;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif