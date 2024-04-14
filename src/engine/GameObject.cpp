#include "GameObject.h"

GameObject::GameObject(Texture* texture, Vector2D<int> position) : m_texture(texture), m_position(position), m_size(0), m_visible(true)
{
    if (texture != nullptr) {
        m_size.x = texture->getWidth();
        m_size.y = texture->getHeight();
    }
}

void GameObject::draw(Graphics& graphics)
{
    if (m_texture != nullptr && m_visible) {
        graphics.draw(*m_texture, m_position.x, m_position.y);
    }
}

void GameObject::setTexture(Texture* texture)
{
    m_texture = texture;
    m_size.x = texture->getWidth();
    m_size.y = texture->getHeight();
}

Vector2D<int> GameObject::getPosition() const
{
    return m_position;
}

void GameObject::setPosition(Vector2D<int> newPosition)
{
    m_position = newPosition;
}

void GameObject::show()
{
    m_visible = true;
}

void GameObject::hide()
{
    m_visible = false;
}
