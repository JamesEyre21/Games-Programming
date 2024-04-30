#ifndef enemyController
#define enemyController

#include "SDL.h"
#include "SDL_image.h"

class Enemy
{
public:
	Enemy(int x, int y, int height, int width, int direction);
	void Move();
	

	SDL_Rect enemyRect;
	int enemyDir;
	bool isMoving;
private:
	int moveSpeed;
};

#endif