#include "Enemy.h"

Enemy::Enemy()
{
	model = Circle{ Vec2(0, 0), 30 };
}

Enemy::~Enemy()
{
}

Enemy::Enemy(Vec2 position)
{
	this->position = position;
	this->model = Circle{ this->position, 30 };
}

void Enemy::Move()
{
	position = position + moveForce;
}
