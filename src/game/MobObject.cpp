#include "MobObject.h"
#include "Player.h"

MobObject::MobObject(Texture* texture, Vector2D<int> position, Graphics& graphics) :
	GameObject(texture, position, graphics)
{
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
	if (Player* player = dynamic_cast<Player*>(&other)) {
		float newHp = player->getHp() - 0.1;
		if (newHp > 0) player->setHp(newHp);
	}
}
