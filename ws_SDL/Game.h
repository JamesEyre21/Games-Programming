#ifndef gameFile
#define gameFile

#include "SDL.h"
#include <iostream>
#include <array>

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
	int count = 0;
	bool isRunning;
	bool isFullscreen;
	SDL_Rect rect;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif