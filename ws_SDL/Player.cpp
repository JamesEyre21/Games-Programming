#include "Player.h"

Player::Player()
{
	moveSpeed = 25;

	playerRect.x = 400;
	playerRect.y = 600;
	playerRect.w = 20;
	playerRect.h = 20;

	isMoving = false;
	movingLeft = false;
	movingRight = true;
}