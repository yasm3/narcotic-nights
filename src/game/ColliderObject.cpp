#include "ColliderObject.h"

ColliderObject::ColliderObject(Vector2D<int> position, Vector2D<int> size, Graphics& graphics) :
	GameObject(nullptr, position, graphics)
{
	m_size = size;
	showHitbox(true);
}

void ColliderObject::update(float deltaTime, Input& input)
{

}

void ColliderObject::handleCollision(GameObject& other)
{
	other.handleCollision(*this);
}
