#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	int width = 0;
	int height = 0;
	sf::RectangleShape shape;

public:
	Rectangle();
	Rectangle(int width, int height);
	float Area();
	void Draw(sf::RenderTarget& target);

};

