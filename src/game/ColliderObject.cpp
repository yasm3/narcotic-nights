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
	Vector2D<int> directionCollision = other.getPosition() - m_position;
	if (directionCollision.x > 0) {
		std::cout << "droite" << std::endl;
	}
	else if (directionCollision.x < 0) {
		std::cout << "gauche" << std::endl;
	}
}
