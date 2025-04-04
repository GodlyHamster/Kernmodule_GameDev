#include "Player.h"

Player::Player()
{
	model = Circle{ Vec2(0, 0), 30 };
}

Player::~Player()
{
}

Player::Player(Vec2 position)
{
	this->position = position;
	this->model = Circle{ this->position, 30 };
}

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveForce = moveForce + Vec2(-3.0f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveForce = moveForce + Vec2(3.0f, 0);
	}

	if (moveForce.x > 0) {
		moveForce = moveForce - frictionForce;
	}
	if (moveForce.x < 0) {
		moveForce = moveForce + frictionForce;
	}
	if (moveForce.Magnitude() <= 0.1f) {
		moveForce = Vec2(0, 0);
	}

	position = position + moveForce;
}

Vec2 Player::GetMoveForce()
{
	return this->moveForce;
}

void Player::SetMoveForce(Vec2 moveForce)
{
	this->moveForce = moveForce;
}

void Player::ApplyMoveForce(Vec2 addition)
{
	this->moveForce = this->moveForce + addition;
}
