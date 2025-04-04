#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	Enemy(Vec2 position);
	void Move();
	Vec2 GetMoveForce();
	void SetMoveForce(Vec2 moveForce);

private:
	Vec2 moveForce = Vec2(0, 0);
	Vec2 frictionForce = Vec2(0.07f, 0.0f);
};

