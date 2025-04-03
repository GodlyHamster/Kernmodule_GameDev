#pragma once
#include "Vec2.h"
#include "Circle.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	GameObject(Vec2 pos);
	GameObject(Vec2 pos, float radius);
	Shape GetModel();
	void Draw(sf::RenderTarget& target);

private:
	Shape model;
};

