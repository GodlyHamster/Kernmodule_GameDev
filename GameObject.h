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
	Vec2 GetPosition();
	Circle GetModel();
	void Draw(sf::RenderTarget& target);

protected:
	Vec2 position;
	Circle model;

private:

};

