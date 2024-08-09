#pragma once
#include <iostream>
#include <io.h>
#include <SFML/Graphics.hpp>

class Vec2
{
public:
	Vec2();
	Vec2(float x, float y);
	float x;
	float y;
	void SetVector(float x, float y);
	float Distance(Vec2 other);
	float Magnitude();
	Vec2 Normalize();
	sf::Vector2f ToVectorf();

	//operartors
	Vec2 operator+(const Vec2& other) const;
	Vec2 operator+(const float& other) const;
	Vec2 operator-(const Vec2& other) const;
	Vec2 operator-(const float& other) const;
	Vec2 operator*(const float& other) const;
	Vec2 operator/(const float& other) const;
};

