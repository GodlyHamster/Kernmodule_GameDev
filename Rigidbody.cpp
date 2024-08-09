#include <iostream>
#include "Rigidbody.h"
#include <math.h>

Rigidbody::Rigidbody()
{
}

void Rigidbody::SetPosition(Vec2 position)
{
	this->position = position;
}

Vec2 Rigidbody::GetPosition()
{
	return this->position;
}

void Rigidbody::SetForce(Vec2 force)
{
	this->force = force;
}

Vec2 Rigidbody::GetForce()
{
	return force;
}

void Rigidbody::SetVelocity(Vec2 velocity)
{
	this->velocity = velocity;
}

Vec2 Rigidbody::GetVelocity()
{
	return this->velocity;
}

void Rigidbody::UpdatePosition()
{
	float deltaTime = 0.016f;

	acceleration = force / 10.0f;
	velocity = velocity + acceleration * deltaTime;

	force = Vec2(0, 0);

	this->position = position + velocity * deltaTime;
}
