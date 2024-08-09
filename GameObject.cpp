#include "GameObject.h"

GameObject::GameObject()
{
	rigidbody = new Rigidbody{};
	circleModel = Circle{Vec2(0, 0), 30};
}

GameObject::~GameObject()
{
}

GameObject::GameObject(Vec2 pos)
{
	rigidbody = new Rigidbody{};
	circleModel = Circle{pos, 30};
	rigidbody->SetPosition(pos);
}

GameObject::GameObject(Vec2 pos, float radius)
{
	rigidbody = new Rigidbody{};
	circleModel = Circle{pos, radius};
	rigidbody->SetPosition(pos);
}

Rigidbody& GameObject::GetRigidbody()
{
	return *rigidbody;
}

Circle GameObject::GetModel()
{
	return circleModel;
}

void GameObject::Draw(sf::RenderTarget& target)
{
	circleModel.SetPosition(rigidbody->GetPosition());
	circleModel.Draw(target);
}
