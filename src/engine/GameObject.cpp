#include "GameObject.h"

GameObject::GameObject(Texture* texture, int posX, int posY) : m_texture(texture), m_x(posX), m_y(posY), m_visible(true)
{
    m_w = texture->getWidth();
    m_h = texture->getHeight();
}

int GameObject::getPosX() const
{
    return m_x;
}

int GameObject::getPosY() const
{
    return m_y;
}

void GameObject::setPosX(int x)
{
    m_x = x;
}

void GameObject::setPosY(int y)
{
    m_y = y;
}

void GameObject::show()
{
    m_visible = true;
}

void GameObject::hide()
{
    m_visible = false;
}
