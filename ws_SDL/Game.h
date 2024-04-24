#ifndef gameWorld
#define gameWorld

#include "SDL.h"
#include "Player.h"
#include <iostream>

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

	bool running() { return isRunning; }

private:
	Player player;

	bool isRunning;
	bool isFullscreen;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif