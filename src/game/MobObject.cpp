#include "MobObject.h"

MobObject::MobObject(Texture* texture, Vector2D<int> position, Graphics& graphics) :
	GameObject(texture, position, graphics)
{
	showHitbox(true);
}

void MobObject::update(float deltaTime, Input& input)
{
	int direction = generateRandomNumber(0, 30);
	switch (direction) {
	case 0:
		m_position = m_position + Vector2D<int>(-10, 0);
		break;
	case 1:
		m_position = m_position + Vector2D<int>(0, 10);
		break;
	case 2:
		m_position = m_position + Vector2D<int>(10, 0);
		break;
	case 3:
		m_position = m_position + Vector2D<int>(0, -10);
		break;
	}
}

void MobObject::handleCollision(GameObject& other)
{
	
}
