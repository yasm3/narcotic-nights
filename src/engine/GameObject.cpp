#include "GameObject.h"

GameObject::GameObject(Texture* texture, int posX, int posY) : m_texture(texture), m_x(posX), m_y(posY), m_w(0), m_h(0), m_visible(true)
{
    if (texture != nullptr) {
        m_w = texture->getWidth();
        m_h = texture->getHeight();
    }
}

void GameObject::draw(Graphics& graphics)
{
    if (m_texture != nullptr && m_visible) {
        graphics.draw(*m_texture, m_x, m_y);
    }
}

int GameObject::getPosX() const
{
    return m_x;
}

int GameObject::getPosY() const
{
    return m_y;
}

void GameObject::setTexture(Texture* texture)
{
    m_texture = texture;
    m_w = texture->getWidth();
    m_h = texture->getHeight();
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
