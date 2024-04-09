#include "GameObject.h"

GameObject::GameObject(Texture& texture, int posX, int posY) : m_texture(texture), m_x(posX), m_y(posY), m_visible(true)
{
    m_w = texture.getWidth();
    m_h = texture.getHeight();
}

void GameObject::update(float deltaTime)
{

}

void GameObject::draw(Graphics& graphics)
{
    graphics.draw(m_texture, m_x, m_y);
}

bool GameObject::collidesWith(GameObject& other)
{
    int otherX1 = other.m_x;
    int otherY1 = other.m_y;
    int otherX2 = other.m_x + other.m_w;
    int otherY2 = other.m_y + other.m_h;

    bool overlapX = (m_x <= otherX2 && m_x + m_w >= otherX1) || (otherX1 <= m_x + m_w && otherX2 >= m_x);

    bool overlapY = (m_y <= otherY2 && m_y + m_h >= otherY1) || (otherY1 <= m_y + m_h && otherY2 >= m_y);

    bool collision = overlapX && overlapY;
    return collision;
}

int GameObject::getPosX() const
{
    return m_x;
}

int GameObject::getPosY() const
{
    return m_y;
}
