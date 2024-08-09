#pragma once
#include "Shape.h"

class Circle : public Shape
{
private :
	float radius = 0;
	sf::CircleShape shape;
	Vec2 position;

public :
	Circle();
	~Circle();
	Circle(Vec2 position);
	Circle(Vec2 position, float radius);
	float GetRadius();
	float Area();
	void SetColor(sf::Color color);
	Vec2 GetPosition();
	void SetPosition(Vec2 position);
	void AddPosition(Vec2 position);
	void Draw(sf::RenderTarget& target);
};

