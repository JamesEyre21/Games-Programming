#include "Enemy.h"

Enemy::Enemy(int x, int y, int height, int width, int direction)
{
	moveSpeed = 1;
	enemyDir = direction;
	isMoving = true;

	enemyRect.x = x;
	enemyRect.y = y;
	enemyRect.w = width;
	enemyRect.h = height;

}

void Enemy::Move()
{
	if (enemyDir == 0)
	{
		enemyRect.x += moveSpeed;
	}
	else if (enemyDir == 1)
	{
		enemyRect.x -= moveSpeed;
	}

}