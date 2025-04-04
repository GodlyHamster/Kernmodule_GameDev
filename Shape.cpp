#include "Shape.h"

Shape::Shape()
{
}

Shape::~Shape()
{
}

void Shape::SetAlpha(float a)
{
}

float Shape::Area()
{
	return 0.0f;
}

void Shape::SetColor(sf::Color color)
{
}

void Shape::SetPosition(Vec2 position)
{
	this->position = position;
}

void Shape::AddPosition(Vec2 position)
{
	this->position = this->position + position;
}

void Shape::Draw(sf::RenderTarget& target)
{
}
