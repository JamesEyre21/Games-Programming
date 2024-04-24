#ifndef playerController
#define playerController

#include "SDL.h"

class Player
{
public:
	Player();



	SDL_Rect playerRect;
	int moveSpeed;
	int playerX;
	int playerY;
	bool isMoving;
	bool movingLeft;
	bool movingRight;
};

#endif