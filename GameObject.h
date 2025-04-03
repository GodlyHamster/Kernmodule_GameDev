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
	void SetPosition(Vec2 position);
	Vec2 GetPosition();
	void SetForce(Vec2 force);
	Vec2 GetForce();
	void SetVelocity(Vec2 velocity);
	Vec2 GetVelocity();
	void UpdatePosition();
	Circle GetModel();
	void Draw(sf::RenderTarget& target);

private:
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;
	Vec2 force;
	Circle circleModel;
};

