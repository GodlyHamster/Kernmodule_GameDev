#include "Vec2.h"
#include <math.h>

Vec2::Vec2()
{
	x = 0;
	y = 0;
}

Vec2::Vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vec2::SetVector(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vec2::Distance(Vec2 other)
{
	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

float Vec2::Magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

Vec2 Vec2::Normalize()
{
	return Vec2(x / this->Magnitude(), y / this->Magnitude());
}

sf::Vector2f Vec2::ToVectorf()
{
	return sf::Vector2f(this->x, this->y);
}

//Operators
Vec2 Vec2::operator+(const Vec2& other) const
{
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator+(const float& other) const
{
	return Vec2(x + other, y + other);
}

Vec2 Vec2::operator-(const Vec2& other) const
{
	return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator-(const float& other) const
{
	return Vec2(x - other, y - other);
}

Vec2 Vec2::operator*(const float& other) const
{
	return Vec2(x * other, y * other);
}

Vec2 Vec2::operator/(const float& other) const
{
	return Vec2(x / other, y / other);
}
