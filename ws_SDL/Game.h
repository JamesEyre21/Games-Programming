#ifndef gameWorld
#define gameWorld

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "RandNum.h"
#include "Player.h"
#include "Enemy.h"
#include "textManager.h"
#include <vector>

class Game
{
public:
	Game(const char* sceneName);
	~Game();

	const char* sceneName;
	int score;
	int countdownTime = 60;
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
	void countdownInterval();
	Uint32 TimerCallBack(Uint32 interval, void* param);

	bool running() { return isRunning; }

private:
	TextManager textManager;
	TextManager textManager2;
	TextManager textManager3;
	Mix_Music* audio_background;
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