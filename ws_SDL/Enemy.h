#ifndef enemyController
#define enemyController

#include "SDL.h"

class Enemy
{
public:
	Enemy(int x, int y, int height, int width);
	void Move();
	

	SDL_Rect enemyRect;
	int direction;
	bool isMoving;
private:
	int moveSpeed;
};

#endif