#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	Enemy(Vec2 position);
	void Move();

private:
	Vec2 moveForce = Vec2(0, 5);
};

