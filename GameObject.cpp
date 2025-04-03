#include "GameObject.h"

GameObject::GameObject()
{
	model = Circle{Vec2(0, 0), 30};
}

GameObject::~GameObject()
{
}

GameObject::GameObject(Vec2 pos)
{
	model = Circle{pos, 30};
}

GameObject::GameObject(Vec2 pos, float radius)
{
	model = Circle{pos, radius};
}

Shape GameObject::GetModel()
{
	return model;
}

void GameObject::Draw(sf::RenderTarget& target)
{
	model.Draw(target);
}
