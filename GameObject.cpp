#include "GameObject.h"

GameObject::GameObject()
{
	circleModel = Circle{Vec2(0, 0), 30};
}

GameObject::~GameObject()
{
}

GameObject::GameObject(Vec2 pos)
{
	circleModel = Circle{pos, 30};
	SetPosition(pos);
}

GameObject::GameObject(Vec2 pos, float radius)
{
	circleModel = Circle{pos, radius};
	SetPosition(pos);
}

void GameObject::SetPosition(Vec2 position)
{
	this->position = position;
}

Vec2 GameObject::GetPosition()
{
	return this->position;
}

void GameObject::SetForce(Vec2 force)
{
	this->force = force;
}

Vec2 GameObject::GetForce()
{
	return force;
}

void GameObject::SetVelocity(Vec2 velocity)
{
	this->velocity = velocity;
}

Vec2 GameObject::GetVelocity()
{
	return this->velocity;
}

void GameObject::UpdatePosition()
{
	float deltaTime = 0.016f;

	acceleration = force / 10.0f;
	velocity = velocity + acceleration * deltaTime;

	force = Vec2(0, 0);

	this->position = position + velocity * deltaTime;
}

Circle GameObject::GetModel()
{
	return circleModel;
}

void GameObject::Draw(sf::RenderTarget& target)
{
	circleModel.SetPosition(this->position);
	circleModel.Draw(target);
}
