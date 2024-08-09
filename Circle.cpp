#define _USE_MATH_DEFINES
#include <iostream>
#include "Circle.h"
#include <math.h>

Circle::Circle()
{
}

Circle::~Circle()
{
}

Circle::Circle(Vec2 position)
{
	this->position = position;
}

Circle::Circle(Vec2 position, float radius)
{
	this->position = position;
	this->radius = radius;
}

float Circle::GetRadius()
{
	return this->radius;
}

float Circle::Area()
{
	return M_PI * pow(radius, 2);
}

void Circle::SetColor(sf::Color color)
{
	shape.setFillColor(color);
}

Vec2 Circle::GetPosition()
{
	return position;
}

void Circle::SetPosition(Vec2 position)
{
	this->position = position;
	shape.setPosition(sf::Vector2f(position.x, position.y));
}

void Circle::AddPosition(Vec2 position)
{
	Vec2 newPos = Vec2(this->position.x + position.x, this->position.y + position.y);
	this->position = newPos;
	shape.setPosition(sf::Vector2f(newPos.x, newPos.y));
}

void Circle::Draw(sf::RenderTarget& target)
{
	shape.setPosition(sf::Vector2f(position.x - radius, position.y - radius)); //draws circle from center
	shape.setRadius(radius);
	target.draw(shape);
}
