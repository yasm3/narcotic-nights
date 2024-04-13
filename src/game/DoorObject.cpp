#include "DoorObject.h"

DoorObject::DoorObject() : GameObject(nullptr, 0, 0), m_active(false)
{

}

DoorObject::DoorObject(Texture* texture) : GameObject(texture, 0, 0), m_active(false)
{
}

void DoorObject::update(float deltaTime, Input& input)
{
}

void DoorObject::draw(Graphics& graphics)
{
    if (m_texture != nullptr && m_active == true)
        std::cout << "left door" << std::endl;
        graphics.draw(*m_texture, m_x, m_y);
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
