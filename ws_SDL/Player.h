#ifndef playerController
#define playerController

#include "SDL.h"
#include "SDL_image.h"

class Player
{
public:
	Player();

	SDL_Rect playerRect;
	int moveSpeed;
	bool isMoving;
	bool movingLeft;
	bool movingRight;
};

#endif