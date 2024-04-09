#include "GameObject.h"

GameObject::GameObject(Texture& texture, int posX, int posY) : m_texture(texture), m_x(posX), m_y(posY), m_visible(true)
{
    m_w = texture.getWidth();
    m_h = texture.getHeight();
}

int GameObject::getPosX() const
{
    return m_x;
}

int GameObject::getPosY() const
{
    return m_y;
}
