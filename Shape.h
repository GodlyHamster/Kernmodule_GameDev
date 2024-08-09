#pragma once
#include "Rigidbody.h"
#include <SFML/Graphics.hpp>

class Shape
{
private:

public:
	Shape();
	virtual ~Shape();
	void SetAlpha(float a);
	virtual float Area();
	virtual void SetColor(sf::Color color);
	virtual void SetPosition(Vec2 position);
	virtual void AddPosition(Vec2 position);
	virtual void Draw(sf::RenderTarget& target);
};

