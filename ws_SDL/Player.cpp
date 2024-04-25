#include "Player.h"

Player::Player()
{
	moveSpeed = 20;
	playerX = 400;
	playerY = 580;

	playerRect.x = playerX;
	playerRect.y = playerY;
	playerRect.w = 50;
	playerRect.h = 20;

	isMoving = false;
	movingLeft = false;
	movingRight = true;
}