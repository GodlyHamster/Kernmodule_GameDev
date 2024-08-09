#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int width, int height)
{
	this->width = width;
	this->height = height;
}

float Rectangle::Area()
{
	return width * height;
}

void Rectangle::Draw(sf::RenderTarget& target)
{
	shape.setSize(sf::Vector2f(width, height));
	target.draw(shape);
}
