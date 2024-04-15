#include "BulletObject.h"
#include "MobObject.h"

BulletObject::BulletObject(Texture* texture, Vector2D<int> position, Graphics& graphics) :
	GameObject(texture, position, graphics)
{
	m_mousePos = m_graphics.getMousePos();
}

void BulletObject::update(float deltaTime, Input& input)
{
	if (m_alive) {
	}
}

void BulletObject::handleCollision(GameObject& other)
{
	if (MobObject* mob = dynamic_cast<MobObject*>(&other)) {
		std::cout << "touch mob" << std::endl;
	}
}
