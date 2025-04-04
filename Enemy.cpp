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
	if (moveForce.x > 0) {
		moveForce = moveForce - frictionForce;
	}
	if (moveForce.x < 0) {
		moveForce = moveForce + frictionForce;
	}

	position = position + moveForce;
}

Vec2 Enemy::GetMoveForce()
{
	return this->moveForce;
}

void Enemy::SetMoveForce(Vec2 moveForce)
{
	this->moveForce = moveForce;
}
