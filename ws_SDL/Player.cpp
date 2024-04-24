#include "Player.h"

Player::Player()
{
	moveSpeed = 10;
	playerX = 400;
	playerY = 580;

	playerRect.x = playerX;
	playerRect.y = playerY;
	playerRect.w = 50;
	playerRect.h = 20;

	isMoving = false;
	movingUp = false;
	movingDown = false;
	movingLeft = false;
	movingRight = false;
}