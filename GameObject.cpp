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
	this->position = pos;
	model = Circle{pos, 30};
}

GameObject::GameObject(Vec2 pos, float radius)
{
	this->position = pos;
	model = Circle{pos, radius};
}

Circle GameObject::GetModel()
{
	return model;
}

void GameObject::Draw(sf::RenderTarget& target)
{
	model.SetPosition(position);
	model.Draw(target);
}
