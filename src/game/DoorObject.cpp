#include "DoorObject.h"

DoorObject::DoorObject(Texture* texture, Vector2D<int> pos) : GameObject(texture, pos), m_active(false)
{

}

void DoorObject::update(float deltaTime, Input& input)
{
}

void DoorObject::draw(Graphics& graphics)
{
    if (m_texture != nullptr && m_active == true)
        std::cout << "left door" << std::endl;
        graphics.draw(*m_texture, m_position.x, m_position.y, graphics.getScale());
}

bool DoorObject::collidesWith(GameObject& other)
{
    return false;
}

void DoorObject::handleCollision(GameObject& other)
{

}

void DoorObject::setActive(bool active)
{
    m_active = active;
}
