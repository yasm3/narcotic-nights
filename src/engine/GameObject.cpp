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

int GameObject::getWidth() const
{
    return m_w;
}

int GameObject::getHeight() const
{
    return m_h;
}

void GameObject::setPosition(int x, int y) {m_x = x; m_y = y;}