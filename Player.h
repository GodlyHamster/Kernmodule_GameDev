#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();
	Player(Vec2 position);
	void Move();
	Vec2 GetMoveForce();
	void SetMoveForce(Vec2 moveForce);
	void ApplyMoveForce(Vec2 addition);

private:
	Vec2 moveForce = Vec2(0, 0);
	Vec2 frictionForce = Vec2(0.3f, 0);
};

