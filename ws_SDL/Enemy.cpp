#include "Enemy.h"

Enemy::Enemy(int x, int y, int height, int width)
{
	moveSpeed = 1;
	isMoving = true;

	enemyRect.x = x;
	enemyRect.y = y;
	enemyRect.w = width;
	enemyRect.h = height;

}

void Enemy::Move()
{
	if (direction == 0)
	{
		enemyRect.x += moveSpeed;
	}
	else if (direction == 1)
	{
		enemyRect.x -= moveSpeed;
	}

}