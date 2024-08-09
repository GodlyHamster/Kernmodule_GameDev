#pragma once
#include "Vec2.h"
#include "CustomTime.h"

class Rigidbody
{
public:
	Rigidbody();
	void SetPosition(Vec2 position);
	Vec2 GetPosition();
	void SetForce(Vec2 force);
	Vec2 GetForce();
	void SetVelocity(Vec2 velocity);
	Vec2 GetVelocity();
	void UpdatePosition();

private:
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;
	Vec2 force;
};

