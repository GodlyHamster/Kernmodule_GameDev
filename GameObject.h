#pragma once
#include "Rigidbody.h"
#include "Circle.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	GameObject(Vec2 pos);
	GameObject(Vec2 pos, float radius);
	Rigidbody& GetRigidbody();
	Circle GetModel();
	void Draw(sf::RenderTarget& target);

private:
	Rigidbody* rigidbody = nullptr;
	Circle circleModel;

};

